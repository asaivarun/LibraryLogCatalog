#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 20
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOK_LENGTH 45
	

struct node						//Creating a Library Node
	{
	char name[MAX_NAME_LENGTH];
	char book_name[MAX_BOOK_LENGTH];
	char author_name[MAX_AUTHOR_LENGTH];
	int in_time;
	int out_time;
	
	struct node *next;
	
	struct date
		{
		int date;
		int month;
		int year;
		}dat_t;
	
	
	};
	
	
struct node *head;

int current_date;
int current_month;

int insert(char *name,char *bookname,char *authorname,int intime,int issuedate,int issuemonth,int issueyear)
{
 
 struct node *temp=(struct node *)malloc(sizeof(struct node));
 
 temp->next=NULL;
 temp->out_time=0;
 
 strcpy(temp->name,name);
 strcpy(temp->book_name,bookname);
 strcpy(temp->author_name,authorname);
 
 temp->in_time=intime;
 
 temp->dat_t.date=issuedate;
 temp->dat_t.month=issuemonth;
 temp->dat_t.year=issueyear;
 
 temp->next=head;
 head=temp;
 
 return 1;
 

 }


 
int delete(char *name)
{
struct node *temp1=head;
 	
 	struct node *temp2 = NULL;

   while (temp1 != NULL)
   {
      if (strcmp(temp1->name, name) == 0)
      {
        // Found it.
        if (temp2 != NULL)
          temp2->next = temp1->next;
        else
           head = temp1->next;
        free(temp1);
        return 1; // SUCCESS. found it. Deleted it.
      }

      /* Keep Looking. Move pointers. */
      temp2 = temp1;
      temp1 = temp1->next;
  }
return 0;
} 


void print()
{
struct node *temp=head;
while(temp!=NULL)
	{
	printf("\n");
	printf("Name of The Student is %s",(*temp).name);
	printf("\n");
	printf("Name of The Book is %s",temp->book_name);
	printf("\n");
	printf("Author Name of The %s is %s",temp->book_name,temp->author_name);
	printf("\n");
	printf("Intime of the %s is %d",temp->name,temp->in_time);
	printf("\n");
	printf("Outtime of the %s is %d",temp->name,temp->out_time);
	printf("\n");
	printf("Issue date of %s is %d/%d/%d",temp->book_name,temp->dat_t.date,temp->dat_t.month,temp->dat_t.year);
	
	printf("\n");
	temp=temp->next;
	}
printf("\n");
}



int search(char *name)
{
struct node *temp=head;
 	
 
   while (temp != NULL)
   {
      if (strcmp(temp->name, name) == 0)
      {
        printf("Name of The Student is %s",(*temp).name);
        printf("\n");
	printf("Name of The Book is %s",temp->book_name);
	printf("\n");
	printf("Author Name of The %s is %s",temp->book_name,temp->author_name);
	printf("\n");
	printf("Intime of the %s is %d",temp->name,temp->in_time);
	printf("\n");
	printf("Intime of the %s is %d",temp->name,temp->out_time);
	printf("\n");
	printf("Issue date of %s is %d/%d/%d",temp->book_name,temp->dat_t.date,temp->dat_t.month,temp->dat_t.year);
	return 1; // SUCCESS. found it.      
      }
      temp=temp->next;
                     
    }
return 0;

}

void return_date(char *name)
{
struct node *temp=head;
int return_date;
printf("\n");
while (temp != NULL)
{
if(strcmp(name,temp->name)==0)
	{
	return_date=temp->dat_t.date+7;
	if(return_date>30)
		{
		return_date=return_date-30;
 		temp->dat_t.month++;
 		}
 	if(temp->dat_t.month>12)
 		{
 		temp->dat_t.year++;
 		temp->dat_t.month--;
 		}
 	printf("Return Date of %s is %d/%d/%d",temp->book_name,return_date,temp->dat_t.month,temp->dat_t.year);
	return;
	}
temp=temp->next;
}
}

int update_out_time(char *name)
{
struct node *temp=head;
int outtime; 	
printf("\n"); 
   while (temp != NULL)
   {
      if (strcmp(temp->name, name) == 0)
      {
      printf("Enter the Out Time");
      scanf("%d",&outtime);
      temp->out_time=outtime;
      return 1;
      }
    temp=temp->next;  
   }   
return 0;
}


int fine(char *name)
{
struct node *temp=head;
int c,d,fine;
while (temp != NULL)
{
if(strcmp(name,temp->name)==0)
	{
	
	if((temp->dat_t.month>current_month) || (temp->dat_t.month<current_month))
		{
		d=abs(temp->dat_t.month-current_month);			
		// Calculating Days	
		if(temp->dat_t.date>current_date)
			c=(30-temp->dat_t.date)+current_date+30*(d-1);
		else 
			c=current_date-temp->dat_t.date+30*d;
		}
	else	
		c=abs(temp->dat_t.date-current_date);
	}
temp=temp->next;
}	
	fine=c*2-14;

if(fine<0)
	{
	printf("You have no fine");
	fine=0;
	}
	
return fine;	
	
}

int main()
{
char name[MAX_NAME_LENGTH];
char bookname[MAX_BOOK_LENGTH];
char authorname[MAX_AUTHOR_LENGTH];
int intime;
int issuedate;
int issuemonth;
int issueyear,c,ch;

printf("Instructions :1) While entering intime do it like the given Eg.0503 means 5 hours and 3mins");

printf("\n");

printf("2)While entering any kind of string instaed of using spacebar use '_', Eg.For Bookname 'Half_Girlfriend'");

printf("\n");

printf("Please Enter Today's date");
scanf("%d",&current_date);

printf("Please Enter Today's month");
scanf("%d",&current_month);


while(1)
{   printf("\n");
    printf("Welcome to Library Log 1.1");
    printf("\n");
    printf("\n");	
    printf(" 1)Print Whole Library Log\n");
    printf(" 2)Insert Entry\n");
    printf(" 3)Search Entry\n");
    printf(" 4)Delete Entry\n");
    printf(" 5)Update Your Outtime \n");
    printf(" 6)Print Return Date Of the Book\n");
    printf(" 7)Calculate Fine\n");
    printf(" 0)Exit\n");
    printf(" What do you want to do?");
   
    scanf("%d", &ch);
    switch(ch)
    {
       case 1: /* Print Whole List */
        print(); 
         break;
       
       
       case 2:/* Inserting Into the List */
	printf("Enter The Your Name");
	printf("\n");
	scanf("%s",name);
	printf("\n");
	printf("Enter The Book name");
	scanf("%s",bookname);
	printf("\n");
	printf("Enter The Author Name");
	scanf("%s",authorname);
	printf("\n");
	printf("Enter the intime");
	scanf("%d",&intime);
	printf("\n");
	printf("Enter the issuedate");
	scanf("%d",&issuedate);
	printf("\n");
	printf("Enter the issuemonth");
	scanf("%d",&issuemonth);
	printf("\n");
	printf("Enter the issueyear");
	scanf("%d",&issueyear);
	printf("\n");
        
        c=insert(name,bookname,authorname,intime,issuedate,issuemonth,issueyear);
	
	printf("\n");
	if(c==1)
	printf("Inserting into Library record Successfull");
	
	break;
 
 
       
       
       case 3:/* Searching A Entry Of Student */
        printf("\n");
 	printf("Enter The name of Student For Searching its entry");
 	scanf("%s",name);
 	c=search(name);
 	printf("\n");
 	if(c==1)
 	printf("searching into Library record Successfull");
 	else
 	printf("searching into Library record Failed");
 	break;
 	printf("\n");
 	
        
        
        case 4:/* Deleting The entry */ 
        printf("\n");
 	printf("Enter The name of Student For Deleting its entry");
 	scanf("%s",name);
 	c=delete(name);
 	printf("\n");
 	if(c==1)
 	printf("Deleting into Library record Successfull");
 	else
 	printf("Deleting into Library record Failed");
 	break;
       
       case 5:/* Updating Out Time When Going Out */
       	printf("Enter your name");
       	scanf("%s",name);
       	c=update_out_time(name);
	if(c==1)
 	printf("Updating into Library record Successfull");
 	else
 	printf("Updating into Library record Failed");
 	break;	
 	
 	case 6 :/* Printing Return Date of The book */
	printf("Enter your name");
	scanf("%s",name);
	return_date(name);
	break; 	
 	
 	case 7 :/* Calculating Fine*/
 	printf("Enter your name");
 	scanf("%s",name);
	c=fine(name);
	printf("\n");
	printf("Fine = %d",c);
	break; 	

 	case 0:/* Exit */
 	exit(0);
 	
 	      	
	}
}	

}	 

