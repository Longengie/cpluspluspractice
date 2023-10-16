#include<iostream>
#include <iterator>
#include <limits>
#include <string>
#include<iomanip>

using namespace std;
using std::cout;

class Employee
{
private:
    enum employee_status
    {
        FULLTIME,
        PARTTIME,
        EMPTY
    };
    // Last Name
    string last_name;
    // Building Code
    char buiding_code;
    // Current Salary
    double current_salary;
    // Status
    employee_status status;

public:
    
    // Setter Last Name
    void setLastName(string lastname)
    {
        last_name = lastname;
    }

    // Getter Last Name
    string getLastName()
    {
        return last_name;
    }

    // Setter Buiding Code
    void setBuidingCode(char buildingcode)
    {
        buiding_code = buildingcode;
    }

    // Getter Current Salary
    char getBuidingCode()
    {
        return buiding_code;
    }

    // Setter Current Salary
    void setCurrentSalary(double currentsalary)
    {
        current_salary = currentsalary;
    }

    // Getter Current Salary
    double getCurrentSalary()
    {
        return current_salary;
    }

    // Setter Employee Status
    void setEmployeeStatus(employee_status employeestatus)
    {
        status = employeestatus;
    }

    // Setter Employee Status From String
    void setEmployeeStatusString(string employee_status)
    {
        for(char text: employee_status)
        {
            text = tolower(text);
        }

        if(employee_status == "fulltime")
        {
            status = FULLTIME;
            return;
        }

        if (employee_status == "full time")
        {
            status = FULLTIME;
            return;
        }

        if (employee_status == "full-time")
        {
            status = FULLTIME;
            return;
        }

        if (employee_status == "1")
        {
            status = FULLTIME;
            return;
        }

        if (employee_status == "parttime")
        {
            status = PARTTIME;
            return;
        }

        if (employee_status == "part time")
        {
            status = PARTTIME;
            return;
        }

        if (employee_status == "part-time")
        {
            status = PARTTIME;
            return;
        }

        if (employee_status == "2")
        {
            status = PARTTIME;
            return;
        }

        status = EMPTY;
    }

    // Getter Current Salary
    employee_status getEmployeeStatus()
    {
        return status;
    }

    string getStringEmployeeStatus()
    {
        switch(status)
        {
            case FULLTIME:
                return "Full-time";
            case PARTTIME:
                return "Part-time";
            default:
                return "";
        }
    }
};

class Lab2
{
private:
    Employee* employee;
    string buiding_label;
    double new_salary;

    int inputData()
    {
        try
        {
            inputLastName();
            inputBuidingCode();
            inputCurrentSalary();
            inputStatus();
        }
        catch(int error_code)
        {
            getErrorLabel(error_code);
            return 0;
        }
        return 1;
    }
    // Input Last Name
    void inputLastName()
    {
        cout << "Enter Last Name: ";
        string input;
        getline(cin,input);

        if(input.empty())
        {
            throw 100;
        }

        employee->setLastName(input);
    }

    // Input Buiding Code
    void inputBuidingCode()
    {
        cout << "Enter Buiding Code: ";
        string input;
        getline(cin,input);

        // Check if input empty or not char convertable
        if(input.empty() || input.length() > 1)
        {
            throw 200;
        }

        employee->setBuidingCode(input[0]);
        buiding_label = getBuidingCodeLocation();
    }

    // Input Current Salary
    void inputCurrentSalary()
    {
        cout << "Enter Current Salary: ";
        string input;
        getline(cin,input);

        // Check if input empty
        if(input.empty())
        {
            throw 300;
        }

        try
        {
            double salaryinput = stod(input);
            if (salaryinput < 0)
            {
                throw 301;
            }

            employee->setCurrentSalary(salaryinput);
        }
        catch(const std::exception& e)
        {
            throw 300;
        }
    }

    // Input Employee Status
    void inputStatus()
    {
        cout << "Enter Employment Status: ";
        string input;
        getline(cin,input);

        // Check if input empty
        if(input.empty())
        {
            throw 400;
        }

        employee->setEmployeeStatusString(input);
        if(employee->getStringEmployeeStatus() == "")
        {
            throw 401;
        }
    }
    // Get Building Code Label
    string getBuidingCodeLocation()
    {
        switch (toupper(employee->getBuidingCode()))
        {
        case 'N':
            return "Wake, North Carolina";
        
        case 'D':
            return "Washington, DC";

        case 'V':
            return "Las Vegas, Nevada";

        case 'T':
            return "Austin, Texas";

        default:
            throw 201;
        }
    }

    void getNewSalary()
    {
        string status = employee->getStringEmployeeStatus();
        double current_salary = employee->getCurrentSalary();
        
        if (status == "Full-time")
        {
            new_salary = current_salary + ((current_salary*3)/100);
            return;
        }

        if (status == "Part-time")
        {
            new_salary = current_salary + 500;
            return;
        }

        new_salary = current_salary;
    }

    void displayEmployee()
    {
        cout << "Employee's Last name: ";
        cout << employee->getLastName() << endl;
        cout << "Building Code: ";
        cout << employee->getBuidingCode() << endl;
        cout << "Building Location: ";
        cout << getBuidingCodeLocation() << endl;
        cout << "Employment Status: ";
        cout << employee->getStringEmployeeStatus() << endl;
        cout << "Current Salary: $";
        cout << fixed << showpoint << setprecision(2) << employee->getCurrentSalary() << endl;
        cout << "New Salary: $";
        cout << fixed << showpoint << setprecision(2) << new_salary << endl;
    }
    void cleanState() {
        delete(employee);
    }

    void getErrorLabel(int error_code)
    {
        switch (error_code)
        {
        case 100:
            cout << "Last Name is empty or wrong" << endl;
            break;
        case 200:
            cout << "Buiding Code is empty or wrong" << endl;
            break;
        case 201:
            cout << "Buiding Code does not exist" << endl;
            break;
        case 300:
            cout << "Current Salary is empty or wrong" << endl;
            break;
        case 301:
            cout << "Current Salary must be equal or greater than 0" << endl;
            break;
        case 400:
            cout << "Employer Status is empty or wrong" << endl;
        case 401:
            cout << "Employer Status does not exist" << endl;
        default:
            cout << "The Program meet unexpected Error" << endl;
            break;
        }
        cout << "The Program will stop now" << endl;
    }
public:

    Lab2()
    {
        employee = new Employee();
        buiding_label = "";
    }

    int mainProcess() {
        int input = inputData();
        if (input == 0)
        {
            cleanState();
            return 0;
        }
        getNewSalary();
        displayEmployee();
        cleanState();
        return 1;
    }
};

int main()
{
    Lab2 lab2;
    int result = lab2.mainProcess();

    if (result != 1)
    {
        return 0;
    }
    return 1;
}