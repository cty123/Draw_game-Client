#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gamesocket.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionCreate_New_Game_triggered();

    void on_actionJoin_Random_Game_triggered();

    void on_actionStart_Game_triggered();

private:
    Ui::MainWindow *ui;
public:
    GameSocket * gs;
};

#endif // MAINWINDOW_H
