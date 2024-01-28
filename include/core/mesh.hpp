#pragma once

#include <core/common.hpp>

namespace Core
{

  class Mesh
  {
  protected:
    // A list that contains all the vertexes of the object
    std::vector<Vector *> vertexes;
    // A table that contains all the halfedges of the object
    std::vector<HalfEdge *> mesh;
    // A list that contains all the faces of the object
    std::vector<Face *> faces;
    // The number of faces of the object
    int num_faces;
    // The id of the object
    std::string id;

  public:
    Mesh();
    Mesh(std::vector<Vector *> vertexes, std::vector<std::vector<int>> faces, std::string id);
    Mesh(const Mesh &o);
    ~Mesh();

    std::vector<Vector *> getVertexes() const;
    std::vector<HalfEdge *> getMesh() const;
    std::vector<Face *> getFaces() const;
    int getNumFaces() const;
    std::string getId() const;

    void setVertexes(std::vector<Vector *> vertexes);
    void setMesh(std::vector<HalfEdge *> mesh);
    void setFaces(std::vector<Face *> faces);
    void setNumFaces(int num_faces);
    void setId(std::string id);

    Mesh &operator=(const Mesh &o);

    void createMesh();
    void createMesh(std::vector<Vector *> vertexes, std::vector<std::vector<int>> faces);
  };
} // namespace core