#include "personmodel.h"

#include "personlist.h"

PersonListModel::PersonListModel(QObject *parent)
	: QAbstractListModel(parent)
	, mList(nullptr)
{
}

int PersonListModel::rowCount(const QModelIndex &parent) const
{
	// For list models only the root node (an invalid parent) should return the list's size. For all
	// other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
	if (parent.isValid() || !mList)
		return 0;

	return mList->items().size();
}

QVariant PersonListModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid() || !mList)
		return QVariant();

	const Person item = mList->items().at(index.row());
	switch (role) {
		case FirstNameRole:
			return QVariant(item.first_name);
		case LastNameRole:
			return QVariant(item.last_name);
	}

	return QVariant();
}

bool PersonListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!mList)
		return false;

	Person item = mList->items().at(index.row());
	switch (role) {
		case FirstNameRole:
			item.first_name = value.toString();
			break;
		case LastNameRole:
			item.last_name = value.toString();
			break;
	}

	if (mList->setItemAt(index.row(), item)) {
		emit dataChanged(index, index, QVector<int>() << role);
		return true;
	}
	return false;
}

Qt::ItemFlags PersonListModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;

	return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PersonListModel::roleNames() const
{
	QHash<int, QByteArray> names;
	names[FirstNameRole] = "first_name";
	names[LastNameRole] = "last_name";
	return names;
}

PersonList *PersonListModel::list() const
{
	return mList;
}

void PersonListModel::setList(PersonList *list)
{
	beginResetModel();

	if (mList)
		mList->disconnect(this);

	mList = list;

	if (mList) {
		connect(mList, &PersonList::preItemAppended, this, [=]() {
			const int index = mList->items().size();
			beginInsertRows(QModelIndex(), index, index);
		});
		connect(mList, &PersonList::postItemAppended, this, [=]() {
			endInsertRows();
		});

		connect(mList, &PersonList::preItemRemoved, this, [=](int index) {
			beginRemoveRows(QModelIndex(), index, index);
		});
		connect(mList, &PersonList::postItemRemoved, this, [=]() {
			endRemoveRows();
		});
	}

	endResetModel();
}
