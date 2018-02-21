#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"


class Queen : public Piece
{
public:
    Queen(bool _isWhite);
    virtual ~Queen();

    std::string whoAmI();
    bool isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove);
    void changeToTaken();

protected:

private:
    std::string name;
    int dirX, dirY, difX, difY;
};

#endif // QUEEN_H
