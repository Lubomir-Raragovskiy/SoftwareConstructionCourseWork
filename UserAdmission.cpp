#include "UserAdmission.h"



UserAdmission::UserAdmission(DataBaseConnection* connection): connection(connection)
{

    connection->getDataBase()->prepare("signUp", "INSERT INTO \"Users\"(login, \"password\", salt, user_name) VALUES($1, $2, $3, $4);");
    connection->getDataBase()->prepare("signIn", "SELECT password, salt, user_id FROM \"Users\" WHERE login = $1");

}

void UserAdmission::signUp(QString login, QString password)
{
    try {


        std::string salt = getSalt();


        pqxx::transaction transaction(*connection->getDataBase());

        transaction.exec_prepared("signUp", login.toStdString(), encryptPassword(password.toStdString(), salt), salt, login.toStdString());

        transaction.commit();


    }
    catch (pqxx::not_null_violation) {
        QMessageBox::warning(NULL, "Login or password cannot be blank", "Fill Login or password and try again");
    }
    catch (pqxx::unique_violation) {
        QMessageBox::warning(NULL, "Login already taken", "Choose different login and try again");
    }
    
}

int UserAdmission::logIn(QString login, QString password)
{

    hash.reset();
    pqxx::transaction transaction(*connection->getDataBase());


    pqxx::result result = transaction.exec_prepared("signIn", login.toStdString());

    if (!result.empty()) {


        hash.addData(password.toStdString() + result[0][1].as<std::string>());

        if (hash.result().toHex().toStdString() == result[0][0].as<std::string>()) {

            return result[0][2].as<int>();

        }
        else
        {
            QMessageBox::warning(NULL, "Incorrect password", "Password is incorect, try again");
            return -1;
        }
        
    }
    else {
        QMessageBox::warning(NULL, "Incorrect login", "Login is incorect, try again");
        return -1;
    }



}

std::string UserAdmission::getSalt()
{
    std::chrono::milliseconds timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
        );

    hash.reset();
    hash.addData(QByteArray(std::to_string(timestamp.count()).c_str()).constData());

    return hash.result().toHex().toStdString();
}

std::string UserAdmission::encryptPassword(std::string password, std::string salt)
{
    hash.reset();

    hash.addData(password + salt);

    return hash.result().toHex().toStdString();
}

