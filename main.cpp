#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>


int main() {
	/*std::cout << "Hello World!";*/

    sf::RenderWindow window(sf::VideoMode(600, 600), "SFML window");


    sf::Texture texture;
    if(!texture.loadFromFile("images/board.png"))
    	return EXIT_FAILURE;

    sf::Sprite sprite(texture);


    while(window.isOpen()) {


    	sf::Event event;
    	while(window.pollEvent(event)) {
    		if(event.type == sf::Event::Closed)
    			window.close();
    	}


    	window.clear();
    	window.draw(sprite);
    	window.display();
    }

	return EXIT_SUCCESS;
}


