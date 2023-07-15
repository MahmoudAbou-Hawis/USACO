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
    setIO("cownomics");
    int n, m;
    cin >> n >> m;
    int freq[m+1][28];
    memset(freq,0,sizeof freq);
    for(int i = 0 ; i < n ; i++)
    {
        string spotted_cow;
        cin >> spotted_cow;
        for(int e = 0 ; e < m ;e++)
        {
            freq[e][spotted_cow[e]-'A']++;
        }
    } 
    vector<string>Normal_Cows(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> Normal_Cows[i];
    }
    int cnt = 0;
    for(int row = 0 ; row < m ; row++)
    {
        bool good_loc = true;
        for(int Cow = 0 ; Cow < n && good_loc; Cow++)
        {
            if(freq[row][Normal_Cows[Cow][row] - 'A'])
            {
                good_loc = false;
            }
        }
        if(good_loc)
        {
            cnt++;
        } 
    }
    cout << cnt << '\n';
    return 0;
}