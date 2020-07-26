#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::downloadFinished(QNetworkReply *my_reply)
{
    QPixmap pix;
    pix.loadFromData(my_reply->readAll());
    ui->my_label->setPixmap(pix);

}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->my_pushButton, SIGNAL (pressed()), this, SLOT(on_pushButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::downloadFinished);
    const QUrl my_URL = QUrl("https://550gallery.com/wp-content/uploads/2019/12/throwing-beg-adult_1200x.jpg");
    QNetworkRequest my_request (my_URL);
    manager->get(my_request);
}
