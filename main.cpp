#include <fstream>
#include <map>
#include <iostream>
using namespace std;

void printAirports(const map<string, int> &, int, int);

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

    cout << "All airport traffic counts:" << endl;
    for (auto &p : airportFlightsCount)
    {
        cout << p.first << " " << p.second << endl;

        if (p.second >= maxFlightsCount) 
        {
            maxFlightsCount = p.second;
        }
    }

    cout << endl << "Busiest airports with count " << maxFlightsCount << ":" << endl;
    for (auto &p : airportFlightsCount)
    {
        if (p.second == maxFlightsCount)
        {
            cout << p.first << ": " << p.second << endl;
        }
    }

    cout << endl << "Airports with traffic in range [5, 8]:" << endl;
    printAirports(airportFlightsCount, 5, 8);

    cout << endl << "Airports with traffic in range [9, 12]:" << endl;
    printAirports(airportFlightsCount, 9, 12);

    return 0;
}

void printAirports(const map<string, int> &airportFlightsCount, int low, int high)
{
    for (const auto &p : airportFlightsCount) 
    {
        cout << "Airport: " << p.first << " Count: " << p.second << " Low: " << low << " High: " << high << endl;
        if (p.second > low && p.second < high) 
        {
            cout << p.first << ": " << p.second << endl;
        }
    }
}