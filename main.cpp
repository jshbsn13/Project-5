
//***************************
//Project 5
//Josh Boston
//***************************



//Text file must be one directory above executable



#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"

string eraseNonAlphaChars(string *);

using namespace std;





int main()
{
    int sequenceLength = 0;

    string fileName;
    string appendedFileName;
    string fileLine;

    ifstream file;

    BinaryTree bTree;


    do {
        cout << "Please enter the name of the file to open: " << endl;

        cin >> fileName;

        if (fileName == "")
            cout << "Error! No file name was given!"<<endl;

        cout << "Please enter the maximum length of char sequence: "<<endl;
        cin >> sequenceLength;

        if (sequenceLength <= 0)
            cout << "Error! Please enter an integer greater than zero!";

    } while (fileName == "");


    appendedFileName = "../" + fileName;

    file.open(appendedFileName);


    if(file.is_open())
    {
        getline(file, fileLine);

        while (file)
        {


            string editedFileLine = eraseNonAlphaChars(&fileLine);


            string nodestr = ""; //str to hold a char to pass to insert


            for (int slen = 1;slen <= sequenceLength; slen++)
            {
                for (int i = 0; i < editedFileLine.length(); ++i) {

                    nodestr = editedFileLine.substr(i,slen);



                    if (!bTree.searchNode(nodestr)) {
                        bTree.insertNode(nodestr, 1);
                    }


                    nodestr.clear();

                }
            }


            getline(file, fileLine);

        }

        bTree.displayInOrder();

    }else
    {
        cout<< "Error opening file!"<<endl;
    }













    return 0;
}



string eraseNonAlphaChars(string *pString) {

    string restr;

    for (int i = 0; i < pString->length(); ++i)
    {
        if (isalpha(pString->at(i)))
        {
            restr.push_back(pString->at(i));
        }
    }

    return restr;
}
