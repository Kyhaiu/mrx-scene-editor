#include <core/face.hpp>

namespace face
{

  /**
   * @brief Construct a new Face::Face object
   *
   */
  Face::Face()
  {
    this->edges = std::vector<halfedge::HalfEdge>();
    this->halfedge = nullptr;
    this->visible = false;
    this->centroid = vector::Vector();
    this->normal = vector::Vector();
  }

  /**
   * @brief Construct a new Face::Face object
   *
   * @param edges A vector of halfedge::HalfEdge objects.
   * @param halfedge A pointer to the halfedge::HalfEdge object.
   * @param visible A boolean value indicating whether the face is visible or not.
   * @param centroid A vector::Vector object representing the centroid of the face.
   * @param normal A vector::Vector object representing the normal of the face.
   */
  Face::Face(std::vector<halfedge::HalfEdge> edges, halfedge::HalfEdge *halfedge, bool visible, vector::Vector centroid, vector::Vector normal)
  {
    this->edges = edges;
    this->visible = visible;
    this->halfedge = halfedge;
    this->centroid = centroid;
    this->normal = normal;
  }

  /**
   * @brief Copy constructor of Face::Face object
   *
   * @param f The Face object to copy.
   */
  Face::Face(const Face &f)
  {
    this->edges = f.edges;
    this->halfedge = f.halfedge;
    this->visible = f.visible;
    this->centroid = f.centroid;
    this->normal = f.normal;
  }

  Face::~Face()
  {
    delete this;
  }

  /**
   * @brief Get the edges of the Face object
   *
   * @return std::vector<halfedge::HalfEdge> A vector of halfedge::HalfEdge objects.
   */
  std::vector<halfedge::HalfEdge> Face::getEdge() const
  {
    return this->edges;
  }

  /**
   * @brief Get the halfedge of the Face object
   *
   * @return halfedge::HalfEdge* A pointer to the halfedge::HalfEdge object.
   */
  halfedge::HalfEdge *Face::getHalfEdge() const
  {
    return this->halfedge;
  }

  /**
   * @brief Get the centroid of the Face object
   *
   * @return vector::Vector A vector::Vector object representing the centroid of the face.
   */
  vector::Vector Face::getCentroid() const
  {
    return this->centroid;
  }

  /**
   * @brief Get the normal of the Face object
   *
   * @return vector::Vector A vector::Vector object representing the normal of the face.
   */
  vector::Vector Face::getNormal() const
  {
    return this->normal;
  }

  /**
   * @brief Set the edges of the Face object
   *
   * @param edges A vector of halfedge::HalfEdge objects.
   */
  void Face::setEdge(std::vector<halfedge::HalfEdge> edges)
  {
    this->edges = edges;
  }

  /**
   * @brief Set the halfedge of the Face object
   *
   * @param halfedge A pointer to the halfedge::HalfEdge object.
   */
  void Face::setHalfEdge(halfedge::HalfEdge *halfedge)
  {
    this->halfedge = halfedge;
  }

  /**
   * @brief Set the centroid of the Face object
   *
   * @param centroid A vector::Vector object representing the centroid of the face.
   */
  void Face::setCentroid(vector::Vector centroid)
  {
    this->centroid = centroid;
  }

  /**
   * @brief Set the normal of the Face object
   *
   * @param normal A vector::Vector object representing the normal of the face.
   */
  void Face::setNormal(vector::Vector normal)
  {
    this->normal = normal;
  }

  /**
   * @brief Get the visibility of the Face object
   *
   * @return true If the face is visible.
   * @return false If the face is not visible.
   */
  bool Face::isVisible() const
  {
    return this->visible;
  }

  /**
   * @brief Define the centroid of the Face object
   *
   */
  void Face::defineCentroid()
  {
    vector::Vector centroid = vector::Vector();
    for (auto &he : this->edges)
    {
      centroid = centroid + he.getOrigin();
    }
    // The centroid in this case is the average of the vertices
    centroid = centroid / this->edges.size();
    this->setCentroid(centroid);
  }

  /**
   * @brief Define the normal of the Face object
   *
   */
  void Face::defineNormal()
  {
    vector::Vector normal = vector::Vector();
    for (auto &he : this->edges)
    {
      normal = normal + he.getOrigin();
    }
    normal = normal / this->edges.size();
    this->normal = normal;
  }

  /**
   * @brief Assignment operator of Face::Face object
   *
   * @param f The Face object to copy.
   * @return Face& A reference to the Face object.
   */
  Face &Face::operator=(const Face &f)
  {
    this->edges = f.edges;
    this->halfedge = f.halfedge;
    this->visible = f.visible;
    this->centroid = f.centroid;
    this->normal = f.normal;
    return *this;
  }
} // namespace face