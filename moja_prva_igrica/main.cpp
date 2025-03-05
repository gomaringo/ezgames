#include<iostream>
#include<random>
using namespace std;
char matrica[100][100];

int velicina_tablice=10;

void kvadrat(){
    for (int redak=0;redak<velicina_tablice;redak++){
        for (int stupac=0;stupac<velicina_tablice;stupac++){
            matrica[redak][stupac]='-';
        }
    }
}

void ispis(){
    for (int redak=0;redak<velicina_tablice;redak++){
        for (int stupac=0;stupac<velicina_tablice;stupac++){
            cout<<matrica[redak][stupac]<<' ';
        }
        cout<<endl;

    }
    cout<<endl;

}


int main()
{

    int i,koordinate,j,k,HP,levelup,snaga,coins,kraken,trophis,kukac,banana;
    kraken=200;
    coins=0;
    kukac=25;
    snaga=100;
    levelup=25;
    trophis=0;
    banana=0;
    HP=200;
    string ananas;
    for (int ads=0;1;ads++){
        kvadrat();
        cout<<"Strength: "<<snaga<<endl;
        cout<<"Coins: "<<coins<<endl;
        cout<<"HP of enemy: "<<HP<<endl;
        cout<<"Trophis: "<<trophis<<endl;
        cout<<"Nedded coins: "<<levelup<<endl;
        j=5;
        k=0;
        matrica[k][j]='O';
        cout<<"LEVEL_UP ili PLAY"<<endl;
        cin>>ananas;
        cout << "\033[2J\033[1;1H";
        if (ananas=="PLAY"){
            ispis();
            for (int c=0;1;c++){

                srand(time(NULL));
                i=rand()%4;
                while (i==0){
                    srand(time(NULL));
                    i=rand()%4;
                }
                cin>>koordinate;
                matrica[koordinate/10][koordinate%10]='#';
                if (i==1){
                    matrica[k][j]='-';
                    k=k+1;
                    j=j-1;
                    matrica[k][j]='O';
                    ispis();
                }
                if (i==2){
                    matrica[k][j]='-';
                    k=k+1;
                    matrica[k][j]='O';
                    ispis();
                }
                if (i==3){
                    matrica[k][j]='-';
                    k=k+1;
                    j=j+1;
                    matrica[k][j]='O';
                    ispis();
                }
                if (matrica[k][j] == matrica[koordinate/10][koordinate%10]){
                    HP=HP-snaga;
                    cout<<"STRIKE" << endl;

                }
                if (HP <= 0){
                    cout<<"YOU GET 100 COINS AND 5 TROPHIS"<<endl;
                    cout<<endl;
                    coins=coins+100+banana;
                    banana=banana+25;
                    HP=0+kraken+50;
                    kraken=HP;
                    trophis=trophis+5;
                    break;

                }
                if (k==10){
                    cout<<"YOU LOSE"<<endl;
                    cout<<endl;
                    HP=0+kraken;
                    kraken=HP;
                    if (trophis == 0){
                        trophis= trophis - 0;
                    }
                    else{
                        trophis=trophis - 5;
                    }

                    break;
                }
            }
        }
        if (ananas == "LEVEL_UP"){
            if (coins>=levelup){
                coins=coins-levelup;
                snaga=snaga+50;
                levelup=levelup+50+kukac;
                kukac=kukac+25;
            }
            else{
                cout<<"Not enough coins"<<endl;
                cout<<endl;

            }

        }
    }
    return 0;
}

