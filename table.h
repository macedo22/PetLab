#include <vector>

#ifndef TABLE_H
#define TABLE_H

using namespace std;

enum Color { BLACK, BROWN, WHITE, GREEN, RED };
enum Material { WOOD, METAL, CERAMIC };

struct Dimension{
	int length;
	int width;
};

class Book{

private:
	bool status;//book is opened or closed; opened=true, closed=false
	int numberOfPages;
	string title;
	Dimension bookDim;
	int surfaceArea;

public:
	bool getStatus(){
		return status;
	}

	int getNumberOfPages(){
		return numberOfPages;
	}

	string getTitle(){
		return title;
	}

	int getLength(){
		return bookDim.length;
	}

	int getWidth(){
		return bookDim.width;
	}

	int getSurfaceArea(){
		return surfaceArea;
	}

	void setStatus(string s){
		if (s == "open"){
			status = true;
		}
		else{
			status = false;
		}
	}

	void setNumberOfPages(int p){
		numberOfPages = p;
	}

	void setTitle(string t){
		title = t;
	}

	void setLength(int l){
		bookDim.length = l;
	}

	void setWidth(int w){
		bookDim.width = w;
	}

	void setSurfaceArea(int length, int width){
		surfaceArea = length*width;
	}
};

class TissueBox{

private:
	int maxTissues;
	int currentTissues;
	Dimension tissueDim;
	int surfaceArea;

public:
	int getMaxTissues(){
		return maxTissues;
	}

	int getCurrentTissues(){
		return currentTissues;
	}

	int getLength(){
		return tissueDim.length;
	}

	int getWidth(){
		return tissueDim.width;
	}

	int getSurfaceArea(){
		return surfaceArea;
	}

	void setMaxTissues(int maxT){
		maxTissues = maxT;
	}

	void setLength(int l){
		tissueDim.length = l;
	}

	void setWidth(int w){
		tissueDim.width = w;
	}

	void setSurfaceArea(int length, int width){
		surfaceArea = length * width;
	}
};

class Lamp{

private:
	Color color;
	bool status;//lamp is on or off. on=true, off=false
	Dimension lampDim;
	int surfaceArea;

public:
	Color getColor(){
		return color;
	}

	bool getStatus(){
		return status;
	}

	int getLength(){
		return lampDim.length;
	}

	int getWidth(){
		return lampDim.width;
	}

	int getSurfaceArea(){
		return surfaceArea;
	}

	void setColor(Color c){
		color = c;
	}

	void setStatus(bool s){
		status = s;
	}

	void setLength(int l){
		lampDim.length = l;
	}

	void setWidth(int w){
		lampDim.width = w;
	}

	void setSurfaceArea(int length, int width){
		surfaceArea = length * width;
	}

	void input(){
		cout << "What is the length of the base of your  in inches? ";
		cin >> lampDim.length;
		setLength(lampDim.length);

		cout << "What is the width of the base of your lamp in inches? ";
		cin >> lampDim.width;
		setWidth(lampDim.width);

		setSurfaceArea(lampDim.length, lampDim.width);
	}

	void output(){
		cout << endl << "This lamp is " << lampDim.length << " inches long, "
			<< lampDim.width << " inches wide, and has a surface area of "
			<< surfaceArea << " square inches." << endl;
	}
};

class Table{

private:
	Color color;
	int numberOfLegs;
	Material material;
	Dimension tableDim;
	int surfaceArea;
	//vectors to keep track of all items placed on top of a Table
	vector < Book > books;
	vector <TissueBox> tissueBoxes;
	vector <Lamp> lamps;


public:
	Color getColor(){
		return color;
	}

	int getNumberOfLegs(){
		return numberOfLegs;
	}

	Material getMaterial(){
		return material;
	}

	int getLength(){
		return tableDim.length;
	}

	int getWidth(){
		return tableDim.width;
	}

	int getSurfaceArea(){
		return surfaceArea;
	}

	int getNumberOfBooks(){
		return books.size();
	}

	int getNumberOfTissueBoxes(){
		return tissueBoxes.size();
	}

	int getNumberOfLamps(){
		return lamps.size();
	}

	vector<Book> getBooks(){
		return books;
	}

	void setColor(string c){
		if (c == "black"){
			color = BLACK;
		}
		else if (c == "brown"){
			color = BROWN;
		}
		else if (c == "white"){
			color = WHITE;
		}
		else if (c == "green"){
			color = GREEN;
		}
		else{
			color = RED;
		}
	}

	void setNumberOfLegs(int numLegs){
		numberOfLegs = numLegs;
	}

	void setMaterial(string m){
		if (m == "wood"){
			material = WOOD;
		}
		else if (m == "metal"){
			material = METAL;
		}
		else{
			material = CERAMIC;
		}
	}

	void setLength(int l){
		tableDim.length = l;
	}

	void setWidth(int w){
		tableDim.width = w;
	}

	void setSurfaceArea(int length, int width){
		surfaceArea = length * width;
	}

	void addBook(Book book){
		if (surfaceArea >= book.getSurfaceArea()){
			books.push_back(book);
			surfaceArea -= book.getSurfaceArea();
			cout << endl << "The book has been added to your table." << endl;
		}
		else{
			cout << endl << "I'm sorry. There is not enough room on the table for " << book.getTitle() << "." << endl;
		}
	}

	//removes most recent book added to a Table
	void removeBook(){
		if (!books.empty()){
			int i = books.size();
			surfaceArea += books[i - 1].getSurfaceArea();
			cout << endl << books[i - 1].getTitle() << " has been removed from the table." << endl;
			books.pop_back();
		}
		else{
			cout << endl << "There are currently no books on the table." << endl;
		}
	}

	void addTissueBox(TissueBox tissueBox){
		if (surfaceArea >= tissueBox.getSurfaceArea()){
			tissueBoxes.push_back(tissueBox);
			surfaceArea -= tissueBox.getSurfaceArea();
			cout << endl << "The tissue box has been added to your table." << endl;
		}
		else{
			cout << endl << "I'm sorry. There is not enough room on the table for this tissue box." << endl;
		}
	}

	//removes most recent tissue box added to a Table
	void removeTissueBox(){
		if (!tissueBoxes.empty()){
			int i = tissueBoxes.size();
			surfaceArea += tissueBoxes[i - 1].getSurfaceArea();
			cout << endl << "The most recent tissue box placed has been removed from the table." << endl;
			tissueBoxes.pop_back();
		}
		else{
			cout << endl << "There are currently no tissue boxes on the table." << endl;
		}
	}

	void addLamp(Lamp lamp){
		if (surfaceArea >= lamp.getSurfaceArea()){
			lamps.push_back(lamp);
			surfaceArea -= lamp.getSurfaceArea();
			cout << endl << "The lamp has been added to your table." << endl;
		}
		else{
			cout << endl << "I'm sorry. There is not enough room on the table for this lamp." << endl;
		}
	}

	//removes most recent lamp added to a Table
	void removeLamp(){
		if (!lamps.empty()){
			int i = lamps.size();
			surfaceArea += lamps[i - 1].getSurfaceArea();
			cout << endl << "The most recent lamp placed has been removed from the table." << endl;
			lamps.pop_back();
		}
		else{
			cout << endl << "There are currently no lamps on the table." << endl;
		}
	}


	//remove all objects on a Table
	//Cat class contains this friend function
	friend void removeAllItems(Table* tablePtr){
		(*tablePtr).books.clear();
		(*tablePtr).tissueBoxes.clear();
		(*tablePtr).lamps.clear();
	}

};

#endif