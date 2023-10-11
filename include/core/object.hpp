#pragma once

#include <vector>

#include "vector.hpp"
#include "face.hpp"
#include "half_edge.hpp"

namespace object
{

  class Object
  {
  protected:
    // A list that contains all the vertexes of the object
    std::vector<vector::Vector> vertexes;
    // A table that contains all the halfedges of the object
    std::vector<halfedge::HalfEdge> mesh;
    // A list that contains all the faces of the object
    std::vector<face::Face> faces;

  public:
    Object();
    Object(std::vector<vector::Vector> vertexes, std::vector<std::vector<int>> faces);
    Object(const Object &o);
    ~Object();

    std::vector<vector::Vector> getVertexes() const;
    std::vector<halfedge::HalfEdge> getMesh() const;
    std::vector<face::Face> getFaces() const;

    Object &operator=(const Object &o);

    void createMesh();
    void createMesh(std::vector<vector::Vector> vertexes, std::vector<std::vector<int>> faces);
  };
} // namespace object