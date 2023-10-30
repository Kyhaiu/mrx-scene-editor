#include <core/half_edge.hpp>
#include <core/vector.hpp>
#include <core/face.hpp>

#include <iostream>
#include <string>

namespace HalfMesh
{

  /**
   * @brief Construct a new HalfEdge::HalfEdge object
   *
   */
  HalfEdge::HalfEdge()
  {
    this->origin = new Vector();
    this->twin = nullptr;
    this->prev = nullptr;
    this->next = nullptr;
    this->face = nullptr;
    this->id = "";
  }

  /**
   * @brief Construct a new HalfEdge::HalfEdge object
   *
   * @param origin A Vector object representing the origin of the HalfEdge.
   * @param twin The twin halfedge::HalfEdge object.
   * @param next The next halfedge::HalfEdge object in the face.
   * @param face The Face object that the HalfEdge belongs to.
   * @param id A string containing the id of the halfedge::HalfEdge.
   */
  HalfEdge::HalfEdge(Vector *origin, HalfEdge *twin, HalfEdge *prev, HalfEdge *next, Face *face, std::string id)
  {
    this->origin = origin;
    this->twin = twin;
    this->prev = prev;
    this->next = next;
    this->face = face;
    this->id = id;
  }

  /**
   * @brief Copy constructor of HalfEdge::HalfEdge object
   *
   * @param he The HalfEdge object to copy.
   */
  HalfEdge::HalfEdge(const HalfEdge &he)
  {
    this->origin = he.origin;
    this->twin = he.twin;
    this->prev = he.prev;
    this->next = he.next;
    this->face = he.face;
    this->id = he.id;
  }

  HalfEdge::~HalfEdge()
  {
    delete this;
  }

  /**
   * @brief Get the origin of the HalfEdge object
   *
   * @return Vector A Vector object representing the origin of the HalfEdge.
   */
  Vector *HalfEdge::getOrigin() const
  {
    return this->origin;
  }

  /**
   * @brief Get the twin of the HalfEdge object
   *
   * @return halfedge::HalfEdge* A pointer to the twin halfedge::HalfEdge object.
   */
  HalfEdge *HalfEdge::getTwin() const
  {
    return this->twin;
  }

  /**
   * @brief Get the prev of the HalfEdge object
   *
   * @return halfedge::HalfEdge* A pointer to the previous halfedge::HalfEdge object.
   */
  HalfEdge *HalfEdge::getPrev() const
  {
    return this->prev;
  }

  /**
   * @brief Get the next of the HalfEdge object
   *
   * @return halfedge::HalfEdge* A pointer to the next halfedge::HalfEdge object.
   */
  HalfEdge *HalfEdge::getNext() const
  {
    return this->next;
  }

  /**
   * @brief Get the face of the HalfEdge object
   *
   * @return Face* A pointer to the Face object that the HalfEdge belongs to.
   */
  Face *HalfEdge::getFace() const
  {
    return this->face;
  }

  /**
   * @brief Get the id of the HalfEdge object
   *
   * @return std::string A string containing the id of the halfedge::HalfEdge.
   */
  std::string HalfEdge::getId() const
  {
    return this->id;
  }

  /**
   * @brief Set the origin of the HalfEdge object
   *
   * @param origin A Vector object representing the origin of the HalfEdge.
   */
  void HalfEdge::setOrigin(Vector *origin)
  {
    this->origin = origin;
  }

  /**
   * @brief Set the twin of the HalfEdge object
   *
   * @param twin A pointer to the twin halfedge::HalfEdge object.
   */
  void HalfEdge::setTwin(HalfEdge *twin)
  {
    this->twin = twin;
  }

  /**
   * @brief Set the prev of the HalfEdge object
   *
   * @param prev A pointer to the previous halfedge::HalfEdge object.
   */
  void HalfEdge::setPrev(HalfEdge *prev)
  {
    this->prev = prev;
  }

  /**
   * @brief Set the next of the HalfEdge object
   *
   * @param next A pointer to the next halfedge::HalfEdge object.
   */
  void HalfEdge::setNext(HalfEdge *next)
  {
    this->next = next;
  }

  /**
   * @brief Set the face of the HalfEdge object
   *
   * @param face A pointer to the Face object that the HalfEdge belongs to.
   */
  void HalfEdge::setFace(Face *face)
  {
    this->face = face;
  }

  /**
   * @brief Set the id of the HalfEdge object
   *
   * @param id A string containing the id of the halfedge::HalfEdge.
   */
  void HalfEdge::setId(std::string id)
  {
    this->id = id;
  }

  /**
   * @brief Overload of the << operator of HalfEdge::HalfEdge object
   *
   * @param os The output stream.
   * @param he The HalfEdge object to print.
   * @return std::ostream& A reference to the output stream.
   */
  std::ostream &operator<<(std::ostream &os, const HalfEdge &he)
  {

    os << he.id << ": (\n";
    os << "\torigin: " << he.getOrigin()->getId() << "\n";
    os << "\tprev: " << he.prev->getOrigin()->getId() << "\n";
    os << "\tnext: " << he.next->getOrigin()->getId() << "\n";
    os << "\ttwin: " << he.twin->getOrigin()->getId() << "\n";
    os << "\tface: " << he.face->getId() << "\n"
       << ")";
    return os;
  }

  /**
   * @brief Assignment operator of HalfEdge::HalfEdge object
   *
   * @param he The HalfEdge object to copy.
   * @return HalfEdge& A reference to the HalfEdge object.
   */
  HalfEdge &HalfEdge::operator=(const HalfEdge &he)
  {
    this->origin = he.origin;
    this->twin = he.twin;
    this->prev = he.prev;
    this->next = he.next;
    this->face = he.face;
    this->id = he.id;

    return *this;
  }
} // namespace halfedge