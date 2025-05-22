#pragma once
#include "CoordinateEdit.h"
#include <QStyledItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QPainterPath>
#include <qabstractitemmodel.h>
#include <qmap.h>
#include <qsize.h>
#include <qtmetamacros.h>
#include <QObject>

#define COLUMN_TYPE_DATA_INDEX Qt::UserRole+1




/// 
/// @brief Делегат для представления строк таблицы в установленном формате 
/// Отрисовка ведется относительно установленного стиля или прочих параметров 
/// Так же для можно утановить какой виджет будет отрсовываться в ячейке через ColumnType в UserRole +1 
/// Если ничего не установлено - обычная ячейка
///
/// Для отображения ячеек в редактируемом и нередактируемом состояних таблица должна быть перобразована в StyledTable
/// @see StyledTable.hpp


class TableDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    enum class ColumnType{
        DoubleSpinBox, 
                    //UserRole + 2 - suffix
                    //UserRole + 3 - min
                    //UserRole + 4 - max
                    //UserRole + 5 - decimals
        SpinBox,
        LineEdit,
                    //UserRole + 5 - Validator
                    //UserRole + 6 - EcoMode
        ComboBox,
                    //UserRole + 2 - Qstringlist elements
                    //edit role = index
                    //dysplayrole = currenttext
        Checkbox,
        LatEdit,
        LongEdit,
        TimeEdit,
        DateEdit,
        DateTimeEdit,
        AltitEdit,
        RadioButton,
        Button,   //UserRole + 2 QstringList Active prop
        DeleteButton,
        DragButton,
        // Switch
    };
    Q_ENUM(ColumnType)

    TableDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    /**
     * @brief Добавляет в путь закругленный прямоугольник с настраиваемыми радиусами углов
     * 
     * Метод создает путь для отрисовки прямоугольника с закругленными углами, где радиусы углов задаются отдельно для осей X и Y.
     * Закругление применяется либо к левой, либо к правой стороне прямоугольника в зависимости от параметра leftOrRightSide.
     * Радиусы могут интерпретироваться в абсолютных или относительных единицах в зависимости от режима.
     * 
     * @param [out] path Путь QPainterPath, в который добавляется закругленный прямоугольник
     * @param rect Геометрия прямоугольника (QRectF)
     * @param xRadius Радиус закругления по оси X (в пикселях или процентах в зависимости от mode)
     * @param yRadius Радиус закругления по оси Y (в пикселях или процентах в зависимости от mode)
     * @param leftOrRightSide Флаг, определяющий сторону закругления: true для левой стороны, false для правой
     * @param mode Режим интерпретации радиусов: Qt::AbsoluteSize (пиксели) или Qt::RelativeToBoundingRect (проценты)
     */
    static void addCustomRoundedRect(QPainterPath &path, const QRectF &rect, qreal xRadius, qreal yRadius, bool leftOrRightSide, Qt::SizeMode mode = Qt::AbsoluteSize);
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    /**
     * @brief Отключает отображение границы для указанного столбца
     * 
     * @param col Индекс столбца
     */
    void offColumnBorger(int col);

    /**
     * @brief Отключает отображение границ для набора столбцов
     * 
     * @param col Набор индексов столбцов
     */
    void offColumnBorger(QSet<int> col);

    /**
     * @brief Удаляет столбец из списка столбцов с отключенными границами
     * 
     * @param col Индекс столбца
     */
    void removeColumnOffBorger(int col);
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    bool editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index) override;
    /**
     * @brief Устанавливает отступ текста в ячейках
     * 
     * @param marg Величина отступа текста (в пикселях)
     */
    void setMarginText(int marg);
    /**
     * @brief Отрисовывает пользовательский флажок
     * 
     * @param painter Указатель на объект QPainter для отрисовки
     * @param rect Геометрия области флажка
     * @param checked Состояние флажка (включен/выключен)
     * @param color Цвет флажка
     */
    static void drawCustomCheckBox(QPainter *painter, const QRect &rect, bool checked, const QColor &color);
    /**
     * @brief Отрисовывает пользовательскую радиокнопку
     * 
     * @param painter Указатель на объект QPainter для отрисовки
     * @param rect Геометрия области радиокнопки
     * @param checked Состояние радиокнопки (включена/выключена)
     * @param color Цвет радиокнопки
     */
    static void drawCustomRadioButton(QPainter *painter, const QRect &rect, bool checked, const QColor &color);
    /**
     * @brief Получает цвет границы ячейки
     * 
     * @param enabled Активно ли состояние виджета
     * @param widget Указатель на виджет для импорта цвета с property
     * @return QColor Цвет границы
     */
    static QColor getBorderColor(bool enabled ,const QWidget* widget);
    /**
     * @brief Получает геометрию элемента ячейки
     * 
     * @param rectCell Геометрия всей ячейки
     * @param index Индекс модели данных ячейки
     * @return QRect Геометрия элемента внутри ячейки
     */
    static QRect getRectElementCell(QRect rectCell, const QModelIndex &index);
signals:
    /**
     * @brief Сигнал нажатия кнопки в ячейке
     * 
     * @param index Индекс модели данных ячейки
     */
    void buttonClicked(const QModelIndex &index) const ;
    /**
     * @brief Сигнал нажатия кнопки удаления в ячейке
     * 
     * @param index Индекс модели данных ячейки
     */
    void deleteButtonCicked(const QModelIndex &index) const ;
private:
    void initializePainter(QPainter* painter, QStyleOptionViewItem& opt) const ;
    /**
     * @brief Создает путь для отрисовки ячейки
     * 
     * @param rectCell Геометрия ячейки
     * @param index Индекс модели данных ячейки
     * @param [out] path Путь QPainterPath для отрисовки
     */
    void createPathCell(QRect rectCell, const QModelIndex &index, QPainterPath &path ) const;
    
private:
   

    int textmargin = 20;
    QMap<int, QSize> sizeColumn;
    QSet<int> colOffBorder;
};

/**
 * @brief Перечисление типов соединений для обработки событий редактирования
 */
enum ConnectionType {
    editingFinished, ///< Событие завершения редактирования
    valueChanged     ///< Событие изменения значения
};

//UserRole + 1 - тип ячейки
//UserRole + 2 - какие-то доп данные
//EditRole - данные ячейки
//DisplayRole - то что покажем
class TableWidgetsDelegate :public TableDelegate{
    Q_OBJECT
public:
    
    explicit TableWidgetsDelegate(QObject *parent = nullptr, ConnectionType _typeConnect = ConnectionType::valueChanged);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    // void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    // void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
private:    
    ConnectionType typeConnect = ConnectionType::valueChanged;
};

