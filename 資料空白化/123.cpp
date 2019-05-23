#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<random>
#include<utility>
#include<limits>
#include<math.h>
using namespace std;
const int MOD = 1e9+7;
int main(){
    fstream kinp;
    kinp.open("C:\key", ios::in);
    if(kinp){
        long long int ke1 = 0, in = 0, ke2 = 2147483647, in2;
        string key = "there is a key", inp;
        getline(kinp, inp);
//        cout << key<< endl << inp <<endl;
        for(long long int i = 0 ; i < key.size() ; i++){
            ke1 += pow(127,i) * key[i];
        }
        for(long long int i = 0 ; i < inp.size() ; i++){
            in += pow(127,i) * inp[i];
        }
        kinp >> in2;
//        cout << ke1<<' ' << in << endl;
        if(ke1 == in && ke2 == in2){
            return 1;
        }
    }
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(ltm->tm_year+1900>=2020)return 1;
    return 0;
}
