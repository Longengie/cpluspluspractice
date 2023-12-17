#include <iostream>

using namespace std;

namespace Customer
{
    /// @brief Customer Model
    class CustomerModel
    {
    private:
        /// @brief Customer Last Name
        string _last_name;

        /// @brief Customer First Name
        string _first_name;

        /// @brief Score for Vanilla
        double _score_for_vanilla;

        /// @brief Score for Chocolate
        double _score_for_chocolate;

        /// @brief Score for Strawberry
        double _score_for_strawberry;

        /// @brief Score for Banana
        double _score_for_banana;

        /// @brief Score fore Oreo
        double _score_for_oreo;

    public:

        CustomerModel()
        {
            _last_name = "";
            _first_name = "";
            _score_for_vanilla = 0;
            _score_for_chocolate = 0;
            _score_for_strawberry = 0;
            _score_for_banana = 0;
            _score_for_oreo = 0;
        }
        
        /// @brief Customer Model Constructor
        ~CustomerModel()
        {
            _last_name = "";
            _first_name = "";
            _score_for_vanilla = 0;
            _score_for_chocolate = 0;
            _score_for_strawberry = 0;
            _score_for_banana = 0;
            _score_for_oreo = 0;
        }

        /// @brief Customer Model Constructor
        /// @param last_name Last Name
        /// @param first_name First Name
        /// @param score_for_vanilla Score for Vanilla
        /// @param score_for_chocolate Score for Chocolate
        /// @param score_for_strawberry Score for Strawberry
        /// @param score_for_banana Score for Banana
        /// @param score_for_oreo Score for Oreo
        CustomerModel(string last_name, string first_name,
        double score_for_vanilla, double score_for_chocolate,
        double score_for_strawberry, double score_for_banana,
        double score_for_oreo)
        {
            _last_name = last_name;
            _first_name = first_name;
            _score_for_vanilla = score_for_vanilla;
            _score_for_chocolate = score_for_chocolate;
            _score_for_strawberry = score_for_strawberry;
            _score_for_banana = score_for_banana;
            _score_for_oreo = score_for_oreo;
        }

        /// @brief Getter Last Name
        /// @return Last Name
        string getLastName ()
        {
            return _last_name;
        }

        /// @brief Setter Last Name
        /// @param last_name Last Name
        void setLastName (string last_name)
        {
            _last_name = last_name;
        }

        /// @brief Getter First Name
        /// @return First Name
        string getFirstName ()
        {
            return _first_name;
        }

        /// @brief Setter First Name
        /// @param first_name First Name
        void setFirstName (string first_name)
        {
            _first_name = first_name;
        }

        /// @brief Getter Score for Vanilla
        /// @return Score for Vanilla
        double getScoreForVanilla ()
        {
            return _score_for_vanilla;
        }

        /// @brief Setter Score for Vanilla
        /// @param score_for_vanilla Score for Vanilla
        void setScoreForVanilla (double score_for_vanilla)
        {
            _score_for_vanilla = score_for_vanilla;
        }

        /// @brief Getter Score for Chocolate
        /// @return Score for Chocolate
        double getScoreForChocolate ()
        {
            return _score_for_chocolate;
        }

        /// @brief Setter Score for Chocolate
        /// @param score_for_vanilla Score for Chocolate
        void setScoreForChocolate (double score_for_chocolate)
        {
            _score_for_chocolate = score_for_chocolate;
        }

        /// @brief Getter Score for Strawberry
        /// @return Score for Strawberry
        double getScoreForStrawberry ()
        {
            return _score_for_strawberry;
        }

        /// @brief Setter Score for Strawberry
        /// @param score_for_strawberry Score for Strawberry
        void setScoreForStrawberry (double score_for_strawberry)
        {
            _score_for_strawberry = score_for_strawberry;
        }

        /// @brief Getter Score for Banana
        /// @return Score for Banana
        double getScoreForBanana ()
        {
            return _score_for_banana;
        }

        /// @brief Setter Score for Banana
        /// @param score_for_strawberry Score for Banana
        void setScoreForBanana (double score_for_banana)
        {
            _score_for_banana = score_for_banana;
        }

        /// @brief Getter Score for Oreo
        /// @return Score for Oreo
        double getScoreForOreo ()
        {
            return _score_for_oreo;
        }

        /// @brief Setter Score for Oreo
        /// @param score_for_strawberry Score for Oreo
        void setScoreForOreo (double score_for_oreo)
        {
            _score_for_oreo = score_for_oreo;
        }
    };
}