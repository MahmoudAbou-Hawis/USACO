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

//0 4 1 5
void setIO(string name = "")
{
    Code By Abou_Hawis 
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool intersect(int x, int y, int x1, int y1)
{
    return ((x < x1 && y < y1 && x1 < y) || (x > x1 && y > y1 && x < y1));
}


int main()
{
    setIO("circlecross");
    string str;
    cin >> str;
    int counter = 0;
    vector<vector<int>> cows(26);
    for(int i = 0 ; i < sz(str) ; i++)
    {
        cows[str[i] - 'A'].pb(i);
    }
    for(int i = 0 ; i < 26 ;i++)
    {
        for(int j = i + 1 ; j < 26 ; j++)
        {
            counter += intersect(cows[i][0], cows[i][1],cows[j][0],cows[j][1]);
        }
    }
    cout << counter ;
    return 0;
}