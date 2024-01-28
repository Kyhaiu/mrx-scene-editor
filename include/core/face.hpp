#pragma once

#include <core/common.hpp>

namespace Core
{

  class Face
  {
  protected:
    std::vector<HalfEdge *> edges;
    HalfEdge *halfedge;
    bool visible;
    std::string id;

  public:
    Face();
    Face(std::vector<HalfEdge *> edges, HalfEdge *halfedge, bool visible, std::string id);
    Face(const Face &f);
    ~Face();

    std::vector<HalfEdge *> getEdges() const;
    HalfEdge *getHalfEdge() const;
    std::string getId() const;

    void setEdges(std::vector<HalfEdge *> edge);
    void setHalfEdge(HalfEdge *halfedge);
    void setId(std::string id);

    bool isVisible() const;

    friend std::ostream &operator<<(std::ostream &os, const Face &f);
    Face &operator=(const Face &f);
  };
} // namespace face