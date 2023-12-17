#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/// @brief Super Hero
namespace super_hero
{
    /// @brief Super Hero Model
    struct super_hero_model
    {
        /// @brief Super Hero Name
        string name;

        /// @brief Strength Rating
        double strength_rating;

        /// @brief Intelligence Rating
        double intelligence_rating;

        /// @brief Speed Rating
        double speed_rating;

        /// @brief Durability Rating
        double durability_rating;

        /// @brief Fighting Rating
        double fighting_rating;
    };

    /// @brief Power Comprasion Model
    struct power_comparison_model
    {
        /// @brief Power Name
        string name;

        /// @brief Power Rating
        double rating;
    };

    /// @brief Super Hero Handler
    class super_hero_handler
    {
    private:
        /// @brief Get Power Comparison List
        /// @param hero Hero
        /// @return Power Comparison List
        vector<power_comparison_model> getPowerComparisonList (super_hero_model hero)
        {
            return 
            {
                {
                    "Strength",
                    hero.strength_rating
                },
                {
                    "Intelligence",
                    hero.intelligence_rating
                },
                {
                    "Speed",
                    hero.speed_rating
                },
                {
                    "Durability",
                    hero.durability_rating
                },
                {
                    "Fighting",
                    hero.fighting_rating
                }
            };
        }

    public:
        /// @brief Get Super Hero from Line
        /// @param line Line
        /// @return Super Hero
        super_hero_model getSuperHeroFromLine (string line);

        /// @brief Get Power of Super Hero
        /// @param hero Hero
        /// @return Power
        string getPower (super_hero_model hero);
    };

    /// @brief Get Super Hero from Line
    /// @param line Line
    /// @return Super Hero
    inline super_hero_model super_hero_handler::getSuperHeroFromLine (string line)
    {
        stringstream line_stream(line);
        string word;

        super_hero_model hero;

        int input = 1;

        while (getline(line_stream, word, ' '))
        {
            if (word.empty()) continue;
            switch (input)
            {
            case 1:
                hero.name = word;
                break;

            case 2:
                try
                {
                    hero.strength_rating = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;

            case 3:
                try
                {
                    hero.intelligence_rating = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;

            case 4:
                try
                {
                    hero.speed_rating = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;

            case 5:
                try
                {
                    hero.durability_rating = stod(word);
                }
                catch(const std::exception&)
                {
                    throw 101;
                }
                break;

            case 6:
                try
                {
                    hero.fighting_rating = stod(word);
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

        return hero;
    }

    /// @brief Get Power of Super Hero
    /// @param hero Hero
    /// @return Power
    inline string super_hero_handler::getPower (super_hero_model hero)
    {
        vector<power_comparison_model> comparision_list = getPowerComparisonList (hero);

        sort (comparision_list.begin(), comparision_list.end(), [] (power_comparison_model power1,
        power_comparison_model power2) {return power1.rating > power2.rating; });

        return comparision_list[0].name;
    }
}
