#ifndef IMAGEN_H
#define IMAGEN_H
#include <QImage>
#include <QVector>
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
    unsigned int h, w;
    Imagen(QString folder);
    ~Imagen();
    int GetColor(unsigned int x, unsigned int y,char tipe);
    void GenerarMatColores(unsigned int x,unsigned int y);
    void GetMat10x10(unsigned int w,unsigned int h);
    void Prom(unsigned int x, unsigned int y, unsigned int dx, unsigned int dy);
    void Im10x10();
};

#endif // IMAGEN_H
