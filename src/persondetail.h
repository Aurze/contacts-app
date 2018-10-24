#ifndef PERSONDETAIL_H
#define PERSONDETAIL_H

#include <QObject>
#include <QString>
#include <QVariant>

#include "personlist.h"

class PersonDetail : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged)
	Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged)

public:
	explicit PersonDetail(QObject *parent = nullptr);
	PersonDetail(const Person& p) :
		m_firstName(p.first_name),
		m_lastName(p.last_name){

	}
	enum {
		FirstNameRole = Qt::UserRole,
		LastNameRole
	};
	QString firstName() const { return m_firstName; }
	QString lastName() const { return m_lastName; }


public slots:
	void setFirstName(QString firstName);
	void setLastName(QString lastName);

signals:
	void firstNameChanged(QString newFirstName);
	void lastNameChanged(QString newLastName);

private:
	QString m_firstName;
	QString m_lastName;
};

#endif // PERSONDETAIL_H
