#include <iostream>
#include <cmath>
using namespace std;
void releaseMemory(double *pathLen, double **d, int **s, int *count, int n );                 //清除動態配置之記憶體 
int isNeighbor(int a, int b, int **s, int len);                                 
int main()
{
    int n = 0 ,m = 0, k = 0, nodeCnt=0, num=0;                                          
    cin >> n >> m >> k;
    int *u = new int [m], *v = new int [m];
    int **s = new int *[n+1], *a=new int [m], *count=new int [n+1];
    double *pathLen = new double [k], **d = new double *[n+1], *dt = new double [m];
    for (int i = 0; i < m; i++) 
    {
        cin >> u[i] >> v[i] >> dt[i];
    }
    for (int i=1; i<n+1; i++)
    {
        count[i] = 0;
        for(int j=0; j<m; j++ )
        {
            if(u[j] == i)
            {
                a[count[i]]=j;
                count[i]++;
            }
        }
        d[i]=new double [count[i]];
        s[i]=new int [count[i]];
        for (int j=0;j<count[i];j++)
        {
            d[i][j]=dt[a[j]];
            s[i][j]=v[a[j]];
            //cout << i<<" "<< s[i][j]<<" "<<d[i][j]<<endl;
        }
    }
    delete [] u;
    delete [] dt;
    delete [] v;
    delete [] a;
       
    for (int i = 0; i < k; i++)
    {
        //bool first=true;
        //int skip=0;
        cin >> nodeCnt;
        int *x = new int [nodeCnt];
        double *pass = new double [nodeCnt];
        for (int j = 0; j < nodeCnt; j++)
        {
            cin >> x[j];
        }
        pathLen[i] = 0;
        for (int j = 0; j < nodeCnt - 1; j++)
        {
            num=isNeighbor(x[j],x[j+1],s,count[x[j]]);
            if (num == -1)
            {
                bool NR=true;
                for (int l = 1; l < nodeCnt; l++)
                {
                    if (l!=j+1)
                    {
                        if (x[l] == x[j+1])
                        {
                            pathLen[i]=pass[l-1];
                            NR=false;
                            break;
                        }
                    }
                }
                if (NR)
                {
                    pathLen[i]=-1;
                    break;  
                }
                 
            }
            else
            {
                pathLen[i] += d[x[j]][num];
                pass[j] = pathLen[i];
                for (int l = 1; l < j+1; l++)
                {
                    if (x[l]==x[j+1])
                    {
                        if (pathLen[i]>pass[l-1])
                        {
                            pathLen[i]=pass[l-1];
                            pass[j] = pathLen[i];
                        }
                    }
                }
            }
        }
        delete [] pass;
        delete [] x;
    }
       
    for (int i = 0; i < k-1; i++)
        cout << pathLen[i] << " ";
    cout << pathLen[k-1];
       
    releaseMemory(pathLen, d, s, count, n+1);
    return 0;
}
   
void releaseMemory(double *pathLen, double **d, int **s, int *count, int n )
{
    delete [] pathLen;
    delete [] count;
    for (int i=1 ;i<n;i++)
    {
        delete [] d[i];
        delete [] s[i];
    }
    delete [] d;
    delete [] s;
}
   
int isNeighbor(int a, int b, int **s, int len)
{
    //cout<<len<<endl;
    for (int i = 0; i < len ;i++)
    {
        if (s[a][i]==b)
            return i;
    }
    return -1;
}
