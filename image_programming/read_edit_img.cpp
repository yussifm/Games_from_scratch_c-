
#include <iostream>
#include <fstream>
// #include <ctime>
// #include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream image;
    ofstream newImage;
    image.open("image1.ppm");
    newImage.open("newImage1.ppm");

    // Copying information
    string type = "", width = "", height = "", RGB = "";
    image >> type;   // first read return the type (P3)
    image >> width;  // second read return the width
    image >> height; // third read return the height
    image >> RGB;

    newImage << type << endl;

    newImage << width << " " << height << endl;
    newImage << RGB << endl;

    string red = "", green = "", blue = "";
    int r = 0, g = 0, b = 0;

    // if not at the end of the file (eof)
    while (!image.eof())
    {
        image >> red;
        image >> green;
        image >> blue;

        stringstream redStream(red); // convert to int
        stringstream greenStream(green);
        stringstream blueStream(blue);

        r = redStream.get(); // get the int value
        g = greenStream.get();
        b = blueStream.get();

        // Adding filters
        if (g + 50 > 255)
        {
            g = 255;
        }
        else
        {
            g += 50;
        }
        newImage << r << " " << g << " " << b << endl;
    }
    image.close();    //
    newImage.close(); //

    return 0;
}