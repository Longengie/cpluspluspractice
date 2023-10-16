#include <iostream>
#include <iomanip>

using namespace std;

class Shop
{
private:
    /// This is price in total
    double _total = 0;

    void displayMenu()
    {
        cout << "1 - Standard Jersey [price: $14.99]" << endl;
        cout << "2 - Standard Jersey with Name [price: $19.99]" << endl;
        cout << "3 - Standard Jersey with NFL Logo [price: $16.99]" << endl;
        cout << "4 - Special Edition Team Jersey [price: $29.99]" << endl;
        cout << "4 - Special Edition Team Jersey [price: $29.99]" << endl;
        cout << "Enter the option for the jersey [1/2/3/4] or 99 to calculate total: ";
    }

    void inputMenu()
    {
        int select;
        string input;
        do
        {
            displayMenu();
            getline(cin,input);
            cout << endl;
            // Check if input empty
            if (input.empty())
            {
                cout << "Wrong entry, please try again!" << endl;
                continue;
            }

            try
            {
                select = stoi(input);
            }
            catch(const std::exception& e)
            {
                cout << "Wrong entry, please try again!" << endl;
                continue;
            }

            optionSelect (select);

        } while (select != 99);
        displayTotal ();        
    }

    void optionSelect (int select)
    {
        switch (select)
        {
        case 1:
            _total += 14.99;
            return;
        case 2:
            _total += 19.99;
            return;
        case 3:
            _total += 16.99;
            return;
        case 4:
            _total += 29.99;
            return;
        case 99:
            return;
        }

        cout << "Wrong entry, please try again!" << endl;
    }

    void displayTotal ()
    {
        double tax = _total * 6 / 100;
        double total = _total + tax;

        cout << "Subtotal: $";
        cout << fixed << showpoint << setprecision(2) << _total << endl;
        cout << "Tax: $";
        cout << fixed << showpoint << setprecision(2) << tax << endl;
        cout << "Total: $";
        cout << fixed << showpoint << setprecision(2) << total << endl;
    }
public:
    void mainProgress()
    {
        inputMenu();
    }
};

int main()
{
    Shop shop;
    shop.mainProgress();
}

