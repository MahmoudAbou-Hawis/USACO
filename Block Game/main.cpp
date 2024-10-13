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
    setIO("blocks");

    int n;
    cin >> n;

    string a,b;

    vector<int>v(26);

    int freq[27];

    int freq2[27];

    for(int i = 0 ;i < n ; i++)
    {
       cin >> a >> b;
       memset(freq,0,sizeof(freq));      
       memset(freq2,0,sizeof(freq2));

       for(int j = 0 ; j < a.size() ; j++)
       {
            freq[a[j] - 'a']++;     
       }
       for(int j = 0 ; j < b.size() ; j++)
       {
            freq2[b[j] - 'a']++;     
       }

       for(int j = 0 ; j < 27 ; j++)
       {
            v[j] += max(freq[j], freq2[j]);
       }
    }

    for(auto &i : v)
    {
        cout << i << '\n';
    }
    return 0;
}