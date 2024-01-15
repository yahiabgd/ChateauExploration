#ifndef ADVENTUREGAME_H
#define ADVENTUREGAME_H
#include <vector>
#include <memory>

#include "Monstre.h"
#include "Aventurier.h"
#include "Terrain.h"
#include "ObjetRamassable.h"
class AfficheurJeu;


/**
    @class responsable de la gestion globale du jeu
*/

class AdventureGame
{
    public:
        AdventureGame();
        AdventureGame(const Aventurier& aventurier, const std::vector<std::shared_ptr<Monstre>>& monstres
                      ,std::vector<std::shared_ptr<ObjetRamassable>>&objets, const std::string& fichierTerrain);
        AdventureGame(const Aventurier& aventurier, const std::vector<std::shared_ptr<Monstre>>& monstres ,
                      std::vector<std::shared_ptr<ObjetRamassable>>&objets, const Terrain& terrain);
        AdventureGame( const Terrain& terrain);

        virtual ~AdventureGame();
        void commencer(const AfficheurJeu& afficheur);
        bool finJeu() const;
        void Initialiserlejeu();


    private:
        void ActeAventurier(const AfficheurJeu& afficheur);
        void ActeMonstre();
        void inisialiserMap();
        void DeplacerAventurier(const Position& position);
        void ChangerTerrain(const AfficheurJeu& afficheur);
        void ConfigurerTerrain(const AfficheurJeu& afficheur);
        int getMonstreIndiceParPosition(const Position& position);
        void commencerJeu(const AfficheurJeu& afficheur);
        int getObjetIndiceParPosition(const Position& position);

        void changementContenuTerrain(const AfficheurJeu& afficheur);
        void creerTerrain(const AfficheurJeu& afficheur);
        void ImportTerrain(const AfficheurJeu& afficheur);
    private:
        Aventurier d_aventurier;
        std::vector<std::shared_ptr<Monstre>> d_monstres;
        std::vector<std::shared_ptr<ObjetRamassable>> d_objets;
        Terrain d_terrain;
        std::string d_fichierSauvegarde;
        const std::string TERRAIN_PAR_DEFAUT{"testmap.txt"};
        const std::string SAUVEGARDE_PAR_DEFAUT{"restor.txt"};
        bool d_finjeu;
};


#endif // ADVENTUREGAME_H
