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
    private:
    enum EtatJeu {DEBUT , FIN };
    public:
        AdventureGame();
        AdventureGame(const Aventurier& aventurier, const std::vector<Monstre>& monstres , const std::string& fichierTerrain);
        AdventureGame(const Aventurier& aventurier, const std::vector<Monstre>& monstres , const Terrain& terrain);

        virtual ~AdventureGame();
        void commencer(const AfficheurJeu& afficheur);
        bool finJeu() const;

    private:
        void ModifierTerrain(const AfficheurJeu& afficheur);

        void commencerJeu(const AfficheurJeu& afficheur);
    private:
        std::unique_ptr<Aventurier> d_aventurier;
        std::vector<std::unique_ptr<Monstre>> d_monstres;
        std::unique_ptr<Terrain> d_terrain;
        static std::string DEFAUT_TERRAIN;
};


#endif // ADVENTUREGAME_H
