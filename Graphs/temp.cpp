#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define all(x) (x).begin(),(x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long int ll;

using namespace std;

ll gcd(ll a, ll b)
{
    if(a == 0)
    {
        return b;
    }
    return gcd(b%a, a);
}

int isPrime(int n){
    int i;

    if (n==2)
        return 1;

    if (n%2==0)
        return 0;

    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;

    return 1;
}

const int N = 200100;

vector<ll> tree[N], weight(N);
int visited[N];
int sol[N];

void dfs(int node, vector<ll> v)
{
    visited[node] = 1;
    v.pb(node);
    for(int x : tree[node])
    {
        if(visited[x] == 1)
        {
            continue;
        }
        dfs(x, v);
    }


    if(v.size() == 1)
    {
        sol[node] = -1;
    }
    else
    {
        // cout << "NODE : " << node << " WEIGHT : " << weight[node] << '\n';
        // for(int i = 0; i < v.size(); ++i)
        // {
        //     cout << v[i] << ' ';
        // }
        // cout << '\n';
        for(int i = v.size() - 2; i >= 0; --i)
        {
            if(gcd(weight[node], weight[v[i]]) == 1)
            {
                //cout << "Here : " << weight[node] << ' ' << weight[v[i]] << '\n';
                sol[node] = v[i];
                break;
            }

        }
        if(sol[node] == 0)
        {
            sol[node] = -1;
        }


    }
}

int main() {

    NFS
    int t = 1;
    //cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        for(int i = 1; i <= n; ++i)
        {
            cin >> weight[i];
        }

        for(int i = 0; i < n-1; ++i)
        {
            int u, v;
            cin >> u >> v;
            tree[u].pb(v);
            tree[v].pb(u);
        }

        vector<ll> v;
        dfs(1, v);

        for(int i = 1; i <= n; ++i)
        {
            cout << sol[i] << ' ';
        }
        cout << '\n';



    }
	return 0;

}
