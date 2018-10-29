#ifndef PERSONQUERY_H
#define PERSONQUERY_H

#include <QVector>
#include <QString>

#include <libcontacts/query.h>
#include <libcontacts/person.h>

#include "personlist.h"

class PersonQuery {
public:
	QVector<Person> mPersons;
	PersonQuery()
	{
		auto persons = pim::get_all();
		for (auto& p : persons){
			mPersons.append({QString::fromStdString(p.first_name), QString::fromStdString(p.last_name)});
		}

//		mPersons.append({ QStringLiteral("John"), QStringLiteral("Wick") });
//		mPersons.append({ QStringLiteral("Johnny"), QStringLiteral("Cash") });


	}

};

#endif // PERSONQUERY_H
