#include <iostream>
#include "imagen.h"
using namespace std;

int main()
{
    Imagen *I;
    int h,w;
    I = new Imagen(":/descarga.png");
    h=I->h;
    w=I->w;
    I->GenerarMatColores(w,h);
    I->GetMat10x10(w,h);
    I->Im10x10();
    delete I;
    return 0;
}
/*
void ImpMat(unsigned int matriz[10][10][3]){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
        if(i%2==0)  neopixel.setPixelColor(j+(i*10), matriz[i][j][0], matriz[i][j][1], matriz[i][j][2]);
        else neopixel.setPixelColor((i+1*10)-(j+1), matriz[i][j][0], matriz[i][j][1], matriz[i][j][2]);
    }
  }

  neopixel.show();
  delay(2000);
  neopixel.clear();
}
*/
