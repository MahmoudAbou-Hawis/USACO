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
using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD = 1e9 + 7, OO = 0x3f3f3f3f;
const long long int LOO = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
const int N = 1e5 + 7;

void setIO(string name = "")
{
    Code By Abou_Hawis 
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

map<string,int> score;


int get_highScore()
{
    map<int,int>h;
    int i = 1;
    int mx = 0;
    for(auto &[cow, sc] : score)
    {
        mx = max(mx, sc);
        h[sc] += i;
        i++;
        if(i == 3) i = 15;
    }
    return h[mx];
}

int main()
{
    setIO("measurement");
    int n;
    cin >> n;
    score["Bessie"] = 7 ;
    score["Elsie"] = 7;
    score["Mildred"] = 7;


    int cnt = 0;

    int cur = 18;

    string name;
    int day,delta;

    vector<pair<int,pair<string,int>>> v;

    for(int i = 0 ; i < n; i++)
    {
        cin >> day >> name >> delta;
        v.pb({day,{name,delta}});
    }

    sort(all(v));

    for(auto &[day , cow] : v)
    {
        auto& [name, change] = cow;
        score[name] += change;
        int nw = get_highScore();
        if(nw != cur)
        {
            cnt++;
            cur = nw;
        }

    }
    cout << cnt ;

    return 0;
}