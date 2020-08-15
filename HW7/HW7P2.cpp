#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n=0,m=0,k=0,maxk=0,mink=0;
    double len=0,max=0,min=999999;
    cin>>n>>m>>k;
    
    int *x=new int[m], *y=new int[m], *r=new int[m], *p=new int[m];
    int *xs=new int[k], *ys=new int[k], *xt=new int[k], *yt=new int[k];
	double *RiskSum=new double[k];
	for (int i=0;i<k;i++)
	{
		RiskSum[i]=0;
	}
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
    for (int i=0;i<k;i++)
    {
        cin>>xs[i]>>ys[i]>>xt[i]>>yt[i];
    }
    for(int i=0;i<k;i++)
    {
    	len=sqrt(pow(xt[i]-xs[i],2)+pow(yt[i]-ys[i],2));
    	int seg=static_cast <int>(len);
		if (len==seg)
			seg--; 
    	double *xseg=new double[seg], *yseg=new double[seg];
    	for (int j=0;j<seg;j++)
    	{
    		double temp1=0;
    		xseg[j]=((j+1)*xt[i]+(len-(j+1))*xs[i])/len;
    		yseg[j]=((j+1)*yt[i]+(len-(j+1))*ys[i])/len;
    		for (int l=0;l<m;l++)
    		{
    			double temp2=p[l]*(r[l]-sqrt(pow(x[l]-xseg[j],2)+pow(y[l]-yseg[j],2)))/r[l];
    			if (temp2>0)
    				temp1+=temp2;
			}
			RiskSum[i]+=temp1;
			
		}
		if (max<RiskSum[i])
		{
			max=RiskSum[i];
			maxk=i+1;
		}
		if (min>RiskSum[i])
		{
			min=RiskSum[i];
			mink=i+1;
		}
		//cout<<mink<<" "<<maxk<<endl;
		//cout<<i<<" "<<RiskSum[i]<<endl;
	}
    cout<<mink<<" "<<maxk;
	return 0;
}
