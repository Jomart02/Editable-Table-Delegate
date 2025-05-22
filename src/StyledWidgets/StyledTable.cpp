#include "StyledTable.h"
#include <QPainterPath>

ViewStyle::ViewStyle(QStyle* style) : QProxyStyle(style) {
}
ViewStyle::~ViewStyle(){
}
void ViewStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const {
    if (element == QStyle::PE_IndicatorItemViewItemDrop && !option->rect.isNull()) {
        QStyleOption opt(*option);
        opt.rect.setLeft(0);
        
        if (widget) opt.rect.setRight(widget->width());

        painter->save();

        painter->setBrush(QColor(66, 80, 222, 255*0.1));
        painter->setPen(Qt::NoPen);

        QPainterPath pathRow;

        pathRow.addRoundedRect(opt.rect, 8, 8);
        painter->drawPath(pathRow);
        painter->restore();
        return;
    }
    QProxyStyle::drawPrimitive(element, option, painter, widget);
}

StyledTable::StyledTable(QWidget *parent) : QTableView(parent)  {
    _borderColorItems = QColor("#4150de");
    _borderColorItemsDisable = Qt::gray;
    viewStyle = new ViewStyle();
    setStyle(viewStyle);
    viewStyle->setParent(this);
}
StyledTable::~StyledTable(){
    
}

QColor StyledTable::borderColorItems() const {
    return _borderColorItems;
}

QColor StyledTable::borderColorItemsDisable() const {
    return _borderColorItemsDisable;
}

void StyledTable::setBorderColorItems(const QColor &color) {
    if (_borderColorItems != color) {
        _borderColorItems = color;
        emit borderColorItemsChanged(color);
        update();
    }
}

void StyledTable::setBorderColorItemsDisable(const QColor &color) {
    if (_borderColorItemsDisable != color) {
        _borderColorItemsDisable = color;
        emit borderColorItemsDisableChanged(color);
        update();
    }
}