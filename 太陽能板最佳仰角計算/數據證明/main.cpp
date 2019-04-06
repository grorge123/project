#include <bits/stdc++.h>
#include <math.h>
#include <fstream>
using namespace std;
#define IOS ios::sync_with_stdio();cin.tie(0);
#define endl '\n'
#define M_PI 3.14159265358979323846 // pi
#define ISC 1.382 //Solar Constant(=1.382 [kW /m)
#define sun 149600000000 // 太陽到地球的距離
#define F first
#define S second
#define pii pair<int,int>
///////////////////////////////debug////////////////////////////////////////
//#define grorge
#ifdef grorge
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#else
#define debug(...)
#define pary(...)
#endif
///////////////////////////////////////////////////////////////////////////////
//ψ = fi
//δ = del
//ω = om
//φ = phi 緯度
//e = E
//χ = X
//n = N
//λ = lam 經度
//ρ = ro
//β = B 太陽能板的傾斜角
//γ = R 太陽能板的方位角
//θ = si
struct cycle{
    //球座標 ( r , θ , φ )
    //r = 半徑 θ = 跟z軸夾角 φ = 跟x軸夾角
};
long double all = 0;
int n;
int s[10005][10005]={};
pii ra,rb;
bool is_solar[10005][10005]={};
inline long double f_sin_fi(double long del,double long sin_om,long double cos_H){
    return (cos(del) * sin_om)/cos_H;
}
inline long double f_fi(double long del,double long om,long double cos_sis,long double phi){
    long double cos_fi = (sin(del) * cos(phi) - cos(om) * cos(del) * sin(phi)) / (sin(acos(cos_sis)));
    long double fi = acos(cos_fi)*180/M_PI;
    if(om > 0){
        fi = 180 - fi;
    }else if(om <0){
        fi -= 180;
    }else{
        fi = 0;
    }
//    cout << fi << ',';
    fi = fi*M_PI/180;
    return cos_fi;
}
inline long double f_sin_H(long double cos_phi,long double cos_del,long double cos_om,long double del,long double phi){
    return (cos_phi * cos_del * cos_om) + (sin(del) * sin(phi));
}
inline long double f_sin_H0(long double del,long double phi){
    return cos(del - phi);
}
inline long double f_del(long double X,long double N){
    //return -23.45 * cos(360.0/365.0 * (N + 10));
    return 0.006918 - 0.399912 * cos(X) + 0.070257 * sin(X) - 0.006758 * cos(2 * X) + 0.000908 * sin(2 * X);
}
inline long double f_X(long double N){
    return (2 * M_PI * (N - 1))/365;
}
inline long double f_om(long double lam,long double E){
    return lam + 15 * E;
}
inline long double f_E(long double X){
    return (0.0172 + 0.4281 * cos(X) - 7.3515 * sin(X) - 3.3495 * cos(2 * X) - 9.3619 * sin(2 * X))/60;
}
inline long double f_I(long double sin_H,long double sin_H0){
    return (0.42 * sin_H) + (((2.92 - sin_H0) / (2 * sin_H0)) * pow(sin_H,2)) - (((2.92 - sin_H0) / (4 * pow(sin_H0,2))) * pow(sin_H,3));
}
inline long double f_IDN(long double I,long double sin_H){
    return ((1.323 * I) / (sin_H)) - 0.5466;
}
inline long double f_ISH(long double I,long double IDN,long double sin_H){
    return I - (IDN * sin_H);
}
inline long double f_IBR(long double IsBR,long double IbBR,long double IrBR){
    return IbBR + IsBR + IrBR;
}
inline long double f_IbBR(long double IDN,long double cos_si){
    return IDN * cos_si;
}
inline long double f_IsBR(long double I,long double ISH,long double IoH,long double cos_si,long double sin_H,long double B){
    return ISH * (((I-ISH) / (IoH)) * ((cos_si) / (sin_H)) + (1 + ((I-ISH) / (IoH))) * ((1 + cos(B)) / (2)));
}
inline long double f_IoH(long double sin_H,long double N){
    return ISC * (1 + 0.033 * cos((N - 2) * ((2 * M_PI) / (365)))) * sin_H;
}
inline long double f_cos_si(long double del,long double om,long double B,long double R,long double phi){
    return (sin(phi) * cos(B) - cos(phi) * sin(B) * cos(R)) * sin(del) + (cos(phi) * cos(B) + sin(phi) * sin(B) * cos(R)) * cos(del) * cos(om) + sin(B) * sin(R) * cos(del) *sin(om);
}
inline long double f_IrBR(long double I,long double ro,long double B){
    return (ro * I) * ((1 - cos(B)) / (2));
}
inline long double f_ro(long double NS){
    return 0.55;//new concrete Typical albedo (https://en.wikipedia.org/wiki/Albedo)
//    return 0.2 * (1 - NS) + 0.7 * NS;
}
inline long double get_IBR(long double N,long double R,long double B,long double phi,long double lam,long double om, long double* s_sin_H,long double* s_fi,long double* s_IsBR,long double *s_IrBR){
    om = ((om) * M_PI)/180;
    long double X = f_X(N);
//    long double E = f_E(X);
    long double del = f_del(X,N)/*,om = f_om(lam,E)*/;
    long double sin_H = f_sin_H(cos(phi),cos(del),cos(om),del,phi),sin_H0 = f_sin_H0(del,phi);
    long double I = f_I(sin_H,sin_H0);
    long double IDN = f_IDN(I,sin_H),cos_si = f_cos_si(del,om,B,R,phi),IoH = f_IoH(sin_H,N);
    long double ISH = f_ISH(I,IDN,sin_H),ro = f_ro(0);
    long double IbBR = f_IbBR(IDN,cos_si),IsBR = f_IsBR(I,ISH,IoH,cos_si,sin_H,B),IrBR = f_IrBR(I,ro,B);
    long double fi = f_fi(del,om,sin_H,phi);
//    cout << N << ' ' << om/15+12 << ' ' << asin (sin_fi) * 180.0 / M_PI << ' ' << asin (sin_H) * 180.0 / M_PI << endl;
//    cout << sin_fi << endl;
    *s_sin_H = sin_H;
    *s_fi = fi;
    *s_IsBR = IsBR;
    *s_IrBR = IrBR;
    all += IbBR;
    return f_IBR(IsBR,IbBR,IrBR);
}
inline long double get_IBR(long double N,long double R,long double B,long double phi,long double lam,long double om){
    om = ((om) * M_PI)/180;
    long double X = f_X(N);
//    long double E = f_E(X);
    long double del = f_del(X,N)/*,om = f_om(lam,E)*/;
    long double sin_H = f_sin_H(cos(phi),cos(del),cos(om),del,phi),sin_H0 = f_sin_H0(del,phi);
    long double I = f_I(sin_H,sin_H0);
    long double IDN = f_IDN(I,sin_H),cos_si = f_cos_si(del,om,B,R,phi),IoH = f_IoH(sin_H,N);
    long double ISH = f_ISH(I,IDN,sin_H),ro = f_ro(0);
    long double IbBR = f_IbBR(IDN,cos_si),IsBR = f_IsBR(I,ISH,IoH,cos_si,sin_H,B),IrBR = f_IrBR(I,ro,B);
    long double fi = f_fi(del,om,sin_H,phi);
//    cout << N << ' ' << om/15+12 << ' ' << asin (sin_fi) * 180.0 / M_PI << ' ' << asin (sin_H) * 180.0 / M_PI << endl;
//    all += IbBR;
    return f_IBR(IsBR,IbBR,IrBR);
}
inline bool init(long double* phi,long double* lam){
    int m = 1;
    char address[500];
    cout << "input the file name:";
    cin >> address;
    cout << "input Latitude:";
    cin >> *phi;
    *phi = ((*phi) * M_PI)/180;
    cout << "input Longitude:";
    cin >> *lam;
    *lam = ((*lam) * M_PI)/180;
//    cout << "How many solar do you want to build?";
//    cin >> m;
    for(int i = 0; i < m; i++){
//        pair<int,int> a,b;
        cout << "input the solar upper left corner:";
        cin >> ra.F >> ra.S;
        cout << "input the solar lower right corner:";
        cin >> rb.F >> rb.S;
        for(int i = ra.F; i <= rb.F; i++){
            for(int q= ra.S; q <= rb.S; q++){
                is_solar[i][q] = 1;
            }
        }
    }
    fstream file;
    file.open(address,ios::in);
    if(!file){
        cout << "can't find file!"<<endl;
        system("pause");
        return 0;
    }
    file >> n;
    for (int i = 0; i < n; i++){
        for(int q = 0; q < n; q++){
            file >> s[i][q];
        }
    }
    for(int i = 0; i < n; i++){
        for(int q = 0; q < n; q++){
            cout << s[i][q] << ' ' ;
        }
        cout << endl;
    }
    return 1;
}
void special_point(){
//    for(int i = -75; i < 75;i += 15){
////        113,174,267,357
//        get_IBR(357,0,0,((25) * M_PI)/180,((121) * M_PI)/180,i);
    for(int i = -75; i <= 75;i +=15){
//        113,174,267,357
        get_IBR(357,((0) * M_PI)/180,((45) * M_PI)/180,((40) * M_PI)/180,((105) * M_PI)/180,i);
    }
//    for(long double i = 0; i < 360; i++){
//        for(long double q = 0; q < 360; q++){
//            cout << "方位:" << i << ' ' << "傾斜:" << q << ' '<< "能量:" << get_IBR(365.0,i,q,25.0,121.0) << endl;
//        }
//    }
//    for(int i = 0;i <= 20 ;i += 5){
//        all = 0;
//        for(int q = -75; q <= 75; q+=15){
//            all += get_IBR(113, ((i) * M_PI)/180, ((21) * M_PI)/180, ((25) * M_PI)/180, ((121) * M_PI)/180,q);
//            all += get_IBR(174, ((i) * M_PI)/180, ((21) * M_PI)/180, ((25) * M_PI)/180, ((121) * M_PI)/180,q);
//            all += get_IBR(267, ((i) * M_PI)/180, ((21) * M_PI)/180, ((25) * M_PI)/180, ((121) * M_PI)/180,q);
//            all += get_IBR(357, ((i) * M_PI)/180, ((21) * M_PI)/180, ((25) * M_PI)/180, ((121) * M_PI)/180,q);
//            cout << get_IBR(113, ((i) * M_PI)/180, ((21) * M_PI)/180, ((25) * M_PI)/180, ((121) * M_PI)/180,q) << endl;
//            cout << get_IBR(174, ((i) * M_PI)/180, ((21) * M_PI)/180, ((25) * M_PI)/180, ((121) * M_PI)/180,q) << endl;
//            cout << get_IBR(267, ((i) * M_PI)/180, ((21) * M_PI)/180, ((25) * M_PI)/180, ((121) * M_PI)/180,q) << endl;
//            cout << get_IBR(357, ((i) * M_PI)/180, ((21) * M_PI)/180, ((25) * M_PI)/180, ((121) * M_PI)/180,q) << endl;
//        }
//        cout << all << ',';
//        cout << endl;
////        if(i == 40) i-=5;
////        else if(i == 45) i-=5;
//    }
}
void get_hourse(queue<pii>& qu,pii now,long double sin_H,long double fi){
    long double X = ((sun * cos(asin(sin_H))) * sin(fi) * -1),Y = ((sun * cos(asin(sin_H))) * cos(fi));
    int px,py;
    if(X > now.F)px = 1;
    else px = -1;
    if(Y > now.S)py = 1;
    else py = -1;
    if(X - now.F == 0){
        for(int i = now.S; i >=0 && i < n; i += py){
            qu.push(pii(i,now.F));
        }
    }else if(Y - now.S == 0){
        for(int i = now.F; i >=0 && i < n; i += px){
            qu.push(pii(now.S,i));
        }
    }else{
        //Y - now.S = m*(X - now.F)
        //Y - m*X - now.S + m*now.F = 0
        long double m = (Y - now.S) / (X - now.F);
//        cout << "debug1:" << m << endl;
        int nx = now.F,ny = now.S;
        while(nx >= 0 && nx < n&& ny >=0 && ny < n){
//            cout << nx << ' ' << ny << ' ' << abs(ny - m*nx - now.S + m * now.F) / sqrt(1.0 + pow(m,2.0)) << endl;
            while(ny < n && ny >= 0){
                if(abs(ny - m*nx - now.S + m * now.F) / sqrt(1.0 + pow(m,2.0)) > 0.5){
                    ny += py;
                }else{
                    break;
                }
            }
            for(int i = ny; i >= 0 && i < n ; i += py){
//                printf("%d %llf %llf %llf %d\n",i,abs(i - m*nx - now.S + m * now.F) / sqrt(1.0 + pow(m,2.0)),abs(i - m*nx - now.S + m * now.F),sqrt(1.0 + pow(m,2.0)),(abs(i - m*nx - now.S + m * now.F) / sqrt(1.0 + pow(m,2.0)) <= 0.5 && (nx != now.F || i !=now.S)));
//                cout << i << ' ' << abs(ny - m*nx - now.S + m * now.F) / sqrt(1.0 + pow(m,2.0)) << endl;
                if(abs(i - m*nx - now.S + m * now.F) / sqrt(1.0 + pow(m,2.0)) <= 0.5 && (nx != now.F || i !=now.S)){
                    qu.push(pii(i,nx));
                }else if(abs(ny - m*nx - now.S + m * now.F) / sqrt(1.0 + pow(m,2.0)) > 0.5){
                    break;
                }
            }
            nx += px;
        }
    }
    return;
}
pii is_out(long double sin_H,long double fi){
    int re = 0,cont = 0;
    for(int i = ra.F; i <= rb.F; i++){
        for(int q = ra.S; q <= rb.S; q++){
            if(is_solar[i][q]){
                cont++;
                queue<pii> qu;
                get_hourse(qu,pii(q,i),sin_H,fi);
                long double lb = asin (sin_H) * 180.0 / M_PI;
//                cout << "debug2:" << qu.size() << endl;
                debug("debug2:",qu.size());
                while(!qu.empty()){
                    pii now = qu.front();
//                    cout << "debug3:" << now.F << ' ' << now.S << endl;
                    long double lx = sqrt( (now.F - i) * (now.F - i) + (now.S - q) * (now.S - q) );
//                    cout << lb << ' ' << atan((s[now.F][now.S] - s[i][q]) / lx) * 180.0 / M_PI << ' ' << (s[now.F][now.S] - s[i][q]) << ' ' << lx << endl;
                    debug(lb,atan((s[now.F][now.S] - s[i][q]) / lx) * 180.0 / M_PI,(s[now.F][now.S] - s[i][q]),lx);
                    if((s[now.F][now.S] < s[i][q]) || ( lb > atan((s[now.F][now.S] - s[i][q]) / lx) * 180.0 / M_PI)){
                        qu.pop();
                    }else{
                        break;
                    }
                }
                if(qu.size() == 0){
                    re++;
                }
            }
        }
    }
    return pii(re,cont);
}
void solve(long double phi, long double lam,long double ans[]){
    int N[5] = {113,174,267,357};
    for(int R = 0; R <= 0; R++){
        for(int B = 0; B <= 90; B++){
            for(int q = 0; q <= 3; q++){
                for(int i = -75; i <= 75; i += 15){
                    long double sin_H,fi,IsBR,IrBR;
//                    cout << "debug3:" << N[q] << ' ' << R << ' ' << B << ' ' << i << endl;
                    long double IBR = get_IBR(N[q],((R) * M_PI)/180,((B) * M_PI)/180,phi,lam,i,&sin_H,&fi,&IsBR,&IrBR);
                    pii tmp = is_out(sin_H,fi);
//                    cout << "debug4:" << IBR << ' ' << tmp.F << ' ' << tmp.S << endl;
                    ans[B] += IBR * tmp.F;
//                    ans[B] -= IrBR * tmp.F;
                    ans[B] += IsBR * (tmp.S - tmp.F);
//                    system("pause");
                }
            }
//            cout << "debug11:" << ans[B] << endl;
//            system("pause");
        }
    }
    for(int i = 0; i <= 90; i++){
        cout << ans[i] << ',';
    }
}
void output(long double ans[95]){
    fstream file;
    file.open("out.csv",ios::out);
    for(int i = 0; i <= 90; i++){
        file << ans[i];
        file << ',';
    }
    file.close();
}
int main(){
    IOS
//    special_point();
    long double phi,lam = -5;
    long double ans[95] = {};
    if(!init(&phi,&lam))return 0;
    solve(phi,lam,ans);
    output(ans);
    system("pause");
    return 0;
}
