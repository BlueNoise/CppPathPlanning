#include <iostream>

#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    // Create a blank image (300x300) with 3 channels (BGR) and initialize to black
    cv::Mat image = cv::Mat::zeros(300, 300, CV_8UC3);

    // Draw a circle in the middle of the image
    cv::circle(image, cv::Point(150, 150), 50, cv::Scalar(0, 255, 0), -1);

    // Draw a rectangle in the image
    cv::rectangle(image, cv::Point(50, 50), cv::Point(250, 250), cv::Scalar(255, 0, 0), 3);

    // Draw a line across the image
    cv::line(image, cv::Point(0, 0), cv::Point(300, 300), cv::Scalar(0, 0, 255), 2);

    // Put some text in the image
    cv::putText(image, "OpenCV Test", cv::Point(70, 280), cv::FONT_HERSHEY_SIMPLEX, 0.8, cv::Scalar(255, 255, 255), 2);

    // Display the image in a window
    cv::imshow("OpenCV installation test", image);

    // Wait for a keystroke in the window
    cv::waitKey(0);

    // Save the image to a file
    cv::imwrite("generated_test_image.jpg", image);

    std::cout << "Image generated and displayed successfully" << std::endl;

    return 0;
}