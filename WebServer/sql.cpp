#include "sql.h"

bool ConnectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("RVS");
    db.setUserName("root");
    db.setPassword("admin");
    if (!db.open()){
        qDebug() << "ERROR DB\r\n";
        return 0;
    }
    else {
        qDebug() << "OK DB\r\n";
        return 1;
    }
}

QSqlQuery InsertDB(int number_value){
    QSqlQuery query;
    QString strF =
            "call RVS.addNumber(%1);";

    QString str = strF.arg(number_value);   
    query.exec(str);
    return query;
}
