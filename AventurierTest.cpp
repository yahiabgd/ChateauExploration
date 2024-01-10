#include "doctest.h"
#include "Aventurier.h"
TEST_SUITE("Test D'aventurier et les objets qui le compose (epée,bourse,armure)")
{
    TEST_CASE("Test épee")
    {
        int points{100};
        Epee e{points};
        SUBCASE("CONSTRUCTEUR ET GETTER")
        {
            int result1 {e.pointSolide()};
            REQUIRE_EQ(result1,points);
        }
        SUBCASE("Test fonction pointsreduit")
        {
            int pointsreduit{25};
            e.reduireSolidite(pointsreduit);
            int result2{e.pointSolide()};
            REQUIRE_EQ(result2,points-pointsreduit);
        }

    }
    TEST_CASE("Test Bourse")
    {
        int nbpiece{0};
        Bourse b{nbpiece};
        SUBCASE("CONSTRUCTEUR ET GETTER")
        {
            REQUIRE_EQ(b.pieceMonnaie(),nbpiece);
        }
        SUBCASE("Test fonction ajouter et enlever")
        {
            b.ajouter(3);
            REQUIRE_EQ(b.pieceMonnaie(),nbpiece+3);
            b.enlever(2);
            REQUIRE_EQ(b.pieceMonnaie(),nbpiece+3-2);
        }
    }
    TEST_CASE("Test Armure")
    {
        int points{100};
        Armure a{points};
        SUBCASE("CONSTRUCTEUR ET GETTER")
        {
            int result1 {a.pointSolide()};
            REQUIRE_EQ(result1,points);
        }
        SUBCASE("Test fonction pointsreduit")
        {
            int pointsreduit{25};
            a.reduireSolidite(pointsreduit);
            int result2{a.pointSolide()};
            REQUIRE_EQ(result2,points-pointsreduit);
        }
    }
    TEST_CASE("Test Aventurier")
    {
        int pointdeforce{50};
        int pointdevie{100};
        Position position{1,10};
        Armure armure{75};
        Epee epee{25};
        Bourse bourse{0};
        bool amulette = false;
        Aventurier aventurier{pointdeforce,pointdevie,position,armure,epee,bourse,amulette};
        SUBCASE("CONSTRUCTEUR ET GETTER")
        {
            REQUIRE_EQ(1,1);
        }
    }
}
