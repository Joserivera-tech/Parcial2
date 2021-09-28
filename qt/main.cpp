#include <iostream>
#include "imagen.h"
using namespace std;

int main()
{
    Imagen *I;
    int h,w;

    I = new Imagen();
    h=I->h;
    w=I->w;
    I->GenerarMatColores(w,h);
    I->reSize(w,h);
    I->Im10x10();
    delete I;
    return 0;
}
