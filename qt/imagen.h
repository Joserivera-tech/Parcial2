#ifndef IMAGEN_H
#define IMAGEN_H
#include <QImage>
#include <QVector>

class Imagen: public QObject, public QImage
{

private:
    QImage Img;
    QColor color;


public:
    QVector<QVector<QVector<int>>> MatColor;
    int h, w;
    Imagen(QString folder);
    ~Imagen();
    int GetColor(int x,int y, char tipe);
    void GenerarMatColores(int x, int y);
};

#endif // IMAGEN_H
