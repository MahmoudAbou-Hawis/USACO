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
    Code By Abou_Hawis if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("cownomics");
    int N, M;
    cin >> N >> M;
    vector<string> gens(2 * N);
    ll cnt = 0;
    for (int i = 0; i < 2 * N; i++)
    {
        cin >> gens[i];
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            for (int e = j + 1; e < M; e++)
            {
                unordered_map<string,bool>temp;
                string CowGen = "";
                for (int idx = 0; idx < N; idx++)
                {
                    CowGen = "";
                    CowGen += gens[idx][i];
                    CowGen += gens[idx][j];
                    CowGen += gens[idx][e];
                    temp[CowGen] = 1;
                }
                bool flag = true;
                for (int idx = 0; idx < N; idx++)
                {
                    CowGen = "";
                    CowGen += gens[idx + N][i];
                    CowGen += gens[idx + N][j];
                    CowGen += gens[idx + N][e];
                    if (temp[CowGen])
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            }
        }
    }
    cout << cnt ;
    return 0;
}