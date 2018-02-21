#include "queen.h"

Queen::Queen(bool _isWhite): Piece(_isWhite)
{
    name = "Queen";
}

Queen::~Queen()
{
    //dtor
}

std::string Queen::whoAmI()
{
    return name;
}

bool Queen::isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove)
{
    if(newPosition == position)
    {
        return false;
    }
    if(((position.x == newPosition.x) && ((newPosition.y >= 0) && (newPosition.y < 8))) ||
       ((position.y == newPosition.y) && ((newPosition.x >= 0) && (newPosition.x < 8))) ||
       ((position.x - newPosition.x) == (position.y - newPosition.y)*-1)              ||
       ((position.x - newPosition.x) == (position.y - newPosition.y)))
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
        for(unsigned int i = 0; i < currentPlayer.size(); ++i)
        {
            // Collision on Y axis
            if(position.x == newPosition.x)
            {
                for(int j = 1; j<= difY*dirY; ++j)
                {
                    if((currentPlayer[i]->getPosition().y == position.y+j*dirY) && (currentPlayer[i]->getPosition().x == newPosition.x))
                    {
                        return false;
                    }
                    else if((opponent[i]->getPosition().y == position.y+j*dirY) && (opponent[i]->getPosition().x == newPosition.x))
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

            // Collision on X axis
            else if(position.y == newPosition.y)
            {
                for(int j = 1; j<= difX*dirX; ++j)
                {
                    if((currentPlayer[i]->getPosition().x == position.x+j*dirX) && (currentPlayer[i]->getPosition().y == newPosition.y))
                    {
                        return false;
                    }
                    else if((opponent[i]->getPosition().x == position.x+j*dirX) && (opponent[i]->getPosition().y == newPosition.y))
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

            // Diagonal collision
            else
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
        }
        if(willBeTaken)
        {
            opponent[indexOfTaken]->changeToTaken();
            if(whiteTurnToMove)
                pieceImg->setNewPosition(indexOfTaken+16, sf::Vector2f(8,8), isWhite, willBeTaken);
            else if(!whiteTurnToMove)
                pieceImg->setNewPosition(indexOfTaken, sf::Vector2f(8,8), isWhite, willBeTaken);
        }
        return true;
    }
    return false;
}


void Queen::changeToTaken()
{
    isTaken = true;
}
