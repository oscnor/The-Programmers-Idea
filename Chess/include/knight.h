#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"


class Knight : public Piece
{
public:
    Knight(bool _isWhite);
    virtual ~Knight();

    std::string whoAmI();
    bool isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer,std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove);
    void changeToTaken();

protected:

private:
    std::string name;
};

#endif // KNIGHT_H
