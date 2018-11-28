#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QFile>
#include <QWidget>
#include <list>
#include <iostream>
#include <QFileDialog>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    if (manager->networkAccessible() == QNetworkAccessManager::NotAccessible)
    {
        ui->statusBar->showMessage(tr("Сохранённая информация"));
        for(int i = 0; i < 12; i++)
            readFile(i);
    }
    else
    {
        ui->statusBar->showMessage(tr("Онлайн-информация"));
        system("java -jar parser.jar");
        for(int i = 0; i < 12; i++)
            readFile(i);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

// метод сохранения конфигурации в файл
void MainWindow::on_Save_triggered()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    int i = 1;
    for(i = 1;i;i++)
    {
        QString num = QString::number(i);
        QString str = "Configs/PC_Config" + num + ".txt";
        QFile filetest(str);

        if(!filetest.exists())
            break;
    }

    QString num = QString::number(i);
    QString name = "Configs/PC_Config" + num + ".txt";
    QFile file(name);
    if (!file.open(QIODevice::ReadWrite))
        return;

    file.write(filePrint());
    file.close();

    if (manager->networkAccessible() == QNetworkAccessManager::NotAccessible)
        ui->statusBar->showMessage(tr("Сохранённая информация"));
    else
        ui->statusBar->showMessage(tr("Онлайн-информация"));
}

// метод, добавляющий комплектующие из файлов приложения в приложение
void MainWindow::readFile(int ID)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));

    if(ID == 0)
    {
        QFile Config("System/Motherboard.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox->addItem(total);
            motherboardNameSet.push_back(total);
            motherboardPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 1)
    {
        QFile Config("System/Processor.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_2->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_2->addItem(total);
            procNameSet.push_back(total);
            procPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 2)
    {
        QFile Config("System/Cooler.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_3->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_3->addItem(total);
            coolerNameSet.push_back(total);
            coolerPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 3)
    {
        QFile Config("System/RAM.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_4->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_4->addItem(total);
            ozuNameSet.push_back(total);
            ozuPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 4)
    {
        QFile Config("System/Videocard.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_5->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_5->addItem(total);
            videoNameSet.push_back(total);
            videoPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 5)
    {
        QFile Config("System/HDD.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_6->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_6->addItem(total);
            hNameSet.push_back(total);
            hPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 6)
    {
        QFile Config("System/SSD.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_7->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_7->addItem(total);
            sNameSet.push_back(total);
            sPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 7)
    {
        QFile Config("System/Powerblock.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_8->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_8->addItem(total);
            bpNameSet.push_back(total);
            bpPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 8)
    {
        QFile Config("System/Systemblock.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_9->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_9->addItem(total);
            korpNameSet.push_back(total);
            korpPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 9)
    {
        QFile Config("System/Monitor.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_10->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_10->addItem(total);
            monitNameSet.push_back(total);
            monitPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 10)
    {
        QFile Config("System/Keyboard.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_11->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_11->addItem(total);
            keyNameSet.push_back(total);
            keyPriceSet.push_back(str_list.at(1));
        }
    } else if(ID == 11)
    {
        QFile Config("System/Mouse.txt");
        if (!Config.open(QIODevice::ReadOnly))
            return;
        ui->comboBox_12->addItem("");
        while(true)
        {
            QByteArray str = Config.readLine();
            if(str == "")
                break;
            QByteArrayList str_list = str.split(';');
            QString total = QString::fromLocal8Bit(str_list.at(0));
            ui->comboBox_12->addItem(total);
            mouseNameSet.push_back(total);
            mousePriceSet.push_back(str_list.at(1));
        }
    }
    return;
}

// метод, возвращающий итоговую информацию о конфигурации для записи в файл
QByteArray MainWindow::filePrint()
{
    QString to_back = "Материнская плата: \r\n" + ui->comboBox->currentText() + "\r\n" + "Цена: \r\n" + ui->label_14->text() + "\r\n\r\n" +
                 "Процессор: \r\n" + ui->comboBox_2->currentText() + "\r\n" + "Цена: \r\n" + ui->label_15->text() + "\r\n\r\n" +
                 "Кулер: \r\n" + ui->comboBox_3->currentText() + "\r\n" + "Цена: \r\n" + ui->label_16->text() + "\r\n\r\n" +
                 "Оперативная память: \r\n" + ui->comboBox_4->currentText() + "\r\n" + "Цена: \r\n" + ui->label_17->text() + "\r\n\r\n" +
                 "Видеокарта: \r\n" + ui->comboBox_5->currentText() + "\r\n" + "Цена: \r\n" + ui->label_18->text() + "\r\n\r\n" +
                 "HDD: \r\n" + ui->comboBox_6->currentText() + "\r\n" + "Цена: \r\n" + ui->label_19->text() + "\r\n\r\n" +
                 "SSD: \r\n" + ui->comboBox_7->currentText() + "\r\n" + "Цена: \r\n" + ui->label_20->text() + "\r\n\r\n" +
                 "Блок питания: \r\n" + ui->comboBox_8->currentText() + "\r\n" + "Цена: \r\n" + ui->label_21->text() + "\r\n\r\n" +
                 "Корпус: \r\n" + ui->comboBox_9->currentText() + "\r\n" + "Цена: \r\n" + ui->label_22->text() + "\r\n\r\n" +
                 "Монитор: \r\n" + ui->comboBox_10->currentText() + "\r\n" + "Цена: \r\n" + ui->label_23->text() + "\r\n\r\n" +
                 "Клавиатура: \r\n" + ui->comboBox_11->currentText() + "\r\n" + "Цена: \r\n" + ui->label_24->text() + "\r\n\r\n" +
                 "Мышь: \r\n" + ui->comboBox_12->currentText() + "\r\n" + "Цена: \r\n" + ui->label_25->text() + "\r\n\r\n" +
                 "Итого: \r\n" + ui->label_26->text();

    QByteArray to_back_total;
    to_back_total += to_back;
    return to_back_total;
}

// метод, подсчитывающий итоговую цену сборки
void MainWindow::getTotalPrice()
{
    QString part_sum = "";
    double sum = 0;

    part_sum = ui->label_14->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_15->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_16->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_17->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_18->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_19->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_20->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_21->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_22->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_23->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_24->text().split(' ').at(0);
    sum += part_sum.toDouble();

    part_sum = ui->label_25->text().split(' ').at(0);
    sum += part_sum.toDouble();

    if(sum == 0)
    {
        ui->label_26->setText("");
        return;
    }

    QString str = QString::number(sum);
    str += " p.";

    ui->label_26->setText(str);
}

// следующие 12 методов пересчитывают цену, если какой-либо из параметров конфигурации был изменён
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_14->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = motherboardNameSet.begin(); i != motherboardNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = motherboardPriceSet.begin(); j != motherboardPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_14->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_15->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = procNameSet.begin(); i != procNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = procPriceSet.begin(); j != procPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_15->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_16->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = coolerNameSet.begin(); i != coolerNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = coolerPriceSet.begin(); j != coolerPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_16->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_4_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_17->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = ozuNameSet.begin(); i != ozuNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = ozuPriceSet.begin(); j != ozuPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_17->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_5_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_18->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = videoNameSet.begin(); i != videoNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = videoPriceSet.begin(); j != videoPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_18->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_6_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_19->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = hNameSet.begin(); i != hNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = hPriceSet.begin(); j != hPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_19->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_7_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_20->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = sNameSet.begin(); i != sNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = sPriceSet.begin(); j != sPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_20->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_8_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_21->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = bpNameSet.begin(); i != bpNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = bpPriceSet.begin(); j != bpPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_21->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_9_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_22->setText("");
        getTotalPrice();
        return;
    }

    std::list<QString>::iterator i;
    std::list<QString>::iterator j;

    for(i = korpNameSet.begin(); i != korpNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }

    for(j = korpPriceSet.begin(); j != korpPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_22->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_10_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_23->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = monitNameSet.begin(); i != monitNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = monitPriceSet.begin(); j != monitPriceSet.end(); ++j)
    {
        if(k == s)
           ui->label_23->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_11_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_24->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = keyNameSet.begin(); i != keyNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = keyPriceSet.begin(); j != keyPriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_24->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

void MainWindow::on_comboBox_12_currentTextChanged(const QString &arg1)
{
    int k = 0, s = 0;

    if(arg1 == "")
    {
        ui->label_25->setText("");
        getTotalPrice();
        return;
    }
    std::list<QString>::iterator i;
    std::list<QString>::iterator j;
    for(i = mouseNameSet.begin(); i != mouseNameSet.end(); ++i)
    {
        if(*i == arg1) break;
        s++;
    }
    for(j = mousePriceSet.begin(); j != mousePriceSet.end(); ++j)
    {
        if(k == s)
            ui->label_25->setText(*j + " p.");

        k++;
    }
    getTotalPrice();
}

// метод, загружающий конфигурацию из файла в приложение
void MainWindow::on_Load_triggered()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    std::vector<QString> list;
    QString value = "";
    QString junk = "";

    QString filename = QFileDialog::getOpenFileName(this,"Load","Configs","(*.txt)");
    QFile File(filename);

    if (!File.open(QIODevice::ReadOnly))
        return;

    junk = File.readLine();
    for(int j = 0;j < 12; j++)
    {
        value = File.readLine().split('\r').at(0);
        list.push_back(value);
        for(int k = 0;k < 4;k++)
            junk = File.readLine();

    }

    value = File.readLine();
    list.push_back(value);

    ui->comboBox->setCurrentText(list[0]);
    ui->comboBox_2->setCurrentText(list[1]);
    ui->comboBox_3->setCurrentText(list[2]);
    ui->comboBox_4->setCurrentText(list[3]);
    ui->comboBox_5->setCurrentText(list[4]);
    ui->comboBox_6->setCurrentText(list[5]);
    ui->comboBox_7->setCurrentText(list[6]);
    ui->comboBox_8->setCurrentText(list[7]);
    ui->comboBox_9->setCurrentText(list[8]);
    ui->comboBox_10->setCurrentText(list[9]);
    ui->comboBox_11->setCurrentText(list[10]);
    ui->comboBox_12->setCurrentText(list[11]);

    if (manager->networkAccessible() == QNetworkAccessManager::NotAccessible)
        ui->statusBar->showMessage(tr("(Сохранённая конфигурация) Сохранённая информация"));
    else
        ui->statusBar->showMessage(tr("(Сохранённая конфигурация) Онлайн-информация"));
}

// метод, предназначенный для вывода дополнительной информации о приложении
void MainWindow::on_Info_triggered()
{
    Dialog list;
    list.setModal(true);
    QIcon icon("icon.png");
    list.setWindowIcon(icon);
    list.exec();
}
