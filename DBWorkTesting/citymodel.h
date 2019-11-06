#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class CityModel : public QSqlRelationalTableModel
{
public:
    CityModel();
    CityModel(QObject *parent,QSqlDatabase db);
};

#endif // CITYMODEL_H
