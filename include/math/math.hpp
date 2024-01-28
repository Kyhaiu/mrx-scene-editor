#pragma once

#include <core/vector.hpp>
#include <cmath>

#include <vector>

namespace Math
{

  double angle(Core::Vector *v1, Core::Vector *v2);
  double angle(Core::Vertex::Vertex v1, Core::Vertex::Vertex v2);
  double length(Core::Vector *v1, Core::Vector *v2);
  double length(Core::Vertex::Vertex v, Core::Vertex::Vertex v2);
  double dot(Core::Vertex::Vertex v1, Core::Vertex::Vertex v2);
  double dot(Core::Vector *v1, Core::Vector *v2);
  Core::Vector *dot(double scalar, Core::Vector *v);
  Core::Vertex::Vertex dot(double scalar, Core::Vertex::Vertex v);
  double v_module(Core::Vertex::Vertex v);
  double v_module(Core::Vector *v);

  Core::Vector *normalize(Core::Vector *v);
  Core::Vertex::Vertex normalize(Core::Vertex::Vertex v);
  Core::Vector *cross(Core::Vector *v1, Core::Vector *v2);
  Core::Vertex::Vertex cross(Core::Vertex::Vertex v1, Core::Vertex::Vertex v2);

  std::vector<std::vector<double>> multiply_matrix(std::vector<std::vector<double>> m1, std::vector<std::vector<double>> m2);

  void apply_matrix(Core::Vector *v, std::vector<std::vector<double>> m);

} // namespace Math