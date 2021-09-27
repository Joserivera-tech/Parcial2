#ifndef IMAGEN_H
#define IMAGEN_H
#include <QImage>
#include <QVector>
#include <math.h>
#include <iostream>

using namespace std;

class Imagen: public QObject, public QImage
{

private:
    QImage Img;
    QColor color;
    QVector<QVector<QVector<int>>> Mat10x10;


public:
    QVector<QVector<QVector<int>>> MatColor;
    unsigned long int h, w;
    Imagen(QString folder);
    ~Imagen();
    int GetColor(unsigned long int x, unsigned long int y,char tipe);
    void GenerarMatColores(unsigned long int x, unsigned long int y);
    void GetMat10x10(unsigned long int w, unsigned long int h);
    void Prom(unsigned long int x, unsigned long int y, unsigned int dx, unsigned int dy, unsigned long int Mx, unsigned long int My);
    void Im10x10();
};

#endif // IMAGEN_H
