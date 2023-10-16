#include <iostream>
#include <iomanip>

using namespace std;

int mainProccess ();

int main () {
    int result = mainProccess ();

    if (result != 1) return 0;
    return 1;
}


class YardsModel
{
private:
    // Attemps 15 Yards
    int _attemps_15;

    // Completions 15 Yards
    int _completions_15;

    // Attemps 25 Yards
    int _attemps_25;

    // Completions 25 Yards
    int _completions_25;

    // Attemps more 25 Yards
    int _attemps_more_25;

    // Completions more 25 Yards
    int _completions_more_25;

public:
    // Yard Model Constructor
    YardsModel ()
    {
        _attemps_15 = 0;
        _attemps_25 = 0;
        _attemps_more_25 = 0;

        _completions_15 = 0;
        _completions_25 = 0;
        _completions_more_25 = 0;
    }


    // Yard Model Constructor
    YardsModel (int attemps_15, int completions_15,
    int attemps_25, int completions_25,
    int attemps_more_25, int completions_more_25)
    {
        _attemps_15 = attemps_15;
        _attemps_25 = attemps_25;
        _attemps_more_25 = attemps_more_25;

        _completions_15 = completions_15;
        _completions_25 = completions_25;
        _completions_more_25 = completions_more_25;
    }

    // Getter Attemps 15 Yards
    int getAttemps15 () {
        return _attemps_15;
    }

    // Setter Attemps 15 Yards
    void setAttemps15 (int attemps15) {
        _attemps_15 = attemps15;
    }

    // Getter Attemps 25 Yards
    int getAttemps25 () {
        return _attemps_25;
    }

    // Setter Attemps 25 Yards
    void setAttemps25 (int attemps25) {
        _attemps_25 = attemps25;
    }

    // Getter Attemps more 25 Yards
    int getMoreAttemps25 () {
        return _attemps_more_25;
    }

    // Setter Attemps more 25 Yards
    void setMoreAttemps25 (int attempsMore25) {
        _attemps_more_25 = attempsMore25;
    }

    // Getter Completions 15 Yards
    int getCompletions15 () {
        return _completions_15;
    }

    // Setter Completions 15 Yards
    void setCompletions15 (int completions_15) {
        _completions_15 = completions_15;
    }

    // Getter Completions 25 Yards
    int getCompletions25 () {
        return _completions_25;
    }

    // Setter Completions 25 Yards
    void setCompletions25 (int completions_25) {
        _completions_25 = completions_25;
    }

    // Getter Completions more 25 Yards
    int getMoreCompletions25 () {
        return _completions_more_25;
    }

    // Setter Completions more 25 Yards
    void setMoreCompletions25 (int completions_more_25) {
        _completions_more_25 = completions_more_25;
    }

    // Get Percent of 15 Yards
    double get15Percent () {
        return (double) _completions_15 / _attemps_15;
    }

    // Get Percent of 25 Yards
    double get25Percent () {
        return (double) _completions_25 / _attemps_25;
    }

    // Get Percent of More 25 Yards
    double getMore25Percent () {
        return (double) _completions_more_25 / _attemps_more_25;
    }
};

class YardsCalculation
{
private:
    enum Errors
    {
        YARDS15_INPUT_MISSING_ERROR,
        YARDS25_INPUT_MISSING_ERROR,
        YARDS25_MORE_INPUT_MISSING_ERROR,
        UNKNOWN_INPUT_MISSING_ERROR,
        YARDS15_INPUT_VALID_ERROR,
        YARDS25_INPUT_VALID_ERROR,
        YARDS25_MORE_INPUT_VALID_ERROR,
        UNKNOWN_INPUT_VALID_ERROR,
    };

    // Input Yards
    int inputYards (string label, int error_code, int check_number = -1)
    {
        cout << "Enter number of " << label << ": ";
        // Het String Input
        string input;
        getline(cin, input);

        if (input.empty()) {
            throwInputMissingError (error_code);
        }

        int number_input;

        // Convert String Input to Intenger
        try
        {
            number_input = stoi (input);

            if (number_input < 0)
            {
                throwInputValidError (error_code);
            }

            if (check_number != -1 && number_input > check_number)
            {
                throwInputValidError (error_code);
            }
        }
        catch(...)
        {
            throwInputValidError (error_code);
        }

        return number_input;
    }

    // Throw Input Missing Error
    void throwInputMissingError (int error_code)
    {
        switch (error_code)
        {
            case 15:
                throw YARDS15_INPUT_MISSING_ERROR;
            case 25:
                throw YARDS25_INPUT_MISSING_ERROR;
            case 26:
                throw YARDS25_MORE_INPUT_MISSING_ERROR;
        }
        throw UNKNOWN_INPUT_MISSING_ERROR;
    }

    // Throw Input Valid Error
    void throwInputValidError (int error_code)
    {
        switch (error_code)
        {
            case 15:
                throw YARDS15_INPUT_VALID_ERROR;
            case 25:
                throw YARDS25_INPUT_VALID_ERROR;
            case 26:
                throw YARDS25_MORE_INPUT_VALID_ERROR;
        }
        throw UNKNOWN_INPUT_VALID_ERROR;
    }

    // Create New Yards Model with Console Input
    YardsModel createYardsModel ()
    {
        YardsModel new_yard = YardsModel();

        new_yard.setAttemps15(inputYards("attemps from 0 - 15 yards", 15));
        new_yard.setCompletions15(
            inputYards("completions from 0 - 15 yards", 15, new_yard.getAttemps15())
            );

        new_yard.setAttemps25(inputYards("attemps from 16 - 25 yards", 25));
        new_yard.setCompletions25(
            inputYards("completions from 16 - 25 yards", 25, new_yard.getAttemps25())
            );

        new_yard.setMoreAttemps25(inputYards("attemps from 16 - 25 yards", 26));
        new_yard.setMoreCompletions25(
            inputYards("completions from 16 - 25 yards", 26, new_yard.getMoreAttemps25())
            );

        return new_yard;
    }

    // Display Percent of Yard Completion on Console
    void displayPercent (YardsModel yards)
    {
        cout << "Percentage of passing between 0 - 15 yards is ";
        cout << fixed << showpoint << setprecision(2) << yards.get15Percent() << endl;

        cout << "Percentage of passing between 16 - 25 yards is ";
        cout << fixed << showpoint << setprecision(2) << yards.get25Percent() << endl;

        cout << "Percentage of passing more than 25 yards is ";
        cout << fixed << showpoint << setprecision(2) << yards.getMore25Percent() << endl;
    }

    void displayError (Errors error_code)
    {
        switch (error_code)
        {

        case YARDS15_INPUT_MISSING_ERROR:
            cout << "The information of attemps from 0 - 15 yards is missing" << endl;
            break;

        case YARDS25_INPUT_MISSING_ERROR:
            cout << "The information of attemps from 16 - 25 yards is missing" << endl;
            break;

        case YARDS25_MORE_INPUT_MISSING_ERROR:
            cout << "The information of attemps from more than 25 yards is missing" << endl;
            break;

        case YARDS15_INPUT_VALID_ERROR:
            cout << "The information of attemps from 0 - 15 yards is invalid" << endl;
            break;

        case YARDS25_INPUT_VALID_ERROR:
            cout << "The information of attemps from 16 - 25 yards is invalid" << endl;
            break;

        case YARDS25_MORE_INPUT_VALID_ERROR:
            cout << "The information of attemps from more than 25 yards is invalid" << endl;
            break;
        
        default:
            cout << "The program meet unexpected errors" << endl;
            break;
        }
    }

public:
    YardsCalculation () {};
    int mainProccess ()
    {
        YardsModel new_yard;
        try
        {
            new_yard = createYardsModel ();
            
            cout << endl;

            displayPercent (new_yard);
        }
        catch(Errors error)
        {
            displayError (error);
            return 0;
        }
        
        return 1;
    }
};

int mainProccess () {
    YardsCalculation yard_calculation{};
    int result = yard_calculation.mainProccess();

    if (result != 1) return 0;
    return 1;
}