#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QSqlQuery>
#include <QString>
#include <QModelIndex>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    userLogin="onufriev";
    userPassword="353044046";
    userHost="localhost";
    localPortDB=3306;
    remotePort=2233;
    sshTunelConfigForDB ="ssh\\plink -P %1 -L %2:localhost:3306 %3@%4 -N -pw %5 < ssh\\config.ini";

    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("donnu");
    db.setHostName("localhost");
    db.setUserName(userLogin);
    db.setPassword(userPassword);
    db.setPort(localPortDB);

}

MainWindow::~MainWindow()
{
    delete peopleModel;
    delete universityModel;
    delete countryModel;
    delete regionModel;
    delete districtModel;
    delete cityModel;
    delete ui;
}

void MainWindow::on_connectButton_released()
{
    QString msgDB;
    msgDB=sshTunelConfigForDB.arg(remotePort).arg(localPortDB).arg(userLogin).arg(userHost).arg(userPassword);
    qDebug()<<msgDB;
    dbTunel.start(msgDB);
    int i;

    for(i=0;i<30;i++)
      {
        DBConnectionState = db.open();
        if(true==DBConnectionState)
            break;
      }

    if(true==DBConnectionState)
       {
         ui->statusString->setText("Подключение выполнено !!!");

         countryModel=new CountryModel(this,db);
         ui->table_country->setModel(countryModel);
         ui->table_country->resizeColumnsToContents();

         regionModel = new RegionModel(this, db);
         ui->table_region->setModel(regionModel);
         ui->table_region->resizeColumnsToContents();
         ui->table_region->setItemDelegate(new QSqlRelationalDelegate());

         districtModel = new DistrictModel(this, db);
         ui->table_district->setModel(districtModel);
         ui->table_district->resizeColumnsToContents();
         ui->table_district->setItemDelegate(new QSqlRelationalDelegate());

         cityModel = new CityModel(this, db);
         ui->table_cities->setModel(cityModel);
         ui->table_cities->resizeColumnsToContents();
         ui->table_cities->setItemDelegate(new QSqlRelationalDelegate());

       }
    else
    {
      ui->statusString->setText("Подключение не выполнено."+db.lastError().text());
//      errorLog->AddErrorMessage("Подключение не выполнено."+db.lastError().text());
     qDebug()<<"\nDB Error: "<<db.lastError().text();
    }



}



void MainWindow::on_disconectButton_released()
{
    db.close();
    dbTunel.close();
}

void MainWindow::on_updateButton_released()
{
    countryModel->select();
    regionModel->select();
}

void MainWindow::on_add_country_released()
{
    QSqlQuery add;
    add.prepare("INSERT INTO country (country, citizenship) "
                      "VALUES (:country_name, :citizenship_name)");

    QString country_name = ui->input_country->text();
    QString citizenship_name = ui->input_citizenship->text();

    add.bindValue(":country_name", country_name);
    add.bindValue(":citizenship_name", citizenship_name);

    if (!add.exec()) {
        ui->text_notification->append("error pre adding new element in table county");
    }

    countryModel->select();
    ui->input_country->setText("");
    ui->input_citizenship->setText("");
}

void MainWindow::on_delete_country_released()
{
    QModelIndex field = ui->table_country->currentIndex();

    if(field.isValid()){
        QSqlRecord record = countryModel->record(field.row());
        int Id = record.value(0).toInt();
        QString sql = "DELETE FROM country WHERE country_id=%1;";
        sql = sql.arg(Id);
        QSqlQuery query(db);

        if (!query.exec(sql)) {
            ui->text_notification->append("Error pre delete element from table country");
        }
    }

        countryModel->select();

}

void MainWindow::on_save_to_file_released()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Save file"), "",tr("Txt(*.txt)"));
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out<<ui->text_notification->toPlainText();
    file.close();
}

void MainWindow::on_add_region_released()
{
    QSqlQuery add;
    add.prepare("INSERT INTO region (region, country_id) "
                      "VALUES (:region_name, :cauntry_id_name)");

    QString region_name = ui->input_region->text();
    QString cauntry_id_name = ui->input_cauntry_id->text();

    add.bindValue(":region_name", region_name);
    add.bindValue(":cauntry_id_name", cauntry_id_name);

    if (!add.exec()) {
        ui->text_notification->append("error pre adding new element in table region");
    }

    regionModel->select();
    ui->input_region->setText("");
    ui->input_cauntry_id->setText("");
}

void MainWindow::on_delete_region_released()
{
    QModelIndex field = ui->table_region->currentIndex();

    if(field.isValid()){
        QSqlRecord record = regionModel->record(field.row());
        int Id = record.value(0).toInt();
        QString sql = "DELETE FROM region WHERE region_id=%1;";
        sql = sql.arg(Id);
        QSqlQuery query(db);

        if (!query.exec(sql)) {
            ui->text_notification->append("Error pre delete element from table region");
        }
    }

        regionModel->select();
}

void MainWindow::on_button_add_district_released()
{
    QSqlQuery add;
    add.prepare("INSERT INTO district (district, region_id) "
                      "VALUES (:district_name, :region_id_name)");

    QString district_name = ui->input_district->text();
    QString region_id_name = ui->input_region_id->text();

    add.bindValue(":district_name", district_name);
    add.bindValue(":region_id_name", region_id_name);

    if (!add.exec()) {
        ui->text_notification->append("error pre adding new element in table district");
    }

    districtModel->select();
    ui->input_district->setText("");
    ui->input_region_id->setText("");
}

void MainWindow::on_button_delete_district_released()
{
    QModelIndex field = ui->table_district->currentIndex();

    if(field.isValid()){
        QSqlRecord record = districtModel->record(field.row());
        int Id = record.value(0).toInt();
        QString sql = "DELETE FROM district WHERE district_id=%1;";
        sql = sql.arg(Id);
        QSqlQuery query(db);

        if (!query.exec(sql)) {
            ui->text_notification->append("Error pre delete element from table district");
        }
    }

        districtModel->select();
}

void MainWindow::on_button_add_city_released()
{
    QSqlQuery add;
    add.prepare("INSERT INTO city (city, phone_kod, district_id) "
                      "VALUES (:city_name, :phone_kod_name, :district_id_name)");

    QString city_name = ui->input_city->text();
    QString phone_kod_name = ui->input_phone->text();
    QString district_id_name = ui->input_disctict_id->text();

    add.bindValue(":city_name", city_name);
    add.bindValue(":phone_kod_name", phone_kod_name);
    add.bindValue(":district_id_name", district_id_name);

    if (!add.exec()) {
        ui->text_notification->append("error pre adding new element in table city");
    }

    cityModel->select();
    ui->input_city->setText("");
    ui->input_phone->setText("");
    ui->input_disctict_id->setText("");
}

void MainWindow::on_button_delete_city_released()
{
    QModelIndex field = ui->table_cities->currentIndex();

    if(field.isValid()){
        QSqlRecord record = cityModel->record(field.row());
        int Id = record.value(0).toInt();
        QString sql = "DELETE FROM city WHERE city_id=%1;";
        sql = sql.arg(Id);
        QSqlQuery query(db);

        if (!query.exec(sql)) {
            ui->text_notification->append("Error pre delete element from table city");
        }
    }

        cityModel->select();
}
