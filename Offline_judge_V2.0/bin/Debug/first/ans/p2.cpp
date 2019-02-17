#include <iostream>
using namespace std;
int main(){
    int s;
    cin >> s;
    for(int i = 2;i*i <= s; i++){
        if(s % i == 0){
            cout << "N" << endl;
            return 0;
        }
    }
    cout << "Y" << endl;
    return 0;
}
