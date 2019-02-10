#include<bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long int
#define F first
#define S second
#define pi pair<int,int>
struct xy{
    int x = 0,y = 0;
};
int n = 8,bone = 1,win = 0,flag = 0;
char s[101][101] = {};
int bs[101][101] = {};
int d[8][2]={{0,1},{1,0},{1,-1},{1,1},{-1,-1},{-1,0},{0,-1},{-1,1}};
void reset(){
    win = flag = 0;
    vector<xy> ve;
    for(int i = 1;i<=n;i++){
        for(int q = 1;q<=n;q++){
            s[i][q]= '.';
            bs[i][q] = 1;
            xy now;
            now.x = i,now.y = q;
            ve.push_back(now);
        }
    }
    while(bone--){
        int a = rand()%ve.size();
        bs[ve[a].x][ve[a].y] = 2;
        ve.erase(ve.begin()+a);
    }
}
void printbs(void){
    for(int i=1;i<=n;i++){
        for(int q=1;q<=n;q++){
            cout << bs[i][q];
        }
        cout << endl;
    }
}
void print(void){
    for(int i=1;i<=n;i++){
        for(int q=1;q<=n;q++){
            cout << s[i][q];
        }
        cout << endl;
    }
}
bool judge(int x,int y,int ty){
    if(ty == 1){
        if(s[x][y] != '.'){
            cout << "�o�̤��ॴ�}\n";
        }else if(bs[x][y] == 2){
            for(int i=1;i<=n;i++){
                for(int q=1;q<=n;q++){
                    if(bs[i][q]==2){
                        s[i][q]='*';
                    }
                }
            }
            return false;
        }else{
            xy now;
            now.x=x,now.y=y;
            queue<xy> qu;
            qu.push(now);
            while(!qu.empty()){
                now=qu.front();
                qu.pop();
                int all=0;
                for(int i=0;i<8;i++){
                    if(bs[now.x+d[i][0]][now.y+d[i][1]]==2){
                        all++;
                    }
                }
                if(all!=0){
                    s[now.x][now.y] = all+'0';
                    continue;
                }else{
                    s[now.x][now.y] = '_';
                }
                for(int i=0;i<8;i++){
                    if(bs[now.x+d[i][0]][now.y+d[i][1]] == 1&&s[now.x+d[i][0]][now.y+d[i][1]] == '.'){
                        xy will;
                        will.x = now.x+d[i][0],will.y = now.y+d[i][1];
                        qu.push(will);
                    }
                }
            }
        }
    }else if(ty == 2){
        if (flag == bone){
            cout << "���u�S���o��h����\n";
        }else if(s[x][y] == '.'){
            s[x][y] = '+';
            flag++;
        }else if(s[x][y]=='+'){
            cout << "�o�̤w�g�Q���L�F\n";
        }else{
            cout << "�o�̤��ഡ�X\n";
        }
    }else if(ty == 3){
        if(s[x][y]!='+'){
            cout << "�S���X�l�i�H�M�z��\n";
        }else{
            s[x][y] = '.';
            flag--;
        }
    }
    print();
    for(int i=1;i<=n;i++){
        bool st=0;
        for(int q=1;q<=n;q++){
            if(bs[i][q] == 2&&s[i][q] != '+'){
                st=1;
                break;
            }else if(bs[i][q] == 1&&s[i][q] != '.'){
                st=1;
                break;
            }
        }
        if(st)break;
        if(i==n){
            win = 1;
            return false;
        }
    }
    return true;
}
int chNum(string inp){
    int re=0;
    for(int i=0;i<inp.size();i++){
        re*=10;
        re+=inp[i]-'0';
    }
    return re;
}
int input(int mi,int ma){
    string inp;
    getline(cin,inp);
    for(int i=0;i<inp.size();i++){
        if(inp[i]<'0'||inp[i]>'9'){
            cout << "wrong input!Please enter again!\n";
            return input(mi,ma);
        }
    }
    if(inp.size() == 0){
        cout << "wrong input!Please enter again!\n";
        return input(mi,ma);
    }
    int ans=chNum(inp);
    if(ans>=mi&&ans<=ma){
        return ans;
    }else{
        cout << "wrong range!!Please enter again!\n";
        return input(mi,ma);
    }
}
int main(){
    srand(time(NULL));
    while(true){
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "~                 �w��C���m�a�p               ~\n";
        cout << "~�C���W�h����:�A�����N�Ҧ����Ů氵���}�άO���X ~\n";
        cout << "~���O����N�X����D�a�p����m�άO���}�a�p����m~\n";
        cout << "~�C�ӼƦr�N��P��8�椺���X�Ӧa�p               ~\n";
        cout << "~�Ÿ�����:\"+\"�N��X�l,\"_\"�N��S�F��,\".\"�N      ~\n";
        cout << "~���}�o\"*\"�N��a�p                           ~\n";
        cout << "~��J����:����#include<bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long int
#define F first
#define S second
#define pi pair<int,int>
struct xy{
    int x = 0,y = 0;
};
int n = 8,bone = 1,win = 0,flag = 0;
char s[101][101] = {};
int bs[101][101] = {};
int d[8][2]={{0,1},{1,0},{1,-1},{1,1},{-1,-1},{-1,0},{0,-1},{-1,1}};
void reset(){
    win = flag = 0;
    vector<xy> ve;
    for(int i = 1;i<=n;i++){
        for(int q = 1;q<=n;q++){
            s[i][q]= '.';
            bs[i][q] = 1;
            xy now;
            now.x = i,now.y = q;
            ve.push_back(now);
        }
    }
    while(bone--){
        int a = rand()%ve.size();
        bs[ve[a].x][ve[a].y] = 2;
        ve.erase(ve.begin()+a);
    }
}
void printbs(void){
    for(int i=1;i<=n;i++){
        for(int q=1;q<=n;q++){
            cout << bs[i][q];
        }
        cout << endl;
    }
}
void print(void){
    for(int i=1;i<=n;i++){
        for(int q=1;q<=n;q++){
            cout << s[i][q];
        }
        cout << endl;
    }
}
bool judge(int x,int y,int ty){
    if(ty == 1){
        if(s[x][y] != '.'){
            cout << "�o�̤��ॴ�}\n";
        }else if(bs[x][y] == 2){
            for(int i=1;i<=n;i++){
                for(int q=1;q<=n;q++){
                    if(bs[i][q]==2){
                        s[i][q]='*';
                    }
                }
            }
            return false;
        }else{
            xy now;
            now.x=x,now.y=y;
            queue<xy> qu;
            qu.push(now);
            while(!qu.empty()){
                now=qu.front();
                qu.pop();
                int all=0;
                for(int i=0;i<8;i++){
                    if(bs[now.x+d[i][0]][now.y+d[i][1]]==2){
                        all++;
                    }
                }
                if(all!=0){
                    s[now.x][now.y] = all+'0';
                    continue;
                }else{
                    s[now.x][now.y] = '_';
                }
                for(int i=0;i<8;i++){
                    if(bs[now.x+d[i][0]][now.y+d[i][1]] == 1&&s[now.x+d[i][0]][now.y+d[i][1]] == '.'){
                        xy will;
                        will.x = now.x+d[i][0],will.y = now.y+d[i][1];
                        qu.push(will);
                    }
                }
            }
        }
    }else if(ty == 2){
        if (flag == bone){
            cout << "���u�S���o��h����\n";
        }else if(s[x][y] == '.'){
            s[x][y] = '+';
            flag++;
        }else if(s[x][y]=='+'){
            cout << "�o�̤w�g�Q���L�F\n";
        }else{
            cout << "�o�̤��ഡ�X\n";
        }
    }else if(ty == 3){
        if(s[x][y]!='+'){
            cout << "�S���X�l�i�H�M�z��\n";
        }else{
            s[x][y] = '.';
            flag--;
        }
    }
    print();
    for(int i=1;i<=n;i++){
        bool st=0;
        for(int q=1;q<=n;q++){
            if(bs[i][q] == 2&&s[i][q] != '+'){
                st=1;
                break;
            }else if(bs[i][q] == 1&&s[i][q] != '.'){
                st=1;
                break;
            }
        }
        if(st)break;
        if(i==n){
            win = 1;
            return false;
        }
    }
    return true;
}
int chNum(string inp){
    int re=0;
    for(int i=0;i<inp.size();i++){
        re*=10;
        re+=inp[i]-'0';
    }
    return re;
}
int input(int mi,int ma){
    string inp;
    getline(cin,inp);
    for(int i=0;i<inp.size();i++){
        if(inp[i]<'0'||inp[i]>'9'){
            cout << "wrong input!Please enter again!\n";
            return input(mi,ma);
        }
    }
    if(inp.size() == 0){
        cout << "wrong input!Please enter again!\n";
        return input(mi,ma);
    }
    int ans=chNum(inp);
    if(ans>=mi&&ans<=ma){
        return ans;
    }else{
        cout << "wrong range!!Please enter again!\n";
        return input(mi,ma);
    }
}
int main(){
    srand(time(NULL));
    while(true){
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "~                 �w��C���m�a�p               ~\n";
        cout << "~�C���W�h����:�A�����N�Ҧ����Ů氵���}�άO���X ~\n";
        cout << "~���O����N�X����D�a�p����m�άO���}�a�p����m~\n";
        cout << "~�C�ӼƦr�N��P��8�椺���X�Ӧa�p               ~\n";
        cout << "~�Ÿ�����:\"+\"�N��X�l,\"_\"�N��S�F��,\".\"�N      ~\n";
        cout << "~���}�o\"*\"�N��a�p                           ~\n";
        cout << "~��J����:���Ƭ�x��Ƭ�y,�@�ӼƦr��J���@��    ~\n";
        cout << "~                    ��������                  ~\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "�п�J�a�Ϥj�p(�̤j100*100�̤p1*1)\n";
        n = input(1,100);
        cout << "�п�J�a�p�ƶq�����j��1�M�p���`�Ů��\n";
        bone = input(1,n*n);
        reset();
//        printbs();
        int x,y,ty;
        printbs();
        do{
            cout << "�п�Jx�y��";
            x = input(1,n);
            cout << "�п�Jy�y��";
            y = input(1,n);
            cout << "�п�J�ʧ@:\n1:½�}\n2:���X\n3:�M���X�l\n";
            ty = input(1,3);
        }while(judge(x,y,ty));
        if(win == 1){
            print();
            cout << "���ߧAĹ�F\n";
        }else{
            print();
            cout << "Bone!!�A�z���F\n";
        }
        cout << "Do you want to play again 1:yes 0:no\n";
        if(!input(0,1)){
            return 0;
        }
    }
}
��x��Ƭ�y,�@�ӼƦr��J���@��    ~\n";
        cout << "~                    ��������                  ~\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "�п�J�a�Ϥj�p(�̤j100*100�̤p1*1)\n";
        n = input(1,100);
        cout << "�п�J�a�p�ƶq�����j��1�M�p���`�Ů��\n";
        bone = input(1,n*n);
        reset();
//        printbs();
        int x,y,ty;
        print();
        do{
            cout << "�п�Jx�y��";
            x = input(1,n);
            cout << "�п�Jy�y��";
            y = input(1,n);
            cout << "�п�J�ʧ@:\n1:½�}\n2:���X\n3:�M���X�l\n";
            ty = input(1,3);
        }while(judge(x,y,ty));
        if(win == 1){
            print();
            cout << "���ߧAĹ�F\n";
        }else{
            print();
            cout << "Bone!!�A�z���F\n";
        }
        cout << "Do you want to play again 1:yes 0:no\n";
        if(!input(0,1)){
            return 0;
        }
    }
}
