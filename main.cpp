#include <fstream>
#include <map>
#include <iostream>
using namespace std;

int main() 
{
    ifstream file("210-final-1-FA25.txt");
    map<string, int> airportFlightsCount;
    string originAirport;
    string destinationAirport;
    int maxFlightsCount = 0;

    while (file >> originAirport >> destinationAirport) 
    {
        airportFlightsCount[originAirport]++;
        airportFlightsCount[destinationAirport]++;
    }

    file.close();

    cout << "Airport Flight Counts:" << endl;
    for (auto &p : airportFlightsCount)
    {
        cout << "\t" << p.first << ": " << p.second << endl;

        if (p.second >= maxFlightsCount) 
        {
            maxFlightsCount = p.second;
        }
    }

    cout << endl << "Busiest Airport Counts:" << endl;
    for (auto &p : airportFlightsCount)
    {
        if (p.second == maxFlightsCount)
        {
            cout << "\t" << p.first << ": " << p.second << endl;
        }
    }

    return 0;
}

// Milestone 2