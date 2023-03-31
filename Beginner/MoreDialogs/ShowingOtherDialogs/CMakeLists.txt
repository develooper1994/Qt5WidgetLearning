cmake_minimum_required(VERSION 3.5)

project(ShowingOtherDialogs VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOUIC_SEARCH_PATHS "${PROJECT_SOURCE_DIR}/ui")


set(PROJECT_CPP     main.cpp
                    source/dialog.cpp source/dialog2.cpp)
set(PROJECT_HEADER  header/dialog.h   header/dialog2.h)
set(PROJECT_UI      ui/dialog.ui
                    ui/dialog2.ui
                         )
set(PROJECT_SOURCES
        ${PROJECT_CPP}
        ${PROJECT_HEADER}
        ${PROJECT_UI}
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ShowingOtherDialogs
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ShowingOtherDialogs APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ShowingOtherDialogs SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ShowingOtherDialogs
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ShowingOtherDialogs PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(ShowingOtherDialogs PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ShowingOtherDialogs
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ShowingOtherDialogs)
endif()
