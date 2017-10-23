#include "manipulatormodel.h"

ManipulatorModel::ManipulatorModel(Manipulator *inp, QObject *parent)
    : QAbstractTableModel(parent),
      man(inp)
{}

QVariant ManipulatorModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        switch (section)
        {
        case 0:
            return QString("Координата");
            break;
        case 1:
            return QString("Значение");
            break;
        }
    else
        return QString("Звено %1").arg(section+1);
}

int ManipulatorModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return man->links.size();
}

int ManipulatorModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 2;
}

QVariant ManipulatorModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= man->links.size() || index.row() < 0)
        return QVariant();
    if (index.column() >= 2 || index.column() < 0)
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        Link temp = man->links.at(index.row());
        if (index.column())
        {
            if (temp.genCoorIndex != -1)
                return temp.param[temp.genCoorIndex];
            else
                return QString("--");
        }
        else
        {
            if (temp.genCoorIndex != -1)
                switch (temp.genCoorIndex)
                {
                case (0):
                    return QString("d%1").arg(index.row()+1);
                    break;
                case (1):
                    return QString("a%1").arg(index.row()+1);
                    break;
                case (2):
                    return QString("q%1").arg(index.row()+1);
                    break;
                case (3):
                    return QString("alfa%1").arg(index.row()+1);
                    break;
                }
            else
                return QString("--");
        }
    }

    return QVariant();
}

bool ManipulatorModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Link *temp = &man->links[index.row()];

    if (index.isValid() && role == Qt::EditRole)
    {
        temp->set`Coor(value.toDouble(), temp->genCoorIndex);
        man->updateRecentPosition();

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ManipulatorModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void ManipulatorModel::resetModel()
{
    beginResetModel();
    endResetModel();
}
