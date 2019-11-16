/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Charts module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "chart.h"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

double value{0};

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axisX(new QCategoryAxis()),
    m_axisY(new QCategoryAxis()),
    m_step(0),
    m_x(5),
    m_y(1)
{
    QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
    m_timer.setInterval(400);

    m_series = new QLineSeries(this);

    QPen lineColor(QColor("#6FC3DF"));
    lineColor.setWidth(3);
    m_series->setPen(lineColor);
    m_series->append(m_x, m_y);

    QPen axisColor(QColor("#6FC3DF"));
    axisColor.setWidth(2);
    m_axisX->setLinePen(axisColor);
    m_axisY->setLinePen(axisColor);

    addSeries(m_series);

    m_axisX->setTickCount(1);
    m_axisY->append("", 100);
    m_axisX->append("", 0);
    m_axisX->setRange(0, 10);
    m_axisY->setRange(-10, 10); //Fix values depending on range
    m_axisX->setGridLineVisible(false);
    m_axisY->setGridLineVisible(false);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);

    m_series->attachAxis(m_axisX);
    m_series->attachAxis(m_axisY);

    m_timer.start();
}

Chart::~Chart()
{

}

void Chart::setValue(double val)
{
    m_y = val;
}

void Chart::handleTimeout()
{
    qreal x = plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += y;
    m_y = QRandomGenerator::global()->bounded(5) - 2; //Delete when adding
    m_series->append(m_x, m_y);
    scroll(x, 0);
}
