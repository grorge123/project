#include<bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long int
#define F first
#define S second
#define pi pair<int,int>
struct xy{
    int x = 0,y = 0;
};
int n = 8,bone = 1;
char s[101][101] = {};
bool bs[101][101] = {};
void reset(){
    vector<xy> ve;
    for(int i = 1;i<=n;i++){
        for(int q = 1;q<=n;q++){
            s[i][q]= '.';
            bs[i][q] = false;
            xy now;
            now.x = i,now.y = q;
            ve.push_back(now);
        }
    }
    while(bone--){
        int a = rand()%ve.size();
        bs[ve[a].x][ve[a].y]=true;
        ve.erase(ve.begin()+a);
    }
}
void print(void){
    for(int i=1;i<=n;i++){
        for(int q=1;q<=n;q++){
            cout << ss[i][q];
        }
        cout << endl;
    }
}
bool input(int x,int y){

}
void dfs(void){

}
int checkNum(string inp){
    for(int i=0;i<inp.size();i++){
        if((inp[i]>'9'||inp[i]<'0')&&inp[i]!=' '){
            return 0;
        }
    }
    return inp.size();
}
int chNum(string inp){
    int re=0;
    for(int i=0;i<inp.size();i++){
        re*=10;
        re+=inp[i]-'0';
    }
    return re;
}
int main(){
    srand(time(NULL));
    cout << "請輸入地圖大小(最大100*100最小1*1)\n";
    string inp;
    while(true){
        getline(cin,inp);
        if(checkNum(inp)<=3&&checkNum(inp)>=1){
            n=chNum(inp);
            if(n==0){
                cout << "場地太小\n";
            }else{
                cout << "請輸入地雷數量\n";
                break;
            }
        }else{
            cout << "Wrong input!Please enter again!!\n";
        }
    }
    while(true){
        getline(cin,inp);
        if(checkNum(inp)<=3&&checkNum(inp)>=1){
            bone=chNum(inp);
            if(bone>n*n){
                cout << "地雷數量太多\n";
            }else{
                cout << "reseting\n";
                reset();
                break;
            }
        }else{
            cout << "Wrong input!Please enter again!!\n";
        }
    }
    print();
}
