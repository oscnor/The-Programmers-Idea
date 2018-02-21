#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "pieceimg.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <iostream>
#include <string>
#include <vector>

class Game
{
public:
    /** Default constructor */
    Game();
    /** Default destructor */
    virtual ~Game();
    void run();

protected:

private:

    void eventHandler();
    void draw();
    void populate(std::vector<Piece*> *player, bool isWhite, PieceImg pieceImg);
    void freeMemory(std::vector<Piece*> player);

    sf::RenderWindow win;
    sf::Texture boardTexture;
    sf::Sprite board;
    sf::Vector2f getCurrentMouseSquare(sf::RenderWindow *_win);
    sf::Vector2f prevSelectedSquare;
    sf::Vector2f selectedSquare;
    sf::RectangleShape selectedSquareIndicator;
    sf::Color selectionColor;
    PieceImg pieceImg;
    std::vector<Piece*> player1, player2;
    std::vector<Piece*> *opponent;
    std::vector<Piece*> *currentPlayer;

    bool squareSelected;
    bool prevMouseState;
    bool whiteTurnToMove;
    int playerIndex;

    std::string playerName;
    char xPos;

    const int WINDOW_HEIGHT = 1280;
    const int WINDOW_WIDTH = 1280;
    const int BOARD_PADDING = 40;
};

#endif // GAME_H
