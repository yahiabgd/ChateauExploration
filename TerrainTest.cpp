#include "doctest.h"
#include "Terrain.h"

TEST_SUITE("Test du terrain et cellule")
{
    TEST_CASE("Fonctionnement Cellulue"){
        SUBCASE("Constructeur et Getters correct"){
            Cellule T{Cellule::TypeCellule::VIDE};
            T.changecontenu(Cellule::TypeCellule::JOUEUR);
            REQUIRE_EQ(T.contenu(),Cellule::TypeCellule::JOUEUR);
        }

    }

    TEST_CASE("Terrain fonctionne correctment"){
        Terrain T{5,10};
        SUBCASE("Constructeur et Getters correct"){
            REQUIRE_EQ(T.lignes(),10);
            REQUIRE_EQ(T.colonnes(),5);
            bool eq = true;
            for(int y=0;y<T.lignes();y++)
            {
                for(int x=0;x<T.colonnes();x++)
                {
                    eq = eq * (T.cellule(x,y) == Cellule::TypeCellule::VIDE);

                }
            }
            REQUIRE_EQ(eq,true);

        }

        SUBCASE("Import et export de terrain")
        {
            T.miseajourcellule( 4 ,9,Cellule::TypeCellule::JOUEUR);
            T.miseajourcellule( 4 ,5,Cellule::TypeCellule::AMULETTE);
            T.miseajourcellule( 2 ,1,Cellule::TypeCellule::PIECE);
            REQUIRE_EQ(T.sauvegarder("test.txt"),true);
            Terrain F{"test.txt"};
            F.sauvegarder("test2.txt");
            bool eq = true;
            for(int y=0;y<T.lignes();y++)
            {
                for(int x=0;x<T.colonnes();x++)
                {
                    std::cout << F.cellule(x,y) << " ";
                    eq = eq * (T.cellule(x,y) == F.cellule(x,y));
                }
            }
            REQUIRE_EQ(eq,true);

        }

        SUBCASE("Terrain Valide")
        {
            T.miseajourcellule( 4 ,9,Cellule::TypeCellule::JOUEUR);
            T.miseajourcellule( 4 ,5,Cellule::TypeCellule::AMULETTE);
            T.miseajourcellule( 2 ,1,Cellule::TypeCellule::PIECE);
            T.miseajourcellule( 4 ,1,Cellule::TypeCellule::SORTIE);
            bool eq = T.estvalide();
            REQUIRE(eq);

        }
        SUBCASE("Terrain INValide")
        {
            T.miseajourcellule( 4 ,9,Cellule::TypeCellule::JOUEUR);
            T.miseajourcellule( 4 ,5,Cellule::TypeCellule::AMULETTE);
            T.miseajourcellule( 2 ,1,Cellule::TypeCellule::PIECE);
            bool eq = T.estvalide();
            REQUIRE_FALSE(eq);

        }

    }

}
