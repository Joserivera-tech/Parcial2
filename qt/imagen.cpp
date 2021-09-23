#include "imagen.h"

Imagen::Imagen(QString folder)
{
    Img.load(folder);
    h=Img.height();
    w=Img.width();
}

Imagen::~Imagen(){

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

void Imagen::GenerarMatColores(int x, int y){
    MatColor.resize(y);
    for(int f=0;f<y;f++){
        MatColor[f].resize(x);
        for(int c=0;c<x;c++){
            MatColor[f][c].resize(3);
        }
    }

    for(int f=0;f<y;f++){
        for(int c=0;c<x;c++){
            MatColor[f][c][0]=GetColor(c,f,'R');
            MatColor[f][c][1]=GetColor(c,f,'G');
            MatColor[f][c][2]=GetColor(c,f,'B');
        }
    }
}
