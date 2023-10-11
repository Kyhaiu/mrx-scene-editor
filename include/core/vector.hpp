#pragma once

#include <core/half_edge.hpp>

namespace vector
{
  class Vector
  {
  protected:
    double x;
    double y;
    double z;
    double h;
    halfedge::HalfEdge *halfedge;

  public:
    Vector();
    Vector(double x, double y, double z, double h, halfedge::HalfEdge *halfedge = nullptr);
    Vector(const Vector &v);
    ~Vector();

    double getX() const;
    double getY() const;
    double getZ() const;
    double getH() const;
    halfedge::HalfEdge *getHalfEdge() const;

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setH(double h);
    void setHalfEdge(halfedge::HalfEdge *halfedge);

    Vector operator+(const Vector &v) const;
    Vector operator-(const Vector &v) const;
    Vector operator*(const Vector &v) const;
    Vector operator/(const Vector &v) const;

    Vector operator+(double scalar) const;
    Vector operator-(double scalar) const;
    Vector operator*(double scalar) const;
    Vector operator/(double scalar) const;

    Vector &operator+=(const Vector &v);
    Vector &operator-=(const Vector &v);
    Vector &operator*=(const Vector &v);
    Vector &operator/=(const Vector &v);

    Vector &operator+=(double scalar);
    Vector &operator-=(double scalar);
    Vector &operator*=(double scalar);
    Vector &operator/=(double scalar);

    Vector &operator=(const Vector &v);

    bool operator==(const Vector &v) const;
    bool operator!=(const Vector &v) const;
    bool operator==(const std::nullptr_t &v) const;
    bool operator!=(const std::nullptr_t &v) const;

    double operator[](int index) const;
    double &operator[](int index);

    double angle(const Vector &v) const;
    Vector cross(const Vector &v) const;
    double distance(const Vector &v) const;
    double dot(const Vector &v) const;
    double magnitude() const;
    Vector normalize() const;
    Vector unit() const;
  };

} // namespace vector