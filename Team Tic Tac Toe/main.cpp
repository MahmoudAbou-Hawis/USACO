#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
using namespace std;
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int teams      = 0;
int individual = 0;
map<string,bool>m;
void check(map<char,bool>&M)
{
    string str;
        for(auto &i : M)
        {
            str+=i.f;
        }
        if(!m[str])
        {
            m[str] = 1;
            if(sz(str) == 1)individual++;
            else teams++;
        }
}
int main() {
    setIO("tttt");
    char grid[3][3];
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cin>>grid[i][j];
        }
    }
    map<char,bool>Rows;
    map<char,bool>Colms;
    map<char,bool>Diag0;
    map<char,bool>Diag1;
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ;j++)
        {
            Rows[grid[i][j]]  = 1;
            Colms[grid[j][i]] = 1;
            if(i == j)
            {
                Diag0[grid[i][j]] = 1;
            }
            if(i+j == 2)
            {
                Diag1[grid[i][j]] = 1;
            }
        }
        if(Rows.size() < 3 )
        {
            check(Rows);
        }
        if(Colms.size() < 3)
        {
            check(Colms);
        }
        Rows.clear();
        Colms.clear();
    }
    if(sz(Diag0) < 3 )
    {
        check(Diag0);
    }
    if(Diag1.size() < 3)
    {
        check(Diag1);
    }

    cout<<individual<<'\n'<<teams;
    return 0;
}
