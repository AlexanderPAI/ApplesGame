#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Init settings

const float PAUSE_TIME = 10.f;		// Game Settings

const int SCREEN_WIDTH = 800;       // Screen
const int SCREEN_HEIGHT = 600;


const float INITIAL_SPEED = 100.f;  // Player
const float PLAYER_SIZE = 20.f;
const float ACCELERATION = 20.f;


const int NUM_APPLES = 20;          // Apples
const float APPLE_SIZE = 20.f;


const int NUM_STONES = 10;          // Stones
const float STONE_SIZE = 20.f;


struct Vector2D
{
	float x = 0.f;
	float y = 0.f;
};

enum class PlayerDirection
{
	Right = 0,
	Up,
	Left,
	Down
};

typedef Vector2D Position2D;

struct Player
{
	Position2D position;
	float speed = INITIAL_SPEED;
	PlayerDirection direction = PlayerDirection::Right;
	sf::RectangleShape shape;
};

struct Apple
{
	Position2D position;
	sf::CircleShape shape;
};

struct Stone
{
	Position2D position;
	sf::RectangleShape shape;
};

struct Game
{
	Player player;
	Apple apples[NUM_APPLES];
	Stone stones[NUM_STONES];

	// Global game data
	bool isGameOver = false;
	bool isPaused = false;
	float pauseTime = 5.f;
	float pauseTimeLeft = 0.f;
	int numEatenApples = 0;

	// UI
	sf::Font font;
	sf::Text scoreCounterLabel;
};

sf::Font initFont()
{
	sf::Font font;
	font.loadFromFile("arial.ttf");
	return font;
}

sf::Text initUI(sf::Font& font)
{
	sf::Text scoreCounterLabel;
	scoreCounterLabel.setFont(font);
	scoreCounterLabel.setCharacterSize(14);
	scoreCounterLabel.setString("Scores: 0");
	scoreCounterLabel.setFillColor(sf::Color::White);
	scoreCounterLabel.setPosition(20, 20);
	return scoreCounterLabel;
}


Position2D getRandomGameObjectPositionInScreen(std::string shape)
{
	Position2D result;

	if (shape == "apple")
	{
		
		float radius = APPLE_SIZE / 2.f;
		result.x = rand() / (float)RAND_MAX * (SCREEN_WIDTH - 2 * radius) + radius;
		result.y = rand() / (float)RAND_MAX * (SCREEN_HEIGHT - 2 * radius) + radius;
		return result;
	}
	else if (shape == "stone")
	{
		result.x = rand() / (float)RAND_MAX * (SCREEN_WIDTH - STONE_SIZE) + STONE_SIZE / 2.f;
		result.y = rand() / (float)RAND_MAX * (SCREEN_HEIGHT - STONE_SIZE) + STONE_SIZE / 2.f;
		return result;
	}
	else
	{
		return result;
	}


}


bool isCircleCollide(Position2D object1Position, Vector2D object1Size, Position2D object2Position, Vector2D object2Size)
{
	float sqrDistanse = (object1Position.x - object2Position.x) * (object1Position.x - object2Position.x) + (object1Position.y - object2Position.y) * (object1Position.y - object2Position.y);
	float sqrRadiusSum = (object1Size.x + object2Size.x) * (object1Size.y + object2Size.y) / 4;
	return (sqrDistanse <= sqrRadiusSum);
}

bool isRectangleCollide(Position2D rect1Position, Vector2D rect1Size, Position2D rect2Position, Vector2D rect2Size)
{
	float deltaPosX = fabs(rect1Position.x - rect2Position.x);
	float deltaPosY = fabs(rect1Position.y - rect2Position.y);

	return (deltaPosX <= (rect1Size.x + rect2Size.x) / 2.f && deltaPosY <= (rect1Size.y + rect1Size.y) / 2.f);
}


void initPlayer(Player& player)
{
	player.position = { SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f };
	player.speed = INITIAL_SPEED;
	player.direction = PlayerDirection::Right;

	player.shape.setSize(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
	player.shape.setFillColor(sf::Color::Red);
	player.shape.setOrigin(PLAYER_SIZE / 2.f, PLAYER_SIZE / 2.f);
	player.shape.setPosition(player.position.x, player.position.y);
}


void initApple(Apple& apple)
{
	apple.position = getRandomGameObjectPositionInScreen("apple");

	apple.shape.setRadius(APPLE_SIZE / 2.f);
	apple.shape.setFillColor(sf::Color::Green);
	apple.shape.setOrigin(APPLE_SIZE / 2.f, APPLE_SIZE / 2.f);
	apple.shape.setPosition(apple.position.x, apple.position.y);
}

void initStone(Stone& stone)
{
	stone.position = getRandomGameObjectPositionInScreen("stone");

	stone.shape.setSize(sf::Vector2f(STONE_SIZE, STONE_SIZE));
	stone.shape.setFillColor(sf::Color::White);
	stone.shape.setOrigin(STONE_SIZE / 2.f, STONE_SIZE / 2.f);
	stone.shape.setPosition(stone.position.x, stone.position.y);
}


void initGame(Game& game)
{
	// GAME INITIALIZATION
	// Init game data
	game.isGameOver = false;
	game.pauseTime = 5.f;
	game.numEatenApples = 0.f;

	// UI
	game.numEatenApples = 0;
	game.font = initFont();
	game.scoreCounterLabel = initUI(game.font);

	// Player
	initPlayer(game.player);

	// Apples
	for (int i = 0; i < NUM_APPLES; ++i)
	{
		initApple(game.apples[i]);
	}

	// Stones
	for (int i = 0; i < NUM_STONES; ++i)
	{
		initStone(game.stones[i]);
	}
}


void restartGame(Game& game)
{
	game.isPaused = true;
	game.pauseTimeLeft = game.pauseTime;

	initGame(game);
}

void updateGame(Game& game, float deltaTime)
{
	if (!game.isPaused)
	{
		// Check press keyboard key
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			game.player.direction = PlayerDirection::Right;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			game.player.direction = PlayerDirection::Up;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			game.player.direction = PlayerDirection::Left;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			game.player.direction = PlayerDirection::Down;
		}

		// Update player acceleration
		//playerSpeed += ACCELERATION * deltaTime;

		// Player moving
		switch (game.player.direction)
		{
		case PlayerDirection::Right:
		{
			game.player.position.x += game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Up:
		{
			game.player.position.y -= game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Left:
		{
			game.player.position.x -= game.player.speed * deltaTime;
			break;
		}
		case PlayerDirection::Down:
		{
			game.player.position.y += game.player.speed * deltaTime;
			break;
		}
		}

		// Logic of eating apples
		for (int i = 0; i < NUM_APPLES; ++i)
		{
			if (isCircleCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE }, game.apples[i].position, {APPLE_SIZE, APPLE_SIZE}))
			{
				initApple(game.apples[i]);

				++game.numEatenApples;
				game.scoreCounterLabel.setString("Scores: " + std::to_string(game.numEatenApples));
				game.player.speed += ACCELERATION;
			}
		}

		// Check GameEnd Conditions
		// Borders collisions
		if (game.player.position.x - PLAYER_SIZE / 2.f <= 0.f || game.player.position.x + PLAYER_SIZE / 2.f >= SCREEN_WIDTH || game.player.position.y - PLAYER_SIZE / 2.f <= 0.f || game.player.position.y + PLAYER_SIZE / 2.f >= SCREEN_HEIGHT)
		{
			game.isGameOver = true;
		}

		// Stones collisions
		for (int i = 0; i < NUM_STONES; ++i)
		{
			if (isRectangleCollide(game.player.position, { PLAYER_SIZE, PLAYER_SIZE }, game.stones[i].position, { STONE_SIZE, STONE_SIZE }))
			{
				game.isGameOver = true;
			}
		}

		// Restart
		if (game.isGameOver)
		{
			restartGame(game);
		}
	}
	else
	{
		game.pauseTimeLeft -= deltaTime;
		if (game.pauseTimeLeft <= 0.f)
		{
			game.isPaused = false;
		}
	}
}


void renderGame(Game& game, sf::RenderWindow& window)
{
	// Logic of drawing frame

	window.draw(game.scoreCounterLabel);

	game.player.shape.setPosition(game.player.position.x, game.player.position.y);
	window.draw(game.player.shape);

	for (int i = 0; i < NUM_APPLES; ++i)
	{
		window.draw(game.apples[i].shape);
	}

	for (int i = 0; i < NUM_STONES; ++i)
	{
		window.draw(game.stones[i].shape);
	}
}


void deinitializeGame(Game& game)
{

}


int main()
{
	int seed = (int)time(nullptr);
	srand(seed);

	// Init window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Apples game!");

	Game game;

	initGame(game);

	// Sync time
	sf::Clock gameClock;
	float lastTime = gameClock.getElapsedTime().asSeconds();

	// Game Loop
	while (window.isOpen())
	{
		// Get deltaTime
		float currentTime = gameClock.getElapsedTime().asSeconds();
		float deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		// READ EVENTS
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// UPDATE GAME STATE
		updateGame(game, deltaTime);

		// RENDER GAME
		window.clear();
		renderGame(game, window);
		window.display();
	}

	// DEINITIALIZATION
	deinitializeGame(game);
	return 0;
}