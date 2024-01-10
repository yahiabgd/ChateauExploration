#include "doctest.h"
#include "Position.h"

TEST_CASE("Position fonctionne correctment"){
    Position p1{1,1};
    SUBCASE("Constructeur et Getters correct"){

        REQUIRE_EQ(p1.x(),1);
        REQUIRE_EQ(p1.y(),1);
    }
        SUBCASE("Distance correct"){
        Position p2{0,0};
        REQUIRE_EQ(p1.distance(p2),std::sqrt(2));
    }
    SUBCASE("Deplace En Deplace De "){
        p1.deplacerDe(1,2);
        REQUIRE_EQ(p1.x(),2);
        REQUIRE_EQ(p1.y(),3);
        p1.deplacerEn(0,0);
        REQUIRE_EQ(p1.x(),0);
        REQUIRE_EQ(p1.y(),0);
    }
}
