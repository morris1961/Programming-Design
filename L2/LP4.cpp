#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x1=0,x2=0,x3=0,y1=0,y2=0,y3=0,a=0,b=0;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	for (a=0;a!=6;a++)
	{
		if((x1==a)||(x2==a)||(x3==a))
		continue;
		else
		{
			for(b=0;b!=6;b++)
			{
				if((y1==b)||(y2==b)||(y3==b))
				continue;
				else
				{
					if((abs(a-x1)!=abs(b-y1))&&
						(abs(a-x2)!=abs(b-y2))&&
						(abs(a-x3)!=abs(b-y3)))
					{
						cout<<a<<" ";
						cout<<b<<"\n";
					}
				}
			}
		}
	}
	return 0 ;
}
