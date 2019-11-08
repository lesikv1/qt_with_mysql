#include "regionmodel.h"

RegionModel::RegionModel()
{

}

RegionModel::RegionModel(QObject *parent, QSqlDatabase db)
{
    setTable("region");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    select();

    this->setRelation(2,QSqlRelation("country","country_id","country"));

    setHeaderData( 0, Qt::Horizontal,"Id");
    setHeaderData( 1, Qt::Horizontal,"Region");
    setHeaderData( 2, Qt::Horizontal,"country_id");

}

