#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

/// @brief Parking Model
class ParkingModel
{
private:
    /// @brief Name
    string _name;
    /// @brief Parking Hour
    double _parking_hour;
    /// @brief Is Vehicle is Commerical
    bool _is_commerical;

public:
    /// @brief Parking Model Constructor
    ParkingModel ()
    {
        _name = "";
        _parking_hour = 0;
        _is_commerical = false;
    }

    /// @brief Name Getter
    /// @return Name
    string getName ()
    {
        return _name;
    }

    /// @brief Name Setter
    /// @param name Name
    void setName (string name)
    {
        _name = name;
    }

    /// @brief Parking Hour Getter
    /// @return Parking Hour
    double getParkingHour ()
    {
        return _parking_hour;
    }

    /// @brief Parking Hour Setter
    /// @param parking_hour Parking Hour
    void setParkingHour (double parking_hour)
    {
        _parking_hour = parking_hour;
    }

    /// @brief Getter Is Commerical
    /// @return Is Commerical
    bool getIsCommerical ()
    {
        return _is_commerical;
    }

    /// @brief Setter Is Commerical
    /// @param is_commerical Is Commerical
    void setIsCommerical (bool is_commerical)
    {
        _is_commerical = is_commerical;
    }

    /// @brief Get Parking Charge
    /// @return Parking Charge
    double getParkingCharge ()
    {
        double charge = 0;

        if (_is_commerical)
        {
            charge += 10;
        }

        if (_parking_hour > 0)
        {
            charge += 8;
        }

        if (_parking_hour <= 4)
        {
            return charge;
        }

        charge += (_parking_hour - 4) * 2.5;

        if (charge >= 60)
        {
            charge = 60;
        }

        return charge;
    }
};

class ParkingProcess
{
private:
    /// @brief Input Name
    /// @return Name
    string inputName ()
    {
        cout << "Enter Customer Name: ";
        // Get String Input
        string input;
        getline(cin, input);

        if (input.empty())
        {
            throw 100;
        }

        return input;
    }

    /// @brief Input Parking Hour
    /// @return Parking Hour
    double inputParkingHour ()
    {
        cout << "Enter Hours Parked: ";
        // Get String Input
        string input;
        getline(cin, input);

        if (input.empty())
        {
            throw 200;
        }

        double number_input;
        try
        {
            number_input = stod (input);
        }
        catch (...)
        {
            throw 201;
        }

        if (number_input < 0)
        {
            throw 202;
        }

        return number_input;
    }

    /// @brief Input is Commerical
    /// @return Commerical Status
    bool inputIsCommerical ()
    {
        cout << "Is Vehicle Commerical (Y/N): ";
        string input;
        getline(cin,input);

        // Check if input empty or not char convertable
        if(input.empty() || input.length() > 1)
        {
            throw 300;
        }

        switch (tolower(input[0]))
        {
        case 'y':
            return true;

        case 't':
            return true;

        case 'n':
            return false;

        case 'f':
            return false;
        }

        throw 301;
    }

    /// @brief Get Customer Info
    /// @param parking Parking Model
    void getCustomerInfo (ParkingModel& parking)
    {
        parking.setName(inputName());
        parking.setParkingHour(inputParkingHour());
        parking.setIsCommerical(inputIsCommerical());

        cout << endl;
    }

    /// @brief Export Report Line
    /// @param parking Parking Model
    /// @param file File export
    void exportReportLine (ParkingModel parking, ofstream& file)
    {
        file << left << setw(40) << setfill(' ') << parking.getName();
        file << right << setw(10) << setfill(' ') << fixed << showpoint
        << setprecision(2) << parking.getParkingHour();
        file << right << setw(10) << setfill(' ') << fixed << showpoint
        << setprecision(2) << parking.getParkingCharge();
        file << right << setw(15) << setfill(' ') << fixed << showpoint
        << setprecision(2) << (parking.getIsCommerical() ? 'Y' : 'N') << endl;
    }

    /// @brief Export Report Header
    /// @param file File export
    void exportReportHeader (ofstream& file)
    {
        file << left << setw(40) << setfill(' ') << "Customer";
        file << right << setw(10) << setfill(' ') << "Hours";
        file << right << setw(10) << setfill(' ') << "Charge";
        file << right << setw(15) << setfill(' ') << "Commerical" << endl;
    }

    /// @brief Export File
    /// @param parkings Parking List
    void exportFile (vector<ParkingModel> parkings)
    {
        ofstream outFile;

        try
        {
            outFile.open("report.txt");

            exportReportHeader (outFile);

            for (ParkingModel parking : parkings)
            {
                exportReportLine(parking, outFile);
            }

            outFile.close();
        }
        catch(...)
        {
            throw 400;
        }    
    }

    /// @brief Display Error
    /// @param e Error Code
    void displayError(int e)
    {
        switch (e)
        {
        case 100:
            cout << "The name customer should exist";
            return;

        case 200:
            cout << "The parking hours should exist";
            return;
        
        case 201:
            cout << "The parking hours enter in wrong format";
            return;

        case 202:
            cout << "The parking hours should more than 0";
            return;

        case 300:
            cout << "The vehicle commerical status is not exist or invalid format";
            return;
        
        case 301:
            cout << "The vehicle commerical status enter in wrong format";
            return;

        case 400:
            cout << "The report file export function got errors";
            return;
        }

        cout << "The new error code detected, please contact IT Department!";
    }
public:
    int mainProcess ()
    {
        vector<ParkingModel> parkings;

        try
        {
            for (int i = 1; i <= 3; i++)
            {
                ParkingModel parking;
                getCustomerInfo (parking);

                parkings.push_back(parking);
            }

            exportFile (parkings);
        }
        catch(int e)
        {
            cout << endl;
            displayError(e);
            cout << "Progam will exist now" << endl;
            return 0;
        }
        
        return 1;
    }
};

int main()
{
    ParkingProcess parking;
    int result = parking.mainProcess();

    if (result != 1)
    {
        return 0;
    }
    return 1;
}