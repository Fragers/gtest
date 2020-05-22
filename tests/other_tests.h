#ifndef OTHER_TESTS_H
#define OTHER_TESTS_H
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include<QApplication>
#include<fstream>
#include<iostream>
#include <chrono>

    #include "mainwindow.h"
//    #include "chart.h"
    #include "createnewfile.h"
//    #include "donutbreakdownchart.h"
    #include "httpserver.h"
    #include "initstart.h"
//    #include "mainslice.h"
    #include "savedia.h"
    #include "treeitem.h"
    #include "treemodel.h"
    #include "ui_mainwindow.h"
    #include<QtWidgets>
    #include <QAction>
//    #include"chart.h"
    #include <QtWidgets/QApplication>
    #include <QtWidgets/QMainWindow>
    #include <QtWidgets/QStatusBar>
//    #include <QtCharts/QChartView>
//    #include "donutbreakdownchart.h"
    #include"savedia.h"
    #include"initstart.h"
    #include<QLayout>
    #include <string>

//int argc;
//char* argv[1];
//    QApplication a(argc, argv);


TEST(testOther, tripleInsertRow){

    std::string inpDir = (const char*)INDIR;
    QString se = QString::fromStdString(inpDir);
//    int argc;
//    char* argv[0];
//    QApplication a(argc, argv);
    MainWindow w;
    w.file1.setFileName((inpDir+"show.json").c_str());

    w.flagGetFile = 1;
    w.initModel();

    TreeItem* root = w.model1->getRoot();
    TreeItem* first = root->child(0);
    QModelIndex ind = w.model1->getIn(0, 0, first);

    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    std::string path = (const char*)OTHERDIR;
    w.insertRow();
    w.insertRow();
    w.insertRow();

      w.file1.setFileName((path+"otherTest.json").c_str());
    w.saveClicked();

    QFile getFile;
    getFile.setFileName((path+"otherTest.json").c_str());
    getFile.open(QIODevice::ReadOnly);
    QByteArray getFileAr = getFile.readAll();
    std::string getS = getFileAr.toStdString();
    getFile.close();

    QFile haveFile;
    haveFile.setFileName((path+"tripleInsert.json").c_str());
    haveFile.open(QIODevice::ReadOnly);
    QByteArray haveFileAr = haveFile.readAll();
    std::string haveS = haveFileAr.toStdString();
    haveFile.close();


    if(getS != haveS)
        FAIL();

    w.isSaved = true;
    w.close();
//    a.exit(0);
}

TEST(testOther, emptyFile){

    std::string inpDir = (const char*)INDIR;
    std::string path = (const char*)OTHERDIR;
    QString se = QString::fromStdString(inpDir);
//    int argc;
//    char* argv[0];
//    QApplication a(argc, argv);
    MainWindow w;
    w.file1.setFileName((path+"emptyFile.json").c_str());

    w.flagGetFile = 1;
    w.initModel();

    TreeItem* root = w.model1->getRoot();
    TreeItem* first = root->child(0);
    QModelIndex ind = w.model1->getIn(0, 0, first);

    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());

    w.insertRow();
    w.insertRow();

      w.file1.setFileName((path+"emptyFileNew.json").c_str());
    w.saveClicked();

    QFile getFile;
    getFile.setFileName((path+"emptyFileNew.json").c_str());
    getFile.open(QIODevice::ReadOnly);
    QByteArray getFileAr = getFile.readAll();
    std::string getS = getFileAr.toStdString();
    getFile.close();

    QFile haveFile;
    haveFile.setFileName((path+"emptyShould.json").c_str());
    haveFile.open(QIODevice::ReadOnly);
    QByteArray haveFileAr = haveFile.readAll();
    std::string haveS = haveFileAr.toStdString();
    haveFile.close();


    if(getS != haveS)
        FAIL();

    w.isSaved = true;
    w.close();
//    a.exit(0);
}

TEST(testOther, insertChildToTask){

    std::string inpDir = (const char*)INDIR;
    QString se = QString::fromStdString(inpDir);
//    int argc;
//    char* argv[0];
//    QApplication a(argc, argv);
    MainWindow w;
    w.file1.setFileName((inpDir+"show.json").c_str());

    w.flagGetFile = 1;
    w.initModel();

    TreeItem* root = w.model1->getRoot();
    TreeItem* first = root->child(0)->child(0)->child(0);
    QModelIndex ind = w.model1->getIn(0, 0, first);

    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    std::string path = (const char*)OTHERDIR;
    w.insertChild();

      w.file1.setFileName((path+"otherTest.json").c_str());
    w.saveClicked();

    QFile getFile;
    getFile.setFileName((path+"otherTest.json").c_str());
    getFile.open(QIODevice::ReadOnly);
    QByteArray getFileAr = getFile.readAll();
    std::string getS = getFileAr.toStdString();
    getFile.close();

    QFile haveFile;
    haveFile.setFileName((inpDir+"show.json").c_str());
    haveFile.open(QIODevice::ReadOnly);
    QByteArray haveFileAr = haveFile.readAll();
    std::string haveS = haveFileAr.toStdString();
    haveFile.close();


    if(getS != haveS)
        FAIL();

    w.isSaved = true;
    w.close();
   // a.exit(0);
}

#endif // OTHER_TESTS_H
