#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printgraph(vector<int>adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            cout << it <<" ";
        }
        cout <<endl;
    }
}
void bfs(vector<int>adj[],int v)
{
    vector<int>bfs;
    vector<int>vis(v,0);
    queue<int>q;
    q.push(0);
    vis[0]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
    for(auto it:bfs)
    {
        cout << it << " ";
    }
}

 void dfs(int node,vector<int>&vis)
int main()
{
    int v;
    cin >> v;
    vector<int>adj[v];
    int m,n;
    for(int i=0;i<v;i++)
    {
        cin >>m >> n;
        add_edge(adj,m,n);
    }
    // printgraph(adj,v);
    bfs(adj,v);
    
}