#include "doctest.h"
#include "Personnage.h"

TEST_CASE("Personnage fonctionne correctment"){

    SUBCASE("Constructeur et Getters correct"){
        //(int pointForce, int pointVie, Position position, int habilete):
        Personnage p{10,100,{10,2}}
        REQUIRE_EQ(10,m.pointForce());
        REQUIRE_EQ(100,m.pointVie());
        REQUIRE_EQ(10,m.position().x());
        REQUIRE_EQ(2,m.position().y());

    }
    SUBCASE("réduire point de vie correct"){
        Personnage p{10,100,{10,2}};
        p.reduirePointVie(10);
        REQUIRE_EQ(90,p.ponitVie());
    }
    SUBCASE("fonction estsur correct "){
        Personnage p{10,100,{10,2}};
        REQUIRE_EQ(p.estSur(),Cellule::TypeCellule::VIDE);
    }
    SUBCASE("fonction modifieEstSur est correct "){
        Personnage p{10,100,{10,2}};
        p.modifieEstSur(Cellule::TypeCellule::SORTIE)
        REQUIRE_EQ(p.estSur(),Cellule::TypeCellule::SORTIE);
    }


//    SUBCASE("deplacement vers marche "){
//
//
//    }

}
