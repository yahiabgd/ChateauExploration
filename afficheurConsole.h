#ifndef AFFICHEURCONSOLE_H_INCLUDED
#define AFFICHEURCONSOLE_H_INCLUDED

#include "afficheur.h"

class AfficheurJeuConsole : public AfficheurJeu
{
public:
    ~AfficheurJeuConsole();
    void AffciherTerrain(const Terrain& t) const override;
    int AfficherMenu(const std::vector<std::string>& menu)const override;
    std::string Input(const std::string& str = "") const override;
    void Print(const std::string& str) const override;
    void PrintError(const std::string& str) const override;
    void AttendAppuisSurBoutton(const char c)const ;

};

#endif // AFFICHEURCONSOLE_H_INCLUDED
