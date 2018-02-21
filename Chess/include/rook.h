#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <vector>
#include <iostream>

class Rook : public Piece
{
public:
    Rook(bool _isWhite);
    virtual ~Rook();

    std::string whoAmI();
    bool isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove);
    void changeToTaken();

protected:

private:
    std::string name;
    int dirX, dirY, difX, difY;


};

#endif // ROOK_H
