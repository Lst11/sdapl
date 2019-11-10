#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>

class BaseController {
private:
    QSqlDatabase db;

public:
    BaseController(const QSqlDatabase &db);

    virtual ~BaseController() = 0;

    void createTable(QString create_table_query);

    void insert(QString insert_query);

    QSqlQueryModel *findAll(QString select_query);
};

#endif // BASECONTROLLER_H
