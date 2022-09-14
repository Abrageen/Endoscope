#include <iostream>

using namespace std;

int dist=0;

int issafe(int arr[][50], int cx, int cy, int n, int m)
{
    if(cx>=0 && cx<n && cy>=0 && cy<m && arr[cx][cy]!=0)
        return 1;
    else return 0;
}

void solve(int arr[][50], int vis[][50], int ht, int wd, int cx, int cy, int l)
{
    int temp=arr[cx][cy];
    if(l<0)
        return;
    dist++;
    vis[cx][cy]=1;
    cout<<cx<<"  "<<cy<<" "<<arr[cx][cy]<<endl;
    switch(arr[cx][cy])
    {
    case 1:
        {
            cout<<"ENtered"<<endl;
            //cout<<cx<<" "<<cy<<endl;
            for(int i=0 ; i<4 ; i++)
            {
                switch(i)
                {
                case 0:
                    {
                        if(issafe(arr,cx+1,cy,ht,wd) && vis[cx+1][cy]==0)
                            solve(arr,vis,ht,wd,cx+1,cy,l-1);
                    }
                case 1:
                    {
                        if(issafe(arr,cx-1,cy,ht,wd) && vis[cx-1][cy]==0)
                            solve(arr,vis,ht,wd,cx-1,cy,l-1);
                    }
                case 2:
                    {
                        if(issafe(arr,cx,cy-1,ht,wd) && vis[cx][cy-1]==0)
                            solve(arr,vis,ht,wd,cx,cy-1,l-1);
                    }
                case 4:
                    {
                        if(issafe(arr,cx,cy+1,ht,wd) && (vis[cx][cy+1]==0))
                            solve(arr,vis,ht,wd,cx,cy+1,l-1);
                    }
                }
            }
        }
        case 2:
        {
            if(issafe(arr,cx+1,cy,ht,wd) && (vis[cx+1][cy]==0))
                            solve(arr,vis,ht,wd,cx+1,cy,l-1);
            if(issafe(arr,cx-1,cy,ht,wd) && (vis[cx-1][cy]==0))
                            solve(arr,vis,ht,wd,cx-1,cy,l-1);
        }
        case 3:
        {
            if(issafe(arr,cx,cy+1,ht,wd) && (vis[cx][cy+1]==0))
                            solve(arr,vis,ht,wd,cx,cy+1,l-1);
            if(issafe(arr,cx,cy-1,ht,wd) && (vis[cx][cy-1]==0))
                            solve(arr,vis,ht,wd,cx,cy-1,l-1);
        }
        case 4:
        {
            if(issafe(arr,cx-1,cy,ht,wd) && (vis[cx-1][cy]==0))
                            solve(arr,vis,ht,wd,cx-1,cy,l-1);
            if(issafe(arr,cx,cy+1,ht,wd) && (vis[cx][cy+1]==0))
                            solve(arr,vis,ht,wd,cx,cy+1,l-1);
        }
        case 5:
        {
            if(issafe(arr,cx+1,cy,ht,wd) && (vis[cx+1][cy]==0))
                            solve(arr,vis,ht,wd,cx+1,cy,l-1);
            if(issafe(arr,cx,cy+1,ht,wd) && (vis[cx][cy+1]==0))
                            solve(arr,vis,ht,wd,cx,cy+1,l-1);
        }
        case 6:
        {
            if(issafe(arr,cx+1,cy,ht,wd) && (vis[cx+1][cy]==0))
                            solve(arr,vis,ht,wd,cx+1,cy,l-1);
            if(issafe(arr,cx,cy-1,ht,wd) && (vis[cx][cy-1]==0))
                            solve(arr,vis,ht,wd,cx,cy-1,l-1);
        }
        case 7:
        {
            if(issafe(arr,cx-1,cy,ht,wd) && (vis[cx-1][cy]==0))
                            solve(arr,vis,ht,wd,cx-1,cy,l-1);
            if(issafe(arr,cx,cy-1,ht,wd) && (vis[cx][cy-1]==0))
                            solve(arr,vis,ht,wd,cx,cy-1,l-1);
        }
    }
}

int main()
{
    int t,n,m,r,c,l;
    cin>>t;
    while(t--)
    {
       int arr[50][50]={0};
       int visited[50][50]={0};
       dist=0;
       cin>>n>>m>>r>>c>>l;
       for(int i=0 ; i<n ; i++)
       {
           for(int j=0 ; j<m ; j++)
           {
               cin>>arr[i][j];
           }
       }
       solve(arr,visited,n,m,r,c,l);
       cout<<"DIstance covered: "<<dist;
    }
    return 0;
}
