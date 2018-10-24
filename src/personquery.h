#ifndef PERSONQUERY_H
#define PERSONQUERY_H

#include <QVector>
#include <QString>

#include "personlist.h"

class PersonQuery {
public:
	QVector<Person> mPersons;
	PersonQuery()
	{
		mPersons.append({ QStringLiteral("John"), QStringLiteral("Wick") });
		mPersons.append({ QStringLiteral("Johnny"), QStringLiteral("Cash") });
	}

};

#endif // PERSONQUERY_H
