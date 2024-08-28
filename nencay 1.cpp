#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int n,pa[N];
vector<int> adj[N];
set<int> leaf;
int bac[N];

void dfs(int u,int pr)
{
    pa[u] = pr;

    if(u && (int)adj[u].size()==1) leaf.insert(u);

    for(auto v : adj[u]) if(v!=pr)
    dfs(v,u);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        bac[v]++,bac[u]++;
    }
    dfs(0,0);

    while(!leaf.empty())
    {
        int u = *leaf.begin(); // dinh nho nhat
        leaf.erase(u);

        cout<<pa[u]<<" ";

        bac[pa[u]]--;

        if(pa[u] && bac[pa[u]]==1) leaf.insert(pa[u]);
    }
}
