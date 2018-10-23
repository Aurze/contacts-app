#include "personlist.h"

extern QVector<Person> mPersons;

PersonList::PersonList(QObject *parent) : QObject(parent)
{
		mPersons.append({ QStringLiteral("John"), QStringLiteral("Wick") });
		mPersons.append({ QStringLiteral("Johnny"), QStringLiteral("Cash") });
}

QVector<Person> PersonList::items() const
{
		return mPersons;
}

bool PersonList::setItemAt(int index, const Person &item)
{
		if (index < 0 || index >= mPersons.size())
				return false;

		const Person &oldItem = mPersons.at(index);
		if (item.first_name == oldItem.first_name && item.last_name == oldItem.last_name)
				return false;

		mPersons[index] = item;
		return true;
}

void PersonList::appendItem()
{
		emit preItemAppended();

		Person item;
		item.first_name = false;
		mPersons.append(item);

		emit postItemAppended();
}
