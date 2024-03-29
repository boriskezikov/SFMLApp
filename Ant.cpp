#include "Ant.h"
#include <ctime>

Ant::Ant()
{
	srand(time(0));
	role = new Baby();
	role->setLeftBorder(0);
	role->setRightBorder(9); 
	x = rand() % 9; 
	y = rand() % 20;
	livespan = 0;

	texture.loadFromFile(role->getFile());
	sprite.setTexture(texture);
	sprite.setPosition(x*32, y*32);
}

Sprite Ant::getSprite() {return sprite;}

void Ant::goForward() {y --;}

void Ant::goLeft() {x--;}

void Ant::goBackwards() {y++;}

void Ant::goRight() {x++;}

void Ant::move() {
	int direction;
	if ((x <= role->getRightBorder()) && (x >= role->getLeftBorder())) {
		 direction = 1 + rand() % 4;
	}
	else if (x >= role->getRightBorder()) direction = 4;
	else direction = 2;
	switch (direction) {
	case 1:
		if (y <= 0) move();
		else goForward();
		break;
	case 2:
		if (x >= role->getRightBorder()) move();
		else goRight();
		break;
	case 3:
		if (y >= 23) move();
		else goBackwards();
		break;
	case 4:
		if (x <= role->getLeftBorder()) move();
		else goLeft();
		break;
	default:break;
	}
}

void Ant::update(int time, Field* field) {
	livespan++; 
	if (field->getValue(x, y) != 0) {
		switch (role->Work(field->getValue(x, y))) {
		case 1:
			field->setValue(x, y);
			break;
		case 2:
			field->setValue(x, y);
			field->addFood();
			break;
		case 3:
			field->setValue(x, y);
			field->addBranch();
			break;
		default:break;
		}
	}
	setRole();
	sprite.setTexture(texture);
	move();
	sprite.setPosition(x * 32, y * 32);
}

void Ant::setRole() {
		switch (livespan)
		{
		case 10:
			role = new Nanny();
			texture.loadFromFile(role->getFile());
			role->setLeftBorder(0);
			role->setRightBorder(9); 
			break;
		case 20:
			if ((1 + rand() % 2) == 1) {
				role = new Warrior();
				role->setLeftBorder(25);
				role->setRightBorder(41);
			}
			else {
				role = new Shepherd();
				role->setLeftBorder(10);
				role->setRightBorder(19);
			}
			texture.loadFromFile(role->getFile());
			break;
		case 90:
				role = new Collector();
				role->setLeftBorder(20);
				role->setRightBorder(35);
				texture.loadFromFile(role->getFile());
				break;
		case 140:
			role = new Cleaner();
			role->setLeftBorder(0);
			role->setRightBorder(9);
			texture.loadFromFile(role->getFile());
			break;
			default:break;
		}
	}

bool Ant::alive() {
	return livespan <= 170;
}


Ant::~Ant() = default;
