#ifndef BOURSE_H
#define BOURSE_H


class Bourse
{
    public:
        Bourse(int pieceMonnaie);
        int pieceMonnaie() const;
        void ajouter(int Monnaie);
        void enlever(int Monnaie);

    private:
        int d_pieceMonnaie;
};

#endif // BOURSE_H
