#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n=0,x=0,p1=0,p2=0,p3=0,day=1;
	cin>>n>>x>>p1>>p2>>p3;
	switch (n)
	{
		case 1:														//n=1���ɭ� 
		{
			int x1=0,y1=0;
			cin>>x1>>y1;
			x=x+x1;													//�[�� 
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R���
				{
					x=x-p2; 
				}
				for(int t=1;x>=p3&&t<=y1;t++)						//�R���Υ] 
				{
					x=x-p3;
				}
				cout<<x;
			}
			break;
		}
		case 2:														//n=2���ɭ� 
		{
			int x1=0,y1=0,x2=0,y2=0;
			cin>>x1>>y1>>x2>>y2;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
				cout<<x<<" ";
				day=day+1;											//�U�@�� 
				x=x+x2;												//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ]			
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
				cout<<x<<" ";
				}
			}
			break;
		}
		case 3:														//n=3���ɭ� 
		{
			int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0;
			cin>>x1>>y1>>x2>>y2>>x3>>y3;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@��
					x=x+x2;											//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x3;											//�[�� 
				}
				else if(day==3)										//�ĤT�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y3;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
				}
			}
			break;
		}
		case 4:														//n=4 
		{
			int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0;
			cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@��
					x=x+x2;											//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x3;											//�[�� 
				}
				else if(day==3)										//�ĤT�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y3;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x4;											//�[�� 
				}
				else if(day==4)										//�ĥ|�ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y4;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
				}
			}
			break;
		}
		case 5:														//n=5
		{
			int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0;
			cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@��
					x=x+x2;											//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x3;											//�[�� 
				}
				else if(day==3)										//�ĤT�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y3;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x4;											//�[�� 
				}
				else if(day==4)										//�ĥ|�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y4;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x5;											//�[��
				}
				else if(day==5)										//�Ĥ��ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y5;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
				}
			}
			break;
		}
		case 6:														//n=6
		{
			int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,x6=0,y6=0;
			cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@��
					x=x+x2;											//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x3;											//�[�� 
				}
				else if(day==3)										//�ĤT�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y3;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x4;											//�[�� 
				}
				else if(day==4)										//�ĥ|�ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y4;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x5;											//�[��
				}
				else if(day==5)										//�Ĥ��ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y5;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x6;											//�[��
				}
				else if(day==6)										//�Ĥ��ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y6;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
				}
			}
			break;
		}
		case 7:														//n=7
		{
			int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,x6=0,y6=0,x7=0,y7=0;
			cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6>>x7>>y7;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@��
					x=x+x2;											//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x3;											//�[�� 
				}
				else if(day==3)										//�ĤT�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y3;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x4;											//�[�� 
				}
				else if(day==4)										//�ĥ|�ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y4;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x5;											//�[��
				}
				else if(day==5)										//�Ĥ��ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y5;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x6;											//�[��
				}
				else if(day==6)										//�Ĥ��ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y6;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x7;											//�[��
				}
				else if(day==7)										//�ĤC�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y7;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
				}
			}
			break;
		}
		case 8:														//n=8
		{
			int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,x6=0,y6=0,x7=0,y7=0,x8=0,y8=0;
			cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6>>x7>>y7>>x8>>y8;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@��
					x=x+x2;											//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x3;											//�[�� 
				}
				else if(day==3)										//�ĤT�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y3;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x4;											//�[�� 
				}
				else if(day==4)										//�ĥ|�ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y4;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x5;											//�[��
				}
				else if(day==5)										//�Ĥ��ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y5;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x6;											//�[��
				}
				else if(day==6)										//�Ĥ��ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y6;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x7;											//�[��
				}
				else if(day==7)										//�ĤC�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y7;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x8;											//�[��
				}
				else if(day==8)										//�ĤK�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y8;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
				} 
			}
			break;
		}
		case 9:														//n=9
		{
			int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,x6=0,y6=0,x7=0,y7=0,x8=0,y8=0,x9=0,y9=0;
			cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6>>x7>>y7>>x8>>y8>>x9>>y9;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@��
					x=x+x2;											//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x3;											//�[�� 
				}
				else if(day==3)										//�ĤT�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y3;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x4;											//�[�� 
				}
				else if(day==4)										//�ĥ|�ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y4;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x5;											//�[��
				}
				else if(day==5)										//�Ĥ��ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y5;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x6;											//�[��
				}
				else if(day==6)										//�Ĥ��ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y6;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x7;											//�[��
				}
				else if(day==7)										//�ĤC�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y7;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x8;											//�[��
				}
				else if(day==8)										//�ĤK�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y8;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x9;											//�[��
				}
				else if(day==9) 									//�ĤE�ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y9;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
				} 
			}
			break;
		}
		case 10:
		{
			int x1=0,y1=0,x2=0,y2=0,x3=0,y3=0,x4=0,y4=0,x5=0,y5=0,x6=0,y6=0,x7=0,y7=0,x8=0,y8=0,x9=0,y9=0,x10=0,y10=0;
			cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6>>x7>>y7>>x8>>y8>>x9>>y9>>x10>>y10;
			x=x+x1;													//�[��
			for(int z=1;z<=n;z++)
			{
				if(x>=p1)											//�R����� 
				{
					x=x-p1;
				}
				if(x>=p2)											//�R��� 
				{
					x=x-p2;
				}
				if(day==1)											//�Ĥ@�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y1;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@��
					x=x+x2;											//�[�� 
				}
				else if(day==2)										//�ĤG�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y2;t++)
					{
						x=x-p3;
					}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x3;											//�[�� 
				}
				else if(day==3)										//�ĤT�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y3;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x4;											//�[�� 
				}
				else if(day==4)										//�ĥ|�ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y4;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x5;											//�[��
				}
				else if(day==5)										//�Ĥ��ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y5;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x6;											//�[��
				}
				else if(day==6)										//�Ĥ��ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y6;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x7;											//�[��
				}
				else if(day==7)										//�ĤC�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y7;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x8;											//�[��
				}
				else if(day==8)										//�ĤK�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y8;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x9;											//�[��
				}
				else if(day==9) 									//�ĤE�ѶR���Υ]
				{
					for(int t=1;x>=p3&&t<=y9;t++)
						{
							x=x-p3;
						}
					cout<<x<<" ";
					day=day+1;										//�U�@�� 
					x=x+x10;										//�[��
				}
				else if(day==10)									//�ĤQ�ѶR���Υ] 
				{
					for(int t=1;x>=p3&&t<=y10;t++)
						{
							x=x-p3;
						}
					cout<<x;
				} 
			}
			break;
		}
	}
	return 0 ;
}
