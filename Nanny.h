#pragma once
#include "Role.h"
#include <iostream>

using namespace std;
class Nanny: public Role
{
public:
	Nanny() { file = "/Users/kezikovboris/CLionProjects/SFMLapp/images/Nanny.png"; };
	int Work(int type) override {
		return 0;
	}
};

