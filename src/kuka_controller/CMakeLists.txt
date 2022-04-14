##############################################################################
# CMake
##############################################################################
cmake_minimum_required(VERSION 3.0.2)

#set name of this project
project(kuka_controller)
#add
set(CMAKE_INCLUDE_CURRENT_DIR ON)
##############################################################################
# Catkin
##############################################################################

# qt_build provides the qt cmake glue, roscpp the comms for a default talker
#add catkin package
find_package(catkin REQUIRED COMPONENTS 
	roscpp
	rospy
	std_msgs
	message_generation
)
include_directories(include ${catkin_INCLUDE_DIRS})



add_message_files(
   FILES
   ForceData.msg
   PositionData.msg
)
add_service_files(
   FILES
   KukaControl.srv
)
generate_messages(
  DEPENDENCIES
  std_msgs
)
# Use this to define what the package will export (e.g. libs, headers).
# Since the default here is to produce only a binary, we don't worry about
# exporting anything. 
catkin_package(
   CATKIN_DEPENDS message_runtime
)




#add Qt5 package
find_package(Qt5 REQUIRED Core Widgets Network Charts SerialPort)
#set Qt5 libraries
set(QT_LIBRARIES Qt5::Widgets Qt5::Network Qt5::Charts Qt5::SerialPort)

#set OpenCV
find_package(OpenCV REQUIRED)

##############################################################################
# Qt Environment
##############################################################################

# this comes from qt_build's qt-ros.cmake which is automatically 
# included via the dependency call in package.xml
#remove
#rosbuild_prepare_qt4(QtCore QtGui) # Add the appropriate components to the component list here

##############################################################################
# Sections
##############################################################################

file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/kuka_controller/*.hpp *.h)

#change
QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

##############################################################################
# Sources
##############################################################################

file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

##############################################################################
# Binaries
##############################################################################

add_executable(kuka_controller ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP} )

target_link_libraries(kuka_controller ${QT_LIBRARIES} ${catkin_LIBRARIES})
target_link_libraries(kuka_controller ${OpenCV_LIBS})

#include_directories(${MVCAM_SDK_PATH}/include)
#link_directories(${MVCAM_SDK_PATH}/bin /
#    ${MVCAM_COMMON_RUNENV}/64)       # 指定海康sdk的lib目录
#test

target_link_libraries(kuka_controller MvCameraControl)


install(TARGETS kuka_controller RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

