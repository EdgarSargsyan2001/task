#ifndef USER_H
#define USER_H
#include <QString>
#include <QDate>
#include <QDataStream>

class User
{
public:
    User() = default;
    User(const QString& name,const size_t age,const QDate& date);

    void set_name(const QString& name);
    void set_age(const size_t& age);
    void set_date(const QDate& date);

    QString name()const;
    size_t age()const;
    QDate date()const;

    QString serialize() const ;

    void deserialize(const QString& data);

private:
    QString _name;
    size_t _age;
    QDate _date;

};

#endif // USER_H
