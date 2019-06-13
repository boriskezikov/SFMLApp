#pragma once
#include "Role.h"
#include <iostream>
#include <ctime>

using namespace std;
class Collector : public Role
{
private:
	int food;

public:
	Collector()
	{
		food = 1 + rand() % 2;
		if (food == 1)
			file = "/Users/kezikovboris/CLionProjects/SFMLapp/images/collectorFood.png";
		else
			file = "/Users/kezikovboris/CLionProjects/SFMLapp/images/collectorBranch.png";
	}
	int Work(int type) override {
		if ((type == 2) || (type == 3)) {
			switch (food) {
			case 1:
				if (type == 2) return 2;
				else return 0;
			case 2:
				if (type == 3) return 3;
				else return 0;
			default:break;
			}
		}
		else return 0;
	}
};

