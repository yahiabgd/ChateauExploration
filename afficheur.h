#ifndef AFFICHEUR_H_INCLUDED
#define AFFICHEUR_H_INCLUDED

#include <vector>
#include <string>
class Terrain;
class Aventurier;
class Monstre;

class AfficheurJeu
{
public:
    virtual ~AfficheurJeu(){}
    virtual void AffciherTerrain(const Terrain& t) const =0 ;
    virtual void AffciherTitre() const =0;
    virtual void AfficherInstruction() const = 0;
    virtual void AffciherInfoAventurier(const Aventurier& aventurier) const =0;
    virtual void AffciherInfoMonstre(const std::shared_ptr<Monstre>monstre) const =0;
    virtual int AfficherMenu(const std::vector<std::string>& menu)const =0;
    virtual std::string Input(const std::string& str = "") const =0;
    virtual void Print(const std::string& str) const =0;
    virtual void PrintError(const std::string& str) const =0;
};


#endif // AFFICHEUR_H_INCLUDED
