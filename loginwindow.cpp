#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

bool LoginWindow::requestLogin(QString username, QString password)
{

}

bool LoginWindow::requestRegister(QString username, QString password, QString nickname)
{

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    if (requestLogin(ui->lineEdit_username, ui->lineEdit_password)) {
        emit loginSuccess();
        this->hide();
    }else {
        // Show error message
    }
}

void LoginWindow::on_pushButton_2_clicked()
{

}
