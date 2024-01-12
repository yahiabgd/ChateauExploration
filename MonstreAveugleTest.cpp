#include "doctest.h"
#include "MonstreAveugle.h"
#include "Aventurier.h"

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
    SUBCASE("réduire point de vie correct"){
        MonstreAveugle m{10,100,{10,2},80};
        p.reduirePointVie(10);
        REQUIRE_EQ(90,p.ponitVie());
    }
    SUBCASE("fonction estsur correct "){
        MonstreAveugle m{10,100,{10,2},80};
        REQUIRE_EQ(p.estSur(),Cellule::TypeCellule::VIDE);
    }
    SUBCASE("fonction modifieEstSur est correct "){
        MonstreAveugle m{10,100,{10,2},80};
        p.modifieEstSur(Cellule::TypeCellule::SORTIE)
        REQUIRE_EQ(p.estSur(),Cellule::TypeCellule::SORTIE);
    }


    SUBCASE("test recoitAttaque fonction "){
        SUBCASE("le cas degats < point de vie monstre"){
            MonstreAveugle m{10,100,{10,2},80};
            m.recoitAttaque(10);
            REQUIRE_EQ(m.pointVie(),90);
        }
        SUBCASE("le cas degats >= point de vie monstre"){
            MonstreAveugle m{10,50,{10,2},80};
            m.recoitAttaque(50);
            REQUIRE_EQ(m.pointVie(),0);
        }
    }

    SUBCASE(" la fonction  pour attaquer Aventurier (ennemi) "){
        MonstreAveugle m{10,100,{10,2},100};
        int pointdeforce{50};
        int pointdevie{100};
        Position position{1,10};
        Armure armure{75};
        Epee epee{25};
        Bourse bourse{0};
        bool amulette = false;
        Aventurier aventurier{pointdeforce,pointdevie,position,armure,epee,bourse,amulette};
        m.attaque(aventurier);
        REQUIRE_EQ(armure.pointSolidite(),72);
        REQUIRE_EQ(aventurier.pointVie(),97);

    }

}
