#ifndef AFFICHEUR_H_INCLUDED
#define AFFICHEUR_H_INCLUDED

#include <vector>
#include <string>
class Terrain;

class afficheurJeu
{
public:
    virtual ~afficheurJeu(){}
    virtual void affciherTerrain(const Terrain& t) const =0 ;
    virtual int afficherMenu(const std::vector<std::string>& menu)const =0;
//    virtual void afficherString(const std::string& str) const =0;
};


#endif // AFFICHEUR_H_INCLUDED
