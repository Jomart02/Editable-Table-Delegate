#pragma once
#include <QTableView>
#include <QProxyStyle>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

class ViewStyle : public QProxyStyle {
public:
    ViewStyle(QStyle* style = nullptr);
    ~ViewStyle();
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const override;
};

class StyledTable : public QTableView {
    Q_OBJECT
    Q_PROPERTY(QColor borderColorItems READ borderColorItems WRITE setBorderColorItems NOTIFY borderColorItemsChanged)
    Q_PROPERTY(QColor borderColorItemsDisable READ borderColorItemsDisable WRITE setBorderColorItemsDisable NOTIFY borderColorItemsDisableChanged)

public:
    explicit StyledTable(QWidget *parent = nullptr);
    ~StyledTable();

    QColor borderColorItems() const;
    QColor borderColorItemsDisable() const;

public slots:
    void setBorderColorItems(const QColor &color);
    void setBorderColorItemsDisable(const QColor &color);

signals:
    void borderColorItemsChanged(const QColor &color);
    void borderColorItemsDisableChanged(const QColor &color);

private:
    QColor _borderColorItems;
    QColor _borderColorItemsDisable;
    ViewStyle *viewStyle = nullptr;
};