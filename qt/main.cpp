#include <iostream>
#include "imagen.h"
using namespace std;

int main()
{
    Imagen *I;
    I = new Imagen(":/new/prefix1/Mov lados.png");

    cout << I->GetColor(3,0, 'G') << endl;
    delete I;
    return 0;
}
