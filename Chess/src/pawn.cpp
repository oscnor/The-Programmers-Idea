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
    // Prevent no movement
    if(newPosition == position)
    {
        return false;
    }
    // Is next move 1 forward or if starting move 1 or 2 forward
    if(((newPosition.y == position.y+(1*colorMult))
        || ((startingPos == position.y) && (newPosition.y == position.y+(2*colorMult))))
        && (position.x == newPosition.x))
    {
        // Is piece blocked by own team piece
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
        // Is move colliding with opponent
        for(unsigned int i = 0; i < opponent.size(); ++i)
        {
            if(newPosition == opponent[i]->getPosition() &&
            ((newPosition.x == position.x+1 || newPosition.x == position.x-1)
             && newPosition.y == position.y+(1*colorMult)))
            {
                // Take opponent
                opponent[i]->changeToTaken();
                pieceImg->setNewPosition(i, sf::Vector2f(8,8), !isWhite, true);
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
