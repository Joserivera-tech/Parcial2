#include "imagen.h"

Imagen::Imagen(QString folder)
{
    Img.load(folder);
    h=Img.height();
    w=Img.width();
}
int Imagen::GetColor(int x,int y, char tipe){
    color = Img.pixelColor(x,y);
    if(tipe=='G'){
        return color.green();
    }
    else if(tipe == 'B'){
        return color.blue();
    }
    else if(tipe == 'R'){
        return color.red();
    }
    else return 0;
}
