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
    setIO("cownomics");
    
    int N,M;
    cin >> N >> M;

    vector<string> spot_cow(N);
    vector<string> plain_cow(N);

    for(auto &cow : spot_cow) cin >> cow;
    for(auto &cow : plain_cow) cin >> cow;

    map<char,int> m;

    int result = 0;

    for(int i = 0 ; i < M ;i++)
    {
        m.clear();

        for(int j = 0 ; j < N ; j++)
        {
            m[spot_cow[j][i]] = true;
        }

        bool flag = true;
        for(int j = 0 ; j < N ; j++)
        {

            if(m[plain_cow[j][i]] == true)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            result++;
        }
    }    

    cout << result;
    return 0;
}