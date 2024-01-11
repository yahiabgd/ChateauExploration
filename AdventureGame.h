#ifndef ADVENTUREGAME_H
#define ADVENTUREGAME_H
#include <vector>
#include <memory>

#include "Monstre.h"
#include "Aventurier.h"
#include "Terrain.h"

class AfficheurJeu;


/**
    @class responsable de la gestion globale du jeu
*/

class AdventureGame
{
    public:
        AdventureGame();
        AdventureGame(const Aventurier& aventurier, const std::vector<Monstre>& monstres , const std::string& fichierTerrain);
        AdventureGame(const Aventurier& aventurier, const std::vector<Monstre>& monstres , const Terrain& terrain);

        virtual ~AdventureGame();
        void commencer(const AfficheurJeu& afficheur);
        bool finJeu() const;



    private:
        void ActeAventurier();
        void DeplacerAventurier(const Position& position);
        void ChangerTerrain(const AfficheurJeu& afficheur);
        void ConfigurerTerrain(const AfficheurJeu& afficheur);
        int getMonstreIndiceParPosition(const Position& position);

        void commencerJeu(const AfficheurJeu& afficheur);

        Aventurier d_aventurier;
        std::vector<std::unique_ptr<Monstre>> d_monstres;
        Terrain d_terrain;
        const std::string DEFAUT_TERRAIN{"testmain.txt"};
};


#endif // ADVENTUREGAME_H
