#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
const int MAX = 100;
int n,m;
int display_matrix(int matrix[MAX][MAX])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<matrix[i][j];
        }
    }
}
int main()
{
    
    int i,j,k;
    int available[MAX],allocation[MAX][MAX],need[MAX][MAX],maxi[MAX][MAX];
    int f[MAX],ans[MAX],idx=0;
    int traffic_zone[MAX], travel_mode[MAX], time_taken[MAX], redirect_path[MAX];
    int current_zone = 0, current_mode = 0, current_time = 0, current_path = 0;
    string colors[] = {"RED", "GREEN", "YELLOW"};
    cout<<"Enter number of processes: ";
    cin>>n;
    cout<<"Enter number of resources: ";
    cin>>m;
    cout<<"Enter the available resources: ";
    for(i=0;i<m;i++)
        cin>>available[i];
    cout<<"Enter the allocation matrix: ";
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>allocation[i][j];
    cout<<"Enter the maximum matrix: ";
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>maxi[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j]=maxi[i][j]-allocation[i][j];
    cout<<"the initial allocation is:"<<display_matrix(allocation)<<endl;
    cout<<"the maximum matrix is:"<<display_matrix(maxi)<<endl;
    int x=0;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                int flag=0;
                for(j=0;j<m;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    ans[idx++]=i;
                    for(x=0;x<m;x++)
                        available[x]+=allocation[i][x];
                    f[i]=1;
                }
            }
        }
        if(k == 0) {
            current_zone = 1;
            current_mode = 1;
            current_time = 60;
            current_path = 1;
        } else if(k == n/2) {
            current_zone = 2;
            current_mode = 2;
            current_time = 90;
            current_path = 2;
        } else {
            current_zone = 3;
            current_mode = 1;
            current_time = 120;
            current_path = 3;
        }
        
        cout<<"Process "<<k+1<<" is in Traffic Zone "<<current_zone<<" with Travel Mode "<<current_mode<<endl;
        cout<<"The Traffic Signal is "<<colors[current_mode-1]<<" for "<<current_time<<" seconds."<<endl;
        cout<<"The Redirect Path is "<<current_path<<"."<<endl;
    }
    int flag=0;
    for(i=0;i<n;i++){
        if(f[i]==0){
            cout<<"The system is in dead lock"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"The system is in safe state:"<<endl;
    }
    cout<<"The safe sequence is: ";
    for(i=0;i<n-1;i++)
        cout<<ans[i]<<"-->";
    cout<<ans[n-1]<<endl;
    return 0;
}