#pragma once
#include "Role.h"
#include <iostream>
#include <ctime>

using namespace std;
class Baby : public Role
{
public:
	Baby() {file = "/Users/kezikovboris/CLionProjects/SFMLapp/images/Baby.png";}
	int Work(int type) override { return 0; }
	string getFile() override { return file; }

};

