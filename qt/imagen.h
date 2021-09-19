#ifndef IMAGEN_H
#define IMAGEN_H
#include <QImage>

class Imagen: public QObject, public QImage
{
private:
    QImage Img;
    QColor color;
    int h, w;

public:
    Imagen(QString folder);
    int GetColor(int x,int y, char tipe);
};

#endif // IMAGEN_H
