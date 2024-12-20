#include <iostream>
#include <string>
#include "Ship.h"
#include "CruiseShip.h"
#include "CargoShip.h"
using namespace std;


int main()
{
    // Create an array of Ship pointers, initialized with
    // the addresses of 3 dynamically allocated objects.
    Ship *ships[3] = { new Ship("SS United States", "1952"),
                   new CruiseShip("Quantum of the Seas", "2014", 4905),
                   new CargoShip("CMA CGM Antoine", "2015", 175000)
                    };

    // Call each object's print function using polymorphism.
    for (int index=0; index < 3; index++)
    {
        ships[index]->print();
        cout << "----------------------------\n";
        
        delete ships[index];     //release memory (avoid memory leak)
        ships[index] = nullptr;   //avoid dangling pointer
    }
    
           
    system("PAUSE");
    return 0;
}
