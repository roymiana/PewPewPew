#pragma once
#include "BaseState.h"
#include "EventManager.h"
using namespace std;

struct Name
{
	string labels[4] = { "Abel", "Cain", "Player 1", "Player 2" };
	sf::Text txt[4], ready[3];
	sf::Font font;
};

class PreGame : public BaseState
{
public:
	PreGame(StateManager* l_stateManager);
	~PreGame();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	void animate();
	void setname(sf::Sprite& keeper, sf::Sprite& brother);
private:
	sf::Texture Caintexture, Abeltexture;
	sf::IntRect CainRect, AbelRect;
	sf::Sprite Cain, Abel;

	sf::Texture Ptexture;
	sf::Sprite Psprite;
	sf::RectangleShape Prect;
	Name name;

	sf::SoundBuffer ugh;
	sf::Sound ugh2;

	sf::Clock clock;
	float delay;
	bool ready1, ready2, start;
};



