#include "customer.h"

using namespace Customer;

/// @brief Ice Cream
namespace icecream
{
    /// @brief Rating
    enum rating { EXCELLENT, GOOD, OK, NOT_GOOD, BAD };

    /// @brief Rating to String
    /// @param rating Rating
    /// @return Rating String
    inline string ratingToString (rating rating)
    {
        switch (rating)
        {
        case EXCELLENT:
            return "excellent";

        case GOOD:
            return "good";

        case OK:
            return "ok";

        case NOT_GOOD:
            return "not good";

        case BAD:
            return "bad";
        }

        return "rating invalid";
    }

    /// @brief Get Rating of Customer
    /// @param customer Customer
    /// @return Rating of Customer
    inline rating getRating (CustomerModel customer)
    {
        double score_for_vanilla = customer.getScoreForVanilla();
        double score_for_chocolate = customer.getScoreForChocolate();
        double score_for_strawberry = customer.getScoreForStrawberry();
        double score_for_banana = customer.getScoreForBanana();
        double score_for_oreo = customer.getScoreForOreo();

        double average = (score_for_vanilla +
        score_for_chocolate + score_for_strawberry
        + score_for_banana + score_for_oreo) / 5;

        if (average >= 9.0) return EXCELLENT;

        if (average >= 7.0) return GOOD;

        if (average >= 5.0) return OK;

        if (average >= 3.0) return NOT_GOOD;

        return BAD;
    }
}