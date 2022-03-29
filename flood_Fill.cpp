class Solution {
public:
    void dfs(vector<vector<int>>&image,int sr,int sc,int col,int newColor)
    {
        if(image[sr][sc]==col)
        {
            image[sr][sc]=newColor;
            if(sr>=1)dfs(image,sr-1,sc,col,newColor);
            if(sc>=1)dfs(image,sr,sc-1,col,newColor);
            if(sr+1<image.size())dfs(image,sr+1,sc,col,newColor);
            if(sc+1<image[0].size())dfs(image,sr,sc+1,col,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int col=image[sr][sc];
        if(col!=newColor)
        {
            dfs(image,sr,sc,col,newColor);
        }
        return image;
        
        
    }
};