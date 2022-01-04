#pragma once
#include <iostream>
#include<string>
using namespace std;

enum vendingmachinestate {
	SELECT, QUANTITY, CALCULATE, UPDATE
};


enum Brand {
	COKE = 100, PEPSI = 200, SPRITE = 300
};

struct Student {
	string name;
	int points{0};
};

struct Soda {
	Brand brandname;
	int inventory;
	int price;

};

int main() {


	//Initial
	vendingmachinestate currentstate = SELECT;
	//fill up with sodas
	Soda vendingmachine[3];
	vendingmachine[0].brandname = COKE;
	vendingmachine[0].inventory = 10;
	vendingmachine[0].price = 1;

	vendingmachine[1].brandname = PEPSI;
	vendingmachine[1].inventory = 10;
	vendingmachine[1].price = 2;

	vendingmachine[2].brandname = SPRITE;
	vendingmachine[2].inventory = 10;
	vendingmachine[2].price = 3;


	Soda selectedSoda;
	Student Pranjali;
	Pranjali.name = "Pranjali";
	Pranjali.points = 100;
	while (true) {
		switch (currentstate)
		{
		case SELECT:
			//Display the current status for the vending machine
			cout << "Current Status - vending machine" << endl;
			for (int i = 0; i < 3; i++) {
				cout << vendingmachine[i].brandname << " has " << vendingmachine[i].inventory << " drinks " << vendingmachine[i].price << " per soda" << endl;
			}

			//Display soda names and id values
			cout << "what drink will you have?" << endl;
			cout << "COKE = 100 " << endl;
			cout << "PEPSI = 200 " << endl;
			cout << "SPRITE = 300 " << endl;

			// Ask the user what drink
			int selected;
			cin >> selected;

			//If valid drink selected , go ahead
			switch (selected) {
			case COKE:
				selectedSoda.brandname = COKE;
				cout << "you selected COKE" <<endl;
				currentstate = QUANTITY;
				break;
			case PEPSI:
				selectedSoda.brandname = PEPSI;

				cout << "you selected PEPSI" << endl;
				currentstate = QUANTITY;

				break;

			case SPRITE:
				selectedSoda.brandname = SPRITE;

				cout << "you selected SPRITE" << endl;
				currentstate = QUANTITY;

				break;
			default:
				cout << "Invalid input" << endl;
				currentstate = SELECT;
				break;
			}

			break;
		case QUANTITY:
			cout << "How many would you like?" << endl;
			int val;
			cin >> val;
			switch (selectedSoda.brandname) {
			case COKE:
				if (val< 0 || val> vendingmachine[0].inventory) {
					cout << "Invalid input";
				}
				else {
					cout << " Request received for the Coke" << endl;
					currentstate = CALCULATE;

				}
				break;
			case PEPSI:
				if (val< 0 || val> vendingmachine[1].inventory) {
					cout << "Invalid input";
				}
				else {
					cout << " Request received for the Pepsi" << endl;
					currentstate = CALCULATE;

				}
				break;

			case SPRITE:
				if (val< 0 || val> vendingmachine[2].inventory) {
					cout << "Invalid input";
				}
				else {
					cout << " Request received for the Sprite" << endl;
					currentstate = CALCULATE;

				}
				break;
			default:
				cout << "Invalid" << endl;
				break;

			}

			break;
		case CALCULATE:
			int total_cost;

			switch (selectedSoda.brandname) {
			case COKE:
				total_cost = vendingmachine[0].price * val;
				cout << "Customer owes " << total_cost << endl;
				currentstate = UPDATE;

				break;
			case PEPSI:
				total_cost = vendingmachine[1].price * val;
				cout << "Customer owes " << total_cost << endl;
				currentstate = UPDATE;


				break;
			case SPRITE:
				total_cost = vendingmachine[2].price * val;
				cout << "Customer owes " << total_cost << endl;
				currentstate = UPDATE;

				break;

			}
			cout << "Please pay the above shown amount" << endl;
			int customer_paid;
			cin >> customer_paid;

			cout << "you paid " << customer_paid << endl;
			if (customer_paid > Pranjali.points || customer_paid < total_cost || customer_paid < 0) {
				cout << "Please give a valid amount" << endl;
				currentstate = SELECT;
			}
			else {
				Pranjali.points = Pranjali.points - customer_paid;
				int change = customer_paid - total_cost;
				cout << "your change is " << change << endl;
				Pranjali.points = Pranjali.points + change;
				currentstate = UPDATE;
			}
			break;
		case UPDATE:
			switch (selectedSoda.brandname) {
			case COKE:
				vendingmachine[0].inventory = vendingmachine[0].inventory - val;
				currentstate = SELECT;
				break;
			case PEPSI:
				vendingmachine[1].inventory = vendingmachine[1].inventory - val;
				currentstate = SELECT;

				break;
			case SPRITE:
				vendingmachine[2].inventory = vendingmachine[2].inventory - val;
				currentstate = SELECT;

				break;

		}
			
			
			break;

		default:
			cout << "Error! Invalid state";
			break;
		}
	}

	return 0;
}

