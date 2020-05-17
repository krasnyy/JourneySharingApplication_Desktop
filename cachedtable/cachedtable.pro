HEADERS       = ../connection.h \
                ../../../../../Users/Monster/Documents/JourneySharingApplication_Desktop/logger.h \
                tableeditor.h
SOURCES       = main.cpp \
                ../../../../../Users/Monster/Documents/JourneySharingApplication_Desktop/logger.cpp \
                tableeditor.cpp
QT           += sql widgets
requires(qtConfig(tableview))

# install
target.path = $$[QT_INSTALL_EXAMPLES]/sql/cachedtable
INSTALLS += target

