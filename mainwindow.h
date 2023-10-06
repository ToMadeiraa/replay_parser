#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector<QString> findSettings(QByteArray arr);
    QVector<QVector<QString>> findPlayers(QByteArray arr);
    QVector<QVector<QString>> findPlayersInfo(QByteArray arr);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
void filterSettings (QVector<QString>& settings);
void findNationColor(QVector<QVector<QString>> &plrs);

#endif // MAINWINDOW_H
