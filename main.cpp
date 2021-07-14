#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

int main() {

    RenderWindow window(VideoMode(600, 600), "SFML window");


    Texture board, pawns;
    if(!board.loadFromFile("images/board.png"))
    	return EXIT_FAILURE;

    IntRect size(0,0,50,55);


    if(!pawns.loadFromFile("images/pawns.jpg", size))
    	return EXIT_FAILURE;


    board.setSmooth(true);
    pawns.setSmooth(true);

    Sprite sprite(board);

    Sprite rook(pawns);

    rook.setOrigin(-10,-10);

    bool mouse_pressed_on_pawn = false;
    Vector2i decalage_mouse_pawn;

	
    while(window.isOpen()) {


    	Event event;
    	while(window.pollEvent(event)) {

    		switch(event.type) {


    			case Event::Closed:
    				
	    			window.close();
    

	    		case Event::MouseButtonPressed:

	    			std::cout << "button mouse pressed\n";
	    			std::cout << "x pos " + std::to_string(Mouse::getPosition(window).x) + "\n";

	    			// if mouse is on a pawn
	    			if(rook.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)){
	    				std::cout << "pawn selected \n";
	    				mouse_pressed_on_pawn = true;
	    				decalage_mouse_pawn = Vector2i(Mouse::getPosition(window).x - rook.getPosition().x,Mouse::getPosition(window).y - rook.getPosition().y);
	    			}
	    			break;


	    		case Event::MouseButtonReleased:

	    			// if mouse is in sprite
    				std::cout << "button mouse released \n";
    				mouse_pressed_on_pawn = false;

	    			


	    		case Event::MouseMoved:
	    			if(mouse_pressed_on_pawn) {
	    				std::cout << std::to_string(Mouse::getPosition(window).x)+"\n";
	    				rook.setPosition(Mouse::getPosition(window).x - decalage_mouse_pawn.x, Mouse::getPosition(window).y - decalage_mouse_pawn.y);
	    			}
    		}

    	}


    	window.clear();
    	window.draw(sprite);
    	window.draw(rook);
    	window.display();
    }

	return EXIT_SUCCESS;
}


