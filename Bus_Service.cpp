#include<iostream.h>
#include <stdio.h>
#include<graphics.h>
#include <limits.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<ctype.h>
// Number of vertices in the graph
#define V 16
char prin(int vm)
{
    if(vm==0)
	return 'A';
    if(vm==1)
	return 'B';
    if(vm==2)
	return 'C';
    if(vm==3)
	return 'D';
    if(vm==4)
	return 'E';
    if(vm==5)
	return 'F';
    if(vm==6)
	return 'G';
    if(vm==7)
	return 'H';
    if(vm==8)
	return 'I';
    if(vm==9)
	return 'J';
    if(vm==10)
	return 'K';
    if(vm==11)
	return 'L';
    if(vm==12)
	return 'M';
    if(vm==13)
	return 'N';
    if(vm==14)
	return 'O';
    if(vm==15)
	return 'P';
    return 0;

}
int s11[20];
int s21[20];
int d11[20];
int d21[20];
int x=0;
int a[V][V] = {{0, 5, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {5, 0, 3, 0, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 17, 0},
		      {0, 3, 0, 6, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {6, 5, 0, 0, 0, 3, 0, 4, 3, 5, 0, 0, 0, 0, 0, 0},
		      {0, 3, 8, 0, 3, 0, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0},
		      {0, 0, 0, 6, 0, 5, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
		      {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
		      {0, 0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 3, 5, 0, 15, 0},
		      {0, 0, 0, 0, 5, 3, 0, 0, 4, 0, 4, 0, 5, 4, 6, 0},
		      {0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 3, 4, 5},
		      {0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 2, 0, 0, 0},
		      {0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 2, 0, 2, 0, 0},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 2, 0, 0, 0},
		      {0, 17, 0, 0, 0, 0, 0, 0, 0, 6, 4, 0, 0, 0, 0, 2},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 2, 0}
		     };
int visited[20],n,cost=0,parent1[20],srcc;
int least(int c)
{
	int i,nc=999;
	int min=999,kmin;

	for(i=0;i < V;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0))
			if(a[c][i] < min)
			{
				min=a[i][0]+a[c][i];
				kmin=a[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=kmin;
	return nc;
}
int mq=0;
void mincost(int city,int parent1[20],int pa)
{
	int i,ncity;
	visited[city]=1;
	//printf("%d ->",city);
	mq++;
	    ncity=least(city);
	    char t=prin(city);

 	//settextstyle(2,HORIZ_DIR,6);
	//outtextxy(100,2,"%c -> ",t);
	    printf(" %c ->",t);

	//cout<<endl<<city<<" "<<ncity<<endl;
	if(ncity==999)
	{
		ncity=0;
		char t=prin(ncity);
	printf(" %c",t);


		cost+=a[city][ncity];
		return;
	}
	mincost(ncity,parent1,city);
}

void put()
{
	//printf("\n\nMinimum cost:");
	//printf("%d",cost);

	outtextxy(40,275,"Minimum Cost : ");
	//printf("\t\t\t\t\t\t%d",cost);
	//outtextxy(100,40,"%d",cost);
	//gotoxy(50,275);
	//printf("%d",cost);
	outtextxy(400,275,"64");
}


   void fun(int src, int des)
   {  int i,j,k,s1,s2,d1,d2,p,q,gdriver=DETECT,gmode;
	 initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	 // outtextxy(25,240,"Press any key to view the moving car");

	// delay(3000);

       setviewport(0,0,639,480,1);
       if(src==0)
       s1=20,s2=40;
       if(src==1)
       s1=220,s2=40;
       if(src==2)
       s1=420,s2=40;
       if(src==3)
       s1=600,s2=40;
       if(src==4)
       s1=100,s2=170;
       if(src==5)
       s1=300,s2=170;

       if(src==6)
       s1=500,s2=170;

       if(src==7)
       s1=20,s2=310;

       if(src==8)
       s1=220,s2=310;

       if(src==9)
       s1=420,s2=310;

       if(src==10)
       s1=600,s2=310;

       if(src==11)
       s1=30,s2=450;

       if(src==12)
       s1=180,s2=450;


       if(src==13)
       s1=320,s2=450;

       if(src==14)
       s1=460,s2=450;

       if(src==15)
       s1=610,s2=450;
	 if(des==0)
       d1=20,d2=40;
       if(des==1)
       d1=220,d2=40;
       if(des==2)
       d1=420,d2=40;
       if(des==3)
       d1=600,d2=40;
       if(des==4)
       d1=100,d2=170;
       if(des==5)
       d1=300,d2=170;

       if(des==6)
       d1=500,d2=170;

       if(des==7)
       d1=20,d2=310;

       if(des==8)
	d1=220,d2=310;

       if(des==9)
       d1=420,d2=310;

       if(des==10)
       d1=600,d2=310;

       if(des==11)
       d1=30,d2=450;

       if(des==12)
       d1=180,d2=450;


       if(des==13)
       d1=320,d2=450;

       if(des==14)
       d1=460,d2=450;

       if(des==15)
       d1=610,d2=450;
       p=(d1-s1)/10;
       q=(d2-s2)/10;
       s11[x]=s1;
       s21[x]=s2;
       d11[x]=d1;
       d21[x]=d2;
       x++;


	 for( i = s1,k=s2 ; i != d1||k!=d2 ; i = i + p, j++,k=k+q )
   {
	   setbkcolor(YELLOW);
	     setcolor(RED);


	   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	  outtextxy(20,40,"A");
	  outtextxy(220,40,"B");
	  outtextxy(420,40,"C");
	  outtextxy(600,40,"D");
	  outtextxy(100,170,"E");
	  outtextxy(300,170,"F");
	  outtextxy(500,170,"G");
	  outtextxy(20,310,"H");
	  outtextxy(220,310,"I");
	  outtextxy(420,310,"J");
	  outtextxy(600,310,"K");
	  outtextxy(30,450,"L");
	  outtextxy(180,450,"M");
	  outtextxy(320,450,"N");
	  outtextxy(460,450,"O");
	  outtextxy(610,450,"P");
	  circle(30,50,20);
	  circle(230,50,20);
	  circle(430,50,20);
	  circle(610,50,20);
	  circle(110,180,20);
	  circle(310,180,20);
	  circle(510,180,20);
	  circle(30,320,20);
	  circle(230,320,20);
	  circle(430,320,20);
	  circle(610,320,20);
	  circle(40,460,20);
	  circle(190,460,20);
	  circle(330,460,20);
	  circle(470,460,20);
	  circle(620,460,20);
	 line(s1,s2,d1,d2);
	 rectangle(i-30,k,10+i,k+20);
	 rectangle(i-30,k,i-10,k+20);
	 rectangle(i-25,k+5,i-15,k+15);
	 rectangle(i-5,k+5,5+i,k+15);
	 circle(i-20,20+k,3);
	 circle(i,20+k,3);
      setcolor(j);
      delay(300);

      if( i == d1&&k==d2)
	 break;

      clearviewport();

   }


   closegraph();

}
void welcome_screen()
{
setbkcolor(YELLOW);
setcolor(RED);
settextstyle(4,0,4);
outtextxy(45,30,"********** W E L C O M E **********");
settextstyle(1,0,2);
outtextxy(175,80,"BUS SERVICEs");
settextstyle(0,0,2);
outtextxy(20,175,"CREATED BY--");
settextstyle(0,0,2);
outtextxy(20,250,"Devrishee Upadhyay  Ishaan Dhamija");
outtextxy(20,300,"Jatin Sharma   Sarthak Mathur");
settextstyle(0,0,1);
outtextxy(10,375,"***press any key to continue***");
}


int minDistance(int dist[],int sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == 0 && dist[v] <= min)
	 min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int parent[], int n,int graph[V][V],int des,int time[V][V],int c)
{
int  i=des;int sum=0;int sum1=0;

   while(parent[i]!=parent[n])
     {                 fun(i,parent[i]);
     // printf("%d -----> %d   (%d)\n",i,parent[i],graph[i][parent[i]]);
sum=sum+graph[i][parent[i]];
sum1=sum1+time[i][parent[i]];
i=parent[i];
     }


i=des;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");

	   setbkcolor(YELLOW);
	     setcolor(RED);


	   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	  outtextxy(20,40,"A");
	  outtextxy(220,40,"B");
	  outtextxy(420,40,"C");
	  outtextxy(600,40,"D");
	  outtextxy(100,170,"E");
	  outtextxy(300,170,"F");
	  outtextxy(500,170,"G");
	  outtextxy(20,310,"H");
	  outtextxy(220,310,"I");
	  outtextxy(420,310,"J");
	  outtextxy(600,310,"K");
	  outtextxy(30,450,"L");
	  outtextxy(180,450,"M");
	  outtextxy(320,450,"N");
	  outtextxy(460,450,"O");
	  outtextxy(610,450,"P");
	  circle(30,50,20);
	  circle(230,50,20);
	  circle(430,50,20);
	  circle(610,50,20);
	  circle(110,180,20);
	  circle(310,180,20);
	  circle(510,180,20);
	  circle(30,320,20);
	  circle(230,320,20);
	  circle(430,320,20);
	  circle(610,320,20);
	  circle(40,460,20);
	  circle(190,460,20);
	  circle(330,460,20);
	  circle(470,460,20);
	  circle(620,460,20);
	  for(int j=0;j<x;j++)
	  {
	  line(s11[j],s21[j],d11[j],d21[j]);
	  }
	  for(int p=0;p<x;p++)
	  {
	  s11[p]=0;
	  s21[p]=0;
	  d11[p]=0;
	  d21[p]=0;
	  }
	  x=0;
	  getch();


setbkcolor(RED);
while(parent[i]!=parent[n])
{ printf("%d -----> %d    (%d) (%d) \n",i,parent[i],graph[i][parent[i]],time[i][parent[i]]);
i=parent[i];
}

if(c==1)
printf("\nTotal distance travelled== %d\nTotal cost of journey== %d\nThankyou for travelling!!!",sum,sum1);
if(c==2)
printf("\nTotal distance travelled== %d\nTotal cost of journey== %d\nThankyou for travelling!!!",sum1,sum);
getch();

}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void algo(int graph[V][V], int src,int des,int time[V][V],int c)
{
     int dist[V];     // The output array.  dist[i] will hold the shortest
     int parent[V];		      // distance from src to i

     int sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
		     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
	dist[i] = INT_MAX, sptSet[i] = 0;

     dist[src] = 0;
     parent[src]=-1;
    for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);


       sptSet[u] = 1;


       for (int v = 0; v < V; v++)

	 if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				       && dist[u]+graph[u][v] < dist[v])
	   parent[v]=u, dist[v] = dist[u] + graph[u][v];
     }

    printSolution(parent,src,graph,des,time,c);
}

int main()
{ int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"..//BGI");
//setbkcolor(GREEN);
//delay(1000);
//getch();
//closegraph();
welcome_screen();
printf("\a\a\a\a");
getch();
gotoxy(20,0);
delay(1000);
clearviewport();
		    char ch='y';
	      while(ch=='y')
	      {
	   setbkcolor(YELLOW);
	     setcolor(RED);
	      settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

	  outtextxy(260,20,"CITY-MAP");
	   settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	  outtextxy(20,40,"A");

	  line(30,50,610,50);
	  line(110,180,510,180);
	  line(30,50,110,180);
	  line(230,50,110,180);
	  line(230,50,310,180);
	  line(430,50,310,180);
	  line(610,50,510,180);
	  outtextxy(220,40,"B");
	  outtextxy(420,40,"C");
	  outtextxy(600,40,"D");
	  outtextxy(100,170,"E");
	  outtextxy(300,170,"F");
	  outtextxy(500,170,"G");
	  outtextxy(20,310,"H");
	  line(230,320,610,320);
	  line(110,180,30,320);
	  line(110,180,230,320);
	  line(110,180,430,320);
	  line(310,180,430,320);
	  line(510,180,610,320);
	  line(40,460,330,460);
	  outtextxy(220,310,"I");
	  outtextxy(420,310,"J");
	  line(190,460,430,320);
	  outtextxy(600,310,"K");
	  line(30,320,40,460);
	  line(230,320,40,460);
	  outtextxy(30,450,"L");
	  line(230,320,190,460);
	  line(430,320,330,460);
	  outtextxy(180,450,"M");
	  line(430,320,330,460);
	  line(610,320,330,460);
	  line(430,320,470,460);
	  line(610,320,470,460);
	  line(610,320,620,460);
	  outtextxy(320,450,"N");
	  outtextxy(460,450,"O");
	  line(470,460,620,460);
	  outtextxy(610,450,"P");
	  circle(30,50,20);
	  circle(230,50,20);
	  circle(430,50,20);
	  circle(610,50,20);
	  circle(110,180,20);
	  circle(310,180,20);
	  circle(510,180,20);
	  circle(30,320,20);
	  circle(230,320,20);
	  circle(430,320,20);
	  circle(610,320,20);
	  circle(40,460,20);
	  circle(190,460,20);
	  circle(330,460,20);
	  circle(470,460,20);
	  circle(620,460,20);
	  getch();
	  clearviewport();

setbkcolor(GREEN);
 cout<<"\t\t\tWELCOME\n\nThanks for choosing our bus service.\nenter your source of journey\n";
int a,b,c;
char x, y;
cout<<"\n";
cout<<"\n OPTIONS : "<<endl<<"1. for minimum time"<<endl<<"2. for minimum price"<<endl<<"3. for Travelling all cities\n";
cout<<endl;
cout<<"Choose your option :";
cin>>c;



   int graph[V][V] = {{0, 5, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {5, 0, 3, 0, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {0, 3, 0, 6, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {0, 0, 6, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {6, 5, 0, 0, 0, 3, 0, 4, 3, 5, 0, 0, 0, 0, 0, 0},
		      {0, 3, 8, 0, 3, 0, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0},
		      {0, 0, 0, 6, 0, 5, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
		      {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0},
		      {0, 0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 3, 5, 0, 0, 0},
		      {0, 0, 0, 0, 5, 3, 0, 0, 4, 0, 4, 0, 5, 4, 6, 0},
		      {0, 0, 0, 0, 0, 0, 4, 0, 0, 4, 0, 0, 0, 3, 4, 5},
		      {0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 2, 0, 0, 0},
		      {0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 0, 2, 0, 2, 0, 0},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 2, 0, 0, 0},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 4, 0, 0, 0, 0, 2},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 2, 0}
		     };
   int time[V][V] = {{0, 50, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {50, 0, 80, 0, 48, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {0, 90, 0, 30, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {0, 0, 90, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		      {70, 40, 0, 0, 0, 30, 0, 10, 20, 10, 0, 0, 0, 0, 0, 0},
		      {0, 50, 70, 0, 30, 0, 70, 0, 0, 30, 0, 0, 0, 0, 0, 0},
		      {0, 0, 0, 90, 0, 80, 0, 0, 0, 0, 80, 0, 0, 0, 0, 0},
		      {0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 60, 0, 0, 0, 0},
		      {0, 0, 0, 0, 90, 0, 0, 0, 0, 40, 0, 80, 70, 0, 0, 0},
		      {0, 0, 0, 0, 20, 30, 0, 0, 90, 0, 40, 0, 30, 50, 100, 0},
		      {0, 0, 0, 0, 0, 0, 80, 0, 0, 40, 0, 0, 0, 30, 60, 70},
		      {0, 0, 0, 0, 0, 0, 0, 60, 80, 0, 0, 0, 50, 0, 0, 0},
		      {0, 0, 0, 0, 0, 0, 0, 0, 60, 90, 0, 50, 0, 40, 0, 0},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 70, 0, 40, 0, 0, 0},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 60, 0, 0, 0, 0, 20},
		      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0, 0, 90, 0}
			};


      if(c==1)
    {
cout<<"\nEnter your Source of journey\n";
	scanf("\n%c",&y);
if(y=='a'||'A')
b=0;
if(y=='b'||y=='B')
b=1;

if(y=='c'||y=='C')
b=2;

if(y=='d'||y=='D')
b=3;

if(y=='e'||y=='E')
b=4;

if(y=='f'||y=='F')
b=5;

if(y=='g'||y=='G')
b=6;

if(y=='h'||y=='H')
b=7;

if(y=='i'||y=='I')
b=8;

if(y=='j'||y=='J')
b=9;

if(y=='k'||y=='K')
b=10;

if(y=='l'||y=='L')
b=11;

if(y=='m'||y=='M')
b=12;

if(y=='n'||y=='N')
b=13;

if(y=='o'||y=='O')
b=14;

if(y=='p'||y=='P')
b=15;


cout<<"\nEnter your destination of journey\n";
scanf("\n%c",&x);
if(x=='a'||x=='A')
a=0;
if(x=='b'||'B')
a=1;

if(x=='c'||x=='C')
a=2;

if(x=='d'||x=='D')
a=3;

if(x=='e'||x=='E')
a=4;

if(x=='f'||x=='F')
a=5;

if(x=='g'||x=='G')
a=6;

if(x=='h'||x=='H')
a=7;

if(x=='i'||x=='I')
a=8;

if(x=='j'||x=='J')
a=9;

if(x=='k'||x=='K')
a=10;

if(x=='l'||x=='L')
a=11;

if(x=='m'||x=='M')
a=12;

if(x=='n'||x=='N')
a=13;

if(x=='o'||x=='O')
a=14;

if(x=='p'||x=='P')
a=15;
algo(graph, a,b,time,c);
    }

    if(c==2)
    {
cout<<"\nEnter your Source of journey\n";
        scanf("\n%c",&y);
if(y=='a'||'A')
b=0;
if(y=='b'||y=='B')
b=1;

if(y=='c'||y=='C')
b=2;

if(y=='d'||y=='D')
b=3;

if(y=='e'||y=='E')
b=4;

if(y=='f'||y=='F')
b=5;

if(y=='g'||y=='G')
b=6;

if(y=='h'||y=='H')
b=7;

if(y=='i'||y=='I')
b=8;

if(y=='j'||y=='J')
b=9;

if(y=='k'||y=='K')
b=10;

if(y=='l'||y=='L')
b=11;

if(y=='m'||y=='M')
b=12;

if(y=='n'||y=='N')
b=13;

if(y=='o'||y=='O')
b=14;

if(y=='p'||y=='P')
b=15;


cout<<"\nEnter your destination of journey\n";
scanf("\n%c",&x);
if(x=='a'||x=='A')
a=0;
if(x=='b'||'B')
a=1;

if(x=='c'||x=='C')
a=2;

if(x=='d'||x=='D')
a=3;

if(x=='e'||x=='E')
a=4;

if(x=='f'||x=='F')
a=5;

if(x=='g'||x=='G')
a=6;

if(x=='h'||x=='H')
a=7;

if(x=='i'||x=='I')
a=8;

if(x=='j'||x=='J')
a=9;

if(x=='k'||x=='K')
a=10;

if(x=='l'||x=='L')
a=11;

if(x=='m'||x=='M')
a=12;

if(x=='n'||x=='N')
a=13;

if(x=='o'||x=='O')
a=14;

if(x=='p'||x=='P')
a=15;
algo(time, a,b,graph,c);
    }
    if(c==3)
    {
gotoxy(50,50);
//delay(1000);
clearviewport();
  //  cout<<"Enter the Starting Point:";
    //cin>>srcc;
    char tm=prin(srcc);
    int i;
	for(i=0;i < V;i++)
	{

		visited[i]=0;
	}
	for(i=0;i < V;i++)
	{

		parent1[i]=0;
	}
	//printf("\n\nThe Path is:\n\n");
	outtextxy(50,50,"The Path is : ");
	printf("--------------------------------------------------------------------------------");
	mincost(0,parent1,-1);
	printf("\n--------------------------------------------------------------------------------\n\n");
	put();
	//printSolution(parent1,0,graph,parent1[12],time,1);

    }
		 getchar();
		 printf("\n\n\nDo you want another ride y/n??\n");
		 scanf("\n%c",&ch);
		 clearviewport();    }
    return 0;
}
