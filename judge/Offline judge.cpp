#include<bits/stdc++.h>
#include<time.h>
#include<fstream>
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std;
using namespace std::chrono;
int compaile(string inp,string ans,string pro,int tim){
    fstream finp,fans,fpro;
    fans.open("./ans/"+ans+".cpp",ios::in);
    finp.open("./inp/"+inp+".cpp",ios::in);
    fpro.open("./pro/"+pro+".txt",ios::in);
    if(!finp){
        cout << "輸入檔名錯誤!"<<endl;
        return 0;
    }
    if(!fans){
        cout << "輸入答案檔名錯誤!"<<endl;
        return 0;
    }
    if(!fpro){
        cout <<"題目找不到"<<endl;
        return 0;
    }
    string cmd = "g++ -g -O2 -std=gnu++11 -o ./out/"+inp+".exe"+" ./inp/"+inp+".cpp";
    cout << cmd<<endl;
    if(system(cmd.c_str())){
        return 0;
    }
    cmd="g++ -g -O2 -std=gnu++11 -o ./ansout/" + ans + ".exe" + " ./ans/" + ans + ".cpp";
    if(system(cmd.c_str())){
        return 0;
    }
    auto startTime = steady_clock::now();
    string cmdS = "ansout\\" + ans + ".exe < " + "pro\\" + pro + ".txt > " + "judge\\" + ans + ".txt";
    cout << cmdS<<endl;
    system(cmdS.c_str());
    //cout << "correct answer cost " << (steady_clock::now() - startTime).count() << " at test" << i << endl;
    auto timeout =  (steady_clock::now() - startTime) * 15;
    auto timeout2 = seconds(tim);
    startTime = steady_clock::now();
    cmdS = "out\\" + inp + ".exe < " + "pro\\" + pro + ".txt > " + "judge\\" + inp + ".txt";
    cout << cmdS<<endl;
    if(system(cmdS.c_str()))return 4;
    auto currentTime = steady_clock::now();
    //cout << "submit answer cost  " << (steady_clock::now() - startTime).count() << " at test" << i << endl;
    if(currentTime - startTime > timeout || currentTime - startTime > timeout2) {
        return 2;
    }
    return 1;
}
int judge(string inp,string ans, string pro){
    fstream finp,fans;
    fans.open("./judge/"+ans+".txt",ios::in);
    finp.open("./judge/"+inp+".txt",ios::in);
    vector<string> ansarry,inparry;
    string now;
    while(fans>>now){
        ansarry.push_back(now);
    }
    while(finp>>now){
        inparry.push_back(now);
    }
//    for(int i=0;i<ansarry.size();i++){
//        cout << ansarry[i]<<endl;
//    }
//    for(int i=0;i<inparry.size();i++){
//        cout << inparry[i]<<endl;
//    }
    if(inparry.size()!=ansarry.size()){
        cout << inparry.size()<<" "<<ansarry.size()<<endl;
        return 3;
    }
    for(int i=0;i<inparry.size();i++){
        if(inparry[i]!=ansarry[i]){
            cout <<inparry[i]<<" "<<ansarry[i]<<endl;
            return 3;
        }
    }
    return 1;
}
void rm(string inp,string ans){
    string cmd = "del judge\\" + inp + ".txt";
    system(cmd.c_str());
    cmd = "del judge\\" + ans + ".txt";
    system(cmd.c_str());
    cmd = "del out\\" + inp + ".exe";
    system(cmd.c_str());
    cmd = "del ansout\\" + ans + ".exe";
    system(cmd.c_str());
//    string cmd = "del inp\\" + inp + ".cpp";
//    system(cmd.c_str());
}
int main(){
    string inp,ans,pro;
    int tim;
    while(true){
        cout << "請輸入程式檔名,答案檔名,問題資料夾,時間";
        cin >> inp>>ans>> pro>>tim;
        int result=compaile(inp,ans,pro,tim);
        if(result==1){
            result=judge(inp,ans,pro);
            rm(inp,ans);
        }
        switch(result){
        case 0:
            cout << "CE"<<endl;
            break;
        case 1:
            cout << "AC"<<endl;
            break;
        case 2:
            cout << "TLE"<<endl;
            break;
        case 3:
            cout << "WA"<<endl;
            break;
        case 4:
            cout << "RE"<<endl;
            break;
        }
    }
    return 0;
}
