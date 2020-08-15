#include <iostream>
#include <cmath>
using namespace std;
 
 
int main ()
{
    const int MAX_M=100; 
    int n=0,m=0;
    int x[MAX_M+1]={0},y[MAX_M+1]={0},r[MAX_M+1]={0},p[MAX_M+1]={0};
     
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>x[i];
    }
    for (int i=0;i<m;i++)
    {
        cin>>y[i];
    }
    for (int i=0;i<m;i++)
    {
        cin>>r[i];
    }
    for (int i=0;i<m;i++)
    {
        cin>>p[i];
    }
    double an=-99999,x1=0,y1=0;
    for (int k=0;k<m;k++)
    {
        for (int i=-5;i<6;i++)
        {
        	if ((x[k]+i)>n+1)
        		continue;
            for (int j=-5;j<6;j++)
            {   
            	if ((y[k]+j)>n+1)
        			continue;
                double temp1=0;
                for(int l=0;l<m;l++)
                {
                    double temp2=0;
                    temp2=p[l]*(r[l]-sqrt((x[l]-(x[k]+i))*(x[l]-(x[k]+i))+(y[l]-(y[k]+j))*(y[l]-(y[k]+j))))/r[l];
                    if (temp2>0)
                        temp1+=temp2;
                }
               // cout<<x[k]+i<<" "<<y[k]+j<<" "<<temp1<<endl;
                if (temp1>an)
                {
                    an=temp1;
                    x1=x[k]+i;
                    y1=y[k]+j;
                }
                else if (abs(temp1-an)<1e-5)
                {
                    if (x1>x[k])
                    {
                        an=temp1;
                        x1=x[k]+i;
                        y1=y[k]+j;
                    }
                    else if(x1==x[k])
                    {
                        if (y1>y[k])
                        {
                            an=temp1;
                            x1=x[k]+i;
                            y1=y[k]+j;
                        }
                    }
                }
            }
        }
    }
    cout<<x1<<" "<<y1;
     
    return 0;
}
