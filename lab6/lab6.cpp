#include <iostream>
#include <vector>
#include <fstream>
#include "includes/flavor_model.h"

using namespace std;
using namespace Flavor;



class Lab6
{
private:
    /// @brief Get Ratings From Line
    /// @param line Line
    /// @return Ratings List
    vector<double> getRatingsFromLine (string line)
    {
        stringstream line_stream(line);

        int input = 1;
        string word;
        vector<double> ratings;

        while (getline(line_stream, word, ' '))
        {
            if (word.empty()) continue;
            
            try
            {
                ratings.push_back(stod(word));
            }
            catch(const std::exception&)
            {
                throw 101;
            }
             
        }

        

        return ratings;
    }

    /// @brief Get Flavors From File
    /// @return Flavors
    flavor_model getFlavorsFromFile ()
    {
        flavor_model flavors;
        ifstream inFile;
        string line, flavor;
        int input = 1;

        try
        {
            inFile.open("flavors.txt");
        }
        catch(const std::exception&)
        {
            throw 100;
        }

        while (getline(inFile, line))
        {
            if (input == 1)
            {
                flavor = line;
                input = 2;

                continue;
            }

            vector<double> ratings = getRatingsFromLine (line);

            if (ratings.size() != 5)
            {
                throw 101;
            }

            flavors.addFlavor (flavor, ratings[0], ratings[1], ratings[2], ratings[3], ratings[4]);
            input = 1;
        }

        return flavors;
    }
    

public:
    int mainProcess ()
    {
        try
        {
            flavor_model flavors = getFlavorsFromFile();
            flavors.displayAll();
            cout << endl;

            highest_lowest highest_lowest_list= flavors.getHighestLowest();

            cout << "This flavor that has the highest average rating: ";
            cout << highest_lowest_list.highest_flavor << " with a rating of ";
            cout << fixed << showpoint << setprecision(2) << highest_lowest_list.highest << "." << endl;

            cout << "This flavor that has the lowest average rating: ";
            cout << highest_lowest_list.lowest_flavor << " with a rating of ";
            cout << fixed << showpoint << setprecision(2) << highest_lowest_list.lowest << "." << endl;
        }
        catch(int e)
        {
            cout << "Program failed, Will exist!" << endl;
        }
        return 1;
}
};


int main() {
    Lab6 main_control;
    int result = main_control.mainProcess();

    if (result != 1)
    {
        return 0;
    }
    return 1;
}