#include "QGameMode.h"
#include <QPushButton>
#include <iostream>
#include <QLineEdit> 
#include <QString> 
#include <string>
#include <QtWidgets/QComboBox>
#include "Game.h"
#include "ui_QTraining.h"
#include "QTraining.h"

QGameMode::QGameMode(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	gameModeWidget = ui.gameModeWidget;
	gameI = ui.gameI;
	gameII = ui.gameII;
	gameIII = ui.gameIII;

	namePlayer1 = ui.namePlayer1;
	namePlayer2 = ui.namePlayer2;
	singleSelector = ui.singleSelector;
	play = ui.play;
	namePlayer1->hide();
	namePlayer2->hide();
	singleSelector->hide();
	play->hide();

	connect(gameI, &QPushButton::clicked, this, &QGameMode::selectFirstSlot);
	connect(gameII, &QPushButton::clicked, this, &QGameMode::selectSecondSlot);
	connect(gameIII, &QPushButton::clicked, this, &QGameMode::selectThirdSlot);
	connect(play, &QPushButton::clicked, this, &QGameMode::playGame);

	showMaximized();

}

QGameMode::~QGameMode()
{
}


void QGameMode::selectGameMode(int slot)
{
	std::cout << slot << std::endl;
}

void QGameMode::showDataInput()
{

	gameI->hide();
	gameII->hide();
	gameIII->hide();

	namePlayer1->show();
	namePlayer2->show();
	singleSelector->show();
	play->setFixedHeight(100);
	play->show();
}

void QGameMode::selectFirstSlot() {
	showDataInput();
	m_gameModeSlot = 1;
}
void QGameMode::selectSecondSlot()
{
	showDataInput();
	m_gameModeSlot = 2;
}

void QGameMode::selectThirdSlot()
{
	showDataInput();
	m_gameModeSlot = 3;
}

void QGameMode::playGame()
{
	game::Game* newGame = new game::Game();
	std::string valueNamePlayer1 = namePlayer1->text().toStdString();
	std::string valueNamePlayer2 = namePlayer2->text().toStdString();
	int valueGameMode = singleSelector->currentIndex()+1;
	newGame->selectGamemode(valueGameMode, valueNamePlayer1, valueNamePlayer2, 0, 0);

	QTraining* training = new QTraining(nullptr);
	this->hide();
}

