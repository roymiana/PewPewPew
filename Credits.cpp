#include "Credits.h"
#include "StateManager.h"

Credits::Credits(StateManager* l_stateManager)
	: BaseState(l_stateManager){}

Credits::~Credits(){}

void Credits::OnCreate()
{
	Tcredit.loadFromFile("credit.png");
	Tsprite.setTexture(Tcredit);
	Tsprite.setOrigin(0, 0);
	Tsprite.setPosition(0, 0);
}

void Credits::OnDestroy()
{
}

void Credits::Update(const sf::Time& l_time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		m_stateMgr->SwitchTos(StateType::MainMenu);
}

void Credits::Draw()
{
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(Tsprite);
}

void Credits::Activate(){}

void Credits::Deactivate(){}

