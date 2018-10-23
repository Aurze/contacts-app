#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>

class PersonList;

class PersonListModel : public QAbstractListModel
{
		Q_OBJECT
		Q_PROPERTY(PersonList *list READ list WRITE setList)

public:
		explicit PersonListModel(QObject *parent = nullptr);

		enum {
				FirstNameRole = Qt::UserRole,
				LastNameRole
		};

		// Basic functionality:
		int rowCount(const QModelIndex &parent = QModelIndex()) const override;

		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

		// Editable:
		bool setData(const QModelIndex &index, const QVariant &value,
								 int role = Qt::EditRole) override;

		Qt::ItemFlags flags(const QModelIndex& index) const override;

		virtual QHash<int, QByteArray> roleNames() const override;

		PersonList *list() const;
		void setList(PersonList *list);

private:
		PersonList *mList;
};

#endif // PERSONMODEL_H
