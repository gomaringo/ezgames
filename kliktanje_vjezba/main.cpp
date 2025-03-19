#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <iomanip>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main(){
    vector<char> ananas;
    vector<string> pisanje={"jf", "fj", "KD", "dk", "ls", "SL", ";a", "a;", "asl", "fjl", ";kd", "aj", "jh", "Fg", "ir", "eo", "ikl", "erio", ";es", "aoi","we","Rtub"};
    int a, koliko;
    koliko=0;
    string banana;
    auto start = high_resolution_clock::now();
    for (int i=0;i<20;i++){
        a=rand() % pisanje.size();
        cout<< pisanje[a] << endl;
        cin>>banana;
        cout << "\033[2J\033[1;1H";
        if (banana==pisanje[a]){
            koliko=koliko+1;
            ananas.push_back('+');
        }
        else{
            ananas.push_back('-');
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout<<koliko<<endl;
    cout <<"Time: ";
    cout << std::setprecision(2);
    cout << (double) duration.count();
    cout<<" "<<"seconds"<<endl;
    cout<<"+ = correct    - = not correct:";
    for (int jabuka=0;jabuka<ananas.size();jabuka++){
        cout<<ananas[jabuka];
    }
    cout << endl;
    system ("read");

    cout << "\033[2J\033[1;1H";
    cout<<"Thanks for playing.";
}
