#ifndef DISTRICTMODEL_H
#define DISTRICTMODEL_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>

class DistrictModel : public QSqlRelationalTableModel
{
public:
    DistrictModel();
    DistrictModel(QObject *parent,QSqlDatabase db);
};

#endif // DISTRICTMODEL_H
