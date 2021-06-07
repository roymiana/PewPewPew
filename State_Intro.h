#pragma once
#include "BaseState.h"
#include "EventManager.h"

class State_Intro : public BaseState{
public:
	State_Intro(StateManager* l_stateManager);
	~State_Intro();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	void Continue(EventDetails* l_details);
private:
	sf::Texture m_introTexture;
	sf::Sprite m_introSprite;
	sf::Texture m_background;
	sf::Sprite m_backSprite;
	sf::Font m_font;
	sf::Text m_text;

	sf::Music theme;

	float m_timePassed;
};