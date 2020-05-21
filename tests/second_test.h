#ifndef SECOND_TEST_H
#define SECOND_TEST_H


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



//TEST(insertRow, secondGroup){
//    int argc;
//    char* argv[0];
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.file1.setFileName("E://qt_creator//3rd_task_testing//gtest//app//show.json");
//    w.flagGetFile = 1;
//    w.initModel();

//    TreeItem* root = w.model1->getRoot();
//    TreeItem* first = root->child(2);
//    QModelIndex ind = w.model1->getIn(2, 0, first);
//    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
//    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
//    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
//    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());

//    w.insertRow();
//    TreeItem* second = root->child(3);
//    QModelIndex ind1 = w.model1->getIn(3, 0, second);
//    QString name = w.model1->data(ind1, 0).toString();
//    std::string s = name.toStdString();
//    std::string str = "group4";
//    ASSERT_EQ(s.size(), str.size());
//    if(s.size() == str.size()){
//        for(unsigned int i = 0; i < s.size(); i++){
//            ASSERT_EQ(s[i], str[i]);
//        }
//    }
//}
//TEST(insertRow, thirdGroup){
//    int argc;
//    char* argv[0];
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.file1.setFileName("E://qt_creator//3rd_task_testing//gtest//app//show.json");
//    w.flagGetFile = 1;
//    w.initModel();

//    TreeItem* root = w.model1->getRoot();
//    TreeItem* first = root->child(0);
//    TreeItem* emp = first->child(0);
//    QModelIndex ind = w.model1->getIn(0, 0, emp);

//    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
//    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());
//    w.ui->treeView->selectionModel()->setCurrentIndex(ind, QItemSelectionModel::Select);
//    w.ui->treeView->closePersistentEditor(w.ui->treeView->selectionModel()->currentIndex());

//    w.insertRow();
//    TreeItem* empNew = first->child(1);
//    QModelIndex ind1 = w.model1->getIn(1, 0, empNew);
//    QString name = w.model1->data(ind1, 0).toString();
//    std::string s = name.toStdString();
//    std::string str = "employee3";
//    ASSERT_EQ(s.size(), str.size());
//    if(s.size() == str.size()){
//        for(unsigned int i = 0; i < s.size(); i++){
//            ASSERT_EQ(s[i], str[i]);
//        }
//    }
//}

TEST(kek, kekw){
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

    w.insertRow();
    TreeItem* second = root->child(1);
    QModelIndex ind1 = w.model1->getIn(0, 0, second);
    QString name = w.model1->data(ind1, 0).toString();

    std::string s = name.toStdString();
    std::string str = "group4";
    if(str != s)
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


#endif // SECOND_TEST_H
