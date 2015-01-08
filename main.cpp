#include <cstdio>
#include <string>
#include <ctime>
#include <SFML/Graphics.hpp>

/* consts */
#define ITOA_CHAR_BUFF_MAX 20
#define WIN_WIDTH 1024
#define WIN_HEIGHT 786
#define TEXT_SIZE 52
#define REFRESH_FREQ 30.0 //fps

/* funcs */
void HandleInput(sf::RenderWindow* window);
void RenderFrame(sf::RenderWindow* window, std::string const* buffer, sf::Font const* font);
void RenderTextCentered(sf::RenderWindow* window, std::string const* buffer, sf::Font const* font);
std::string GetTimeString();
std::string itoa(int num);
std::string GetWords(int hours, int mins);
std::string LookUpWord(int num);

/* globals */
bool running = true;

int main() {

	sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "word clock", sf::Style::Fullscreen);
	window.setMouseCursorVisible(false);
	sf::Font font;
	font.loadFromFile("ass/font.ttf");
	std::string buffer;
	sf::Clock clock;
	sf::Time time;

	clock.restart();

	while (running) {

		HandleInput(&window);

		buffer = GetTimeString();
		RenderFrame(&window, &buffer, &font);

		time = clock.restart();
		sf::sleep(sf::seconds((1.0/REFRESH_FREQ) - time.asSeconds()));

	}

	window.close();

}

void HandleInput(sf::RenderWindow* window) {

	sf::Event event;

	while (window->pollEvent(event)) {

		switch (event.type) {
			
			case sf::Event::Closed:
			case sf::Event::KeyPressed:
			case sf::Event::MouseMoved:
			case sf::Event::MouseButtonPressed:
				running = false;
				break;

			default:
				break;

		}

	}

}

void RenderFrame(sf::RenderWindow* window, std::string const* buffer, sf::Font const* font) {

	window->clear();
	RenderTextCentered(window, buffer, font);
	window->display();

}

void RenderTextCentered(sf::RenderWindow* window, std::string const* buffer, sf::Font const* font) {

	sf::Text text;
	text.setFont(*font);
	text.setColor(sf::Color::White);
	text.setCharacterSize(TEXT_SIZE);
	text.setString(buffer->c_str());
	text.setPosition((window->getSize().x - text.getGlobalBounds().width) / 2, (window->getSize().y - text.getGlobalBounds().height) / 2 );

	window->draw(text);

}

std::string GetTimeString() {

	std::time_t rawTime = std::time(NULL);
	std::tm* tChunks = std::localtime(&rawTime);

	std::string tString = GetWords(tChunks->tm_hour, tChunks->tm_min);

	return tString;

}

std::string itoa(int num) {

	std::string s;
	char buff[ITOA_CHAR_BUFF_MAX];
	buff[0] = '\0';

	snprintf(buff, ITOA_CHAR_BUFF_MAX, "%d", num);
	s.append(buff);

	return buff;

}

std::string GetWords(int hours, int mins) {

	std::string str;
	int nextHours;
	if (hours > 12)
		hours -= 12;
	if ((nextHours = hours + 1) > 12)
		nextHours -= 12;

	str.append("It is ");

	switch (mins) {

		case 0:
			str.append(LookUpWord(hours));
			str.append("o'clock");
			break;

		default:
			if (mins <= 30) {

				str.append(LookUpWord(mins));
				if (!(mins == 30 || mins == 15))
					mins == 1 ? str.append("minute ") : str.append("minutes ");
				str.append("past ");
				str.append(LookUpWord(hours));

			} else {

				str.append(LookUpWord(mins - ((mins - 30) * 2)));
				if (!(mins == 45))
					mins == 1 ? str.append("minute ") : str.append("minutes ");
				str.append("to ");
				str.append(LookUpWord(nextHours));

			}
			break;

	}

	return str;

}

std::string LookUpWord(int num) {

	std::string conv;

	switch (num) {

		case 1:
			conv = "one ";
			break;

		case 2:
			conv = "two ";
			break;

		case 3:
			conv = "three ";
			break;

		case 4:
			conv = "four ";
			break;

		case 5:
			conv = "five ";
			break;

		case 6:
			conv = "six ";
			break;

		case 7:
			conv = "seven ";
			break;

		case 8:
			conv = "eight ";
			break;

		case 9:
			conv = "nine ";
			break;

		case 10:
			conv = "ten ";
			break;

		case 11:
			conv = "eleven ";
			break;

		case 12:
			conv = "twelve ";
			break;

		case 13:
			conv = "thirteen ";
			break;

		case 14:
			conv = "fourteen ";
			break;

		case 15:
			conv = "quarter ";
			break;

		case 16:
			conv = "sixteen ";
			break;

		case 17:
			conv = "seventeen ";
			break;

		case 18:
			conv = "eighteen ";
			break;

		case 19:
			conv = "nineteen ";
			break;

		case 20:
			conv = "twenty ";
			break;

		case 21:
			conv = "twenty one ";
			break;

		case 22:
			conv = "twenty two ";
			break;

		case 23:
			conv = "twenty three ";
			break;

		case 24:
			conv = "twenty four ";
			break;

		case 25:
			conv = "twenty five ";
			break;

		case 26:
			conv = "twenty six ";
			break;

		case 27:
			conv = "twenty seven ";
			break;

		case 28:
			conv = "twenty eight ";
			break;

		case 29:
			conv = "twenty nine ";
			break;

		case 30:
			conv = "half ";
			break;

		default:
			conv = "derp ";
			break;

	}

	return conv;

}
