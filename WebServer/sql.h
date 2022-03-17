#ifndef SQL_H
#define SQL_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

bool ConnectDB();
QSqlQuery InsertDB(int number_value);

#endif // SQL_H
