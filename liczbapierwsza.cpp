#include "liczbapierwsza.h"
#include "ui_liczbapierwsza.h"
#include <QRegExp>
#include <QRegExpValidator>
#include <QMessageBox>

Liczbapierwsza::Liczbapierwsza(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Liczbapierwsza)
{

    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),ui->lineEdit));
}

Liczbapierwsza::~Liczbapierwsza()
{
    delete ui;
}

void Liczbapierwsza::on_sprawdz_clicked()
{
    //    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
    int i,liczba;
    liczba = ui->lineEdit->text().toInt();
        if (czy_pierwsza(liczba)) {
            QMessageBox::information(this,"liczba pierwsza",QString::number(liczba)+ " jest liczba pierwsza");
        }
        else if(!czy_pierwsza(liczba))
        {
        QMessageBox::information(this,"liczba pierwsza",QString::number(liczba)+ " nie jest liczba pierwsza");

            for (i=liczba-1;i>=2;i--)
            {
                if(czy_pierwsza(i))
                {
                    QMessageBox::information(this,"liczba pierwsza ", QString::number(i) + " najblisza jest liczba pierwsza");
                    break;
                }
            }
        }

}
bool Liczbapierwsza::czy_pierwsza(int n)
{
    if(n<2)
        return false; //gdy liczba jest mniejsza niż 2 to nie jest pierwszą

    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false; //gdy znajdziemy dzielnik, to dana liczba nie jest pierwsza
    return true;
}

