#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

#include <QTextEdit>
extern void setSalida(QTextEdit* sal, QTextEdit* grafo); //METODO CREADO EN EL ANALIZADOR SINTACTICO

namespace Ui {
class principal;
}

class principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();

private slots:
    void on_btnAnalizar_clicked();

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
