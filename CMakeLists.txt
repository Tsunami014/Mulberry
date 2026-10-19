cmake_minimum_required(VERSION 3.22)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(APP_NAME Mulberry)

set(CORE
    main.cpp  app.cpp
)


project(${APP_NAME} LANGUAGES CXX)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_add_executable(${APP_NAME} ${CORE})
target_link_libraries(${APP_NAME} PRIVATE Qt6::Core Qt6::Widgets)

target_include_directories(${APP_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

set_property(TARGET ${APP_NAME} PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
set_property(TARGET ${APP_NAME} PROPERTY QT_ANDROID_TARGET_SDK_VERSION 29)

option(ENABLE_DEBUG "Enable extra debug mode features" OFF)
if(ENABLE_DEBUG)
    target_compile_definitions(${APP_NAME} PRIVATE APP_DEBUG)
endif()
