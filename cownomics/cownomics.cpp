#include <bits/stdc++.h>
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define So_Far cout.tie(0);
#define fi(i,s,e) for(int i =s;i<e;i++)
#define fd(i,e,s) for(int i=e;i>=s;i--)
using namespace std;
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
 
void setIO(string name = "") {
    Code By So_Far
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}
int main()
{
    setIO("cownomics");
    int n, len;
    cin >> n >> len;
    vector<string> spot_cows(n);
    vector<string> plain_cows(n);

    for(auto &i : spot_cows)
    {
        cin >> i;
    }

    for(auto &i : plain_cows)
    {
        cin >> i;
    }
    int result = 0;
    unordered_map<string,int> geno;
    for(int i = 0 ; i < len ; i++)
    {
        for(int j = i +1 ; j < len ; j++)
        {
            for(int k = j +1 ; k < len ; k++)
            {
                for(int m = 0 ; m < n ; m++)
                {
                    geno[string(1 ,spot_cows[m][i] )+ spot_cows[m][j] + spot_cows[m][k]]++;
                }

                bool flag = true;
                for(int m = 0 ; m < n ; m++)
                {
                    if(geno[string(1 ,plain_cows[m][i] )+ plain_cows[m][j] + plain_cows[m][k]] > 0)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    result++;
                }
                geno.clear();
            }
        }
    }

    cout << result;
    return 0;
}