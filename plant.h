#include "pet.h"

#ifndef PLANT_H
#define PLANT_H

using namespace std;

class Plant :public Pet{
protected:
	int greenness;
	const int MIN_GREENNESS = 1;
	const int MAX_GREENNESS = 50;
};

class Fern :public Plant{
public:
	void action(){
		cout << "Fernnaises" << endl;
	}
};

class Cactus :public Plant{
public:
	void action(){
		cout << "Poke!" << endl;
	}
};

#endif
