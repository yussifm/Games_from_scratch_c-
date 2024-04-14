
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    srand(time(0));
    ifstream image;
    ofstream newImage;
    image.open("out.ppm");
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
        if (g + 10 > 255)
        {
            g = 255;
        }
        else
        {
            g += 10;
        }

        // red
        if (r + 10 > 255)
        {
            r = 255;
        }
        else
        {
            r += 10;
        }

        // blue
        if (b + 10 > 255)
        {
            b = 255;
        }
        else
        {
            b += 10;
        }
        // newImage << (r * rand()) % 255 << " " << (g * rand()) % 255 << " " << (b * rand()) % 255 << endl;
        newImage << r << " " << g << " " << b << endl;
    }
    image.close();    //
    newImage.close(); //

    return 0;
}