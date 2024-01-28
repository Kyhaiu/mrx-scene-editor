#pragma once

#include <core/common.hpp>

namespace Core
{

  class Vector
  {
  protected:
    Vertex::Vertex vertex;
    double h;
    HalfEdge *half_edge;
    std::string id;

  public:
    Vector();
    Vector(double x, double y, double z, double h, HalfEdge *halfedge = nullptr, std::string id = "");
    Vector(const Vector &v);
    ~Vector();

    double getX() const;
    double getY() const;
    double getZ() const;
    double getH() const;
    HalfEdge *getHalfEdge() const;
    std::string getId() const;
    Vertex::Vertex getVertex() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setH(double h);
    void setHalfEdge(HalfEdge *half_edge);
    void setId(std::string id);

    friend std::ostream &operator<<(std::ostream &os, const Vector &v);

    Vector &operator=(const Vector &v);

    bool operator==(const Vector &v) const;
    bool operator!=(const Vector &v) const;

    double operator[](int index) const;

    // double angle(const Vector &v) const;
    // Vector cross(const Vector &v) const;
    // double distance(const Vector &v) const;
    // double dot(const Vector &v) const;
    // double magnitude() const;
    // Vector normalize() const;
    // Vector unit() const;
  };

} // namespace vector