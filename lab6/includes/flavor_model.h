#include <iostream>
#include <iomanip>

using namespace std;

namespace Flavor {
    class highest_lowest
    {
    public:
        double lowest, highest;
        string lowest_flavor, highest_flavor;
    };

    

    /// @brief Flavor Model
    class flavor_model
    {
    private:
        /// @brief Flavors
        string _flavors [10];

        /// @brief Ratings
        double _ratings [10] [5];

        int _last_position;
    
    public:
        /// @brief Add new Flavor
        /// @param flavor Flavor
        /// @param rating1 Rating 1
        /// @param rating2 Rating 2
        /// @param rating3 Rating 3
        /// @param rating4 Rating 4
        /// @param rating5 Rating 5
        void addFlavor (string flavor, double rating1,
        double rating2, double rating3,
        double rating4, double rating5);

        /// @brief Get Highest and Lowest Rating
        /// @param highest Highest
        /// @param highest_flavor Highest Flavor
        /// @param lowest Lowest
        /// @param lowest_flavor Lowest Flavor
        /// @return Highest Lowest
        highest_lowest getHighestLowest ();

        /// @brief Display All Flavors
        void displayAll ();

        /// @brief Display Header
        void displayHeader ();
    };

    /// @brief Add new Flavor
    /// @param flavor Flavor
    /// @param rating1 Rating 1
    /// @param rating2 Rating 2
    /// @param rating3 Rating 3
    /// @param rating4 Rating 4
    /// @param rating5 Rating 5
    inline void flavor_model::addFlavor (string flavor, double rating1, double rating2, double rating3, double rating4, double rating5){
        if (_last_position >= 10)
        {
            return;
        }
        
        _flavors [_last_position] = flavor;
        _ratings [_last_position] [0] = rating1;
        _ratings [_last_position] [1] = rating2;
        _ratings [_last_position] [2] = rating3;
        _ratings [_last_position] [3] = rating4;
        _ratings [_last_position] [4] = rating5;

        _last_position += 1;
    }

    /// @brief Get Highest and Lowest Rating
    /// @param highest Highest
    /// @param lowest Lowest
    inline highest_lowest flavor_model::getHighestLowest ()
    {
        highest_lowest highest_lowest_list;
        highest_lowest_list.highest = 0;
        auto rating_first = _ratings[0];
        highest_lowest_list.lowest_flavor = _flavors[0];
        highest_lowest_list.lowest = (rating_first[0]+ rating_first[1]+ rating_first[2]+rating_first[3] + rating_first[4]) / 5;
        int i = 0;

        for(auto &rating : _ratings) {
            double average = (rating[0]+ rating[1]+ rating[2]+rating[3] + rating[4]) / 5 ;

            if (average > highest_lowest_list.highest)
            {
                highest_lowest_list.highest = average;
                highest_lowest_list.highest_flavor = _flavors[i];
            }
            
            if (average < highest_lowest_list.lowest )
            {
                highest_lowest_list.lowest = average;
                highest_lowest_list.lowest_flavor = _flavors[i];
            }

            i+= 1;
        }

        return highest_lowest_list;
    }

    /// @brief Display all flavors in console
    inline void flavor_model::displayAll ()
    {
        displayHeader ();

        double* rating;

        for (int i = 0; i < 10; i++)
        {
            rating = _ratings [i];

            cout << left << setw(15) << setfill(' ') << _flavors[i];
            cout << right << setw(10) << setfill(' ')
            << fixed << showpoint << setprecision(2) << rating [0];
            cout << right << setw(10) << setfill(' ')
            << fixed << showpoint << setprecision(2) << rating [1];
            cout << right << setw(10) << setfill(' ')
            << fixed << showpoint << setprecision(2) << rating [2];
            cout << right << setw(10) << setfill(' ')
            << fixed << showpoint << setprecision(2) << rating [3];
            cout << right << setw(10) << setfill(' ')
            << fixed << showpoint << setprecision(2) << rating [4];

            double average = (rating[0]+ rating[1]+ rating[2]+rating[3] + rating[4]) / 5 ;
            
            cout << right << setw(18) << setfill(' ')
            << fixed << showpoint << setprecision(2) << average << endl;

        }
    }

    /// @brief Display Header
    inline void flavor_model::displayHeader ()
    {
        cout << left << setw(15) << setfill(' ') << "Flavor";
        cout << right << setw(10) << setfill(' ') << "Rating 1";
        cout << right << setw(10) << setfill(' ') << "Rating 2";
        cout << right << setw(10) << setfill(' ') << "Rating 3";
        cout << right << setw(10) << setfill(' ') << "Rating 4";
        cout << right << setw(10) << setfill(' ') << "Rating 5";
        cout << right << setw(18) << setfill(' ') << "Average Rating" << endl;

        cout <<"-------------------------------------------------------------------------------------------------" << endl;
    }
}