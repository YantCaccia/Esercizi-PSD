#include "auto.h"
#include "list.h"

typedef struct garage* Garage;

Garage newGarage(char* nome, char* indirizzo, int posti);
Garage insertCar(Garage garage, Car car);
Garage removeCar(Garage, int);
Garage forwardCar(Garage, int);
List listBySegment(Garage, int);
void printGarage(Garage);