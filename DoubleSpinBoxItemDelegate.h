#ifndef DOUBLESPINBOXITEMDELEGATE_H
#define DOUBLESPINBOXITEMDELEGATE_H

#include <QItemDelegate>

class DoubleSpinBoxItemDelegate : public QItemDelegate
{
public:
    DoubleSpinBoxItemDelegate(QObject *parent = nullptr);
protected:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &,
                          const QModelIndex &) const override;
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor,
                              const QStyleOptionViewItem &option,
                              const QModelIndex &) const override;
};

#endif // DOUBLESPINBOXITEMDELEGATE_H
