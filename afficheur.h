#ifndef AFFICHEUR_H_INCLUDED
#define AFFICHEUR_H_INCLUDED

class Terrain;

class afficheurJeu
{
public:
    virtual ~afficheurJeu(){}
    virtual void affciherTerrain(const Terrain& t) const =0 ;
    virtual int afficherMenu()const =0;
};


#endif // AFFICHEUR_H_INCLUDED
