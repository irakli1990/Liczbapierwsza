#ifndef LICZBAPIERWSZA_H
#define LICZBAPIERWSZA_H

#include <QMainWindow>

namespace Ui {
class Liczbapierwsza;
}

class Liczbapierwsza : public QMainWindow
{
    Q_OBJECT

public:
    explicit Liczbapierwsza(QWidget *parent = nullptr);
    ~Liczbapierwsza();

private slots:
    void on_sprawdz_clicked();
    bool czy_pierwsza(int n);

private:
    Ui::Liczbapierwsza *ui;
};

#endif // LICZBAPIERWSZA_H
