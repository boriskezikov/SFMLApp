#pragma once
#include "Role.h"
#include <iostream>

using namespace std;
class Shepherd: public Role
{
public:
	Shepherd() { file = "/Users/kezikovboris/CLionProjects/SFMLapp/images/Shepherd.png"; };
	int Work(int type) override { return 0; }
};

