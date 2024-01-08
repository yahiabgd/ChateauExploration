#include "doctest.h"
#include "Position.h"

TEST_CASE("Position fonctionne correctment"){
    SUBCASE("Constructeur et Getters correct"){
        Position p{5,2};
        REQUIRE_EQ(p.x(),5);
        REQUIRE_EQ(p.y(),2);
    }
        SUBCASE("Distance correct"){
        Position p1{0,0};
        Position p2{1,1};
        REQUIRE_EQ(p1.distance(p2),std::sqrt(2));
    }
}
