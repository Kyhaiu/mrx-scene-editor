#include <utils/sfml-utils.hpp>
#include <core/vertex.hpp>
#include <core/half_edge.hpp>
#include <core/vector.hpp>

namespace utils
{
  /**
   * @brief Convert the Core::Vertex::Vertex to a sf::Vertex
   *
   * @param vertex A Core::Vertex::Vertex to convert
   * @return sf::Vertex The converted sf::Vertex
   */
  sf::Vertex to_sfml_vertex(const Core::Vertex::Vertex &vertex)
  {
    return sf::Vertex(sf::Vector2f(vertex.x, vertex.y), sf::Color::White);
  }

  /**
   * @brief Draw a Core::Vertex::Vertex
   *
   * @param vertex A Core::Vertex::Vertex to draw
   * @param window The sf::RenderWindow to draw the vertex on
   */
  void draw_vertex(const Core::Vertex::Vertex &vertex, sf::RenderWindow &window)
  {
    sf::CircleShape circle(5);
    circle.setFillColor(sf::Color::White);
    circle.setPosition(vertex.x, vertex.y);
    window.draw(circle);
  }

  /**
   * @brief Draw a Core::HalfEdge
   *
   * @param half_edge A Core::HalfEdge to draw
   * @param window The sf::RenderWindow to draw the half edge on
   */
  void draw_half_edge(Core::HalfEdge &half_edge, sf::RenderWindow &window)
  {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(half_edge.getOrigin()->getX(), half_edge.getOrigin()->getY()), sf::Color::White),
        sf::Vertex(sf::Vector2f(half_edge.getNext()->getOrigin()->getX(), half_edge.getNext()->getOrigin()->getX()), sf::Color::White)};

    window.draw(line, 2, sf::Lines);
  }
} // namespace utils