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
    setIO("cbarn");
    
    int n;
    cin >> n;
    
    vector<int>v(n);

    long sum = 0;


    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    int idx = 0;

    int result = OO;

    for(int i = 0 ; i < n ; i++)
    {
        int temp = sum;
        int num = 0;
        for(int j = 0 ; j < n ; j++)
        {
            temp -= v[(idx + j)% n];
            num += temp;
        }
        idx++;
        result = min(result , num);
    }

    cout << result << '\n';
    
    return 0;
}