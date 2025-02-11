#pragma once
#include "ui_QTraining.h"
#include <QtWidgets/QMainWindow>
#include <QPushButton>

class QTraining : public QMainWindow
{
    Q_OBJECT
public:
    QTraining(QWidget* parent = nullptr);
    ~QTraining();

private slots:
    void createBoard();

private:
    Ui::QTrainingClass ui;

    QWidget* trainingTableWidget;
    QPushButton* space00;
    QPushButton* space01;
    QPushButton* space02;
    QPushButton* space03;
    QPushButton* space04;

    QPushButton* space10;
    QPushButton* space11;
    QPushButton* space12;
    QPushButton* space13;
    QPushButton* space14;

    QPushButton* space20;
    QPushButton* space21;
    QPushButton* space22;
    QPushButton* space23;
    QPushButton* space24;

    QPushButton* space30;
    QPushButton* space31;
    QPushButton* space32;
    QPushButton* space33;
    QPushButton* space34;

    QPushButton* space40;
    QPushButton* space41;
    QPushButton* space42;
    QPushButton* space43;
    QPushButton* space44;
};
