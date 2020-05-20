#ifndef TEST_SAVE_H
#define TEST_SAVE_H
#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include<QApplication>
#include<fstream>
#include<iostream>
#include <chrono>
extern "C++" {
    #include "mainwindow.h"
    #include "chart.h"
    #include "createnewfile.h"
    #include "donutbreakdownchart.h"
    #include "httpserver.h"
    #include "initstart.h"
    #include "mainslice.h"
    #include "savedia.h"
    #include "treeitem.h"
    #include "treemodel.h"
    #include "ui_mainwindow.h"
    #include<QtWidgets>
    #include <QAction>
    #include"chart.h"
    #include <QtWidgets/QApplication>
    #include <QtWidgets/QMainWindow>
    #include <QtWidgets/QStatusBar>
    #include <QtCharts/QChartView>
    #include "donutbreakdownchart.h"
    #include"savedia.h"
    #include"initstart.h"
    #include<QLayout>
    #include <string>
}




TEST(testSave, insertRow){
    std::string inpDir = (const char*)INDIR;
    QString se = QString::fromStdString(inpDir);
    int argc;
    char* argv[0];
    QApplication a(argc, argv);
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
    std::string path = (const char*)SAVEDIR;
    w.insertRow();
      w.file1.setFileName((path+"firstTest.json").c_str());
    w.saveClicked();

    QFile getFile;
    getFile.setFileName((path+"firstTest.json").c_str());
    getFile.open(QIODevice::ReadOnly);
    QByteArray getFileAr = getFile.readAll();
    std::string getS = getFileAr.toStdString();
    getFile.close();

    QFile haveFile;
    haveFile.setFileName((path+"haveFile.json").c_str());
    haveFile.open(QIODevice::ReadOnly);
    QByteArray haveFileAr = haveFile.readAll();
    std::string haveS = haveFileAr.toStdString();
    haveFile.close();

    TreeItem* second = root->child(1);
    QModelIndex ind1 = w.model1->getIn(0, 0, second);
    QString name = w.model1->data(ind1, 0).toString();

    std::string s = name.toStdString();
    std::string str = "group4";
    if(getS != haveS)
        FAIL();
//    ASSERT_EQ(s.size(), str.size());
//    if(s.size() == str.size()){
//        for(unsigned int i = 0; i < s.size(); i++){
//            ASSERT_EQ(s[i], str[i]);
//        }
//    }

    w.isSaved = true;
    w.close();
    a.exit(0);
}

TEST(testSave, insertChild){
    int argc;
    char* argv[0];
    QApplication a(argc, argv);
    MainWindow w;
    w.file1.setFileName("E://qt_creator//3rd_task_testing//gtest//app//show.json");
    w.flagGetFile = 1;
    w.initModel();

    TreeItem* root = w.model1->getRoot();
    TreeItem* first = root->child(0);
    QModelIndex ind = w.model1->getIn(0, 0, first);

    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    std::string path = (const char*)SAVEDIR;
    w.insertChild();
      w.file1.setFileName((path+"secondTest.json").c_str());
    w.saveClicked();

    QFile getFile;
    getFile.setFileName((path+"secondTest.json").c_str());
    getFile.open(QIODevice::ReadOnly);
    QByteArray getFileAr = getFile.readAll();
    std::string getS = getFileAr.toStdString();
    getFile.close();

    QFile haveFile;
    haveFile.setFileName((path+"haveFile2.json").c_str());
    haveFile.open(QIODevice::ReadOnly);
    QByteArray haveFileAr = haveFile.readAll();
    std::string haveS = haveFileAr.toStdString();
    haveFile.close();

    TreeItem* second = root->child(1);
    QModelIndex ind1 = w.model1->getIn(0, 0, second);
    QString name = w.model1->data(ind1, 0).toString();

    std::string s = name.toStdString();
    std::string str = "group4";
    if(getS != haveS)
        FAIL();
//    ASSERT_EQ(s.size(), str.size());
//    if(s.size() == str.size()){
//        for(unsigned int i = 0; i < s.size(); i++){
//            ASSERT_EQ(s[i], str[i]);
//        }
//    }

    w.isSaved = true;
    w.close();
    a.exit(0);
}



#endif // TEST_SAVE_H
