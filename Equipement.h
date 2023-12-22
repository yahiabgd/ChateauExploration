#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H


class Equipement
{
    public:
        Equipement(int pointSolidite);
        virtual ~Equipement() = default;
        virtual void reduireSolidite(int force)=0;
        void reparer(int pieceMonnaie);
        int pointSolide() const;

    protected:
        int d_pointSolidite;
};

#endif // EQUIPEMENT_H
