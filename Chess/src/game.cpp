#include "game.h"

Game::Game()
{
    win.create(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), "Chess");

    if(!boardTexture.loadFromFile("board.png"))
    {/* Errormsg */}
    else
    {
        board.setTexture(boardTexture);
    }

    // Creating images of pieces
    pieceImg.create(BOARD_PADDING);
    pieceImg.load("pieces.png");

    // Add corresponding pieces to players

    populate(&player1, true, pieceImg);
    populate(&player2, false, pieceImg);
    // Set starting position for every piece
    for(unsigned int i = 0; i < player1.size(); ++i)
    {
        player1[i]->setPosition(pieceImg.getPosition(i));
    }
    for(unsigned int i = 0; i < player2.size(); ++i)
    {
        player2[i]->setPosition(pieceImg.getPosition(i+player1.size()));
    }

    prevSelectedSquare = sf::Vector2f(-1,-1);
    selectedSquare = sf::Vector2f(-1,-1);
    squareSelected = false;
    whiteTurnToMove = true;
    prevMouseState = false;
    xPos = 'A';
    playerIndex = 0;

    currentPlayer = &player1;
    opponent      = &player2;
    selectionColor = sf::Color(204,0,102,0);
    selectedSquareIndicator.setSize(sf::Vector2f(150,150));
    selectedSquareIndicator.setPosition(0,0);
    selectedSquareIndicator.setFillColor(selectionColor);
}

Game::~Game()
{
    freeMemory(player1);
    freeMemory(player2);
    delete opponent;
    delete currentPlayer;
}

void Game::run()
{
    while (win.isOpen())
    {
        eventHandler();
        draw();
    }
}

void Game::eventHandler()
{

    sf::Event event;
    while (win.pollEvent(event))
    {
        prevMouseState = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        if (event.type == sf::Event::Closed)
        {
            win.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // Set current player and opponent
            if(whiteTurnToMove)
            {
                currentPlayer = &player1;
                opponent      = &player2;
            }
            else if(!whiteTurnToMove)
            {
                currentPlayer = &player2;
                opponent      = &player1;
            }

            if(!squareSelected)
            {
                selectedSquare = getCurrentMouseSquare(&win);
                for(unsigned int i = 0; i < currentPlayer->size(); ++i)
                {
                    if(!currentPlayer->at(i)->returnIsTaken() &&
                       ((selectedSquare.x == currentPlayer->at(i)->getPosition().x) &&
                        (selectedSquare.y == currentPlayer->at(i)->getPosition().y)))
                    {
                        squareSelected = true;
                        selectionColor.a = 125;
                        selectedSquareIndicator.setFillColor(selectionColor);
                        selectedSquareIndicator.setPosition(BOARD_PADDING + selectedSquare.x*150, BOARD_PADDING + selectedSquare.y*150);
                        playerIndex = i;
                        break;
                    }
                }
            }

            else if(squareSelected && prevMouseState)
            {
                prevSelectedSquare = selectedSquare;
                selectedSquare = getCurrentMouseSquare(&win);

                // Check if move is legal
                if(currentPlayer->at(playerIndex)->isLegal(selectedSquare, *currentPlayer, *opponent, &pieceImg, whiteTurnToMove))
                {
                    pieceImg.setNewPosition(playerIndex,selectedSquare,whiteTurnToMove, false);
                    currentPlayer->at(playerIndex)->setPosition(selectedSquare);
                    // Reset for next turn
                    whiteTurnToMove = !whiteTurnToMove;

                    squareSelected = false;
                    selectionColor.a = 0;
                    selectedSquareIndicator.setFillColor(selectionColor);

                    playerIndex = 0;
                    break;
                }
                else
                {
                    squareSelected = false;
                    selectionColor.a = 0;
                    selectedSquareIndicator.setFillColor(selectionColor);
                }
            }
        }
    }
}

void Game::draw()
{
    win.clear();
    win.draw(board);
    win.draw(selectedSquareIndicator);
    win.draw(pieceImg);
    win.display();
}

void Game::populate(std::vector<Piece*> *player, bool isWhite, PieceImg pieceImg)
{
    player->push_back(new Rook(isWhite));
    player->push_back(new Knight(isWhite));
    player->push_back(new Bishop(isWhite));
    player->push_back(new Queen(isWhite));
    player->push_back(new King(isWhite));
    player->push_back(new Bishop(isWhite));
    player->push_back(new Knight(isWhite));
    player->push_back(new Rook(isWhite));
    for(unsigned int i = 0; i < 8; ++i)
    {
        player->push_back(new Pawn(isWhite));
    }
}

void Game::freeMemory(std::vector<Piece*> player)
{
    // Delete pieces before exit to free memory
    for(unsigned int i = 0; i < player.size();++i)
    {
        delete player[i];
    }
}

sf::Vector2f Game::getCurrentMouseSquare(sf::RenderWindow *_win)
{
    sf::Vector2f pos((sf::Mouse::getPosition(*_win).x - BOARD_PADDING) / 150/* SQUARE SIZE */,
                     (sf::Mouse::getPosition(*_win).y - BOARD_PADDING) / 150/* SQUARE SIZE */);
    if(pos.y > 7)
        pos.y = 7;
    if(pos.x > 7)
        pos.x = 7;
    return pos;

}
