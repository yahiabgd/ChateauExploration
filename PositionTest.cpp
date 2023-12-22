#include "doctest.h"
#include "Position.h"

TEST_CASE("Position fonctionne correctment"){
    SUBCASE("constructeur correct"){
        Position p{5,2};
        REQUIRE_EQ(p.x(),5);
        REQUIRE_EQ(p.y(),2);
    }
}
