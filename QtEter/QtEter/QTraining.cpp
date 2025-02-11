#include "QTraining.h"
#include <string>

QTraining::QTraining(QWidget* parent)
{
	ui.setupUi(this);
	trainingTableWidget = ui.trainingTableWidget;

	space00 = ui.space00;
	space01 = ui.space01;
	space02 = ui.space02;
	space03 = ui.space03;
	space04 = ui.space04;

	space10 = ui.space10;
	space11 = ui.space11;
	space12 = ui.space12;
	space13 = ui.space13;
	space14 = ui.space14;

	space20 = ui.space20;
	space21 = ui.space21;
	space22 = ui.space22;
	space23 = ui.space23;
	space24 = ui.space24;

	space30 = ui.space30;
	space31 = ui.space31;
	space32 = ui.space32;
	space33 = ui.space33;
	space34 = ui.space34;

	space40 = ui.space40;
	space41 = ui.space41;
	space42 = ui.space42;
	space43 = ui.space43;
	space44 = ui.space44;


	space01->hide();
	space02->hide();
	space10->hide();
	space11->hide();
	space12->hide();
	space20->hide();
	space21->hide();
	space22->hide();

	showMaximized();
}

QTraining::~QTraining()
{
}
void QTraining::createBoard() {
	std::string border = "1/1";
	size_t separatorPos = border.find('/');

	int row = std::stoi(border.substr(0, separatorPos));
	int height = std::stoi(border.substr(separatorPos + 1));


}
