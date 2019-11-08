#include "citymodel.h"

CityModel::CityModel()
{

}

CityModel::CityModel(QObject *parent, QSqlDatabase db)
{
    setTable("city");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    select();

    this->setRelation(3, QSqlRelation("district"," district_id", "district"));
    setHeaderData( 0, Qt::Horizontal,"Id");
    setHeaderData( 1, Qt::Horizontal,"City");
    setHeaderData( 2, Qt::Horizontal,"phone_kod");
    setHeaderData( 3, Qt::Horizontal,"district_id");

}
