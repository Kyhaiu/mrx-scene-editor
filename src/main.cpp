#include <SFML/Graphics.hpp>
#include <gui/imgui/imgui.h>
#include <gui/imgui-sfml/imgui-SFML.h>

#include <core/vector.hpp>

#include <utils/sfml-utils.hpp>

#include "./gui/canvas.cpp"

int main()
{
  // Create SFML window
  sf::RenderWindow window(sf::VideoMode(800, 800), "ImGui + SFML Triangle Example");
  window.setFramerateLimit(60);

  // Setup ImGui context
  bool isOpen = ImGui::SFML::Init(window);

  // // Bottom-right-front
  // Core::Vector *v1 = new Core::Vector(100.0, 200.0, 100.0, 1.0, nullptr, "v1");
  // // Bottom-left-front
  // Core::Vector *v2 = new Core::Vector(200.0, 200.0, 100.0, 1.0, nullptr, "v2");

  // // Top-right-front
  // Core::Vector *v3 = new Core::Vector(100.0, 100.0, 100.0, 1.0, nullptr, "v3");
  // // Top-left-front
  // Core::Vector *v4 = new Core::Vector(200.0, 100.0, 100.0, 1.0, nullptr, "v4");

  gui::Canvas *canvas = new gui::Canvas();

  canvas->setWindow(&window);

  // // Triangle vertices
  // sf::VertexArray triangle(sf::Triangles, 3);
  // triangle[0].position = sf::Vector2f(400, 100);
  // triangle[1].position = sf::Vector2f(200, 500);
  // triangle[2].position = sf::Vector2f(600, 500);
  // triangle[0].color = sf::Color::Red;
  // triangle[1].color = sf::Color::Green;
  // triangle[2].color = sf::Color::Blue;

  // Main loop
  while (window.isOpen() && isOpen)
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      ImGui::SFML::ProcessEvent(event);

      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    // Start the ImGui frame
    ImGui::SFML::Update(window, sf::seconds(1.0f / 60.0f));

    // Display the fps in the screen
    ImGui::Text("FPS: %f", ImGui::GetIO().Framerate);

    // ImGui window

    // show the value of vrp
    ImGui::Text("VRP: (%f, %f, %f)",
                canvas->scene->getCamera()->getVRP().x,
                canvas->scene->getCamera()->getVRP().y,
                canvas->scene->getCamera()->getVRP().z);
    // show the value of p
    ImGui::Text("P: (%f, %f, %f)",
                canvas->scene->getCamera()->getP().x,
                canvas->scene->getCamera()->getP().y,
                canvas->scene->getCamera()->getP().z);
    // show the value of d
    ImGui::Text("D: %f", canvas->scene->getCamera()->getD());
    // show the value of view port
    ImGui::Text("View Port: (%f, %f, %f, %f)",
                canvas->scene->getCamera()->getViewPort()[0],
                canvas->scene->getCamera()->getViewPort()[1],
                canvas->scene->getCamera()->getViewPort()[2],
                canvas->scene->getCamera()->getViewPort()[3]);
    // show the value of window
    ImGui::Text("Window: (%f, %f, %f, %f)",
                canvas->scene->getCamera()->getWindow()[0],
                canvas->scene->getCamera()->getWindow()[1],
                canvas->scene->getCamera()->getWindow()[2],
                canvas->scene->getCamera()->getWindow()[3]);

    // Rendering
    window.clear();

    canvas->draw();

    // // Draw the thing
    // utils::draw_vertex(v1->getVertex(), window);
    // utils::draw_vertex(v2->getVertex(), window);
    // utils::draw_vertex(v3->getVertex(), window);
    // utils::draw_vertex(v4->getVertex(), window);

    // Render ImGui
    ImGui::SFML::Render(window);

    window.display();
  }

  // Cleanup
  ImGui::SFML::Shutdown();

  return 0;
}
