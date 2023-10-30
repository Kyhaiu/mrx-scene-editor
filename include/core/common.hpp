#pragma once

#include <vector>
#include <iostream>

namespace HalfMesh
{
  // This is a vertex struct that is used to store the coordinates of a vector
  typedef struct
  {
    double x;
    double y;
    double z;
  } Vertex;

  // Forward declaration of all classes
  class Vector;
  class Face;
  class HalfEdge;
  class Mesh;

  // // Some standard null pointers
  // std::nullptr_t NULL_VERTEX;
  // std::nullptr_t NULL_FACE;
  // std::nullptr_t NULL_EDGE;
  // std::nullptr_t NULL_HALF_EDGE;
  // std::nullptr_t NULL_POINTER;

} // namespace HalfMesh