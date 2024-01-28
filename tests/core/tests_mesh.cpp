#include <gtest/gtest.h>
#include <core/face.hpp>
#include <core/vector.hpp>
#include <core/half_edge.hpp>
#include <core/mesh.hpp>

/**
 * @note The following test case is based on the following mesh:
 *
 * # vertices
 * v -1 -1 0
 * v 1 -1 0
 * v 1 1 0
 * # face
 * f 1 2 3
 *
 * Vertex	Coordinate	Incident edge
 * v1	    (-1, -1, 0)	e0
 * v2	    (1, -1, 0)  e1
 * v3	    (1, 1, 0) 	e2
 *
 * Face	Half-edge
 * f0	  e0
 *
 * Half-edge	Origin	Twin	Incident face	Next	Prev
 * e0	        v1	    e3	  f0            e1    e2
 * e1	        v2	    e4	  f0            e2    e0
 * e2	        v3	    e5	  f0            e0    e1
 * e3	        v2	    e0	  ∅	            e5	  e4
 * e4	        v3	    e1	  ∅	            e3	  e5
 * e5	        v1	    e2	  ∅	            e4	  e3

 */
class MeshTest : public ::testing::Test
{
protected:
  // Creating half edges
  Core::HalfEdge *e0 = new Core::HalfEdge();
  Core::HalfEdge *e1 = new Core::HalfEdge();
  Core::HalfEdge *e2 = new Core::HalfEdge();
  Core::HalfEdge *e3 = new Core::HalfEdge();
  Core::HalfEdge *e4 = new Core::HalfEdge();
  Core::HalfEdge *e5 = new Core::HalfEdge();

  // Creating vertices
  Core::Vector *v1 = new Core::Vector(-1.0, -1.0, -1.0, 1.0, nullptr);
  Core::Vector *v2 = new Core::Vector(1.0, -1.0, -1.0, 1.0, nullptr);
  Core::Vector *v3 = new Core::Vector(1.0, 1.0, -1.0, 1.0, nullptr);

  // Creating a list that contains how the edges are connected
  std::vector<std::vector<int>> edges = {{0, 1, 2}};

  // Creating a list that contains all edges of the face
  // std::vector<Core::HalfEdge *> edges = {e0, e1, e2, e3, e4, e5};

  // // set the incident edge of each vertex
  // v1->setHalfEdge(e3);
  // v2->setHalfEdge(e4);
  // v3->setHalfEdge(e5);

  // // set the origin of each edge
  // e0->setOrigin(v1);
  // e1->setOrigin(v2);
  // e2->setOrigin(v3);
  // e3->setOrigin(v2);
  // e4->setOrigin(v3);
  // e5->setOrigin(v1);

  // // set the next edge of each edge
  // e0->setNext(e1);
  // e1->setNext(e2);
  // e2->setNext(e0);
  // e3->setNext(e5);
  // e4->setNext(e3);
  // e5->setNext(e4);

  // // set the previous edge of each edge
  // e0->setPrev(e2);
  // e1->setPrev(e0);
  // e2->setPrev(e1);
  // e3->setPrev(e4);
  // e4->setPrev(e5);
  // e5->setPrev(e3);

  // // set the twin edge of each edge
  // e0->setTwin(e3);
  // e1->setTwin(e4);
  // e2->setTwin(e5);
  // e3->setTwin(e0);
  // e4->setTwin(e1);
  // e5->setTwin(e2);

  // // Creating a face
  // Core::Face *f0 = new Face(edges, e0, true);

  // // set the incident face of each edge
  // e0->setFace(f0);
  // e1->setFace(f0);
  // e2->setFace(f0);
  // e3->setFace(nullptr);
  // e4->setFace(nullptr);
  // e5->setFace(nullptr);

  void
  SetUp() override
  {
  }
};

/**
 * @brief Test the constructor of the mesh
 *
 */
TEST_F(MeshTest, default_mesh_constructor)
{
  Core::Mesh *mesh = new Core::Mesh();
  EXPECT_EQ(mesh->getNumFaces(), 0);
  EXPECT_EQ(mesh->getVertexes().size(), 0);
  EXPECT_EQ(mesh->getMesh().size(), 0);
  EXPECT_EQ(mesh->getFaces().size(), 0);
}

/**
 * @brief Test the constructor of the mesh
 *
 */
// TEST_F(MeshTest, mesh_constructor)
// {
//   Core::Mesh *mesh = new Core::Mesh({v1, v2, v3}, edges);

//   Core::HalfEdge *he = mesh->getMesh()[0];
// }

/**
 * @brief Test case for a cube mesh
 *
 */
TEST_F(MeshTest, cube_mesh_constructor)
{
  // Back Face
  // Left Face
  // Bottom Face
  // Right Face
  // Top Face

  // Bottom-left-back
  Core::Vector *v0 = new Core::Vector(-1.0, -1.0, -1.0, 1.0, nullptr, "v0");
  // Bottom-right-back
  Core::Vector *v1 = new Core::Vector(1.0, -1.0, -1.0, 1.0, nullptr, "v1");
  // Bottom-right-front
  Core::Vector *v2 = new Core::Vector(1.0, -1.0, 1.0, 1.0, nullptr, "v2");
  // Bottom-left-front
  Core::Vector *v3 = new Core::Vector(-1.0, -1.0, 1.0, 1.0, nullptr, "v3");
  // Top-left-back
  Core::Vector *v4 = new Core::Vector(-1.0, 1.0, -1.0, 1.0, nullptr, "v4");
  // Top-right-back
  Core::Vector *v5 = new Core::Vector(1.0, 1.0, -1.0, 1.0, nullptr, "v5");
  // Top-right-front
  Core::Vector *v6 = new Core::Vector(1.0, 1.0, 1.0, 1.0, nullptr, "v6");
  // Top-left-front
  Core::Vector *v7 = new Core::Vector(-1.0, 1.0, 1.0, 1.0, nullptr, "v7");

  std::vector<std::vector<int>> edges = {
      // Back Face
      {2, 6, 7, 3},
      // Left Face
      {1, 0, 4, 5},
      // Bottom Face
      {3, 7, 4, 0},
      // Right Face
      {2, 3, 0, 1},
      // Top Face
      {6, 2, 1, 5},
      // Front Face
      {6, 5, 4, 7}};

  Core::Mesh *mesh = new Core::Mesh({v0, v1, v2, v3, v4, v5, v6, v7}, edges, "cube");

  for (auto &f : mesh->getFaces())
  {
    Core::HalfEdge *he = f->getHalfEdge();
    // std::cout << "Face: " << f->getId() << std::endl;
    // std::cout << *f << std::endl;
    while (true)
    {
      // std::cout << he->getOrigin()->getId() << "->";
      he = he->getNext();

      if (he == f->getHalfEdge())
      {
        break;
      }
    }
    std::cout << std::endl;
  }
}
