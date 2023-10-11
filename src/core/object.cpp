#include <core/object.hpp>

namespace object
{

  /**
   * @brief Construct a new Object::Object object
   *
   */
  Object::Object()
  {
    this->vertexes = std::vector<vector::Vector>();
    this->mesh = std::vector<halfedge::HalfEdge>();
    this->faces = std::vector<face::Face>();
  }

  /**
   * @brief Construct a new Object::Object object
   *
   * @param vertexes A vector of vector::Vector objects.
   * @param faces A vector of vectors containing the indexes of the vertices that form a face
   */
  Object::Object(std::vector<vector::Vector> vertexes, std::vector<std::vector<int>> faces)
  {
    this->createMesh(vertexes, faces);
  }

  /**
   * @brief Copy constructor of Object::Object object
   *
   * @param o The Object object to copy.
   */
  Object::Object(const Object &o)
  {
    this->vertexes = o.vertexes;
    this->mesh = o.mesh;
    this->faces = o.faces;
  }

  Object::~Object()
  {
    delete this;
  }

  /**
   * @brief Get the vertexes of the Object object
   *
   * @return std::vector<vector::Vector> A vector of vector::Vector objects.
   */
  std::vector<vector::Vector> Object::getVertexes() const
  {
    return this->vertexes;
  }

  /**
   * @brief Get the mesh of the Object object
   *
   * @return std::vector<halfedge::HalfEdge> A vector of halfedge::HalfEdge objects.
   */
  std::vector<halfedge::HalfEdge> Object::getMesh() const
  {
    return this->mesh;
  }

  /**
   * @brief Get the faces of the Object object
   *
   * @return std::vector<face::Face> A vector of face::Face objects.
   */
  std::vector<face::Face> Object::getFaces() const
  {
    return this->faces;
  }

  /**
   * @brief Assignment operator of Object::Object object
   *
   * @param o The Object object to copy.
   * @return Object& A reference to the Object object.
   */
  Object &Object::operator=(const Object &o)
  {
    this->vertexes = o.vertexes;
    this->mesh = o.mesh;
    this->faces = o.faces;

    return *this;
  }

  /**
   * @brief Create the mesh of the Object object
   *
   */
  void Object::createMesh(std::vector<vector::Vector> _vertexes, std::vector<std::vector<int>> _faces)
  {
    std::vector<vector::Vector *> vertexes;
    std::vector<face::Face *> faces;
    std::vector<halfedge::HalfEdge *> mesh;

    // create vertexes of the mesh
    for (auto &v : _vertexes)
    {
      vertexes.push_back(&v);
    }

    // create faces of the mesh
    for (auto &f : _faces)
    {
      faces.push_back(new face::Face());
    }

    int i = 0;
    int num_vertexes = 0;
    // create mesh of the object
    for (auto &f : _faces)
    {
      num_vertexes = f.size();
      std::vector<halfedge::HalfEdge *> face_mesh;

      // create halfedges of the face
      for (int j = 0; j < num_vertexes; j++)
      {
        halfedge::HalfEdge *he = new halfedge::HalfEdge();
        face_mesh.push_back(he);
        mesh.push_back(he);
      }

      // connect halfedges of the face
      for (int j = 0; j < num_vertexes; j++)
      {
        halfedge::HalfEdge *he = face_mesh[j];

        he->setOrigin(*vertexes[f[j]]);

        if (he->getOrigin() != nullptr)
        {
          vertexes[f[j]]->setHalfEdge(he);
        }

        he->setNext(face_mesh[(j + 1) % num_vertexes]);
        he->setPrev(face_mesh[(j - 1) % num_vertexes]);
        he->setFace(faces[i]);
      }

      faces[i]->setHalfEdge(face_mesh[0]);
    }

    // connect twin halfedges of the mesh
    for (int j = 0; i < mesh.size(); j++)
    {
      halfedge::HalfEdge *he = mesh[j];
      halfedge::HalfEdge *twin = nullptr;

      if (he->getTwin() == nullptr)
      {
        for (int k = 0; j + 1 < mesh.size(); k++)
        {
          twin = mesh[k];

          if (he->getOrigin() == twin->getNext()->getOrigin() && he->getNext()->getOrigin() == twin->getOrigin())
          {
            he->setTwin(twin);
            twin->setTwin(he);
            break;
          }
        }
      }
    }
  }
} // namespace object