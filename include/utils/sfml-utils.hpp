#pragma once

#include <SFML/Graphics.hpp>
#include <gui/imgui/imgui.h>
#include <core/common.hpp>

namespace utils
{
  // Convert the Core::Vertex:Vertex to a sf::Vertex
  sf::Vertex to_sfml_vertex(const Core::Vertex::Vertex &vertex);

  // Draw a Core::Vertex:Vertex
  void draw_vertex(const Core::Vertex::Vertex &vertex, sf::RenderWindow &window);

  // Draw a Core::HalfEdge
  void draw_half_edge(Core::HalfEdge &half_edge, sf::RenderWindow &window);
} // namespace utils