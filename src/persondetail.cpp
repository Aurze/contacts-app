#include <algorithm>

#include "persondetail.h"
#include "personquery.h"

PersonDetail::PersonDetail(QObject *parent) : QObject(parent)
{

}

void PersonDetail::setFirstName(QString firstName)
{
	m_firstName = firstName;
	auto persons = PersonQuery().mPersons;
	Person* p = std::find_if(persons.begin(), persons.end(), [firstName](Person p) -> bool {return p.first_name == firstName;});

	setLastName(p->last_name);
	emit firstNameChanged(firstName);
}

void PersonDetail::setLastName(QString lastName)
{
	m_lastName = lastName;
	emit lastNameChanged(lastName);
}



