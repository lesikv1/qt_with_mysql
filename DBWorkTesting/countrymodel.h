#ifndef COUNTRYMODEL_H
#define COUNTRYMODEL_H

#include <QtSql>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>


class CountryModel : public QSqlRelationalTableModel
{
public:
    CountryModel();
    CountryModel(QObject *parent,QSqlDatabase db);
};

#endif // COUNTRYMODEL_H
