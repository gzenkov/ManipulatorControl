#ifndef LINEEEDITDELEGATE_H
#define LINEEEDITDELEGATE_H

#include <QStyledItemDelegate>
#include <QLineEdit>

class LineEditDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit LineEditDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // LINEEEDITDELEGATE_H
