#include "lineeditdelegate.h"

LineEditDelegate::LineEditDelegate(QObject *parent) : QStyledItemDelegate(parent)
{}

QWidget *LineEditDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QLineEdit *editor = new QLineEdit(parent);
    editor->setFrame(false);

    QRegExp rx("(q|-?\\d*.?\\d*)");
    QValidator *validator = new QRegExpValidator(rx, editor);
    editor->setValidator(validator);

    return editor;
}

void LineEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);

    QVariant temp = index.model()->data(index, Qt::EditRole);
    if (temp.type() == QMetaType::Double)
        line->setText(QString::number(temp.toDouble(),'g',4));
    else
        line->setText(temp.toString());
}

void LineEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    QLineEdit *line = static_cast<QLineEdit*>(editor);

    bool ok;
    double d;
    d = line->text().toDouble(&ok);

    if (ok)
        model->setData(index, d, Qt::EditRole);
    else
        model->setData(index, line->text(), Qt::EditRole);
}

void LineEditDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}
