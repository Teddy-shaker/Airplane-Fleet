#include "CargoPlane.h"

// Mutators definition 
void CargoPlane::setMaxCargoWeight(int s)
{
	maxCargoWeight = s;
}

CargoPlane* CargoPlane::addNewCargoPlane() {
    string manufacturer, model;
    int yearBuilt, flightHours, maxCargoWeight;

    // Ask the user for data
    cout << "Enter name of manufacturer: ";
    getline(cin, manufacturer);
    cout << "Enter model: ";
    getline(cin, model);
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
    cout << "Enter maximum cargo weight: ";
    cin >> maxCargoWeight;
    while (maxCargoWeight < 0)
    {
        cout << "Enter valid year built: ";
        cin >> maxCargoWeight;
    }
    cin.ignore();

    return new CargoPlane(manufacturer, model, yearBuilt, flightHours, maxCargoWeight);
}

// Accessors
int CargoPlane::getMaxCargoWeight() const
{
    return maxCargoWeight;
}

// Override getDescription() to provide specific description for CargoPlane
string CargoPlane::getDescription() const
{
    return Airplane::getDescription() + ", max cargo: " +
        to_string(maxCargoWeight);
}
