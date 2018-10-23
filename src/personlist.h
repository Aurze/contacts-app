#ifndef PERSONLIST_H
#define PERSONLIST_H

#include <QObject>
#include <QString>
#include <QVector>

struct Person {
	QString first_name;
	QString last_name;
};


class PersonList : public QObject
{
	Q_OBJECT
public:
	explicit PersonList(QObject *parent = nullptr);

	QVector<Person> items() const;

	bool setItemAt(int index, const Person &item);

signals:
	void preItemAppended();
	void postItemAppended();

	void preItemRemoved(int index);
	void postItemRemoved();

public slots:
	void appendItem();

private:
	QVector<Person> mPersons;

};

#endif // PERSONLIST_H
