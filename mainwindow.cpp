#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//aba do solver
void MainWindow::on_calcular_2_clicked(){
    double res;
    char* saida;
    char* m_erro;
    saida = (char*)malloc(32*sizeof(char));
    m_erro = (char*)malloc(100*sizeof(char));
    saida[0] = '\0';
    if(ui->entrada->text().toStdString().c_str()[0] == '\0' ||
    ui->parametro->text().toStdString().c_str()[0] == '\0'){
        if(ui->entrada->text().toStdString().c_str()[0] == '\0'){
            ui->saida->setText("Eu preciso de uma função para trabalhar!");
        }
        else{
            ui->saida->setText("Eu preciso de um parâmetro!");
        }
    }
    else{
        if(!Sintaxe_correta(ui->entrada->text().toStdString().c_str(),m_erro)){
            ui->saida->setText(m_erro);
            free(m_erro);
        }
        else{
            strcat(saida,ui->Name->text().toStdString().c_str());
            strcat(saida,"(");
            strcat(saida,ui->parametro->text().toStdString().c_str());
            strcat(saida,") = ");
            if(strcmp(ui->parametro->text().toStdString().c_str(),"e") == 0 ||
            strcmp(ui->parametro->text().toStdString().c_str(),"P") == 0 ||
            strcmp(ui->parametro->text().toStdString().c_str(),"F") == 0 ||
            strcmp(ui->parametro->text().toStdString().c_str(),"L") == 0 ){
                if(strcmp(ui->parametro->text().toStdString().c_str(),"e") == 0){
                    res = Parser(ui->entrada->text().toStdString().c_str(),M_E);
                }
                else if(strcmp(ui->parametro->text().toStdString().c_str(),"P") == 0){
                    res = Parser(ui->entrada->text().toStdString().c_str(),M_PI);
                }
                else if(strcmp(ui->parametro->text().toStdString().c_str(),"F") == 0){
                    res = Parser(ui->entrada->text().toStdString().c_str(),MY_PHI);
                }
                else if(strcmp(ui->parametro->text().toStdString().c_str(),"L") == 0){
                    res = Parser(ui->entrada->text().toStdString().c_str(),MY_L);
                }
            }
            else{
                res = Parser(ui->entrada->text().toStdString().c_str(),ui->parametro->text().toDouble());
            }
            strcat(saida,QString::number(res).toStdString().c_str());
            ui->saida->setText(saida);
            free(saida);
        }
    }
}

void MainWindow::on_calcular_derivada_clicked(){
    double res;
    char* saida;
    char* m_erro;
    saida = (char*)malloc(32*sizeof(char));
    m_erro = (char*)malloc(100*sizeof(char));
    saida[0] = '\0';
    m_erro[0] = '\0';
    if(ui->entrada->text().toStdString().c_str()[0] == '\0' ||
    ui->parametro->text().toStdString().c_str()[0] == '\0'){
        if(ui->entrada->text().toStdString().c_str()[0] == '\0'){
            ui->saida->setText("Eu preciso de uma função para trabalhar!");
        }
        else{
            ui->saida->setText("Eu preciso de um parâmetro!");
        }
    }
    else{
        if(!Sintaxe_correta(ui->entrada->text().toStdString().c_str(),m_erro)){
            ui->saida->setText(m_erro);
            free(m_erro);
        }
        else{
            strcat(saida,ui->Name->text().toStdString().c_str());
            strcat(saida,"'(");
            strcat(saida,ui->parametro->text().toStdString().c_str());
            strcat(saida,") = ");
            if(strcmp(ui->parametro->text().toStdString().c_str(),"e") == 0 ||
            strcmp(ui->parametro->text().toStdString().c_str(),"P") == 0 ||
            strcmp(ui->parametro->text().toStdString().c_str(),"F") == 0 ||
            strcmp(ui->parametro->text().toStdString().c_str(),"L") == 0 ){
                if(strcmp(ui->parametro->text().toStdString().c_str(),"e") == 0){
                    res = Derivar(ui->entrada->text().toStdString().c_str(),M_E);
                }
                else if(strcmp(ui->parametro->text().toStdString().c_str(),"P") == 0){
                    res = Derivar(ui->entrada->text().toStdString().c_str(),M_PI);
                }
                else if(strcmp(ui->parametro->text().toStdString().c_str(),"F") == 0){
                    res = Derivar(ui->entrada->text().toStdString().c_str(),MY_PHI);
                }
                else if(strcmp(ui->parametro->text().toStdString().c_str(),"L") == 0){
                    res = Derivar(ui->entrada->text().toStdString().c_str(),MY_L);
                }
            }
            else{
                res = Derivar(ui->entrada->text().toStdString().c_str(),ui->parametro->text().toDouble());
            }
            strcat(saida,QString::number(res).toStdString().c_str());
            ui->saida->setText(saida);
            free(saida);
        }
    }
}

void MainWindow::on_Clear_clicked(){
    ui->saida->clear();
    ui->parametro->clear();
    ui->entrada->clear();
}

//aba das raizes
void MainWindow::on_metodo_activated(int index)
{
    int metodo = ui->metodo->currentIndex();
    if(metodo == 2 || metodo == 4){
        ui->chute_a->setVisible(0);
        ui->chute_b->setVisible(0);
        ui->a->setVisible(0);
        ui->b->setVisible(0);
        ui->chute_x0->setVisible(1);
        ui->x0->setVisible(1);
        if(metodo == 2){
            ui->multiplicidade->setVisible(1);
            ui->label_multiplicidade->setVisible(1);
        }
        else{
            ui->multiplicidade->setVisible(0);
            ui->label_multiplicidade->setVisible(0);
        }
    }
    else{
        ui->chute_a->setVisible(1);
        ui->chute_b->setVisible(1);
        ui->a->setVisible(1);
        ui->b->setVisible(1);
        ui->chute_x0->setVisible(0);
        ui->x0->setVisible(0);
        if(metodo != 3){
            ui->chute_a->setText("a");
            ui->chute_b->setText("b");
            ui->multiplicidade->setVisible(0);
            ui->label_multiplicidade->setVisible(0);
        }
        else{
            ui->chute_a->setText("x0");
            ui->chute_b->setText("x1");
            ui->multiplicidade->setVisible(1);
            ui->label_multiplicidade->setVisible(1);
        }
    }
}

void MainWindow::on_Limpar_clicked(){
    ui->funcao->clear();
    ui->a->clear();
    ui->b->clear();
    ui->x0->clear();
    ui->precisao->clear();
    ui->precisao2->clear();
    ui->max_it->clear();
    ui->display->clear();
}

void MainWindow::on_opcao_clicked(bool checked){
    if(ui->opcao->isChecked()){
        opcao = 1;
    }
    else{
        opcao = 0;
    }
}

void MainWindow::on_K_ideal_clicked(bool checked){
    double a,b,ep;
    if(ui->a->text().toStdString().c_str()[0] == '\0' || ui->b->text().toStdString().c_str()[0] == '\0' ||
    ui->precisao->text().toStdString().c_str()[0] == '\0'){
        ui->display->setText("Eu preciso que você preencha os campos a,b e precisão para que eu calcule o valor de k.");
    }
    else{
        a = ui->a->text().toDouble();
        b = ui->b->text().toDouble();
        ep = ui->precisao->text().toDouble();
        int k = (log(b - a) - log(ep))/log(2);
        ui->max_it->setText(QString::number(k));
        ui->display->clear();
    }
}

void MainWindow::on_Linkar_clicked(){
    ui->precisao2->setText(ui->precisao->text().toLocal8Bit());
}

void MainWindow::on_calcular_clicked(){
    int metodo = ui->metodo->currentIndex();
    int it = 0,erro;
    if(ui->funcao->text().toStdString().c_str()[0] == '\0' || ui->max_it->text().toStdString().c_str()[0] == '\0'
    || ui->precisao->text().toStdString().c_str()[0] == '\0' || ui->precisao2->text().toStdString().c_str()[0] == '\0'){
        if(ui->funcao->text().toStdString().c_str()[0] == '\0'){
            ui->display->setText("Eu preciso de uma função para trabalhar!");
        }
        else{
            ui->display->setText("Você não preencheu todos os campos obrigatórios!");
        }
    }
    else{
        char* saida;
        char* m_erro;
        saida = (char*)malloc(100 * sizeof(char));
        m_erro = (char*)malloc(100*sizeof(char));
        saida[0] = '\0';
        m_erro[0] = '\0';
        if(!Sintaxe_correta(ui->funcao->text().toStdString().c_str(),m_erro)){
            ui->display->setText(m_erro);
            free(m_erro);
        }
        else{
            if(metodo == 0){
                if(ui->a->text().toStdString().c_str()[0] == '\0' || ui->b->text().toStdString().c_str()[0] == '\0'){
                    ui->display->setText("Você não preencheu todos os campos obrigatórios!");
                }
                else{
                    resposta = Bissecao(ui->funcao->text().toStdString().c_str(),ui->a->text().toDouble(),ui->b->text().toDouble(),ui->precisao->text().toDouble(),ui->precisao2->text().toDouble(),ui->max_it->text().toInt(),it,erro,opcao);
                    if(erro == 0){
                        strcat(saida,"Após ");
                        strcat(saida,QString::number(it).toLocal8Bit());
                        strcat(saida," iterações eu cheguei a seguinte aproximação para a raíz: ");
                        strcat(saida,QString::number(resposta).toLocal8Bit());
                    }
                    else{
                        strcat(saida,"Desculpe, mas eu não consigo encontrar raíz entre os valores de a e b que vocẽ me passou.");
                    }
                }
            }
            if(metodo == 1){
                if(ui->a->text().toStdString().c_str()[0] == '\0' || ui->b->text().toStdString().c_str()[0] == '\0'){
                    ui->display->setText("Você não preencheu todos os campos obrigatórios!");
                }
                else{
                    resposta = Posicao_Falsa(ui->funcao->text().toStdString().c_str(),ui->a->text().toDouble(),ui->b->text().toDouble(),ui->precisao->text().toDouble(),ui->precisao2->text().toDouble(),ui->max_it->text().toInt(),it,erro,opcao);
                    if(erro == 0){
                        strcat(saida,"Após ");
                            strcat(saida,QString::number(it).toLocal8Bit());
                            strcat(saida," iterações eu cheguei a seguinte aproximação para a raíz: ");
                            strcat(saida,QString::number(resposta).toLocal8Bit());
                    }
                    else{
                        strcat(saida,"Desculpe, mas eu não consigo encontrar raíz entre os valores de a e b que vocẽ me passou.");
                    }
                }
            }
            if(metodo == 2){
                if(ui->x0->text().toStdString().c_str()[0] == '\0'){
                    ui->display->setText("Você não preencheu todos os campos obrigatórios!");
                }
                else{
                    resposta = Newton_Raphson(ui->funcao->text().toStdString().c_str(),ui->x0->text().toDouble(),ui->precisao->text().toDouble(),ui->precisao2->text().toDouble(),ui->max_it->text().toInt(),it,opcao,ui->multiplicidade->text().toDouble());
                    strcat(saida,"Após ");
                    strcat(saida,QString::number(it+1).toLocal8Bit());
                    strcat(saida," iterações eu cheguei a seguinte aproximação para a raíz: ");
                    strcat(saida,QString::number(resposta).toLocal8Bit());
                }
            }
            if(metodo == 3){
                if(ui->a->text().toStdString().c_str()[0] == '\0' || ui->b->text().toStdString().c_str()[0] == '\0'){
                    ui->display->setText("Você não preencheu todos os campos obrigatórios!");
                }
                else{
                    resposta = Secante(ui->funcao->text().toStdString().c_str(),ui->a->text().toDouble(),ui->b->text().toDouble(),ui->precisao->text().toDouble(),ui->precisao2->text().toDouble(),ui->max_it->text().toInt(),it,opcao,ui->multiplicidade->text().toDouble());
                    strcat(saida,"Após ");
                    strcat(saida,QString::number(it).toLocal8Bit());
                    strcat(saida," iterações eu cheguei a seguinte aproximação para a raíz: ");
                    strcat(saida,QString::number(resposta).toLocal8Bit());
                }
            }
            if(metodo == 4){
                if(ui->x0->text().toStdString().c_str()[0] == '\0'){
                     ui->display->setText("Você não preencheu todos os campos obrigatórios!");
                }
                else{
                    resposta = Ponto_Fixo(ui->funcao->text().toStdString().c_str(),ui->x0->text().toDouble(),ui->precisao->text().toDouble(),ui->precisao2->text().toDouble(),ui->max_it->text().toInt(),it,erro,opcao);
                    if(erro == 0){
                        strcat(saida,"Após ");
                        strcat(saida,QString::number(it).toLocal8Bit());
                        strcat(saida," iterações eu cheguei a seguinte aproximação para a raíz: ");
                        strcat(saida,QString::number(resposta).toLocal8Bit());
                    }
                    else{
                        strcat(saida,"Erro! Sua funcao Phi nao converge para x0 = ");
                        strcat(saida,ui->x0->text().toStdString().c_str());
                        strcat(saida,", sugiro escolher outra ou mudar o x0!");
                    }
                }
            }
            ui->display->setText(saida);
            free(saida);
        }
    }
}

//aba do conversor
void MainWindow::on_Numero_editingFinished(){
    strcpy(numero,ui->Numero->text().toLocal8Bit());
}

void MainWindow::on_Base_entrada_currentTextChanged(const QString &arg1){
    Base_entrada = ui->Base_entrada->currentText().toInt();
}

void MainWindow::on_Base_saida_currentTextChanged(const QString &arg1){
    Base_saida = ui->Base_saida->currentText().toInt();
}

void MainWindow::on_Converter_clicked(){
    int erro = 0;
    char* m_erro;
    m_erro = (char*)malloc(60 * sizeof(char));
    m_erro[0] = '\0';
    char *saida = Conversor_de_Base(Conversor_Reverso(numero,Base_entrada,erro,m_erro),Base_saida);
    if(erro == 0){
        ui->Resposta->setText(saida);
    }
    else{
        ui->Resposta->setText(m_erro);
    }
    free(m_erro);
}

//aba dos erros
void MainWindow::on_SPF_clicked(){
    resultado_SPF = SPF(ui->Numero2->text().toDouble(),ui->Base->value(),ui->Mantissa->value(),ui->Lower->value(),ui->Upper->value());
    int complemento = 1 + (log(ui->Numero2->text().toDouble())/log(ui->Base->value()));
    ui->Mostrador_SPF->setText(QString::number(resultado_SPF) + " x10^" + QString::number(complemento));
}

void MainWindow::on_maximo_clicked(){
   max = Maximo(ui->Base->value(),ui->Mantissa->value(),ui->Upper->value());
   ui->Mostrador_max->setText(QString::number(max));
}

void MainWindow::on_minimo_clicked(){
    min = Minimo(ui->Base->value(),ui->Mantissa->value(),ui->Lower->value());
    ui->Mostrador_min->setText(QString::number(min));
}

//aba dos sistemas de equações
void MainWindow::on_Calcular_determinante_clicked(){
        double* numeros = Guardar_numeros(ui->matriz_entrada->text().toStdString().c_str());
        if(ui->matriz_entrada->text().toStdString().c_str()[0] == '\0'){
            ui->display_determinante->setText("Eu preciso de uma matriz!");
        }
        else{
            if(IsQuadrada(ui->matriz_entrada->text().toStdString().c_str())){
                double** matrix;
                matrix = (double**)malloc(sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())) * sizeof(double*));
                int i,j,index = 0;
                for(i = 0; i < sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())); i++){
                    matrix[i] = (double*)malloc(sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())) * sizeof(double*));
                }
                for(i = 0; i < sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())); i++){
                    for(j = 0; j < sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())); j++){
                        matrix[i][j] = numeros[index];
                        index++;
                    }
                }
                int det = Determinante(i,j,matrix);
                ui->display_determinante->setText(QString::number(det));
                free(matrix);
            }
            else{
                ui->display_determinante->setText("Matriz não quadrada!");
            }
        }
}

void MainWindow::on_solucionar_clicked(){
    clock_t inicio,fim;
    float duracao;
    int metodo = ui->metodo_sistema->currentIndex();
    double* numeros = Guardar_numeros(ui->matriz_entrada->text().toStdString().c_str());
    double** matrix;
    matrix = (double**)malloc(sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())) * sizeof(double*));
    int i,j,index = 0;
    for(i = 0; i < sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())); i++){
        matrix[i] = (double*)malloc(sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())) * sizeof(double*));
    }
    for(i = 0; i < sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())); i++){
        for(j = 0; j < sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str())); j++){
            matrix[i][j] = numeros[index];
            index++;
        }
    }
    double* vetor = Guardar_numeros(ui->termos->text().toStdString().c_str());
    int ordem = sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str()));
    char* raizes;
    raizes = (char*)malloc(100 * sizeof(char));
    raizes[0] = '\0';
    if(metodo == 0){
        if(ui->termos->text().toStdString().c_str()[0] != '\0'){
            if(IsQuadrada(ui->matriz_entrada->text().toStdString().c_str())){
                int erro = 0;
                double *r;
                r = Cramer(i,j,matrix,vetor,erro);
                if(erro == 0){
                int xi;
                strcat(raizes,"Solução: {");
                for(xi = 0; xi < ordem; xi++){
                    strcat(raizes,QString::number(r[xi]).toStdString().c_str());
                    strcat(raizes,",");
                }
                raizes[strlen(raizes)-1] = '\0';
                strcat(raizes,"}");
                ui->raizes_sistema->setText(raizes);
                }
                else{
                    ui->raizes_sistema->setText("Sistema sem solução!");
                }
            }
            else{
                ui->raizes_sistema->setText("Matriz não quadrada!");
            }
        }
        else{
            ui->raizes_sistema->setText("Preencha o campo Termos independentes!");
        }
    }
    else if(metodo == 1){
        if(ui->termos->text().toStdString().c_str()[0] != '\0'){
            if(IsQuadrada(ui->matriz_entrada->text().toStdString().c_str())){
                double *r;
                r = Solucionar_triangular_inferior(i,matrix,vetor);
                int xi;
                strcat(raizes,"Solução: {");
                for(xi = 0; xi < ordem; xi++){
                    strcat(raizes,QString::number(r[xi]).toStdString().c_str());
                    strcat(raizes,",");
                }
                raizes[strlen(raizes)-1] = '\0';
                strcat(raizes,"}");
                ui->raizes_sistema->setText(raizes);
            }
            else{
                ui->raizes_sistema->setText("Matriz não quadrada!");
            }
        }
        else{
            ui->raizes_sistema->setText("Preencha o campo Termos independentes!");
        }
    }
    else if(metodo == 2){
        if(ui->termos->text().toStdString().c_str()[0] != '\0'){
            if(IsQuadrada(ui->matriz_entrada->text().toStdString().c_str())){
                Transformar_triangular_superior(i,j,matrix);
                double *r;
                r = Solucionar_triangular_superior(i,matrix,vetor);
                int xi;
                strcat(raizes,"Solução: {");
                for(xi = 0; xi < ordem; xi++){
                    strcat(raizes,QString::number(r[xi]).toStdString().c_str());
                    strcat(raizes,",");
                }
                raizes[strlen(raizes)-1] = '\0';
                strcat(raizes,"}");
                ui->raizes_sistema->setText(raizes);
            }
            else{
                ui->raizes_sistema->setText("Matriz não quadrada!");
            }
        }
        else{
            ui->raizes_sistema->setText("Preencha o campo Termos independentes!");
        }
    }
    else if(metodo == 3){
        if(ui->termos->text().toStdString().c_str()[0] != '\0'){
            if(IsQuadrada(ui->matriz_entrada->text().toStdString().c_str())){
                double *r;
                r = Gauss(i,j,matrix,vetor);
                int xi;
                strcat(raizes,"Solução: {");
                for(xi = 0; xi < ordem; xi++){
                    strcat(raizes,QString::number(r[xi]).toStdString().c_str());
                    strcat(raizes,",");
                }
                raizes[strlen(raizes)-1] = '\0';
                strcat(raizes,"}");
                ui->raizes_sistema->setText(raizes);
            }
            else{
                ui->raizes_sistema->setText("Matriz não quadrada!");
            }
        }
        else{
            ui->raizes_sistema->setText("Preencha o campo Termos independentes!");
        }
    }
    else if(metodo == 4){
        if(ui->termos->text().toStdString().c_str()[0] != '\0'){
            if(IsQuadrada(ui->matriz_entrada->text().toStdString().c_str())){
                double *r;
                r = Gauss_jordan(i,matrix,vetor);
                int xi;
                strcat(raizes,"Solução: {");
                for(xi = 0; xi < ordem; xi++){
                    strcat(raizes,QString::number(r[xi]).toStdString().c_str());
                    strcat(raizes,",");
                }
                raizes[strlen(raizes)-1] = '\0';
                strcat(raizes,"}");
                ui->raizes_sistema->setText(raizes);
            }
            else{
                ui->raizes_sistema->setText("Matriz não quadrada!");
            }
        }
        else{
            ui->raizes_sistema->setText("Preencha o campo Termos independentes!");
        }
    }
    else if(metodo == 5){
        if(ui->termos->text().toStdString().c_str()[0] != '\0' || ui->precisao_entrada->text().toStdString().c_str()[0] == '\0'
            || ui->chute_entrada->text().toStdString().c_str()[0] == '\0' || ui->iteracoes_entrada->text().toStdString().c_str()[0] == '\0'){
            if(IsQuadrada(ui->matriz_entrada->text().toStdString().c_str())){
                double* chute = Guardar_numeros(ui->chute_entrada->text().toStdString().c_str());
                int max_it = ui->iteracoes_entrada->text().toInt();
                double precisao = ui->precisao_entrada->text().toDouble();
                double *r;
                r = Gauss_Jacob(i,j,matrix,vetor,chute,max_it,precisao);
                int xi;
                strcat(raizes,"Solução: {");
                for(xi = 0; xi < ordem; xi++){
                    strcat(raizes,QString::number(r[xi]).toStdString().c_str());
                    strcat(raizes,",");
                }
                raizes[strlen(raizes)-1] = '\0';
                strcat(raizes,"}");
                ui->raizes_sistema->setText(raizes);
            }
            else{
                ui->raizes_sistema->setText("Matriz não quadrada!");
            }
        }
        else{
            ui->raizes_sistema->setText("Preencha os campos obrigatórios!");
        }
    }
    else if(metodo == 7){
        if(ui->termos->text().toStdString().c_str()[0] != '\0'){
            if(IsQuadrada(ui->matriz_entrada->text().toStdString().c_str())){
                double *r;
                inicio = clock();
                r = Solucionar_Doolittle(i,matrix,vetor);
                fim = clock();
                duracao = (float)(fim - inicio)/CLOCKS_PER_SEC;
                int xi;
                strcat(raizes,"Solução: {");
                for(xi = 0; xi < ordem; xi++){
                    strcat(raizes,QString::number(r[xi]).toStdString().c_str());
                    strcat(raizes,",");
                }
                raizes[strlen(raizes)-1] = '\0';
                strcat(raizes,"}");
                //strcat(raizes,"    Tempo: ");
                //strcat(raizes,QString::number(duracao).toStdString().c_str());
                ui->raizes_sistema->setText(raizes);
            }
            else{
                ui->raizes_sistema->setText("Matriz não quadrada!");
            }
        }
        else{
            ui->raizes_sistema->setText("Preencha o campo Termos independentes!");
        }
    }
    free(matrix);
    free(raizes);
}

void MainWindow::on_matriz_entrada_editingFinished()
{
    char* matriz_representada;
    matriz_representada = (char*)malloc(strlen(ui->matriz_entrada->text().toStdString().c_str()) - 4 * sizeof(char));
    matriz_representada = '\0';
    matriz_representada = Gerar_representacao_matricial(ui->matriz_entrada->text().toStdString().c_str());
    ui->texto_matriz->setText("Representação Matricial: ");
    ui->matriz_representada->setText(matriz_representada);
    char ordem[5];
    ordem[0] = '\0';
    int l,c;
    Calcular_ordem(ui->matriz_entrada->text().toStdString().c_str(),l,c);
    strcat(ordem,QString::number(l).toStdString().c_str());
    strcat(ordem,"x");
    strcat(ordem,QString::number(c).toStdString().c_str());
    if(ui->matriz_entrada->text().toStdString().c_str()[0] != '\0'){
        ui->ordem->setText(ordem);
    }
    else{
        ui->ordem->setText(" ");
    }
    if(ui->imprimir_matriz->isChecked()){
        FILE* k;
        k = fopen("Matriz.txt","w");
        fprintf(k,"Matriz: ");
        fprintf(k,ordem);
        fprintf(k,"\n\n");
        fprintf(k,matriz_representada);
        fclose(k);
    }
    free(matriz_representada);
}
void MainWindow::on_transformacoes_activated(int index)
{
    int op = ui->transformacoes->currentIndex();
    double* numeros = Guardar_numeros(ui->matriz_entrada->text().toStdString().c_str());
    int n = sqrt(Contar_numeros(ui->matriz_entrada->text().toStdString().c_str()));
    double** matrix;
    matrix = (double**)malloc(n * sizeof(double*));
    int i,j;
    for(i = 0; i < n; i++){
        matrix[i] = (double*)malloc(n * sizeof(double*));
    }
    int indice = 0;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matrix[i][j] = numeros[indice];
            indice++;
        }
    }
    double** saida;
    saida = (double**)malloc(n * sizeof(double*));
    for(i = 0; i < n; i++){
        saida[i] = (double*)malloc(n * sizeof(double));
    }
    double** saida2;
    saida2 = (double**)malloc(n * sizeof(double*));
    for(i = 0; i < n; i++){
        saida2[i] = (double*)malloc(n * sizeof(double));
    }
    if(op == 0){
        Transposta(i,j,matrix,saida);
        ui->texto_matriz->setText("Matriz Transposta: ");
    }
    else if(op == 1){
        Gerar_identidade(n,n,saida);
        Inversa(n,n,matrix,saida);
        ui->texto_matriz->setText("Matriz Inversa: ");
    }
    else if(op == 2){
        Gerar_LU_Doolittle(i,matrix,saida,saida2);
        ui->texto_matriz->setText("LU: ");
    }
    char* saida_t;
    saida_t = (char*)malloc(1024 * sizeof(char));
    saida_t[0] = '\0';
    strcat(saida_t,"{");
    for(i = 0; i < n; i++){
        strcat(saida_t,"{");
        for(j = 0; j < n; j++){
            strcat(saida_t,QString::number(saida[i][j]).toStdString().c_str());
            if(j != n-1){
                strcat(saida_t,",");
            }
        }
        if(i != n-1){
            strcat(saida_t,"},");
        }
    }
    if(op == 2){
        strcat(saida_t,"},\n");
        for(i = 0; i < n; i++){
            strcat(saida_t,"{");
            for(j = 0; j < n; j++){
                strcat(saida_t,QString::number(saida2[i][j]).toStdString().c_str());
                if(j != n-1){
                    strcat(saida_t,",");
                }
            }
            if(i != n-1){
                strcat(saida_t,"},");
            }
        }
    }
    strcat(saida_t,"}}");
    saida_t = Gerar_representacao_matricial(saida_t);
    ui->matriz_representada->setText(saida_t);
    if(ui->imprimir_matriz->isChecked()){
        FILE* k;
        k = fopen("Matriz.txt","a");
        if(op == 0){
            fprintf(k,"\n\nMatriz Transposta: \n\n");
        }
        else if(op == 1){
            fprintf(k,"\n\nMatriz Inversa: \n\n");
        }
        else if(op == 2){
            fprintf(k,"\n\nDecomposição LU: \n\n");
        }
        fprintf(k,saida_t);
        fclose(k);
    }
    free(matrix);
    free(saida);
    free(saida_t);
}

void MainWindow::on_metodo_sistema_activated(int index)
{
    int metodo = ui->metodo_sistema->currentIndex();
    if(metodo != 5 && metodo != 6){
        ui->chute_label->setHidden(1);
        ui->chute_entrada->setHidden(1);
        ui->precisao_label->setHidden(1);
        ui->precisao_entrada->setHidden(1);
        ui->iteracoes_label->setHidden(1);
        ui->iteracoes_entrada->setHidden(1);
    }
    else{
        ui->chute_entrada->setVisible(1);
        ui->chute_label->setVisible(1);
        ui->precisao_entrada->setVisible(1);
        ui->precisao_label->setVisible(1);
        ui->iteracoes_label->setVisible(1);
        ui->iteracoes_entrada->setVisible(1);
    }
}

void MainWindow::on_Solver_tabBarClicked(int index)
{
    ui->chute_label->setHidden(1);
    ui->chute_entrada->setHidden(1);
    ui->precisao_label->setHidden(1);
    ui->precisao_entrada->setHidden(1);
    ui->iteracoes_label->setHidden(1);
    ui->iteracoes_entrada->setHidden(1);

    ui->metodo->setCurrentIndex(0);
    ui->chute_a->setText("a");
    ui->chute_b->setText("b");
    ui->a->setVisible(1);
    ui->b->setVisible(1);
    ui->chute_x0->setVisible(0);
    ui->x0->setVisible(0);
    ui->multiplicidade->setVisible(0);
    ui->label_multiplicidade->setVisible(0);
}
