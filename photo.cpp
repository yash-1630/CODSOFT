/*IMAGE PROCESSING TOOL
 Build a tool that allows users to perform various image processing operations
 like resizing, cropping, and filtering.
 Load Image: Allow users to load an image.
 Display Image: Display the loaded image in the application.
 Image Filters: Implement basic image filters like grayscale, blur, and
 sharpen.
 Color Adjustment: Allow users to adjust image colors, brightness,
 and contrast.
 Crop and Resize: Provide options to crop and resize the image.
 Image Saving: Enable users to save the processed image.
 User Interface: Design a user-friendly interface for easy interaction
*/

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void displayImage(const Mat& image, const string& windowName) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, image);
}

Mat applyGrayscale(const Mat& image) {
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);
    return grayImage;
}

Mat applyBlur(const Mat& image) {
    Mat blurredImage;
    GaussianBlur(image, blurredImage, Size(15, 15), 0);
    return blurredImage;
}

Mat applySharpen(const Mat& image) {
    Mat sharpenedImage;
    Mat kernel = (Mat_<float>(3, 3) <<
        0, -1, 0,
        -1, 5, -1,
        0, -1, 0);
    filter2D(image, sharpenedImage, image.depth(), kernel);
    return sharpenedImage;
}

Mat adjustBrightnessContrast(const Mat& image, double alpha, int beta) {
    Mat newImage = Mat::zeros(image.size(), image.type());
    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < image.channels(); c++) {
                newImage.at<Vec3b>(y, x)[c] =
                    saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);
            }
        }
    }
    return newImage;
}

Mat cropImage(const Mat& image, Rect region) {
    return image(region);
}

Mat resizeImage(const Mat& image, Size size) {
    Mat resizedImage;
    resize(image, resizedImage, size);
    return resizedImage;
}

void saveImage(const Mat& image, const string& filename) {
    imwrite(filename, image);
}

int main() {
    string imagePath;
    cout << "Enter the path to the image: ";
    cin >> imagePath;

    Mat image = imread(imagePath);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    displayImage(image, "Original Image");

    Mat grayImage = applyGrayscale(image);
    displayImage(grayImage, "Grayscale Image");

    Mat blurredImage = applyBlur(image);
    displayImage(blurredImage, "Blurred Image");

    Mat sharpenedImage = applySharpen(image);
    displayImage(sharpenedImage, "Sharpened Image");

    Mat brightImage = adjustBrightnessContrast(image, 1.2, 30);
    displayImage(brightImage, "Brightened Image");

    Rect cropRegion(50, 50, 200, 200);
    Mat croppedImage = cropImage(image, cropRegion);
    displayImage(croppedImage, "Cropped Image");

    Size newSize(300, 300);
    Mat resizedImage = resizeImage(image, newSize);
    displayImage(resizedImage, "Resized Image");

    string savePath;
    cout << "Enter the path to save the processed image: ";
    cin >> savePath;
    saveImage(resizedImage, savePath);

    waitKey(0);
    return 0;
}
