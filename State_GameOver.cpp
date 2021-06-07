#include "State_GameOver.h"
#include "StateManager.h"

State_GameOver::State_GameOver(StateManager* l_stateManager)
	: BaseState(l_stateManager){}

State_GameOver::~State_GameOver(){}

void State_GameOver::OnCreate(){
	m_elapsed = 0;
	m_font.loadFromFile("font.otf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(16);
	m_text.setString("TIME IS UP");
	m_text.setOrigin(m_text.getLocalBounds().width / 2, 
		m_text.getLocalBounds().height / 2);
	m_text.setPosition(400, 300);

	victory.openFromFile("Victory.wav");
	victory.play();

	winner = m_stateMgr->GetContext()->winner;

	m_stateMgr->Remove(StateType::Game);
}

void State_GameOver::OnDestroy(){}

void State_GameOver::Activate(){}
void State_GameOver::Deactivate(){}

void State_GameOver::Update(const sf::Time& l_time){
	m_elapsed += l_time.asSeconds();
	if (m_elapsed >= 3.0f ) {
		if (winner == 1) {
			m_text.setString("ABEL WINS");
		}
		if (winner == 2) {
			m_text.setString("CAIN WINS");
		}
		if (winner == 0) {
			m_text.setString("DEUCE");
		}
	}
	if (m_elapsed >= 7.0f) {
		if (winner == 1) {
			m_text.setString("God deserves only the best,\nso I will be the best.\nTo Hell with the rest.");
		}
		if (winner == 2) {
			m_text.setString("I am not my brothers keeper.\nHell can keep him now");
		}
		if (winner == 0) {
			m_text.setString("In the end,\nviolence solves nothing.");
		}
	}
	if(m_elapsed >= 15.0f){
		m_stateMgr->Remove(StateType::GameOver);
		m_stateMgr->SwitchTos(StateType::Intro);
	}
}

void State_GameOver::Draw(){
	sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
	window->draw(m_text);
}

