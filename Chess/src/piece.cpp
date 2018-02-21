#include "piece.h"

Piece::Piece(bool _isWhite)
{
    isWhite = _isWhite;
    isTaken = false;
    willBeTaken = false;
}

Piece::~Piece()
{
    //dtor
}

sf::Vector2f Piece::getPosition()
{
    return position;
}

void Piece::setPosition(sf::Vector2f newPos)
{
    position = newPos;
}

bool Piece::returnIsWhite()
{
    return isWhite;
}
bool Piece::returnIsTaken()
{
    return isTaken;
}
