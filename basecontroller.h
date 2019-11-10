#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>

class BaseController
{
private:
    QSqlDatabase db;

public:
    BaseController(const QSqlDatabase &db);

    virtual ~BaseController() = 0;

    void createTable(QString create_table_query);

    void insert(QString insert_query);

    QSqlQueryModel *findAll(QString select_query);

//    virtual void showTableName()=0;

//    QSqlQueryModel *findAll();

//    QSqlQueryModel *findAllByCountry(string countryName);

//    QSqlQueryModel *findAllSortedByPrice();

//    QSqlQueryModel *findAllSortedByCountry();

//    void showAll();
};

#endif // BASECONTROLLER_H
