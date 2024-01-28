#include <core/camera.hpp>

namespace Core
{

  /**
   * @brief Construct a new Camera:: Camera object
   *
   */
  Camera::Camera()
  {
    this->setVRP({0.0, 0.0, 80.0});
    this->setP({0.0, 0.0, 10.0});
    this->setD(100.0);
    this->setViewPort({0, 255, 0, 255});
    this->setWindow({-3, 3, -3, 3});
  }

  /**
   * @brief Construct a new Camera:: Camera object
   *
   * @param vrp A Vertex::Vertex that represents the VRP (View Reference Point)
   * @param p A Vertex::Vertex that represents the P point (Projection point)
   * @param d A double that represents the distance between the VRP and the P point
   * @param view_port A vector of doubles that represents the view port (x_min, x_max, y_min, y_max)
   * @param window A vector of doubles that represents the window (u_min, u_max, v_min, v_max)
   */
  Camera::Camera(Vertex::Vertex vrp, Vertex::Vertex p, double d, std::vector<double> view_port, std::vector<double> window)
  {
    this->setVRP(vrp);
    this->setP(p);
    this->setD(d);
    this->setViewPort(view_port);
    this->setWindow(window);
  }

  /**
   * @brief Construct a new Camera:: Camera object
   *
   * @param c The camera to be copied
   */
  Camera::Camera(const Camera &c)
  {
    this->setVRP(c.getVRP());
    this->setP(c.getP());
    this->setD(c.getD());
    this->setViewPort(c.getViewPort());
    this->setWindow(c.getWindow());
  }

  Camera::~Camera()
  {
  }

  /**
   * @brief This method is used to get the VRP (View Reference Point)
   *
   * @return Vertex::Vertex The VRP
   */
  Vertex::Vertex Camera::getVRP() const
  {
    return this->vrp;
  }

  /**
   * @brief This method is used to get the P point (Projection point)
   *
   * @return Vertex::Vertex The P point
   */
  Vertex::Vertex Camera::getP() const
  {
    return this->p;
  }

  /**
   * @brief This method is used to get the distance between the VRP and the P point
   *
   * @return double The distance between the VRP and the P point
   */
  double Camera::getD() const
  {
    return this->d;
  }

  /**
   * @brief This method is used to get the view port (x_min, x_max, y_min, y_max)
   *
   * @return std::vector<double> The view port
   */
  std::vector<double> Camera::getViewPort() const
  {
    return this->view_port;
  }

  /**
   * @brief This method is used to get the window (u_min, u_max, v_min, v_max)
   *
   * @return std::vector<double> The window
   */
  std::vector<double> Camera::getWindow() const
  {
    return this->window;
  }

  /**
   * @brief This method is used to set the VRP (View Reference Point)
   *
   * @param vrp The VRP
   */
  void Camera::setVRP(Vertex::Vertex vrp)
  {
    this->vrp = vrp;
  }

  /**
   * @brief This method is used to set the P point (Projection point)
   *
   * @param p The P point
   */
  void Camera::setP(Vertex::Vertex p)
  {
    this->p = p;
  }

  /**
   * @brief This method is used to set the distance between the VRP and the P point
   *
   * @param d The distance between the VRP and the P point
   */
  void Camera::setD(double d)
  {
    this->d = d;
  }

  /**
   * @brief This method is used to set the view port (x_min, x_max, y_min, y_max)
   *
   * @param view_port The view port
   */
  void Camera::setViewPort(std::vector<double> view_port)
  {
    this->view_port = view_port;
  }

  /**
   * @brief This method is used to set the window (u_min, u_max, v_min, v_max)
   *
   * @param window The window
   */
  void Camera::setWindow(std::vector<double> window)
  {
    this->window = window;
  }

  /**
   * @brief This method is used to print the camera
   *
   * @param os The output stream
   * @param c The camera to be printed
   * @return std::ostream&
   */
  std::ostream &operator<<(std::ostream &os, const Camera &c)
  {
    os << "Camera{"
       << "vrp: " << c.getVRP() << ", "
       << "p: " << c.getP() << ", "
       << "d: " << c.getD() << ", "
       //  << "view_port: " << c.getViewPort() << ", "
       //  << "window: " << c.getWindow()
       << "}";
    return os;
  }

  /**
   * @brief This method is used to copy a camera
   *
   * @param c The camera to be copied
   * @return Camera& The copied camera
   */
  Camera &Camera::operator=(const Camera &c)
  {
    this->setVRP(c.getVRP());
    this->setP(c.getP());
    this->setD(c.getD());
    this->setViewPort(c.getViewPort());
    this->setWindow(c.getWindow());
    return *this;
  }

  /**
   * @brief This method is used to check if two cameras are equal
   *
   * @param c The camera to be compared
   * @return true If the cameras are equal
   * @return false If the cameras are not equal
   */
  bool Camera::operator==(const Camera &c) const
  {
    return this->getVRP() == c.getVRP() &&
           this->getP() == c.getP() &&
           this->getD() == c.getD() &&
           this->getViewPort() == c.getViewPort() &&
           this->getWindow() == c.getWindow();
  }

  /**
   * @brief This method is used to check if two cameras are not equal
   *
   * @param c The camera to be compared
   * @return true If the cameras are not equal
   * @return false If the cameras are equal
   */
  bool Camera::operator!=(const Camera &c) const
  {
    return !(*this == c);
  }

  /**
   * @brief This method is used to move the camera
   *
   * @param direction The direction to move the camera
   */
  void Camera::move(Vector *direction)
  {
    // this->setVRP(this->getVRP() + *direction);
  }

  /**
   * @brief This method is used to rotate the camera
   *
   * @param direction The direction to rotate the camera
   */
  void Camera::rotate(Vector *direction)
  {
    // TODO: Implement this
  }

  /**
   * @brief This method is used to zoom the camera
   *
   * @param direction The direction to zoom the camera
   */
  void Camera::zoom(Vector *direction)
  {
    // TODO: Implement this
  }
} // namespace Camera