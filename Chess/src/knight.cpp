#include "knight.h"
#include <iostream>
Knight::Knight(bool _isWhite): Piece(_isWhite)
{
    name = "Knight";
}

Knight::~Knight()
{
    //dtor
}

std::string Knight::whoAmI()
{
    return name;
}

bool Knight::isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove)
{
    if(newPosition == position)
    {
        return false;
    }
    if(((position.x + 2 == newPosition.x) && ((position.y + 1 == newPosition.y) || (position.y - 1 == newPosition.y))) ||
       ((position.x - 2 == newPosition.x) && ((position.y + 1 == newPosition.y) || (position.y - 1 == newPosition.y))) ||
       ((position.x + 1 == newPosition.x) && ((position.y + 2 == newPosition.y) || (position.y - 2 == newPosition.y))) ||
       ((position.x - 1 == newPosition.x) && ((position.y + 2 == newPosition.y) || (position.y - 2 == newPosition.y))))
    {
        for(unsigned int i = 0; i < opponent.size(); ++i)
        {
            if(currentPlayer[i]->getPosition() == newPosition)
            {
                return false;
            }
            else if(opponent[i]->getPosition() == newPosition)
            {
                opponent[i]->changeToTaken();
                if(whiteTurnToMove)
                {
                    pieceImg->setNewPosition(i+16, sf::Vector2f(8,8), isWhite, true);
                }
                else if(!whiteTurnToMove)
                {
                    pieceImg->setNewPosition(i, sf::Vector2f(8,8), isWhite, true);
                }
            }
        }
        return true;
    }
    return false;
}

void Knight::changeToTaken()
{
    isTaken = true;
}
