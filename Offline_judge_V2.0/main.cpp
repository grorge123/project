#include <iostream>
#include "fun.h"
using namespace std;
Problem problem[100];
People people[100];
string address;
int all_pro,all_peo;
int main(){
    restart(problem,people,&address,&all_pro,&all_peo);
    People now_peo;
    Problem now_pro;
    while(input(people,problem,&now_peo,&now_pro,address,all_pro,all_peo)){
        solve(problem,people,now_pro,now_peo,address,all_pro,all_peo);
    }
    return 0;
}

