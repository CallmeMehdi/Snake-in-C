#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
typedef struct
{
	int x;
	int y;
	char vector;
	int velocity;
}snake;
void update(snake* s,COORD* f,int* l);
void draw(snake* s,COORD* f,int* l);
void init();
void main()
{
	
	int l=5,i,b=0;
	COORD f;
	snake* s=(snake*)malloc(l*sizeof(snake));
	//init();
	for (i=0;i<l;i++)
	{ 
	  s[i].velocity=0;
	  s[i].x=20;
	  s[i].y= b+ 20;
	  s[i].vector='z';
	  b--;
	}
	do
	{
		update(s,&f,&l);
		draw(s,&f,&l);
	} while (1);

}
void food(COORD* f)
{
	int x,y;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	int r = rand() % 6;
	if (!r)
	{ 
	x = rand() % 115;
	y = rand() % 40;
	COORD a;
	a.X=x;
	a.Y=y;
	SetConsoleCursorPosition(hConsole,a);
	printf("*");
	}
	f->X=x;
	f->Y=y;
}
/*void init()
{
	int i;
	printf(" ");
	for (i=0;i<115;i++)
	printf("-");
	printf("\n");
	for(i=0;i<20;i++)
	{
		printf("|                                                                                                                   |\n");
	}
		printf("|                                                       1.PLAY                                                       |\n");
		printf("|                                                       2.EXIT                                                       |\n");
	for(i=0;i<20;i++)
	{
		printf("|                                                                                                                   |\n");
	}
	printf(" ");
	for (i=0;i<115;i++)
	printf("-");
	if (getch()=='1')
	clrscr();
	else if(getch()=='2')
	exit(0);
}*/

/*int eat(snake* s,COORD* f,int* l)
{
	if ((s[0].x==f->X-1 && s[0].y==f->Y&&s[0].vector=='d')||(s[0].x==f->X+1 && s[0].y==f->Y&&s[0].vector=='q')||(s[0].x==f->X && s[0].y==f->Y+1&&s[0].vector=='z')||(s[0].x==f->X && s[0].y==f->Y-1&&s[0].vector=='s'))
	if (s[0].x==f->X&&s[0].y==f->Y)
	{
		*l++;
		s[0].velocity+=10;
		return 1;
	}
	return 0;
}*/

void update(snake* s,COORD* f,int * l)
{
	char key;
//	eat(s,f,l);
	//food(f);
	if (kbhit())
	{
	do
	{
		key=getch();
	}while (key!='d' && key!='s' && key!='q' && key!='z');
	s[0].vector=key;
	}
}

void draw (snake* s,COORD* f,int* l)
{
	int aux1,aux2,j,k,i,v;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD a;
	//food
	int x,y;
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	int r = rand() % 6;
	if (!r)
	{ 
	x = rand() % 115;
	y = rand() % 40;
	COORD a;
	a.X=x;
	a.Y=y;
	SetConsoleCursorPosition(hConsole,a);
	printf("*");
	}
	f->X=x;
	f->Y=y;
	//food
	//eat
	if (s[0].x==f->X&&s[0].y==f->Y)
	{
		*l=*l+1;
		s[0].velocity+=10;
	v=1;
	}
	else v=0;
	//eat
	switch(s[0].vector)
	{
		case 's': 
		{
			a.Y=s[0].y+1;
		    a.X=s[0].x;
			SetConsoleCursorPosition(hConsole,a);	
			printf(".");
			aux1=s[0].y;
			aux2=s[0].x;
			s[0].y=s[0].y+1;
			for (i=1;i<*l;i++)
			{
				j=s[i].y;
				k=s[i].x;
				s[i].y=aux1;
				s[i].x=aux2;
				a.Y=s[i].y;
				a.X=s[i].x;
				SetConsoleCursorPosition(hConsole,a);
				printf(".");
				aux1=j;
				aux2=k;
			}
			if (!v)
			{
			a.Y=aux1;
			a.X=aux2;
			SetConsoleCursorPosition(hConsole,a);
			printf(" ");
			}
			break;
		}
		case 'z': 
		{
			a.Y=s[0].y-1;
		    a.X=s[0].x;
			SetConsoleCursorPosition(hConsole,a);	
			printf(".");
			aux1=s[0].y;
			aux2=s[0].x;
			s[0].y=s[0].y-1;
			for (i=1;i<*l;i++)
			{
				j=s[i].y;
				k=s[i].x;
				s[i].y=aux1;
				s[i].x=aux2;
				a.Y=aux1;
				a.X=aux2;
				SetConsoleCursorPosition(hConsole,a);
				printf(".");
				aux1=j;
				aux2=k;
			}
			if (!v)
			{
			a.Y=aux1;
			a.X=aux2;
			SetConsoleCursorPosition(hConsole,a);
			printf(" ");
			}
			break;
		}
		case 'd': 
		{
			a.Y=s[0].y;
		    a.X=s[0].x+1;
			SetConsoleCursorPosition(hConsole,a);	
			printf(".");
			aux1=s[0].y;
			aux2=s[0].x;
			s[0].x=s[0].x+1;
			for (i=1;i<*l;i++)
			{
				j=s[i].y;
				k=s[i].x;
				s[i].y=aux1;
				s[i].x=aux2;
				a.Y=aux1;
				a.X=aux2;
				SetConsoleCursorPosition(hConsole,a);
				printf(".");
				aux1=j;
				aux2=k;
			}
			if (!v)
			{
			a.Y=aux1;
			a.X=aux2;
			SetConsoleCursorPosition(hConsole,a);
			printf(" ");}
			break;
		}
		case 'q': 
		{
			a.Y=s[0].y;
		    a.X=s[0].x-1;
			SetConsoleCursorPosition(hConsole,a);	
			printf(".");
			aux1=s[0].y;
			aux2=s[0].x;
			s[0].x=s[0].x-1;
			for (i=1;i<*l;i++)
			{
				j=s[i].y;
				k=s[i].x;
				s[i].y=aux1;
				s[i].x=aux2;
				a.Y=aux1;
				a.X=aux2;
				SetConsoleCursorPosition(hConsole,a);
				printf(".");
				aux1=j;
				aux2=k;
			}
			if (!v)
			{a.Y=aux1;
			a.X=aux2;
			SetConsoleCursorPosition(hConsole,a);
			printf(" ");}
			break;
		}
		
			
	}
	Sleep(100-s[0].velocity);
	//	printf("%d%d",f->X,f->Y);
	
	
	
}
