#include "imagen.h"

Imagen::Imagen(QString folder)
{
    Img.load(folder);
    h=Img.height();
    w=Img.width();
    //Creacion de la nueva matriz
    Mat10x10.resize(10);
    for(unsigned int f=0;f<10;f++){
        Mat10x10[f].resize(10);
        for(unsigned int c=0;c<10;c++){
            Mat10x10[f][c].resize(3);
        }
    }
}

Imagen::~Imagen(){

}

int Imagen::GetColor(unsigned int x, unsigned int y,char tipe){
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

void Imagen::GenerarMatColores(unsigned int x, unsigned int y){
    MatColor.resize(y);
    for(unsigned int f=0;f<y;f++){
        MatColor[f].resize(x);
        for(unsigned int c=0;c<x;c++){
            MatColor[f][c].resize(3);
        }
    }

    for(unsigned int f=0;f<y;f++){
        for(unsigned int c=0;c<x;c++){
            MatColor[f][c][0]=GetColor(c,f,'R');
            MatColor[f][c][1]=GetColor(c,f,'G');
            MatColor[f][c][2]=GetColor(c,f,'B');
        }
    }
}

void Imagen::GetMat10x10(unsigned int w,unsigned int h){
    if(w>10 && h>10){
        for(unsigned int f=0;f<10;f++){
            for(unsigned int c=0;c<10;c++){
                if(f+1==10 && h%10!=0) Prom(c*(w/10),f*(h/10),w/10,h%10);
                else if(c+1==10 && w%10!=0) Prom(c*(w/10),f*(h/10),w%10,w/10);
                else if(f+1==10 && h%10!=0 && c+1==10 && w%10!=0) Prom(c*(w/10),f*(h/10),w%10,h%10);
                else Prom(c*(w/10),f*(h/10),w/10,h/10);
            }
        }
    }
    cout << "terminado" << endl;
}

void Imagen::Prom(unsigned int x, unsigned int y, unsigned int dx, unsigned int dy){
    unsigned int Sr=0, Sg=0, Sb=0; //sumas de colores
    for(unsigned int f=y;f<y+dy;f++){
        for(unsigned int c=x;c<x+dx;c++){
            Sr+=MatColor[f][c][0];
            Sg+=MatColor[f][c][1];
            Sb+=MatColor[f][c][2];
        }
    }
    if(Sr/(dx*dy)==255) Mat10x10[y/(h/10)][x/(w/10)][0]=Sr/(dx*dy)-1;
    else Mat10x10[y/(h/10)][x/(w/10)][0]=Sr/(dx*dy);
    if(Sg/(dx*dy)==255) Mat10x10[y/(h/10)][x/(w/10)][1]=Sg/(dx*dy)-1;
    else Mat10x10[y/(h/10)][x/(w/10)][1]=Sg/(dx*dy);
    if(Sb/(dx*dy)==255) Mat10x10[y/(h/10)][x/(w/10)][2]=Sb/(dx*dy)-1;
    else Mat10x10[y/(h/10)][x/(w/10)][2]=Sb/(dx*dy);
}

void Imagen::Im10x10(){
    string salida="";
    salida.push_back( '{');
    for(int i =0;i<Mat10x10.size();i++){
        salida.push_back('{');
        for(int j=0;j<Mat10x10[i].size();j++){
            salida.push_back('{');
            salida+=to_string(Mat10x10[i][j][0]);
            salida+=",";
            salida+=to_string(Mat10x10[i][j][1]);
            salida+=",";
            salida+=to_string(Mat10x10[i][j][2]);
            salida.push_back('}');
            if(j<Mat10x10[i].size()-1) salida.push_back(',');
        }
        salida.push_back('}');
        if(i<Mat10x10[i].size()-1) salida.push_back(',');
    }
    salida.push_back('}');
    cout << salida << endl;
    cout << salida.length() << endl;
}
