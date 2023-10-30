#include <math/math.hpp>
#include <iostream>

namespace Math
{
  /**
   * @brief A function that calculates the angle between two vectors.
   *
   * @param v1 The first vector.
   * @param v2 The second vector.
   * @return double The angle between the two vectors.
   */
  double angle(HalfMesh::Vector *v1, HalfMesh::Vector *v2)
  {
    // #TODO check if this is faster than the other implementation
    // return acos(dot(v1, v2) / (length(v1) * length(v2)));
    double dot_product = dot(v1, v2);
    double length_v1 = v_module(v1);
    double length_v2 = v_module(v2);

    return dot_product / (length_v1 * length_v2);
  }

  /**
   * @brief A function that calculates the dot product of two vertex.
   *
   * @param v1 The first vertex.
   * @param v2 The second vertex.
   * @return double
   */
  double angle(HalfMesh::Vertex v1, HalfMesh::Vertex v2)
  {
    // #TODO check if this is faster than the other implementation
    // return acos(dot(v1, v2) / (length(v1) * length(v2)));
    double dot_product = dot(v1, v2);
    double length_v1 = v_module(v1);
    double length_v2 = v_module(v2);

    return dot_product / (length_v1 * length_v2);
  }

  /**
   * @brief A function that calculates the dot product of two vectors.
   *
   * @param v1 The first vector.
   * @param v2 The second vector.
   * @return double The dot product of the two vectors.
   */
  double dot(HalfMesh::Vector *v1, HalfMesh::Vector *v2)
  {
    return v1->getX() * v2->getX() + v1->getY() * v2->getY() + v1->getZ() * v2->getZ();
  }

  /**
   * @brief A function that calculates the dot product of two vertex.
   *
   * @param v1 The first vertex.
   * @param v2 The second vertex.
   * @return double The dot product of the two vertex.
   */
  double dot(HalfMesh::Vertex v1, HalfMesh::Vertex v2)
  {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  }

  /**
   * @brief A function that calculates the dot product of a vector and a scalar.
   *
   * @param scalar The scalar.
   * @param v The vector.
   * @return HalfMesh::Vector* A pointer to the result of the dot product.
   */
  HalfMesh::Vector *dot(double scalar, HalfMesh::Vector *v)
  {
    HalfMesh::Vector *result = new HalfMesh::Vector(
        v->getX() * scalar,
        v->getY() * scalar,
        v->getZ() * scalar,
        1, // TODO: Check this and fix it if necessary.
        nullptr);
    return result;
  }

  /**
   * @brief A function that calculates the dot product of a vertex and a scalar.
   *
   * @param scalar The scalar.
   * @param v The vertex.
   * @return HalfMesh::Vertex A pointer to the result of the dot product.
   */
  HalfMesh::Vertex dot(double scalar, HalfMesh::Vertex v)
  {
    HalfMesh::Vertex result = {
        v.x * scalar,
        v.y * scalar,
        v.z * scalar,
    };

    return result;
  }

  /**
   * @brief A function that calculates the distance between two vectors.
   *
   * @param v1 HalfMesh::Vector* The first vector.
   * @param v2 HalfMesh::Vector* The second vector.
   * @return double
   */
  double length(HalfMesh::Vector *v1, HalfMesh::Vector *v2)
  {
    return sqrt(pow(v1->getX() - v2->getX(), 2) + pow(v1->getY() - v2->getY(), 2) + pow(v1->getZ() - v2->getZ(), 2));
  }

  /**
   * @brief A function that calculates the distance between two vertex.
   *
   * @param v1 HalfMesh::Vertex The first vertex.
   * @param v2 HalfMesh::Vertex The second vertex.
   * @return double
   */
  double length(HalfMesh::Vertex v1, HalfMesh::Vertex v2)
  {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
  }

  /**
   * @brief A function that calculates the module of a vector.
   *
   * @param v The vector.
   * @return double The module of the vector.
   */
  double v_module(HalfMesh::Vector *v)
  {
    return sqrt(pow(v->getX(), 2) + pow(v->getY(), 2) + pow(v->getZ(), 2));
  }

  /**
   * @brief A function that calculates the module of a vertex.
   *
   * @param v The vertex.
   * @return double The module of the vertex.
   */
  double v_module(HalfMesh::Vertex v)
  {
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
  }

  /**
   * @brief A function that normalizes a vector.
   *
   * @param v The vector to normalize.
   * @return HalfMesh::Vector* A pointer to the normalized vector.
   */
  HalfMesh::Vector *normalize(HalfMesh::Vector *v)
  {
    double length_v = v_module(v);
    HalfMesh::Vector *result = new HalfMesh::Vector(
        v->getX() / length_v,
        v->getY() / length_v,
        v->getZ() / length_v,
        1, // TODO: Check this and fix it if necessary.
        nullptr);
    return result;
  }

  /**
   * @brief A function that normalizes a vertex.
   *
   * @param v The vertex to normalize.
   * @return HalfMesh::Vertex* A pointer to the normalized vertex.
   */
  HalfMesh::Vertex normalize(HalfMesh::Vertex v)
  {
    double length_v = v_module(v);
    HalfMesh::Vertex result = {
        v.x / length_v,
        v.y / length_v,
        v.z / length_v,
    };

    return result;
  }

  /**
   * @brief A function that calculates the cross product of two vectors.
   *
   * @param v1 The first vector.
   * @param v2 The second vector.
   * @return HalfMesh::Vector* A pointer to the cross product of the two vectors.
   */
  HalfMesh::Vector *cross(HalfMesh::Vector *v1, HalfMesh::Vector *v2)
  {
    HalfMesh::Vector *result = new HalfMesh::Vector(
        v1->getY() * v2->getZ() - v1->getZ() * v2->getY(),
        v1->getZ() * v2->getX() - v1->getX() * v2->getZ(),
        v1->getX() * v2->getY() - v1->getY() * v2->getX(),
        1, // TODO: Check this and fix it if necessary.
        nullptr);
    return result;
  }

  /**
   * @brief A function that calculates the cross product of two vertex.
   *
   * @param v1 The first vertex.
   * @param v2 The second vertex.
   * @return HalfMesh::Vertex* A pointer to the cross product of the two vertex.
   */
  HalfMesh::Vertex cross(HalfMesh::Vertex v1, HalfMesh::Vertex v2)
  {
    HalfMesh::Vertex result = {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x,
    };

    return result;
  }
} // namespace Math