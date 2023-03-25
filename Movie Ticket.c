#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tickets,file;
FILE *fp,*tc,*tw;
struct node
{
	int age;
	char name[20];
	struct node *next;
}*top;
void push(int age,char name[20])
{
	struct node *nn;
	char op[5];
	nn = (struct node*)malloc(sizeof(struct node));
	nn->age = age;
	strcpy(nn->name,name);
	nn->next = NULL;
	if(top == NULL)
	{
		top = nn;
	}
	else
	{
		nn->next = top;
		top = nn;
	}
}
int pop()
{
	struct node *temp;
	temp = top;
	if(top == NULL)
	return;
	else
	{
		printf("%s cancled the ticket\n",temp->name);
		top = top->next;
		free(temp);
	}
}
void daily_run()
{
	int number,age,cost,n,i;
	struct node *temp;
	char name[20],opt[5];
	if(tickets==0)
	{
		printf("\n-----------------------------------------------------------------------------------\n");
		printf("  --------------------------------------------------------------------------------------\n");
		printf("                    sorry HOUSE FULL!!");
		printf("\n-----------------------------------------------------------------------------------\n");
		printf("  --------------------------------------------------------------------------------------\n");
		return;
	}
	printf("enter the number of customers: ");
	scanf("%d",&number);
	n=number;
	if(tickets < number)
	{
		printf("\n       sorry we have only %d tickets for that show!!\n",tickets);
		return;
	}
	cost = number*250;
	while(number--)
	{
		printf("enter the name of customer: ");
		scanf("%s",name);
		printf("enter the age of customer: ");
		scanf("%d",&age);
		push(age,name);
	}
	printf("your ticket costs rupees:%d press yes to continue: ",cost);
	scanf("%s",opt);
	if(strcmp("yes",opt))
	{
		while(n--)
		{
			pop();
		}
	}
	else
	{
		printf("\n-----------------------------------------------------------------------\n");
		printf("  -----------------------------------------------------------------------------\n");
		printf("        !!you have booked %d tickets!!\n",n);
		printf("\n-----------------------------------------------------------------------\n");
		printf("  -----------------------------------------------------------------------------\n");
		temp = top;
		while(n--)
		{
			fprintf(fp,"name : %s\n age : %d\n",temp->name,temp->age);
			temp = temp->next;
			tickets--;
		}
	}
}
void todayscollection()
{
	struct node *temp;
	temp = top;
	if(temp == NULL)
	{
		printf("                there is no booking today\n");
	}
	else
	{
		printf("today's customers are:\n");
		while(temp!=NULL)
		{
			printf("\tname-%s\n\tage -%d\n",temp->name,temp->age);
			temp = temp->next;
		}
	}
}
FILE* select_Theater(int a)
{
	if(a == 1)
	{
		fp = fopen("Theater-1.txt","a+");
		return fp;
	}
	else if(a == 2)
	{
		fp = fopen("Theater-2.txt","a+");
		return fp;
	}
	else if(a == 3)
	{
		fp = fopen("Theater-3.txt","a+");
		return fp;
	}
	else if(a == 4)
	{
		fp = fopen("Theater-4.txt","a+");
		return fp;
	}
	else if(a == 5)
	{
		fp = fopen("Theater-5.txt","a+");
		return fp;
	}
}
FILE* exporting(int a)
{
	if(a==1)
	{
		tw = fopen("Ticket-1.txt","w");
		return tw;
	}
	else if(a==2)
	{
		tw = fopen("Ticket-2.txt","w");
		return tw;
	}
	else if(a==3)
	{
		tw = fopen("Ticket-3.txt","w");
		return tw;
	}
	else if(a==4)
	{
		tw = fopen("Ticket-4.txt","w");
		return tw;
	}
	else if(a==5)
	{
		tw = fopen("Ticket-5.txt","w");
		return tw;
	}
}
int Ticket_count(int a)
{
	int tic;
	if(a == 1)
	{
		tc = fopen("Ticket-1.txt","r");
		if(tc == NULL)
		{
			tc = fopen("Ticket-1.txt","w");
			fprintf(tc,"%d",20);
			fclose(tc);
			tc = fopen("Ticket-1.txt","r");
		}
		fscanf(tc,"%d",&tic);
		fclose(tc);
		return tic;
	}
	else if(a == 2)
	{
		tc = fopen("Ticket-2.txt","r");
		if(tc == NULL)
		{
			tc = fopen("Ticket-2.txt","w");
			fprintf(tc,"%d",20);
			fclose(tc);
			tc = fopen("Ticket-2.txt","r");
		}
		fscanf(tc,"%d",&tic);
		fclose(tc);
		return tic;
	}
	else if(a == 3)
	{
		tc = fopen("Ticket-3.txt","r");
		if(tc == NULL)
		{
			tc = fopen("Ticket-3.txt","w");
			fprintf(tc,"%d",20);
			fclose(tc);
			tc = fopen("Ticket-3.txt","r");
		}
		fscanf(tc,"%d",&tic);
		fclose(tc);
		return tic;
	}
	else if(a == 4)
	{
		tc = fopen("Ticket-4.txt","r");
		if(tc == NULL)
		{
			tc = fopen("Ticket-4.txt","w");
			fprintf(tc,"%d",20);
			fclose(tc);
			tc = fopen("Ticket-4.txt","r");
		}
		fscanf(tc,"%d",&tic);
		fclose(tc);
		return tic;
	}
	else if(a == 5)
	{
		tc = fopen("Ticket-5.txt","r");
		if(tc == NULL)
		{
			tc = fopen("Ticket-5.txt","w");
			fprintf(tc,"%d",20);
			fclose(tc);
			tc = fopen("Ticket-5.txt","r");
		}
		fscanf(tc,"%d",&tic);
		fclose(tc);
		return tic;
	}
}
int main()
{
	FILE *fp1,*tw1;
	printf("\n-----------------------------------------------------------------------\n");
	printf("  -----------------------------------------------------------------------------\n");
	while(1)
	{
		printf("1.Avengers End Game\n2.Pushpa The Rise\n3.Baahubali 2: The Conclusion\n4.Vikram\n5.Liger\n6.stop booking\n");
		printf("enter your movie number: ");
		scanf("%d",&file);
		if(file==6)
		break;
		fp1 = select_Theater(file);
		tickets = Ticket_count(file);
		daily_run();
		tw1 = exporting(file);
		fprintf(tw,"%d",tickets);
		fclose(fp);
		fclose(tw);
		fclose(fp1);
		fclose(tw1);
	}
	printf("\n-----------------------------------------------------------------------\n");
	printf("  -----------------------------------------------------------------------------\n");
	todayscollection();
	printf("\n-----------------------------------------------------------------------\n");
	printf("  -----------------------------------------------------------------------------\n");
	return 0;
}