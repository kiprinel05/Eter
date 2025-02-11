#pragma once

#include "ui_Eter.h"
#include <QtWidgets/QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QVBoxLayout>

class Eter : public QMainWindow
{
    Q_OBJECT

public:
    Eter(QWidget* parent = nullptr);
    ~Eter();

private slots:
    void onPlayButtonClicked();
    void onLoadButtonClicked();
    void makeMove(int row, int column);

private:
    Ui::EterClass ui;
   
    QPushButton* playButton;
    QPushButton* loadButton;
    QPushButton* rulesButton;
    QLabel* label1;
    QLabel* label2;
    QTableWidget* table;
    QVBoxLayout* mainLayout;
    QWidget* centralWidget;

    QWidget* trainingWidget;
};
