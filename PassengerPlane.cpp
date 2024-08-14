#include "PassengerPlane.h"

// Mutators
void PassengerPlane::setMaxNumberOfPassengers(int passengers)
{
	maxNumberOfPassengers = passengers;
}

// Implementation of the static member function addNewPassengerPlane()
PassengerPlane* PassengerPlane::addNewPassengerPlane() {
    string manufacturer, model;
    int yearBuilt, flightHours, maxNumberOfPassengers;

    // Ask the user for data
    cout << "Enter name of manufacturer: ";
    getline(cin,manufacturer);
    cout << "Enter model: ";
    getline(cin,model);
    cout << "Enter year built: ";
    cin >> yearBuilt;

    while (yearBuilt < 0)
    {
        cout << "Enter valid year built: ";
        cin >> yearBuilt;
    }
    cout << "Enter flight hours: ";
    cin >> flightHours;

    while (flightHours < 0)
    {
        cout << "Enter valid flight hours: ";
        cin >> flightHours;
    }

    cout << "Enter maximum Passenger count: ";
    cin >> maxNumberOfPassengers;

    while (maxNumberOfPassengers < 0)
    {
        cout << "Enter valid Passenger count: ";
        cin >> maxNumberOfPassengers;
    }
    cin.ignore();
    // Create and return a new PassengerPlane object with the provided data
    return new PassengerPlane(manufacturer, model, yearBuilt, flightHours, maxNumberOfPassengers);
}


// Accessors
int PassengerPlane::getMaxNumberOfPassengers() const
{
	return maxNumberOfPassengers;
}

string PassengerPlane::getDescription() const
{
	return Airplane::getDescription() + ", max passengers: " +
		to_string(maxNumberOfPassengers);
}