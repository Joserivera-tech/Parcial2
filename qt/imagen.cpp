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

int Imagen::GetColor(unsigned long int x, unsigned long int y,char tipe){
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

void Imagen::GenerarMatColores(unsigned long int x, unsigned long int y){
    MatColor.resize(y);
    for(unsigned long int f=0;f<y;f++){
        MatColor[f].resize(x);
        for(unsigned long int c=0;c<x;c++){
            MatColor[f][c].resize(3);
        }
    }

    for(unsigned int f=0;f<y;f++){
        for(unsigned long int c=0;c<x;c++){
            MatColor[f][c][0]=GetColor(c,f,'R');
            MatColor[f][c][1]=GetColor(c,f,'G');
            MatColor[f][c][2]=GetColor(c,f,'B');
        }
    }
}

void Imagen::GetMat10x10(unsigned long int w, unsigned long int h){
    unsigned int Dx=w/10, Dy=h/10;
    unsigned long int x, y;
    float Px, Py, Dfx=w/10.0,Dfy=h/10.0;
    if(w>=10 && h>=10){
        for(unsigned int f=0;f<10;f++){
            for(unsigned int c=0;c<10;c++){
                Px=float(c)*Dfx; Py=float(f)*Dfy;
                if(Px-floor(Px)<0.5) x=floor(Px);
                else  x=ceil(Px);
                if(Py-floor(Py)<0.5) y=floor(Py);
                else y=ceil(Py);
                Prom(x,y,Dx,Dy,c,f);
                cout << x <<' '<<y << endl;
            }
        }
    }


}

void Imagen::Prom(unsigned long int x, unsigned long int y, unsigned int dx, unsigned int dy, unsigned long int Mx, unsigned long int My){
    unsigned int Sr=0, Sg=0, Sb=0; //sumas de colores
    for(unsigned long int f=y;f<h && f<y+dy;f++){
        for(unsigned long int c=x;c<w && c<x+dx;c++){
            Sr+=MatColor[f][c][0];
            Sg+=MatColor[f][c][1];
            Sb+=MatColor[f][c][2];
        }
    }
    if(Sr/(dx*dy)==255) Mat10x10[My][Mx][0]=Sr/(dx*dy)-1;
    else Mat10x10[My][Mx][0]=Sr/(dx*dy);
    if(Sg/(dx*dy)==255) Mat10x10[My][Mx][1]=Sg/(dx*dy)-1;
    else Mat10x10[My][Mx][1]=Sg/(dx*dy);
    if(Sb/(dx*dy)==255) Mat10x10[My][Mx][2]=Sb/(dx*dy)-1;
    else Mat10x10[My][Mx][2]=Sb/(dx*dy);
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
