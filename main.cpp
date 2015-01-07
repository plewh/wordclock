#include <SFML/Graphics.hpp>
#include <string>

void HandleInput(sf::RenderWindow* window);
void RenderFrame(sf::RenderWindow* window);
void RenderTextCentered(sf::RenderWindow* window, std::string str);
bool running = true;
sf::Font font;
font.loadFromFile("ass/font.ttf");

int main() {

	sf::RenderWindow window(sf::VideoMode(640, 480), "word clock");

	while (running) {

		HandleInput(&window);
		RenderFrame(&window);

	}

	window.close();

}

void HandleInput(sf::RenderWindow* window) {

	sf::Event event;
	std::string buffer;

	while (window->pollEvent(event)) {

		switch (event.type) {
			
			case (sf::Event::Closed):
				running = false;
				break;

			default:
				break;

		}

	}

}

void RenderFrame(sf::RenderWindow* window) {

	window->clear();
	RenderTextCentered(window, "derp my herp");
	window->display();

}

void RenderTextCentered(sf::RenderWindow* window, std::string str) {

	;

}
