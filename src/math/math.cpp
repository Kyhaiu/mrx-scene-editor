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
  double angle(Core::Vector *v1, Core::Vector *v2)
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
  double angle(Core::Vertex::Vertex v1, Core::Vertex::Vertex v2)
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
  double dot(Core::Vector *v1, Core::Vector *v2)
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
  double dot(Core::Vertex::Vertex v1, Core::Vertex::Vertex v2)
  {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  }

  /**
   * @brief A function that calculates the dot product of a vector and a scalar.
   *
   * @param scalar The scalar.
   * @param v The vector.
   * @return Core::Vector* A pointer to the result of the dot product.
   */
  Core::Vector *dot(double scalar, Core::Vector *v)
  {
    Core::Vector *result = new Core::Vector(
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
   * @return Core::Vertex:Vertex A pointer to the result of the dot product.
   */
  Core::Vertex::Vertex dot(double scalar, Core::Vertex::Vertex v)
  {
    Core::Vertex::Vertex result = {
        v.x * scalar,
        v.y * scalar,
        v.z * scalar,
    };

    return result;
  }

  /**
   * @brief A function that calculates the distance between two vectors.
   *
   * @param v1 Core::Vector* The first vector.
   * @param v2 Core::Vector* The second vector.
   * @return double
   */
  double length(Core::Vector *v1, Core::Vector *v2)
  {
    return sqrt(pow(v1->getX() - v2->getX(), 2) + pow(v1->getY() - v2->getY(), 2) + pow(v1->getZ() - v2->getZ(), 2));
  }

  /**
   * @brief A function that calculates the distance between two vertex.
   *
   * @param v1 Core::Vertex:Vertex The first vertex.
   * @param v2 Core::Vertex:Vertex The second vertex.
   * @return double
   */
  double length(Core::Vertex::Vertex v1, Core::Vertex::Vertex v2)
  {
    return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
  }

  /**
   * @brief A function that calculates the module of a vector.
   *
   * @param v The vector.
   * @return double The module of the vector.
   */
  double v_module(Core::Vector *v)
  {
    return sqrt(pow(v->getX(), 2) + pow(v->getY(), 2) + pow(v->getZ(), 2));
  }

  /**
   * @brief A function that calculates the module of a vertex.
   *
   * @param v The vertex.
   * @return double The module of the vertex.
   */
  double v_module(Core::Vertex::Vertex v)
  {
    return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
  }

  /**
   * @brief A function that normalizes a vector.
   *
   * @param v The vector to normalize.
   * @return Core::Vector* A pointer to the normalized vector.
   */
  Core::Vector *normalize(Core::Vector *v)
  {
    double length_v = v_module(v);
    Core::Vector *result = new Core::Vector(
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
   * @return Core::Vertex:Vertex* A pointer to the normalized vertex.
   */
  Core::Vertex::Vertex normalize(Core::Vertex::Vertex v)
  {
    double length_v = v_module(v);
    Core::Vertex::Vertex result = {
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
   * @return Core::Vector* A pointer to the cross product of the two vectors.
   */
  Core::Vector *cross(Core::Vector *v1, Core::Vector *v2)
  {
    Core::Vector *result = new Core::Vector(
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
   * @return Core::Vertex:Vertex* A pointer to the cross product of the two vertex.
   */
  Core::Vertex::Vertex cross(Core::Vertex::Vertex v1, Core::Vertex::Vertex v2)
  {
    Core::Vertex::Vertex result = {
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x,
    };

    return result;
  }

  /**
   * @brief A function that multiplies two matrices.
   *
   * @param m1 The first matrix.
   * @param m2 The second matrix.
   * @return std::vector<std::vector<double>> The result of the multiplication.
   */
  std::vector<std::vector<double>> multiply_matrix(std::vector<std::vector<double>> m1, std::vector<std::vector<double>> m2)
  {
    std::vector<std::vector<double>> result;

    for (int i = 0; i < m1.size(); i++)
    {
      std::vector<double> row;
      for (int j = 0; j < m2[0].size(); j++)
      {
        double sum = 0;
        for (int k = 0; k < m1[0].size(); k++)
        {
          sum += m1[i][k] * m2[k][j];
        }
        row.push_back(sum);
      }
      result.push_back(row);
    }

    return result;
  }

  /**
   * @brief A function that applies a matrix to a vector.
   *
   * @param v The vector.
   * @param m The matrix.
   */
  void apply_matrix(Core::Vector *v, std::vector<std::vector<double>> m)
  {
    std::vector<std::vector<double>> v_matrix = {
        {v->getX()},
        {v->getY()},
        {v->getZ()},
        {v->getH()}};

    std::vector<std::vector<double>> result = multiply_matrix(m, v_matrix);

    v->setX(result[0][0]);
    v->setY(result[1][0]);
    v->setZ(result[2][0]);
    v->setH(result[3][0]);
  }
} // namespace Math