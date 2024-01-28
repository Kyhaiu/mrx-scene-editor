#pragma once

#include <vector>
#include <iostream>

namespace Core
{

  // Forward declaration of all classes
  class Vector;
  class Face;
  class HalfEdge;
  class Mesh;
  class Camera;
  class Scene;

  namespace Vertex
  {
    // This is a vertex struct that is used to store the coordinates of a vector
    typedef struct
    {
      double x;
      double y;
      double z;
    } Vertex;
    // Methods for vertex struct
    std::ostream &operator<<(std::ostream &os, const Vertex &v);
    bool operator==(const Vertex &v1, const Vertex &v2);
    bool operator!=(const Vertex &v1, const Vertex &v2);

  }

  // // Some standard null pointers
  // std::nullptr_t NULL_VERTEX;
  // std::nullptr_t NULL_FACE;
  // std::nullptr_t NULL_EDGE;
  // std::nullptr_t NULL_HALF_EDGE;
  // std::nullptr_t NULL_POINTER;

} // namespace Core