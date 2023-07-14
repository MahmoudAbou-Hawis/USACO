#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
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
const long long int MOD=1e9 + 7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
const int N = 1e5 + 7 ;

void setIO(string name = "") {
    Code By Abou_Hawis
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("gymnastics");
    int session_num, cow_num;
    cin >> session_num >> cow_num;
    vector<vector<int>>v(session_num,vector<int>(cow_num,0));
    for(int i = 0 ; i < session_num ; i++)
    {
        for(int j = 0 ; j < cow_num ; j++)
        {
            cin >> v[i][j];
        }
    }
    map<pi,int>better_pairs;
    for(int i = 0 ; i < session_num ; i++)
    {
        for(int j = 0 ; j < cow_num ; j++)
        {
            for(int e = j+1 ; e < cow_num ;e++)
            {
                better_pairs[{v[i][j] , v[i][e]}]++;
            }
        }
    }
    int cnt = 0;
    for(auto &i : better_pairs)
    {
        if(i.second == session_num)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}