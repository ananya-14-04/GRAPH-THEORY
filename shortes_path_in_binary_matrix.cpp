class Solution {
public:
    int n;
   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0)
            return -1;
        
        queue<pair<int,int>>q;
       vector<pair<int,int>>dirs = {{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
        
        q.push({0,0});
        
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
           
            if(p.first==n-1 && p.second==n-1)
                return grid[p.first][p.second]+1;
            
            for(auto it:dirs)
            {
                int x=p.first+it.first;
                int y=p.second+it.second;
                if(x>=0 && y>=0 && x<n && y<n && grid[x][y]==0)
                {
                    grid[x][y]=grid[p.first][p.second]+1;
                    q.push({x,y});
                }
            }
        }
        return -1;
    }
};