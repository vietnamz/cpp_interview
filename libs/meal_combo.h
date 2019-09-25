// meal_combo.h 

#include <stdio.h>
#include <iostream>

using namespace std;
// Base Entree class
class Entree
{
protected:
	char _entree[10];
public:
    Entree(char e[10]) {
		strcpy(_entree ,e);
	}
	const char *getEntree()
	{
		return _entree;
	}
};


class Side
{
protected:
	char _side[10];
public:
    Side(char e[10]) {
		strcpy(_side ,e);
	}
	char *getSide()
	{
		return _side;
	}
};

class Drink
{
protected:
	char _drink[10];
public:
	Drink()
	{
		cout << "\n Fill cup with soda" << endl;
		strcpy(_drink, "soda");
	}
	char *getDrink()
	{
		return _drink;
	}
};

// Complex MealCombo object that contains an Entree, a Side and a Drink object

class MealCombo {
private:
	Entree * entree;
	Side* side;
	Drink* drink;
	char _bag[100];
public:
	MealCombo(const char* type) {
		sprintf(_bag, "%s meal combo:", type);
	}
	void setEntree(Entree* e) {
		this->entree = e;
	}
	void setSide(Side *s) {
		this->side = s;
	}
	void setDrink(Drink* d) {
		this->drink = d;
	}

	string openMealBag() {
		sprintf(_bag, "%s %s, %s, %s", _bag, entree->getEntree(),
		drink->getDrink(), side->getSide());
		return string(_bag);
	}

};

