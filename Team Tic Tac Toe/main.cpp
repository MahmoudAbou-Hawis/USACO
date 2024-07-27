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
    setIO("tttt");

    vector<string>cows(3);

    for(int i = 0 ; i < 3 ; i++)
    {
        cin >> cows[i];
    }

    for(int i = 0 ; i < 3 ;i++)
    {
        string str = "";
        for(int j = 0 ; j < 3 ;j++)
        {
            str += cows[j][i];
        }
        cows.pb(str);
    }

    string diag1 = "";
    diag1 +=  cows[0][0]; 
    diag1 += cows[1][1];
    diag1+= cows[2][2];

    cows.pb(diag1);
    diag1 = "";
    diag1 +=  cows[0][2]; 
    diag1 += cows[1][1];
    diag1+= cows[2][0];

    cows.pb(diag1);

    map<string,bool>m;

    int ind = 0;
    int teams = 0;
    for(auto &i : cows)
    {
        set<char>st;
        string str = "";
        for(auto &ch : i)
        {
            st.emplace(ch);
        }
        for(auto &j : st)
        {
            str += j;
        }
        if(st.size() == 1 && m[str] == 0)
        {
            ind++;
            m[str] = 1;
        }  
        if(st.size() == 2 && m[str] == 0)
        {
            teams++;
            m[str] = 1;
        }
    }
    cout << ind <<  "\n" << teams;

    return 0;
}