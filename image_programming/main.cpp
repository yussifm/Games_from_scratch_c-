#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    ofstream image;
    image.open("image.ppm");

    srand(time(0));

    if (image.is_open())
    {

        // Placeholder
        image << "P3" << endl;
        image << "250 250" << endl;
        image << "255" << endl;
        for (int y = 0; y < 250; y++)
        {
            for (int x = 0; x < 250; x++)
            {

                // the % 255 represents the RGB colors
                image << rand() % 255 << " " << rand() % 255 << " " << rand() % 255 << endl;
            }
        }
    }

    image.close(); //

    return 0;
}