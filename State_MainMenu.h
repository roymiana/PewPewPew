#pragma once
#include "BaseState.h"
#include "EventManager.h"

class State_MainMenu : public BaseState{
public:
	State_MainMenu(StateManager* l_stateManager);
	~State_MainMenu();

	void OnCreate();
	void OnDestroy();

	void Activate();
	void Deactivate();

	void Update(const sf::Time& l_time);
	void Draw();

	void MouseClick(EventDetails* l_details);
private:
	sf::Font m_font;
	sf::Text m_text;

	sf::Texture m_background;
	sf::Sprite m_backSprite;
	sf::Texture m_tutexture;
	sf::Sprite m_tutoSprite;

	sf::Vector2f m_buttonSize;
	sf::Vector2f m_buttonPos;
	unsigned int m_buttonPadding;

	sf::RectangleShape m_rects[3];
	sf::Text m_labels[3];

	sf::Music theme1;
};