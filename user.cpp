#include "user.h"

User::User(const QString& name,const size_t age,const QDate& date)
    : _name(name)
    , _age(age)
    , _date(date)
{
}

void User::set_name(const QString& name){
    _name = name;
}

void User::set_age(const size_t& age){
    _age = age;
}

void User::set_date(const QDate& date){
    _date = date;
}

QString User::name()const{
    return _name;
}

size_t User::age()const{
    return _age;
}

QDate User::date()const{
    return _date;
}


QString User::serialize() const {
    return _name + "," + QString::number(_age) + "," + _date.toString("dd.MM.yyyy");
}

void User::deserialize(const QString& data) {
    QStringList dataList = data.split(',');

    if (dataList.size() == 3) {
        _name = dataList.at(0);
        _age =  dataList.at(1).toULong();

        QStringList dateList = dataList.at(2).split('.');
        int day = dateList[0].toInt();
        int year = dateList[2].toInt();
        int month = dateList[1].toInt();
        _date.setDate(year,month,day);

    } else {
        qDebug() << "Error: Invalid data format.";
    }
}
