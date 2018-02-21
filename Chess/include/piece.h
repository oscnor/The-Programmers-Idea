#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "pieceimg.h"


class Piece
{
public:
    /** Default constructor */

    Piece(bool _isWhite);

    /** Default destructor */
    virtual ~Piece();

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f newPos);
    virtual std::string whoAmI() = 0;
    virtual bool isLegal(sf::Vector2f newPosition, std::vector<Piece*> currentPlayer, std::vector<Piece*> opponent, PieceImg *pieceImg, bool whiteTurnToMove) = 0;
    virtual void changeToTaken() = 0;
    bool returnIsWhite();
    bool returnIsTaken();


protected:
    sf::Vector2f position;
    bool isWhite, isTaken, willBeTaken;
    int indexOfTaken;



private:

};

#endif // PIECE_H
