#include <iostream>
#include "imagen.h"
using namespace std;

int main()
{
    Imagen *I;
    int h,w;
    int x=0;
    int y=0;
    I = new Imagen(":/new/prefix1/Mov lados.png");
    h=I->h;
    w=I->w;
    I->GenerarMatColores(w,h);
    for(int f=0;f<h;f++){
        for(int c=0;c<w;c++){
            if(I->GetColor(c,f,'R')!=I->MatColor[f][c][0]) cout << x <<" " << y << ' '<< 'R'<< endl;
            if(I->GetColor(c,f,'G')!=I->MatColor[f][c][1]) cout << x <<" " << y << ' '<< 'G'<< endl;
            if(I->GetColor(c,f,'B')!=I->MatColor[f][c][2]) cout << x <<" " << y << ' '<< 'B'<< endl;
        }
    }
    delete I;
    return 0;
}
