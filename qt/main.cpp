#include <iostream>
#include "imagen.h"
using namespace std;

int main()
{
    Imagen *I;
    int h,w;
    I = new Imagen(":/prueba.png");
    h=I->h;
    w=I->w;
    I->GenerarMatColores(w,h);
    I->GetMat10x10(w,h);
    I->Im10x10();
    delete I;
    return 0;
}
