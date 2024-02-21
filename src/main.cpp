#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{

    if(argc != 2) {
        cout << "pute file name in arguments";
        return -1;
    }

    std::string fileName = argv[1];

    vector<string> characters = {"@", "#", "S", "%", "?", "*", "+", ";", ":", ",", "."};

    Mat image = imread(fileName, IMREAD_GRAYSCALE);  

    if (image.empty())
    {
        cout << "Image File "<< "Not Found" << endl;
        cin.get();
        return -1;
    }

    //conversion
    vector<vector<string>> imageArray;
    for (int i = 0; i < image.rows; i += 2) {
        vector<string> row;
        for (int j = 0; j < image.cols; ++j) {
            int pixelValue = round((static_cast<int>(image.at<uchar>(i, j)) + static_cast<int>(image.at<uchar>(i+1, j)))/2);
            row.push_back(pixelValue < 0 ? "F" : characters[pixelValue / 24]);
        }
        imageArray.push_back(row);
    }

    //open file
    ofstream MyFile("output.txt");
    
    //clear file
    std::ofstream ofs;
    ofs.open("test.txt", std::ofstream::out | std::ofstream::trunc);

    //write to file
    for (const auto& row : imageArray) {
        for (string pixel : row) {
            MyFile << pixel;
        }
        MyFile << "\n";
    }

    MyFile.close();

    //open file
    system( "notepad.exe output.txt" );

    waitKey(0);
    return 0;
}