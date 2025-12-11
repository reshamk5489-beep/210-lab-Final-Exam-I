#include <fstream>
#include <map>
using namespace std;

int main() 
{
    ifstream file("210-final-1-FA25.txt");
    map<string, int> airportFlightsCount;
    string originAirport;
    string destinationAirport;

    while (file >> originAirport >> destinationAirport) 
    {
        airportFlightsCount[originAirport]++;
    }

    file.close();

    return 0;
}