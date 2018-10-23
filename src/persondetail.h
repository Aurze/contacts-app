#ifndef PERSONDETAIL_H
#define PERSONDETAIL_H

#include <QObject>
#include <QString>

class PersonDetail : public QObject
{
	Q_OBJECT
public:
	explicit PersonDetail(QObject *parent = nullptr);

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
