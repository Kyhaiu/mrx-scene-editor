#pragma once

#include <core/common.hpp>
#include <vector>

namespace Core
{
  class Scene
  {
  private:
    std::vector<Mesh *> objects;
    Core::Camera *camera;

  public:
    Scene();
    Scene(std::vector<Mesh *> objects, Core::Camera *camera);
    Scene(const Scene &o);
    ~Scene();

    std::vector<Mesh *> getObjects() const;
    Core::Camera *getCamera() const;

    void setObjects(std::vector<Mesh *> objects);
    void setCamera(Core::Camera *camera);

    Scene &operator=(const Scene &o);

    void addObject(Mesh *object);
    void removeObject(Mesh *object);

    void moveCamera(Vector *direction);
    void rotateCamera(Vector *direction);
    void zoomCamera(Vector *direction);

    void render();
  };
} // namespace Core