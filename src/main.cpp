#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main()
{

    Mat image = imread("C:\\Users\\stasi\\Documents\\koding\\c++\\ImgToAsci\\src\\image.png", IMREAD_GRAYSCALE);

    if (image.empty())
    {
        cout << "Image File "<< "Not Found" << endl;
        cin.get();
        return -1;
    }

    imshow("Window Name", image);

    waitKey(0);

    return 0;
}