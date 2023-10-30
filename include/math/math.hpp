#pragma once

#include <core/vector.hpp>
#include <cmath>

namespace Math
{

  double angle(HalfMesh::Vector *v1, HalfMesh::Vector *v2);
  double angle(HalfMesh::Vertex v1, HalfMesh::Vertex v2);
  double length(HalfMesh::Vector *v1, HalfMesh::Vector *v2);
  double length(HalfMesh::Vertex v, HalfMesh::Vertex v2);
  double dot(HalfMesh::Vertex v1, HalfMesh::Vertex v2);
  double dot(HalfMesh::Vector *v1, HalfMesh::Vector *v2);
  HalfMesh::Vector *dot(double scalar, HalfMesh::Vector *v);
  HalfMesh::Vertex dot(double scalar, HalfMesh::Vertex v);
  double v_module(HalfMesh::Vertex v);
  double v_module(HalfMesh::Vector *v);

  HalfMesh::Vector *normalize(HalfMesh::Vector *v);
  HalfMesh::Vertex normalize(HalfMesh::Vertex v);
  HalfMesh::Vector *cross(HalfMesh::Vector *v1, HalfMesh::Vector *v2);
  HalfMesh::Vertex cross(HalfMesh::Vertex v1, HalfMesh::Vertex v2);

} // namespace Math