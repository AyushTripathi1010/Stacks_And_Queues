// GFG LINK: https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
/*
Problem: Petrol Pump Tour

The structure of petrolPump is:
struct petrolPump
{
    int petrol;
    int distance;
};

You are required to complete this method.
*/

#include <iostream>

struct petrolPump
{
    int petrol;
    int distance;
};

class PetrolPumpTour
{
public:
    // Function to find the starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        int start = 0;
        int currentFuelCapacity = 0, fuelShortage = 0;

        for (int i = 0; i < n; i++)
        {
            currentFuelCapacity += p[i].petrol - p[i].distance;

            if (currentFuelCapacity < 0)
            {
                // If there is a fuel shortage, the current starting point is not viable.
                // Move to the next petrol pump and reset the fuel capacity to 0,
                // storing the previous shortage in fuelShortage.
                start = i + 1;
                fuelShortage += currentFuelCapacity;
                currentFuelCapacity = 0;
            }
        }

        // If the total fuel available with the shortage is non-negative,
        // then a successful tour is possible.
        if (currentFuelCapacity + fuelShortage >= 0)
            return start;

        // If no successful tour is possible, return -1.
        return -1;
    }
};

int main()
{
    // You can add test cases here to verify the functionality of the code.
    return 0;
}
