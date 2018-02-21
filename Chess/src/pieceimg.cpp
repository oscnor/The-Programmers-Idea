#include "pieceimg.h"

PieceImg::PieceImg(){};
PieceImg::~PieceImg(){};

void PieceImg::create(int BOARD_PADDING)
{
    m_boardPadding = BOARD_PADDING;
}

void PieceImg::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the pieces texture
    states.texture = &m_pieceImgTexture;

    // draw the vertex array
    target.draw(m_vertices, states);
}

bool PieceImg::load(std::string pieceImgString)
{

    // load texture
    if(!m_pieceImgTexture.loadFromFile(pieceImgString))
        return false;
    else
    {
        // Define offset for player1
        int whiteOffset = m_square*7;
        int blackPiece = 0;
        int blackOffset = 0;
        int resetRow = -8;
        int pawnOffset = -1;
        // Resize the vertex array to fit pieces
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(32*4);
        for(int i = 0; i<32; ++i)
        {
            sf::Vertex *quad = &m_vertices[i*4];
            // Check if still white pieces
            // Getting pieces from texture in order
            if(i < (5 + blackOffset))
            {
                setVerticesPositionAndCorner(quad, i - blackOffset, i - blackOffset + blackPiece, whiteOffset, 0);
            }
            // Finding Bishop with pieceI in texture
            else if(i == (5 + blackOffset))
            {
                setVerticesPositionAndCorner(quad, i - blackOffset, i - 3 - blackOffset + blackPiece, whiteOffset, 0);
            }
            // Finding Knight with pieceI in texture
            else if(i == (6 + blackOffset))
            {
                setVerticesPositionAndCorner(quad, i - blackOffset, i - 1 - blackOffset + blackPiece, whiteOffset, 0);
            }
            // Finding Rook with pieceI in texture
            else if(i == (7 + blackOffset))
            {
                setVerticesPositionAndCorner(quad, i - blackOffset, i - 7 - blackOffset + blackPiece, whiteOffset, 0);
            }
            // Finding Pawn with pieceI in texture and offsetting to place pawn on correct row
            else if(i > (7 + blackOffset) && i < (16 + blackOffset))
            {
                setVerticesPositionAndCorner(quad, i + resetRow, 6 + blackPiece, whiteOffset, m_square * pawnOffset);
            }
            if(i==15)
            {
                whiteOffset = 0;
                blackPiece = 7;
                blackOffset = 16;
                resetRow = -24;
                pawnOffset = 1;
            }
        }
    }
    return true;
}

void PieceImg::setNewPosition(int piece, sf::Vector2f newPosition, bool isWhite, bool taken)
{
    sf::Vertex *quad;
    if(isWhite)
    {
        quad = &m_vertices[piece*4];
    }
    else
    {
        piece += 16;
        quad = &m_vertices[piece*4];
    }
    if(taken)
    {
        quad[0].texCoords = sf::Vector2f(0,0);
        quad[1].texCoords = sf::Vector2f(0,0);
        quad[2].texCoords = sf::Vector2f(0,0);
        quad[3].texCoords = sf::Vector2f(0,0);
    }
    else
    {
        quad[0].position = sf::Vector2f((newPosition.x * m_square) + m_boardPadding           , (newPosition.y * m_square) + m_boardPadding);
        quad[1].position = sf::Vector2f((newPosition.x * m_square) + m_boardPadding + m_square, (newPosition.y * m_square) + m_boardPadding);
        quad[2].position = sf::Vector2f((newPosition.x * m_square) + m_boardPadding + m_square, (newPosition.y * m_square) + m_boardPadding + m_square);
        quad[3].position = sf::Vector2f((newPosition.x * m_square) + m_boardPadding           , (newPosition.y * m_square) + m_boardPadding + m_square);
    }
}

sf::Vector2f PieceImg::getPosition(int piece)
{
    sf::Vertex *quad = &m_vertices[piece*4];
    sf::Vector2f _position((quad[0].position.x - m_boardPadding) / m_square,(quad[0].position.y - m_boardPadding) / m_square);
    return _position;
}

void PieceImg::setVerticesPositionAndCorner(sf::Vertex *_quad, int counterI, int pieceI, int _whiteOffset, int _pawnOffset)
{
    // Define corners
    _quad[0].position = sf::Vector2f((counterI * m_square) + m_boardPadding           , m_boardPadding + _whiteOffset + _pawnOffset);
    _quad[1].position = sf::Vector2f((counterI * m_square) + m_boardPadding + m_square, m_boardPadding + _whiteOffset + _pawnOffset);
    _quad[2].position = sf::Vector2f((counterI * m_square) + m_boardPadding + m_square, m_boardPadding + _whiteOffset + _pawnOffset + m_square);
    _quad[3].position = sf::Vector2f((counterI * m_square) + m_boardPadding           , m_boardPadding + _whiteOffset + _pawnOffset + m_square);

    // Define texture coordinates
    _quad[0].texCoords = sf::Vector2f( pieceI * m_square             , 0);
    _quad[1].texCoords = sf::Vector2f((pieceI * m_square) + m_square , 0);
    _quad[2].texCoords = sf::Vector2f((pieceI * m_square) + m_square , m_square);
    _quad[3].texCoords = sf::Vector2f( pieceI * m_square             , m_square);
}

