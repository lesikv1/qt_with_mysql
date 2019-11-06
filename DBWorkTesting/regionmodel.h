#ifndef REGIONMODEL_H
#define REGIONMODEL_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class RegionModel : public QSqlRelationalTableModel
{
public:
    RegionModel();
    RegionModel(QObject *parent,QSqlDatabase db);
};

#endif // REGIONMODEL_H
