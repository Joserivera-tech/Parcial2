#include "imagen.h"

Imagen::Imagen()
{

    string ing;
    cout << "Ingrese la direccion de la imagen:"<< endl;
    cin >> ing;
    QString folder=QString::fromStdString(ing);
    if(Img.load(folder)){
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
        cout << "Imagen cargada correctamente"<<endl;
    }
    else cout << "Imagen invalida"<<endl;
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

void Imagen::reSize(unsigned long int w, unsigned long int h){
    if(w<10 || h<10) sobreMuestreo();
    subMuestreo();
    cout << "Redimecionamiento con exito, su numa matriz de colores es:\n ";
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

void Imagen::subMuestreo(){
    unsigned int Dx=w/10, Dy=h/10;
    unsigned long int x, y;
    float Px, Py, Dfx=w/10.0,Dfy=h/10.0;
    for(unsigned int f=0;f<10;f++){
        for(unsigned int c=0;c<10;c++){
            Px=float(c)*Dfx; Py=float(f)*Dfy;
            if(Px-floor(Px)<0.5) x=floor(Px);
            else  x=ceil(Px);
            if(Py-floor(Py)<0.5) y=floor(Py);
            else y=ceil(Py);
            Prom(x,y,Dx,Dy,c,f);
        }
    }
}

void Imagen::sobreMuestreo(){
    QVector<QVector<QVector<int>>> New_mat;
    unsigned int nsize=1;
    while(w*nsize<10 || h*nsize<10){
        nsize++;
    }
    New_mat.resize((h*nsize));
    for(unsigned int f=0;f<(h*nsize);f++){
        New_mat[f].resize(w*nsize);
        for(unsigned int c=0;c<(w*nsize);c++){
            New_mat[f][c].resize(3);
        }
    }

    for(unsigned int f=0;f<h*nsize;f+=nsize){
        for(unsigned int c=0;c<w*nsize;c+=nsize){
            //relleno
            New_mat=fill(c,f,nsize,New_mat);
        }
    }
    MatColor.clear();
    MatColor=New_mat;
    h=New_mat.size();
    w=New_mat[0].size();
}

QVector<QVector<QVector<int>>> Imagen::fill(unsigned int x, unsigned int y,unsigned dif, QVector<QVector<QVector<int>>> mat){
    for(unsigned int f=y;f<y+dif;f++){
        for(unsigned int c=x;c<x+dif;c++){
            mat[f][c][0]=MatColor[y/dif][x/dif][0];
            mat[f][c][1]=MatColor[y/dif][x/dif][1];
            mat[f][c][2]=MatColor[y/dif][x/dif][2];
        }
    }
    return mat;
}
