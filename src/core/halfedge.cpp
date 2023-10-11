#include <core/half_edge.hpp>

namespace halfedge
{

  /**
   * @brief Construct a new HalfEdge::HalfEdge object
   *
   */
  HalfEdge::HalfEdge()
  {
    this->origin = vector::Vector();
    this->twin = nullptr;
    this->prev = nullptr;
    this->next = nullptr;
    this->face = nullptr;
  }

  /**
   * @brief Construct a new HalfEdge::HalfEdge object
   *
   * @param origin A vector::Vector object representing the origin of the HalfEdge.
   * @param twin The twin halfedge::HalfEdge object.
   * @param next The next halfedge::HalfEdge object in the face.
   * @param face The face::Face object that the HalfEdge belongs to.
   */
  HalfEdge::HalfEdge(vector::Vector origin, HalfEdge *twin, HalfEdge *prev, HalfEdge *next, face::Face *face)
  {
    this->origin = origin;
    this->twin = twin;
    this->prev = prev;
    this->next = next;
    this->face = face;
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
  }

  HalfEdge::~HalfEdge()
  {
    delete this;
  }

  /**
   * @brief Get the origin of the HalfEdge object
   *
   * @return vector::Vector A vector::Vector object representing the origin of the HalfEdge.
   */
  vector::Vector HalfEdge::getOrigin() const
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
   * @return face::Face* A pointer to the face::Face object that the HalfEdge belongs to.
   */
  face::Face *HalfEdge::getFace() const
  {
    return this->face;
  }

  /**
   * @brief Set the origin of the HalfEdge object
   *
   * @param origin A vector::Vector object representing the origin of the HalfEdge.
   */
  void HalfEdge::setOrigin(vector::Vector origin)
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
   * @param face A pointer to the face::Face object that the HalfEdge belongs to.
   */
  void HalfEdge::setFace(face::Face *face)
  {
    this->face = face;
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

    return *this;
  }
} // namespace halfedge