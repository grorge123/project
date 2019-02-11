#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define M_PI 3.14159265358979323846 // pi
#define ISC 1.382 //Solar Constant(=1.382 [kW /m)
//ψ = fi
//δ = del
//ω = om
//φ = phi
//e = E
//χ = X
//n = N
//λ = lam
//ρ = ro
//β = B
//γ = R
//θ = si
struct cycle{
    //球座標 ( r , θ , φ )
    //r = 半徑 θ = 跟z軸夾角 φ = 跟x軸夾角

};
int n;
int s[10005][10005]={};
long double f_sin_fi(double long del,double long sin_om,long double cos_H){
    return (cos(del) * sin_om)/cos_H;
}
long double f_sin_H(long double cos_phi,long double cos_del,long double cos_om,long double del,long double phi){
    return (cos_phi * cos_del * cos_om) + (sin(del) * sin(phi));
}
long double f_sin_H0(long double del,long double phi){
    return cos(del - phi);
}
long double f_del(long double X){
    return 0.006918 - 0.399912 * cos(2*X) + 0.070257 * sin(X) - 0.006758 * cos(2 * X) + 0.000908 * sin(2 * X);
}
long double f_X(long double N){
    return (2 * M_PI * (N - 1))/365;
}
long double f_om(long double lam,long double E){
    return lam + 15 * E;
}
long double f_E(long double X){
    return (0.0172 + 0.4281 * cos(X) - 7.3515 * sin(X) - 3.3495 * cos(2 * X) - 9.3619 * sin(2 * X))/60;
}
long double f_I(long double sin_H,long double sin_H0){
    return (0.42 * sin_H) + (((2.92 - sin_H0) / (2 * sin_H0)) * pow(sin_H,2)) - (((2.92 - sin_H0) / (4 * pow(sin_H0,2))) * pow(sin_H,3));
}
long double f_IDN(long double I,long double sin_H){
    return ((1.323 * I) / (sin_H)) - 0.5466;
}
long double f_ISH(long double I,long double IDN,long double sin_H){
    return I - (IDN * sin_H);
}
long double f_IBR(long double IsBR,long double IbBR,long double IrBR){
    return IbBR + IsBR + IrBR;
}
long double f_IbBR(long double IDN,long double cos_si){
    return IDN * cos_si;
}
long double f_IsBR(long double I,long double ISH,long double IoH,long double cos_si,long double sin_H,long double B){
    return ISH * (((I-ISH) / (IoH)) * ((cos_si) / (sin_H)) + (1 + ((I-ISH) / (IoH))) * ((1 + cos(B)) / (2)));
}
long double f_IoH(long double sin_H,long double N){
    return ISC * (1 + 0.033 * cos((N - 2) * ((2 * M_PI) / (365)))) * sin_H;
}
long double f_cos_si(long double del,long double om,long double B,long double R,long double phi){
    return (sin(phi) * cos(B) - cos(phi) * sin(B) * cos(R)) * sin(del) + (cos(phi) * cos(B) + sin(phi) * sin(B) * cos(R)) * cos(del) * cos(om) + sin(B) * sin(R) * cos(del) *sin(om);
}
long double f_IrBR(long double I,long double ro,long double B){
    return (ro * I) * ((1 - cos(B)) / (2));
}
long double f_ro(long double NS){
    return 0.2 * (1 - NS) + 0.7 * NS;
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
//    solve();
//    output();
}
