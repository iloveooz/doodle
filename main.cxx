
	#include <SFML/Graphics.hpp>
	#include <time.h>
	
	struct point {
		int x;
		int y;
	};
	
	int main() {
		
		srand(time(NULL));
		
		sf::RenderWindow app(sf::VideoMode(400, 533), "DOODLE IT!");
		app.setFramerateLimit(60);
		
		// текстуры
		sf::Texture t1, t2, t3;
		
		t1.loadFromFile("images/background.png");
		t2.loadFromFile("images/platform.png");
		t3.loadFromFile("images/doodle.png");
		
		// спрайты
		sf::Sprite sBackground(t1), sPlat(t2), sPers(t3);
		
		// массив точек
		point plat[20];
		
		for (int i = 0; i < 10; i++) {
			plat[i].x = rand() % 400;
			plat[i].y = rand() % 533;
		}
		
		while (app.isOpen()) {
			sf::Event e;
			
			while (app.pollEvent(e)) {
				if (e.type == sf::Event::Closed)
					app.close();
			}
			
			app.draw(sBackground);
			app.draw(sPers);
			
			for (int i = 0; i < 10; i++) {
				sPlat.setPosition(plat[i].x, plat[i].y);
				app.draw(sPlat);
			}
			
			app.display();
			
		}
		
		return 0;
	}
