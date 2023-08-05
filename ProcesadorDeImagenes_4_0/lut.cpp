#include "lut.h"

Lut::Lut()
{
    lut.resize(256); //hago un resize para las intensidades y uno para datos basura
  for(unsigned int i=0;i<lut.size();++i)
  {
      lut[i].resize(4);//hago un resize por cada color y una intensidad
  }

}

void Lut::cargar(int pNum)
{
    string dirArchivoLut="../ProcesadorDeImagenes_4_0/grupo_luts/";

    if(pNum==1)// en funcion de pNum elijo que tabla voy a usar
    {
        dirArchivoLut=dirArchivoLut + "glow.lut";

    }

    if(pNum==2)
    {
        dirArchivoLut=dirArchivoLut + "Turbo.lut";
    }

    ifstream archi;
    string aux;

    archi.open(dirArchivoLut);//abro el archivo lut

    if(archi.is_open()) // si el archivo se abre
    {
       getline(archi,aux,'\n');
       for(unsigned int i=0;i<lut.size();++i)
       {
           for(unsigned int j=0;j<lut[0].size();++j)
           {
               archi>>lut[i][j];//cargo la imagen, en la primer fila se cargan las intensidades y en el resto RGB

           }
       }
    }
    else  cout<<"no se pudo abrir el archivo";
    archi.close();
}

void Lut::modificarimg(Imagen &pImagen)
{
    int R,G,B;
    if(pImagen.getFormato()=="P2" or pImagen.getFormato()=="P5")//escala de grises unicamente
    {
        for(int i=0;i<pImagen.getAlto();++i)
        {
            for(int j=0;j<pImagen.getAncho();++j)
            {
                R=lut[pImagen.getPixel(i,j).intensidad()][1];
                G=lut[pImagen.getPixel(i,j).intensidad()][2];
                B=lut[pImagen.getPixel(i,j).intensidad()][3];

                pImagen.ModificarPixelTerna(i,j,R,G,B);//cargo la imagen
            }
        }
    }
}
