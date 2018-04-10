/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *NumberOfRows;
    QLineEdit *NOR;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *NOC;
    QHBoxLayout *horizontalLayout_3;
    QLabel *MazeFile;
    QPushButton *OpenFileMaze;
    QLineEdit *MazePath;
    QVBoxLayout *verticalLayout;
    QRadioButton *MD;
    QRadioButton *ED;
    QRadioButton *CD;
    QSpacerItem *verticalSpacer;
    QPushButton *Solve;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(580, 379);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        NumberOfRows = new QLabel(centralWidget);
        NumberOfRows->setObjectName(QStringLiteral("NumberOfRows"));

        horizontalLayout->addWidget(NumberOfRows);

        NOR = new QLineEdit(centralWidget);
        NOR->setObjectName(QStringLiteral("NOR"));

        horizontalLayout->addWidget(NOR);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        NOC = new QLineEdit(centralWidget);
        NOC->setObjectName(QStringLiteral("NOC"));

        horizontalLayout_2->addWidget(NOC);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        MazeFile = new QLabel(centralWidget);
        MazeFile->setObjectName(QStringLiteral("MazeFile"));

        horizontalLayout_3->addWidget(MazeFile);

        OpenFileMaze = new QPushButton(centralWidget);
        OpenFileMaze->setObjectName(QStringLiteral("OpenFileMaze"));

        horizontalLayout_3->addWidget(OpenFileMaze);

        MazePath = new QLineEdit(centralWidget);
        MazePath->setObjectName(QStringLiteral("MazePath"));

        horizontalLayout_3->addWidget(MazePath);


        verticalLayout_3->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        MD = new QRadioButton(centralWidget);
        MD->setObjectName(QStringLiteral("MD"));

        verticalLayout->addWidget(MD);

        ED = new QRadioButton(centralWidget);
        ED->setObjectName(QStringLiteral("ED"));

        verticalLayout->addWidget(ED);

        CD = new QRadioButton(centralWidget);
        CD->setObjectName(QStringLiteral("CD"));

        verticalLayout->addWidget(CD);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer);

        Solve = new QPushButton(centralWidget);
        Solve->setObjectName(QStringLiteral("Solve"));

        verticalLayout_4->addWidget(Solve);


        horizontalLayout_5->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 580, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Maze", Q_NULLPTR));
        NumberOfRows->setText(QApplication::translate("MainWindow", "  Number of rows =", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "  Number of columns =", Q_NULLPTR));
        MazeFile->setText(QApplication::translate("MainWindow", "  Maze file = ", Q_NULLPTR));
        OpenFileMaze->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        MD->setText(QApplication::translate("MainWindow", "  Manhattan Distance", Q_NULLPTR));
        ED->setText(QApplication::translate("MainWindow", "  Eucledian Distance", Q_NULLPTR));
        CD->setText(QApplication::translate("MainWindow", "  Chebyshev Distance", Q_NULLPTR));
        Solve->setText(QApplication::translate("MainWindow", "Solve", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
