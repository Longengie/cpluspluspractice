#include <fstream>
#include "includes/super_hero.h"

using namespace super_hero;

/// @brief Hero Controller
class hero_controller
{
private:
    /// @brief Get Heroes List
    /// @return Heroes List
    vector<super_hero_model> getHeroesList ()
    {
        ifstream inFile;
        string line;

        /// Suppose to use array, but I use vector for easier
        vector<super_hero_model> hero_list;
        super_hero_handler handler;

        try
        {
            inFile.open("superheros.txt");
        }
        catch(const std::exception&)
        {
            throw 100;
        }

        while (getline(inFile, line))
        {
            try
            {
                super_hero_model hero = handler.getSuperHeroFromLine (line);
                hero_list.push_back (hero);
            }
            catch(int error)
            {
                throw 101;
            }
        }

        return hero_list;
    }

    /// @brief Display Heroes Power
    /// @param heroes Heroes List
    void displayHeroesPower (vector<super_hero_model> heroes)
    {
        super_hero_handler handler;
        for (super_hero_model hero: heroes)
        {
            cout << hero.name;
            cout << "'s greatest power is ";
            cout << handler.getPower (hero) << endl;
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

        default:
            break;
        }
    }
public:
    /// @brief Main Progress
    /// @return Progress Status
    int mainProcess ()
    {
        try
        {
            vector<super_hero_model> hero_list = getHeroesList();

            displayHeroesPower (hero_list);
        }
        catch(int e)
        {
            cout << "Program failed, Will exist!" << endl;
            displayError (e);
        }
        return 1;
    }
};

/// @brief Main Program
/// @return Program Status
int main()
{
    hero_controller main_control;
    int result = main_control.mainProcess();

    if (result != 1)
    {
        return 0;
    }
    return 1;
}
