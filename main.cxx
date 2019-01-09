
	#include <SFML/Graphics.hpp>
	#include <time.h>
	#include <iostream>
	
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
		
		// заполняем массив
		for (int i = 0; i < 10; i++) {
			plat[i].x = rand() % 400;
			plat[i].y = rand() % 533;
		}
		
		int x = 100;
		int y = 100;
		int h = 200;
		
		float dx = 0.0;
		float dy = 0.0;
		
		while (app.isOpen()) {
			sf::Event e;
			
			while (app.pollEvent(e)) {
				if (e.type == sf::Event::Closed)
					app.close();
			}
			
			// управление
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += 3;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= 3;
			
			// падение (интересно реализовано)
			dy += 0.2; 
			y += dy;
			
			if (y > 500) dy = -10;
			
			// диагностические сообщения
			std::cout << "x = " << x << ", y = " << y << ", dy = " << dy << std::endl;
			
			// чтобы дудл отскакивал от площадки
			for (int i = 0; i < 10; i++) 
				if ((x + 50 > plat[i].x) &&
					(x + 20 < plat[i].x + 68) &&
					(y + 70 > plat[i].y) &&
					(y + 70 < plat[i].y + 14) &&
					(dy > 0))
					dy = -10;
			
			sPers.setPosition(x, y);
			
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
