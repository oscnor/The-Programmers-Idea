#ifndef PAWN_H
#define PAWN_H

#include "piece.h"


class Pawn : public Piece
{
public:
    Pawn(bool _isWhite);
    virtual ~Pawn();

    std::string whoAmI();
    bool isLegal(sf::Vector2f newPosition,std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove);
    void changeToTaken();

protected:

private:
    std::string name;
    int colorMult;
    int startingPos;
};

#endif // PAWN_H
