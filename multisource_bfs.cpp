class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return -1;
        int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    q.push(pair<int,int>({i,j}));
                }
            }
        }
        if(q.size()==0 || q.size()==grid.size()*grid[0].size())
            return -1;
        int level=-1;
        while(!q.empty())
        {
            int size =q.size();
            level++;
            while(size--){
                pair<int,int>arr = q.front();
                q.pop();
                int x = arr.first;
                int y = arr.second;
                
                for(int i=0;i<4;i++){
                    int nx = x+dis[i][0];
                    int ny = y+dis[i][1];
                    
                    if((nx<0 or nx>=grid.size()) or (ny<0 or ny>=grid[0].size()) or grid[nx][ny]==1)
                        continue;
                    q.push({nx,ny});
                    grid[nx][ny]=1;
                }
            }
        }
        return level;
    }
};