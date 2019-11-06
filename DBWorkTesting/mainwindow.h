#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QtSql>

#include "peoplemodel.h"
#include "universitymodel.h"
#include "countrymodel.h"
#include "regionmodel.h"
#include "districtmodel.h"
#include "citymodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectButton_released();

    void on_disconectButton_released();

    void on_updateButton_released();

    void on_add_country_released();

    void on_delete_country_released();

    void on_save_to_file_released();

    void on_add_region_released();

    void on_delete_region_released();

    void on_button_add_district_released();

    void on_button_delete_district_released();

    void on_button_add_city_released();

    void on_button_delete_city_released();

private:
    Ui::MainWindow *ui;

protected:
    QSqlDatabase db;
    QString userLogin;
    QString userPassword;
    QString userHost;
    int     localPortDB;
    int     remotePort;
    bool    DBConnectionState;
    QString sshTunelConfigForDB;
    QProcess dbTunel;
    PeopleModel *peopleModel;
    UniversityModel *universityModel;
    CountryModel *countryModel;
    RegionModel *regionModel;
    DistrictModel *districtModel;
    CityModel *cityModel;
};

#endif // MAINWINDOW_H
