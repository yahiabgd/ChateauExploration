#ifndef AFFICHEURCONSOLE_H_INCLUDED
#define AFFICHEURCONSOLE_H_INCLUDED

#include "afficheur.h"

class afficheurJeuConsole : public afficheurJeu
{
public:
    ~afficheurJeuConsole();
    void affciherTerrain(const Terrain& t) const override;
    int afficherMenu()const override;
};

#endif // AFFICHEURCONSOLE_H_INCLUDED
