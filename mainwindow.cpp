#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{

    nameLabel = new QLabel("Name:", this);
    nameLineEdit = new QLineEdit(this);

    ageLabel = new QLabel("Age:", this);
    ageLineEdit = new QSpinBox(this);

    dateLabel = new QLabel("Date:", this);
    dateEdit = new QDateEdit(QDate::currentDate(), this);

    serializeButton = new QPushButton("serialize", this);

    connect(serializeButton,QPushButton::clicked,[this](){
        QFile file("saved_date.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Error: Unable to open the file for writing.";
            return;
        }
        _user.set_name(nameLineEdit->text());
        _user.set_age(ageLineEdit->value());
        _user.set_date(dateEdit->date());

        QTextStream out(&file);
        out << _user.serialize();
        file.close();
    });

    deserializeButton = new QPushButton("deserialize", this);

    connect(deserializeButton,QPushButton::clicked,[this](){
        QFile file("saved_date.txt");

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Error: Unable to open the file for reading.";
        }

        QTextStream in(&file);
        QString fileContent = in.readAll();
        _user.deserialize(fileContent);

        nameLineEdit->setText(_user.name());
        ageLineEdit->setValue(_user.age());
        dateEdit->setDate(_user.date());

        file.close();
    });

    setLayoutWidget();

}

MainWindow::~MainWindow()
{
}


void MainWindow::setLayoutWidget(){
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QHBoxLayout *mainLay = new QHBoxLayout(centralWidget);


    QVBoxLayout *Leftlayout = new QVBoxLayout();
    Leftlayout->addWidget(nameLabel);
    Leftlayout->addWidget(nameLineEdit);
    Leftlayout->addWidget(ageLabel);
    Leftlayout->addWidget(ageLineEdit);
    Leftlayout->addWidget(dateLabel);
    Leftlayout->addWidget(dateEdit);

    QVBoxLayout *Rightlayout = new QVBoxLayout();
    Rightlayout->addWidget(serializeButton);
    Rightlayout->addWidget(deserializeButton);

    mainLay->addLayout(Leftlayout);
    mainLay->addLayout(Rightlayout);

}

