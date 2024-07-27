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




int main()
{
    setIO("traffic");
    int n;
    cin >> n;
    vector<string>state;
    vector<pair<int,int>>period;
 
    string st;
    int a,b;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> st >> a >> b;
        state.pb(st);
        period.pb({a,b});
    }

    a = 0, b = OO;

    for(int i = n-1 ; i >= 0 ; i--)
    {
        if(state[i] == "none")
        {
            a = max(a, period[i].f);
            b = min(b , period[i].s);
        }
        else if(state[i] == "on")
        {
            b -= period[i].f;
            a -= period[i].s;
			a = max(0, a);
        }
        else
        {
            a += period[i].f;
            b += period[i].s;
        }
    }

    cout << a << " " << b << '\n';

    a = 0, b = OO;

    
    for(int i = 0 ; i < n ; i++)
    {
        if(state[i] == "none")
        {
            a = max(a, period[i].f);
            b = min(b , period[i].s);
        }
        else if(state[i] == "on")
        {
            a += period[i].f;
            b += period[i].s;
        }
        else
        {
            b -= period[i].f;
            a -= period[i].s;
			a = max(0, a);        }
    }

    cout << a << " " << b;
    return 0;
}