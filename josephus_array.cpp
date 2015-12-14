#include<iostream>
class  joseph_circle
{
public:
	int circle[100];
	int n;

	joseph_circle(int num)
		:n(num)
	{}
	void eliminate(int step)
	{
		int i=0;
		while(n-1)
		{
			i=i+step-1;
			if(i>=n)
			{
				i=0+i-n;
			}
			std::cout<<"deleting:"<<circle[i]<<std::endl;
			n--;
			for(int j=i;j<n;j++)
			{
				circle[j]=circle[j+1];
			}
			output();		
		}
	}
	void output()
	{
		for(int i=0;i<n;i++)
			std::cout<<circle[i]<<" ";
		std::cout<<std::endl;
	}

};
int main()
{
	joseph_circle circle(20);
	for(int i=0;i<circle.n;i++)
	{
		circle.circle[i]=i;
	}
	circle.eliminate(3);

	return 0;
}