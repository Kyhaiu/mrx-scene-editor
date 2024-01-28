#include <core/vector.hpp>
#include <core/half_edge.hpp>

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

namespace Core
{

  /**
   * @brief Construct a new Vector object with all values set to 0.
   *
   */
  Vector::Vector()
  {
    this->vertex.x = 0;
    this->vertex.y = 0;
    this->vertex.z = 0;
    this->h = 0;
    this->setHalfEdge(nullptr);
    this->setId("");
  }

  /**
   * @brief Construct a new Vector object with the given values.
   *
   * @param _x The component in the x direction.
   * @param _y The component in the y direction.
   * @param _z The component in the z direction.
   * @param _h The component in the h direction.
   * @param _half_edge The HalfEdge object associated with this Vector.
   */
  Vector::Vector(double _x, double _y, double _z, double _h, HalfEdge *_half_edge, std::string _id)
  {
    vertex.x = _x;
    vertex.y = _y;
    vertex.z = _z;
    h = _h;
    this->setHalfEdge(_half_edge);
    this->setId(_id);
  }

  /**
   * @brief Construct a new Vector object with the same values as the given Vector.
   *
   * @param v The Vector to copy.
   */
  Vector::Vector(const Vector &v)
  {
    vertex.x = v.vertex.x;
    vertex.y = v.vertex.y;
    vertex.z = v.vertex.z;
    h = v.h;
    half_edge = v.half_edge;
    id = v.id;
  }

  /**
   * @brief Destroy the Vector object.
   *
   */
  Vector::~Vector()
  {
    delete this;
  }

  /**
   * @brief Returns the component in the x direction.
   *
   * @return double The component in the x direction.
   */
  double Vector::getX() const
  {
    return vertex.x;
  }

  /**
   * @brief Returns the component in the y direction.
   *
   * @return double The component in the y direction.
   */
  double Vector::getY() const
  {
    return vertex.y;
  }

  /**
   * @brief Returns the component in the z direction.
   *
   * @return double The component in the z direction.
   */
  double Vector::getZ() const
  {
    return vertex.z;
  }

  /**
   * @brief Returns the component in the h direction.
   *
   * @return double The component in the h direction.
   */
  double Vector::getH() const
  {
    return h;
  }

  /**
   * @brief Returns the HalfEdge object associated with this Vector.
   *
   * @return HalfEdge* The HalfEdge object associated with this Vector.
   */
  HalfEdge *Vector::getHalfEdge() const
  {
    return half_edge;
  }

  /**
   * @brief Returns the id of this Vector.
   *
   * @return std::string The id of this Vector.
   */
  std::string Vector::getId() const
  {
    return id;
  }

  /**
   * @brief Returns the Vertex object associated with this Vector.
   *
   * @return Vertex The Vertex object associated with this Vector.
   */
  Vertex::Vertex Vector::getVertex() const
  {
    return vertex;
  }

  /**
   * @brief Sets the component in the x direction.
   *
   * @param _x The component in the x direction.
   */
  void Vector::setX(double _x)
  {
    vertex.x = _x;
  }

  /**
   * @brief Sets the component in the y direction.
   *
   * @param _y The component in the y direction.
   */
  void Vector::setY(double _y)
  {
    vertex.y = _y;
  }

  /**
   * @brief Sets the component in the z direction.
   *
   * @param _z The component in the z direction.
   */
  void Vector::setZ(double _z)
  {
    vertex.z = _z;
  }

  /**
   * @brief Sets the component in the h direction.
   *
   * @param _h The component in the h direction.
   */
  void Vector::setH(double _h)
  {
    h = _h;
  }

  /**
   * @brief Sets the HalfEdge object associated with this Vector.
   *
   * @param _half_edge The HalfEdge object associated with this Vector.
   */
  void Vector::setHalfEdge(HalfEdge *_half_edge)
  {
    half_edge = _half_edge;
  }

  /**
   * @brief Sets the id of this Vector.
   *
   * @param _id The id of this Vector.
   */
  void Vector::setId(std::string _id)
  {
    id = _id;
  }

  /**
   * @brief Returns a string representation of this Vector.
   *
   * @param os The output stream to write to.
   * @param v The Vector to write.
   * @return std::ostream& The output stream.
   */
  std::ostream &operator<<(std::ostream &os, const Vector &v)
  {
    os << v.id << ": (" << v.vertex.x << ", " << v.vertex.y << ", " << v.vertex.z << ", " << v.h << ")";
    return os;
  }

  /**
   * @brief Assign the given Vector to this Vector.
   *
   * @param v The Vector to assign.
   * @return Vector
   */
  Vector &Vector::operator=(const Vector &v)
  {
    vertex.x = v.vertex.x;
    vertex.y = v.vertex.y;
    vertex.z = v.vertex.z;
    h = v.h;
    half_edge = v.half_edge;
    id = v.id;
    return *this;
  }

  /**
   * @brief Compare the given Vector to this Vector.
   *
   * @param v The Vector to compare.
   * @return true If the given Vector is equal to this Vector.
   * @return false If the given Vector is not equal to this Vector.
   */
  bool Vector::operator==(const Vector &v) const
  {
    return vertex.x == v.vertex.x && vertex.y == v.vertex.y && vertex.z == v.vertex.z && h == v.h && half_edge == v.half_edge && id == v.id;
  }

  /**
   * @brief Compare the given Vector to this Vector.
   *
   * @param v The Vector to compare.
   * @return true If the given Vector is not equal to this Vector.
   * @return false If the given Vector is equal to this Vector.
   */
  bool Vector::operator!=(const Vector &v) const
  {
    return vertex.x != v.vertex.x || vertex.y != v.vertex.y || vertex.z != v.vertex.z || h != v.h || half_edge != v.half_edge || id != v.id;
  }

  /**
   * @brief Get the component at X, Y, Z or H in the given index.
   *
   * @param index The index of the component to get.
   * @return double The component at the given index.
   */
  double Vector::operator[](int index) const
  {
    switch (index)
    {
    case 0:
      return vertex.x;
    case 1:
      return vertex.y;
    case 2:
      return vertex.z;
    case 3:
      return h;
    default:
      return 0;
    }
  }
} // namespace vector