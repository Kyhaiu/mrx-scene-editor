#pragma once

#include <core/vector.hpp>
#include <core/face.hpp>

namespace halfedge
{
  /**
   * @brief HalfEdge class - Represents a half-edge of a mesh.
   *
   */
  class HalfEdge
  {
  protected:
    vector::Vector origin;
    HalfEdge *twin;
    HalfEdge *prev;
    HalfEdge *next;
    face::Face *face;

  public:
    HalfEdge();
    HalfEdge(vector::Vector origin, HalfEdge *twin, HalfEdge *prev, HalfEdge *next, face::Face *face);
    HalfEdge(const HalfEdge &he);
    ~HalfEdge();

    vector::Vector getOrigin() const;
    HalfEdge *getTwin() const;
    HalfEdge *getPrev() const;
    HalfEdge *getNext() const;
    face::Face *getFace() const;

    void setOrigin(vector::Vector origin);
    void setTwin(HalfEdge *twin);
    void setPrev(HalfEdge *prev);
    void setNext(HalfEdge *next);
    void setFace(face::Face *face);

    HalfEdge &operator=(const HalfEdge &he);
  };
} // namespace halfedge