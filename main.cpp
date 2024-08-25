#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

struct valReturn {
    int num;
    string text;
};

string getRandomWord() {
    vector< string > allwords;
    string line; 

    ifstream inputFile("C:/Users/bence/Desktop/vsc/cpp/test3/words.txt");   
    while (getline (inputFile, line)) {
        allwords.push_back(line);
    }
    inputFile.close(); 


    srand((unsigned) time(NULL));
    int random = rand() % 50;
    return allwords[random]; 
}

int main() {
    string target=getRandomWord();
    int targetl=target.size();
    std::string targetKnown(targetl,'_');
    
    int maxTries;
    cout << "How many tries would you like to have?" << endl;
    cin >> maxTries;
    //cout << "You have " << maxTries << " tries." << endl;

    cout << "here is what we know: the word is ";
    cout << targetl; 
    cout << " letters long; ";
    cout << targetKnown << endl;

    char curGuess;
    int tries = maxTries;
    bool found;
    bool in;
    bool first=true;
    vector <char> tried;
    
    for (;;)
    {   
        cout<<"--------------------------------------"<<endl;
        cout << targetKnown << endl;
        if (!first && tried.size()!=0)
        {
            cout << "you have already tried these letters incorrectly: ";
            for (int i=0;i<int(tried.size());i++){
                cout <<tried[i];
                cout << " ";
            }
            cout << " " << endl;
        }
        found=false;

        if (targetKnown==target){
            cout << "congrats, you have won with ";
            cout << tries;
            cout << " left"<< endl;
            break;
        }

        if (tries < 1){
            cout << "you have lost, better luck next time";
            break;
        }

        cout << "what is your guess?" << endl;
        cin >> curGuess;

        for (int i=0;i<targetl;i++){
            if (target[i]==curGuess)
            {
                targetKnown[i]=curGuess;
                found = true;
            }
        }
        in=false;
        for(int u=0;u<int(tried.size());u++){if (tried[u]==curGuess){in= true;}}
        if (!found)
        {   
            if (in)
            {
                cout << "you have already tried this character"<<endl;
            }
            else
            {
            tries-=1;
            cout <<"you have ";
            cout << tries;
            cout << " tries left" << endl;
            tried.push_back(curGuess);
            }
        }
        first=false;
    }
        

    


    return 0;
}
