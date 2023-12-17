#include <array>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

#include "includes/lab5.h"

using namespace std;
using namespace Customer;
using namespace icecream;


class MainControl
{
private:
    /// @brief Get Customer From Line
    /// @param line Line
    /// @return Customer
    CustomerModel getCustomerFromLine (string line)
    {
        stringstream line_stream(line);

        string last_name, first_name, word;
        double score_for_vanilla;
        double score_for_chocolate;
        double score_for_strawberry;
        double score_for_banana;
        double score_for_oreo;

        int input = 1;
        

        while (getline(line_stream, word, ' '))
        {
            if (word.empty()) continue;
            switch (input)
            {
            case 1:
                first_name = word;
                break;

            case 2:
                last_name = word;
                break;

            case 3:
                try
                {
                    score_for_vanilla = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;

            case 4:
                try
                {
                    score_for_chocolate = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;

            case 5:
                try
                {
                    score_for_strawberry = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;

            case 6:
                try
                {
                    score_for_banana = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;

            case 7:
                try
                {
                    score_for_oreo = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;
            
            default:
                throw 200;
            }

            input++;
        }
        CustomerModel customer = CustomerModel (last_name, first_name,
        score_for_vanilla, score_for_chocolate,
        score_for_strawberry, score_for_banana,
        score_for_oreo);

        return customer;
    }

    /// @brief Get Customer List From File
    /// @return Customer List
    vector<CustomerModel> getCustomerListFromFile ()
    {
        ifstream inFile;
        string line;

        vector<CustomerModel> list_customer;

        try
        {
            inFile.open("flavors.txt");
        }
        catch(const std::exception&)
        {
            throw 100;
        }
        

        while (getline(inFile, line)) // Suppose to use eof but I designed to work different
        {
            try
            {
                CustomerModel customer = getCustomerFromLine(line);
                list_customer.push_back(customer);
            }
            catch(int error)
            {
                throw 101;
            }
        }

        return list_customer;
    }

    /// @brief Export Customer String
    /// @param customer Customer
    /// @param file File
    void exportCustomerString (CustomerModel customer)
    {
        cout << left << setw(12) << setfill(' ') << customer.getLastName();
        cout << left << setw(12) << setfill(' ') << customer.getFirstName();

        cout << left << "Customer rating is ";
        cout << ratingToString(getRating(customer)) << "." << endl;
    }

    /// @brief Export Customer Line
    /// @param customer Customer
    /// @param file Export File
    void exportCustomerLine (CustomerModel customer, ofstream& file)
    {
        file << left << setw(12) << setfill(' ') << customer.getLastName();
        file << left << setw(12) << setfill(' ') << customer.getFirstName();

        file << left << "Customer rating is ";
        file << ratingToString(getRating(customer)) << "." << endl;
    }

    /// @brief Export Files
    /// @param customer_list Customer List
    void exportFile (vector<CustomerModel> customer_list)
    {
        try
        {
            ofstream file;
            file.open("flavors_report.txt");

            for (CustomerModel customer : customer_list)
            {
                exportCustomerString (customer);
                exportCustomerLine (customer, file);
            }
            file.close();
        }
        catch(...)
        {
            throw 200;
        }
        
    }

    void displayError (int error_code)
    {
        switch (error_code)
        {
        case 100:
            cout << "Input file not exist!" << endl;
            return;

        case 101:
            cout << "Input file in wrong format!" << endl;
            return;

        case 200:
            cout << "Export file error!" << endl;
            return;


        default:
            break;
        }
    }
public:
    /// @brief Main Progress
    /// @return Progress Status
    int mainProcess ();
};


/// @brief Main Program
/// @return Program Status
int main()
{
    MainControl main_control;
    int result = main_control.mainProcess();

    if (result != 1)
    {
        return 0;
    }
    return 1;
}

/// @brief Main Control: Main Progress
/// @return Progress Status
int MainControl::mainProcess ()
{
    try
    {
        vector<CustomerModel> customer_list = getCustomerListFromFile();

        exportFile (customer_list);
    }
    catch(int e)
    {
        cout << "Program failed, Will exist!" << endl;
        displayError(e);
    }
    return 1;
}