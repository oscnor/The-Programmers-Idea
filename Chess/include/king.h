#ifndef KING_H
#define KING_H

#include "piece.h"


class King : public Piece
{
public:
    King(bool _isWhite);
    virtual ~King();

    std::string whoAmI();
    bool isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove);
    void changeToTaken();

protected:

private:
    std::string name;
};

#endif // KING_H
