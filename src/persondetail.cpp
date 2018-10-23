#include "persondetail.h"

PersonDetail::PersonDetail(QObject *parent) : QObject(parent)
{

}

void PersonDetail::setFirstName(QString firstName)
{
	m_firstName = firstName;
}

void PersonDetail::setLastName(QString lastName)
{
	m_lastName = lastName;
}
