/* 
 * Developer   : Shiva Agrawal
 * ver         : 1.0 
 * date        : 02.11.2018
 * description : ROS image processing node. Below are the steps of processing
 * 				 
 * 1. Subscribes the camera image from usb_cam node using image_transport subscriber
 * 2. Convert the ROS Image message into CV image using cv_bridge
 * 3. Do image processing. (here I have just increase the brightness for demo purpose)
 * 4. Convert back the processed CV image into ROS image message
 * 5. Assign the ROS msg to image_tranport publisher
 * 6. Publish the processed image to  topic /processedImage/image
 */

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

// image_transport publisher and subsribers
// subscriber: to read the camera image from usb_cam/image_raw topic
//publisher: to publish the processed image to ROS master
image_transport::Subscriber image_sub; 
image_transport::Publisher image_pub;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
   try
   {
     // make a pointer for cv_bridge
     cv_bridge::CvImagePtr cv_ptr;
     
     // convert the ROS msg into CV image using cv_bridge pointer
     // Note that the cv_ptr->image contains the actual cv::mat type image
     cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
     
     // image processing (changing brightness)
     cv_ptr->image = cv_ptr->image + cv::Scalar(50,50,50); 
         
     //display the image 
     cv::imshow("view", cv_ptr->image);
     cv::waitKey(30);
     
     // convert the CV image to ROS message and assign to image_transport publisher 
     image_pub.publish(cv_ptr->toImageMsg());
   }
   catch (cv_bridge::Exception& e)
   {
     ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
   }
 }
 
int main(int argc, char **argv)
{
   // initializa the ROS for the given node name
   ros::init(argc, argv, "cameraImageAquisitionAndProcessingNode");
   
   // create ROS node handle
   ros::NodeHandle nh;
   
   // Image window
   cv::namedWindow("view");
   
   cv::startWindowThread();
   
   // object of type ImageTransport class and pass ROS node handle as parameter
   image_transport::ImageTransport it(nh);
   
   // image_transport subscribe to usb_cam image. Here it reads the image from usb_cam/image_raw node 
   // running in another terminal. It takes the video image data and then pass to imageCallback function.
   image_sub = it.subscribe("usb_cam/image_raw", 1, imageCallback);
   
   // publisher of type image_transport publish the processed image to topic /processedImage/image
   image_pub = it.advertise("/processedImage/image", 1);
   
   ros::spin();
   cv::destroyWindow("view");
 }
