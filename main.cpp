#include <iostream>
#include <QImage>

using namespace std;

int main()
{
    string filename ="../AppImagenes/images/imagen.jpg";
    QImage im( filename.c_str());

    unsigned int pixelX=200;
    unsigned int pixelY=200;

    cout<<"Intensidad de rojo del pixel seleccionado "<<im.pixelColor(pixelX,pixelY).red()<<endl;
    cout<<"Intensidad de rojo del pixel seleccionado "<<im.pixelColor(pixelX,pixelY).green()<<endl;
    cout<<"Intensidad de rojo del pixel seleccionado "<<im.pixelColor(pixelX,pixelY).blue()<<endl;

    cout<<"                                                       "<<endl;

    pixelX =190;
    pixelY =300;

    cout<<"Intensidad de rojo del pixel seleccionado "<<im.pixelColor(pixelX,pixelY).red()<<endl;
    cout<<"Intensidad de rojo del pixel seleccionado "<<im.pixelColor(pixelX,pixelY).green()<<endl;
    cout<<"Intensidad de rojo del pixel seleccionado "<<im.pixelColor(pixelX,pixelY).blue()<<endl;


    return 0;
}
