#include <iostream>
#include <string>

using namespace std;

int main() {
    // Game dev with C++ part 4 Arrays
    cout << "Arrays in C++" << endl;

    // Arrays in C++
    // Arrays are fixed Sized Collections of elements of the same data type.
    // accessed arrays using an index, index start from 0
    //  dataType arrayName[arraySize];
    //  dataType arrayName[arraySize] = {elements};
    // dataType arrayName[] = {elements};

    int points[6] = {0, 1, 2, 3, 4, 5};
    int sum = 0;

    for (int index = 0; index < 6; index++) {
        sum += points[index];
    }

    cout << "sum of points: " << sum << endl;

    // Size omit
    int arr[] = {0, 1, 2, 3, 4};
    int i = 0;
    while (i < 5) {
        cout << "index : " << arr[i] << endl;
        ++i;
    }

    // Arrays with do while loops
    int arr_do[] = {14, 16, 8, 12, 100};
    int max = arr_do[0];

    int j = 1;

    do {
        if (arr_do[j] > max) {
            max = arr_do[j];
        }
        ++j;
    } while (j < 5);

    cout << "Maximum element in the array is : " << max << endl;

    // Range-based 'For' loop, Foreach loop
    // for (type variableName : arrayName){ code block}

    int arr_range[7] = {1, 20, 5, 6, 9, 10, 12};

    for (int i : arr_range) {
        cout << "For each Loop index: " << i << endl;
    }

    // Getting Size of an Array

    int arr_get_size[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Array Sized in bytes: " << sizeof(arr_get_size) << endl;
    cout << "Actual Array Sized: " << sizeof(arr_get_size) / sizeof(int)
         << endl;

    // Recommended way of getting array size
    cout << "Actual Array Sized: "
         << sizeof(arr_get_size) / sizeof(arr_get_size[0]) << endl;

    //  Multi-dimensional Arrays in C++
    //  a multi-dimensional array is an array of arrays
    //   dataType arrayName[][];
    //   dataType arrayName[3][5];
    //   dataType arrayName[3][5][6];

    string aphs_arr[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"},
    };

    cout << "Elements in multi-dimensional array: " << aphs_arr[1][0] << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Two dimensional arrays: " << aphs_arr[i][j] << endl;
        }
    }

    string tri_aphs_arr[4][2][3] = {{{"1", "2", "3"}, {"4", "5", "6"}},
                                    {{"7", "8", "9"}, {"10", "11", "12"}},
                                    {{"13", "14", "15"}, {"16", "17", "18"}},
                                    {{"19", "20", "21"}, {"22", "23", "24"}

                                    }};

    cout << "Elements in multi-dimensional array: " << tri_aphs_arr[0][0][0]
         << tri_aphs_arr[3][0][0] << endl;

    tri_aphs_arr[3][0][0] = "Hello";
    cout << "Elements in multi-dimensional array: " << tri_aphs_arr[3][0][0]
         << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << "Two dimensional arrays: " << tri_aphs_arr[i][j][k]
                     << endl;
            }
        }
    }

    // Arrays example in  Game dev
    const int numFrames = 3;
    string animationsFrames[numFrames] = {
        "play_frame_1.png", "play_frame_2.png", "play_frame_3.png"};

    const int ROWS = 5;
    const int COLS = 5;

    char level[ROWS][COLS] = {{'#', '#', '#', '#', '#'},
                              {'#', '.', '.', '.', '#'},
                              {'#', '.', '#', '.', '#'},
                              {'#', '.', '.', '.', '#'},
                              {'#', '#', '#', '#', '#'}};

    // Print the game level
    std::cout << "Game Level:" << std::endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << level[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}