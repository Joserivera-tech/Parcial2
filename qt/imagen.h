#ifndef IMAGEN_H
#define IMAGEN_H
#include <QImage>
#include <QVector>
#include <math.h>
#include <iostream>
#include <fstream>

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
    Imagen();
    ~Imagen();
    int GetColor(unsigned long int x, unsigned long int y,char tipe);
    void GenerarMatColores(unsigned long int x, unsigned long int y);
    void reSize(unsigned long int w, unsigned long int h);
    void Prom(unsigned long int x, unsigned long int y, unsigned int dx, unsigned int dy, unsigned long int Mx, unsigned long int My);
    void Im10x10();
    void sobreMuestreo();
    void subMuestreo();
    void escribir(string texto, string nombre);
    QVector<QVector<QVector<int>>> fill(unsigned int x, unsigned int y,unsigned dif, QVector<QVector<QVector<int>>> mat);
};

#endif // IMAGEN_H
