#include <core/mesh.hpp>
#include <core/vector.hpp>
#include <core/face.hpp>
#include <core/half_edge.hpp>

#include <iostream>

namespace HalfMesh
{

  /**
   * @brief Construct a new Mesh::Mesh object
   *
   */
  Mesh::Mesh()
  {
    this->setVertexes(std::vector<Vector *>());
    this->setMesh(std::vector<HalfEdge *>());
    this->setFaces(std::vector<Face *>());
    this->setNumFaces(0);
    this->setId("");
  }

  /**
   * @brief Construct a new Mesh::Mesh object
   *
   * @param vertexes A vector of Vector objects.
   * @param faces A vector of vectors containing the indexes of the vertices that form a face
   * @param id A string containing the id of the mesh
   */
  Mesh::Mesh(std::vector<Vector *> vertexes, std::vector<std::vector<int>> faces, std::string id)
  {
    this->createMesh(vertexes, faces);
    this->setId(id);
  }

  /**
   * @brief Copy constructor of Mesh::Mesh object
   *
   * @param o The Mesh object to copy.
   */
  Mesh::Mesh(const Mesh &o)
  {
    this->setVertexes(o.vertexes);
    this->setMesh(o.mesh);
    this->setFaces(o.faces);
    this->setNumFaces(o.num_faces);
    this->setId(o.id);
  }

  Mesh::~Mesh()
  {
    delete this;
  }

  /**
   * @brief Get the vertexes of the Mesh object
   *
   * @return std::vector<Vector> A vector of Vector objects.
   */
  std::vector<Vector *> Mesh::getVertexes() const
  {
    return this->vertexes;
  }

  /**
   * @brief Get the mesh of the Mesh object
   *
   * @return std::vector<HalfEdge> A vector of HalfEdge objects.
   */
  std::vector<HalfEdge *> Mesh::getMesh() const
  {
    return this->mesh;
  }

  /**
   * @brief Get the faces of the Mesh object
   *
   * @return std::vector<Face> A vector of Face objects.
   */
  std::vector<Face *> Mesh::getFaces() const
  {
    return this->faces;
  }

  /**
   * @brief Get the number of faces of the Mesh object
   *
   * @return int The number of faces of the Mesh object.
   */
  int Mesh::getNumFaces() const
  {
    return this->faces.size();
  }

  /**
   * @brief Get the id of the Mesh object
   *
   * @return std::string A string containing the id of the Mesh object.
   */
  std::string Mesh::getId() const
  {
    return this->id;
  }

  /**
   * @brief Set the vertexes of the Mesh object
   *
   * @param vertexes A vector of Vector objects.
   */
  void Mesh::setVertexes(std::vector<Vector *> vertexes)
  {
    this->vertexes = vertexes;
  }

  /**
   * @brief Set the mesh of the Mesh object
   *
   * @param mesh A vector of HalfEdge objects.
   */
  void Mesh::setMesh(std::vector<HalfEdge *> mesh)
  {
    this->mesh = mesh;
  }

  /**
   * @brief Set the faces of the Mesh object
   *
   * @param faces A vector of Face objects.
   */
  void Mesh::setFaces(std::vector<Face *> faces)
  {
    this->faces = faces;
  }

  /**
   * @brief Set the number of faces of the Mesh object
   *
   * @param num_faces The number of faces of the Mesh object.
   */
  void Mesh::setNumFaces(int num_faces)
  {
    this->num_faces = num_faces;
  }

  /**
   * @brief Set the id of the Mesh object
   *
   * @param id A string containing the id of the Mesh object.
   */
  void Mesh::setId(std::string id)
  {
    this->id = id;
  }

  /**
   * @brief Assignment operator of Mesh::Mesh object
   *
   * @param o The Mesh object to copy.
   * @return Mesh& A reference to the Mesh object.
   */
  Mesh &Mesh::operator=(const Mesh &o)
  {
    this->vertexes = o.vertexes;
    this->mesh = o.mesh;
    this->faces = o.faces;
    this->num_faces = o.num_faces;
    this->id = o.id;

    return *this;
  }

  /**
   * @brief Create the mesh of the Mesh object
   *
   * @param _vertexes A vector of Vector objects.
   * @param _faces A vector of vectors containing the indexes of the vertices that form a face
   */
  void Mesh::createMesh(std::vector<Vector *> _vertexes, std::vector<std::vector<int>> _faces)
  {
    std::vector<Vector *> vertexes;
    std::vector<Face *> faces;
    std::vector<HalfEdge *> mesh;

    // create vertexes of the mesh
    for (auto &v : _vertexes)
    {
      vertexes.push_back(v);
    }

    // create faces of the mesh
    for (int i = 0; i < _faces.size(); i++)
    {
      faces.push_back(new Face());
      faces[i]->setId("f" + std::to_string(i));
    }

    // variable to store the index of the half edge (just for the id)
    int k = 0;
    // create half edges of the mesh
    for (int i = 0; i < _faces.size(); i++)
    {
      // get the number of vertices of the face
      int num_vertices = _faces[i].size();

      // vector to store the half edges of the face
      std::vector<HalfMesh::HalfEdge *> face_half_edges = {};

      // create the half edges of the face
      for (int j = 0; j < num_vertices; j++)
      {
        HalfMesh::HalfEdge *he = new HalfEdge();
        he->setId("he" + std::to_string(k));
        mesh.push_back(he);
        face_half_edges.push_back(he);
        k++;
      }

      // set the half edges of the face
      for (int j = 0; j < num_vertices; j++)
      {
        HalfMesh::HalfEdge *he = face_half_edges[j];
        he->setOrigin(vertexes[_faces[i][j]]);

        if (he->getOrigin()->getHalfEdge() == nullptr)
        {
          // associate the vertex with the half edge
          he->getOrigin()->setHalfEdge(he);
        }

        he->setNext(face_half_edges[(j + 1) % num_vertices]);
        he->setPrev(face_half_edges[(j - 1 + num_vertices) % num_vertices]);
        he->setFace(faces[i]);
      }

      faces[i]->setHalfEdge(face_half_edges[0]);
      faces[i]->setEdges(face_half_edges);
    }

    // set the twin of the half edges
    for (int i = 0; i < mesh.size(); i++)
    {
      HalfMesh::HalfEdge *he = mesh[i];

      if (he->getTwin() == nullptr)
      {
        for (int j = i + 1; j < mesh.size(); j++)
        {
          HalfMesh::HalfEdge *twin = mesh[j];

          if (he->getOrigin() == twin->getNext()->getOrigin() && he->getNext()->getOrigin() == twin->getOrigin())
          {
            he->setTwin(twin);
            twin->setTwin(he);
            break;
          }
        }
      }
    }

    // set the half edges of the vertexes
    this->setVertexes(vertexes);
    this->setMesh(mesh);
    this->setFaces(faces);
  }

} // namespace object