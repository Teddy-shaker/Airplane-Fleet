// Description:
// This program uses three classes, one base class Airplane and two derived 
// classes, CargoPlane and PassengerPlane. The program's functionality
// involves: creating objects of CargoPlane and/or PassengerPlane classes 
// and storing them in the fleet (a vector of pointers),
// user's access to modifying data of in the objects, removing objects, 
// and displaying them on the screen


#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include"Airplane.h"
#include"CargoPlane.h"
#include"PassengerPlane.h"

using namespace std;

// function prototypes
void fly(vector<Airplane*>& Flee);
void remove(vector<Airplane*>& Flee);
int findAirPlane(vector<Airplane*>& Fleet);
void displayFleet(vector<Airplane*>& Fleet);
char getAirplaneModel();
void displayHelp();
bool confirmYN(string promptText);

// main function 
int main()
{

	vector<Airplane*> fleet;

	bool keepRunning = true;


	while (keepRunning)
	{
		string command;
		cout << "Enter command: ";
		getline(cin, command);


		if (command == "a" || command == "A")
		{
			Airplane* plane = nullptr;
			char airplaneModel = getAirplaneModel(); // determine what plane to create 
			if (airplaneModel == 'c' || airplaneModel == 'C')
			{
				plane = CargoPlane::addNewCargoPlane();
				if (plane != nullptr)
				{
					fleet.push_back(plane);
				}

			}
			else if (airplaneModel == 'p' || airplaneModel == 'P')
			{
				plane = PassengerPlane::addNewPassengerPlane();
				if (plane != nullptr)
				{
					fleet.push_back(plane);
				}
			}
			else {
				cout << "Invalid airplane type!\n";
			}


		}
		else if (command == "p" || command == "P") {
			displayFleet(fleet);
		}
		else if (command == "r" || command == "R") {
			remove(fleet);
		}
		else if (command == "f" || command == "F") {
			fly(fleet);
		}
		else if (command == "h" || command == "H") {
			displayHelp();
		}
		else if (command == "q" || command == "Q") {
			keepRunning = !confirmYN("Are you sure you want exit the program? ");

		}
		else {
			cout << "Invalid command.\n";;
		}
	}
	for (Airplane* plane : fleet)
	{
		delete plane;
	}
	return 0;
}

// this function retrieves a char to determine a type of a plane to produce
char getAirplaneModel()
{
	char choice;
	cout << "Enter type of airplane (c = cargo, p = passenger): ";
	cin >> choice;
	cin.ignore();
	return choice;
}

// this function finds airplane in the vector of pointer to use in in function
// remove or fly
int findAirPlane(vector<Airplane*>& fleet, int ID) {
	for (int i = 0; i < fleet.size(); ++i) {
		int tempID = fleet[i]->getAirplane_ID(); // search for the desired ID
		if (tempID == ID) {
			// Return the index of the found airplane
			return i;
		}
	}

	// Return -1 if the airplane with the given ID is not found in the fleet
	return -1;
}


// Function for fly implementation 
void fly(vector<Airplane*>& Fleet)
{
	int ID;
	int hours;
	cout << "Which airplane do you want to fly? "; // get the ID of a plane 
	cin >> ID;
	cout << "Length of flight (hours)?"; // get hours(length) to add to the existing a
	cin >> hours;
	cin.ignore();

	int index = findAirPlane(Fleet, ID); 
	// checks if the airplane is the list
	if (index == -1)
	{
		cout << "Airplane " << ID << " not found" << endl;
	}
	else
	{
		int currentHours = Fleet[index]->getFlightHours(); // get current flight hours
		int NewHours = hours + currentHours; //create new hours with the hours we want to add
		Fleet[index]->setFlightHours(NewHours); //set new hours for the plane 

	}


}



// implementation of the remove function 
//this function is similar to the fly function in a way that it calls the findAirPlane function
void remove(vector<Airplane*>& Fleet)
{
	int ID;
	cout << "Which airplane do you want to remove? ";
	cin >> ID;
	cin.ignore();

	int index = findAirPlane(Fleet, ID);

	if (index == -1)
	{
		cout << "Airplane " << ID << " not found" << endl;
	}
	else
	{
		cout << "Removal complete: Airplane [" << Fleet[index]->getDescription() << "] has been removed." << endl; 
		delete Fleet[index]; //deleting the plane
		Fleet.erase(Fleet.begin() + index);    // using iterator to access the element 

	}

}

// implematation of the display fleet function 
void displayFleet(vector<Airplane*>& Fleet)
{
	cout << "Current fleet contains " << Fleet.size() << " airplane(s):" << endl;
	for (int i = 0; i < Fleet.size(); i++) // go thru the vecor and display it
	{
		cout << Fleet[i]->getDescription() << endl;
	}
}

// implementation of the display help function 
void displayHelp()
{
	cout << "Supported commands:" << endl;
	cout << "   a   Add a new airplane to the fleet." << endl;
	cout << "   f   Fly a plane in the fleet." << endl;
	cout << "   h   Print help text." << endl;
	cout << "   p   Print fleet information." << endl;
	cout << "   q   Quit (end the program)." << endl;
	cout << "   r   Remove airplane from the fleet." << endl;
}

// the function from your previous labs to implement the confirm if the user wants to exit the program 
bool confirmYN(string promptText)
{
	string inputString;
	bool confirmationValue = false;
	bool inputIsOK = false;

	do
	{
		// input from user 
		cout << promptText;
		getline(cin, inputString);

		if (inputString == "y" || inputString == "Y")
		{
			confirmationValue = true;
			inputIsOK = true;
		}
		else if (inputString == "n" || inputString == "N")
		{
			confirmationValue = false;
			inputIsOK = true;
		}
		else
		{
			cout << "Invalid input:  " << inputString << ".  Please input y or n." << endl;
		}
	} while (inputIsOK == false);
	return confirmationValue;

} // (end function 'confirmYN')