#pragma once

#include <core/common.hpp>

namespace Core
{
  namespace Vertex
  {

    // Methods for vertex struct

    /**
     * @brief This method is used to print the vertex
     *
     * @param os The output stream
     * @param v The vertex to be printed
     * @return std::ostream&
     */
    std::ostream &operator<<(std::ostream &os, const Vertex &v)
    {
      os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
      return os;
    }

    /**
     * @brief This method is used to check if two vertices are equal
     *
     * @param v1 The first vertex
     * @param v2 The second vertex
     * @return true If the vertices are equal
     * @return false If the vertices are not equal
     */
    bool operator==(const Vertex &v1, const Vertex &v2)
    {
      return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z);
    }

    /**
     * @brief This method is used to check if two vertices are not equal
     *
     * @param v1 The first vertex
     * @param v2 The second vertex
     * @return true If the vertices are not equal
     * @return false If the vertices are equal
     */
    bool operator!=(const Vertex &v1, const Vertex &v2)
    {
      return !(v1 == v2);
    }
  }
} // namespace Core