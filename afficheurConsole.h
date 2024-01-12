#ifndef AFFICHEURCONSOLE_H_INCLUDED
#define AFFICHEURCONSOLE_H_INCLUDED
#include<memory>
#include "afficheur.h"

class Position;

class AfficheurJeuConsole : public AfficheurJeu
{
public:
    ~AfficheurJeuConsole();
    void AffciherTerrain(const Terrain& t) const override;
    void AffciherTitre() const override;
    void AfficherInstruction() const override;
    void AffciherInfoAventurier(const Aventurier& aventurier) const override;
    void AffciherInfoMonstre(const std::shared_ptr<Monstre>monstre) const override;
    int AfficherMenu(const std::vector<std::string>& menu)const override;
    std::string Input(const std::string& str = "") const override;
    void Print(const std::string& str) const override;
    void PrintError(const std::string& str) const override;
    void effacer() const override ;
    void AttendAppuisSurBoutton(const char c)const ;
    void MiseAJourContenuTerrain(Terrain& t);
    Position getPositionCurseur() const override;
    void setPositionCursor(const Position& p) const override;

};

#endif // AFFICHEURCONSOLE_H_INCLUDED
