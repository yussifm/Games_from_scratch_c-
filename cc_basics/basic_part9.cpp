// File Handling with c++ and Game Dev

// Classes for file Stream Operations
// IOS :-> Input Output Stream
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// istream -> input stream, drive from ios
// handles input streams
// extractions operators '>>'

// ostream -> output stream, drive from ios
//  handles output streams
//  insertion operators '<<'

// streambuf  -> This class contains a  pointer which points to the buffer which is used to managed the input
// output streams

class Player
{
public:
    string name;
    string fileName;
    int health;
    int level;

    void saverPlayer()
    {
        //
        ofstream outfile(fileName);

        if (outfile.is_open())
        {
            outfile << "Player Name: " << name << endl;
            outfile << "Player Health: " << health << endl;
            outfile << "PLayer Level: " << level << endl;
            outfile.close();
            cout << "PLayer data Saved Successfully " << endl;
        }
        else
        {
            cerr << "ERROR: saving Player data failed" << endl;
        }
    }

    void getPlayerSavedData()
    {
        ifstream playerData(fileName);
        string allPlayerSavedData;

        if (playerData.is_open())
        {
            cout << "Getting Player " << name << " saved data..." << endl;
            while (getline(playerData, allPlayerSavedData))
            {
                cout << allPlayerSavedData << endl;
            }
            playerData.close();
        }
        else
        {
            cerr << "ERROR: getting Player data failed" << endl;
        }
    }
};

int main()
{
    // creating instance /  class object  of ofstream
    ofstream fout;

    // by default ios::out, overwrite anything in the file
    // ios::app -> append to the file content
    fout.open("sample.txt", ios::out);     // open the file and append to the file content
    fout << "My sample text file" << endl; // adding content to the file
    fout << "********************************" << endl;
    fout << "************** ******************" << endl;
    fout << "************** ******************" << endl;
    fout << "********************************" << endl;
    fout << "************ ***** ***************" << endl;
    fout << "***************** ***************" << endl;
    fout << "******** ************************" << endl;
    fout << "********************************" << endl;
    fout.close(); // close the file

    // creating instance / class object of ifstream
    ifstream fin;
    string contents;

    fin.open("sample.txt");
    // fin >> contents;
    cout << "Contents in file" << endl;
    while (getline(fin, contents))
    {
        cout << contents << endl;
    }

    fin.close(); // close the file

    // create instance or object of Player class

    Player plyOne;
    plyOne.name = "PlayerOne";
    plyOne.health = 100;
    plyOne.level = 1;
    plyOne.fileName = "PlayerOne.txt";

    plyOne.saverPlayer();
    plyOne.getPlayerSavedData();

    //
    Player plyTwo;
    plyTwo.name = "PlayerTwo";
    plyTwo.health = 50;
    plyTwo.level = 5;
    plyTwo.fileName = "PlayerTwo.txt";

    plyTwo.saverPlayer();
    plyTwo.getPlayerSavedData();

    return 0;
}
