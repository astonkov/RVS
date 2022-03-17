#include <QCoreApplication>
#include "qserver.h"
#include "sql.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ConnectDB();
    QServer server;
    return a.exec();
}
