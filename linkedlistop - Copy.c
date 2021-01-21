#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
} *start;
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
void main()
{
	struct node *start = NULL;
	int n,choice,data,item,pos,i;
	while(1)
	{
		printf("1.create list\n");
		printf("2.Display\n");
		printf("3.Count\n");
		printf("4.search\n");
		printf("5. ADD to empty list/Add at begining\n");
		printf("6.Add at the end\n");
		printf("7.Add after node\n");
		printf("8. Add before node\n");
		printf("9. Add at the position\n");
		printf("10. DELETE\n");
		printf("11.Quit\n\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
	switch(choice)
		{
		case1:
			printf("how many do you want to store?");
			scanf("%d",n);
			for (i=0;i<n;i++)
				start = create_list(start);
			break;
	    case2:
	    	dispaly(start);
	    	break;
	    case3:
	    	count(start);
	    	break;
	    case4:
	    	printf("Enter the element to be searched:");
	    	scanf("%d",&data);
	    	search(start,data);
	    	break;
	    case5:
	    	printf("Enter the element to be inserted:");
	    	scanf("%d",&data);
	    	start = addatbeg(start,data);
	    	break;
	    case6:
		    printf("Enter the element to be inserted:");
			scanf("%d",&data);
			start = addatend(start,data);
			break;
		case7:
		    printf("Enter the element to be inserted:");
			scanf("%d",&data);
			printf("Enter the element after which to be inserted:");
			scanf("%d",&item);
			start = addafter(start,data,item);
			break;
		case8:
		    printf("Emter the element to be inserted:");
			scanf("%d",&data);
			printf("Enter the element before which to be inserted:");
			scanf("%d",&item);
			start = addbefore(start,data,item);
			break;
		case9:
			printf("Enter the element to be inserted:");
			scanf("%d",&data);
			printf("Enter the element at which to be inserted:");
			scanf("%d",&pos);
			start = addatpos(start,data,pos);
			break;
		case10:
			printf("Enter the element to be deleted:");
			scanf("%d",&data);
			start = del(start,data);
			break;
		case11:
			exit(0);
		default:
			printf("you entered the wrong choice.");
						
		}
            }
                }
	
struct node *create_list(struct node *start){
	int n,i,data;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	start = NULL;
	if(n==0);
	return start;
	printf("Enter the element to be inserted:");
	scanf("%d",&data);
	start = addatbeg(start,data);
	for(i=2;i<=n;i++){
		printf("Enter the element to be inserted:");
		scanf("%d",&data);
		start = addatend(start,data);
	}
	return start;
}
void display(struct node *start){
	struct node *p;
	if(start ==NULL)
	{
		printf("list is Empty.");
		return;
	}
	p=start;
	printf("linst is:\n");
	while(p!= NULL)
	{
		printf("%d",p->info );
		p=p->link;
	}
	printf("\n\n");
}
void count(struct node *start){
	struct node *p;
	int cnt=0;
	p= start;
	while (p!=NULL){
		p=p->link;
		cnt++;
	}
	printf("number of elements are%d \n",cnt);
}
void search(struct node *start,int item){
	struct node *p =start;
	int pos=1;
	while(p!=NULL){
		if(p->info == item){
			printf("item %d at position %d\n",item,pos);
			return;
		}
		p=p->link;
		pos++;
	}
	printf("item %D not found in the list\n",item);
}
struct node *addatbeg(struct node *start, int data){
	struct node *tmp;
	tmp =(struct node *)malloc(sizeof(struct node));
	tmp->info =data;
	tmp->link =start;
	tmp = start;
	return start;
}
struct node *addatend(struct node *start,int data){
	struct node *p,*tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL){
		p=p->link;
	}
	p->link=tmp;
	tmp->link=NULL;
	return start;
}
struct node *addafter(struct node *start,int data,int item){
	struct node *tmp,*p;
	p=start;
	while(p != NULL){
		if(p->info==item){
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d is not present in the list",item);
	return start;
}
struct node *addbefore(struct node *start,int data, int item){
	struct node *tmp,*p;
	if(start==NULL){
		printf("list is empty.");
		return start;
	}
	if(item==start->info ){
		tmp=(struct node*)malloc(sizeof(struct node));
		tmp->info = data;
		tmp->link= start;
	}
	while(p->link!= NULL){
		if(p->link->info==item){
			tmp=(struct node*)malloc(sizeof(struct node));
			tmp->info =data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d is not present in the list",item);
}
struct  node *del(struct node *start,int data){
	struct node *tmp,*p;
	if(start == NULL){
		printf("list is Empty.");
		return start;
	}
	if(start->info ==data){
		tmp=start;
		start=start->link;
		free(tmp);
		return start;
	}
	p=start;
	while(p->link!=NULL){
		if(p->link->info==data){
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	printf("Element %d  not found\n",data);
	return start;
}

