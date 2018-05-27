#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    bool requestLogin(QString username, QString password);
    bool requestRegister(QString username, QString password, QString nickname);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void loginSuccess();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
