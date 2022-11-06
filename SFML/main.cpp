#include <SFML/Graphics.hpp>

int main()
{
	setlocale(LC_ALL, "Russian");
	sf::RenderWindow window(sf::VideoMode(900, 600), "Hello world!");
	sf::Event event; 
	window.setFramerateLimit(60);
	sf::CircleShape circle;
	circle.setRadius(100.f);
	circle.setFillColor(sf::Color::Black);
	circle.setPosition(0.f, 200.f);
	sf::Clock clk;
	double dy = 0;
	bool onGround = true;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float elapsed = clk.restart().asMilliseconds();
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			circle.move(100 * elapsed / 1000, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			circle.move(-100 * elapsed / 1000, 0);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			onGround = false;
			dy = -5;
		}
		if (!onGround)
		{
			dy += elapsed * 0.010;
		}
		circle.move(0, dy);
		if (circle.getPosition().y > 200) {
			onGround = true;
			dy = 0;
		}
		window.clear(sf::Color::White);
		window.draw(circle);
		window.display();
	}
	
	return 0;
}