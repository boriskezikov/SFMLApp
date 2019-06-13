#include "Enemy.h"


Enemy::Enemy()
{
	srand(time(0));
	x = 41; 
	y = rand() % 23;
	attackTime = 25 + rand() % 35; 
	intervalBetweenAttacks = 10 + rand() % 20;
	livespan = 1;
	texture.loadFromFile("/Users/kezikovboris/CLionProjects/SFMLapp/images/Enemy.png");
	sprite.setTexture(texture);
	sprite.setPosition(x * 32, y * 32);
}


Sprite Enemy::getSprite() { return sprite; }

void Enemy::goForward() { y--; }

void Enemy::goLeft() { x--; }

void Enemy::goBackwards() { y ++; }

void Enemy::goRight() { x++; }

void Enemy::move() {
	int direction;
	if ((x <= getRightBorder()) && (x >= getLeftBorder())) {
		direction = 1 + rand() % 4;
	}
	else if (x >= getRightBorder()) direction = 4;
	else direction = 2;
	switch (direction) {
	case 1:
		if (y <= 0) move();
		else goForward();
		break;
	case 2:
		if (x >= getRightBorder()) move();
		else goRight();
		break;
	case 3:
		if (y >= 20) move();
		else goBackwards();
		break;
	case 4:
		if (x <= getLeftBorder()) move();
		else goLeft();
		break;
	}
}


void Enemy::update(Field* field,int time) {
	if (field->getValue(x,y)==2)
		field->setValue(x, y);
	livespan++;
	sprite.setTexture(texture);
	move();
	sprite.setPosition(x * 32, y * 32);
}

bool Enemy::alive(int time) {
	if (time >= attackTime)
		return true;
	else{
		return false;
	}
}

void Enemy::setCoordinates() {
	x = 41;
	y = 1+rand()%23;
}
void Enemy::doWork(Ant* ant,Field* field,int time) {
	if (ant->getX() == x && ant->getY() == y) { 
		if (ant->getRole()->Work(field->getValue(x, y)) == 4) {
			switch (1 + rand() % 3)
			{
			case 1: 
				ant->setLivespan();
				ant->setRole();
				cout << "Муравей героически сдох" << endl;
				break;
			case 2: 
				while (getX() != 41) {
					goRight();
				}
				cout << "Вы напугали красного муравья" << endl;
				break;
			case 3:
				setCoordinates();
				attackTime = time + intervalBetweenAttacks;
				cout << "Враг повержен!!! " << endl;
				break;
			}
		}
		if (ant->getRole()->getFile() == "/Users/kezikovboris/CLionProjects/SFMLapp/images/collectorFood.png") {
			switch (1+rand()%2 )
			{
			case 1:
				field->setCountedFood(field->getCountedFood() - 1);
				cout << "Оп! Хавчик" << endl;
				break;
			case 2:
				cout << "(( облом , еду забрали(( " << endl;
				break;
			}
		}
	}
}


