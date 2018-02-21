#include "pawn.h"

#include <iostream>


Pawn::Pawn(bool _isWhite):Piece(_isWhite)
{
    name = "Pawn";
    if(isWhite)
    {
        colorMult = -1;
        startingPos = 6;
    }
    else if(!isWhite)
    {
        colorMult = 1;
        startingPos = 1;
    }
}

Pawn::~Pawn()
{
    //dtor
}

std::string Pawn::whoAmI()
{
    return name;
}

bool Pawn::isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove)
{




    if(newPosition == position)
    {
        return false;
    }
    if(((newPosition.y == position.y+(1*colorMult))
        || ((startingPos == position.y) && (newPosition.y == position.y+(2*colorMult))))
        && (position.x == newPosition.x))
    {
        for(unsigned int i = 0; i < currentPlayer.size(); ++i)
        {
            if((currentPlayer[i]->getPosition().x == position.x) &&
               ((currentPlayer[i]->getPosition().y == newPosition.y) ||
                (currentPlayer[i]->getPosition().y == newPosition.y)))
            {
                return false;
            }
        }
        startingPos = 9;
        return true;
    }
    else
    {
        for(unsigned int i = 0; i < opponent.size(); ++i)
        {
            if(newPosition == opponent[i]->getPosition() &&
            ((newPosition.x == position.x+1 || newPosition.x == position.x-1)
             && newPosition.y == position.y+(1*colorMult)))
            {

                /** Only black pawns are getting taken????*/


                opponent[i]->changeToTaken();
                if(whiteTurnToMove)
                    pieceImg->setNewPosition(i+16, sf::Vector2f(8,8), isWhite, true);
                else if(!whiteTurnToMove){
                    pieceImg->setNewPosition(i, sf::Vector2f(8,8), isWhite, true);
                    std::cout << "i=" << i <<  std::endl;
                }
                return true;
            }
        }
    }
    return false;
}

void Pawn::changeToTaken()
{
    isTaken = true;
}
