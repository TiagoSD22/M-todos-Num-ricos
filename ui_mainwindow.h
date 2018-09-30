/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *Solver;
    QWidget *tab_5;
    QLabel *label_15;
    QLabel *label_19;
    QLabel *label_22;
    QWidget *tab;
    QPushButton *Converter;
    QLabel *Resposta;
    QComboBox *Base_saida;
    QComboBox *Base_entrada;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *Numero;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *tab_2;
    QLabel *Mostrador_SPF;
    QLineEdit *Numero2;
    QPushButton *SPF;
    QLabel *label_11;
    QPushButton *minimo;
    QSpinBox *Mantissa;
    QLabel *label_12;
    QSpinBox *Base;
    QSpinBox *Upper;
    QSpinBox *Lower;
    QLabel *Mostrador_max;
    QLabel *label_13;
    QLabel *label4;
    QPushButton *maximo;
    QLabel *label_14;
    QLabel *Mostrador_min;
    QWidget *tab_3;
    QLabel *label_5;
    QComboBox *metodo;
    QLineEdit *precisao;
    QLineEdit *precisao2;
    QLabel *label_2;
    QLabel *chute_b;
    QLineEdit *b;
    QLabel *chute_a;
    QLabel *label;
    QPushButton *calcular;
    QLabel *label_6;
    QLabel *display;
    QLineEdit *funcao;
    QLineEdit *a;
    QCheckBox *opcao;
    QLineEdit *x0;
    QLineEdit *max_it;
    QLabel *label_18;
    QRadioButton *K_ideal;
    QPushButton *Limpar;
    QPushButton *Linkar;
    QLineEdit *multiplicidade;
    QLabel *label_multiplicidade;
    QLabel *chute_x0;
    QWidget *tab_6;
    QLabel *saida;
    QLineEdit *parametro;
    QPushButton *calcular_derivada;
    QLabel *label_23;
    QLabel *label_24;
    QPushButton *calcular_2;
    QLineEdit *entrada;
    QLabel *label_25;
    QPushButton *Clear;
    QLineEdit *Name;
    QWidget *tab_4;
    QTextBrowser *textBrowser;
    QWidget *tab_7;
    QLineEdit *matriz_entrada;
    QLabel *label_26;
    QTextBrowser *matriz_representada;
    QLabel *texto_matriz;
    QLabel *label_28;
    QPushButton *Calcular_determinante;
    QLabel *display_determinante;
    QComboBox *metodo_sistema;
    QLabel *label_29;
    QPushButton *solucionar;
    QLineEdit *termos;
    QLabel *label_30;
    QLabel *raizes_sistema;
    QLabel *ordem;
    QCheckBox *imprimir_matriz;
    QComboBox *transformacoes;
    QLabel *chute_label;
    QLineEdit *chute_entrada;
    QLabel *iteracoes_label;
    QLabel *precisao_label;
    QLineEdit *iteracoes_entrada;
    QLineEdit *precisao_entrada;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(632, 377);
        QIcon icon;
        icon.addFile(QStringLiteral("Alecive-Flatwoken-Apps-Libreoffice-Math.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow{\n"
"background-color:\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Solver = new QTabWidget(centralWidget);
        Solver->setObjectName(QStringLiteral("Solver"));
        Solver->setEnabled(true);
        Solver->setGeometry(QRect(0, 0, 631, 311));
        Solver->setCursor(QCursor(Qt::PointingHandCursor));
        Solver->setFocusPolicy(Qt::NoFocus);
        Solver->setAutoFillBackground(false);
        Solver->setStyleSheet(QLatin1String("QTabWidget::pane { /* The tab widget frame */\n"
"         border-top: 2px solid #C2C7CB;\n"
"         position: absolute;\n"
"         top: -0.5em;\n"
"     }\n"
"\n"
"     QTabWidget::tab-bar {\n"
"         alignment: center;\n"
"     }\n"
"\n"
"     /* Style the tab using the tab sub-control. Note that\n"
"         it reads QTabBar _not_ QTabWidget */\n"
"     QTabBar::tab {\n"
"         background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                     stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                     stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
"         border: 2px solid #C4C4C3;\n"
"         border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"         border-top-left-radius: 4px;\n"
"         border-top-right-radius: 4px;\n"
"         min-width: 8ex;\n"
"         padding: 2px;\n"
"     }\n"
"\n"
"     QTabBar::tab:selected, QTabBar::tab:hover {\n"
"         background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                       "
                        "              stop: 0 #fafafa, stop: 0.4 #f4f4f4,\n"
"                                     stop: 0.5 #e7e7e7, stop: 1.0 #fafafa);\n"
"	background-color: rgb(41, 168, 170)\n"
"     }\n"
"\n"
"     QTabBar::tab:selected {\n"
"         border-color: #9B9B9B;\n"
"         border-bottom-color: #C2C7CB; /* same as pane color */\n"
"     }\n"
""));
        Solver->setTabPosition(QTabWidget::North);
        Solver->setTabShape(QTabWidget::Rounded);
        Solver->setElideMode(Qt::ElideNone);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_15 = new QLabel(tab_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(160, 50, 371, 41));
        label_19 = new QLabel(tab_5);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(20, 110, 521, 51));
        label_22 = new QLabel(tab_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 160, 211, 17));
        Solver->addTab(tab_5, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        Converter = new QPushButton(tab);
        Converter->setObjectName(QStringLiteral("Converter"));
        Converter->setGeometry(QRect(390, 140, 75, 22));
        Converter->setCursor(QCursor(Qt::PointingHandCursor));
        Resposta = new QLabel(tab);
        Resposta->setObjectName(QStringLiteral("Resposta"));
        Resposta->setGeometry(QRect(50, 240, 511, 16));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        Resposta->setFont(font);
        Resposta->setCursor(QCursor(Qt::IBeamCursor));
        Resposta->setStyleSheet(QLatin1String("QLabel{\n"
"background-color:rgb(85, 170, 127);\n"
"}\n"
""));
        Resposta->setFrameShape(QFrame::Box);
        Resposta->setScaledContents(false);
        Resposta->setAlignment(Qt::AlignCenter);
        Base_saida = new QComboBox(tab);
        Base_saida->setObjectName(QStringLiteral("Base_saida"));
        Base_saida->setGeometry(QRect(390, 80, 69, 22));
        Base_entrada = new QComboBox(tab);
        Base_entrada->setObjectName(QStringLiteral("Base_entrada"));
        Base_entrada->setGeometry(QRect(90, 140, 69, 22));
        Base_entrada->setCursor(QCursor(Qt::PointingHandCursor));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 50, 181, 31));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 110, 241, 31));
        Numero = new QLineEdit(tab);
        Numero->setObjectName(QStringLiteral("Numero"));
        Numero->setGeometry(QRect(90, 80, 113, 22));
        Numero->setToolTipDuration(1);
        Numero->setAutoFillBackground(false);
        Numero->setInputMethodHints(Qt::ImhDigitsOnly|Qt::ImhUppercaseOnly);
        Numero->setMaxLength(50);
        Numero->setClearButtonEnabled(true);
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(320, 50, 281, 31));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(220, 220, 261, 16));
        Solver->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Mostrador_SPF = new QLabel(tab_2);
        Mostrador_SPF->setObjectName(QStringLiteral("Mostrador_SPF"));
        Mostrador_SPF->setGeometry(QRect(100, 20, 181, 17));
        Mostrador_SPF->setCursor(QCursor(Qt::IBeamCursor));
        Mostrador_SPF->setStyleSheet(QLatin1String("QLabel{\n"
"background-color:rgb(85, 170, 127);\n"
"}"));
        Mostrador_SPF->setFrameShape(QFrame::Box);
        Numero2 = new QLineEdit(tab_2);
        Numero2->setObjectName(QStringLiteral("Numero2"));
        Numero2->setGeometry(QRect(270, 165, 113, 27));
        SPF = new QPushButton(tab_2);
        SPF->setObjectName(QStringLiteral("SPF"));
        SPF->setGeometry(QRect(10, 15, 61, 27));
        SPF->setCursor(QCursor(Qt::PointingHandCursor));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(390, 95, 67, 17));
        minimo = new QPushButton(tab_2);
        minimo->setObjectName(QStringLiteral("minimo"));
        minimo->setGeometry(QRect(10, 115, 61, 27));
        minimo->setCursor(QCursor(Qt::PointingHandCursor));
        Mantissa = new QSpinBox(tab_2);
        Mantissa->setObjectName(QStringLiteral("Mantissa"));
        Mantissa->setGeometry(QRect(340, 50, 48, 27));
        Mantissa->setMinimum(1);
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(390, 20, 67, 17));
        Base = new QSpinBox(tab_2);
        Base->setObjectName(QStringLiteral("Base"));
        Base->setGeometry(QRect(340, 15, 48, 27));
        Base->setMinimum(2);
        Base->setMaximum(36);
        Base->setValue(10);
        Upper = new QSpinBox(tab_2);
        Upper->setObjectName(QStringLiteral("Upper"));
        Upper->setGeometry(QRect(340, 130, 48, 27));
        Upper->setMinimum(-99);
        Lower = new QSpinBox(tab_2);
        Lower->setObjectName(QStringLiteral("Lower"));
        Lower->setGeometry(QRect(340, 90, 48, 27));
        Lower->setMinimum(-99);
        Mostrador_max = new QLabel(tab_2);
        Mostrador_max->setObjectName(QStringLiteral("Mostrador_max"));
        Mostrador_max->setGeometry(QRect(100, 70, 181, 17));
        Mostrador_max->setCursor(QCursor(Qt::IBeamCursor));
        Mostrador_max->setStyleSheet(QLatin1String("QLabel{\n"
"background-color:rgb(85, 170, 127);\n"
"}"));
        Mostrador_max->setFrameShape(QFrame::Box);
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(390, 170, 67, 17));
        label4 = new QLabel(tab_2);
        label4->setObjectName(QStringLiteral("label4"));
        label4->setGeometry(QRect(390, 135, 67, 17));
        maximo = new QPushButton(tab_2);
        maximo->setObjectName(QStringLiteral("maximo"));
        maximo->setGeometry(QRect(10, 65, 61, 27));
        maximo->setCursor(QCursor(Qt::PointingHandCursor));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(390, 55, 67, 17));
        Mostrador_min = new QLabel(tab_2);
        Mostrador_min->setObjectName(QStringLiteral("Mostrador_min"));
        Mostrador_min->setGeometry(QRect(100, 120, 181, 17));
        Mostrador_min->setCursor(QCursor(Qt::IBeamCursor));
        Mostrador_min->setStyleSheet(QLatin1String("QLabel{\n"
"background-color:rgb(85, 170, 127);\n"
"}"));
        Mostrador_min->setFrameShape(QFrame::Box);
        Solver->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(262, 70, 67, 17));
        metodo = new QComboBox(tab_3);
        metodo->setObjectName(QStringLiteral("metodo"));
        metodo->setGeometry(QRect(3, 110, 85, 27));
        metodo->setCursor(QCursor(Qt::PointingHandCursor));
        precisao = new QLineEdit(tab_3);
        precisao->setObjectName(QStringLiteral("precisao"));
        precisao->setGeometry(QRect(260, 90, 111, 27));
        precisao->setDragEnabled(true);
        precisao2 = new QLineEdit(tab_3);
        precisao2->setObjectName(QStringLiteral("precisao2"));
        precisao2->setGeometry(QRect(390, 90, 111, 27));
        precisao2->setDragEnabled(true);
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(3, 80, 67, 17));
        chute_b = new QLabel(tab_3);
        chute_b->setObjectName(QStringLiteral("chute_b"));
        chute_b->setGeometry(QRect(182, 90, 67, 17));
        b = new QLineEdit(tab_3);
        b->setObjectName(QStringLiteral("b"));
        b->setGeometry(QRect(180, 110, 61, 27));
        b->setDragEnabled(true);
        chute_a = new QLabel(tab_3);
        chute_a->setObjectName(QStringLiteral("chute_a"));
        chute_a->setGeometry(QRect(102, 90, 67, 17));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(3, 10, 67, 17));
        calcular = new QPushButton(tab_3);
        calcular->setObjectName(QStringLiteral("calcular"));
        calcular->setGeometry(QRect(503, 110, 61, 27));
        calcular->setCursor(QCursor(Qt::PointingHandCursor));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(392, 70, 81, 17));
        display = new QLabel(tab_3);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(3, 250, 621, 21));
        display->setCursor(QCursor(Qt::IBeamCursor));
        display->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color:rgb(85, 170, 127);\n"
"}"));
        display->setFrameShape(QFrame::Box);
        display->setTextInteractionFlags(Qt::TextBrowserInteraction);
        funcao = new QLineEdit(tab_3);
        funcao->setObjectName(QStringLiteral("funcao"));
        funcao->setGeometry(QRect(3, 40, 201, 27));
        funcao->setDragEnabled(true);
        funcao->setClearButtonEnabled(true);
        a = new QLineEdit(tab_3);
        a->setObjectName(QStringLiteral("a"));
        a->setGeometry(QRect(100, 110, 61, 27));
        a->setDragEnabled(true);
        opcao = new QCheckBox(tab_3);
        opcao->setObjectName(QStringLiteral("opcao"));
        opcao->setGeometry(QRect(440, 220, 181, 22));
        opcao->setCursor(QCursor(Qt::PointingHandCursor));
        x0 = new QLineEdit(tab_3);
        x0->setObjectName(QStringLiteral("x0"));
        x0->setGeometry(QRect(140, 110, 61, 27));
        x0->setDragEnabled(true);
        max_it = new QLineEdit(tab_3);
        max_it->setObjectName(QStringLiteral("max_it"));
        max_it->setGeometry(QRect(260, 120, 61, 27));
        max_it->setDragEnabled(true);
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(330, 120, 161, 20));
        K_ideal = new QRadioButton(tab_3);
        K_ideal->setObjectName(QStringLiteral("K_ideal"));
        K_ideal->setGeometry(QRect(330, 140, 141, 22));
        K_ideal->setCursor(QCursor(Qt::PointingHandCursor));
        Limpar = new QPushButton(tab_3);
        Limpar->setObjectName(QStringLiteral("Limpar"));
        Limpar->setGeometry(QRect(580, 110, 51, 27));
        Limpar->setCursor(QCursor(Qt::PointingHandCursor));
        Linkar = new QPushButton(tab_3);
        Linkar->setObjectName(QStringLiteral("Linkar"));
        Linkar->setGeometry(QRect(370, 90, 21, 27));
        Linkar->setCursor(QCursor(Qt::PointingHandCursor));
        multiplicidade = new QLineEdit(tab_3);
        multiplicidade->setObjectName(QStringLiteral("multiplicidade"));
        multiplicidade->setGeometry(QRect(220, 40, 61, 27));
        multiplicidade->setDragEnabled(true);
        label_multiplicidade = new QLabel(tab_3);
        label_multiplicidade->setObjectName(QStringLiteral("label_multiplicidade"));
        label_multiplicidade->setGeometry(QRect(220, 10, 111, 17));
        chute_x0 = new QLabel(tab_3);
        chute_x0->setObjectName(QStringLiteral("chute_x0"));
        chute_x0->setGeometry(QRect(140, 90, 67, 17));
        Solver->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        saida = new QLabel(tab_6);
        saida->setObjectName(QStringLiteral("saida"));
        saida->setGeometry(QRect(10, 190, 611, 21));
        QFont font1;
        font1.setPointSize(11);
        saida->setFont(font1);
        saida->setCursor(QCursor(Qt::IBeamCursor));
        saida->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color:rgb(85, 170, 127);\n"
"}"));
        saida->setFrameShape(QFrame::Box);
        saida->setAlignment(Qt::AlignCenter);
        saida->setWordWrap(false);
        saida->setTextInteractionFlags(Qt::TextBrowserInteraction);
        parametro = new QLineEdit(tab_6);
        parametro->setObjectName(QStringLiteral("parametro"));
        parametro->setGeometry(QRect(10, 120, 81, 27));
        calcular_derivada = new QPushButton(tab_6);
        calcular_derivada->setObjectName(QStringLiteral("calcular_derivada"));
        calcular_derivada->setGeometry(QRect(140, 150, 131, 27));
        calcular_derivada->setCursor(QCursor(Qt::PointingHandCursor));
        label_23 = new QLabel(tab_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 160, 91, 17));
        label_24 = new QLabel(tab_6);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 35, 67, 17));
        calcular_2 = new QPushButton(tab_6);
        calcular_2->setObjectName(QStringLiteral("calcular_2"));
        calcular_2->setGeometry(QRect(140, 120, 131, 27));
        calcular_2->setCursor(QCursor(Qt::PointingHandCursor));
        entrada = new QLineEdit(tab_6);
        entrada->setObjectName(QStringLiteral("entrada"));
        entrada->setGeometry(QRect(10, 60, 201, 27));
        label_25 = new QLabel(tab_6);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(10, 100, 131, 17));
        Clear = new QPushButton(tab_6);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(290, 133, 61, 27));
        Clear->setCursor(QCursor(Qt::PointingHandCursor));
        Name = new QLineEdit(tab_6);
        Name->setObjectName(QStringLiteral("Name"));
        Name->setGeometry(QRect(70, 30, 81, 27));
        Solver->addTab(tab_6, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        textBrowser = new QTextBrowser(tab_4);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(10, 10, 631, 281));
        Solver->addTab(tab_4, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        matriz_entrada = new QLineEdit(tab_7);
        matriz_entrada->setObjectName(QStringLiteral("matriz_entrada"));
        matriz_entrada->setGeometry(QRect(8, 45, 521, 27));
        matriz_entrada->setClearButtonEnabled(true);
        label_26 = new QLabel(tab_7);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 20, 67, 17));
        matriz_representada = new QTextBrowser(tab_7);
        matriz_representada->setObjectName(QStringLiteral("matriz_representada"));
        matriz_representada->setGeometry(QRect(10, 100, 256, 192));
        matriz_representada->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        matriz_representada->setUndoRedoEnabled(true);
        matriz_representada->setReadOnly(false);
        matriz_representada->setOverwriteMode(false);
        texto_matriz = new QLabel(tab_7);
        texto_matriz->setObjectName(QStringLiteral("texto_matriz"));
        texto_matriz->setGeometry(QRect(10, 80, 211, 17));
        label_28 = new QLabel(tab_7);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(490, 80, 111, 17));
        Calcular_determinante = new QPushButton(tab_7);
        Calcular_determinante->setObjectName(QStringLiteral("Calcular_determinante"));
        Calcular_determinante->setGeometry(QRect(270, 100, 161, 27));
        Calcular_determinante->setCursor(QCursor(Qt::PointingHandCursor));
        display_determinante = new QLabel(tab_7);
        display_determinante->setObjectName(QStringLiteral("display_determinante"));
        display_determinante->setGeometry(QRect(440, 105, 191, 20));
        display_determinante->setCursor(QCursor(Qt::IBeamCursor));
        display_determinante->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color:rgb(85, 170, 127);\n"
"}"));
        display_determinante->setAlignment(Qt::AlignCenter);
        display_determinante->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        metodo_sistema = new QComboBox(tab_7);
        metodo_sistema->setObjectName(QStringLiteral("metodo_sistema"));
        metodo_sistema->setGeometry(QRect(270, 160, 85, 27));
        metodo_sistema->setCursor(QCursor(Qt::PointingHandCursor));
        label_29 = new QLabel(tab_7);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(270, 140, 131, 17));
        solucionar = new QPushButton(tab_7);
        solucionar->setObjectName(QStringLiteral("solucionar"));
        solucionar->setGeometry(QRect(270, 248, 141, 27));
        solucionar->setCursor(QCursor(Qt::PointingHandCursor));
        termos = new QLineEdit(tab_7);
        termos->setObjectName(QStringLiteral("termos"));
        termos->setGeometry(QRect(270, 220, 161, 27));
        termos->setClearButtonEnabled(true);
        label_30 = new QLabel(tab_7);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(270, 200, 161, 17));
        raizes_sistema = new QLabel(tab_7);
        raizes_sistema->setObjectName(QStringLiteral("raizes_sistema"));
        raizes_sistema->setGeometry(QRect(270, 275, 351, 17));
        raizes_sistema->setCursor(QCursor(Qt::IBeamCursor));
        raizes_sistema->setStyleSheet(QLatin1String("QLabel{\n"
"	background-color:rgb(85, 170, 127);\n"
"}\n"
""));
        raizes_sistema->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);
        ordem = new QLabel(tab_7);
        ordem->setObjectName(QStringLiteral("ordem"));
        ordem->setGeometry(QRect(200, 80, 67, 17));
        ordem->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        imprimir_matriz = new QCheckBox(tab_7);
        imprimir_matriz->setObjectName(QStringLiteral("imprimir_matriz"));
        imprimir_matriz->setGeometry(QRect(180, 270, 97, 22));
        transformacoes = new QComboBox(tab_7);
        transformacoes->setObjectName(QStringLiteral("transformacoes"));
        transformacoes->setGeometry(QRect(529, 45, 102, 27));
        chute_label = new QLabel(tab_7);
        chute_label->setObjectName(QStringLiteral("chute_label"));
        chute_label->setGeometry(QRect(440, 140, 67, 17));
        chute_entrada = new QLineEdit(tab_7);
        chute_entrada->setObjectName(QStringLiteral("chute_entrada"));
        chute_entrada->setGeometry(QRect(440, 160, 161, 27));
        iteracoes_label = new QLabel(tab_7);
        iteracoes_label->setObjectName(QStringLiteral("iteracoes_label"));
        iteracoes_label->setGeometry(QRect(440, 233, 151, 17));
        precisao_label = new QLabel(tab_7);
        precisao_label->setObjectName(QStringLiteral("precisao_label"));
        precisao_label->setGeometry(QRect(440, 190, 67, 17));
        iteracoes_entrada = new QLineEdit(tab_7);
        iteracoes_entrada->setObjectName(QStringLiteral("iteracoes_entrada"));
        iteracoes_entrada->setGeometry(QRect(440, 250, 51, 23));
        precisao_entrada = new QLineEdit(tab_7);
        precisao_entrada->setObjectName(QStringLiteral("precisao_entrada"));
        precisao_entrada->setGeometry(QRect(440, 210, 81, 23));
        Solver->addTab(tab_7, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 632, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        mainToolBar->addSeparator();
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        Solver->setCurrentIndex(0);
        Base_entrada->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Projeto", 0));
        label_15->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">Projeto para disciplina de M\303\251todos Num\303\251ricos I</span></p></body></html>", 0));
        label_19->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Desenvolvedor:</p></body></html>", 0));
#ifndef QT_NO_STATUSTIP
        label_22->setStatusTip(QApplication::translate("MainWindow", "Eu sou Foda! Hahaha!", 0));
#endif // QT_NO_STATUSTIP
        label_22->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">-TIAGO SIQUEIRA DIONIZIO</span></p></body></html>", 0));
        Solver->setTabText(Solver->indexOf(tab_5), QApplication::translate("MainWindow", "In\303\255cio", 0));
        Converter->setText(QApplication::translate("MainWindow", "Converter", 0));
        Converter->setShortcut(QApplication::translate("MainWindow", "Return", 0));
        Resposta->setText(QString());
        Base_saida->clear();
        Base_saida->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
         << QApplication::translate("MainWindow", "9", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "11", 0)
         << QApplication::translate("MainWindow", "12", 0)
         << QApplication::translate("MainWindow", "13", 0)
         << QApplication::translate("MainWindow", "14", 0)
         << QApplication::translate("MainWindow", "15", 0)
         << QApplication::translate("MainWindow", "16", 0)
         << QApplication::translate("MainWindow", "17", 0)
         << QApplication::translate("MainWindow", "18", 0)
         << QApplication::translate("MainWindow", "19", 0)
         << QApplication::translate("MainWindow", "20", 0)
         << QApplication::translate("MainWindow", "21", 0)
         << QApplication::translate("MainWindow", "22", 0)
         << QApplication::translate("MainWindow", "23", 0)
         << QApplication::translate("MainWindow", "24", 0)
         << QApplication::translate("MainWindow", "25", 0)
         << QApplication::translate("MainWindow", "26", 0)
         << QApplication::translate("MainWindow", "27", 0)
         << QApplication::translate("MainWindow", "28", 0)
         << QApplication::translate("MainWindow", "29", 0)
         << QApplication::translate("MainWindow", "30", 0)
         << QApplication::translate("MainWindow", "31", 0)
         << QApplication::translate("MainWindow", "32", 0)
         << QApplication::translate("MainWindow", "33", 0)
         << QApplication::translate("MainWindow", "34", 0)
         << QApplication::translate("MainWindow", "35", 0)
         << QApplication::translate("MainWindow", "36", 0)
        );
        Base_saida->setCurrentText(QApplication::translate("MainWindow", "2", 0));
        Base_entrada->clear();
        Base_entrada->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
         << QApplication::translate("MainWindow", "9", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "11", 0)
         << QApplication::translate("MainWindow", "12", 0)
         << QApplication::translate("MainWindow", "13", 0)
         << QApplication::translate("MainWindow", "14", 0)
         << QApplication::translate("MainWindow", "15", 0)
         << QApplication::translate("MainWindow", "16", 0)
         << QApplication::translate("MainWindow", "17", 0)
         << QApplication::translate("MainWindow", "18", 0)
         << QApplication::translate("MainWindow", "19", 0)
         << QApplication::translate("MainWindow", "20", 0)
         << QApplication::translate("MainWindow", "21", 0)
         << QApplication::translate("MainWindow", "22", 0)
         << QApplication::translate("MainWindow", "23", 0)
         << QApplication::translate("MainWindow", "24", 0)
         << QApplication::translate("MainWindow", "25", 0)
         << QApplication::translate("MainWindow", "26", 0)
         << QApplication::translate("MainWindow", "27", 0)
         << QApplication::translate("MainWindow", "28", 0)
         << QApplication::translate("MainWindow", "29", 0)
         << QApplication::translate("MainWindow", "30", 0)
         << QApplication::translate("MainWindow", "31", 0)
         << QApplication::translate("MainWindow", "32", 0)
         << QApplication::translate("MainWindow", "33", 0)
         << QApplication::translate("MainWindow", "34", 0)
         << QApplication::translate("MainWindow", "35", 0)
         << QApplication::translate("MainWindow", "36", 0)
        );
        Base_entrada->setCurrentText(QApplication::translate("MainWindow", "10", 0));
#ifndef QT_NO_STATUSTIP
        label_7->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        label_7->setText(QApplication::translate("MainWindow", "N\303\272mero de entrada:", 0));
        label_8->setText(QApplication::translate("MainWindow", "Este n\303\272mero est\303\241 em qual base?", 0));
#ifndef QT_NO_TOOLTIP
        Numero->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Numero->setStatusTip(QApplication::translate("MainWindow", "Ao utilizar letras,use-as em CAIXA ALTA.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        Numero->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        Numero->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        Numero->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        label_9->setText(QApplication::translate("MainWindow", "Para qual base voc\303\252 quer converter?", 0));
        label_10->setText(QApplication::translate("MainWindow", "O n\303\272mero na nova base \303\251:", 0));
        Solver->setTabText(Solver->indexOf(tab), QApplication::translate("MainWindow", "Conversor", 0));
        Mostrador_SPF->setText(QString());
#ifndef QT_NO_TOOLTIP
        Numero2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Numero2->setStatusTip(QApplication::translate("MainWindow", "Use \".\" para representar a parte fracion\303\241ria.", 0));
#endif // QT_NO_STATUSTIP
        SPF->setText(QApplication::translate("MainWindow", "SPF", 0));
        label_11->setText(QApplication::translate("MainWindow", "Lower", 0));
        minimo->setText(QApplication::translate("MainWindow", "M\303\255nimo", 0));
#ifndef QT_NO_STATUSTIP
        Mantissa->setStatusTip(QApplication::translate("MainWindow", "N\303\272mero de d\303\255gitos usados na mantissa.", 0));
#endif // QT_NO_STATUSTIP
        label_12->setText(QApplication::translate("MainWindow", "Base", 0));
#ifndef QT_NO_STATUSTIP
        Base->setStatusTip(QApplication::translate("MainWindow", "Base do sistema. M\303\255nimo 2 e m\303\241ximo 36.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        Upper->setStatusTip(QApplication::translate("MainWindow", "Maior expoente.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        Lower->setStatusTip(QApplication::translate("MainWindow", "Menor expoente.", 0));
#endif // QT_NO_STATUSTIP
        Mostrador_max->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "N\303\272mero", 0));
        label4->setText(QApplication::translate("MainWindow", "Upper", 0));
        maximo->setText(QApplication::translate("MainWindow", "M\303\241ximo", 0));
        label_14->setText(QApplication::translate("MainWindow", "Mantissa", 0));
        Mostrador_min->setText(QString());
        Solver->setTabText(Solver->indexOf(tab_2), QApplication::translate("MainWindow", "Erro", 0));
        label_5->setText(QApplication::translate("MainWindow", "Precis\303\243o", 0));
        metodo->clear();
        metodo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Bisse\303\247\303\243o", 0)
         << QApplication::translate("MainWindow", "Posi\303\247\303\243o Falsa", 0)
         << QApplication::translate("MainWindow", "Newton-Raphson", 0)
         << QApplication::translate("MainWindow", "Secante", 0)
         << QApplication::translate("MainWindow", "Ponto Fixo", 0)
        );
#ifndef QT_NO_STATUSTIP
        precisao->setStatusTip(QApplication::translate("MainWindow", "Campo obrigat\303\263rio para todos os m\303\251todos.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        precisao2->setStatusTip(QApplication::translate("MainWindow", "Campo obrigat\303\263rio para todos os m\303\251todos.", 0));
#endif // QT_NO_STATUSTIP
        label_2->setText(QApplication::translate("MainWindow", "M\303\251todo:", 0));
        chute_b->setText(QApplication::translate("MainWindow", "b", 0));
#ifndef QT_NO_STATUSTIP
        b->setStatusTip(QApplication::translate("MainWindow", "Usado para os Metodos de Bisse\303\247ao, Posi\303\247ao Falsa e Secante.", 0));
#endif // QT_NO_STATUSTIP
        chute_a->setText(QApplication::translate("MainWindow", "a", 0));
        label->setText(QApplication::translate("MainWindow", "Fun\303\247\303\243o:", 0));
        calcular->setText(QApplication::translate("MainWindow", "Calcular", 0));
        calcular->setShortcut(QApplication::translate("MainWindow", "Return", 0));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Precisao 2</p><p><br/></p></body></html>", 0));
        display->setText(QString());
#ifndef QT_NO_STATUSTIP
        funcao->setStatusTip(QApplication::translate("MainWindow", "Cuidado com a sintaxe ao digitar a fun\303\247ao,use a aba Ajuda? para mais informa\303\247oes.", 0));
#endif // QT_NO_STATUSTIP
        funcao->setText(QApplication::translate("MainWindow", "Ex: x^3-x*9+3", 0));
#ifndef QT_NO_STATUSTIP
        a->setStatusTip(QApplication::translate("MainWindow", "Usado para os Metodos de Bisse\303\247ao, Posi\303\247ao Falsa e Secante.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        opcao->setStatusTip(QApplication::translate("MainWindow", "Ei,se voc\303\252 me marcar eu posso gerar um relat\303\263rio mais detalhado de cada itera\303\247\303\243o.", 0));
#endif // QT_NO_STATUSTIP
        opcao->setText(QApplication::translate("MainWindow", "Imprimir em relat\303\263rio?", 0));
        opcao->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
#ifndef QT_NO_STATUSTIP
        x0->setStatusTip(QApplication::translate("MainWindow", "Usado para os Metodos de Newton-Raphson e Ponto Fixo.", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        max_it->setStatusTip(QApplication::translate("MainWindow", "Campo obrigat\303\263rio para todos os m\303\251todos.", 0));
#endif // QT_NO_STATUSTIP
        label_18->setText(QApplication::translate("MainWindow", "M\303\241ximo de Itera\303\247\303\265es", 0));
#ifndef QT_NO_STATUSTIP
        K_ideal->setStatusTip(QApplication::translate("MainWindow", "Calcula o valor m\303\255nimo de K com base no m\303\251todo da Bisse\303\247\303\243o.", 0));
#endif // QT_NO_STATUSTIP
        K_ideal->setText(QApplication::translate("MainWindow", "Usar K m\303\255nimo", 0));
#ifndef QT_NO_STATUSTIP
        Limpar->setStatusTip(QApplication::translate("MainWindow", "Clique em mim para limpar todos os campos.", 0));
#endif // QT_NO_STATUSTIP
        Limpar->setText(QApplication::translate("MainWindow", "Limpar", 0));
#ifndef QT_NO_STATUSTIP
        Linkar->setStatusTip(QApplication::translate("MainWindow", "Preenche o campo Precis\303\243o 2 com o mesmo valor do campo Precis\303\243o.", 0));
#endif // QT_NO_STATUSTIP
        Linkar->setText(QApplication::translate("MainWindow", "->", 0));
#ifndef QT_NO_STATUSTIP
        multiplicidade->setStatusTip(QApplication::translate("MainWindow", "Usado para os Metodos de Newton e Secante.", 0));
#endif // QT_NO_STATUSTIP
        multiplicidade->setText(QApplication::translate("MainWindow", "1", 0));
        label_multiplicidade->setText(QApplication::translate("MainWindow", "Multiplicidade:", 0));
        chute_x0->setText(QApplication::translate("MainWindow", "x0", 0));
        Solver->setTabText(Solver->indexOf(tab_3), QApplication::translate("MainWindow", "Ra\303\255zes", 0));
        saida->setText(QString());
        calcular_derivada->setText(QApplication::translate("MainWindow", "Calcular Derivada", 0));
        label_23->setText(QApplication::translate("MainWindow", "Resultado:", 0));
        label_24->setText(QApplication::translate("MainWindow", "Fun\303\247\303\243o:", 0));
        calcular_2->setText(QApplication::translate("MainWindow", "Calcular", 0));
#ifndef QT_NO_STATUSTIP
        entrada->setStatusTip(QApplication::translate("MainWindow", "Digite aqui sua fun\303\247ao", 0));
#endif // QT_NO_STATUSTIP
        entrada->setText(QApplication::translate("MainWindow", "Ex: x^3-x*9+3", 0));
        label_25->setText(QApplication::translate("MainWindow", "Aplicar ao valor:", 0));
        Clear->setText(QApplication::translate("MainWindow", "Limpar", 0));
#ifndef QT_NO_STATUSTIP
        Name->setStatusTip(QApplication::translate("MainWindow", "De um nome a sua fun\303\247ao!", 0));
#endif // QT_NO_STATUSTIP
        Name->setText(QApplication::translate("MainWindow", "F", 0));
        Solver->setTabText(Solver->indexOf(tab_6), QApplication::translate("MainWindow", "Solver", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:9pt;\">Ao utilizar a aba ra\303\255zes para encontrar ra\303\255zes de equa\303\247\303\265es, tenha cuidado quanto ao preenchimento do campo fun\303\247\303\243o,voc\303\252 deve seguir algumas regras de sintaxe para que o programa funcione corretamente.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:9pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0p"
                        "x; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:9pt; font-weight:600;\">-N\303\243o utilize espa\303\247os enquanto estiver digitando,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:9pt; font-weight:600;\">-Utilize os seguintes s\303\255mbolos: + , - , * , / , ^ ,  @ , # ,$  para opera\303\247\303\265es de soma,subtra\303\247\303\243o,multiplica\303\247\303\243o,divis\303\243o, exponencia\303\247\303\243o,logaritmo, trigonometria e radicia\303\247\303\243o respectivamente,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:9pt; font-weight:600;\">-Ponha literais(vari\303\241veis) antes de seus coeficientes,caso queira digitar 9*x digite x*9,isso vale para as opera\303\247\303"
                        "\265es de multiplica\303\247\303\243o e exponencia\303\247\303\243o,</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:9pt; font-weight:600;\">-As opera\303\247\303\265es possuem uma hierarquia de execu\303\247\303\243o e sua express\303\243o deve ser digitada respeitando tal hierarquia. Exemplo,para a equa\303\247\303\243o 9*x^3 + 2*x^2 - 1 digite x^3*9+x*2-1</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:9pt; font-weight:600;\">-Para opera\303\247\303\265es logar\303\255tmicas, trigonom\303\251tricas e de radicia\303\247\303\243o use a seguinte sintaxe: x@y significa log de x na base de y, para lnx use y = e, x#y significa alguma opera\303\247\303\243o trigonom\303\251trica sobre x em que y define a opera\303\247\303\243o a ser realizada,assim:"
                        " x#1 = seno(x), x#2 = cos(x), x#3 = tg(x), x#4 = arcsen(x), x#5 = arccos(x), x#6 = arctg(x), x#7 = sinh(x), x#8 = cosh(x), x#9 = tanh(x) em que x \303\251 um valor medido em radianos e x$y significa ra\303\255z y-\303\251sima de x, assim x$2 = ra\303\255z quadrada de x, x$3 = ra\303\255z c\303\272bica de x, etc.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:9pt; font-weight:600;\">-Para constantes num\303\251ricas como Pi e o n\303\272mero de Euler use: 'P' para Pi, 'e' para Euler, 'F' para N\303\272mero de Ouro e 'L' para Constante de Liouville.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:9pt; font-weight:600;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; tex"
                        "t-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:9pt;\">Obs: Se voc\303\252 marcar a op\303\247\303\243o Imprimir em relat\303\263rio ser\303\241 gerado um arquivo.txt com mais detalhes de cada itera\303\247\303\243o,olhe o diret\303\263rio em que se encontra o arquivo fonte do projeto, l\303\241 estar\303\241 o relat\303\263rio.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Ubuntu'; font-size:9pt;\"><br /></p></body></html>", 0));
        Solver->setTabText(Solver->indexOf(tab_4), QApplication::translate("MainWindow", "Ajuda?", 0));
        matriz_entrada->setText(QApplication::translate("MainWindow", "Ex: {{3,2,4},{1,1,2},{4,3,-2}}", 0));
        label_26->setText(QApplication::translate("MainWindow", "Matriz:", 0));
        texto_matriz->setText(QApplication::translate("MainWindow", "Representa\303\247\303\243o Matricial:", 0));
        label_28->setText(QApplication::translate("MainWindow", "Determinante:", 0));
        Calcular_determinante->setText(QApplication::translate("MainWindow", "Calcular Determinante", 0));
        display_determinante->setText(QString());
        metodo_sistema->clear();
        metodo_sistema->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Cramer", 0)
         << QApplication::translate("MainWindow", "Triangular Inferior", 0)
         << QApplication::translate("MainWindow", "Triangular Superior", 0)
         << QApplication::translate("MainWindow", "Gauss", 0)
         << QApplication::translate("MainWindow", "Gauss Jordan", 0)
         << QApplication::translate("MainWindow", "Gauss Jacob", 0)
         << QApplication::translate("MainWindow", "Gauss Seidel", 0)
         << QApplication::translate("MainWindow", "LU(Doolittle)", 0)
        );
        label_29->setText(QApplication::translate("MainWindow", "M\303\251todo", 0));
        solucionar->setText(QApplication::translate("MainWindow", "Solucionar Sistema", 0));
        termos->setText(QApplication::translate("MainWindow", "Ex: {1,2,3}", 0));
        label_30->setText(QApplication::translate("MainWindow", "Termos independentes", 0));
        raizes_sistema->setText(QString());
        ordem->setText(QString());
        imprimir_matriz->setText(QApplication::translate("MainWindow", "Imprimir", 0));
        transformacoes->clear();
        transformacoes->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Transposta", 0)
         << QApplication::translate("MainWindow", "Inversa", 0)
         << QApplication::translate("MainWindow", "Decompor LU", 0)
        );
        chute_label->setText(QApplication::translate("MainWindow", "Chute", 0));
        iteracoes_label->setText(QApplication::translate("MainWindow", "Itera\303\247oes", 0));
        precisao_label->setText(QApplication::translate("MainWindow", "Precisao", 0));
        Solver->setTabText(Solver->indexOf(tab_7), QApplication::translate("MainWindow", "Sistemas", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
