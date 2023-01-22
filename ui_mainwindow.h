/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *createItemAct;
    QAction *openItemAct;
    QAction *saveItemAct;
    QAction *saveAsItemAct;
    QAction *mergeAct;
    QAction *exitAct;
    QAction *addItemAct;
    QAction *deleteItemAct;
    QAction *editItemAct;
    QAction *aboutAct;
    QAction *findItemAct;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(661, 365);
        createItemAct = new QAction(MainWindow);
        createItemAct->setObjectName("createItemAct");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/icons8-new-file-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        createItemAct->setIcon(icon);
        openItemAct = new QAction(MainWindow);
        openItemAct->setObjectName("openItemAct");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/icons8-opened-folder-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        openItemAct->setIcon(icon1);
        saveItemAct = new QAction(MainWindow);
        saveItemAct->setObjectName("saveItemAct");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/img/icons8-save-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveItemAct->setIcon(icon2);
        saveAsItemAct = new QAction(MainWindow);
        saveAsItemAct->setObjectName("saveAsItemAct");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/img/icons8-save-as-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAsItemAct->setIcon(icon3);
        mergeAct = new QAction(MainWindow);
        mergeAct->setObjectName("mergeAct");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rec/img/icons8-merge-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        mergeAct->setIcon(icon4);
        exitAct = new QAction(MainWindow);
        exitAct->setObjectName("exitAct");
        addItemAct = new QAction(MainWindow);
        addItemAct->setObjectName("addItemAct");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/rec/img/icons8-add-new-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        addItemAct->setIcon(icon5);
        deleteItemAct = new QAction(MainWindow);
        deleteItemAct->setObjectName("deleteItemAct");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/rec/img/icons8-remove-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteItemAct->setIcon(icon6);
        editItemAct = new QAction(MainWindow);
        editItemAct->setObjectName("editItemAct");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/rec/img/icons8-pencil-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        editItemAct->setIcon(icon7);
        aboutAct = new QAction(MainWindow);
        aboutAct->setObjectName("aboutAct");
        findItemAct = new QAction(MainWindow);
        findItemAct->setObjectName("findItemAct");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/rec/img/icons8-search-50.png"), QSize(), QIcon::Normal, QIcon::Off);
        findItemAct->setIcon(icon8);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 641, 261));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(verticalLayoutWidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMaximumSize(QSize(631, 16777215));

        verticalLayout_2->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 661, 22));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setIconSize(QSize(27, 27));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(createItemAct);
        menu->addAction(openItemAct);
        menu->addAction(saveItemAct);
        menu->addAction(saveAsItemAct);
        menu->addAction(mergeAct);
        menu->addSeparator();
        menu->addAction(exitAct);
        menu_2->addAction(aboutAct);
        menu_3->addAction(addItemAct);
        menu_3->addAction(deleteItemAct);
        menu_3->addAction(editItemAct);
        menu_3->addSeparator();
        menu_3->addAction(findItemAct);
        toolBar->addAction(createItemAct);
        toolBar->addAction(openItemAct);
        toolBar->addAction(saveItemAct);
        toolBar->addAction(saveAsItemAct);
        toolBar->addAction(mergeAct);
        toolBar->addAction(addItemAct);
        toolBar->addAction(deleteItemAct);
        toolBar->addAction(editItemAct);
        toolBar->addAction(findItemAct);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createItemAct->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        createItemAct->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        openItemAct->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        openItemAct->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        saveItemAct->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        saveItemAct->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        saveAsItemAct->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
#if QT_CONFIG(shortcut)
        saveAsItemAct->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Alt+S", nullptr));
#endif // QT_CONFIG(shortcut)
        mergeAct->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\270\321\202\321\214", nullptr));
        exitAct->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(shortcut)
        exitAct->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        addItemAct->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteItemAct->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        deleteItemAct->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        editItemAct->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        aboutAct->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
#if QT_CONFIG(shortcut)
        aboutAct->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        findItemAct->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260 \320\277\320\276\320\270\321\201\320\272\320\260:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\270", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
