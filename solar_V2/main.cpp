#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define M_PI 3.14159265358979323846/* pi */
//£r = fi
//£_ = sb
//£s = som
//£p = phi
struct cycle{
    //²y®y¼Ð ( r , £c , £p )
    //r = ¥b®| £c = ¸òz¶b§¨¨¤ £p = ¸òx¶b§¨¨¤

};
int n;
int s[10005][10005]={};
long double sin_fi(double long cos_sb,double long sin_som,long double cos_H){
    return (cos_sb * sin_som)/cos_H;
}
long double sin_H(double long cos_phi,double long cos_sb,double long cos_som,double long sin_sb,double long sin_phi){
    return (con_phi * cos_sb * cos_som)
}
bool init(){
    string address;
    cout << "input the file name:";
    cin >> address;
    fstream file;
//    file.open(address,'r');
    if(file){
        cout << "can't find file!"<<endl;
        return 0;
    }
    file >> n;
    for (int i = 0; i < n; i++){
        for(int q = 0; q < n; q++){
            file >> s[i][q];
        }
    }
}

int main(){
    if(!init())return 0;
    solve();
    output();
}
