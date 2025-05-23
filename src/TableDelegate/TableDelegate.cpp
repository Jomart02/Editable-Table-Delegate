#include "TableDelegate.h"
#include <qcombobox.h>
#include <qdatetimeedit.h>
#include <qglobal.h>
#include <qnamespace.h>
#include "CoordinateEdit.h"
#include "NaviStrings.h"
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QTimeEdit>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QCheckBox>
#include <QPainter>
#include <QApplication>
#include <QStyle>
#include <QMouseEvent>
#include <QRadioButton>
#include <qpushbutton.h>
// #include "ToggleSwitch.hpp"
#include "StylePropDefines.h"

TableDelegate::TableDelegate(QObject *parent) : QStyledItemDelegate(parent) {

}


void TableDelegate::initializePainter(QPainter* painter, QStyleOptionViewItem& opt) const {
    QColor base = opt.palette.color(QPalette::Base);
    painter->setBrush(base);
    painter->setPen(Qt::NoPen);
    painter->drawRoundedRect(opt.rect,0,0);
    
    opt.rect.adjust(0,  1, 0, -1); //Сужаем снизу и сверху чтобы получить область между строками

}

void TableDelegate::createPathCell(QRect rectCell, const QModelIndex &index,QPainterPath &path ) const{
    if (index.column() == 0) {
        addCustomRoundedRect(path, rectCell, 6, 6, true); // First column
    } else if (index.column() == index.model()->columnCount() - 1) {
        addCustomRoundedRect(path, rectCell, 6, 6, false); // Last column
    } else {
        bool isPenultimateColumn = (index.column() == index.model()->columnCount() - 2);
        bool isLastColumnDeleteButton = false;
        if (isPenultimateColumn) {
            QModelIndex lastColumnIndex = index.sibling(index.row(), index.model()->columnCount() - 1);
            isLastColumnDeleteButton = lastColumnIndex.data(Qt::UserRole + 1).isValid() &&
                                       lastColumnIndex.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::DeleteButton;
        }
    
        if (isPenultimateColumn && isLastColumnDeleteButton) {
            // Если текущий столбец предпоследний и последний — DeleteButton, рисуем скругление справа
            addCustomRoundedRect(path, rectCell, 6, 6, false);
        } else {
            path.addRect(rectCell); 
        }
    }
}

QRect TableDelegate::getRectElementCell(QRect rectCell,const QModelIndex &index){
    rectCell.adjust(2, 4, -2, -4);
    if(index.column() == index.model()->columnCount() - 1) rectCell.adjust(0, 0, -6, 0);
    else if(index.column() == 0) rectCell.adjust(6, 0, 0, 0);

    rectCell = rectCell.adjusted(0.25, 0.25, -0.25, -0.25);

    return rectCell;
}

void TableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const{
        
    QStyleOptionViewItem opt = option;
    painter->save();

    QColor base = option.palette.color(QPalette::Base);
    painter->setBrush(base);
    painter->setPen(Qt::NoPen);
    painter->drawRoundedRect(opt.rect,0,0);
    
    opt.rect.adjust(0,  1, 0, -1); //Сужаем снизу и сверху чтобы получить область между строками

    QPainterPath path;
    QRect rectCell = opt.rect;
    createPathCell(rectCell,index,path);

    //цвет текста и фона
    QColor textColor ;
    QColor backgroundColor = opt.palette.color(QPalette::Base);
    //Если элемент выбран 
    if (opt.state & QStyle::State_Selected) {
        if(!(index.data(Qt::UserRole + 1).isValid() && index.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::DeleteButton)){
            backgroundColor = opt.palette.color(QPalette::Highlight);
        }
        textColor = index.data(Qt::ForegroundRole).value<QColor>();
        if(!textColor.isValid()) textColor = opt.palette.color(QPalette::HighlightedText);
        opt.palette.setColor(QPalette::HighlightedText,textColor);
    }else{
        textColor = index.data(Qt::ForegroundRole).value<QColor>();
        if(!textColor.isValid()) textColor= opt.palette.color(QPalette::WindowText);
        opt.palette.setColor(QPalette::Text,textColor);
    }
    //Отрисовка фон
    painter->setBrush(backgroundColor);
    painter->setPen(Qt::NoPen);
    painter->setRenderHint(QPainter::RenderHint::Antialiasing, true);
    painter->drawPath(path);

    if(!colOffBorder.contains(index.column())){
        QPainterPath pathBorder;
        //Отрисовка ячейки
        rectCell = getRectElementCell(opt.rect,index);
        pathBorder.addRoundedRect(rectCell, 8, 8);

        QPen pen;
        // pen.setWidthF(1.0);
        pen.setColor(getBorderColor(index.flags().testFlag(Qt::ItemIsEditable),opt.widget));
        // pen.setCosmetic(false);
        painter->setPen(pen);
        painter->drawPath(pathBorder);
    }


    if (index.data(Qt::UserRole + 1).isValid() && index.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::Button) {
        QStyleOptionButton buttonOption;
        QRect rectB = rectCell.adjusted(4, 2, -4, -2); 
        buttonOption.rect = rectB;
        buttonOption.text = index.data(Qt::DisplayRole).toString();
        
        auto parent = const_cast<QWidget*>(opt.widget);
        QPushButton but;
        but.setParent(parent);
        
        if(index.data(Qt::UserRole + 2).isValid()){
            auto list = index.data(Qt::UserRole + 2).value<QStringList>();
            for(auto prop:list){
                but.setProperty(prop.toUtf8(),true);
            }
            but.style()->polish(&but);
            but.style()->unpolish(&but);
            but.update();
        }


        but.setText(index.data(Qt::DisplayRole).toString());
        
        buttonOption.state = QStyle::State_Raised; // Базовое состояние кнопки
        if (index.flags().testFlag(Qt::ItemIsEditable)) {
            buttonOption.state |= QStyle::State_Enabled;
            if (opt.state & QStyle::State_MouseOver) {
                
                buttonOption.state |= QStyle::State_MouseOver; // Hover
            }
            if (opt.state & QStyle::State_Sunken || opt.state & QStyle::State_Selected) {
                buttonOption.state |= QStyle::State_Sunken; // Pressed
            }
        } else {
            buttonOption.state |= QStyle::State_None; // Disabled
        }
        

        QStyle* style =parent->style();
        style->drawControl(QStyle::CE_PushButton, &buttonOption, painter, &but);
        but.setParent(nullptr);
        painter->restore();
        return;
    }
    if (index.data(Qt::UserRole + 1).isValid() && index.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::DeleteButton) {
        int size = qMin(rectCell.width(), rectCell.height()) * 0.5; 
        size = qMax(size, 10);
        int x = rectCell.left() + (rectCell.width() - size) / 2;
        int y = rectCell.top() + (rectCell.height() - size) / 2;
        QRect crossRect(x, y, size, size);

        QColor colorCross = QColor(Qt::red);
        if (!index.flags().testFlag(Qt::ItemIsEditable)) colorCross = QColor(Qt::gray); 
        QPen pen(colorCross, 3);
        pen.setCapStyle(Qt::RoundCap); // Скругленные концы линий
        painter->setPen(pen);
        painter->setRenderHint(QPainter::Antialiasing, true);

        painter->drawLine(crossRect.topLeft(), crossRect.bottomRight()); 
        painter->drawLine(crossRect.topRight(), crossRect.bottomLeft()); 

        painter->restore();
        return;
    }
    if (index.data(Qt::UserRole + 1).isValid() && index.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::DragButton) {
        painter->setBrush(QColor("#F0F0F0"));
        painter->setPen(Qt::NoPen);
        painter->drawPath(path);

        int dotSize = qMin(rectCell.width(), rectCell.height()) * 0.15; 
        dotSize = qMax(dotSize, 2); 

        int centerX = rectCell.left() + rectCell.width() / 2;

        int centerY = rectCell.top() + rectCell.height() / 2;

        int spacing = rectCell.height() * 0.2;
        spacing = qMax(spacing, dotSize + 2); //  расстояние между точками

        int topY = centerY - spacing;    
        int middleY = centerY;           
        int bottomY = centerY + spacing;
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(Qt::NoPen);
        painter->setBrush(Qt::black); 

        painter->drawEllipse(QPoint(centerX, topY), dotSize, dotSize);    
        painter->drawEllipse(QPoint(centerX, middleY), dotSize, dotSize);
        painter->drawEllipse(QPoint(centerX, bottomY), dotSize, dotSize); 

        painter->restore();
        return;
    }

    //Надо для отрисовки чек бокса и переклюяателя - хз как получать нужный размер - пока 24х24
    if (index.flags().testFlag(Qt::ItemIsUserCheckable) && index.data(Qt::UserRole + 1).isValid()) {
        Qt::CheckState checkState = static_cast<Qt::CheckState>(index.data(Qt::CheckStateRole).toInt());
        ColumnType type = index.data(Qt::UserRole + 1).value<ColumnType>();
        auto parent = const_cast<QWidget*>(opt.widget);
        bool isChecked = (checkState == Qt::Checked);
        bool isEnabled = index.flags().testFlag(Qt::ItemIsEditable);


        // if(type == ColumnType::Switch){
            
        //     int w = rectCell.width()*0.9;
        //     int h = rectCell.height()*0.8;
        //     int x = rectCell.left() + (rectCell.width()/2) - w/2;
        //     int y = rectCell.top() + (rectCell.height()/2) - h/2;
        //     QRect switchRect(x, y, w, h); 

        //     ToggleSwitch switchWidget;
        //     switchWidget.setAttribute(Qt::WA_TranslucentBackground); 
        //     switchWidget.setAnimated(false);
        //     switchWidget.setAutoFillBackground(false);
        //     switchWidget.setGeometry(switchRect);
        //     switchWidget.setToggled(isChecked);
        //     switchWidget.setEnabled(isEnabled);
        //     switchWidget.style()->polish(&switchWidget);
        //     switchWidget.style()->unpolish(&switchWidget);
        //     switchWidget.update();


        //     QPixmap pixmap(switchRect.size());
        //     pixmap.fill(Qt::transparent); 
        //     switchWidget.render(&pixmap);
        //     painter->drawPixmap(switchRect, pixmap);
        //     painter->restore();
        //     switchWidget.setParent(nullptr);

        //     return;
        // }
        
        int size = std::min(rectCell.width(),rectCell.height())*0.75;
        int x = rectCell.left() + (rectCell.width()/2) - size/2;
        int y = rectCell.top() + (rectCell.height()/2) - size/2;
        QRect indicatorRect(x, y, size, size);        
        
        QColor colorCheckb = textColor;
        if(!isEnabled) colorCheckb = Qt::gray;

        if (type == ColumnType::Checkbox) {
            drawCustomCheckBox(painter, indicatorRect, isChecked, colorCheckb);
        } else if (type == ColumnType::RadioButton) {
            drawCustomRadioButton(painter, indicatorRect, isChecked, colorCheckb);
        }

        painter->restore();
        return;
    }

    // Получаем текст из модели
    QString text = index.data().toString();
    //Отрисовка текста
    rectCell = rectCell.adjusted(5, 0, -5, 0);
    if(!text.isEmpty()){
        // Получаем текущий шрифт
        QFont font = painter->font();
        QFontMetrics fontMetrics(font);

        // Максимальная доступная ширина
        int maxWidth = rectCell.width();
        text.remove("\n");
        // Проверяем, помещается ли текст
        if (fontMetrics.horizontalAdvance(text) > maxWidth) {
            // Если текст не помещается, сокращаем его
            text = fontMetrics.elidedText(text, Qt::ElideRight, maxWidth);
        }

        painter->setPen(textColor);
        painter->drawText(rectCell,index.data(Qt::TextAlignmentRole).value<int>() , text);
    }
    // QStyledItemDelegate::paint(painter, opt, index);
    painter->restore();
}


// Реализация методов в .cpp файле
void TableDelegate::drawCustomCheckBox(QPainter *painter, const QRect &rect, bool checked, const QColor &color) {
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);
    QPen pen(color, 2); 
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);

    painter->drawRoundedRect(rect, 4, 4);

    if (checked) {
        QPainterPath path;
        // Первая линия (левая часть галочки)
        path.moveTo(rect.left() + rect.width() * 0.25, rect.top() + rect.height() * 0.55);
        path.lineTo(rect.left() + rect.width() * 0.45, rect.top() + rect.height() * 0.75);
        // Вторая линия (правая часть галочки)
        path.lineTo(rect.left() + rect.width() * 0.75, rect.top() + rect.height() * 0.35);
        painter->drawPath(path);
    }

    painter->restore();
}

void TableDelegate::drawCustomRadioButton(QPainter *painter, const QRect &rect, bool checked, const QColor &color) {
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);
    QPen pen(color, 2); 
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);
    QRect uotRect = rect.adjusted(rect.width() * 0.2, rect.height() * 0.2, -rect.width() * 0.2, -rect.height() * 0.2);
    painter->drawEllipse(uotRect);

    if (checked) {
        painter->setBrush(color);
        QRect innerRect = rect.adjusted(rect.width() * 0.3, rect.height() * 0.3, -rect.width() * 0.3, -rect.height() * 0.3);
        painter->drawEllipse(innerRect);
    }

    painter->restore();
}

QSize TableDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    // Получаем текст из модели
    if (index.flags().testFlag(Qt::ItemIsUserCheckable) && index.data(Qt::UserRole + 1).isValid()) {

        // if(index.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::Switch){
        //     return QSize(60,option.rect.size().height()); 
        // }

        if(option.rect.size().width() < 36 ) return QSize(36,option.rect.size().height()); 
        if(option.rect.size().height() < 36 ) return QSize(option.rect.size().width(),36); 
        return option.rect.size();
    } 
    if(index.data(Qt::UserRole + 1).isValid() && index.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::Button){
       
        QString text = index.data().toString();
        QFontMetrics metrics(option.font);
        int width = metrics.horizontalAdvance(text) + textmargin*4;
        int height = metrics.height();
    
        return QSize(width, height);
    }
    if(index.data(Qt::UserRole + 1).isValid() && index.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::DeleteButton){
        if(option.rect.size().width() < 36 || option.rect.size().height() < 36) return QSize(36,36); 
        return option.rect.size();
    }
    if(index.data(Qt::UserRole + 1).isValid() && index.data(Qt::UserRole + 1).value<ColumnType>() == ColumnType::DragButton){
        return QSize(20,option.rect.size().height()); 
    }
    QString text = index.data().toString();
    QFontMetrics metrics(option.font);
    int width = metrics.horizontalAdvance(text) + textmargin; 
    int height = option.fontMetrics.height() + 10;

    return QSize(width, height);
}

void TableDelegate::addCustomRoundedRect(QPainterPath &path, const QRectF &rect, qreal xRadius, qreal yRadius, bool leftOrRightSide, Qt::SizeMode mode )
{
    QRectF r = rect.normalized();

    if (r.isNull())
        return;

    // Корректировка радиуса
    if (mode == Qt::AbsoluteSize) {
        qreal w = r.width() / 2;
        qreal h = r.height() / 2;
        if (w == 0) {
            xRadius = 0;
        } else {
            xRadius = 100 * qMin(xRadius, w) / w;
        }
        if (h == 0) {
            yRadius = 0;
        } else {
            yRadius = 100 * qMin(yRadius, h) / h;
        }
    } else {
        if (xRadius > 100)
            xRadius = 100;

        if (yRadius > 100)
            yRadius = 100;
    }

    if (xRadius <= 0 || yRadius <= 0) {
        path.addRect(r);
        return;
    }

    qreal x = r.x();
    qreal y = r.y();
    qreal w = r.width();
    qreal h = r.height();
    qreal rxx2 = w * xRadius / 100;
    qreal ryy2 = h * yRadius / 100;

    if(leftOrRightSide) {
        path.moveTo(x, y + ryy2);
        path.arcTo(x, y, rxx2, ryy2, 180, -90);
        path.lineTo(x + w, y);
        path.lineTo(x + w, y + h);
        path.lineTo(x + rxx2, y + h);
        path.arcTo(x, y + h - ryy2, rxx2, ryy2, 270, -90);
    } else {
        path.moveTo(x, y);
        path.lineTo(x + w - rxx2, y);
        path.arcTo(x + w - rxx2, y, rxx2, ryy2, 90, -90);
        path.lineTo(x + w, y + h - ryy2);
        path.arcTo(x + w - rxx2, y + h - ryy2, rxx2, ryy2, 0, -90);
        path.lineTo(x, y + h);
    }

    path.closeSubpath();
}

QColor TableDelegate::getBorderColor(bool enabled, const QWidget* widget){
    QString propName = enabled ? BORDER_COLOR_ITEMS : BORDER_COLOR_ITEMS_DIS;
    QVariant borderColorProp = widget->property(propName.toUtf8());
    return borderColorProp.isValid() && borderColorProp.canConvert<QColor>()
         ? borderColorProp.value<QColor>()
         : QColor("#F0F0F0");
}

void TableDelegate::offColumnBorger(int col){
    colOffBorder.insert(col);
}
void TableDelegate::offColumnBorger(QSet<int> col){
    colOffBorder = col;
}
void TableDelegate::removeColumnOffBorger(int col){
    if(colOffBorder.contains(col)) colOffBorder.remove(col);
}
void TableDelegate::setMarginText(int marg){
    textmargin = marg;
}

void TableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    
    if (colOffBorder.contains(index.column())) {
        QStyledItemDelegate::updateEditorGeometry(editor, option, index);
        return;
    }
    
    QRect rectCell = option.rect;
    rectCell.adjust(0,  1, 0, -1); 
    rectCell = getRectElementCell(rectCell,index);
    editor->setGeometry(rectCell);

}

bool TableDelegate::editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index)
{
    //Для правильного переключения чекбокса - эта дура индецифицирует себя как рект левого угла а не ровный (пацан)чекбокс по центру
    if (event->type() == QEvent::MouseButtonRelease && index.flags().testFlag(Qt::ItemIsUserCheckable)) {

        if (!index.flags().testFlag(Qt::ItemIsEditable)) {
            return false; 
        }
        auto mouseEvent = static_cast<QMouseEvent*>(event);
        QRect checkBoxRect ;
        int x = option.rect.left() + option.rect.width()/2 -20;
        int y = option.rect.top() + option.rect.height()/2 -20;
        checkBoxRect = QRect(x,y,40, 40);
        
        if (checkBoxRect.contains(mouseEvent->pos())) {
            auto isChecked = model->data(index, Qt::CheckStateRole).toBool();
            QVariant newValue = !isChecked ? Qt::Checked : Qt::Unchecked;
            model->setData(index, newValue, Qt::CheckStateRole);
            return true; 
        }
        return false; 
    }
    if(event->type() == QEvent::MouseButtonRelease && index.data(Qt::UserRole + 1).isValid() && index.flags().testFlag(Qt::ItemIsEditable)){
        auto colType = index.data(Qt::UserRole + 1).value<ColumnType>();

        if(colType == ColumnType::Button){
            buttonClicked(index);
            return true;     
        }
        if(colType == ColumnType::DeleteButton){
            deleteButtonCicked(index);
            return true; 
        }
        return false; 
    } 

    return QStyledItemDelegate::editorEvent(event, model, option, index);
}


//================================================================================================================================



TableWidgetsDelegate::TableWidgetsDelegate(QObject *parent, ConnectionType _typeConnect ): TableDelegate(parent),typeConnect(_typeConnect){

}

QWidget *TableWidgetsDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const{
    if (!(index.flags() & Qt::ItemIsEditable)) {
        return nullptr;
    }

    ColumnType type = index.data(Qt::UserRole + 1).value<ColumnType>();
    QWidget *editor = nullptr;

    QColor textColor = index.data(Qt::ForegroundRole).value<QColor>();
    if (!textColor.isValid()) {
        textColor = option.palette.color(QPalette::WindowText);
    }

    switch (type) {
        case ColumnType::DoubleSpinBox: {
            QDoubleSpinBox *spinBox = new QDoubleSpinBox(parent);
            spinBox->setMinimum(0);
            spinBox->setWrapping(true);
            spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
            
            if(index.data(Qt::UserRole +5).isValid()) spinBox->setDecimals(index.data(Qt::UserRole + 5).toInt());
            else spinBox->setDecimals(2);
            
            spinBox->setSpecialValueText("---");
            if(index.data(Qt::UserRole +3).isValid()) spinBox->setMinimum(index.data(Qt::UserRole +3).toDouble());
            if(index.data(Qt::UserRole +4).isValid()) spinBox->setMaximum(index.data(Qt::UserRole +4).toDouble());
            connect(spinBox, qOverload<double>(&QDoubleSpinBox::valueChanged), this, [=](double value) {
                const_cast<TableWidgetsDelegate*>(this)->commitData(spinBox);
            });
            editor = spinBox;
            break;
        }
        case ColumnType::SpinBox: {
            QSpinBox *spinBox = new QSpinBox(parent);
            spinBox->setMinimum(0);
            spinBox->setWrapping(true);
            spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
            spinBox->setSpecialValueText("---");
            connect(spinBox, qOverload<int>(&QSpinBox::valueChanged), this, [=](int value) {
                const_cast<TableWidgetsDelegate*>(this)->commitData(spinBox);
            });
            editor = spinBox;
            break;
        }
        case ColumnType::LineEdit: {
            QLineEdit *lineEdit = new QLineEdit(parent);
            lineEdit->setMaxLength(20);
            
            if(index.data(Qt::UserRole +5).isValid()) {
                if(index.data(Qt::UserRole +5).canConvert<QRegularExpression>()){
                    QRegularExpression reg = index.data(Qt::UserRole +5).value<QRegularExpression>();
                    lineEdit->setValidator( new QRegularExpressionValidator(reg, lineEdit));
                }
                
            }

            if(index.data(Qt::UserRole +6).isValid()) {
                if(index.data(Qt::UserRole +6).canConvert<QLineEdit::EchoMode>()){
                    QLineEdit::EchoMode echo = index.data(Qt::UserRole +6).value<QLineEdit::EchoMode>();
                    lineEdit->setEchoMode(echo);
                }
                
            }
            
            if(typeConnect == ConnectionType::valueChanged){
                connect(lineEdit, &QLineEdit::textEdited, this, [=](const QString &text) {
                    const_cast<TableWidgetsDelegate*>(this)->commitData(lineEdit);
                });
            }
            editor = lineEdit;
            break;
        }
        case ColumnType::ComboBox: {
            QComboBox *comboBox = new QComboBox(parent);
            //
            if(index.data(Qt::UserRole +2).isValid()) comboBox->addItems(index.data(Qt::UserRole +2).toStringList());
            connect(comboBox, qOverload<int>(&QComboBox::currentIndexChanged), this, [=](int) {
                const_cast<TableWidgetsDelegate*>(this)->commitData(comboBox);
            });
            editor = comboBox;
            break;
        }
        case ColumnType::Checkbox: {
            return nullptr;
            // QCheckBox *checkBox = new QCheckBox(parent);
            // connect(checkBox, &QCheckBox::stateChanged, this, [=](int state) {
            //     const_cast<TableWidgetsDelegate*>(this)->commitData(checkBox);
            // });
            // editor = checkBox;
            // break;
        }
        case ColumnType::LatEdit: {
            LatitudeEdit *latEdit = new LatitudeEdit(parent);
            connect(latEdit, qOverload<double>(&LatitudeEdit::valueChanged), this, [=](double value) {
                const_cast<TableWidgetsDelegate*>(this)->commitData(latEdit);
            });
            editor = latEdit;
            break;
        }
        case ColumnType::LongEdit: {
            LongitudeEdit *lonEdit = new LongitudeEdit(parent);
            connect(lonEdit, qOverload<double>(&LongitudeEdit::valueChanged), this, [=](double value) {
                const_cast<TableWidgetsDelegate*>(this)->commitData(lonEdit);
            });
            editor = lonEdit;
            break;
        }
        case ColumnType::TimeEdit: {
            QTimeEdit *timeEdit = new QTimeEdit(parent);
            timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
            timeEdit->setDisplayFormat("HH:mm:ss");
            connect(timeEdit, &QTimeEdit::timeChanged, this, [=](const QTime &time) {
                const_cast<TableWidgetsDelegate*>(this)->commitData(timeEdit);
            });
            editor = timeEdit;
            break;
        }
        case ColumnType::DateEdit: {
            QDateEdit *dateEdit = new QDateEdit(parent);
            dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
            connect(dateEdit, &QDateEdit::dateChanged, this, [=](const QDate &date) {
                const_cast<TableWidgetsDelegate*>(this)->commitData(dateEdit);
            });
            editor = dateEdit;
            break;
        }
        case ColumnType::AltitEdit: {
            AltitudeEdit *altEdit = new AltitudeEdit(parent);
            connect(altEdit, qOverload<double>(&AltitudeEdit::valueChanged), this, [=](double value) {
                const_cast<TableWidgetsDelegate*>(this)->commitData(altEdit);
            });
            editor = altEdit;
            break;
        }
        case ColumnType::RadioButton: {
            QRadioButton *radBut = new QRadioButton(parent);
            connect(radBut, &QRadioButton::toggled, this, [=](int state)  {
                const_cast<TableWidgetsDelegate*>(this)->commitData(radBut);
            });
            editor = radBut;
            break;
        }
        case ColumnType::Button: 
        case ColumnType::DeleteButton:
        case ColumnType::DragButton: 
        // case ColumnType::Switch: 
            // QPushButton *button = new QPushButton(parent);
            // button->setText(index.data(Qt::DisplayRole).toString());
            
            // if(index.data(Qt::UserRole + 2).isValid()){
            //     auto list = index.data(Qt::UserRole + 2).value<QStringList>();
            //     for(auto prop:list){
            //         button->setProperty(prop.toUtf8(),true);
            //     }
            //     button->style()->polish(button);
            //     button->style()->unpolish(button);
            //     button->update();
            // }
            // connect(button, &QPushButton::clicked, this, [=]()  {
            //     buttonClicked(index);
            // });

            // editor = button;
            return nullptr;
            break;
        
        default:
            editor = QStyledItemDelegate::createEditor(parent, option, index);
    }
    editor->setStyleSheet(QString("color:%1;").arg(textColor.name()));
    
    return editor;
}

void TableWidgetsDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
    ColumnType type = index.data(Qt::UserRole + 1).value<ColumnType>();
    
    switch (type) {
        case ColumnType::DoubleSpinBox: {
            QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
            spinBox->setValue(index.model()->data(index, Qt::EditRole).toDouble());
            break;
        }
        case ColumnType::SpinBox: {
            QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
            spinBox->setValue(index.model()->data(index, Qt::EditRole).toInt());
            break;
        }
        case ColumnType::LineEdit: {
            QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
            lineEdit->setText(index.model()->data(index, Qt::EditRole).toString());
            break;
        }
        case ColumnType::ComboBox: {
            QComboBox *comboBox = static_cast<QComboBox*>(editor);
            comboBox->setCurrentIndex(index.model()->data(index, Qt::EditRole).toInt());
            break;
        }
        case ColumnType::Checkbox: {
            QCheckBox *checkBox = static_cast<QCheckBox*>(editor);
            checkBox->setChecked(index.model()->data(index, Qt::CheckStateRole).toInt() == Qt::Checked);
            break;
        }
        case ColumnType::LatEdit: {
            LatitudeEdit *latEdit = static_cast<LatitudeEdit*>(editor);
            latEdit->setValue(index.model()->data(index, Qt::EditRole).toDouble());
            break;
        }
        case ColumnType::LongEdit: {
            LongitudeEdit *lonEdit = static_cast<LongitudeEdit*>(editor);
            lonEdit->setValue(index.model()->data(index, Qt::EditRole).toDouble());
            break;
        }
        case ColumnType::TimeEdit: {
            QTimeEdit *timeEdit = static_cast<QTimeEdit*>(editor);
            timeEdit->setTime(index.model()->data(index, Qt::EditRole).toTime());
            break;
        }
        case ColumnType::DateEdit: {
            QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
            dateEdit->setDate(index.model()->data(index, Qt::EditRole).toDate());
            break;
        }
        case ColumnType::AltitEdit: {
            AltitudeEdit *altEdit = static_cast<AltitudeEdit*>(editor);
            altEdit->setValue(index.model()->data(index, Qt::EditRole).toDouble());
            break;
        }
        case ColumnType::RadioButton: {
            QRadioButton *radBut =  static_cast<QRadioButton*>(editor);
            radBut->setChecked(index.model()->data(index, Qt::CheckStateRole).toInt() == Qt::Checked);
            break;
        }
        default:
            QStyledItemDelegate::setEditorData(editor, index);
    }
}

void TableWidgetsDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    ColumnType type = index.data(Qt::UserRole + 1).value<ColumnType>();
    
    switch (type) {
        case ColumnType::DoubleSpinBox: {
            QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
            model->setData(index, spinBox->value(), Qt::EditRole);
            model->setData(index, QString::number(spinBox->value(), 'f', 2), Qt::DisplayRole);
            break;
        }
        case ColumnType::SpinBox: {
            QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
            model->setData(index, spinBox->value(), Qt::EditRole);
            model->setData(index, QString::number(spinBox->value()), Qt::DisplayRole);
            break;
        }
        case ColumnType::LineEdit: {
            QLineEdit *lineEdit = static_cast<QLineEdit*>(editor);
            model->setData(index, lineEdit->text(), Qt::EditRole);
            model->setData(index, lineEdit->text(), Qt::DisplayRole);
            break;
        }
        case ColumnType::ComboBox: {
            QComboBox *comboBox = static_cast<QComboBox*>(editor);
            model->setData(index, comboBox->currentIndex(), Qt::EditRole);
           // model->setData(index, comboBox->currentText(), Qt::DisplayRole);
            break;
        }
        case ColumnType::Checkbox: {
            QCheckBox *checkBox = static_cast<QCheckBox*>(editor);
            model->setData(index, checkBox->isChecked() ? Qt::Checked : Qt::Unchecked, Qt::CheckStateRole);
            break;
        }
        case ColumnType::LatEdit: {
            LatitudeEdit *latEdit = static_cast<LatitudeEdit*>(editor);
            model->setData(index, latEdit->value(), Qt::EditRole);
         //   model->setData(index, geoLat(latEdit->value()), Qt::DisplayRole);
            break;
        }
        case ColumnType::LongEdit: {
            LongitudeEdit *lonEdit = static_cast<LongitudeEdit*>(editor);
            model->setData(index, lonEdit->value(), Qt::EditRole);
           // model->setData(index, geoLon(lonEdit->value()), Qt::DisplayRole);
            break;
        }
        case ColumnType::TimeEdit: {
            QTimeEdit *timeEdit = static_cast<QTimeEdit*>(editor);
            model->setData(index, timeEdit->time(), Qt::EditRole);
            model->setData(index, timeEdit->time().toString("hh:mm:ss"), Qt::DisplayRole);
            break;
        }
        case ColumnType::DateEdit: {
            QDateEdit *dateEdit = static_cast<QDateEdit*>(editor);
            model->setData(index, dateEdit->date(), Qt::EditRole);
            model->setData(index, dateEdit->date().toString(Qt::ISODate), Qt::DisplayRole);
            break;
        }
        case ColumnType::AltitEdit: {
            AltitudeEdit *altEdit = static_cast<AltitudeEdit*>(editor);
            model->setData(index, altEdit->value(), Qt::EditRole);
            model->setData(index, altEdit->text(), Qt::DisplayRole);
            break;
        }
        case ColumnType::RadioButton: {
            QRadioButton *radBut =  static_cast<QRadioButton*>(editor);
            model->setData(index, radBut->isChecked() ? Qt::Checked : Qt::Unchecked, Qt::CheckStateRole);
            break;
        }
        default:
            QStyledItemDelegate::setModelData(editor, model, index);
    }
}

