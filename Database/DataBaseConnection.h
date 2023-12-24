#pragma once

#include <pqxx/pqxx>
#include <libconfig.h++>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>


class DataBaseConnection
{

private:
	static DataBaseConnection* connection;
	pqxx::connection* dataBase;
	DataBaseConnection();
	~DataBaseConnection();

public:
	pqxx::connection* getDataBase();
	static DataBaseConnection* connectDataBase();

};

QStandardItemModel* convertToModel(const pqxx::result& adaptee);

QAbstractItemModel* filterModel(QAbstractItemModel* model, int filterColumn, QString filterValue);