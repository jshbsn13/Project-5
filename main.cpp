#include <iostream>
#include <fstream>

using namespace std;

int main()
{


    string fileName;
    string fileLine;

    ifstream file;


    do {
        cout << "Please enter the name of the file to open: " << endl;

        cin >> fileName;

        if (fileName == "")
            cout << "Error! No file name was given!"<<endl;

    } while (fileName == "");

    cout << fileName << endl;
    file.open(fileName);

    if(file)
    {
        getline(file, fileLine);

        while (file)
        {
            cout << fileLine << endl;
        }

    }else
    {
        cout<< "Error opening file!"<<endl;
    }













    return 0;
}
