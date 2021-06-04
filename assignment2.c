#include <stdio.h>

int point_value(int segment,char ring)
{
	int value;
	if(ring == 'S')
	{
		value = segment;
	}
	else if(ring == 'D')
	{
		value = segment * 2;
	}
	else if(ring == 'T')
	{
		value = segment * 3;
	}
	else if(ring == 'O')
	{
		value = 25;
	}
	else if(ring == 'I')
	{
		value = 50;
	}
	
	return value;
}

int remaining_value(int current,int target,int segment,char ring)
{
	int remaining;
	if(current == target)
	{
		if(ring == 'D')
		{
			remaining = current - point_value(segment,ring);
		}
		else 
		{
			remaining = current;
		}
	}
	else
	{
		remaining = current - point_value(segment,ring);
		if(remaining < 0)
		{
			remaining = current;
		}			
		else if(remaining == 0 && ring == 'D')
		{
			remaining = remaining;
		}
		else if(remaining == 0 && ring != 'D')
		{
			remaining = current ;
		}
		else
		{
			remaining = remaining;
		}
	}
	return remaining;
}

int main()
{
int target,current,segment;
char ring;
printf("Target: ");
scanf("%d",&target);
current = target;
do
{
	printf("Throw: ");
	scanf("%d %c",&segment,&ring);
	current = remaining_value(current,target,segment,ring);
	printf("Points: %d\n",current);
	
}while(current > 0);


return 0;
}