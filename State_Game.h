#pragma once
#include "BaseState.h"
#include "EventManager.h"
#include "TileMap.h"
#include "Collision.h"
#include <SFML/Audio.hpp>

struct Player
{
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::IntRect m_rectSourceSprite;
	float height = 0.0;
	bool jumping = true;
	bool faceRight = true;
	sf::Clock clock;

	//stats
	int kills = 0;
	float health = 100.0f;
	bool status = true;

	void animate(int direction, int vertical, bool idle);
	void gravity();
	bool collide(int x, int y);
};

struct Bullet
{
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	sf::IntRect bulletRect;
	int ammo = 1;
	bool direction = true;

	bool collide(int x, int y);
};

struct weapon
{
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::IntRect Rect;

	void attach(float x, float y, bool direction);
};

struct hud
{
	//total time
	sf::Font ttFont;
	sf::Text ttText;
	std::stringstream tt;

	//hud
	sf::Texture hud_texture;
	sf::Sprite hud_sprite;

	//healthbar first
	sf::Texture bar_texture;
	sf::Sprite bar_sprite;

	//healthbar second
	sf::Texture bars_texture;
	sf::Sprite bars_sprite;

	//kills first player
	sf::Font kfont;
	sf::Text ktext;
	std::stringstream kk;

	//kills second
	sf::Font ksfont;
	sf::Text kstext;
	std::stringstream ks;

	
};

struct explode {
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect rect;

	sf::Clock clock;

	bool animate(float x, float y);
};

class State_Game : public BaseState {
public:
	State_Game(StateManager* l_stateManager);
	~State_Game();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	void MainMenu(EventDetails* l_details);
	void Pause(EventDetails* l_details);

	void move();
	void moveSecond();

	void trigger();
	void shoot();

	void battle();
	void updateKills();
	void healthbar();
	int winner();
private:
	Player first;
	Player second;
	weapon rocket;
	weapon rocketSecond;
	Bullet missile;
	TileMap map;
	hud HUD;
	explode boom;

	//music
	sf::SoundBuffer rocketshoot;
	sf::Sound rockettrigger;
	sf::SoundBuffer kaboom;
	sf::Sound explo;
	sf::Music battletheme;

	sf::Texture background;
	sf::Sprite backSprite;

	sf::Clock shotclock;
	bool turn;
	float deltaTime;
	sf::Font m_font;
	sf::Text m_text;
	std::stringstream ss;

	bool turnPause;

	sf::Clock GameClock;
	float Gclock;

	bool fired;
	sf::Text p_text;

	bool explode;

	sf::RectangleShape m_rect;
};