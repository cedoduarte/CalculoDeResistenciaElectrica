#include "DoubleSpinBoxItemDelegate.h"
#include <QDoubleSpinBox>

DoubleSpinBoxItemDelegate::DoubleSpinBoxItemDelegate(QObject *parent)
    : QItemDelegate(parent)
{ 
}

QWidget *DoubleSpinBoxItemDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &, const QModelIndex &) const
{
    auto spinner = new QDoubleSpinBox(parent);
    return spinner;
}

void DoubleSpinBoxItemDelegate::setEditorData(QWidget *editor,
    const QModelIndex &index) const
{
    auto spinner = static_cast<QDoubleSpinBox *>(editor);
    spinner->setValue(index.data().toDouble());
}

void DoubleSpinBoxItemDelegate::setModelData(QWidget *editor,
    QAbstractItemModel *model, const QModelIndex &index) const
{
    auto spinner = static_cast<QDoubleSpinBox *>(editor);
    model->setData(index, spinner->value());
}

void DoubleSpinBoxItemDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &) const
{
    editor->setGeometry(option.rect);
}
