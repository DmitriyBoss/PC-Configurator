#include "dialog.h"
#include "ui_dialog.h"
#include <QTextStream>
#include <QFile>
#include <QMessageBox>

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    checkInfo();
}

Dialog::~Dialog()
{
    delete ui;
}

/**
    Данный метод выводит в новом окне статус текстовых файлов приложения,
    а также информацию, откуда были взяты комплектующие и цены.
*/

void Dialog::checkInfo()
{
    QString info = "";
    QFile file_test_1("System/Motherboard.txt"), file_test_2("System/Processor.txt"),
          file_test_3("System/Cooler.txt"), file_test_4("System/RAM.txt"),
          file_test_5("System/Videocard.txt"), file_test_6("System/HDD.txt"),
          file_test_7("System/SSD.txt"), file_test_8("System/Powerblock.txt"),
          file_test_9("System/Systemblock.txt"), file_test_10("System/Monitor.txt"),
          file_test_11("System/Keyboard.txt"), file_test_12("System/Mouse.txt");

    if(file_test_1.exists())
        info += "Motherboard.txt          |       OK       |\n";
    else
        info += "Motherboard.txt          |   FAILED   |\n";

    if(file_test_2.exists())
        info += "Processor.txt               |       OK       |\n";
    else
        info += "Processor.txt               |   FAILED   |\n";

    if(file_test_3.exists())
        info += "Cooler.txt                    |       OK       |\n";
    else
        info += "Cooler.txt                    |   FAILED   |\n";

    if(file_test_4.exists())
        info += "RAM.txt                     |       OK       |\n";
    else
        info += "RAM.txt                     |   FAILED   |\n";

    if(file_test_5.exists())
        info += "Videocard.txt               |       OK       |\n";
    else
        info += "Videocard.txt               |   FAILED   |\n";

    if(file_test_6.exists())
        info += "HDD.txt                      |       OK       |\n";
    else
        info += "HDD.txt                      |   FAILED   |\n";

    if(file_test_7.exists())
        info += "SSD.txt                        |       OK       |\n";
    else
        info += "SSD.txt                        |   FAILED   |\n";

    if(file_test_8.exists())
        info += "Powerblock.txt             |       OK       |\n";
    else
        info += "Powerblock.txt             |   FAILED   |\n";

    if(file_test_9.exists())
        info += "Systemblock.txt            |       OK       |\n";
    else
        info += "Systemblock.txt            |   FAILED   |\n";

    if(file_test_10.exists())
        info += "Monitor.txt                   |       OK       |\n";
    else
        info += "Monitor.txt                   |   FAILED   |\n";

    if(file_test_11.exists())
        info += "Keyboard.txt                |       OK       |\n";
    else
        info += "Keyboard.txt                |   FAILED   |\n";

    if(file_test_12.exists())
        info += "Mouse.txt                    |       OK       |";
    else
        info += "Mouse.txt                    |   FAILED   |";

    ui->textEdit->setText(info);
}
