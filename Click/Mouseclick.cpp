#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::RectangleShape rectangle;
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setSize(sf::Vector2f(50.f, 50.f));
    rectangle.setPosition(500, 100);

    sf::RectangleShape rectangletwee;
    rectangletwee.setFillColor(sf::Color::Red);
    rectangletwee.setSize(sf::Vector2f(50.f, 50.f));
    rectangletwee.setPosition(500, 200);

    bool greenCircleVisible = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    // Controleer of de muisklik binnen de grenzen van de rechthoek is
                    if (mousePosition.x >= rectangle.getPosition().x &&
                        mousePosition.x <= rectangle.getPosition().x + rectangle.getSize().x &&
                        mousePosition.y >= rectangle.getPosition().y &&
                        mousePosition.y <= rectangle.getPosition().y + rectangle.getSize().y)
                    {
                        greenCircleVisible = true;
                    }
                    if (mousePosition.x >= rectangletwee.getPosition().x &&
                        mousePosition.x <= rectangletwee.getPosition().x + rectangletwee.getSize().x &&
                        mousePosition.y >= rectangletwee.getPosition().y &&
                        mousePosition.y <= rectangletwee.getPosition().y + rectangletwee.getSize().y && greenCircleVisible)
                    {
                        greenCircleVisible = false;
                    }
                }
            }
        }

        window.clear();
        window.draw(rectangle);
        window.draw(rectangletwee);
   
        if (greenCircleVisible)
            window.draw(shape);

        window.display();
    }

    return 0;
}
