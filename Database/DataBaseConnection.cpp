#include "DataBaseConnection.h"




DataBaseConnection::DataBaseConnection() {

	libconfig::Config config;
	

	std::string res;

	
	config.readFile("Database/databaseConfig.cfg");
	


	std::string conectionString;

	conectionString.append("dbname = " + std::string(config.lookup("dbname").c_str()));
	conectionString.append(" user = " + std::string(config.lookup("user").c_str()));
	conectionString.append(" password = " + std::string(config.lookup("password").c_str()));
	conectionString.append(" hostaddr = " + std::string(config.lookup("hostaddr").c_str()));
	conectionString.append(" port = " + std::string(config.lookup("port").c_str()));


	dataBase = new pqxx::connection(conectionString);


}

DataBaseConnection::~DataBaseConnection()
{


}


pqxx::connection* DataBaseConnection::getDataBase()
{
	return dataBase;
}

DataBaseConnection* DataBaseConnection::connectDataBase()
{

	if (!connection) {

		connection = new DataBaseConnection();
	}

	return connection;

}


DataBaseConnection* DataBaseConnection::connection = DataBaseConnection::connectDataBase();


QStandardItemModel* convertToModel(const pqxx::result& adaptee) {

	QStandardItemModel* result = new QStandardItemModel();

	for (int index(0); index < adaptee.columns(); ++index) {


		result->setHorizontalHeaderItem(index, new QStandardItem(adaptee.column_name(index)));

	}



	int rowIndex(0);

	for (pqxx::result::const_iterator row = adaptee.begin(); row != adaptee.end(); ++row) {


		int columnIndex(0);
		for (pqxx::const_row_iterator column : row) {



			QStandardItem* item = new QStandardItem(column.c_str());
			result->setItem(rowIndex, columnIndex, item);

			++columnIndex;
		}


		++rowIndex;
	}


	return result;
}

QAbstractItemModel* filterModel(QAbstractItemModel* model, int filterColumn, QString filterValue)
{
	QSortFilterProxyModel* filter = new QSortFilterProxyModel();
	filter->setSourceModel(model);
	filter->setFilterFixedString(filterValue);
	filter->setFilterKeyColumn(filterColumn);

	return filter;
}

