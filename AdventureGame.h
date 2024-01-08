#ifndef ADVENTUREGAME_H
#define ADVENTUREGAME_H

#include <vector>
#include <memory>

#include "Monstre.h"
#include "Aventurier.h"
#include "Terrain.h"

class afficheurJeu;


/**
    @class responsable de la gestion globale du jeu
*/

class AdventureGame
{
    public:
        AdventureGame();
        virtual ~AdventureGame();
        void commencer(const afficheurJeu& afficheur);
        bool finJeu() const;

    private:
        void ModifierTerrain(const afficheurJeu& afficheur);

        void commencerJeu(const afficheurJeu& afficheur);
    private:
        std::vector<std::unique_ptr<Monstre>> d_monstres;
        std::unique_ptr<Aventurier> d_aventurier;

        std::unique_ptr<Terrain> d_terrain;
//        std::vector<std::unique_ptr<objetRamassable>> d_objets;
};


#endif // ADVENTUREGAME_H
