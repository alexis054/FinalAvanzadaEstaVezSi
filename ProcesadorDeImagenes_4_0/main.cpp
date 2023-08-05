#include <QApplication>
#include <gestordearchivospnm.h>
#include <sistema.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Sistema sistema;
    sistema.ejecutar(&app);//se ejecuta el sistema

    return 0;
}
