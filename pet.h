#include<string>
#include<iostream>
#include "person.h"

#ifndef PET_H
#define PET_H

using namespace std;

class Pet{

protected:
	string name;
	int age;
	Person owner;

public:
    virtual void action()=0;

};

#endif
