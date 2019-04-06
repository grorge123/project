#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
#define F first
#define S second
int abs(int a){
    if(a>0)return a;
    return a*-1;
}
int main(){
    int n,d[10000];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> d[i];
    }
    for(int i=0;i<n;i++){
        double maxl=0,maxr=0;
        int maxlp,maxrp;
        for(int q=0;q<n;q++){
            if(q<i){
                double now=(d[q]-d[i])/(double)abs(q-i);
//                cout<< now<<"="<<d[q]<<"-"<<d[i]<<"/"<<q<<"-"<<i<<endl;
                if(now>=maxl){
                    maxl=now;
                    maxlp=q+1;
                }
            }
            if(q>i){
                double now=(d[q]-d[i])/(double)abs(q-i);
//                cout<< now<<"="<<d[q]<<"-"<<d[i]<<"/"<<q<<"-"<<i<<endl;
                if(now>maxr){
                    maxr=now;
                    maxrp=q+1;
                }
            }
        }
        if(maxl==0)
            cout<< -1<<" ";
        else
            cout<< maxlp<<" ";
        if(maxr==0)
            cout<< -1<<endl;
        else
            cout<< maxrp<<endl;
    }
}
