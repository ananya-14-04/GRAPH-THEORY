//https://www.spoj.com/problems/BUGLIFE/


#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
typedef signed long long ll;
 
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
} 
 
bool bfs(int src, vector<int> adj[], vector<int>&color) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                
                return false; 
            }
        }
    }
    return true; 
}
signed  main()
{ 
    init_code();
    
      ll t;
       cin >> t;
       for(int i=1;i<=t;i++)
        {
             int  a,b;
            cin >> a >> b;
            vector<int>adj[a+1];
            for(int j=0;j<b;j++)
            {
                int x,y;
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
            } 
            vector<int>color(a+1,-1);
            bool flg=true;
            for(int j=1;j<=a;j++)
            {
               
                if(color[j]==-1)
                {
                   
                    flg=bfs(j,adj,color);
                    if(flg==false)
                    break;
                
                }
                
            }
           
 
            cout << "Scenario #"<< i <<":"<<endl;
            if(flg==false)
            { 
                cout << "Suspicious bugs found!"<<endl;
 
            }
            else
                cout << "No suspicious bugs found!"<<endl;
 
        }
 
    return 0;
}