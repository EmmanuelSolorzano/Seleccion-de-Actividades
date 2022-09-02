//g++ -o main main.cpp
//./main < inputs.txt
#include <iostream>
#include <string>
#include <vector>
#include "Actividad.h"
using namespace std;

const int NUM_ACTIVITYS = 11;
Actividad activityArray[NUM_ACTIVITYS];
vector<Actividad> solutionVector;

void swap(Actividad* a, Actividad* b){ 
    Actividad t = *a; 
    *a = *b; 
    *b = t; 
}

void sort(){
  for (int i = 0; i < NUM_ACTIVITYS; i++){
    for (int k = i; k < NUM_ACTIVITYS-1; k++){
      if(activityArray[i].finish > activityArray[k+1].finish){
        swap(activityArray[i], activityArray[k+1]);
      }
    }   
  }
}

void printArray(){
  for (int i = 0; i < NUM_ACTIVITYS; i++){
    activityArray[i].printActivity();
  }
}

void printSolution(){
  for (int i = 0; i < solutionVector.size(); i++){
    solutionVector[i].printActivity();
  }
}

void solution(){
  Actividad aux = activityArray[0];
  solutionVector.push_back(activityArray[0]);
  for (int i = 1; i < NUM_ACTIVITYS; i++){  
    if(aux.finish <= activityArray[i].start){
      solutionVector.push_back(activityArray[i]);
      aux = activityArray[i];
    }    
  }
}

int main(){
  string input,id,start,finish;
  int contador = 1, arrayPos = 0, verifyNumActivitys = 0;
  while(input != "exit" || verifyNumActivitys == NUM_ACTIVITYS){
    getline(cin,input);
    if(contador == 1){
      id = input;
    }
    else if(contador == 2){
      start = input;
    }
    else if(contador == 3){
      finish = input;
      contador = 0;
    }
    if(contador == 0){
      Actividad act(stoi(id), stoi(start), stoi(finish));
      activityArray[arrayPos] = act;
      arrayPos++;
    }
    contador++;
    verifyNumActivitys++;
  }
  sort();
  solution();
  printSolution();
  return 0;
}