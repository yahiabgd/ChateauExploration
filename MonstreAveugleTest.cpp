#include "doctest.h"
#include "MonstreAveugle.h"

TEST_CASE("Monstre Aveugle fonctionne correctment"){

    SUBCASE("Constructeur et Getters correct"){
        //(int pointForce, int pointVie, Position position, int habilete):
        MonstreAveugle m{10,100,{10,2},80}
        REQUIRE_EQ(10,m.pointForce());
        REQUIRE_EQ(100,m.pointVie());
        REQUIRE_EQ(10,m.position().x());
        REQUIRE_EQ(2,m.position().y());
        REQUIRE_EQ(80,m.habilete());
    }


//    SUBCASE("deplacement vers marche "){
//
//
//    }

}
