#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

int main(){
    ofstream fout;
    string line;
    int check;

    fout.open("file1.txt", ios::app);
    cout<<"Writing to File (Enter -1 to exit):"<<endl;
    while(fout){
        getline(cin, line);
        if(line == "-1")
            break;
        fout<<line<<endl;
    }
    fout.close();

    cout<<"Do you want to Search for Text (Press 1) or Read the file (Press 2)?"<<endl;
    cin>>check;
    if(check==1){
        ifstream inFile;
        string input;

        inFile.open("file1.txt");

        if(!inFile){
            cout<<"Unable to open the file."<<endl;
        }
        cout<<"Enter word to search for: ";
        cin.ignore();
        getline(cin, input);

        size_t pos;
        while(inFile.good()){
            getline(inFile, line);
            pos=line.find(input);
            if(pos!=string::npos){               /// string::npos is returned if string is not found
                cout<<"Found!"<<endl;
                break;
            }
            if(pos==string::npos){
                cout<<"Not Found."<<endl;
                //break;
            }
        }
    }

    if(check==2){
    cout<<"\n\nReading from the File:"<<endl;
    ifstream fin;
    fin.open("file1.txt");
    while(fin){
        getline(fin, line);
        cout<<line<<endl;
    }
    fin.close();
    }
    return 0;
}
