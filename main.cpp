#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;


Texture texture_board, texture_pawns;

Sprite pawns[32];

int b[8][8] = 
	{
		1,2,3,4,5,3,2,1,
		6,6,6,6,6,6,6,6,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,
		-6,-6,-6,-6,-6,-6,-6,-6,
		-1,-2,-3,-4,-5,-3,-2,-1,
	};

void set_origin_pos() {


	int h = 0;
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			int n = b[i][j];
			if(n == 0) continue;
			pawns[h].setTexture(texture_pawns);
			pawns[h].setPosition(j*75,i*75 );
			pawns[h].setTextureRect(IntRect(56*(abs(n)-1),60*(abs(n)/n+1)/2,56,56));
			h++;
		}
	}

}




int main() {

    RenderWindow window(VideoMode(600, 600), "SFML window");


    if(!texture_board.loadFromFile("images/board.png"))
    	return EXIT_FAILURE;

    IntRect size_rook(0,0,56,60); // x, y , x, y


    if(!texture_pawns.loadFromFile("images/pawns.png"))
    	return EXIT_FAILURE;


    Sprite board(texture_board);

    Sprite rook(texture_pawns);


    rook.setTextureRect(size_rook);

    rook.setPosition(0,0);

    bool mouse_pressed_on_pawn = false;
    Vector2f decalage_mouse_pawn;

    int n ;

    set_origin_pos();
	
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
	    			for(int i = 0; i<32; i++)
	    			if(pawns[i].getGlobalBounds().contains(mouse_pos))	{
	    				std::cout << "pawn selected \n";
	    				mouse_pressed_on_pawn = true; n = i;
	    				decalage_mouse_pawn = mouse_pos - pawns[i].getPosition();
	    			}
	    			break;


	    		case Event::MouseButtonReleased:

	    			// if mouse is in sprite
    				std::cout << "button mouse released \n";

    				if(mouse_pressed_on_pawn){
	    				Vector2f new_pos = Vector2f(75 * int(mouse_pos.x/75), 75 * int(mouse_pos.y/75));
	    				pawns[n].setPosition(new_pos);
    				}
    				
    				mouse_pressed_on_pawn = false;
    				break;
	    			


	    		case Event::MouseMoved:
	    			if(mouse_pressed_on_pawn) {
	    				pawns[n].setPosition(mouse_pos - decalage_mouse_pawn);
	    			}
    		}

    	}


    	window.clear();
    	window.draw(board);
    	window.draw(rook);
    	for(int i=0;i<32;i++)
    		window.draw(pawns[i]);
    	window.display();
    }

	return EXIT_SUCCESS;
}


