#include <SFML\Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Vector2.h"
#include <Vector>

# define M_PI 3.141592653589793238462643383279502884L /* pi */

class MaterialPoint
{
public:
    MaterialPoint() {};

    virtual ~MaterialPoint() {};
    virtual void UpdatePosition(float dt)
    {
        position.v_x += dt * velocity.v_x;
        position.v_y += dt * velocity.v_y;
    };

    Vector2 GetImpulse() const {};

    Vector2 position;
    Vector2 velocity;
};

class Ball : public MaterialPoint
{
public:
    float radius = 10;
    sf::CircleShape circle;
};

class Ray : public MaterialPoint
{
public:
    float length = 120;
    float width = 10;
    sf::RectangleShape rectangle;
};


int main()
{ 
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    sf::Clock clock;

    sf::Texture texture;
    texture.loadFromFile("C:/Users/lenovo/Desktop/TestSFML242_x64/TestSFML/vc2017project/testSFML/smile.png");
    sf::Sprite circle(texture);
    circle.setPosition(300, 300);

    std::vector<Ball> particles;
    std::vector<Ray> rays;

    while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
      }

      window.clear(sf::Color::Black);

      sf::Vector2u circleSize = circle.getTexture()->getSize();
      circle.setOrigin(circleSize.x / 2, circleSize.y / 2);

      sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
      sf::Vector2f center = circle.getPosition();
      sf::Vector2f d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

      circle.setRotation(90 + atan2f(d.y, d.x) * 180 / M_PI);

      int X = circle.getPosition().x;
      int Y = circle.getPosition().y;

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
          circle.move(-1, 0);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
          circle.move(1, 0);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
          circle.move(0, -1);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      {
          circle.move(0, 1);
      }

      window.draw(circle);

      if (circle.getPosition().x < 128 || circle.getPosition().x > 672 || circle.getPosition().y < 128 || circle.getPosition().y > 672)
      {
          circle.setPosition(X, Y);
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
          mousePosition = sf::Mouse::getPosition(window);
          d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

          Ball p;

          p.position = Vector2(mousePosition.x, mousePosition.y);
          p.circle.setRadius(p.radius);
          p.velocity = Vector2(40 * d.x / sqrt(abs(d.x) * abs(d.x) + abs(d.y) * abs(d.y)), 40 * d.y / sqrt(abs(d.x) * abs(d.x) + abs(d.y) * abs(d.y)));
          p.circle.setPosition(p.position.getX(), p.position.getY());
          p.circle.setFillColor(sf::Color::Red);
          particles.push_back(p);
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
      {
          mousePosition = sf::Mouse::getPosition(window);
          d = sf::Vector2f(mousePosition.x, mousePosition.y) - center;

          Ray r;

          r.position = Vector2(mousePosition.x, mousePosition.y);
          r.velocity = Vector2(40 * d.x / sqrt(abs(d.x) * abs(d.x) + abs(d.y) * abs(d.y)), 40 * d.y / sqrt(abs(d.x) * abs(d.x) + abs(d.y) * abs(d.y)));
          r.rectangle.setSize(sf::Vector2f(r.width, r.length));
          r.rectangle.setPosition(r.position.getX(), r.position.getY());
          r.rectangle.setFillColor(sf::Color::Red);
          r.rectangle.setRotation(90 + atan2f(d.y, d.x) * 180 / M_PI);
          rays.push_back(r);
      }

      for (size_t i = 0; i < particles.size(); ++i)
      {
          particles[i].UpdatePosition(0.01);
          particles[i].circle.setPosition(particles[i].position.v_x, particles[i].position.v_y);
          window.draw(particles[i].circle);
      }

      for (size_t i = 0; i < rays.size(); ++i)
      {
          rays[i].UpdatePosition(0.01);
          rays[i].rectangle.setPosition(rays[i].position.v_x, rays[i].position.v_y);
          window.draw(rays[i].rectangle);
      }

      window.display();
     }
  
     return 0;
}