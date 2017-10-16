#include "generalizedcoordinatemodel.h"

GeneralizedCoordinateModel::GeneralizedCoordinateModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant GeneralizedCoordinateModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int GeneralizedCoordinateModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int GeneralizedCoordinateModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant GeneralizedCoordinateModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
