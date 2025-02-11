#pragma once
#include "ui_QGameMode.h"
#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QLineEdit> 
#include <QtWidgets/QComboBox>

class QGameMode : public QMainWindow
{
    Q_OBJECT
public:
    QGameMode(QWidget* parent = nullptr);
    ~QGameMode();

    int m_gameModeSlot;
private slots:
    void selectFirstSlot();
    void selectSecondSlot();
    void selectThirdSlot();
    void playGame();

    void selectGameMode(int slot);
    void showDataInput();

private:
    Ui::QGameModeClass ui;

    QHBoxLayout* layout;

    QWidget* gameModeWidget;
    QPushButton* gameI;
    QPushButton* gameII;
    QPushButton* gameIII;

    QLineEdit* namePlayer1;
    QLineEdit* namePlayer2;
    QComboBox* singleSelector;
    QPushButton* play;

};

