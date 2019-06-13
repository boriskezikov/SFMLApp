#include "main.h"
#include "Ant.h"
#include "Engine.h"

int main() {
	auto field = new Field(); // create field with default params
	Engine engine(field);
	engine.start();
}