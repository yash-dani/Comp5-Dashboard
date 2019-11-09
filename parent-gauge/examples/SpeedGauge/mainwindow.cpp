/***************************************************************************
**                                                                        **
**  QcGauge, for instrumentation, and real time data measurement          **
**  visualization widget for Qt.                                          **
**  Copyright (C) 2015 Hadj Tahar Berrima                                 **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU Lesser General Public License as        **
**  published by the Free Software Foundation, either version 3 of the    **
**  License, or (at your option) any later version.                       **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU Lesser General Public License for more details.                   **
**                                                                        **
**  You should have received a copy of the GNU Lesser General Public      **
**  License along with this program.                                      **
**  If not, see http://www.gnu.org/licenses/.                             **
**                                                                        **
****************************************************************************
**           Author:  Hadj Tahar Berrima                                  **
**           Website: http://pytricity.com/                               **
**           Contact: berrima_tahar@yahoo.com                             **
**           Date:    1 dec 2014                                          **
**           Version:  1.0                                                **
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QcThemeItem mainTheme = QcThemeItem(":/styles/waterLoopThemeRETRO.txt");
    QcThemeItem newTheme = QcThemeItem(":/styles/waterLoopThemeNEW.txt");
    speedoMeter = new waterLoopGaugeItem(mainTheme, 250,"Speedometer","SPEED","Km/h",1, 400,300,200,50);
    voltMeter = new waterLoopGaugeItem(newTheme, 250, "Voltmeter", "", "V",2 ,1, 0.5, 0.25, 0.1);
    ui->verticalLayout->addWidget(speedoMeter->getGauge());
    ui->verticalLayout->addWidget(voltMeter->getGauge());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    speedoMeter->setCurrentValue(value);
    voltMeter->setCurrentValue(value);
}
