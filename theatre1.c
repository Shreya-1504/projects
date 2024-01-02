#include<stdio.h>
#include<stdlib.h>
int intro();
void play();
int film();
int process(int num1);
void rating(int num);void details(int num1);
int booked_seats(int a[7][7],int b[],int s);
void trailer(int num);
void trend();
void about();
void reg();
void login();
void first();
struct names
{
	char id[5],pwd[5];
};

void main()
{
    int num;
    int w;int p;
	printf("\n\t\t\t--------------------------------------\n");
	printf(" \n\t\t \t  Welcome to Movie Ticket Booking\n");
	printf("\n\t\t\t--------------------------------------\n");
	first();
    
    
}
void first()
{
	int num;
    int w;int p;
	printf("\n Enter   1:  To log-in \n\n\t 2:  To Register: ");
    scanf("%d",&num);
    x:
    if(num==1)
    {
    	login();
	}
	else if(num==2)
	{
		reg();
	}
	else
	{
		printf("Please enter correct option");
		goto x;
	}
    
}

int intro()
{
	int p;int w;
	s:
	//printf("\n\n Enter 1: To book \n       2: To cancel ");
	
	printf("\n\t\t\t--------------------------------------\n");
	printf(" \n\t\t \t Choose  1: To book\n\n\t\t\t\t 2: To get details\n\n\t\t\t\t 3: Trailer\n\n\t\t\t\t 4: Trending Topics\n\n\t\t\t\t 5: To give a rating\n\n\t\t\t\t 6:  About us\n\n\t\t\t\t 7: Exit ");
	printf("\n\t\t\t--------------------------------------\n");
	scanf("%d",&w);
	if(w==1)
	{
		p=film();
		play(p);
	}
	else if(w==2)
	{
		p=film();
		details(p);
	}
	else if(w==3)
	{
		p=film();
		trailer(p);
	}
	else if(w==4)
	{
		
		trend();
	}
	else if(w==5)
	{
		p=film();
		rating(p);
	}
	else if(w==6)
	{
		about();
	}
	else if(w==7)
	{
	    printf("\nThank you for visiting us\nHave a great day!");
	}
	else
	{
	    printf("\nWrong input\nPlease try again!\n");
	    goto s;
	    
	}
	
}
//////////////////////////////
int film()
{
	FILE *fp;char c;int num1;
	printf("\nSelect a movie:\n\n");
	fp=fopen("film.txt","r");
	c=fgetc(fp);
	printf("\n--------------------------------------\n");
	while(c!=EOF)                     // opens and prints movie list
	{
		printf("%c",c);
		
		c=fgetc(fp);
	}
	fclose(fp);
	printf("\n--------------------------------------\n");
	printf("\n\nEnter: ");
	scanf("%d",&num1);
	return (num1);
}

int process(int num1)
{
		int num2,num3,num4;

		printf("\n\n Choose  1: To book\n\t 2: To get details\n\t 3:Trailer\n\t 4:Trending Topics\n\t 5: To give a rating\n\t 6:About us\n\t 7: Exit ");
		scanf("%d",&num2);
		if(num2==1)
		{
			play();
		}
		else if (num2==2)
		{
			details(num1);
			printf(" \nPlease wait...\n");
			printf("\n Enter   1: To continue\n\t 2: To exit ");
			retry:
			scanf("%d",&num3);
			if (num3==1)
			{
				int x=film();
				process(x);
			}
			else if(num3==2)
			{
				printf("\nThank you for visiting us\nHave a great day!\n\nSee you soon!!!");
			}
			else 
			{
				printf("please try again ");
				goto retry;
			}
		
		}
		else if(num2==3)
		{
			rating(num1);
			printf("\n Enter   1: To continue\n\t 2: To exit ");
			retry1:
			scanf("%d",&num4);
			if (num4==1)
			{
				int x=film();
				process(x);
			}
			else if(num4==2)
			{
				printf("\nThank you for visiting us\nHave a great day!\n\nSee you soon!!!");
			}
			else 
			{
				printf("please try again ");
				goto retry1;
			}
		}
}

/////////////////////////////////////
void details(int num1)
{                              // takes you to the internet
	switch(num1)
	{
		case 1:
			system("explorer https://en.wikipedia.org/wiki/Brahm%C4%81stra:_Part_One_%E2%80%93_Shiva" );
			break;
			
		case 2:
			system("explorer https://en.wikipedia.org/wiki/Radhe_Shyam" );
			break;
			
		case 3:
			system("explorer https://en.wikipedia.org/wiki/RRR_(film)");
			break;
			
		case 4:
			system("explorer https://en.wikipedia.org/wiki/Major_(film)" );
			break;
			
		case 5:
			system("explorer https://en.wikipedia.org/wiki/K.G.F:_Chapter_1" );
			break;
		
		case 6:
			system("explorer https://en.wikipedia.org/wiki/Maestro_(2021_film)" );
			break;
			
		case 7:
			system("explorer https://en.wikipedia.org/wiki/Saaho" );
			break;
			
		case 8:
			system("explorer https://en.wikipedia.org/wiki/Bimbisara" );
			break;
			
		case 9:
			system("explorer https://en.wikipedia.org/wiki/The_Warriorr" );
			break;
			
		case 10:
			system("explorer https://en.wikipedia.org/wiki/Virata_Parvam" );
			break;
			
			
	}
	int m;
	printf("Press  1:  To continue exploring\n\t 2: To exit ");
	scanf("%d",&m);
	if(m==1)
	{
		intro();
		
	}
	else
	{
		printf("\n\tThank you");
	}
	getch();
	
	
}
void rating(int num1)
{
	
	int num;FILE *fp1;int sum=0,count=0,s;FILE *fp2;
	printf("\nPlease rate our project on the scale of 1-5 : ");
	replay:
	scanf("%d",&num);
	
	if(num<1 || num>5)
	{
		printf("\n Try again ");
		goto replay;
	}
	printf("\nThank you for giving a rating \n");
	fp1=fopen("rating.txt","a");
	fprintf(fp1,"%d",num);
	fclose(fp1);
	fp2=fopen("rating.txt","r");
	char c= fgetc(fp2);
	num =atoi(&c);
	while(c!=EOF)
	{
		sum=sum+num;
		count++;
		c= fgetc(fp2);
		num =atoi(&c);
		
	}
	int avg= sum/count;
	printf("\n\nThe average rating given by our users is: %d.0 \n\n",avg);

	fclose(fp2);
	int m;
	printf("Press 1: To continue exploring\n\t 2: To exit ");
	if(m==1)
	{
		intro();
		
	
	}
	else
	{
		printf("\n\tThank you");
	}
}



void play()
{
    int i,j,k,num,s,count=0,a[7][7];char again;int s2;
    char c;
    
    printf("\nHow many seats would you like to book? ");
    scanf("%d",&s);
    int b[s];
    printf("\nHere is the seating arrangement\n\n");
    for(i=0;i<7;i++)
    {
        printf("\t");
        for(j=0;j<7;j++)
        {
            count=count+1;              //seating arrangement
            a[i][j]=count;
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\nPlease select your seats\n");
    for(i=0;i<s;i++)
    {
        scanf("%d",&num);              //taking seat numbers
        b[i]=num;
    }
    int cons;
    for(i=0;i<s;i++)
    {
    	
    	for(j=0;j<s-1;j++)
    	{                                    // bubble sorting the given seat numbers
    		if(b[j]>b[j+1])
    		{
    			cons=b[j];
    			b[j]=b[j+1];
    			b[j+1]=cons;
			}
		}
	}
    

    
    printf("\nThe total cost for you booking will be %d\n",600*s);
	
	replay:
	printf("Would you like to continue (y/n)\n");
	scanf(" %c",&c);
	
    if(c=='y'||c=='Y')
    {
    	printf("\nBooking Successfull !!\n");
    	printf("\nSeating arrangement after your booking :\n\n");
    	printf("\n\t------------------------------------------\n");
    	booked_seats(a,b,s);
    	printf("\n\t------------------------------------------\n");
    	printf("You have booked the seats :");
    	for(i=0;i<s;i++)
    	{
    		printf("%d ",b[i]);
		}
		printf("\n\nYour Bill is: %d .Rs\n",600*s);
		printf("\nThank you for booking!!\n\n");
		int m;
		printf("Press   1: To continue exploring\n\t 2: To exit ");
		scanf("%d",&m);
		if(m==1)
		{
			intro();
			
		
		}
		else
		{
			printf("\n\tThank you");
		}
	}
	
	
}
    
int booked_seats(int a[7][7],int b[],int s)
{
	int i,j,k;
    for(i=0;i<7;i++)
    {
    	printf("\t");
    	
        for(j=0;j<7;j++)
        {
            for(k=0;k<s;k++)
            {
                if(a[i][j]==b[k])
                {
                    a[i][j]=100;                        // @ representation for booked seats
                }
            }
            if(a[i][j]>50)
            {
                printf("@\t");
            }
            else
            {
                printf("%d\t",a[i][j]);
            }           
    	}
        printf("\n");
    }  
}

void trailer(int num1)   //3
{

	switch(num1)
	{
		case 1:
			printf("Playing brahmastra trailer !!");
		//	sleep(2);
			system("v1.mp4" );
			break;
			
		case 2:
			printf("Playing Radhe Shyam trailer !!");
		//	sleep(2);
			system("v2.mp4" );
			break;
			
		case 3:
			printf("Playing RRR trailer !!");
		//	sleep(2);
			system("v3.mp4" );
			break;
			
		case 4:
			printf("Playing RRR trailer !!");
		//	sleep(2);
			system("v4.mp4" );
			break;
			
		case 5:
			printf("Playing K.G.F chapter 2 trailer !!");
		//	sleep(2);
			system("v5.mp4" );
			break;
		
		case 6:
			printf("Playing Maestro trailer !!");
			//sleep(2);
			system("v6.mp4" );
			break;
			
		case 7:
			printf("Playing Saaho trailer !!");
			//sleep(2);
			system("v7.mp4" );
			break;
			
		case 8:
			printf("Playing Bimbisara trailer !!");
			//sleep(2);
			system("v8.mp4" );
			break;
			
		case 9:
			printf("Playing The Godfather trailer !!");
		//	sleep(2);
			system("v9.mp4" );
			break;
			
		case 10:
			printf("Playing Virata Paravam trailer !!");
		//	sleep(2);
			system("v10.mp4" );
			break;
			
			
	}

//	sleep(3);
	
	
    int m;
	printf("Press 1: To continue exploring\n\t 2: To exit ");
	scanf("%d",&m);
	if(m==1)
	{
		intro();
		
	
	}
	else
	{
		printf("\n\tThank you");
	}
}
void trend()
{

	printf("Taking you to the trend zone !!!");
	printf("\n\nPlease wait..");
	printf("\n\nPress enter..");
	
	getch();
	//sleep(3);
	system ("explorer https://www.filmfare.com/");
	//sleep(2);
	int m;
	printf("Press 1: To continue exploring\n\t 2: To exit ");
	scanf("%d",&m);
	if(m==1)
	{
		intro();
		
	
	}
	else
	{
		printf("\n\tThank you")
	;}

}
void about()

{
	char c[1];
//	system("clrscr");
	
//	delay(1000);
	printf("\nHello dear user !!");
	//delay(1000);
	printf("\n\nWe are glad to have you hear !! .");
	//delay(1000);
	printf("\n\nHope you are doing great!!");
	//delay(2000);
	printf("\n\nCREATORS: ");
	//delay(1000);
	printf("\n\tShreya Barlapudi");
	
//	delay(2000);
	printf("\n\nCONTACT US (Instagram): ");
//	delay(1000);
	printf("\n\tshreya_1504");
	


	int m;
	printf("\n\n");
	printf("Press    1: To continue exploring\n\t 2: To exit ");
	scanf("%d",&m);
	if(m==1)
	{
		intro();
		
	
	}
	else
	{
		printf("\n\tThank you");
	}
		

}
void login()
{
	FILE *fp;
	char id[5],pwd[5];
          //pwd
	printf("\nEnter user-id: ");
	scanf("%s",&id);

	printf("\n\nEnter password: ");
	scanf("%s",&pwd);

	
	fp=fopen("names.txt","rb+");

	struct names l;
	while(fread(&l,sizeof(l),1,fp))
	{

		if(strcmp(id,l.id)==0 && strcmp(pwd,l.pwd)==0)
		{
		
			printf("\t\n\nLogin Successful !!\n\n");
			printf("\nPress any key to continue..");
			getch();
			
			printf("\n\n\n\n");
			intro();
			break;
		}
		else
		{
		
		
			printf("\t\nThe given details are invalid\n\n");
			first();
			
			break;
		}
	}	
	fclose(fp);
	
	
   // rectangle(200,100,800,700);

}
void reg()
{
	int y;
	FILE *fp;
	fp=fopen("names.txt","wb+");
	struct names l;
	x:
	printf("\t\nplease chooose your user-id: ");
	scanf("%s",l.id);
	printf("\t\nplease choose your password: ");
    scanf("%s",l.pwd);
    fwrite(&l,sizeof(l),1,fp);

	
	printf("\t\n\n\nregistered!!");
	printf("\n\nPress any key to continue..");
	getch();
	printf("\n\n");
	fclose(fp);
	first();
	

}


