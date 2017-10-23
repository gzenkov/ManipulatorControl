#include "linktablemodel.h"

linkTableModel::linkTableModel(Manipulator *inp, QObject *parent)
    : QAbstractTableModel(parent),
      man(inp)
{}

int linkTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return man->links.size();
}

int linkTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 4;
}

QVariant linkTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        switch (section)
        {
        case 0:
            return QString("d");
            break;
        case 1:
            return QString("a");
            break;
        case 2:
            return QString("q");
            break;
        case 3:
            return QString("alfa");
            break;
        }
    else
        return QString("Звено %1").arg(section+1);
}

QVariant linkTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= man->links.size() || index.row() < 0)
        return QVariant();
    if (index.column() >= 4 || index.column() < 0)
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        Link temp = man->links.at(index.row());
        if (temp.genCoorIndex != index.column())
            return temp.param[index.column()];
        else
            return headerData(index.column(), Qt::Horizontal).toString() += QString("%1").arg(index.row()+1);
    }

    return QVariant();
}

bool linkTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Link *temp = &man->links[index.row()];

    if (index.isValid() && role == Qt::EditRole)
    {
        if (value.type() == QMetaType::Double)
        {
            if(temp->genCoorIndex == index.column())
                temp->deleteGenCoor();

            temp->setCoor(value.toDouble(),index.column());
        }
        else
            temp->setGenCoor(index.column());
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags linkTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool linkTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    int i = 0;
    while (i<count)
    {
        temp = new Link();
        man->links.append(*temp);//(row + i, temp);
        i++;
    }
    endInsertRows();

    emit linksUpdated();
}

bool linkTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    int i = 0;
    while (i<count)
    {
        man->links.removeAt(row + i);
        i++;
    }
    endRemoveRows();

    emit linksUpdated();
}
