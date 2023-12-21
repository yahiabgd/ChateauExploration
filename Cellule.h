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
        FIN = '-',
        HORS='*',
        };
        Cellule(const TypeCellule type);
        TypeCellule contenu() const;
        void changecontenu(const TypeCellule contenu);
    private:
        TypeCellule d_contenu;
};

#endif // CELLULE_H
