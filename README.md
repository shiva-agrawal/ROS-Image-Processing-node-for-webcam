# ROS Image Processing node development using webcam, OpenCV 3 and C++

Perception is the very first step for the development of any Robot or robotic system. Among various sensors, cameras (mono/stereo) have played a vital role and hence this project is aim to develop the image processing node which can take the images from camera, process them as per requirement of the application and then publish the processed image data as ROS topic.

For ROS, the driver which can aquire images from camera are already available. I have used usb_cam for this project. Hence the node developed in this project do the following work

 1. Subscribes the camera image from usb_cam node using image_transport subscriber
 2. Convert the ROS Image message into CV image using cv_bridge
 2. Do image processing. (here I have just increase the brightness for demo purpose)
 3. Convert back the processed CV image into ROS image message
 4. Assign the ROS msg to image_tranport publisher
 5. Publish the processed image to  topic /processedImage/image (topic defined by me)

For the project, ROS node is developed using C++ and openCV 3 in Ubuntu 16.04. I have used ROS Kinetic for the project.

## Project Folder structure

1. docs 
    * Project details.pdf - detailed project report covering hardware and software description
    
2. src
    * image_processing_with_opencv_and_ros - ROS package containing files of the project
    
3. test
    * image processing node.png - screenshot of terminal showing how to start the Node developed in this project
    * usb_cam.png - screenshot of terminal showing how to run usb_cam node to acquire camera images
    * rostopic list.png - screenshot of terminal displaying all the rostopics available during the project run
    * raw image and processed image.png - raw and processed images

