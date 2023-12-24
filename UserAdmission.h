#pragma once
#include <QString>
#include <QMessageBox>
#include <pqxx/pqxx>
#include <chrono>
#include <QCryptographicHash>
#include "Database/DatabaseConnection.h"
class UserAdmission
{
private:

	DataBaseConnection* connection;
	QCryptographicHash hash = QCryptographicHash(QCryptographicHash::Sha512);
	std::string getSalt();
	std::string encryptPassword(std::string password, std::string salt);

public:

	UserAdmission(DataBaseConnection* connection);
	void signUp(QString login, QString password);
	int logIn(QString login, QString password);
	
	



};

