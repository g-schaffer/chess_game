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

    IntRect size_rook(0,0,50,55);


    if(!pawns.loadFromFile("images/pawns.jpg"))
    	return EXIT_FAILURE;


    board.setSmooth(true);
    pawns.setSmooth(true);

    Sprite sprite(board);

    Sprite rook(pawns);
    Sprite knight(pawns);

    rook.setTextureRect(size_rook);

    rook.setOrigin(-10,-10);

    bool mouse_pressed_on_pawn = false;
    Vector2f decalage_mouse_pawn;

	
    while(window.isOpen()) {


    	Event event;
    	while(window.pollEvent(event)) {

    		Vector2f mouse_pos = Vector2f(Mouse::getPosition(window));

    		switch(event.type) {


    			case Event::Closed:
    				
	    			window.close();
    

	    		case Event::MouseButtonPressed:

	    			// std::cout << "button mouse pressed\n";
	    			// std::cout << "x pos " + std::to_string(Mouse::getPosition(window).x) + "\n";

	    			// if mouse is on a pawn
	    			if(rook.getGlobalBounds().contains(mouse_pos))	{
	    				std::cout << "pawn selected \n";
	    				mouse_pressed_on_pawn = true;
	    				decalage_mouse_pawn = mouse_pos - rook.getPosition();
	    			}
	    			break;


	    		case Event::MouseButtonReleased:

	    			// if mouse is in sprite
    				std::cout << "button mouse released \n";
    				mouse_pressed_on_pawn = false;

	    			


	    		case Event::MouseMoved:
	    			if(mouse_pressed_on_pawn) {
	    				rook.setPosition(mouse_pos - decalage_mouse_pawn);
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


