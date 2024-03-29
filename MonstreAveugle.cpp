#include "MonstreAveugle.h"
#include "math.h"

MonstreAveugle::MonstreAveugle(int pointForce, int pointVie, Position position, int habilete):
    Monstre{pointForce, pointVie, position, habilete}
{
    //ctor
}

MonstreAveugle::~MonstreAveugle()
{
    //dtor
}

void MonstreAveugle::deplacervers(Aventurier& aventurier,  Terrain& terrain) {
    //std::cout<<"monstre aveugle";
    if( aventurier.position().distance(d_position)<=sqrt(2) ) {
        // il va attaqu� l'Aventurier
        Monstre::attaque(aventurier); // il manque traiter le cas lorsque l'aventurier est entre deux mur
        return;
    }

    deplacementAleatoire(terrain);
}

void MonstreAveugle::deplacementAleatoire(Terrain& terrain){
    // il peut se d�placer en diagonale

    const int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    int i = 0;
    int NewX;
    int NewY;
    //std::cout<<d_position.x()<<"  "<<d_position.y();
    bool entreDeuxMur;
     do{
        entreDeuxMur = false;
        i = rand()%8;
        NewX = d_position.x()+directions[i][0];
        NewY = d_position.y() + directions[i][1];

        if ( abs(directions[i][0]) + abs(directions[i][1]) == 2 ){
            if(terrain.cellule( NewX , d_position.y() ) == Cellule::TypeCellule::MUR &&
               terrain.cellule( d_position.x() , NewY ) == Cellule::TypeCellule::MUR )
               {
                    entreDeuxMur = true;
               }
        }
     }while(!terrain.positionValide(NewX,NewY)
            ||terrain.cellule( NewX , NewY ) == Cellule::TypeCellule::MUR
            ||terrain.cellule( NewX , NewY ) == Cellule::TypeCellule::MONSTRE || terrain.cellule( NewX , NewY ) == Cellule::TypeCellule::SMONSTRE|| terrain.cellule( NewX , NewY ) == Cellule::TypeCellule::HORS
            || entreDeuxMur);

    terrain.miseajourcellule(d_position.x(),d_position.y(),estSur());
    d_position.deplacerDe(directions[i][0],directions[i][1]);
    Cellule NewCellule = terrain.cellule(d_position.x(),d_position.y());
    modifieEstSur(NewCellule.contenu());
    terrain.miseajourcellule(d_position.x(),d_position.y(),Cellule::TypeCellule::MONSTRE);

    //std::cout<<d_position.x()<<"  "<<d_position.y();

}
