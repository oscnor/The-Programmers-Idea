#include "king.h"

King::King(bool _isWhite): Piece(_isWhite)
{
    name = "King";
}

King::~King()
{
    //dtor
}

std::string King::whoAmI()
{
    return name;
}

bool King::isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove)
{
    if(newPosition == position)
    {
        return false;
    }
    if(((newPosition.x == position.x-1) ||
        (newPosition.x == position.x  ) ||
        (newPosition.x == position.x+1))
    && ((newPosition.y == position.y-1) ||
        (newPosition.y == position.y  ) ||
        (newPosition.y == position.y+1)))
        {
            for(unsigned int i = 0; i < opponent.size(); ++i)
            {
                if(opponent[i]->getPosition() == newPosition)
                {
                    opponent[i]->changeToTaken();
                    if(whiteTurnToMove)
                        pieceImg->setNewPosition(i+16, sf::Vector2f(8,8), isWhite, true);
                    else if(!whiteTurnToMove)
                        pieceImg->setNewPosition(i, sf::Vector2f(8,8), isWhite, true);
                }
                else if(currentPlayer[i]->getPosition() == newPosition)
                {
                    return false;
                }
            }
            return true;
        }
    return false;
}


void King::changeToTaken()
{
    isTaken = true;
}
