#ifndef WATERLOOPGAUGEITEM_H
#define WATERLOOPGAUGEITEM_H

#include "qcgaugewidget.h"
#include "qcthemeitem.h"
#include <QGraphicsDropShadowEffect>


class waterLoopGaugeItem : public QcGaugeWidget
{
public:
    waterLoopGaugeItem();
    waterLoopGaugeItem(QcThemeItem &theme, qreal size, QString type, QString label, QString units,qreal precision, qreal maxValue, qreal warningValueHigh, qreal warningValueMed, qreal stepSize);
    QcGaugeWidget * getGauge();
    void setCurrentValue(qreal value);

private:
    QcGaugeWidget * mainGauge = nullptr;
    QcNeedleItem * mSpeedNeedle = nullptr;
    QcColorBand * mDynamicColorBand = nullptr;
    QcColorBand * mDynamicColorBandDegrees = nullptr;
    QcValuesItem * lightUpValues =nullptr;
    QcBackgroundItem * mainBackground = nullptr;
    QcBackgroundItem * needleCover = nullptr;
    QGraphicsDropShadowEffect * dropShadow = nullptr;
    QcDynamicArcItem * positionIndicatior = nullptr;
    QString type;
    QString label;
    QString units;
    qreal maxValue;
    qreal warningValueHigh;
    qreal warningValueMed;
    qreal stepSize;



};

#endif // WATERLOOPGAUGEITEM_H
