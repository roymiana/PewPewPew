#pragma once
#include "BaseState.h"
#include "EventManager.h"

class Credits : public BaseState
{
public:
	Credits(StateManager* l_stateManager);
	~Credits();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();
private:
	sf::Texture Tcredit;
	sf::Sprite Tsprite;
};

