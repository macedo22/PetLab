#include "pet.h"
#include "table.h"

#ifndef ANIMAL_H
#define ANIMAL_H

using namespace std;


class Animal :public Pet{
protected:
	char gender;
	bool indoor;
};

class Cat : public Animal{
public:

	//removes all current objects on a Table; friend function from the Table class
	/*void knock_shit_off_table(Table* tablePtr){

		removeAllItems(tablePtr);

		cout << "Maintain eye contact. Assert dominance." << endl;
	}*/

	void action(){
	    cout<<"The cat can no longer knock shit off the table :("<<endl;
	}
};

class Dog : public Animal{
public:
	void action(){
		cout << "Yum!" << endl;
	}
};

class Snake : public Animal{
public:
	void action(){
		cout << "snek snek snek" << endl;
	}
};

#endif
