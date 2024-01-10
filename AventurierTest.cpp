#include "doctest.h"
#include "Aventurier.h"
TEST_SUITE("Test D'aventurier et les objets qui le compose (epée,bourse,armure)")
{
    TEST_CASE("Test épee")
    {
        int points{100};
        Epee e{points};
        int result1 {e.pointSolide()};
        REQUIRE_EQ(result1,points);
        int pointsreduit{25};
        e.reduireSolidite(pointsreduit);
        int result2{e.pointSolide()};
        REQUIRE_EQ(result2,points-pointsreduit);
    }
}
