import QtQuick 2.11
import QtQuick.Controls 2.4

import Person 1.0

Page {
    width: 600
    height: 400

    property string first_name: "first_name"
    property string last_name: "last_name"
    title: qsTr("Page 1")

    TextField {
        id: txtFirst
        x: 166
        y: 134
        text: first_name
    }

    Text {
        id: lblFirst
        x: 81
        y: 146
        text: qsTr("First")
        font.pixelSize: 12
    }

    TextField {
        id: txtLast
        x: 166
        y: 208
        text: last_name
    }

    Text {
        id: lblLast
        x: 81
        y: 220
        text: qsTr("Last")
        font.pixelSize: 12
    }
}
