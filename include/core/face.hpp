#pragma once

#include <core/vector.hpp>
#include <core/half_edge.hpp>

#include <vector>

namespace face
{
  class Face
  {
  private:
    std::vector<halfedge::HalfEdge> edges;
    halfedge::HalfEdge *halfedge;
    bool visible;
    vector::Vector centroid;
    vector::Vector normal;

  public:
    Face();
    Face(std::vector<halfedge::HalfEdge> edges, halfedge::HalfEdge *halfedge, bool visible, vector::Vector centroid, vector::Vector normal);
    Face(const Face &f);
    ~Face();

    std::vector<halfedge::HalfEdge> getEdge() const;
    halfedge::HalfEdge *getHalfEdge() const;
    vector::Vector getCentroid() const;
    vector::Vector getNormal() const;

    void setEdge(std::vector<halfedge::HalfEdge> edge);
    void setHalfEdge(halfedge::HalfEdge *halfedge);
    void setCentroid(vector::Vector centroid);
    void setNormal(vector::Vector normal);

    bool isVisible() const;
    void defineCentroid();
    void defineNormal();

    Face &operator=(const Face &f);
  };
} // namespace face