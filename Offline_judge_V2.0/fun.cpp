#include <iostream>
#include <fstream>
#include "com.h"
using namespace std;
const int INF = 2147483647;
string change(int result){
    string re;
    switch(result){
        case 0:
            re = "CE ";
            break;
        case 1:
            re = "AC ";
            break;
        case 2:
            re = "TLE";
            break;
        case 3:
            re = "WA ";
            break;
        case 4:
            re = "RE ";
            break;
        case 5:
            re = "SE ";
            break;
        default:
            re = "WTF!";
    }
    return re;
}
void restart (Problem problem[],People people[],string *address,int *all_pro,int *all_peo){
    cout << "請輸入比賽設定介面地址:";
    cin >> *address;
    fstream index;
    cout << "./"+*address+"/index.txt"<<endl;
    index.open("./"+*address+"/index.txt",ios::in);
    if(!index){
        cout << "輸入錯誤"<<endl;
        restart (problem,people,address,all_pro,all_peo);
    }
    index >> *all_pro;
    for(int i = 1; i <= *all_pro; i++){
        problem[i].name="p";
        problem[i].name+=(char)(i+'0');
        index >> problem[i].type;
        index >> problem[i].is_strict;
        index >> problem[i].ans;
        index >> problem[i].pro;
        index >> problem[i].time;
        if(problem[i].type!="normal"){
            index >> problem[i].special;
        }
    }
    index >> *all_peo;
    for(int i = 1; i <= *all_peo; i++){
        people[i].id = i;
        index >> people[i].name;
    }
}
bool input (People people[],Problem problem[],People* now_peo,Problem* now_pro,string address,int all_pro,int all_peo){
    fstream now;
    int fi=0;
    while(!fi){
        for(int i = 1; i <= all_peo; i++){
            for(int q = 1; q <= all_pro; q++){
                now.open("./"+address+"/inp/"+people[i].name+"_p"+(char)(q+'0')+".cpp",ios::in);
                if(now){
                    *now_peo = people[i];
                    *now_pro = problem[q];
                    fi=1;
                    break;
                }
            }
            if(fi)break;
        }
    }
    now.open("./"+address+"/stop.txt",ios::in);
    if(now)return false;
    return true;
}
void solve (Problem problem[],People people[],Problem now_pro,People now_peo,string address,int all_pro,int all_peo){
    int result = 0;
    if(now_pro.type=="normal"){
        result = compile(address,now_peo.name+"_"+now_pro.name,now_pro.name,now_pro.time,0);
        if(result == 1){
            if(now_pro.is_strict)
                result = strict_judge(address,now_peo.name+"_"+now_pro.name,now_pro.name);
            else
                result = judge(address,now_peo.name+"_"+now_pro.name,now_pro.name);
        }
        rm(address,now_peo.name+"_"+now_pro.name);
    }else if(now_pro.type=="hack"){
        result = compile(address,now_pro.name,now_peo.name+"_"+now_pro.name,INF,1);
        result = special_judge(address,now_peo.name+"_"+now_pro.name,now_pro.special,0);
        if(result == 1){
            if(now_pro.is_strict)
                result = strict_judge(address,now_peo.name+"_"+now_pro.name,now_pro.name) == 3 ? 1 : 3;
            else
                result = judge(address,now_peo.name+"_"+now_pro.name,now_pro.name) == 3 ? 1 : 3;
        }
        rm(address,now_peo.name+"_"+now_pro.name);
    }else if(now_pro.type=="debug"){
        result = compile(address,now_peo.name+"_"+now_pro.name,now_pro.name,now_pro.time,0);
        if(result == 1){
            if(now_pro.is_strict)
                result = strict_judge(address,now_peo.name+"_"+now_pro.name,now_pro.name);
            else
                result = judge(address,now_peo.name+"_"+now_pro.name,now_pro.name);
        }
        if(result == 1)
            result = edit_number(address,now_peo.name+"_"+now_pro.name,now_pro.special,now_pro.ans);
        rm(address,now_peo.name+"_"+now_pro.name);
    }else if(now_pro.type=="special"){
        result = compile(address,now_peo.name+"_"+now_pro.name,now_pro.name,now_pro.time,0);
        if(result==1){
            result = special_judge(address,now_peo.name+"_"+now_pro.name,now_pro.special,1);
        }
        rm(address,now_peo.name+"_"+now_pro.name);
    }else{
        cout << "I can't find this type!!"<<endl;
        return;
    }
    if(people[now_peo.id].score[now_pro.name[1]-'0'] != change(result)){
        people[now_peo.id].score[now_pro.name[1]-'0'] = change(result);
        cout << "debug8:" << now_peo.id << ' ' << now_pro.name[1]-'0' << ' ' << people[now_peo.id].score[now_pro.name[1]-'0'] << endl;
        update_score(people,problem,all_pro,all_peo,address);
    }
    cout << now_peo.name<<' '<<now_pro.name<<' '<<write(result,address,now_peo.name)<<endl;
}
