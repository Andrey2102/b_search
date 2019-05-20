#include "array.h"
#include <cmath>
#include <QString>
#include <ctime>

void ARRAY::generate(){
    srand(time(NULL));
    A[0] = 2;
    for (int i = 1; i < SIZE; i++){
        A[i] = A[i - 1] + rand() % 3 + 1;
    }
}

ARRAY::ARRAY(int size){
    set_SIZE(size);
    A = new int [size];
    generate();
}

ARRAY::~ARRAY(){
    delete A;
}

void ARRAY::getArr(int *&B){
    for(int i = 0; i < SIZE; i++){
        B[i] = A[i];
    }
}
