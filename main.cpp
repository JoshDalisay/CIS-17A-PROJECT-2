// CIS-17A Project 1

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int numScoopsValid(int);
int numToppingsValid(int);

int main() {

	ifstream inputFile;

	string iceHolder = "";
	string chosenIceCream = "";
	string toppingsString;
	string reorderLoop;
	string orderOrder[5]{ "1st", "2nd", "3rd", "4th", "5th" };
	int numScoops = 0;
	int numScoopsReturned;
	int toppingsInput = 0;
	int toppingsInputReturned;
	int oA = 0;
	int noMoreOrder = 1;
	double orderComplete[5]{ 0.00, 0.00, 0.00, 0.00, 0.00 };
	double orderTotal = 0.00;
	double orderTotalComplete = 0.00;
	const double conePrice = 2.50;
	const double bowlPrice = 3.00;
	const double icecreamPrice = 2.00;
	const double toppingPrice = 0.50;

	inputFile.open("OrderTotal.txt");

	cout << "Welcome to (Placeholder)!" << endl << endl;

	while (noMoreOrder != 2) {
		cout << "\nWould you like a cone or bowl?" << endl;

		do {
			cin >> iceHolder;
			if (iceHolder == "cone" || iceHolder == "CONE" || iceHolder == "Cone") {

				orderTotal += conePrice;
				cout << "\nYou chose cone." << endl;

			}
			else if (iceHolder == "bowl" || iceHolder == "BOWL" || iceHolder == "Bowl") {

				orderTotal += bowlPrice;
				cout << "\nYou chose bowl." << endl;

			}
			else {

				cout << "\nInvalid choice! Try again!" << endl;

			}
		} while (iceHolder != "cone" && iceHolder != "CONE" && iceHolder != "Cone" && iceHolder != "bowl" && iceHolder != "BOWL" && iceHolder != "Bowl");

		cout << "\nWhat is the flavor of the ice cream that you would like to order?" << endl;
		cout << "\nWe have vanilla, chocolate, strawberry, sherbert, and pistachio." << endl;

		do {
			cin >> chosenIceCream;

			if (chosenIceCream == "vanilla" || chosenIceCream == "Vanilla")
				cout << "\nYou chose " << chosenIceCream << "." << endl;

			else if (chosenIceCream == "chocolate" || chosenIceCream == "Chocolate")
				cout << "\nYou chose " << chosenIceCream << "." << endl;

			else if (chosenIceCream == "strawberry" || chosenIceCream == "Strawberry")
				cout << "\nYou chose " << chosenIceCream << "." << endl;

			else if (chosenIceCream == "sherbert" || chosenIceCream == "Sherbert")
				cout << "\nYou chose " << chosenIceCream << "." << endl;

			else if (chosenIceCream == "pistachio" || chosenIceCream == "Pistachio")
				cout << "\nYou chose " << chosenIceCream << "." << endl;

			else
				cout << "\nInvalid choice! Try again" << endl;

		} while (chosenIceCream != "vanilla" && chosenIceCream != "Vanilla" && chosenIceCream != "chocolate" && chosenIceCream != "Chocolate"
			&& chosenIceCream != "strawberry" && chosenIceCream != "Strawberry" && chosenIceCream != "sherbert" && chosenIceCream != "Sherbert"
			&& chosenIceCream != "pistachio" && chosenIceCream != "Pistachio");

		cout << "\nHow many scoops would you like? (Max of 3)." << endl;

		do {

			numScoopsReturned = numScoopsValid(numScoops);
			if (numScoopsReturned == 1) {

				orderTotal += icecreamPrice;
				cout << "\nYou chose 1 scoop." << endl;

			}
			else if (numScoopsReturned == 2) {

				orderTotal += icecreamPrice * 2;
				cout << "\nYou chose 2 scoops." << endl;

			}
			else if (numScoopsReturned == 3) {

				orderTotal += icecreamPrice * 3;
				cout << "\nYou chose 3 scoops." << endl;

			}
			else {

				cout << "\nInvalid choice! Try again!" << endl;

			}
		} while (numScoopsReturned != 1 && numScoopsReturned != 2 && numScoopsReturned != 3);

		cout << "\nAlright, now would you like any toppings? (Y/N)" << endl;

		do {

			cin >> toppingsString;
			if (toppingsString == "y" || toppingsString == "Y") {

				cout << "\nWhat kind of toppings would you like?" << endl;
				cout << "We have: \n1. Oreo Cookies \n2. Chocolate Syrup \n3. Strawberries \n4. Gummy Bears \n5. Twix \n6. Snickers \n7. M&Ms \n8. Reese's Pieces \n9. No additional toppings." << endl << endl;
				do {
					
					toppingsInputReturned = numToppingsValid(toppingsInput);
					switch (toppingsInputReturned) {
					case 1: cout << "You chose Oreo Cookies\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					case 2: cout << "You chose Chocolate Syrup\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					case 3: cout << "You chose Strawberries\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					case 4: cout << "You chose Gummy Bears\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					case 5: cout << "You chose Twix\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					case 6: cout << "You chose Snickers\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					case 7: cout << "You chose M&Ms\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					case 8: cout << "You chose Reese's Pieces\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					case 9: cout << "No more toppings.\n";
						orderTotal += toppingPrice;
						cin.clear();
						break;
					default: cout << "Invalid choice! Try again.\n";
						cin.clear();
						break;
					}

				} while (toppingsInputReturned != 9);

			}
			else if (toppingsString == "n" || toppingsString == "N") {

				cout << "\nNo Toppings selected." << endl;

			}
			else {

				cout << "\nInvalid choice! Try Again!" << endl;

			}

		} while (toppingsString != "y" && toppingsString != "Y" && toppingsString != "n" && toppingsString != "N");



		orderComplete[oA] = orderTotal;
		cout << "\nWould you like to add another order? (Max 5) (Y/N) " << endl;
		do {
			cin >> reorderLoop;
			if (reorderLoop == "y" || reorderLoop == "Y") {

				orderComplete[++oA];
				orderTotal = 0.00;
				noMoreOrder = 1;

			}
			else if (reorderLoop == "n" || reorderLoop == "N") {

				noMoreOrder = 2;

			}
			else {

				cout << "\nInvalid choice! Try Again." << endl;

			}
		} while (reorderLoop != "y" && reorderLoop != "Y" && reorderLoop != "n" && reorderLoop != "N");

	}
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[0] << " item cost: " << orderComplete[0] << endl;
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[1] << " item cost: " << orderComplete[1] << endl;
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[2] << " item cost: " << orderComplete[2] << endl;
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[3] << " item cost: " << orderComplete[3] << endl;
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[4] << " item cost: " << orderComplete[4] << endl;
	for (oA = 0; oA < 5; oA++) {

		orderTotalComplete += orderComplete[oA];

	}
	cout << "\nYou order total will be: ";
	cout << setw(5) << setprecision(2) << fixed << "$" << orderTotalComplete << endl << endl;


	inputFile >> orderTotalComplete;
	inputFile.close();

	return 0;


}

int numScoopsValid(int i) {

	while (!(cin >> i)) {
		cout << "Enter a valid number, try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	return i;

}

int numToppingsValid(int x) {

	while (!(cin >> x)) {
		cout << "Enter a valid number, try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	return x;

}
