project(contacts-app)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
find_package(libcontacts REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp"
  "personmodel.h"
  "personmodel.cpp"
  "personlist.h"
  "personlist.cpp"
  "persondetail.h"
  "persondetail.cpp"
  "personquery.h"
  "qml.qrc")

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Quick
    libcontacts::libcontacts)
