#pragma once

#include <core/common.hpp>

namespace HalfMesh
{
  /**
   * @brief HalfEdge class - Represents a half-edge of a mesh.
   *
   */
  class HalfEdge
  {
  protected:
    Vector *origin;
    HalfEdge *twin;
    HalfEdge *prev;
    HalfEdge *next;
    Face *face;
    std::string id;

  public:
    HalfEdge();
    HalfEdge(Vector *origin, HalfEdge *twin, HalfEdge *prev, HalfEdge *next, Face *face, std::string id);
    HalfEdge(const HalfEdge &he);
    ~HalfEdge();

    Vector *getOrigin() const;
    HalfEdge *getTwin() const;
    HalfEdge *getPrev() const;
    HalfEdge *getNext() const;
    Face *getFace() const;
    std::string getId() const;

    void setOrigin(Vector *origin);
    void setTwin(HalfEdge *twin);
    void setPrev(HalfEdge *prev);
    void setNext(HalfEdge *next);
    void setFace(Face *face);
    void setId(std::string id);

    friend std::ostream &operator<<(std::ostream &os, const HalfEdge &he);
    HalfEdge &operator=(const HalfEdge &he);
  };
}