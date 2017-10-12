// Author = Jatin Kumar
//mantaining the database of n no. of students and then providing the various facilities like:
// add the student
// delete the student
// search the student
// update the student details
// print the entire database 
#include<stdio.h>
#include<string.h>
struct student  // declare the desired data required for the student in the form of structure
{
	char name[10];
	int roll;
	float cgpa;
}s[100]; // maximum 100 students are allowed , you can increase it accordingly
int n,i,choice,flag=0;
void initialize();  // initialize the database
void menuchoice();  // print the menu and its choices
void display();     // print the entire database
void search();      // search a student
void update();      // update the data of a student
void add();         // add a student
void del();         // delete the student
void input();       // take the no. of student from the user in order to initialize the database
int main()
{
	input();
	initialize();
	menuchoice();
}
void input()
{
	printf("enter the no. of the students=");
	scanf("%d",&n);
}
void initialize()
{	
	printf("enter the data of the %d studetns\n",n);
	for(i=0;i<n;i++)
	{
		printf("*******************student %d********************\n",i);
		printf("name=");
		scanf("%s",s[i].name);
		printf("roll no.=");
		scanf("%d",&s[i].roll);
		printf("cgpa=");
		scanf("%f",&s[i].cgpa);	
	}
}
void menuchoice()
{
	start:
	printf("\n---------------------MENU---------------------\n");
	printf("1.)Print the entire database of the students\n");
	printf("2.)Search a student with name or roll no.\n");
	printf("3.)Add new student in the database\n");
	printf("4.)Delete a student from the database\n");
	printf("5.)Update the CGPA of student\n");
	printf("6.)Exit\n\n");
	printf("enter your choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:display();
		        break;
		case 2:search();
			break;
		case 3: add();
			break;
		case 4: del();
			break;
		case 5:update();
			break;
		case 6:flag=1;
			break;
		default:printf("please enter a correct choice");
	}
	if(flag==0)
	{
		goto start;
	}
}
void display()
{	if(n==0)
	{
		printf("THE DATABASE IS EMPTY NOTHING TO SHOW\n");
	}
	else
	{	
		for(i=0;i<n;i++)
		{
			printf("\n**************************student %d***************************\n",i);
			printf("Name=%s\n",s[i].name);
			printf("Roll No.=%d\n",s[i].roll);
			printf("CGPA=%f\n",s[i].cgpa);
		}
	}
}
void search()
{
	int choice2,value,roll2,flag2=0;
	char name2[10];
	printf("\npress 0 for search by name and 1 for search by roll no.\n");
	scanf("%d",&choice2);
	if(choice2==0)
	{
		printf("enter the name to be searched=");
		scanf("%s",name2);
		for(i=0;i<n;i++)
		{
			value=strcmp(name2,s[i].name);
			if(value==0)
			{	
				flag2=1;
				printf("\nThe details of the students are:\n");
				printf("Name=%s\tRoll no.=%d\tCGPA=%f\n",s[i].name,s[i].roll,s[i].cgpa);
			}
		}
		if(flag2==0)
		{
			printf("\nNo data found for the name %s\n",name2);
		}
	}
	if(choice2==1)
		{
			printf("enter the roll no. of the student to be searched=");
			scanf("%d",&roll2);
			for(i=0;i<n;i++)
			{
				if(roll2==s[i].roll)
				{	
					flag2=1;
					printf("\nThe details of the students are:\n");
					printf("Name=%s\tRoll no.=%d\tCGPA=%f\n",s[i].name,s[i].roll,s[i].cgpa);
				}
			}
			if(flag2==0)
			{
				printf("\nNo data found for the roll no. %d\n",roll2);
			}
		}	
}
void update()
{	
	int roll3,flag3=0;
	printf("enter the roll no. of the student whose CGPA you want to update=");
	scanf("%d",&roll3);
	for(i=0;i<n;i++)
	{
		if(s[i].roll==roll3)
		{
			flag3=1;
			printf("\nThe current data of the student is:\n");
			printf("Name=%s\tRoll no.=%d\tCGPA=%f\n",s[i].name,s[i].roll,s[i].cgpa);
			printf("ENTER THE NEW CGPA OF THE STUDENT\n");
			scanf("%f",&s[i].cgpa);
			printf("CGPA is successfully UPDATED\n");
		}
	}
	if(flag3==0)
	{
		printf("\nInvalid roll no.\n");
	}
}
void add()
{
	printf("***********************student %d***********************\n",n);
	printf("Name=");
	scanf("%s",s[n].name);
	printf("Roll No.=");
	scanf("%d",&s[n].roll);
	printf("CGPA=");
	scanf("%f",&s[n].cgpa);
	printf("\nTHE DATA HAS BEEN SUCCESSFULLY ADDED TO THE DATABASE");
	n++;
}
void del()
{
	int roll4,j,flag=0;
	printf("Enter the roll no. of the student whose data you want to delete=");
	scanf("%d",&roll4);
	for(i=0;i<n;i++)
	{
		if(roll4==s[i].roll)
		{	
			flag=1;
			printf("the data of the student is:\n");
			printf("Name=%s\tRoll no.=%d\tCGPA=%f\n",s[i].name,s[i].roll,s[i].cgpa);
			printf("This data has been deleted");
			for(j=i;j<n-1;j++)
			{
				strcpy(s[j].name,s[j+1].name);
				s[j].roll=s[j+1].roll;
				s[j].cgpa=s[j+1].cgpa;
			}
			n=n-1;
		}
	}
	if(flag==0)
	{
		printf("Invalid roll no.\n");
	}
}
