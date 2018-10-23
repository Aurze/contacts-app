#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "personlist.h"
#include "personmodel.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	qmlRegisterType<PersonListModel>("Person", 1, 0, "PersonListModel");
	qmlRegisterUncreatableType<PersonList>("Person", 1, 0, "PersonList",
																				 QStringLiteral("PersonList should not be created in QML"));
	qmlRegisterType<PersonList>("Person", 1, 0, "PersonDetail");

	PersonList personList;

	QQmlApplicationEngine engine;
	engine.rootContext()->setContextProperty(QStringLiteral("personList"), &personList);
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
