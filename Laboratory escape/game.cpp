#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Laboratory escape");
	window.setFramerateLimit(30);
	window.setVerticalSyncEnabled(true);

	sf::Texture texture_ground_full, texture_ground_top, texture_player;
	if (false
		|| !texture_ground_full.loadFromFile("ground_stone.png")
		|| !texture_ground_top .loadFromFile("ground_stone_top.png")
		|| !texture_player     .loadFromFile("player.png")
	) return EXIT_FAILURE;

	sf::Sprite	ground_full(texture_ground_full),
				ground_top(texture_ground_top),
				player(texture_player);

	ground_full.setScale(4, 4);
	ground_top.setScale(4, 4);
	player.setScale(4, 4);

	player.setOrigin(8, 0);

	sf::Font font;
	if (!font.loadFromFile("8bit_wonder.ttf"))
		return EXIT_FAILURE;
	sf::Text text("xx FPS", font, 30);

	sf::Clock clock;
	float last_time = 0, total_time = 0;

	float	player_x = 100,
			player_y = 480 - 16 * 4 * 5,
			player_vx = 0,
			player_vy = 0,
			gravity = 9.8f;

	while (window.isOpen())
	{
		float current_time = clock.restart().asSeconds();
		float fps = 1.f / (current_time);
		total_time += current_time;
		last_time = current_time;

		if (total_time >= 1)
		{
			text.setString(std::to_string(static_cast<int>(fps)) + " fps");
			total_time -= static_cast<int>(total_time);
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (int x = 0; x < 640; x += 16 * 4)
		{
			ground_top.setPosition(x, 480 - 16 * 4 * 3);
			window.draw(ground_top);

			for (int y = 0; y < 3; ++y)
			{
				ground_full.setPosition(x, 480 - 16 * 4 * y);
				window.draw(ground_full);
			}
		}

		player_vx = 100 * 2.5f * (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			player.setScale(4, 4);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			player.setScale(-4, 4);

		if (player_y >= 480 - 16 * 4 * 4)
		{
			player_y = 480 - 16 * 4 * 4;
			player_vy -= std::abs(player_vy);
			player_vy /= 2;

			player_vy += 100 * -5 * sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		}
		else
		{
			player_vy += gravity * current_time * 100;
		}

		player_x += player_vx * current_time;
		player_y += player_vy * current_time;

		player.setPosition(player_x, player_y);

		window.draw(player);

		window.draw(text);
		window.display();
	}

	return EXIT_SUCCESS;
}
