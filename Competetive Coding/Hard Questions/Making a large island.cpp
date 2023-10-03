class Solution {
public:
int par[1000001];
int siz[1000001];
vector<pair<int,int>>v={{0,1},{1,0},{-1,0},{0,-1}};
void make(int v)
{
par[v]=v;
siz[v]=1;
}
int find(int v)
{
if(par[v]==v)
{
return v;
}
return v=find(par[v]);
}
void unite(int x,int y)
{
x=find(x);
y=find(y);
if(x!=y)
{
if(siz[x]<siz[y])
{
par[x]=y;
siz[y]+=siz[x];
}
else
{
par[y]=x;
siz[x]+=siz[y];
}
}
}
bool isvalid(int x,int y,int n)
{
if(x>=0 && x<n && y>=0 && y<n)
{
return true;
}
else
{
return false;
}
}

    int largestIsland(vector<vector<int>>& grid) {
     int n=grid.size();
     int m=grid[0].size();
     int sum=0,k=0;
     for(int i=0;i<=n*n;i++)
     {
     make(i);
     }
     for(int i=0;i<n;i++)
     {
      for(int j=0;j<m;j++)
      {
      if(grid[i][j]==1)
      {
     for(auto it:v)
     {
     int x=it.first+i;
     int y=it.second+j;
     int r=i*n+j;
     if(isvalid(x,y,n) && grid[x][y]==1)
     {
      int c=x*n+y;
      unite(r,c);
      }
      }
     }
    }}
      for(int i=0;i<n;i++)
     {
      for(int j=0;j<m;j++)
      {
      set<int>s;
      if(grid[i][j]==0)
      {
        for(auto it:v)
        {
        int x=it.first+i;
        int y=it.second+j;
        int c=i*n+j;
        if(isvalid(x,y,n) && grid[x][y]==1)
        {
        int r=x*n+y;
        s.insert(find(r));//storing distict parents in all four directions.
        }
        }
        for(auto it=s.begin();it!=s.end();it++)
        {
        int p=*it;
        sum+=siz[p];//computing sum of size of all components for a    particular zero.
        }
        k=max(k,sum+1);
        sum=0;
      }}}
      for(int i=0;i<n*n;i++)
      {
      int p=find(i);
      k=max(k,siz[p]);
      }
      return k;
}};