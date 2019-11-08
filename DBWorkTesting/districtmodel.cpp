#include "districtmodel.h"

DistrictModel::DistrictModel()
{

}

DistrictModel::DistrictModel(QObject *parent, QSqlDatabase db)
{
    setTable("district");
    setEditStrategy(QSqlTableModel::OnFieldChange);
    select();

    this->setRelation(2,QSqlRelation("region","region_id","region"));

    setHeaderData( 0, Qt::Horizontal,"Id");
    setHeaderData( 1, Qt::Horizontal,"District");
    setHeaderData( 2, Qt::Horizontal,"region_id");

}

