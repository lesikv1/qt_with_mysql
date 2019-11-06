#include "countrymodel.h"

CountryModel::CountryModel()
{

}

CountryModel::CountryModel(QObject *parent, QSqlDatabase db)
{
    setTable("country");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    select();

    setHeaderData( 0, Qt::Horizontal,"Id");
    setHeaderData( 1, Qt::Horizontal,"Country");
    setHeaderData( 2, Qt::Horizontal,"Citizenship");

}

