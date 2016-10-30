#include "pet.h"

#ifndef ROCK_H
#define ROCK_H

using namespace std;

class Rock :public Pet{
protected:
	int hardness;
	string cleavage;
	int color;
	string chemicalComp;
};

class Fornacite :public Rock{
};

class Fukalite :public Rock{
};

class Cummingtonite :public Rock{
};

#endif