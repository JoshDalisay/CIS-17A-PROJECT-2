
// CIS-17A Project 2B
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

int numScoopsValid(int); 	//Function to check if the number of scoops is possible
int numToppingsValid(int);	//Function to check if user input of toppings is an int
int testStub(int);			//Test stub function
void finalPointsEarned(int *u, double t); //Assian points earned from order 
void mainmenu();			//Function for user login/registration


int choice; 				//User choice to login or not
bool cinfail; 				//To input validation for choice
int confirmation; 			//Username confirmation
string username, password, password2;		//Username and passwords
int loginPassword;							//Password checked when attempting to login

void writetofile(string username, string password) {			//Writes usernames and passwords to a textfile
																//during registration
	ofstream writefile;
	string file = username + ".txt";
	writefile.open(file.c_str());
	writefile << password;
	writefile.close();
	mainmenu();
}



void login() {												//Login screen

	cout << "\nPlease enter your username: " << endl;
	cin >> username;
	cout << "\nPlease enter your password: " << endl;
	cin >> loginPassword;
	cout << "\nYou are being logged in!" << endl;
	cout << "Logged in!" << endl;

}


void registerpassword() {									//Password Registration
	cout << "Please enter the password:" << endl;
	cin >> password;
	cout << "Please renter your password:" << endl;
	cin >> password2;
	if (password == password2) {
		cin.clear();
		cin.ignore(10000, '\n');
		writetofile(username, password);


	}
	else {
		cout << "Sorry invalid" << endl;
		registerpassword();
	}
}


void registerme() {											//Username Registration
	cout << "Please enter your username: " << endl;
	getline(cin, username);
	cout << "\nUsername -  \"" << username << "\"\nConfirm? \n\n[1] Yes\n[2] No" << endl;
	cin >> confirmation;
	if (confirmation == 1) {

		registerpassword();

	}
	else if (confirmation == 2) {

		cout << "Please try again" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		registerme();

	}


	else {
		cout << "Finished registering!" << endl;
	}
}


void mainmenu() {
	cout << "Hello, Would you like to log in or register\n[1] Login\n[2] Register\n[3] None" << endl; 				//Registration main menu
	cin >> choice; do {
		cinfail = cin.fail();
		cin.clear();
		cin.ignore(10000, '\n');

	} while (cinfail == true); {
		switch (choice) {
		case 1:
			login();
			break;

		case 2:
			registerme();
			break;

		case 3:
			cout << "How can we start your order?" << endl;
			break;
		}}
}


int main() {

	ifstream inputFile;

	const int h = 5;										//Defines array sizes
	string iceHolder = "";									//What container for the ice cream the customer would want
	string chosenIceCream = "";								//What flavour of ice cream the customer chose
	string toppingsString;									//A check to see if the guest wants toppings
	string reorderLoop;										//Used to loop the program if a guest wants to order again
	string orderOrder[5]{ "1st", "2nd", "3rd", "4th", "5th" };			//Lists the orders made by the guest
	int numScoops = 0;										//Value passed to the numScoopsVaild function
	int numScoopsReturned;									//Value returend by the numScoopsValid function
	int toppingsInput = 0;									//Topping choice and value passed to function
	int toppingsInputReturned;								//Value returned by function when valid
	int oA = 0;												//Number of values in the order array
	int noMoreOrder = 1;									//Value used to stop loop if guest doesnt want to order anymore
	int pointsEarned;										//Total amount of points earned in customers order
	int pointsEarnedPassed;									//Value of points earned passed into function
	double orderComplete[5]{ 0.00, 0.00, 0.00, 0.00, 0.00 };	//Cost of each order stored in array
	double orderTotal = 0.00;								//the current order total
	double orderTotalComplete = 0.00;						//The final order total
	const double conePrice = 2.50;							//Price of cone
	const double bowlPrice = 3.00;							//Price of bowl
	const double icecreamPrice = 2.00;						//Price per scoop
	const double toppingPrice = 0.50;						//Price per topping

	inputFile.open("OrderTotal.txt");						//Open text file for later use



	cout << "Welcome to Frozen Rock Creamery!" << endl << endl;			//Introduction

	mainmenu(); 	//Registration menu call

	while (noMoreOrder != 2) {				//Loop used to continue order
		cout << "\nWould you like a cone or bowl?" << endl;			//Asks if guest wants cone or bowl

		do {				//Input validation for cone or bowl and adds price to order total
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

		cout << "\nWhat is the flavor of the ice cream that you would like to order?" << endl;		//Asks for desired icecream flavour
		cout << "\nWe have vanilla, chocolate, strawberry, sherbert, and pistachio." << endl;		//List of flavours

		do {	//Checks for what flavour was entered
			cin >> chosenIceCream; //What the guest chose

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

		cout << "\nHow many scoops would you like? (Max of 3)." << endl; //Asks for how many scoops the guest wants

		do { //Checks for how many scoops the guest ordered and adds it to the order total

			numScoopsReturned = numScoopsValid(numScoops); //Input validation for vaild number entered
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

		cout << "\nAlright, now would you like any toppings? (Y/N)" << endl;		//Asks guest if they wanted toppings

		do {		//Topping choice

			cin >> toppingsString; //Checks if the guest wanted toppings
			if (toppingsString == "y" || toppingsString == "Y") {

				cout << "\nWhat kind of toppings would you like?" << endl;
				cout << "We have: \n1. Oreo Cookies \n2. Chocolate Syrup \n3. Strawberries \n4. Gummy Bears \n5. Twix \n6. Snickers \n7. M&Ms \n8. Reese's Pieces \n9. No additional toppings." << endl << endl;
				do {

					toppingsInputReturned = numToppingsValid(toppingsInput);		//Which toppings were chosen by the guest
					switch (toppingsInputReturned) {								//toppings are seleted by number input
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
					case 9: cout << "No more toppings.\n"; //Closes topping choice when guest is done
						orderTotal += toppingPrice;
						cin.clear();
						break;
					default: cout << "Invalid choice! Try again.\n";
						cin.clear();
						break;
					}

				} while (toppingsInputReturned != 9);

			}
			else if (toppingsString == "n" || toppingsString == "N") {		//Ends if guest didn't want any toppings

				cout << "\nNo Toppings selected." << endl;

			}
			else {

				cout << "\nInvalid choice! Try Again!" << endl;

			}

		} while (toppingsString != "y" && toppingsString != "Y" && toppingsString != "n" && toppingsString != "N");



		orderComplete[oA] = orderTotal; //adds the current order to what will become the final order total
		cout << "\nWould you like to add another order? (Max 5) (Y/N) " << endl;			//Checks if guest wanted to order another item
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
		} while (reorderLoop != "y" && reorderLoop != "Y" && reorderLoop != "n" && reorderLoop != "N"); //Input validation for reordering

	}

	cout << endl << endl;

	for (int c = 0; c < h; c++) {						//Selection sort algorithm 
														//Sorts  order in decending order
		double smallest = orderComplete[c];
		int smallestIndex = c;

		for (int e = c; e < h; e++) {

			if (orderComplete[e] < smallest) {

				smallest = orderComplete[e];
				smallestIndex = e;

			}

		}

		swap(orderComplete[c], orderComplete[smallestIndex]);			// Swaps the values 

	}


	cout << "In order from lest expensive to most expensive: " << endl << endl;							//Listing of item prices

	cout << setprecision(2) << fixed << "\nYour " << orderOrder[4] << " most expensive item cost: " << orderComplete[0] << endl;
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[3] << " most expensive item cost: " << orderComplete[1] << endl;
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[2] << " most expensive item cost: " << orderComplete[2] << endl;
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[1] << " most expensive item cost: " << orderComplete[3] << endl;
	cout << setprecision(2) << fixed << "\nYour " << orderOrder[0] << " most expensive item cost: " << orderComplete[4] << endl;
	for (oA = 0; oA < 5; oA++) {

		orderTotalComplete += orderComplete[oA];				//Adds all the items ordered to the final total

	}



	cout << "\nYou order total will be: ";
	cout << setw(5) << setprecision(2) << fixed << "$" << orderTotalComplete << endl << endl;

	pointsEarnedPassed = static_cast<int>(orderTotalComplete);

	//pointsEarned = testStub(pointsEarnedPassed);				//Driver for test stub

	finalPointsEarned(&pointsEarned, orderTotalComplete);


	cout << "\nThis order earned: " << pointsEarned << " points for this order!" << endl;
	cout << "\nThank you for shopping at Frozen Rock Creamery!" << endl;




	inputFile >> orderTotalComplete;		//Writes final total to file for assumed printing
	inputFile.close();

	return 0;


}

int numScoopsValid(int i) {					//Checks to make sure user entered an int

	while (!(cin >> i)) {
		cout << "Enter a valid number, try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	return i;

}

int numToppingsValid(int x) {				//Checks to make sure user entered an int

	while (!(cin >> x)) {
		cout << "Enter a valid number, try again: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	return x;

}


void finalPointsEarned(int *u, double t) {		//Assigns value of points earned using a pointer.

	*u = t * 12;


}

/*												//Test stub to check that program works
int testStub(int p) {

	cout << "The converted points earned: ";
	cout << p << "points" << endl;

}
*/


