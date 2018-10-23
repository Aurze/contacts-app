import QtQuick 2.11
import QtQuick.Controls 2.4

import Person 1.0

Page {
    width: 600
    height: 400

    title: qsTr("Home")

    ScrollView {
        anchors.fill: parent

        ListView {
            Loader { id: pageLoader }
            model: PersonListModel {
                list: personList
            }
            width: parent.width
            delegate: ItemDelegate {
                text: { model.last_name + ", " + model.first_name }
                width: parent.width
                onClicked: stackView.push("PersonDetailView.qml")

            }
        }
    }
}
