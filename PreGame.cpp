#include "PreGame.h"
#include "StateManager.h"


PreGame::PreGame(StateManager* l_stateManager)
	: BaseState(l_stateManager){}

PreGame::~PreGame(){}

void PreGame::OnCreate()
{
	//background
	Ptexture.loadFromFile("introback.png");
	Psprite.setTexture(Ptexture);
	Psprite.setOrigin(0, 0);
	Psprite.setPosition(0, 0);

	Prect.setSize(sf::Vector2f(800,600));
	Prect.setPosition(0, 0);
	Prect.setFillColor(sf::Color(0, 0, 0, 150));

	//abel
	Abeltexture.loadFromFile("blue68.png");
	
	sf::IntRect rectSource(0, 0, 38, 68);
	sf::Sprite sprite(Abeltexture, rectSource);

	AbelRect = rectSource;
	Abel = sprite;
	Abel.setOrigin(19, 34);
	Abel.setPosition(200, 300);

	//Cain
	Caintexture.loadFromFile("pink68.png");

	sf::IntRect rectSources(0, 0, 38, 68);
	sf::Sprite sprites(Caintexture, rectSource);

	CainRect = rectSources;
	Cain = sprites;
	Cain.setOrigin(19, 34);
	Cain.setPosition(600, 300);


	//sound
	ugh.loadFromFile("ugh.wav");
	ugh2.setBuffer(ugh);

	//name
	//Name temp(Abel, Cain);
	//name = temp;
	setname(Abel, Cain);

	ready1 = false;
	ready2 = false;
	start = false;

	delay = 0.0f;
}

void PreGame::OnDestroy()
{
}

void PreGame::Update(const sf::Time& l_time)
{
	//escape
	if (start) 
	{
			delay += 0.1f;
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			if (ready1 == false || ready2 == false) {
				if (ready1 == true) {
					ready1 = false;
					Abeltexture.loadFromFile("blue68.png");
					name.ready[0].setString("Press Enter");
				}
				if (ready2 == true) {
					ready2 = false;
					Caintexture.loadFromFile("pink68.png");
					name.ready[1].setString("Press Space");
				}
			}
		}

		//ready player one
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			name.ready[0].setString("READY");
			AbelRect.left = 0;
			Abeltexture.loadFromFile("blueflex68.png");
			if (ready1 && ready2) {
				name.ready[2].setString("GAME COMMENCING...");
				name.ready[2].setPosition(400 - 166, name.ready[2].getPosition().y);
				start = true;
			}
			else
				ugh2.play();
			ready1 = true;
		}

		//ready player two
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			ugh2.play();
			name.ready[1].setString("READY");
			CainRect.left = 0;
			Caintexture.loadFromFile("pinkflex68.png");
			ready2 = true;
		}
	}
	animate();
}

void PreGame::Draw()
{
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(Psprite);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(Prect);
	if (delay <= 100.0f) {
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(name.ready[2]);
	}
	else {
		m_stateMgr->SwitchTos(StateType::Game);
		m_stateMgr->Remove(StateType::MainMenu);
		m_stateMgr->Remove(StateType::PreGame);
	}
	for (int i = 0; i < 4; i++)
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(name.txt[i]);
	for (int i = 0; i < 2; i++)
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(name.ready[i]);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(Abel);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(Cain);
}

void PreGame::animate()
{
	if (clock.getElapsedTime().asSeconds() > 0.1f) {
		//player 1
		if (AbelRect.left >= 456 - 38 || ready1)
			AbelRect.left = 0;
		else
			AbelRect.left += 38;

		//player 2
		if (CainRect.left >= 456 - 38 || ready2)
			CainRect.left = 0;
		else
			CainRect.left += 38;

		if (!ready1)
			Abel.setTextureRect(AbelRect);
		else if (ready1 && AbelRect.left == 0)
			Abel.setTextureRect(AbelRect);

		if (!ready2)
			Cain.setTextureRect(CainRect);
		else if (ready2 && CainRect.left == 0)
			Cain.setTextureRect(CainRect);

		clock.restart();
	}
}

void PreGame::setname(sf::Sprite& keeper, sf::Sprite& brother)
{
	int ctr = 0, dis1 = 100, dis2 = 100;
	if (!name.font.loadFromFile("font.otf")) {

	}
	for (ctr = 0; ctr < 4; ctr++) {
		if (ctr % 2 == 0) {
			name.txt[ctr].setFont(name.font);
			name.txt[ctr].setFillColor(sf::Color::White);
			name.txt[ctr].setString(name.labels[ctr]);
			name.txt[ctr].setPosition(keeper.getPosition().x - 150, keeper.getPosition().y - dis1);
			dis1 += 50;
		}
		else {
			name.txt[ctr].setFont(name.font);
			name.txt[ctr].setFillColor(sf::Color::White);
			name.txt[ctr].setString(name.labels[ctr]);
			name.txt[ctr].setPosition(brother.getPosition().x - 150, brother.getPosition().y - dis2);
			dis2 += 50;
		}
		//window.draw(txt[ctr]);
	}
	name.ready[0].setFont(name.font);
	name.ready[1].setFont(name.font);
	name.ready[2].setFont(name.font);
	name.ready[2].setString("PRESS ENTER TO START");
	name.ready[2].setPosition(keeper.getPosition().x - 150, keeper.getPosition().y + dis1);
	name.ready[2].setFillColor(sf::Color::White);
	name.ready[0].setString("Press Enter");
	name.ready[1].setString("Press Space");
	name.ready[0].setPosition(keeper.getPosition().x - 150, keeper.getPosition().y + dis1 / 2);
	name.ready[0].setFillColor(sf::Color::White);
	//window.draw(name.ready[0]);
	name.ready[1].setPosition(brother.getPosition().x - 150, brother.getPosition().y + dis2 / 2);
	name.ready[1].setFillColor(sf::Color::White);
	//window.draw(name.ready[1]);
}

void PreGame::Activate() {}

void PreGame::Deactivate() {}