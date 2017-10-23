#ifndef LINKTABLEMODEL_H
#define LINKTABLEMODEL_H

#include <QAbstractTableModel>
#include "manipulator.h"

class linkTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit linkTableModel(Manipulator *inp, QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    Manipulator *man;

    Link *temp;

signals:
    void linksUpdated();
};

#endif // LINKTABLEMODEL_H
