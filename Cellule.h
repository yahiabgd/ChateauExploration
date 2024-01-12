#ifndef CELLULE_H
#define CELLULE_H


class Cellule
{
    public:
        enum TypeCellule : char{
        VIDE = ' ',
        MUR = '#',
        AMULETTE = 'A',
        MONSTRE = 'm',
        SMONSTRE = 'M',
        JOUEUR = 'P',
        PIECE = '$',
        SORTIE = '-',
        HORS='*',
        };

        static bool estType(char type);
        Cellule(const TypeCellule type);
        TypeCellule contenu() const;
        void changecontenu(const TypeCellule contenu);
    private:
        TypeCellule d_contenu;
};
Cellule::TypeCellule toTypeCellule(const char c);

#endif // CELLULE_H
