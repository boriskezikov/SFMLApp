#pragma once
#include "Role.h"
#include <iostream>

using namespace std;

class Warrior: public Role
{
public:
	Warrior() { file = "/Users/kezikovboris/CLionProjects/SFMLapp/images/Warrior.png"; };
	int Work(int type) override {
		return 4;
	}

};

