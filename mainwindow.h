#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"metodos.h"
#include"parser.h"
#include"funcoes.h"
#include"funcoes_erro.h"
#include"matrizes.h"
#include<time.h>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    double resposta;
    int Base_entrada = 10;
    int Base_saida = 2;
    char numero[255];
    double resultado_SPF;
    double max;
    double min;
    int opcao;
    ~MainWindow();

private slots:
    void on_calcular_clicked();

    void on_Numero_editingFinished();

    void on_Base_entrada_currentTextChanged(const QString &arg1);

    void on_Base_saida_currentTextChanged(const QString &arg1);

    void on_Converter_clicked();

    void on_SPF_clicked();

    void on_maximo_clicked();

    void on_minimo_clicked();

    void on_opcao_clicked(bool checked);

    void on_K_ideal_clicked(bool checked);

    void on_calcular_2_clicked();

    void on_calcular_derivada_clicked();

    void on_Limpar_clicked();

    void on_Clear_clicked();

    void on_Linkar_clicked();

    void on_Calcular_determinante_clicked();

    void on_solucionar_clicked();

    void on_matriz_entrada_editingFinished();

    void on_transformacoes_activated(int index);

    void on_metodo_sistema_activated(int index);

    void on_Solver_tabBarClicked(int index);

    void on_metodo_activated(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
