#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <iostream>
using namespace std;

class Actividad {

public:
	int id;
	int start;
	int finish;
  Actividad();
  Actividad(int id, int start, int finish);
  void printActivity();
};

Actividad::Actividad(){
  this->id = 0;
  this->start = 0;
  this->finish = 0;
}

Actividad::Actividad(int id, int start, int finish) {
  this->id = id;
  this->start = start;
  this->finish = finish;
}

void Actividad::printActivity(){
  cout<<"ID: "<<this->id<<"\n Start: "<<this->start<<"\n Finish: "<<this->finish<<endl;
}

#endif
