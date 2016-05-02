set(PROJECT_NAME_STR VideoplayerProject)
project(${PROJECT_NAME_STR} C CXX)
cmake_minimum_required(VERSION 3.3)

set(SETTINGS_APP_NAME "videoplayer_settings" )
set(APP_NAME "videoplayer" )


configure_file(lib/include/cmake_conf.h.in ${CMAKE_BINARY_DIR}/generated/cmake_conf.h)
include_directories( ${CMAKE_BINARY_DIR}/generated/ )


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 ")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")



MESSAGE("PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR}")
MESSAGE("PROJECT_BINARY_DIR:${PROJECT_BINARY_DIR}")

if(WIN32)
    if(MSVC)
        set(Boost_USE_STATIC_LIBS ON)
        set(Boost_USE_MULTITHREADED ON)
        SET (BOOST_ROOT "C:/Src/cpp/boost/boost_1_59_0-win-vs")
        SET (BOOST_INCLUDEDIR "C:/Src/cpp/boost/boost_1_59_0-win-vs/boost")
        SET (BOOST_LIBRARYDIR "C:/Src/cpp/boost/boost_1_59_0-win-vs/stage/lib")
    else()
        SET (BOOST_ROOT "C:/Src/cpp/boost/boost_1_59_0-tdm-mingw")
        SET (BOOST_INCLUDEDIR "C:/Src/cpp/boost/boost_1_59_0-tdm-mingw/boost")
        SET (BOOST_LIBRARYDIR "C:/Src/cpp/boost/boost_1_59_0-tdm-mingw/stage/lib")
    endif()
else()
    SET (BOOST_ROOT "/home/tiit/Src/cpp/boost/boost_1_59_0-linux")
    SET (BOOST_INCLUDEDIR "/home/tiit/Src/cpp/boost/boost_1_59_0-linux/boost")
    SET (BOOST_LIBRARYDIR "/home/tiit/Src/cpp/boost/boost_1_59_0-linux/stage/lib")
endif()

SET (BOOST_MIN_VERSION "1.59.0")
set (Boost_NO_BOOST_CMAKE ON)
FIND_PACKAGE(Boost ${BOOST_MIN_VERSION} COMPONENTS regex system filesystem REQUIRED)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Fatal error: Boost (version >= 1.59) required.")
else()
    message(STATUS "Setting up BOOST")
    message(STATUS " Includes - ${Boost_INCLUDE_DIRS}")
    message(STATUS " Library  - ${Boost_LIBRARY_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif (NOT Boost_FOUND)


#wxWidgets
set(wxWidgets_USE_REL_AND_DBG ON)
if(MSVC)
    if(${CMAKE_BUILD_TYPE} MATCHES "Release")
        set(wxWidgets_CONFIGURATION mswu)
    elseif(${CMAKE_BUILD_TYPE} MATCHES "Debug")
        set(wxWidgets_CONFIGURATION mswud)
    endif()
else()
    set(wxWidgets_ROOT_DIR "C:/git-wx-3.0")
endif()

ADD_DEFINITIONS("-D_UNICODE")
message(STATUS "wxWidgets_CONFIGURATION: ${wxWidgets_CONFIGURATION}")
message(STATUS "wxWidgets_ROOT_DIR: ${wxWidgets_ROOT_DIR}")

find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
MESSAGE(WARNING "wxWidgets_USE_FILE:${wxWidgets_USE_FILE}")

if(WIN32)
    set(GTEST_ROOT "C:/Src/cpp/googletest-release-1.7.0")
    if(MSVC)
        set(GTEST_LIBRARY_DIRS "${GTEST_ROOT}/msvc/gtest-md/Release")
    else()
        set(GTEST_LIBRARY_DIRS "${GTEST_ROOT}/tdm-mingw-build")
    endif()
    set(RAPIDJSON_INCLUDE_DIRS "C:/Src/cpp/rapidjson-1.0.2/include")
else()
    set(GTEST_ROOT "/home/tiit/Src/cpp/googletest-release-1.7.0")
    set(GTEST_LIBRARY_DIRS "${GTEST_ROOT}/linux-build")
    set(RAPIDJSON_INCLUDE_DIRS "/home/tiit/Src/cpp/rapidjson-1.0.2/include")
endif()
set(GTEST_INCLUDE_DIRS "${GTEST_ROOT}/include")



#lib
set(LIB_INCLUDE ${PROJECT_SOURCE_DIR}/lib/include)
include_directories(${LIB_INCLUDE})
set(PROJECT_LIB_NAME ${PROJECT_NAME_STR}_impl)
file(GLOB LIB_SRC_FILES ${PROJECT_SOURCE_DIR}/lib/src/*.cpp ${LIB_INCLUDE}/*.h)
add_library(${PROJECT_LIB_NAME} ${LIB_SRC_FILES})


include_directories(${GTEST_INCLUDE_DIRS} "${GTEST_ROOT}")
add_library(gtest ${GTEST_ROOT}/src/gtest.cc)
add_library(gtest_main ${GTEST_ROOT}/src/gtest_main.cc)
#target_link_libraries(gtest_main gtest)

#settings executable
set(SETTINGS_EXECUTABLE_SRC_DIR "${PROJECT_SOURCE_DIR}/settings")
file(GLOB SETTINGS_EXECUTABLE_SRC_FILES ${SETTINGS_EXECUTABLE_SRC_DIR}/*.cpp)
file(GLOB SETTINGS_EXECUTABLE_HEADER_FILES ${SETTINGS_EXECUTABLE_SRC_DIR}/*.h)
add_executable(${SETTINGS_APP_NAME} WIN32 ${SETTINGS_EXECUTABLE_SRC_FILES} ${SETTINGS_EXECUTABLE_HEADER_FILES} )

if(WIN32)
    if(MSVC)
        target_link_libraries(${SETTINGS_APP_NAME}  ${wxWidgets_LIBRARIES}  ${PROJECT_LIB_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
    else()
        target_link_libraries(${SETTINGS_APP_NAME}  ${wxWidgets_LIBRARIES}  ${PROJECT_LIB_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}  ws2_32 )
    endif()
else()
    target_link_libraries(${SETTINGS_APP_NAME}  ${wxWidgets_LIBRARIES}  ${PROJECT_LIB_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}  )
endif()


#executable
set(EXECUTABLE_SRC_DIR "${PROJECT_SOURCE_DIR}/executable")
file(GLOB EXECUTABLE_SRC_FILES ${EXECUTABLE_SRC_DIR}/*.cpp)
file(GLOB EXECUTABLE_HEADER_FILES ${EXECUTABLE_SRC_DIR}/*.h)
add_executable(${APP_NAME} WIN32 ${EXECUTABLE_SRC_FILES} ${EXECUTABLE_HEADER_FILES} )
if(WIN32)
    if(MSVC)
        target_link_libraries(${APP_NAME} ${wxWidgets_LIBRARIES}  ${PROJECT_LIB_NAME} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY} )
    else()
        target_link_libraries(${APP_NAME} ${wxWidgets_LIBRARIES} ${PROJECT_LIB_NAME}  ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}  ws2_32 )
    endif()
else()
    target_link_libraries(${APP_NAME} ${wxWidgets_LIBRARIES} ${PROJECT_LIB_NAME}  ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}  )
endif()





#google test
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test )
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${EXECUTABLE_HEADER_FILES})
if(WIN32)
    if(MSVC)
        target_link_libraries(${PROJECT_TEST_NAME}  ${PROJECT_LIB_NAME} "${GTEST_LIBRARY_DIRS}/gtest.lib" "${GTEST_LIBRARY_DIRS}/gtest_main-md.lib" ${wxWidgets_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY})
    else()
        target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_LIB_NAME} "${GTEST_LIBRARY_DIRS}/libgtest.a" "${GTEST_LIBRARY_DIRS}/libgtest_main.a" ${wxWidgets_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}  ws2_32 )
    endif()
else()
    target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_LIB_NAME} "${GTEST_LIBRARY_DIRS}/libgtest.a" "${GTEST_LIBRARY_DIRS}/libgtest_main.a" ${wxWidgets_LIBRARIES} ${Boost_FILESYSTEM_LIBRARY} ${Boost_SYSTEM_LIBRARY}  )
endif()

include_directories(${GTEST_INCLUDE_DIRS} ${RAPIDJSON_INCLUDE_DIRS})


SET(BUILD_SHARED_LIBRARIES OFF)
#SET(CMAKE_EXE_LINKER_FLAGS "-static")


set_property(TARGET ${PROJECT_TEST_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_TEST_NAME} PROPERTY CXX_STANDARD 14)

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 14)

set_property(TARGET ${SETTINGS_APP_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${SETTINGS_APP_NAME} PROPERTY CXX_STANDARD 14)

set_property(TARGET ${PROJECT_LIB_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_LIB_NAME} PROPERTY CXX_STANDARD 14)