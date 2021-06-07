#include "State_Game.h"
#include "StateManager.h"

const int level[] =
{
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	2, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	10, 6, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 5, 11, 11, 11, 11, 11, 11, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	8, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 4, 0,
	10, 11, 11, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 11, 11, 11, 11, 11, 11, 6, 0,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	12, 0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	8, 1, 1, 1, 4, 0, 5, 11, 11, 11, 11, 11, 11, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	10, 11, 11, 11, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 0, 0, 0, 0, 3, 1, 1, 1,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 0, 0, 0, 3, 7, 2, 2, 2,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, 2, 2, 2, 2,
	12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 7, 2, 2, 2, 2, 2,
	8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 7, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

State_Game::State_Game(StateManager* l_stateManager)
	: BaseState(l_stateManager) {}

State_Game::~State_Game() {}

void State_Game::OnCreate() {
	//1st player
	first.m_texture.loadFromFile("sprite8x4.png");

	sf::IntRect rect(0, 0, 21, 34);
	sf::Sprite temp(first.m_texture, rect);

	first.m_rectSourceSprite = rect;
	first.m_sprite = temp;
	
	first.m_sprite.setPosition(50, 0);
	first.m_sprite.setOrigin(0.0, 0.0);


	//2nd player

	second.m_texture.loadFromFile("pink8x4.png");

	sf::IntRect rects(0, 0, 21, 34);
	sf::Sprite temps(second.m_texture, rect);

	second.m_rectSourceSprite = rects;
	second.m_sprite = temps;

	second.m_sprite.setPosition(700, 150);
	second.m_sprite.setOrigin(0.0, 0.0);

	second.faceRight = false;
	
	//explosion
	boom.texture.loadFromFile("boom.png");
	sf::IntRect bam(0, 0, 100, 95);
	sf::Sprite bams(boom.texture, rect);

	boom.rect = bam;
	boom.sprite = bams;
	boom.sprite.setOrigin(42, 32);

	explode = false;
	
	//rocket
	rocket.Texture.loadFromFile("rocket.png");

	sf::IntRect rectrocket(0, 0, 36, 14);
	sf::Sprite spriterock(rocket.Texture, rectrocket);

	rocket.Rect = rectrocket;
	rocket.Sprite = spriterock;
	rocket.Sprite.setOrigin(0, 0);

	//rocket
	rocketSecond.Texture.loadFromFile("rocket.png");

	rocketSecond.Rect = rectrocket;
	rocketSecond.Sprite = spriterock;
	rocketSecond.Sprite.setOrigin(0, 0);

	//bullet
	fired = false;
	missile.bulletTexture.loadFromFile("missile.png");

	sf::IntRect rectb(0, 0, 15, 7);
	sf::Sprite tempb(missile.bulletTexture, rectb);

	missile.bulletRect = rectb;
	missile.bulletSprite = tempb;
	//missile.bulletSprite.setTexture(missile.bulletTexture);
	missile.bulletSprite.setOrigin(0, 0);

	//map tileset
	map.load("Tileset.png", sf::Vector2u(32, 32), level, 25, 19);
	
	//turn
	turn = true;
	deltaTime = 0.0;

	//shotclock
	
	m_font.loadFromFile("font.otf");
	m_text.setFont(m_font);
	ss.str(std::string()); //clear the string
	ss << deltaTime;
	m_text.setString(ss.str().c_str());
	m_text.setCharacterSize(15);
	m_text.setOrigin(0.0,0.0);
	m_text.setPosition(384.0, 24.0);



	//pauseturn
	turnPause = false;
	p_text.setFont(m_font);
	p_text.setCharacterSize(30);
	sf::FloatRect textRects = p_text.getLocalBounds();
	p_text.setOrigin(textRects.left + textRects.width / 2.0f,
		textRects.top + textRects.height / 2.0f);
	p_text.setPosition(400, 300);

	m_rect.setSize(sf::Vector2f(800, 600));
	m_rect.setPosition(0, 0);
	m_rect.setFillColor(sf::Color(0, 0, 0, 150));

	//map
	background.loadFromFile("map_background.png");
	backSprite.setTexture(background);
	backSprite.setOrigin(background.getSize().x / 2.0f, background.getSize().y / 2.0f);

	backSprite.setPosition(400, 300);

	//music
	rocketshoot.loadFromFile("rocket.flac");
	rockettrigger.setBuffer(rocketshoot);
	kaboom.loadFromFile("explode.wav");
	explo.setBuffer(kaboom);
	battletheme.openFromFile("battle.ogg");
	battletheme.setVolume(50.0f);
	battletheme.setLoop(true);
	battletheme.play();
	

	//HUD
	{
		//hudback
		HUD.hud_texture.loadFromFile("hud.png");
		HUD.hud_sprite.setTexture(HUD.hud_texture);
		HUD.hud_sprite.setOrigin(0.0, 0.0);
		HUD.hud_sprite.setPosition(0.0, 0.0);

		//healthbar
		HUD.bar_texture.loadFromFile("healthbar.png");
		HUD.bar_sprite.setTexture(HUD.bar_texture);
		HUD.bar_sprite.setOrigin(0.0, 0.0);
		HUD.bar_sprite.setPosition(200, 20);
		//HUD.bar_sprite.scale(0.5, 1);

		//second healthbar
		HUD.bars_texture.loadFromFile("healthbar.png");
		HUD.bars_sprite.setTexture(HUD.bars_texture);
		HUD.bars_sprite.setOrigin(0.0, 0.0);
		HUD.bars_sprite.setPosition(454, 20);

		//firstkill
		HUD.kfont.loadFromFile("font.otf");
		HUD.ktext.setFont(HUD.kfont);
		HUD.kk.str(std::string()); //clear the string
		HUD.kk << first.kills;
		HUD.ktext.setString(HUD.kk.str().c_str());
		HUD.ktext.setCharacterSize(15);
		HUD.ktext.setOrigin(0.0, 0.0);
		HUD.ktext.setPosition(128.0, 24.0);

		//second
		HUD.ksfont.loadFromFile("font.otf");
		HUD.kstext.setFont(HUD.ksfont);
		HUD.ks.str(std::string()); //clear the string
		HUD.ks << second.kills;
		HUD.kstext.setString(HUD.ks.str().c_str());
		HUD.kstext.setCharacterSize(15);
		HUD.kstext.setOrigin(0.0, 0.0);
		HUD.kstext.setPosition(657.0, 24.0);

		//gameclock
		HUD.ttFont.loadFromFile("font.otf");
		HUD.ttText.setFont(m_font);
		HUD.tt.str(std::string()); //clear the string
		HUD.tt << deltaTime;
		HUD.ttText.setString(HUD.tt.str().c_str());
		HUD.ttText.setCharacterSize(15);
		HUD.ttText.setOrigin(0.0, 0.0);
		HUD.ttText.setPosition(381.0, 558.0);
	}

	EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
	evMgr->AddCallback(StateType::Game, "Key_Escape", &State_Game::MainMenu, this);
	evMgr->AddCallback(StateType::Game, "Key_P", &State_Game::Pause, this);
}

void State_Game::OnDestroy() {
	EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
	evMgr->RemoveCallback(StateType::Game, "Key_Escape");
	evMgr->RemoveCallback(StateType::Game, "Key_P");
}

void State_Game::Update(const sf::Time& l_time) {
	sf::Vector2u l_windSize = m_stateMgr->GetContext()->m_wind->GetWindowSize();

	Gclock = GameClock.getElapsedTime().asSeconds();
	HUD.tt.str(std::string()); //clear the string
	HUD.tt << 200 - int(Gclock);
	HUD.ttText.setString(HUD.tt.str().c_str());
	
	if (Gclock <= 200.0f) {
		battle();
		healthbar();
		updateKills();
		
		rocket.attach(first.m_sprite.getPosition().x, first.m_sprite.getPosition().y, first.faceRight);
		rocketSecond.attach(second.m_sprite.getPosition().x, second.m_sprite.getPosition().y, second.faceRight);

		if (explode) {
			explode = boom.animate(missile.bulletSprite.getPosition().x, missile.bulletSprite.getPosition().y);
			if(explode==false)
				explo.play();
		}

	}
	else {
		m_stateMgr->GetContext()->winner = winner();
		m_stateMgr->SwitchTos(StateType::GameOver);
	}

	
}

void State_Game::Draw() {
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(backSprite);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(map);
	if (first.status) {
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(first.m_sprite);
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(rocket.Sprite);
	}
	if (second.status) {
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(second.m_sprite);
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(rocketSecond.Sprite);
	}
	if (fired) {
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(missile.bulletSprite);
	}
	if(explode)
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(boom.sprite);

	//hud
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(HUD.hud_sprite);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(m_text);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(HUD.ktext);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(HUD.kstext);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(HUD.bar_sprite);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(HUD.bars_sprite);
	m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(HUD.ttText);

	if (turnPause) {
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(m_rect);
		m_stateMgr->GetContext()->m_wind->GetRenderWindow()->draw(p_text);
	}
	

}

void State_Game::MainMenu(EventDetails* l_details) {
	m_stateMgr->SwitchTos(StateType::MainMenu);
}

void State_Game::Pause(EventDetails* l_details) {
	m_stateMgr->SwitchTos(StateType::Paused);
}

bool Player::collide(int x, int y)
{
	int tile = level[x + y * 25];
	if (tile > 0) {
		return true;
	}
	else
		return false;
}

void State_Game::move()
{
	float xPos, yPos;
	int i;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			for (i = 1; i <= 30; i++) {
				xPos = first.m_sprite.getPosition().x - 1.0;
				yPos = first.m_sprite.getPosition().y + i;
				if (first.collide(int(xPos / 32), int(yPos / 32)))
					break;
			}
			if (i >= 30) {
				first.animate(1, 0, false);
				first.m_sprite.move(-0.5f, 0.0f);
	
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			for (i = 1; i <= 30; i++) {
				xPos = first.m_sprite.getPosition().x + 22.0;
				yPos = first.m_sprite.getPosition().y + i;
				if (first.collide(int(xPos / 32), int(yPos / 32)))
					break;
			}
			if (i >= 30) {
				first.animate(2, 0, false);
				first.m_sprite.move(+0.5f, 0.0f);	
			}


		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (first.height <= 50.0)) {
			for (i = 1; i <= 21; i++) {
				xPos = first.m_sprite.getPosition().x + i;
				yPos = first.m_sprite.getPosition().y - 1.0;
				if (first.collide(int(xPos / 32), int(yPos / 32)))
					break;
			}
			if (i >= 21) {
				//m_sprite.move(0.0f, -3.0f);
				first.animate(0, 1, false);
				first.m_sprite.setPosition(first.m_sprite.getPosition().x, first.m_sprite.getPosition().y - 3.0);
				
				first.height += 1.0;
			}
			else
				first.height = 50.0;
		}
		
	}
	else {
		first.animate(0 ,0, true);
		
	}
	first.jumping = true;
}

void State_Game::moveSecond()
{
	float xPos, yPos;
	int i;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			for (i = 1; i <= 30; i++) {
				xPos = second.m_sprite.getPosition().x - 1.0;
				yPos = second.m_sprite.getPosition().y + i;
				if (second.collide(int(xPos / 32), int(yPos / 32)))
					break;
			}
			if (i >= 30) {
				second.animate(1, 0, false);
				second.m_sprite.move(-0.5f, 0.0f);

			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			for (i = 1; i <= 30; i++) {
				xPos = second.m_sprite.getPosition().x + 22.0;
				yPos = second.m_sprite.getPosition().y + i;
				if (second.collide(int(xPos / 32), int(yPos / 32)))
					break;
			}
			if (i >= 30) {
				second.animate(2, 0, false);
				second.m_sprite.move(+0.5f, 0.0f);

			}

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && (second.height <= 50.0)) {
			for (i = 1; i <= 21; i++) {
				xPos = second.m_sprite.getPosition().x + i;
				yPos = second.m_sprite.getPosition().y - 1.0;
				if (second.collide(int(xPos / 32), int(yPos / 32)))
					break;
			}
			if (i >= 21) {
				//m_sprite.move(0.0f, -3.0f);
				second.animate(0, 1, false);
				second.m_sprite.setPosition(second.m_sprite.getPosition().x, second.m_sprite.getPosition().y - 3.0);

				second.height += 1.0;
			}
			else
				second.height = 50.0;
		}

	}
	else {
		second.animate(0, 0, true);

	}
	second.jumping = true;
}

void State_Game::trigger()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (turn) {
			
			missile.direction = first.faceRight;
			if(missile.direction)
				missile.bulletSprite.setPosition(first.m_sprite.getPosition().x+15.0f, first.m_sprite.getPosition().y + 9.0f);
			else
				missile.bulletSprite.setPosition(first.m_sprite.getPosition().x - 10.0f, first.m_sprite.getPosition().y + 9.0f);
			//change position if faceright
		}
		else {
			
			missile.direction = second.faceRight;
			if (missile.direction)
				missile.bulletSprite.setPosition(second.m_sprite.getPosition().x + 15.0f, second.m_sprite.getPosition().y + 9.0f);
			else
				missile.bulletSprite.setPosition(second.m_sprite.getPosition().x - 10.0f, second.m_sprite.getPosition().y + 9.0f);
		}
		deltaTime = 25.0;
		missile.ammo = 0;
		fired = true;
		rockettrigger.play();
	}
}

void State_Game::shoot()
{
	
	float xPos, yPos;
	int i;
	if (missile.direction) {
		missile.bulletRect.top = 0;
		missile.bulletSprite.setTextureRect(missile.bulletRect);
		for (i = 1; i <= 7; i++) {
			xPos = missile.bulletSprite.getPosition().x + 15;
			yPos = missile.bulletSprite.getPosition().y + i;
			if (missile.collide(int(xPos / 32), int(yPos / 32)))
				break;
		}
		if (i >= 7) {
			if (turn) {
				if (Collision::PixelPerfectTest(second.m_sprite, missile.bulletSprite)) {
					explode = true;
					fired = false;
					second.health -= 25.0;
				}
				else
					missile.bulletSprite.move(1.0, 0);
			}
			else {
				if (Collision::PixelPerfectTest(first.m_sprite, missile.bulletSprite)) {
					explode = true;
					fired = false;
					first.health -= 25.0;
				}
				else
					missile.bulletSprite.move(1.0, 0);
			}
			
		}
		else {
			explode = true;
			fired = false;
		}
	}
	else {
		missile.bulletRect.top = 7;
		missile.bulletSprite.setTextureRect(missile.bulletRect);
		for (i = 1; i <= 7; i++) {
			xPos = missile.bulletSprite.getPosition().x;
			yPos = missile.bulletSprite.getPosition().y + i;
			if (missile.collide(int(xPos / 32), int(yPos / 32)))
				break;
		}
		if (i >= 7) {
			if (turn) {
				if (Collision::PixelPerfectTest(second.m_sprite, missile.bulletSprite)) {
					explode = true;
					fired = false;
					second.health -= 25.0;
				}
				else
					missile.bulletSprite.move(-1.0, 0);
			}
			else {
				if (Collision::PixelPerfectTest(first.m_sprite, missile.bulletSprite)) {
					explode = true;
					fired = false;
					first.health -= 25.0;
				}
				else
					missile.bulletSprite.move(-1.0, 0);
			}

		}
		else {
			explode = true;
			fired = false;
		}

	}
}

void weapon::attach(float x, float y, bool direction)
{
	if (direction) {
		Rect.top = 0;
		Sprite.setTextureRect(Rect);
		Sprite.setPosition(x - 6.0f, y+7.0f);
	}
	else {
		Rect.top = 14;
		Sprite.setTextureRect(Rect);
		Sprite.setPosition(x- 10.0f, y+7.0f);
	}
}

void Player::gravity()
{
	float xPos, yPos;
	int i;

	for (i = 1; i <= 21; i++) {
		xPos = m_sprite.getPosition().x + i;
		yPos = m_sprite.getPosition().y + 31.0;
		if (collide(int(xPos / 32), int(yPos / 32)))
			break;
	}
	if (i >= 21)
		m_sprite.move(0.0f, 0.5f);
	else {
		jumping = false;
		height = 0.0;

	}
}


void Player::animate(int direction, int vertical, bool idle)
{
	if (idle == false) {
		if (direction == 1) {
			m_rectSourceSprite.top = 102;
			if (clock.getElapsedTime().asSeconds() > 0.1f) {
				if (m_rectSourceSprite.left >= 147)
					m_rectSourceSprite.left = 0;
				else
					m_rectSourceSprite.left += 21;

				faceRight = false;
				m_sprite.setTextureRect(m_rectSourceSprite);
				clock.restart();
			}
		}
		if (vertical == 1) {
			if (faceRight) {
				m_rectSourceSprite.top = 0;
				m_rectSourceSprite.left = 0;
				m_sprite.setTextureRect(m_rectSourceSprite);
			}
			else {
				m_rectSourceSprite.top = 34;
				m_rectSourceSprite.left = 0;
				m_sprite.setTextureRect(m_rectSourceSprite);
			}
			
		}
		if (vertical == 2) {
			if (faceRight) {
				m_rectSourceSprite.top = 0;
				m_rectSourceSprite.left = 0;
				m_sprite.setTextureRect(m_rectSourceSprite);
			}
			else {
				m_rectSourceSprite.top = 34;
				m_rectSourceSprite.left = 0;
				m_sprite.setTextureRect(m_rectSourceSprite);
			}
		}
		if (direction == 2) {
			m_rectSourceSprite.top = 68;
			if (clock.getElapsedTime().asSeconds() > 0.1f) {
				if (m_rectSourceSprite.left >= 147)
					m_rectSourceSprite.left = 0;
				else
					m_rectSourceSprite.left += 21;

				faceRight = true;
				m_sprite.setTextureRect(m_rectSourceSprite);
				clock.restart();
			}

		}
	}
	else {
		if (faceRight) {
			m_rectSourceSprite.top = 0;
			if (clock.getElapsedTime().asSeconds() > 0.1f) {
				if (m_rectSourceSprite.left == 147)
					m_rectSourceSprite.left = 0;
				else
					m_rectSourceSprite.left += 21;

				m_sprite.setTextureRect(m_rectSourceSprite);
				clock.restart();
			}
		}
		else {
			m_rectSourceSprite.top = 34;
			if (clock.getElapsedTime().asSeconds() > 0.1f) {
				if (m_rectSourceSprite.left == 147)
					m_rectSourceSprite.left = 0;
				else
					m_rectSourceSprite.left += 21;

				m_sprite.setTextureRect(m_rectSourceSprite);
				clock.restart();
			}
		}
	}
}


void State_Game::Activate() {}
void State_Game::Deactivate() {}

bool Bullet::collide(int x, int y)
{
	int tile = level[x + y * 25];
	if (tile > 0) {
		return true;
	}
	else
		return false;
}

void State_Game::battle()
{
	//deltaTime = shotclock.getElapsedTime().asSeconds();

	if (shotclock.getElapsedTime().asSeconds() >= 1.0) {
		shotclock.restart();
		deltaTime += 1.0f;
	}

	//change turns
	if (turnPause) {
		if (turn)
			p_text.setString(sf::String("ABEL's turn"));
		else
			p_text.setString(sf::String("CAIN's turn"));

		if (deltaTime >= 3.00) {
			turnPause = false;
			//shotclock.restart();
			deltaTime = 0.0f;
		}

		//respawns after turn change
		if (first.status == false) {
			first.status = true;
			first.health = 100.0;
		}

		if (second.status == false) {
			second.status = true;
			second.health = 100.0;
		}


	}
	else {
		//after turn change
		ss.str(std::string()); //clear the string
		ss << 30 - int(deltaTime);
		m_text.setString(ss.str().c_str());

		//turn timer
		if (deltaTime >= 30.0) {
			if (turn)
				turn = false;
			else
				turn = true;

			turnPause = true;
			//shotclock.restart();
			deltaTime = 0.0f;
			missile.ammo = 1;
		}

		//player 1
		if (turn) {
			if (first.m_sprite.getPosition().x + 21.0f < 800.0f) {
				move();
				if (fired == false && missile.ammo == 1) {
					trigger();
				}
				else if (fired)
					shoot();
			}
		}
		if (first.jumping)
			first.gravity();

		//player 2
		if (turn == false) {
			if (second.m_sprite.getPosition().x + 21.0f < 800.0f) {
				moveSecond();
				if (fired == false && missile.ammo == 1) {
					trigger();
				}
				else if (fired)
					shoot();
			}
		}

		if (second.jumping)
			second.gravity();

		//for death
		if (first.health <= 0.0 && first.status == true) {
			second.kills += 1;
			first.status = false;
			first.m_sprite.setPosition(50,0);
		}

		if (second.health <= 0.0 && (second.status == true)) {
			first.kills += 1;

			second.status = false;
			second.m_sprite.setPosition(700, 150);
		}
	}
}

void State_Game::updateKills()
{
	//first
	HUD.kk.str(std::string()); //clear the string
	HUD.kk << first.kills;
	HUD.ktext.setString(HUD.kk.str().c_str());

	//second
	HUD.ks.str(std::string()); //clear the string
	HUD.ks << second.kills;
	HUD.kstext.setString(HUD.ks.str().c_str());
}

void State_Game::healthbar()
{
	float scale1 = first.health/100.0f;
	float scale2 = second.health/100.0f;
	HUD.bar_sprite.setScale(scale1, 1.0);
	HUD.bars_sprite.setScale(scale2, 1.0f);
}

int State_Game::winner()
{
	if (first.kills > second.kills)
		return 1;
	if (first.kills < second.kills)
		return 2;
	if (first.kills == second.kills)
		return 0;
}

bool explode::animate(float x, float y)
{
	sprite.setPosition(x, y);
	if (clock.getElapsedTime().asSeconds() > 0.1f) {
		if (rect.left >= 400) {
			rect.left = 0;
			return false;
		}
		else
			rect.left += 100;

		sprite.setTextureRect(rect);
		clock.restart();
		return true;
	}
}
