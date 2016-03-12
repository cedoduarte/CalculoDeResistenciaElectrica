#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_cantidadSpinBox_valueChanged(int arg1);
    void on_calcularPushButton_clicked();
    void on_quitarAplicacionPushButton_clicked();
    double getValueAt(int ix, int jx) const;
private:
    Ui::Widget *ui;
    QStandardItemModel *mModel;
};

#endif // WIDGET_H
