#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "scribblearea.h"

#include <QDebug>
#include <QUrl>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Set up the drawing panel

    ScribbleArea * sa = new ScribbleArea(this);
    gs = new GameSocket(QUrl(QStringLiteral("ws://localhost:8080")),this);
    this->gs->connect(sa, SIGNAL(perform_draw(QPoint,QPoint)), gs, SLOT(draw(QPoint,QPoint)));
    connect(gs, SIGNAL(receive_draw(QPoint,QPoint)), sa, SLOT(print(QPoint,QPoint)));
    ui->panel_container->addWidget(sa);
    ui->splitter->setStretchFactor(1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCreate_New_Game_triggered()
{
    gs->create_room();
}

void MainWindow::on_actionJoin_Random_Game_triggered()
{
    gs->join_room();
}

void MainWindow::on_actionStart_Game_triggered()
{
    gs->start_game();
}
