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


bool intersection(int a , int b)
{
    return (b < a);
}

int main()
{
    setIO("blist");
    int n;
    cin >> n;
    vector<tuple<int,int,int>>times;
    int st,t,total;
    for(int i = 0 ; i < n; i++)
    {
        cin >> st >> t >> total;
        tuple<int, int, int> myTuple = make_tuple(st, t, total);
        times.push_back(myTuple);
    }
    sort(all(times));
    int remining = 0;
    int tot = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int free = tot;
        auto &[d , e ,fr] = times[i];
        for(int j = i -1 ; j >= 0 ; j--)
        {
            auto &[a , b ,c ] = times[j];
            if(b >= d)
            {
                free -= c;
            }
        }
        tot += max(0,fr - free);
    }
    cout << tot;
    return 0;
}