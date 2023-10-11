#include <core/vector.hpp>

#include <cmath>

namespace vector
{

  /**
   * @brief Construct a new Vector object with all values set to 0.
   *
   */
  Vector::Vector()
  {
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->h = 0;
    this->setHalfEdge(nullptr);
  }

  /**
   * @brief Construct a new Vector object with the given values.
   *
   * @param _x The component in the x direction.
   * @param _y The component in the y direction.
   * @param _z The component in the z direction.
   * @param _h The component in the h direction.
   * @param _halfedge The halfedge::HalfEdge object associated with this Vector.
   */
  Vector::Vector(double _x, double _y, double _z, double _h, halfedge::HalfEdge *_halfedge)
  {
    x = _x;
    y = _y;
    z = _z;
    h = _h;
    this->setHalfEdge(_halfedge);
  }

  /**
   * @brief Construct a new Vector object with the same values as the given Vector.
   *
   * @param v The Vector to copy.
   */
  Vector::Vector(const Vector &v)
  {
    x = v.x;
    y = v.y;
    z = v.z;
    h = v.h;
    halfedge = v.halfedge;
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
    return x;
  }

  /**
   * @brief Returns the component in the y direction.
   *
   * @return double The component in the y direction.
   */
  double Vector::getY() const
  {
    return y;
  }

  /**
   * @brief Returns the component in the z direction.
   *
   * @return double The component in the z direction.
   */
  double Vector::getZ() const
  {
    return z;
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
   * @brief Returns the halfedge::HalfEdge object associated with this Vector.
   *
   * @return halfedge::HalfEdge* The halfedge::HalfEdge object associated with this Vector.
   */
  halfedge::HalfEdge *Vector::getHalfEdge() const
  {
    return halfedge;
  }

  /**
   * @brief Sets the component in the x direction.
   *
   * @param _x The component in the x direction.
   */
  void Vector::setX(double _x)
  {
    x = _x;
  }

  /**
   * @brief Sets the component in the y direction.
   *
   * @param _y The component in the y direction.
   */
  void Vector::setY(double _y)
  {
    y = _y;
  }

  /**
   * @brief Sets the component in the z direction.
   *
   * @param _z The component in the z direction.
   */
  void Vector::setZ(double _z)
  {
    z = _z;
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
   * @brief Sets the halfedge::HalfEdge object associated with this Vector.
   *
   * @param _halfedge The halfedge::HalfEdge object associated with this Vector.
   */
  void Vector::setHalfEdge(halfedge::HalfEdge *_halfedge)
  {
    halfedge = _halfedge;
  }

  /**
   * @brief Returns the angle between this Vector and the given Vector.
   *
   * @param v The Vector to compare to.
   * @return double The angle between this Vector and the given Vector.
   */
  double Vector::angle(const Vector &v) const
  {
    return acos(Vector::dot(v) / (Vector::magnitude() * v.magnitude()));
  }

  /**
   * @brief Returns the cross product of this Vector and the given Vector.
   *
   * @param v The Vector to compare to.
   * @return Vector The cross product of this Vector and the given Vector.
   */
  Vector Vector::cross(const Vector &v) const
  {
    return Vector(
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x,
        0);
  }

  /**
   * @brief Returns the distance between this Vector and the given Vector.
   *
   * @param v The Vector to compare to.
   * @return double The distance between this Vector and the given Vector.
   */
  double Vector::distance(const Vector &v) const
  {
    return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
  }

  /**
   * @brief Returns the dot product of this Vector and the given Vector.
   *
   * @param v The Vector to compare to.
   * @return double The dot product of this Vector and the given Vector.
   */
  double Vector::dot(const Vector &v) const
  {
    return x * v.x + y * v.y + z * v.z;
  }

  /**
   * @brief Returns the magnitude of this Vector.
   *
   * @return double The magnitude of this Vector.
   */
  double Vector::magnitude() const
  {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  }

  /**
   * @brief Returns the normalized version of this Vector.
   *
   * @return Vector The normalized version of this Vector.
   */
  Vector Vector::normalize() const
  {
    double magnitude = Vector::magnitude();
    return Vector(
        x / magnitude,
        y / magnitude,
        z / magnitude,
        0 // idk if this is right
    );
  }

  /**
   * @brief Returns the unit version of this Vector.
   *
   * @return Vector The unit version of this Vector.
   */
  Vector Vector::unit() const
  {
    return Vector::normalize();
  }

  /**
   * @brief Add the given Vector to this Vector.
   *
   * @param v The Vector to add.
   * @return Vector
   */
  Vector Vector::operator+(const Vector &v) const
  {
    return Vector(
        x + v.x,
        y + v.y,
        z + v.z,
        0 // idk if this is right
    );
  }

  /**
   * @brief Subtract the given Vector from this Vector.
   *
   * @param v The Vector to subtract.
   * @return Vector
   */
  Vector Vector::operator-(const Vector &v) const
  {
    return Vector(
        x - v.x,
        y - v.y,
        z - v.z,
        0 // idk if this is right
    );
  }

  /**
   * @brief Multiply the given Vector by this Vector.
   *
   * @param v The Vector to multiply.
   * @return Vector
   */
  Vector Vector::operator*(const Vector &v) const
  {
    return Vector(
        x * v.x,
        y * v.y,
        z * v.z,
        0 // idk if this is right
    );
  }

  /**
   * @brief Divide the given Vector by this Vector.
   *
   * @param v The Vector to divide.
   * @return Vector
   */
  Vector Vector::operator/(const Vector &v) const
  {
    return Vector(
        x / v.x,
        y / v.y,
        z / v.z,
        0 // idk if this is right
    );
  }

  /**
   * @brief Add the given scalar to this Vector.
   *
   * @param scalar The scalar to add.
   * @return Vector
   */
  Vector Vector::operator+(double scalar) const
  {
    return Vector(
        x + scalar,
        y + scalar,
        z + scalar,
        0 // idk if this is right
    );
  }

  /**
   * @brief Subtract the given scalar from this Vector.
   *
   * @param scalar The scalar to subtract.
   * @return Vector
   */
  Vector Vector::operator-(double scalar) const
  {
    return Vector(
        x - scalar,
        y - scalar,
        z - scalar,
        0 // idk if this is right
    );
  }

  /**
   * @brief Multiply the given scalar by this Vector.
   *
   * @param scalar The scalar to multiply.
   * @return Vector
   */
  Vector Vector::operator*(double scalar) const
  {
    return Vector(
        x * scalar,
        y * scalar,
        z * scalar,
        0 // idk if this is right
    );
  }

  /**
   * @brief Divide the given scalar by this Vector.
   *
   * @param scalar The scalar to divide.
   * @return Vector
   */
  Vector Vector::operator/(double scalar) const
  {
    return Vector(
        x / scalar,
        y / scalar,
        z / scalar,
        0 // idk if this is right
    );
  }

  /**
   * @brief Add the given Vector to this Vector.
   *
   * @param v The Vector to add.
   * @return Vector
   */
  Vector &Vector::operator+=(const Vector &v)
  {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }

  /**
   * @brief Subtract the given Vector from this Vector.
   *
   * @param v The Vector to subtract.
   * @return Vector
   */
  Vector &Vector::operator-=(const Vector &v)
  {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
  }

  /**
   * @brief Multiply the given Vector by this Vector.
   *
   * @param v The Vector to multiply.
   * @return Vector
   */
  Vector &Vector::operator*=(const Vector &v)
  {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
  }

  /**
   * @brief Divide the given Vector by this Vector.
   *
   * @param v The Vector to divide.
   * @return Vector
   */
  Vector &Vector::operator/=(const Vector &v)
  {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
  }

  /**
   * @brief Add the given scalar to this Vector.
   *
   * @param scalar The scalar to add.
   * @return Vector
   */
  Vector &Vector::operator+=(double scalar)
  {
    x += scalar;
    y += scalar;
    z += scalar;
    return *this;
  }

  /**
   * @brief Subtract the given scalar from this Vector.
   *
   * @param scalar The scalar to subtract.
   * @return Vector
   */
  Vector &Vector::operator-=(double scalar)
  {
    x -= scalar;
    y -= scalar;
    z -= scalar;
    return *this;
  }

  /**
   * @brief Multiply the given scalar by this Vector.
   *
   * @param scalar The scalar to multiply.
   * @return Vector
   */
  Vector &Vector::operator*=(double scalar)
  {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
  }

  /**
   * @brief Divide the given scalar by this Vector.
   *
   * @param scalar The scalar to divide.
   * @return Vector
   */
  Vector &Vector::operator/=(double scalar)
  {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    return *this;
  }

  /**
   * @brief Assign the given Vector to this Vector.
   *
   * @param v The Vector to assign.
   * @return Vector
   */
  Vector &Vector::operator=(const Vector &v)
  {
    x = v.x;
    y = v.y;
    z = v.z;
    h = v.h;
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
    return x == v.x && y == v.y && z == v.z && h == v.h && halfedge == v.halfedge;
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
    return x != v.x || y != v.y || z != v.z || h != v.h || halfedge != v.halfedge;
  }

  /**
   * @brief Compare the given nullptr to this Vector.
   *
   * @param v The nullptr to compare.
   * @return true If the given nullptr is equal to this Vector.
   * @return false If the given nullptr is not equal to this Vector.
   */
  bool Vector::operator==(const std::nullptr_t &v) const
  {
    return v == nullptr;
  }

  /**
   * @brief Compare the given nullptr to this Vector.
   *
   * @param v The nullptr to compare.
   * @return true If the given nullptr is not equal to this Vector.
   * @return false If the given nullptr is equal to this Vector.
   */
  bool Vector::operator!=(const std::nullptr_t &v) const
  {
    return v != nullptr;
  }

  /**
   * @brief Get the component at   the given index.
   *
   * @param index The index of the component to get.
   * @return double The component at the given index.
   */
  double Vector::operator[](int index) const
  {
    switch (index)
    {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    case 3:
      return h;
    default:
      return 0;
    }
  }

  /**
   * @brief Get the component at the given index.
   *
   * @param index The index of the component to get.
   * @return double The component at the given index.
   */
  double &Vector::operator[](int index)
  {
    switch (index)
    {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    case 3:
      return h;
    default:
      return x;
    }
  }
} // namespace vector