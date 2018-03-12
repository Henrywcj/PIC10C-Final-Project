
#include "mainwindow.h"


/*I(Yuan Zhang) pledge that I have neither given nor received unauthorized assistance on this assignment*/

int main(int argc, char *argv[])
{
/*set seed for our random process and reate a main window widget*/
srand(time(NULL));
QApplication app(argc, argv);
MainWindow w;

return app.exec();
}
