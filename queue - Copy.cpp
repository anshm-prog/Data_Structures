
#include<stdio.h>
#include<stdlib.h>
void insert();
void display();
void del();
#define MAX 5
int cq[MAX],front=-1,rear=-1;
int main()
{
	int ch;
	//clrscr();
	while(1)
	{
		printf("\n press 1:To insert:");
		printf("\n press 2:To display:");
		printf("\n press 3:To delete:");
		printf("\n press 4:To exit:");
		printf("\n enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				del();
				break;
			case 4:
				exit(0);
			default:
				printf("\n wrong choice:");
		}
	}
	
}


void insert()
{
	if((front==0 && rear==MAX-1)||(front==rear+1))
	{
		printf("\n the Circuller queue is full");
		return;
	}
	printf("\n enter a value:");
	if(rear==MAX-1)
	{
		rear=0;
		scanf("%d",&cq[rear]);
		return;
	}
	if(front==-1)
	{
		front=0;
		scanf("%d",&cq[++rear]);
		return;
	}
	scanf("%d",&cq[++rear]);
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("\n the circular queue is empty");
		return;
	}
	printf("\n circular queue is:    \n");
	printf("\n FRONT>>");
	if(rear>=front)
	{
		for(i=front;i<=rear;i++)
		printf("| %d ",cq[i]);
	}
	else
	{
		for(i=front;i<MAX;i++)
		printf("| %d ",cq[i]);
		for(i=0;i<=rear;i++)
		printf("| %d ",cq[i]);
	}
	printf(" |<<REAR");
}
void del()
{
	if(front==-1)
	{
		printf("\n the circular queue is empty");
		return;
	}
	if(front==rear)
	{
		front=-1;
		rear=-1;
		return;
	}
	if(front==MAX-1)
	{
		front=0;
		return;
	}
	front++;
}
