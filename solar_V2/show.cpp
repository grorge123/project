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
long double all = 0;
int n;
int s[10005][10005]={};
pii ra,rb;
bool is_solar[10005][10005]={};
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
    fi = fi*M_PI/180;
    return cos_fi;
}
inline long double get_IBR(long double N,long double R,long double B,long double phi,long double lam,long double om, long double* s_sin_H,long double* s_fi,long double* s_IsBR,long double *s_IrBR){
    om = ((om) * M_PI)/180;
    long double X = [](long double N){return (2 * M_PI * (N - 1))/365;}(N);
    long double del = [](long double X,long double N){return 0.006918 - 0.399912 * cos(X) + 0.070257 * sin(X) - 0.006758 * cos(2 * X) + 0.000908 * sin(2 * X);}(X,N);
    long double sin_H = [](long double cos_phi,long double cos_del,long double cos_om,long double del,long double phi){return (cos_phi * cos_del * cos_om) + (sin(del) * sin(phi));}(cos(phi),cos(del),cos(om),del,phi);
    long double sin_H0 = [](long double del,long double phi){return cos(del - phi);}(del,phi);
    long double I = [](long double sin_H,long double sin_H0){return (0.42 * sin_H) + (((2.92 - sin_H0) / (2 * sin_H0)) * pow(sin_H,2)) - (((2.92 - sin_H0) / (4 * pow(sin_H0,2))) * pow(sin_H,3));}(del,phi);
    long double IDN = [](long double I,long double sin_H){return ((1.323 * I) / (sin_H)) - 0.5466;}(I,sin_H);
    long double cos_si = [](long double del,long double om,long double B,long double R,long double phi){return (sin(phi) * cos(B) - cos(phi) * sin(B) * cos(R)) * sin(del) + (cos(phi) * cos(B) + sin(phi) * sin(B) * cos(R)) * cos(del) * cos(om) + sin(B) * sin(R) * cos(del) *sin(om);}(del,om,B,R,phi);
    long double IoH = [](long double sin_H,long double N){return ISC * (1 + 0.033 * cos((N - 2) * ((2 * M_PI) / (365)))) * sin_H;}(sin_H,N);
    long double ISH = [](long double I,long double IDN,long double sin_H){return I - (IDN * sin_H);}(I,IDN,sin_H);
    long double ro = 0.55;
    long double IbBR = [](long double IDN,long double cos_si){return IDN * cos_si;}(IDN,cos_si);
    long double IsBR = [](long double I,long double ISH,long double IoH,long double cos_si,long double sin_H,long double B){return ISH * (((I-ISH) / (IoH)) * ((cos_si) / (sin_H)) + (1 + ((I-ISH) / (IoH))) * ((1 + cos(B)) / (2)));}(I,ISH,IoH,cos_si,sin_H,B);
    long double IrBR = [](long double I,long double ro,long double B){return (ro * I) * ((1 - cos(B)) / (2));}(I,ro,B);
    long double fi = f_fi(del,om,sin_H,phi);
    *s_sin_H = sin_H;
    *s_fi = fi;
    *s_IsBR = IsBR;
    *s_IrBR = IrBR;
    all += IbBR;
    return IsBR+IbBR+IrBR;
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
    for(int i = 0; i < m; i++){
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
        long double m = (Y - now.S) / (X - now.F);
        int nx = now.F,ny = now.S;
        while(nx >= 0 && nx < n&& ny >=0 && ny < n){
            while(ny < n && ny >= 0){
                if(abs(ny - m*nx - now.S + m * now.F) / sqrt(1.0 + pow(m,2.0)) > 0.5){
                    ny += py;
                }else{
                    break;
                }
            }
            for(int i = ny; i >= 0 && i < n ; i += py){
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
                while(!qu.empty()){
                    pii now = qu.front();
                    long double lx = sqrt( (now.F - i) * (now.F - i) + (now.S - q) * (now.S - q) );
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
    for(int B = 0; B <= 90; B++){
        for(auto q:N){
            for(int i = -75; i <= 75; i += 15){
                long double sin_H,fi,IsBR,IrBR;
                long double IBR = get_IBR(N[q],((0) * M_PI)/180,((B) * M_PI)/180,phi,lam,i,&sin_H,&fi,&IsBR,&IrBR);
                pii tmp = is_out(sin_H,fi);
                ans[B] += IBR * tmp.F;
                ans[B] += IsBR * (tmp.S - tmp.F);
            }
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
    IOS;long double phi,lam = -5;
    long double ans[95] = {};
    if(!init(&phi,&lam))return 0;
    solve(phi,lam,ans);
    output(ans);
    system("pause");
    return 0;
}
