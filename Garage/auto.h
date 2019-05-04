typedef struct car* Car;

char* getNome(Car);
int getYear(Car);
int getSegment(Car);
Car newCar(char* nome, int anno, int seg);