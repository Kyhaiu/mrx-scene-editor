
#include <core/scene.hpp>
#include <core/mesh.hpp>
#include <core/face.hpp>
#include <core/vector.hpp>
#include <core/half_edge.hpp>
#include <utils/sfml-utils.hpp>
#include <core/vector.hpp>
#include <pipeline/pipeline.hpp>
#include <math/math.hpp>

#include <core/camera.hpp>

namespace gui
{
  class Canvas
  {
  public:
    Core::Scene *scene;
    sf::RenderWindow *window;

    Canvas()
    {
      this->scene = new Core::Scene();
      this->window = nullptr;

      // Bottom-left-back
      Core::Vector *v0 = new Core::Vector(-1.0, -1.0, -1.0, 1.0, nullptr, "v0");
      // Bottom-right-back
      Core::Vector *v1 = new Core::Vector(1.0, -1.0, -1.0, 1.0, nullptr, "v1");
      // Bottom-right-front
      Core::Vector *v2 = new Core::Vector(1.0, -1.0, 1.0, 1.0, nullptr, "v2");
      // Bottom-left-front
      Core::Vector *v3 = new Core::Vector(-1.0, -1.0, 1.0, 1.0, nullptr, "v3");
      // Top-left-back
      Core::Vector *v4 = new Core::Vector(-1.0, 1.0, -1.0, 1.0, nullptr, "v4");
      // Top-right-back
      Core::Vector *v5 = new Core::Vector(1.0, 1.0, -1.0, 1.0, nullptr, "v5");
      // Top-right-front
      Core::Vector *v6 = new Core::Vector(1.0, 1.0, 1.0, 1.0, nullptr, "v6");
      // Top-left-front
      Core::Vector *v7 = new Core::Vector(-1.0, 1.0, 1.0, 1.0, nullptr, "v7");

      std::vector<std::vector<int>> faces = {
          // Back Face
          {2, 6, 7, 3},
          // Left Face
          {1, 0, 4, 5},
          // Bottom Face
          {3, 7, 4, 0},
          // Right Face
          {2, 3, 0, 1},
          // Top Face
          {6, 2, 1, 5},
          // Front Face
          {6, 5, 4, 7}};

      Core::Mesh *mesh = new Core::Mesh({v0, v1, v2, v3, v4, v5, v6, v7}, faces, "cube");

      std::vector<std::vector<double>> sru2src = pipeline::santa_catarina::sru2src(
          this->scene->getCamera()->getVRP(),
          this->scene->getCamera()->getP());

      for (auto &m : sru2src)
      {
        for (auto &n : m)
        {
          std::cout << n << "\t\t ";
        }
        std::cout << std::endl;
      }

      std::cout << "-------------" << std::endl;

      std::vector<std::vector<double>> proj = pipeline::santa_catarina::projection(
          this->scene->getCamera()->getVRP(),
          this->scene->getCamera()->getP(),
          this->scene->getCamera()->getD());

      for (auto &m : proj)
      {
        for (auto &n : m)
        {
          std::cout << n << "\t\t ";
        }
        std::cout << std::endl;
      }

      std::vector<std::vector<double>> src2srd = pipeline::santa_catarina::src2srt(
          this->scene->getCamera()->getWindow(),
          this->scene->getCamera()->getViewPort(), true);

      std::cout << "-------------" << std::endl;

      for (auto &m : src2srd)
      {
        for (auto &n : m)
        {
          std::cout << n << "\t\t ";
        }
        std::cout << std::endl;
      }

      std::cout << "-------------" << std::endl;

      std::vector<std::vector<double>> aux = Math::multiply_matrix(src2srd, proj);
      std::vector<std::vector<double>> m = Math::multiply_matrix(aux, sru2src);

      for (auto &m : m)
      {
        for (auto &n : m)
        {
          std::cout << n << "\t\t ";
        }
        std::cout << std::endl;
      }

      this->scene->addObject(mesh);

      for (auto &mesh : this->scene->getObjects())
      {
        for (auto &v : mesh->getVertexes())
        {
          std::cout << "Before: " << *v << std::endl;
          Math::apply_matrix(v, m);
          v->setX(v->getX() / v->getH());
          v->setY(v->getY() / v->getH());
          v->setH(v->getH() / v->getH());

          std::cout << "After: " << *v << std::endl;
        }
      }
    }

    Canvas(Core::Scene *scene, sf::RenderWindow *window)
    {
      this->scene = scene;
      this->window = window;
    }

    Core::Scene *getScene()
    {
      return this->scene;
    }

    sf::RenderWindow *getWindow()
    {
      return this->window;
    }

    void setScene(Core::Scene *scene)
    {
      this->scene = scene;
    }

    void setWindow(sf::RenderWindow *window)
    {
      this->window = window;
    }

    void draw()
    {
      for (auto &mesh : this->scene->getObjects())
      {
        for (auto &f : mesh->getFaces())
        {
          Core::HalfEdge *he = f->getHalfEdge();
          while (true)
          {
            utils::draw_vertex(he->getOrigin()->getVertex(), *this->getWindow());
            utils::draw_half_edge(*he, *this->getWindow());

            he = he->getNext();

            if (he == f->getHalfEdge())
            {
              break;
            }
          }
        }
      }
    };
  };
} // namespace gui