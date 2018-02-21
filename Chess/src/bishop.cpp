#include "bishop.h"
#include <iostream>
Bishop::Bishop(bool _isWhite):Piece( _isWhite)
{
    name = "Bishop";
}

Bishop::~Bishop()
{
    //dtor
}
std::string Bishop::whoAmI()
{
    return name;
}

bool Bishop::isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove)
{
    if(newPosition == position)
    {
        return false;
    }
    if(((position.x - newPosition.x) == ((position.y - newPosition.y)*-1))
       ||((position.x - newPosition.x) == (position.y - newPosition.y)))
    {
        difX = 0;
        difY = 0;
        dirX = 1;
        dirY = 1;

        difY = newPosition.y - position.y;
        difX = newPosition.x - position.x;
        if(difY < 0)
            dirY = -1;
        if(difX < 0)
            dirX = -1;

        // Check for collision on the way to target
        for(unsigned int i = 0; i < currentPlayer.size(); ++i)
        {
            for(int j = 1; j<= difX*dirX; ++j)
            {
                if((currentPlayer[i]->getPosition().y == position.y+j*dirY) && (currentPlayer[i]->getPosition().x == position.x+j*dirX))
                {
                    return false;
                }
                else if((opponent[i]->getPosition().y == position.y+j*dirY) && (opponent[i]->getPosition().x == position.x+j*dirX))
                {
                    if(opponent[i]->getPosition() == newPosition)
                    {
                        willBeTaken = true;
                        indexOfTaken = i;
                    }
                    else
                        return false;
                }
            }
        }
        if(willBeTaken)
        {
            opponent[indexOfTaken]->changeToTaken();
            if(whiteTurnToMove)
            {
                pieceImg->setNewPosition(indexOfTaken+16, sf::Vector2f(8,8), isWhite, willBeTaken);
            }
            else if(!whiteTurnToMove)
            {
                pieceImg->setNewPosition(indexOfTaken, sf::Vector2f(8,8), isWhite, willBeTaken);
            }
        }
        return true;
    }
    return false;
}

void Bishop::changeToTaken()
{
    isTaken = true;
}
