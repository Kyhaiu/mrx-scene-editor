#include <core/face.hpp>
#include <core/half_edge.hpp>

#include <iostream>
#include <string>

namespace Core
{

  /**
   * @brief Construct a new Face::Face object
   *
   */
  Face::Face()
  {
    this->edges = std::vector<HalfEdge *>();
    this->halfedge = nullptr;
    this->visible = false;
    this->id = "";
  }

  /**
   * @brief Construct a new Face::Face object
   *
   * @param edges A vector of HalfEdge objects.
   * @param halfedge A pointer to the HalfEdge object.
   * @param visible A boolean value indicating whether the face is visible or not.
   * @param id A string containing the id of the face.
   */
  Face::Face(std::vector<HalfEdge *> edges, HalfEdge *halfedge, bool visible, std::string id)
  {
    this->edges = edges;
    this->visible = visible;
    this->halfedge = halfedge;
    this->id = id;
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
    this->id = f.id;
  }

  Face::~Face()
  {
    delete this;
  }

  /**
   * @brief Get the edges of the Face object
   *
   * @return std::vector<HalfEdge> A vector of HalfEdge objects.
   */
  std::vector<HalfEdge *> Face::getEdges() const
  {
    return this->edges;
  }

  /**
   * @brief Get the halfedge of the Face object
   *
   * @return HalfEdge* A pointer to the HalfEdge object.
   */
  HalfEdge *Face::getHalfEdge() const
  {
    return this->halfedge;
  }

  /**
   * @brief Get the id of the Face object
   *
   * @return std::string A string containing the id of the face.
   */
  std::string Face::getId() const
  {
    return this->id;
  }

  /**
   * @brief Set the edges of the Face object
   *
   * @param edges A vector of HalfEdge objects.
   */
  void Face::setEdges(std::vector<HalfEdge *> edges)
  {
    this->edges = edges;
  }

  /**
   * @brief Set the halfedge of the Face object
   *
   * @param halfedge A pointer to the HalfEdge object.
   */
  void Face::setHalfEdge(HalfEdge *halfedge)
  {
    this->halfedge = halfedge;
  }

  /**
   * @brief Set the id of the Face object
   *
   * @param id A string containing the id of the face.
   */
  void Face::setId(std::string id)
  {
    this->id = id;
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
   * @brief Overload of the << operator for the Face::Face object
   *
   * @param os The output stream.
   * @param f The Face object to print.
   * @return std::ostream& A reference to the output stream.
   */
  std::ostream &operator<<(std::ostream &os, const Face &f)
  {
    const char *visible = f.visible ? "true" : "false";

    os << f.id << ": (\n"
       << "\tedges: (\n";
    for (auto &e : f.edges)
    {
      os << "\t\t" << e->getId() << "\n";
    }
    os << "\t)\n"
       << "\thalfedge: " << f.halfedge->getId() << "\n"
       << "\tvisible: " << visible
       << "\n"
       << ")";
    return os;
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
    this->id = f.id;
    return *this;
  }
} // namespace face