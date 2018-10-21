import QtQuick 2.11
import QtQuick.Controls 2.4

Page {
    width: 600
    height: 400

    title: qsTr("Home")

    ScrollView {
        anchors.fill: parent

        ListView {
            Loader { id: pageLoader }
            width: parent.width
            model: 20
            delegate: ItemDelegate {
                text: "Nom, Prenom - " + (index + 1)
                width: parent.width
                onClicked: stackView.push("PersonDetailView.qml")

            }
        }
    }
}
