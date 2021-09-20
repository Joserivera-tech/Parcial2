#include <iostream>
#include "imagen.h"
using namespace std;

int main()
{
    Imagen *I;
    int h,w;
    I = new Imagen(":/new/prefix1/Mov lados.png");
    h=I->h;
    w=I->w;
    for(int f=0;f<h;f++){
        for(int c=0;c<w;c++){
            cout << I->GetColor(c,f,'R') << "-" << I->GetColor(c,f,'G')<< "-" << I->GetColor(c,f,'B');
            cout << "/";
        }
        cout << endl;
    }
    delete I;
    return 0;
}
