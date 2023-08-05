#include "sistema.h"

Sistema::Sistema()
{

}

void Sistema::ejecutar(QApplication *pPtrApp)
{
    unsigned int opcion=1;
    string raiz="../ProcesadorDeImagenes_4_0/";

    while(opcion <=4)
    {
        ui.mostrarDir();//llamo a que se muestren las carpetas en la interfaz
        opcion=ui.getOpcion(); //obtengo la opcion escogida por el usuario

        switch (opcion){//segun la opcion selecciono la ruta del directorio
        case 1:
        {
            Dir = raiz + "grupo_imagenes_1/";
            break;
        }
        case 2:
        {
            Dir = raiz + "grupo_imagenes_2/";
            break;
        }
        case 3:
        {
           Dir = raiz + "grupo_imagenes_3_corruptas/";
            break;
        }
        case 4:
        {
            Dir = raiz + "ij_image_samples/";
            break;
        }
        case 5:
        {
            Dir = raiz + "Nuevas/";
            break;
        }
        case 6:
        {
            cout<< " Decidio Salir del programa! "<<endl;
            exit(0);
            break;
        }
        }

      setDir(Dir);//setdir establece la lista de archivos junto a la lista de rutas
      ui.mostrarListaImagenes(getListaDeArchivos());//muestra la lista de imagenes

      graf.setListaDeArchivos(listaDeArchivos);//le paso a graficador una lista de imagenes
      graf.setListaRutas(listaRutasDeArchivos);//le paso la lista de rutas
      graf.setImagen();

      ui.getKeyBindings();// muestro la lista de comandos
      graf.mostrar(pPtrApp);//muestro la imagen

      opcion=1;//establezco que opcion es 1
      listaDeArchivos.clear(); //limpio la lista de archivos
      listaRutasDeArchivos.clear(); //limpio la lista de rutas

    }
}

void Sistema::setDir(string pRutaDir)
{
    setListadoDeArchivos(pRutaDir);//cargo el vector

    listaRutasDeArchivos.resize(listaDeArchivos.size());// dimensiono el vector de rutas de imagenes

    for(int i=0; i< int(listaDeArchivos.size()); i++)
    {

        listaRutasDeArchivos[i]= Dir + listaDeArchivos[i];//asigno la ruta a cada imagen

    }

   }

void Sistema::setListadoDeArchivos(string pRutaDir) // carga el vector listaDeArchivos con strings con los nombres de las imagenes de un directorio
{
    DIR *dir = opendir(pRutaDir.c_str());

    if (dir != NULL)
    {

        string pto("."), ptopto("..");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
        {

            if( entry->d_name != pto and entry->d_name != ptopto )
            {
                listaDeArchivos.push_back(entry->d_name);


            }
        }
        closedir(dir);
    }
}


vector<string> Sistema::getListaDeArchivos()
{
    return listaDeArchivos;
}

vector<string> Sistema::getListaRutasDeArchivos()
{
    return listaRutasDeArchivos;
}
