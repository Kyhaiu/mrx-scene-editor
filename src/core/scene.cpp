#include <core/scene.hpp>
#include <core/camera.hpp>

namespace Core
{
  Scene::Scene()
  {
    this->objects = std::vector<Mesh *>();
    this->camera = new Core::Camera();
  }

  Scene::Scene(std::vector<Mesh *> objects, Core::Camera *camera)
  {
    this->objects = objects;
    this->camera = camera;
  }

  Scene::Scene(const Scene &o)
  {
    this->objects = o.objects;
    this->camera = o.camera;
  }

  Scene::~Scene()
  {
    delete this;
  }

  std::vector<Mesh *> Scene::getObjects() const
  {
    return this->objects;
  }

  Core::Camera *Scene::getCamera() const
  {
    return this->camera;
  }

  void Scene::setObjects(std::vector<Mesh *> objects)
  {
    this->objects = objects;
  }

  void Scene::setCamera(Core::Camera *camera)
  {
    this->camera = camera;
  }

  Scene &Scene::operator=(const Scene &o)
  {
    this->objects = o.objects;
    this->camera = o.camera;
    return *this;
  }

  void Scene::addObject(Mesh *object)
  {
    this->objects.push_back(object);
  }

  void Scene::removeObject(Mesh *object)
  {
    for (int i = 0; i < this->objects.size(); i++)
    {
      if (this->objects[i] == object)
      {
        this->objects.erase(this->objects.begin() + i);
        break;
      }
    }
  }

  void Scene::moveCamera(Vector *direction)
  {
    this->camera->move(direction);
  }
} // namespace Core