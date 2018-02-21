#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <string>


class Bishop : public Piece
{
public:
    Bishop(bool _isWhite);
    virtual ~Bishop();

    std::string whoAmI();
    bool isLegal(sf::Vector2f newPosition ,std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove);
    void changeToTaken();

protected:

private:
    std::string name;
    int dirX, dirY, difX, difY;
};

#endif // BISHOP_H
