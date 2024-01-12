#include "doctest.h"
#include "MonstreVoyant.h"

TEST_CASE("Monstre Aveugle fonctionne correctment"){

    SUBCASE("Constructeur et Getters correct"){
        //(int pointForce, int pointVie, Position position, int habilete):
        MonstreVoyant m{10,100,{10,2},80};
        REQUIRE_EQ(10,m.pointForce());
        REQUIRE_EQ(100,m.pointVie());
        REQUIRE_EQ(10,m.position().x());
        REQUIRE_EQ(2,m.position().y());
        REQUIRE_EQ(80,m.habilete());
    }
    SUBCASE("réduire point de vie correct"){
        MonstreVoyant m{10,100,{10,2},80};
        m.reduirePointVie(10);
        REQUIRE_EQ(90,m.pointVie());
    }
    SUBCASE("fonction estsur correct "){
        MonstreVoyant m{10,100,{10,2},80};
        REQUIRE_EQ(m.estSur(),Cellule::TypeCellule::VIDE);
    }
    SUBCASE("fonction modifieEstSur est correct "){
        MonstreVoyant m{10,100,{10,2},80};
        m.modifieEstSur(Cellule::TypeCellule::SORTIE);
        REQUIRE_EQ(m.estSur(),Cellule::TypeCellule::SORTIE);
    }

}
