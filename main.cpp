/*Alex Macedo
Lab8?
macedo22@ucla.edu

This main function creates a Pet pointer to a Snake object and
the Snake object sneks. Also, A Table object is created 
and books, a lamp, and a tissue box are added onto the table.
Lastly, a Cat object is is created and knocks all this shit
off of the Table so that no iteams remain on top.*/


#include "pet.h"
#include "animal.h"

using namespace std;

int main(){
	Pet* snake = new Pet();

	static_cast<Snake*>(snake)->snek();//Pet object snake is converted to a Snake object and sneks

	//A Table and its Books, Lamp, and TissueBox are created

	Table table;
	Table* tablePtr=&table;
	table.setSurfaceArea(100, 100);

	Book book;
	book.setSurfaceArea(10, 5);
	table.addBook(book);

	Book book2;
	book.setSurfaceArea(5, 5);
	table.addBook(book2);

	Lamp lamp;
	lamp.setSurfaceArea(5, 5);
	table.addLamp(lamp);

	TissueBox tissueBox;
	tissueBox.setSurfaceArea(8, 4);
	table.addTissueBox(tissueBox);

	//Table contents are displayed

	cout <<endl<< "BEFORE CAT:" << endl << endl;
	cout << "Number of books: " << table.getNumberOfBooks() << endl;
	cout << "Number of lamps: " << table.getNumberOfLamps() << endl;
	cout << "Number of tissue boxes: " << table.getNumberOfTissueBoxes() << endl << endl;

	//Cat knocks all the current shit off the table

	Cat cat;
	cat.knock_shit_off_table(tablePtr);

	//Prints and confirms the lack of shit on the table

	cout << endl<<"AFTER CAT:" << endl << endl;
	cout << "Number of books: " << table.getNumberOfBooks() << endl;
	cout << "Number of lamps: " << table.getNumberOfLamps() << endl;
	cout << "Number of tissue boxes: " << table.getNumberOfTissueBoxes() << endl;

	

	return 0;
}