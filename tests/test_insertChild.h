#ifndef TEST_INSERTCHILD_H
#define TEST_INSERTCHILD_H
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



TEST(insertChild, firstGroupSelected){
    std::string inpDir = (const char*)INDIR;
    QString se = QString::fromStdString(inpDir);
    int argc;
    char* argv[1];
    QApplication a(argc, argv);
    MainWindow w;
    w.file1.setFileName((inpDir+"show.json").c_str());

    w.flagGetFile = 1;
    w.initModel();

    TreeItem* root = w.model1->getRoot();
    TreeItem* first = root->child(0);
    //TreeItem* emp = first->child(0);
    QModelIndex ind = w.model1->getIn(0, 0, first);

    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());

    w.insertChild();
    TreeItem* empNew = root->child(0)->child(0);
    QModelIndex ind1 = w.model1->getIn(0, 0, empNew);
    QString name = w.model1->data(ind1, 0).toString();
    std::string s = name.toStdString();
    std::string str = "employee3";

    if(s != str)
        FAIL();
    w.isSaved = true;
//    w.close();
//    a.exit(0);
//    w.model1->~TreeModel();
//    delete root;
//    delete first;
//    delete empNew;

}


TEST(insertChild, firstGroup_firstEmployeeSelected){
    std::string inpDir = (const char*)INDIR;
    QString se = QString::fromStdString(inpDir);
    int argc;
    char* argv[1];
    QApplication a(argc, argv);
    MainWindow w;
    w.file1.setFileName((inpDir+"show.json").c_str());

    w.flagGetFile = 1;
    w.initModel();

    TreeItem* root = w.model1->getRoot();
    TreeItem* first = root->child(0);
    TreeItem* emp = first->child(0);
    QModelIndex ind = w.model1->getIn(0, 0, emp);

    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());

    w.insertChild();
    TreeItem* empNew = root->child(0)->child(0)->child(0);
    QModelIndex ind1 = w.model1->getIn(0, 0, empNew);
    QString name = w.model1->data(ind1, 0).toString();
    std::string s = name.toStdString();
    std::string str = "task4";

    if(s != str)
        FAIL();
    w.isSaved = true;
//    w.close();
//        a.exit(0);

//    w.model1->~TreeModel();
//    delete root;
//    delete first;
//    delete empNew;

}

TEST(insertChild, firstGroup_secondEmployeeSelected){
    std::string inpDir = (const char*)INDIR;
    QString se = QString::fromStdString(inpDir);
    int argc;
    char* argv[1];
    QApplication a(argc, argv);
    MainWindow w;
    w.file1.setFileName((inpDir+"show.json").c_str());

    w.flagGetFile = 1;
    w.initModel();

    TreeItem* root = w.model1->getRoot();
    TreeItem* first = root->child(0);
    TreeItem* emp = first->child(1);
    QModelIndex ind = w.model1->getIn(1, 0, emp);

    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());

    w.insertChild();
    TreeItem* empNew = root->child(0)->child(1)->child(0);
    QModelIndex ind1 = w.model1->getIn(0, 0, empNew);
    QString name = w.model1->data(ind1, 0).toString();
    std::string s = name.toStdString();
    std::string str = "task2";

    if(s != str)
        FAIL();
    w.isSaved = true;
//    w.close();
//       a.exit(0);
    w.model1->~TreeModel();
//    delete root;
//    delete first;
//    delete empNew;

}


#endif // TEST_INSERTCHILD_H
