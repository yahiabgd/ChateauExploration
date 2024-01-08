#include "doctest.h"
#include "Terrain.h"


TEST_CASE("Fonctionnement Cellulue"){
    SUBCASE("Constructeur et Getters correct"){
        Cellule T{Cellule::TypeCellule::VIDE};
        T.changecontenu(Cellule::TypeCellule::JOUEUR);
        REQUIRE_EQ(T.contenu(),Cellule::TypeCellule::JOUEUR);
    }

}


TEST_CASE("Terrain fonctionne correctment"){
    SUBCASE("Constructeur et Getters correct"){
        Terrain T{5,10};
        REQUIRE_EQ(T.lignes(),5);
        REQUIRE_EQ(T.colonnes(),10);
        //T.miseajourcellule( 4 ,9,Cellule::TypeCellule::JOUEUR);
        bool eq = true;
        for(int i=0;i<T.lignes();i++)
        {
            for(int j=0;j<T.colonnes();j++)
            {
                eq = eq * (T.cellule(i,j) == Cellule::TypeCellule::VIDE);
            }
        }
        REQUIRE_EQ(eq,true);

    }
    SUBCASE("Import et export de terrain")
    {
        Terrain T{5,10};
        T.miseajourcellule( 4 ,9,Cellule::TypeCellule::JOUEUR);
        T.miseajourcellule( 4 ,5,Cellule::TypeCellule::AMULETTE);
        T.miseajourcellule( 2 ,1,Cellule::TypeCellule::PIECE);
        REQUIRE_EQ(T.sauvegarder("test.txt"),true);
        Terrain F{"test.txt"};
        bool eq = true;
        for(int i=0;i<T.lignes();i++)
        {
            for(int j=0;j<T.colonnes();j++)
            {
                eq = eq * (T.cellule(i,j) == F.cellule(i,j));
            }
        }
        REQUIRE_EQ(eq,true);

    }
    SUBCASE("Terrain Valide")
    {


    }

}
