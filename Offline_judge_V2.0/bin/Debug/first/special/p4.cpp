#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int y;
    cin >> y;
    if(y <= 0 || y >= 2000){
        return 3;
    }
    if(!((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 3200 != 0))){
        return 3;
    }
    return 1;
}
