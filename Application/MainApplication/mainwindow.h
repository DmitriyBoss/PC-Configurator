#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtNetwork"
#include <list>
#include <QDebug>

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

    void on_Save_triggered();

    void readFile(int);

    void getTotalPrice();

    QByteArray filePrint();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox_3_currentTextChanged(const QString &arg1);

    void on_comboBox_4_currentTextChanged(const QString &arg1);

    void on_comboBox_5_currentTextChanged(const QString &arg1);

    void on_comboBox_6_currentTextChanged(const QString &arg1);

    void on_comboBox_7_currentTextChanged(const QString &arg1);

    void on_comboBox_8_currentTextChanged(const QString &arg1);

    void on_comboBox_9_currentTextChanged(const QString &arg1);

    void on_comboBox_10_currentTextChanged(const QString &arg1);

    void on_comboBox_11_currentTextChanged(const QString &arg1);

    void on_comboBox_12_currentTextChanged(const QString &arg1);

    void on_Load_triggered();

    void on_Info_triggered();

private:
    Ui::MainWindow *ui;
    std::list<QString> motherboardNameSet , procNameSet, coolerNameSet, ozuNameSet, videoNameSet, hNameSet,
                  sNameSet, bpNameSet, korpNameSet, monitNameSet, keyNameSet, mouseNameSet;
    std::list<QString> motherboardPriceSet, procPriceSet, coolerPriceSet, ozuPriceSet, videoPriceSet, hPriceSet,
                  sPriceSet, bpPriceSet, korpPriceSet, monitPriceSet, keyPriceSet, mousePriceSet;
};

#endif // MAINWINDOW_H
