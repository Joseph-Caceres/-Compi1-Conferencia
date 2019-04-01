/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_principal
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTextEdit *txtEntrada;
    QPushButton *btnAnalizar;
    QTabWidget *Tabs1;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *txtConsola;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *txtGrafo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *principal)
    {
        if (principal->objectName().isEmpty())
            principal->setObjectName(QStringLiteral("principal"));
        principal->resize(703, 447);
        centralWidget = new QWidget(principal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        txtEntrada = new QTextEdit(centralWidget);
        txtEntrada->setObjectName(QStringLiteral("txtEntrada"));

        horizontalLayout->addWidget(txtEntrada);

        btnAnalizar = new QPushButton(centralWidget);
        btnAnalizar->setObjectName(QStringLiteral("btnAnalizar"));

        horizontalLayout->addWidget(btnAnalizar);


        verticalLayout->addLayout(horizontalLayout);

        Tabs1 = new QTabWidget(centralWidget);
        Tabs1->setObjectName(QStringLiteral("Tabs1"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        txtConsola = new QTextEdit(tab);
        txtConsola->setObjectName(QStringLiteral("txtConsola"));

        verticalLayout_2->addWidget(txtConsola);

        Tabs1->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        txtGrafo = new QTextEdit(tab_2);
        txtGrafo->setObjectName(QStringLiteral("txtGrafo"));

        verticalLayout_3->addWidget(txtGrafo);

        Tabs1->addTab(tab_2, QString());

        verticalLayout->addWidget(Tabs1);

        principal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(principal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 703, 22));
        principal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(principal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        principal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(principal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        principal->setStatusBar(statusBar);

        retranslateUi(principal);

        Tabs1->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(principal);
    } // setupUi

    void retranslateUi(QMainWindow *principal)
    {
        principal->setWindowTitle(QApplication::translate("principal", "principal", nullptr));
        btnAnalizar->setText(QApplication::translate("principal", "Analizar", nullptr));
        Tabs1->setTabText(Tabs1->indexOf(tab), QApplication::translate("principal", "Resultado", nullptr));
        Tabs1->setTabText(Tabs1->indexOf(tab_2), QApplication::translate("principal", "Grafo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class principal: public Ui_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
