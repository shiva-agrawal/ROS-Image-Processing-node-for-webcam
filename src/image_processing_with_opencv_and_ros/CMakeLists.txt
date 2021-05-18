cmake_minimum_required(VERSION 2.8.3)
project(image_processing_with_opencv_and_ros)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)
find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES image_processing_with_opencv_and_ros
#  CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
#  DEPENDS system_lib
)
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(cameraImageAquisitionAndProcessingNode src/cameraImageAquisitionAndProcessingNode.cpp)
target_link_libraries(cameraImageAquisitionAndProcessingNode ${catkin_LIBRARIES}  ${OpenCV_LIBRARIES})
