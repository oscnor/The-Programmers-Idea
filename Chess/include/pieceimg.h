#ifndef PIECEIMG_H
#define PIECEIMG_H

#include <SFML/Graphics.hpp>
#include <string>


class PieceImg : public sf::Drawable, public sf::Transformable
{
public:
    /** Default constructor */
    PieceImg();
    /** Default destructor */
    virtual ~PieceImg();

    void create(const int BOARD_PADDING);
    bool load(std::string pieceImgString);
    void setNewPosition(int piece, sf::Vector2f newPosition, bool isWhite, bool taken);
    sf::Vector2f getPosition(int piece);

protected:

private:
    virtual void draw(sf::RenderTarget &Target, sf::RenderStates states) const;
    void setVerticesPositionAndCorner(sf::Vertex *_quad,int counterI, int pieceI, int whiteOffset, int pawnOffset);
    sf::VertexArray m_vertices;
    sf::Texture m_pieceImgTexture;
    const int m_square = 150;
    int m_boardPadding;
};

#endif // PIECEIMG_H
