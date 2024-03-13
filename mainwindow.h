#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QSpinBox>
#include <QFile>
#include <QTextStream>

#include "user.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setLayoutWidget();


private:
    QLabel* nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *ageLabel;
    QSpinBox *ageLineEdit;
    QLabel* dateLabel;
    QDateEdit* dateEdit;
    QPushButton* serializeButton;
    QPushButton* deserializeButton;
    User _user;

};
#endif // MAINWINDOW_H
