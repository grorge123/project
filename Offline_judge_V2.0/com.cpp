#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>
#include "struct.h"
using namespace std;
using namespace std::chrono;

int compile(string address,string inp,string pro,int tim,int type){
    fstream file;
    if(type == 0)
        file.open("./"+address+"/inp/"+inp+".cpp",ios::in);
    else if(type == 1)
        file.open("./"+address+"/ans/"+inp+".cpp",ios::in);
    if(!file)return 0;
    string cmd = "g++ -g -O2 -std=gnu++11 -o ./" + address + "/out/" + inp + ".exe" + " ./" + address + "/inp/" + inp + ".cpp";
    cout << cmd << endl;
    if(system(cmd.c_str())){
        return 0;
    }
    string cmdS;
    if(type == 0)
        cmdS = address + "\\out\\" + inp + ".exe < " + address + "\\pro\\" + pro + ".txt > " + address + "\\judge\\" + inp + ".txt";
    else
        cmdS = address + "\\out\\" + inp + ".exe < " + address + "\\inp\\" + pro + ".txt > " + address + "\\judge\\" + inp + ".txt";
    cout << cmdS<<endl;
    auto time_start = steady_clock::now();
    if(system(cmdS.c_str()))return 4;
    auto time_end = steady_clock::now();
    seconds curr( tim );
    cout <<"time:"<< (double)duration_cast<chrono::microseconds>(time_end - time_start).count()/duration_cast<chrono::microseconds>(curr).count()<<endl;
    if(duration_cast<chrono::microseconds>(time_end - time_start) > duration_cast<chrono::microseconds>(curr)){
        return 2;
    }
    return 1;
}
int judge(string address,string inp,string ans){
    fstream finp,fans;
    fans.open("./" + address + "/judge/"+ans+".txt",ios::in);
    finp.open("./" + address + "/judge/"+inp+".txt",ios::in);
    if(!fans){
        cout <<ans<< "���פ���"<<endl;
        return 5;
    }
    vector<string> ansarry,inparry;
    string now;
    while(fans>>now){
        ansarry.push_back(now);
    }
    while(finp>>now){
        inparry.push_back(now);
    }
    if(inparry.size()!=ansarry.size()){
        cout <<"�A��X�Ӽ�:"<< inparry.size()<<" "<<"���T�Ӽ�:"<<ansarry.size()<<endl;
        return 3;
    }
    for(int i=0;i<(int)inparry.size();i++){
        if(inparry[i]!=ansarry[i]){
            cout <<"���~����:"<<inparry[i]<<" "<<ansarry[i]<<endl;
            return 3;
        }
    }
    return 1;
}
int special_judge(string address,string inp,string special,int type){
    fstream file;
    if(type == 0){
        file.open("./"+address+"/special/"+special+".cpp",ios::in);//�Nspecial judge���sĶ,�M��Hinp���W�٦s��out�M���inp.txt�i�hexe�⵲�G�s��inp.txt
        if(!file){
            cout << "I can't find " + special << endl;
            return 5;
        }
        string cmd = "g++ -g -O2 -std=gnu++11 -o ./" + address + "/out/" + inp + ".exe" + " ./" + address + "/special/" + special + ".cpp";
        cout << cmd << endl;
        if(system(cmd.c_str())){
            cout << "special judge CE " + special<<endl;
            return 5;
        }
        string cmdS = address + "\\out\\" + inp + ".exe < " + address + "\\inp\\" + inp + ".txt > " + address + "\\judge\\" + inp + ".txt";
        cout << cmdS<<endl;
        if(system(cmdS.c_str()))return 4;
    }else if(type == 1){
        file.open("./"+address+"/special/"+special+".cpp",ios::in);
        if(!file){
            cout << "I can't find " + special<<endl;
            return 5;
        }
        string cmd = "g++ -g -O2 -std=gnu++11 -o ./" + address + "/out/" + inp + ".exe" + " ./" + address + "/special/" + special + ".cpp";
        cout << cmd << endl;
        if(system(cmd.c_str())){
            cout << "special judge CE " + special<<endl;
            return 5;
        }
        string cmdS = address + "\\out\\" + inp + ".exe < " + address + "\\judge\\" + inp + ".txt";
        return system(cmdS.c_str());
    }
    return 1;
}
int strict_judge(string address,string inp,string ans){
    fstream finp,fans;
    fans.open("./" + address + "/judge/"+ans+".txt",ios::in);
    finp.open("./" + address + "/judge/"+inp+".txt",ios::in);
    if(!fans){
        cout <<ans<< "�䤣�쵪�צ�m"<<endl;
        return 5;
    }
    vector<string> ansarry,inparry;
    string now;
    char now2[100];
    while(fans.getline(now2,sizeof(now2))){
        now = now2;
        ansarry.push_back(now);
    }
    while(finp.getline(now2,sizeof(now2))){
        now = now2;
        inparry.push_back(now);
    }
    if(inparry.size()!=ansarry.size()){
        cout <<"�A��X�Ӽ�:"<< inparry.size()<<" "<<"���T�Ӽ�:"<<ansarry.size()<<endl;
        return 3;
    }
    for(int i=0;i<(int)inparry.size();i++){
        if(inparry[i]!=ansarry[i]){
            cout <<"���~����:"<<inparry[i]<<" "<<ansarry[i]<<endl;
            return 3;
        }
    }
    return 1;
}
int tonumber(string special){
    long long int re = 0;
    for(int i = 0; i < (int)special.size(); i++){
        re *= 10;
        re += special[i] - '0';
    }
    return re;
}
int LCS[10005][10005]={};
int edit_number(string address,string inp,string special,string ans){
    int MAX_num = tonumber(ans);
    fstream file_inp,file_ans;
    file_inp.open("./" + address + "/inp/" + inp + ".cpp",ios::in);
    file_ans.open("./" + address + "/ans/" + ans + ".cpp",ios::in);
    if(!file_ans){
        cout << "I can't find" << ans << endl;
        return 5;
    }
    string all_inp,all_ans;
    char tmp[500] = {};
    while(file_inp.getline(tmp,sizeof(tmp))){
        all_inp += tmp;
    }
    while(file_ans.getline(tmp,sizeof(tmp))){
        all_ans += tmp;
    }
    for(int i = 0; i <= (int)all_inp.size(); i++){
        for(int q = 0; q <= (int)all_ans.size(); q++){
            if(all_inp[i] == all_ans[i]){
                LCS[i][q] = LCS[i-1][q-1]+1;
            }else{
                LCS[i][q] = max(LCS[i-1][q],LCS[i][q-1]);
            }
        }
    }
    if((int)all_ans.size() - LCS[all_inp.size() - 1][all_ans.size() - 1] <= MAX_num){
        return 1;
    }else{
        return 3;
    }
}
void rm(string address,string inp){
    string cmd = "del " + address + "\\judge\\" + inp + ".txt";
    system(cmd.c_str());
    cmd = "del " + address + "\\out\\" + inp + ".exe";
    system(cmd.c_str());
    cmd = "del " + address + "\\inp\\" + inp + ".cpp";
    system(cmd.c_str());
}
void update_score(People people[],Problem problem[],int all_pro,int all_peo,string address){
    fstream file;
    file.open("./" + address + "/score/score_board.txt",ios::out);
    file << "name";
    for(int i = 1; i <= all_pro; i++){
        file << '\t' << problem[i].name;
    }
    file << '\n';
    for(int i = 1; i <= all_peo; i++){
        file << people[i].name;
        for(int q = 0; q <= all_pro; q++){
            file << '\t' << people[i].score[q];
        }
        file << '\n';
    }
    file.close();
}
string write(int result,string address,string inp){
        fstream file;
        file.open("./" + address + "/score/" + inp + ".txt",ios::ate);
        string re;
        switch(result){
        case 0:
            re = "Oh! CE! Maybe you need to see your code again";
//            cout << "Oh! CE! Maybe you need to see your code again"<<endl;
            break;
        case 1:
            re = "Wow!That is AC!!!You are so smart!";
//            cout << "Wow!That is AC!!!You are so smart!"<<endl;
            break;
        case 2:
            re = "TLE! Your program run time is to more";
//            cout << "TLE! Your program run time is to more"<<endl;
            break;
        case 3:
            re = "WA!!Your program runs result is not same as anser!!!(Be careful!!!Otherwise you will see me again) *\(O_O)/*";
//            cout << "WA!!Your program runs result is not same as anser!!!(Be careful!!!Otherwise you will see me again) *\(O_O)/*"<<endl;
            break;
        case 4:
            re = "RE!!Maybe some bug in your code but it can be compile";
//            cout << "RE!!Maybe some bug in your code but it con be compile"<<endl;
            break;
        case 5:
            re = "SE!!WTF! Please tell manager the problem";
//            cout << "SE!!WTF! Please tell manager the problem"<<endl;
            break;
        }
        time_t now = time(0);
        char* dt = ctime(&now);
        file << dt << endl;
        file << re << endl;
        file.close();
    return re;
}