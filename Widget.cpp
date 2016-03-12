#include "Widget.h"
#include "ui_Widget.h"
#include "DoubleSpinBoxItemDelegate.h"
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);

    ui->tableView->setModel(mModel);
    ui->tableView->setItemDelegate(new DoubleSpinBoxItemDelegate);
    ui->cantidadSpinBox->setMinimum(0);
    ui->cantidadSpinBox->setMaximum(INT_MAX);
    ui->serieRadioButton->setChecked(true);
    mModel->setHorizontalHeaderLabels({ "Valor" });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_cantidadSpinBox_valueChanged(int arg1)
{
    mModel->setRowCount(arg1);
}

void Widget::on_calcularPushButton_clicked()
{
    const int cantidad = ui->cantidadSpinBox->value();
    if (cantidad == 0) {
        return;
    }
    double total = 0.0;
    for (int ix = 0; ix < cantidad; ++ix) {
        const double valor = getValueAt(ix, 0);
        if (ui->serieRadioButton->isChecked()) {
            total += valor;
        } else {
            total += 1.0 / valor;
        }
    }
    // calcular ...
    if (ui->paraleloRadioButton->isChecked()) {
        total = 1.0 / total;
    }
    ui->resultadoLineEdit->setText(QString::number(total));
}

void Widget::on_quitarAplicacionPushButton_clicked()
{
    close();
}

double Widget::getValueAt(int ix, int jx) const
{
    auto itemPtr = mModel->item(ix, jx);
    if (itemPtr == nullptr) {
        return 0.0;
    }
    return itemPtr->text().toDouble();
}
