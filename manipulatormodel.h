#ifndef MANIPULATORMODEL_H
#define MANIPULATORMODEL_H

#include <QAbstractTableModel>
#include "manipulator.h"

class ManipulatorModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ManipulatorModel(Manipulator *inp, QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

public slots:
    void resetModel();

private:
    Manipulator *man;
};

#endif // MANIPULATORMODEL_H
