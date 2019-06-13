#pragma once
#include "Role.h"
#include <iostream>

using namespace std;
class Cleaner:public Role
{
public:
	Cleaner() { file = "/Users/kezikovboris/CLionProjects/SFMLapp/images/Cleaner.png"; };
	int Work(int type) override {
		if (type == 1) return 1;
		else  return 0;
	}
};

