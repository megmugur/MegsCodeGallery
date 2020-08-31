#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    //QString my_URL =  "https://550gallery.com/wp-content/uploads/2019/12/throwing-beg-adult_1200x.jpg";
    Ui::MainWindow *ui;

private slots:
    void downloadFinished(QNetworkReply*);
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
