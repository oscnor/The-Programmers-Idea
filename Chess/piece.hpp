#ifndef PIECES_HPP
#define PIECES_HPP

class Pieces: public sf::Drawable, public sf::Transformable
{
private:
    virtual void draw(sf::RenderTarget &target. sf::RenderStates states) const;
    sf::VertexArray verticies;
    sf::Texture textu;
};
#endif // PIECE_HPP
