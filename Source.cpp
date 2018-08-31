/*
Paul Johnston, Section 3, paulthegreat01@gmail.com
Purpose: To help user decide at which restaurant they will eat.
Input:
	User selection of what they want to do with the list of restaurants 
		i.e. add, remove, shuffle, cut, display, start tournament, quit program
	Names of restaurants
	Number of restaurants user wants to cut
	Which restaurant they prefer in the tournament mode

Output:
	Current list of restaurants
	Whether or not a certain restaurant has already been added
	Whether or not a certain restaurant has already been removed
	Winner of restaurant tournament

Test 1:
	Input:
		-23
		2
		Chili's
		2
		Chili's
		2
		Panda Express
		2
		Cafe Rio
		1
		4
		5
		4
		1
		1
		0

	Expected output:
		"Enter your selection now: "
		"INVALID SELECTION.  Please try again."
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Chili's has been added." 
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"That restaurant is already on the list, you can not add it again."
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Panda Express has been added."
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Cafe Rio has been added."
		"Enter your selection now: "
		"Here are the current restaurants:"
			"Chili's"
			"Panda Express"
			"Cafe Rio"
		"Enter your selection now: "
		"How many restaurants should be taken from the top and put on the bottom? "
		"The restaurants can not be cut there, there are only 3 restaurants in the list."
		"Enter your selection now: "
		"How many restaurants should be taken from the top and put on the bottom? "
		"Enter your selection now: "
		"Here are the current restaurants:"
			"Panda Express"
			"Cafe Rio"
			"Chili's"
		"GOODBYE!"

Test 2:
	Input:
		2
		Wendy's
		2
		Taco Bell
		2
		Tocanos
		5
		2
		Subway
		1
		5
		1
		0

	Expected output:
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Wendy's has been added." 
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Taco Bell has been added."
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Tocanos has been added."
		"Enter your selection now: "
		"The current tournament size (3) is not a power of two (2, 4, 8...)."
		"A shuffle is not possible. Please add or remove resturants."
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Subway has been added."
		"Enter your selection now: "
		"Here are the current restaurants:"
			"Wendy's"
			"Taco Bell"
			"Tocanos"
			"Subway"
		"Enter your selection now: "
		"Enter your selection now: "
		"Here are the current restaurants:"
			"Tocanos"
			"Wendy's"
			"Subway"
			"Taco Bell"
		"GOODBYE!"

Test 3:
	Input:
		2
		Wendy's
		2
		Taco Bell
		2
		Tocanos
		2
		Subway
		2
		Costa Vida
		6
		3
		Joe's Barn Grill
		3
		Tocanos
		6
		1
		2
		1
		0

	Output:
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Wendy's has been added." 
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Taco Bell has been added."
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Tocanos has been added."
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Subway has been added."
		"Enter your selection now: "
		"What is the name of the restaurant you want to add? "
		"Costa Vida has been added."
		"Enter your selection now: "
		"The current tournament size (5) is not a power of two (2, 4, 8...)."
		"A tournament is not possible. Please add or remove resturants."
		"Enter your selection now: "
		"That restaurant is not on the list, you can not remove it."
		"Enter your selection now: "
		"What is the name of the restaurant you want to remove? "
		"Tocanos has been removed."
		"Enter your selection now: "
		"Round: 1"
		"Type "1" if you prefer Wendy's or
		 type "2" if you prefer Taco Bell
		"Choice: "
		"Type "1" if you prefer Subway or
		 type "2" if you prefer Costa Vida
		"Choice: "
		"Round: 2"
		"Type "1" if you prefer Wendy's or
		 type "2" if you prefer Costa Vida
		"Choice: "
		"The winning restaurant is Wendy's"
		"Enter your selection now: "
		"GOODBYE!"
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

const int CUT_IN_HALF = 2;
const int OFFSET_VALUE = 1;

bool FindRestaurant(string certainRestaurant, const vector<string>& currentRestaurants){
	bool foundRestaurant = false;

	for (unsigned int i = 0; i < currentRestaurants.size(); ++i){
		if (currentRestaurants.at(i) == certainRestaurant) {
			foundRestaurant = true;
		}
	}

	return foundRestaurant; 
}

bool FindIfIsPowerOfTwo(const vector<string>& currentRestaurants){
	bool isPowerOfTwo = false;
	double sizeOfList = 0.0;

	sizeOfList = currentRestaurants.size();

	while (sizeOfList >= 2) { 
		if (sizeOfList == 2){
			isPowerOfTwo = true;
		}
		sizeOfList = sizeOfList / CUT_IN_HALF;
	}

	return isPowerOfTwo;
}

void DisplayRestaurants(const vector<string>& currentRestaurants){

	cout << "Here are the current restaurants:" << endl << endl;

	for (unsigned int i = 0; i < currentRestaurants.size(); ++i){
		cout << "\t\"" << currentRestaurants.at(i) << "\"" << endl;
	}
	cout << endl;

	return;
}

void AddRestaurant(vector<string>& currentRestaurants){
	string newRestaurant = " ";
	bool foundRestaurant = false;

	cout << "What is the name of the restaurant you want to add? ";
	cin.ignore(100000, '\n');
	getline(cin, newRestaurant);
	cout << endl;

	foundRestaurant = FindRestaurant(newRestaurant, currentRestaurants);

	if (foundRestaurant == true){
		cout << "That restaurant is already on the list, you can not add it again." << endl << endl;
	}
	if (foundRestaurant == false) {
		currentRestaurants.push_back(newRestaurant);
		cout << newRestaurant << " has been added." << endl << endl;
	}

	return;
}

void RemoveRestaurant(vector<string>& currentRestaurants) {
	string removeRestaurant = " ";
	bool foundRestaurant = true;
	unsigned int indexOfRemoveRestaurant = 0;

	cout << "What is the name of the restaurant you want to remove? ";
	cin.ignore(100000, '\n');
	getline(cin, removeRestaurant);
	cout << endl;

	foundRestaurant = FindRestaurant(removeRestaurant, currentRestaurants);

	if (foundRestaurant == true){
		for (unsigned int i = 0; i < currentRestaurants.size(); ++i){
			if (currentRestaurants.at(i) == removeRestaurant){
				indexOfRemoveRestaurant = i;
			}
		}
		currentRestaurants.erase(currentRestaurants.begin() + indexOfRemoveRestaurant);
		cout << removeRestaurant << " has been removed." << endl << endl;
	}

	if (foundRestaurant == false) {
		cout << "That restaurant is not on the list, you can not remove it." << endl << endl;
	}

	return;
}

void CutRestaurants(vector<string>& currentRestaurants) {
	unsigned int cutAmount = 0;
	vector<string> cutRestaurants;

	cout << "How many restaurants should be taken from the top and put on the bottom? ";
	cin >> cutAmount;
	cout << endl << endl;

	if (cutAmount > currentRestaurants.size() - OFFSET_VALUE){ 
		cout << "The restaurants can not be cut there, there are only " << currentRestaurants.size() << 
			" restaurants in the list." << endl << endl;
	}
	else {
		for (unsigned int i = 0; i < cutAmount; ++i){
			cutRestaurants.push_back(currentRestaurants.at(i));
		}
		for (unsigned int i = 0; i < cutAmount; ++i) {
			currentRestaurants.erase(currentRestaurants.begin() + 0);
		}
		for (unsigned int i = 0; i < cutAmount; ++i) {
			currentRestaurants.push_back(cutRestaurants.at(i));
		}
	}
	return;
}

void ShuffleRestaurants(vector<string>& currentRestaurants) {
	bool isPowerOfTwo = false;
	vector<string> tempRestaurants;
	unsigned int sizeOfList = 0;

	isPowerOfTwo = FindIfIsPowerOfTwo(currentRestaurants);
	sizeOfList = currentRestaurants.size();

	if (isPowerOfTwo == false){
		cout << "The current tournament size (" << currentRestaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
			cout << "A shuffle is not possible. Please add or remove resturants." << endl;
	}
	else {
		for (unsigned int i = 0; i < sizeOfList / CUT_IN_HALF; ++i) { 
			tempRestaurants.push_back(currentRestaurants.at(0));
			currentRestaurants.erase(currentRestaurants.begin() + 0);
		}
		for (unsigned int i = 1; i < sizeOfList; ++i) {
			currentRestaurants.insert(currentRestaurants.begin() + i, tempRestaurants.at(0));
			tempRestaurants.erase(tempRestaurants.begin() + 0);
			++i;
		}
	}
	cout << endl;
	return;
}

void StartTournament(vector<string>& currentRestaurants) {
	const int FIRST_RESTAURANT = 1;
	const int SECOND_RESTAURANT = 2;
	bool isPowerOfTwo = false;
	double sizeOfList = 0.0;
	double sizeOfTempList = 0.0;
	unsigned int numRounds = 0;
	unsigned int userChoice = 0;
	vector<string> tempRestaurants;

	isPowerOfTwo = FindIfIsPowerOfTwo(currentRestaurants);
	
	if (isPowerOfTwo == false){
		cout << "The current tournament size (" << currentRestaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A tournament is not possible. Please add or remove resturants." << endl;
	}

	else {
		sizeOfList = currentRestaurants.size();

		while (sizeOfList >= 2) { 
			++numRounds;
			if (sizeOfList == 2){
				break;
			}
			sizeOfList = sizeOfList / CUT_IN_HALF;
		}

		for (unsigned int i = 0; i < currentRestaurants.size(); ++i) {
			tempRestaurants.push_back(currentRestaurants.at(i));
		}

		for (unsigned int round = 1; round <= numRounds; ++round) {
			cout << "Round: " << round << endl << endl;
			sizeOfTempList = tempRestaurants.size();

			for (unsigned int i = 0; i < sizeOfTempList / CUT_IN_HALF; ++i) { 
				do { 
					cout << "Type \"1\" if you prefer " << tempRestaurants.at(i) << " or" << endl;
					cout << "type \"2\" if you prefer " << tempRestaurants.at(i + OFFSET_VALUE) << endl;
					cout << "Choice: ";
					cin >> userChoice;
					cout << endl;
				} while (userChoice != FIRST_RESTAURANT && userChoice != SECOND_RESTAURANT);

				if (userChoice == FIRST_RESTAURANT){ 
					tempRestaurants.erase(tempRestaurants.begin() + (i + OFFSET_VALUE));
				}
				else if (userChoice == SECOND_RESTAURANT) { 
					tempRestaurants.erase(tempRestaurants.begin() + (i));
				}
			}
		}
		cout << "The winning restaurant is " << tempRestaurants.at(0) << endl;
	}

	cout << endl;
	return;
}

int main() {
	const int QUIT_OPTION = 0;
	const int DISPLAY_OPTION = 1;
	const int ADD_OPTION = 2;
	const int REMOVE_OPTION = 3;
	const int CUT_OPTION = 4;
	const int SHUFFLE_OPTION = 5;
	const int TOURNAMENT_OPTION = 6;

	unsigned int userOption = -1;
	vector <string> currentRestaurants;

	cout << "Welcome to the restaurant battle!" << endl << endl << endl;

	do {
		cout << "Please select one of the following options:" << endl << endl;
		cout << "0 - Quit the program" << endl;
		cout << "1 - Display all restaurants" << endl;
		cout << "2 - Add a restaurant" << endl;
		cout << "3 - Remove a restaurant" << endl;
		cout << "4 - \"Cut\" the list of restaurants" << endl;
		cout << "5 - \"Shuffle\" the list of restaurants" << endl;
		cout << "6 - Begin the tournament" << endl << endl;

		cout << "Enter your selection now: ";
		cin >> userOption;
		cout << endl;

		if (cin.fail() || userOption < QUIT_OPTION || userOption > TOURNAMENT_OPTION) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "INVALID SELECTION.  Please try again." << endl << endl;
			userOption = -1;
		}

		else if (userOption == DISPLAY_OPTION){
			DisplayRestaurants(currentRestaurants);
		}

		else if (userOption == ADD_OPTION){
			AddRestaurant(currentRestaurants);
		}

		else if (userOption == REMOVE_OPTION){
			RemoveRestaurant(currentRestaurants);
		}

		else if (userOption == CUT_OPTION){
			CutRestaurants(currentRestaurants);
		}

		else if (userOption == SHUFFLE_OPTION){
			ShuffleRestaurants(currentRestaurants);
		}

		else if (userOption == TOURNAMENT_OPTION){
			StartTournament(currentRestaurants);
		}

	} while (userOption != QUIT_OPTION);

	cout << "GOODBYE!" << endl;

	system("pause");
	return 0;
}
