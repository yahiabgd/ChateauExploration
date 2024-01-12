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
        int nblignes {10};
        int nbcolonnes {5};
        Terrain T{nblignes,nbcolonnes};
        SUBCASE("Constructeur et Getters correct"){
            REQUIRE_EQ(T.lignes(),nblignes);
            REQUIRE_EQ(T.colonnes(),nbcolonnes);
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
            T.miseajourcellule( nbcolonnes-1 ,nblignes-1,Cellule::TypeCellule::JOUEUR);
            T.miseajourcellule( nbcolonnes-1 ,nblignes-4,Cellule::TypeCellule::AMULETTE);
            T.miseajourcellule( nbcolonnes-3 ,nblignes-7,Cellule::TypeCellule::PIECE);
            std::string testfilename{"test.txt"};
            REQUIRE_EQ(T.sauvegarder(testfilename),true);
            Terrain F{testfilename};
            bool eq = true;
            for(int y=0;y<T.lignes();y++)
            {
                for(int x=0;x<T.colonnes();x++)
                {
                    eq = eq * (T.cellule(x,y) == F.cellule(x,y));
                }
            }
            REQUIRE_EQ(eq,true);

        }
        SUBCASE("Terrain Valide et invalide")
        {
            SUBCASE("Terrain Valide ")
            {
                T.miseajourcellule( nbcolonnes-1 ,nblignes-1,Cellule::TypeCellule::JOUEUR);
                T.miseajourcellule( nbcolonnes-1 ,nblignes-4,Cellule::TypeCellule::AMULETTE);
                T.miseajourcellule( nbcolonnes-3 ,nblignes-9,Cellule::TypeCellule::PIECE);
                T.miseajourcellule( nbcolonnes-1 ,nblignes-9,Cellule::TypeCellule::SORTIE);
                REQUIRE(T.estvalide());

        }
        SUBCASE("Terrain Invalide")
        {
            T.miseajourcellule( 4 ,9,Cellule::TypeCellule::JOUEUR);
            T.miseajourcellule( 4 ,5,Cellule::TypeCellule::AMULETTE);
            T.miseajourcellule( 2 ,1,Cellule::TypeCellule::PIECE);
            bool eq = T.estvalide();
            REQUIRE_FALSE(eq);
            }
            SUBCASE("Terrain INValide")
            {
                T.miseajourcellule( nbcolonnes-1 ,nblignes-1,Cellule::TypeCellule::JOUEUR);
                T.miseajourcellule( nbcolonnes-1 ,nblignes-4,Cellule::TypeCellule::AMULETTE);
                T.miseajourcellule( nbcolonnes-3 ,nblignes-9,Cellule::TypeCellule::PIECE);
                REQUIRE_FALSE(T.estvalide());

            }
        }

        SUBCASE("Terrain test position Valide")
        {
            REQUIRE(T.positionValide(nbcolonnes-1,nblignes-1));
            REQUIRE_FALSE(T.positionValide(nbcolonnes,nblignes));
            REQUIRE_FALSE(T.positionValide(nbcolonnes+1,nblignes+1));
        }
    }

}
