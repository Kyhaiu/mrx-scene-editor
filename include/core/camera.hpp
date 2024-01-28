#pragma once

#include <core/common.hpp>
#include <vector>

namespace Core
{
  class Camera
  {
  private:
    Vertex::Vertex vrp;
    Vertex::Vertex p;
    double d;
    std::vector<double> view_port;
    std::vector<double> window;

  public:
    Camera();
    Camera(Vertex::Vertex vrp, Vertex::Vertex p, double d, std::vector<double> view_port, std::vector<double> window);
    Camera(const Camera &c);
    ~Camera();

    Vertex::Vertex getVRP() const;
    Vertex::Vertex getP() const;
    double getD() const;
    std::vector<double> getViewPort() const;
    std::vector<double> getWindow() const;

    void setVRP(Vertex::Vertex vrp);
    void setP(Vertex::Vertex p);
    void setD(double d);
    void setViewPort(std::vector<double> view_port);
    void setWindow(std::vector<double> window);

    friend std::ostream &operator<<(std::ostream &os, const Camera &c);

    Camera &operator=(const Camera &c);

    bool operator==(const Camera &c) const;
    bool operator!=(const Camera &c) const;

    void move(Vector *direction);
    void rotate(Vector *direction);
    void zoom(Vector *direction);
  };
} // namespace Camera