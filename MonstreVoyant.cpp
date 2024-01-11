#include "MonstreVoyant.h"


MonstreVoyant::MonstreVoyant(int pointForce, int pointVie, Position position, int habilete):
    Monstre{pointForce,pointVie, position,habilete}
{
    //ctor
}

MonstreVoyant::~MonstreVoyant()
{
    //dtor
}


void MonstreVoyant::deplacervers( Aventurier& aventurier, Terrain& terrain){
    std::cout<<"deplcer vers";
    if(aventurier.position().distance(d_position)<=8){
        std::cout<<aventurier.position().distance(d_position);
        if(aventurier.position().distance(d_position)==1){
            attaque(aventurier);
            return;
        }

        std::vector<Position> chemain = MonstreVoyant::cheminVersAventurier(aventurier, terrain);
        std::cout<<chemain[1].x()<<"  "<<chemain[1].y();
        //cellules[d_position.x()][d_position.y()].changecontenu(Cellule::TypeCellule::VIDE);
        terrain.miseajourcellule(d_position.x(),d_position.y(),Cellule::TypeCellule::VIDE);

        d_position.deplacerEn( chemain[1].x(),chemain[1].y()) ;
        std::cout<<" updated"<<d_position.x()<<"  "<<d_position.y();
        terrain.miseajourcellule(d_position.x(),d_position.y(),Cellule::TypeCellule::MONSTRE);
        return;
    }
     std::cout<<"deplcer fd";
    deplacementAleatoire(terrain);
}

void MonstreVoyant::deplacementAleatoire(Terrain& terrain){
    //seulement vertical et horizontal
    //                              up,     down,   left,    right
     const int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int i=0;
    do{
        i = rand() % 4;
    }while(!terrain.positionValide(d_position.x()+directions[i][0],
                                   d_position.y() + directions[i][1]));
    terrain.miseajourcellule(d_position.x(),d_position.y(),Cellule::TypeCellule::VIDE);
    d_position.deplacerDe(directions[i][0],directions[i][1]);
    terrain.miseajourcellule(d_position.x(),d_position.y(),Cellule::TypeCellule::MONSTRE);
}

 std::vector<Position> MonstreVoyant::cheminVersAventurier(const Aventurier& aventurier, Terrain& terrain){
     std::cout<<"chemain vers";
    // Possible movement directions (4 directions: up, down, left, right)
    const int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // Position start = d_position;
    // Position goal = aventurier.position();
    // Create a queue for BFS
    std::queue<Position> q;

    // Create a 2D vector to track whether a Point has been visited
    std::vector<std::vector<bool>> visited(terrain.colonnes(), std::vector<bool>(terrain.lignes(), false));

    // Create a 2D vector to store parent information for backtracking
    std::vector<std::vector<Position>> parent(terrain.colonnes(), std::vector<Position>(terrain.lignes(), {-1, -1}));

    // Add the starting point to the queue and mark it as visited
    q.push(d_position);
    visited[d_position.x()][d_position.y()] = true;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();

        // Check if the current point is the goal
        if (current.x() == aventurier.position().x() && current.y() == aventurier.position().y()) {
            // Reconstruct the path using parent information
            std::vector<Position> path;
            while (parent[current.x()][current.y()].x() != -1) {
                path.push_back(current);
                current = parent[current.x()][current.y()];
            }
            path.push_back(d_position);
            reverse(path.begin(), path.end());
            return path;
        }

        // Explore neighbors
        for (const auto& dir : directions) {
            int newX = current.x() + dir[0];
            int newY = current.y() + dir[1];

            // Check if the new position is valid and has not been visited
            if (terrain.positionValide(newX, newY) && !visited[newX][newY]) {
                // Mark the neighbor as visited and enqueue it
                q.push({newX, newY});
                visited[newX][newY] = true;

                // Update parent information for backtracking
                parent[newX][newY] = current;
            }
        }
    }

    // If the queue is empty and the goal is not reached, return an empty path
    return {};

}
