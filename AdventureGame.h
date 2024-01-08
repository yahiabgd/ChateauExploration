#ifndef ADVENTUREGAME_H
#define ADVENTUREGAME_H
#include "Monstre.h"
#include <memory>
/**
    @namespace contient tout ce qui concerne la logique du jeu
*/
namespace jeu
{

/**
    @class responsable de la gestion globale du jeu
*/

class AdventureGame
{
    private:
    enum EtatJeu {DEBUT , FIN };
    public:
        AdventureGame();
        virtual ~AdventureGame();
        void commencer() const;
        EtatJeu etatJeu() const;

    private:
        //il faut un type d'affichage pour le menu et il doit etre le meme que l'affichege du terrain
        void menu() const ;
    private:
        std::vector<std::unique_ptr<Monstre>> d_monstres;
        std::unique_ptr<Aventurier> d_aventurier;
        std::unique_ptr<Terrain> d_terrain;
        //std::vector<std::unique_ptr<objetRamassable>> d_objets;


};
}

#endif // ADVENTUREGAME_H
