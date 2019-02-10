#include "struct.h"

void restart (Problem problem[],People people[],string *address,int *all_pro,int *all_peo);
bool input (People people[],Problem problem[],People* now_peo,Problem* now_pro,string address,int all_pro,int all_peo);
void solve (Problem problem[],People people[],Problem now_pro,People now_peo,string address,int all_pro,int all_peo);
string change(int result);
