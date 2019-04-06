#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define X first
#define Y second
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define ll long long
#define REP(i,a) for(int i=0;i<a;++i)
#define REP1(i,a,b) for(int i=a;i<b;++i)
#define REP2(i,a,b) for(int i=a;i<=b;++i)
#define RREP(i,a) for(int i=a-1;i>=0;--i)
#define RREP1(i,a,b) for(int i=a;i>b;--i)
#define RREP2(i,a,b) for(int i=a;i>=b;--i)
#define SREP(i,x) for(auto i:x)
#define MS0(x) memset((x),0,sizeof((x)))
#define MS1(x) memset((x),-1,sizeof((x)))
#define MSF(x) memset((x),127,sizeof(x))
#define pb push_back
#define LE(x) (int)((x).size())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<D,D>
#define im guagua
#define RI(x) x=rit()
#define RII(a,b) a=rit(),b=rit()
#define RIII(a,b,c) a=rit(),b=rit(),c=rit()
#define debug 0
const int INF = 0x7F7F7F7F;
const double EPS = 1e-10 ;
const ll mod7 = 1e9+7;
const ll mod9 = 1e9+9;
using namespace std;
inline ll rit(){
    ll f=0,key=1;
    char c;
    do{
        c=getchar();
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
    }while(c>='0' && c<='9');
    return f*key;
}
inline void fprt(D f){
    printf("%.08lf",f);
}
void init(){
}
const int Z = 100005;
int n;
int a[Z],ansl[Z],ansr[Z];
deque<int> dq;
double ask(int p1,int p2){
    return fabs((a[p2]-a[p1])/(p2-p1));
}
void read(){
    RI(n);//¿é¤J
    REP2(i,1,n){
        RI(a[i]);
    }
}
void solve(){
    int last1,last2;
    REP2(i,1,n){
        while((!dq.empty()) && a[i] >= a[dq.back()]){
            dq.pop_back();
        }
        while(dq.size()>=2){
            last1 = dq.back();
            dq.pop_back();
            last2 = dq.back();
            if(ask(last1,i) > ask(last2,i)){
                dq.push_back(last1);
                break;
            }
        }
        if(dq.empty()) ansl[i] = -1;
        else ansl[i] = dq.back();
        dq.push_back(i);
    }
    while(!dq.empty()) dq.pop_back();
    RREP2(i,n,1){
        while((!dq.empty()) && a[i] >= a[dq.back()]){
            dq.pop_back();
        }
        while(dq.size()>=2){
            last1 = dq.back();
            dq.pop_back();
            last2 = dq.back();
            if(ask(last1,i) > ask(last2,i)){
                dq.push_back(last1);
                break;
            }
        }
        if(dq.empty()) ansr[i] = -1;
        else ansr[i] = dq.back();
        dq.push_back(i);
    }
    REP2(i,1,n){
        cout<<ansl[i]<<' '<<ansr[i]<<endl;
    }
}
int main(){
    int nn=1;
    // nn=rit();
    while(nn--){
        // while(cin>>n)
            init(),read(),solve();
    }
    return 0;
}
