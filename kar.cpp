#include<stdio.h>
int main()
{
	int safe_seq[5];
	int alloc[][3]={{0,1,0},{2, 0, 0}, {3, 0, 2},{2, 1, 1},{0, 0, 2}};
	int max_need[][3]={{7, 5, 3},{3, 2, 2},{9, 0, 2},{2, 2, 2},{4, 3, 3}}; 
	int remain_need[5][3];
	int avail[]={3,3,2};
	int a1[3];
	int complete[5]={0};
	int l=1;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			remain_need[i][j]=max_need[i][j]-alloc[i][j];
		}
	}
	for(int i=0;i<3;i++)
	{
		a1[i]=avail[i];
	}
	int count=0;
	while(count<5)
	{
		bool check =false;
		for(int i=0;i<5;i++)
		{
			int j;
			if(complete[i]==0)
			{
			for(j=0;j<3;j++)
			{
				if(remain_need[i][j]>a1[j])
				{
					break;
				}
			}
			if(j==3)
			{
				for(int k=0;k<3;k++)
				{
					a1[k]=a1[k]+alloc[i][k];
				}
				check=true;
				complete[i]=1;
				safe_seq[count++]=i;
					
			}
			
		}
	}
		if(check==false)
		{
			printf("dead lock /n");
			l=0;
		}
		
		
	}
	if(l!=0)
	{
	printf("system is in safe state\n");
	for(int i=0;i<5;i++)
	{
		printf("p%d",safe_seq[i]);
		printf(" ");
	}
}	
}
