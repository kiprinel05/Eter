#include "Eter.h"
#include "ui_QGameMode.h"
#include "QGameMode.h"
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QTimer>

#include<iostream>

Eter::Eter(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    playButton = ui.playButton;
    loadButton = ui.loadButton;
    rulesButton = ui.rulesButton;

    if (!ui.centralWidget->layout()) {
        mainLayout = new QVBoxLayout(ui.centralWidget);
        ui.centralWidget->setLayout(mainLayout);
    }

    connect(playButton, &QPushButton::clicked, this, &Eter::onPlayButtonClicked);
    connect(loadButton, &QPushButton::clicked, this, &Eter::onLoadButtonClicked);
}

Eter::~Eter() {}

void Eter::onLoadButtonClicked()
{
    QGameMode* gamemodeMenu=new QGameMode(nullptr);
    this->hide();
}

void Eter::makeMove(int row, int column)
{
    std::cout << "<make move "<< row<<" "<< column<<" >";
}

void Eter::onPlayButtonClicked()
{
    showMaximized();

    playButton->hide();
    loadButton->hide();
    rulesButton->hide();
    ui.centralWidget->setStyleSheet("background: none;");

    QTimer::singleShot(100, [this]() {
        QLabel* gameLabel = new QLabel("Training", this);
        gameLabel->setAlignment(Qt::AlignCenter);
        gameLabel->setStyleSheet("font-size: 24px; font-weight: bold;");

        QTableWidget* gameTable = new QTableWidget(5, 5, this);
        gameTable->setStyleSheet("gridline-color: red;");
        gameTable->setFixedWidth(1000);
        gameTable->setFixedHeight(1000);
        for (int i = 0; i < 5; ++i) {
            gameTable->setColumnWidth(i, 170);
            gameTable->setRowHeight(i, 170);
        }
        connect(gameTable, &QTableWidget::cellClicked, this, &Eter::makeMove);


        QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(ui.centralWidget->layout());
        if (layout) {
            layout->addWidget(gameLabel);
            layout->addWidget(gameTable);
        }
        });
}
