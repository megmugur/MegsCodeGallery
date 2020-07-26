#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
//#include <opencv2/opencv.hpp>
#include <QtNetwork/QNetworkReply>
#include <QFile>

using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}
Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_clicked()
{
    //path image
    QString path("d:\\people3.jpeg");
    //php script that receives the image
    QNetworkRequest requete(QUrl("http://*.*.*.*:8080/upload"));

    QByteArray boundary = "------WebKitFormBoundarytoHka8LUGjq34sBN";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"error read image";
        return;
    }
    QByteArray fileContent(file.readAll());

    QByteArray data = boundary + "\r\n";
    data += "Content-Disposition: form-data; name=\"file\"; filename=\"people3.jpeg\"\r\n";
    data += "Content-Type: image/jpeg\r\n\r\n" + fileContent + "\r\n";
    data += boundary + "--\r\n";
    requete.setRawHeader("Content-Type", "multipart/form-data; boundary=----WebKitFormBoundarytoHka8LUGjq34sBN");
    requete.setRawHeader("Content-Length", QString::number(data.size()).toLatin1 ());
    file.close();
    QNetworkAccessManager *am = new QNetworkAccessManager(this);
    QNetworkReply *reply = am->post(requete,data);

    QObject::connect(am, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

}

void Widget::replyFinished(QNetworkReply *reply)
{
    reply->open(QIODevice::ReadOnly);

    // if the response is correct
    if(reply->error() == QNetworkReply::NoError)
    {
        QByteArray str=(reply->readAll());
        QString response = QString::fromUtf8(str.data(), str.size());
        qDebug()<<" re "<<response;
    }
    //error sever
    else
        qDebug()<<"error response server";


}

/*
result
 re  "{
  "status": "OK"
}"
*/
