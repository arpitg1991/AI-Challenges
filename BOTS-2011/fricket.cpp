#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>

#define Emax 100
#define MAX 50
#define MOVES 50
// HS Hitting Speed for batsman
// RS Running Speed for fielder
// TS Throw Speed for fielder
// BT Bat Down Time for batsman

#define HS1 15            //Type1
#define RS1 6
#define TS1 20
#define BT1 2.0

#define HS2 20           //Type 2
#define RS2 8
#define TS2 18
#define BT2 1.5

#define HS3 25          //Type3
#define RS3 2
#define TS3 24
#define BT3 1.0

#define HS4 30          //Type4
#define RS4 4
#define TS4 22
#define BT4 0.5
/******************************************************************************
Player 1 has to be the batsmen. Player 2,3,4 would be the fielders and bowlers
******************************************************************************/
using namespace std;


struct player
{
		 float x,y;
};


//change befor to after where any co-ordinates are accesed by us

/*class energy
{
      public:
      int previous;
      int now;
      energy()
      {
              previous=100;
              now=100;
      }
}e1[4];*/
struct ball
{
	float distance,angle;
    //ANGLE IS IN RADIANS?//
}balla;
#include "player00.cpp"
#include "playerxx.cpp"
float dist(float x1, float y1, float x2, float y2)
{
		float a,b;
		if (x1>x2)
		    a=x1-x2;
        else 
             a=x2-x1;
        if (y1>y2)
           b=y1-y2;
        else
            b=y2-y1;
        return sqrt(a*a + b*b);
           
     
  
}

class hawk_eye
{
      player00 t2;
      playerxx t1;
      player before[4],after[4];
      int player_type[4];
      char arena[MAX+1][MAX+1];
      int runs,moves;
      int energy_chk[4];
      int run_calc(float run_time)
      {
          return floor(moves*run_time);
      }
      int valid_move(ball balla,int catch1,int fielder,int run_time);
      //returns 2 if batsman is out
      //returns 1 if move is valid but batsman is not out
      //returns 0 if move is invalid
      int valid_move(ball balla);//can remove player arguement, need to chk
      //returns 0 if energy left is 0
      //returns 1 is sufficient energy is there
      //returns -1 if energy for the move is insuffiecient but non-zero
      float bat_time(float run_time);
      float field_time(ball balla,int fielder);
      float is_out(float run_time,ball balla,int fielder);
      public :
      
             
             void game();
             
             float energy[4];
             hawk_eye()
             {
                 runs=0;
                 //t1.player_id=1;
                 //t2.player_id=2;
                 moves=0;
                 energy[0]=100;
                 energy[1]=100;
                 energy[2]=100;
                 energy[3]=100;
                 energy_chk[0]=0;
                 energy_chk[1]=0;
                 energy_chk[2]=0;
                 energy_chk[3]=0;
             }
             
             /*class energy
             {
                   public:
                          int energy1;
                          energy()
                          {
                                  energy1;
                          }
             }e1[4];*/
};
int hawk_eye::valid_move(ball balla,int catch1,int fielder,int run_time)
{
    if ( fielder>3 || fielder<1 )
       return 0;
    
    float x,y,x1,y1,x2,y2,x3,y3;
    x=balla.distance*cos(balla.angle);
    y=balla.distance*sin(balla.angle);
    if (catch1==1)
    {
       if (((before[fielder].x-1)<=0)&&((before[fielder].x+1)>=0)&&((before[fielder].y-1)<=0)&&((before[fielder].y+1)>=0))
       {
          return 2;
       }
       else if(before[fielder].y>0)
       {
            if ((before[fielder].y-1)>y)
               return 0;
       }
       else if (before[fielder].y<0)
       {
            if ((before[fielder].y+1)<y)
               return 0;
       }
       if(before[fielder].x>0)
       {
            if ((before[fielder].x-1)>x)
               return 0;
       }
       else if (before[fielder].x<0)
       {
            if ((before[fielder].x+1)<x)
               return 0;
       }                         
          
       if (t2.energy_double[fielder]==1)
       {
             if ((energy_chk[fielder]==0) && (energy[fielder]<10))
             {
                energy[fielder]*=2;
                energy_chk[fielder]=1;
                t2.energy_double[fielder]=0;                              
             }
             else
                 t2.energy_double[fielder]=2;
       }
       x1=before[fielder].x-1;
       if( x1<-25 )
           x1=-25;
       y1=x1*tan(balla.angle);
       y2=before[fielder].y-1;
       if ( y2<-25)
           y2=-25;
       y3=before[fielder].y+1;
       if ( y3>25)
          y3=25;
       if ((y1>=y2) && (y1<=y3))
       {
          return 2;
       }
       x1=before[fielder].x + 1;
       if( x1>25 )
           x1=25;
       y1=x1*tan(balla.angle);
       y2=before[fielder].y-1;
       if ( y2<-25)
           y2=-25;
       y3=before[fielder].y+1;
       if ( y3>25)
          y3=25;
       if ((y1>=y2) && (y1<=y3))
       {
          return 2;
       }    
          
       y1=before[fielder].y-1;
       if( y1<-25 )
           y1=-25;
       x1=y1*tan(balla.angle);
       x2=before[fielder].x-1;
       if ( x2<-25)
           x2=-25;
       x3=before[fielder].x+1;
       if ( x3>25)
          x3=25;
       if ((x1>=x2) && (x1<=x3))
          return 2;
          
       y1=before[fielder].y+1;
       if( y1<-25 )
           y1=-25;
       x1=y1*tan(balla.angle);
       x2=before[fielder].x-1;
       if ( x2<-25)
           x2=-25;
       x3=before[fielder].x+1;
       if ( x3>25)
          x3=25;
       if ((x1>=x2) && (x1<=x3))
          return 2;
       
       else
       {
           
           
          return 0;
       }
    }
    else
    {
        float x,y;
        x=balla.distance*cos(balla.angle);
        y=balla.distance*sin(balla.angle);
        float dist1=dist(x,y,before[fielder].x,before[fielder].y);
    float energy_reduce=0;
    energy_reduce=sqrt(dist1);
    if (t2.energy_double[fielder]==1)
      {
         
         if ((energy_chk[fielder]==0) && (energy[fielder]<=10))
         {
            energy[fielder]*=2;
            energy_chk[fielder]=1;  
                                      
         }
         else
             t2.energy_double[fielder]=2;
      }
    if (energy[fielder]<energy_reduce)
    {
        t2.energy_double[fielder]=0;
        return 0;
    }
    else
    {
        
        energy[fielder]-=energy_reduce;
        after[fielder].x=x;
        after[fielder].y=y;
        return 1;
    }
}
}

int hawk_eye::valid_move(ball balla)
{
    float x,y;
    float dist1;
    float energy_reduce;
    x=balla.distance*cos(balla.angle);
    y=balla.distance*sin(balla.angle);
    dist1=dist(x,y,0,0);
    energy_reduce=sqrt(dist1);
    if ((x>25) || (y>25)|| (x<-25) || (y<-25))
    {
       energy[0]-=energy_reduce;
       if (energy[0]<=0)
          return 0;

       return -1;
    }
                  
    if (energy[0]<=0)
       return 0;
    
    if (energy[0]<energy_reduce)
       return -1;
    else
    {
        energy[0]-=energy_reduce;
        return 1;
    }
}
  
float hawk_eye::bat_time(float run_time)
{
      float time=0;
      switch (player_type[0])
      {
             case 1 : time=run_time + BT1;
                      break;
             case 2 : time=run_time + BT2;
                      break;
             case 3 : time=run_time + BT3;
                      break;
             case 4 : time=run_time + BT4;
                      break;
      }
      return time;
}

float hawk_eye::field_time(ball balla,int fielder)
{
      float time=0;
      float x,y;
      x=balla.distance*cos(balla.angle);
      y=balla.distance*sin(balla.angle);
      float dist1=dist(x,y,0,0);
      float dist2=dist(x,y,before[fielder].x,before[fielder].y);
      if (t2.energy_double[fielder]==1)
      {
         time+=2;
         t2.energy_double[fielder]=0;                          
      }
      switch (player_type[0])
      {
             case 1 : time+=dist1/HS1;
                      break;
             case 2 : time+=dist1/HS2;
                      break;
             case 3 : time+=dist1/HS3;
                      break;
             case 4 : time+=dist1/HS4;
                      break;
      }
      
      switch (player_type[fielder])
      {
             case 1 : time+=dist2/RS1;
                      time+=dist1/TS1;
                      break;
             case 2 : time+=dist2/RS2;
                      time+=dist1/TS2;
                      break;
             case 3 : time+=dist2/RS3;
                      time+=dist1/TS3;
                      break;
             case 4 : time+=dist2/RS4;
                      time+=dist1/TS4;
                      break;
      }
      return time;
}
                              
float hawk_eye::is_out(float run_time,ball balla,int fielder)
{
      float time1,time2;
      float time_diff;
      time1=bat_time(run_time);
      time2=field_time(balla,fielder);
      time_diff=time2-time1;
      
      if (time2<time1)
         return time2;
      else
          return -1;
}
/*
int hawk_eye::valid_move(player after[],player before,ball balla,int playerid)
{
    //check available energy
    //check catch is possible
 
}
*/
void hawk_eye::game()
{
     int i,j,k,l,chk,chk2;

	// turn=1;
	 float run_time;//returned by batting team as to how long he wishes to take runs
	 int fielder,xfloor,yfloor,xa,xb,xc,ya,yb,yc;//returned by fielding team,as to what player is supposed to field
	 int out=0;
	 float out2=0;
	 int catch1=0;
     player_type[0]=t1.my_players[0];
     player_type[1]=t2.my_players[1];
     player_type[2]=t2.my_players[2];
     player_type[3]=t2.my_players[3];
	 before[0].x=0;              //Initial position of players
	 before[0].y=0;

	 before[1].x=-10;
	 before[1].y=-10;

	 before[2].x=10;
	 before[2].y=-10;

	 before[3].x=0;
	 before[3].y=13;
	 //ARENA
	 for (k=0;k<=MAX;k++)
	     for (l=0;l<=MAX;l++)
	         arena[k][l]='.';
  
	 for (i=0;i<4;i++)
     {
         after[i]=before[i];
     }
     while (moves<MOVES)
	 {
           moves++;        
          
           for (int yy=0;yy<=MAX;yy++)
               for (int zz=0;zz<=MAX;zz++)
                   arena[yy][zz]='.';
           run_time=t1.play(before,balla);
           for (i=0;i<4;i++)
           {
               before[i]=after[i];
           }
           chk2=valid_move(balla);
           if (chk2==1)
		   {
              
              xfloor=floor(balla.distance*cos(balla.angle))+25;
              yfloor=floor(balla.distance*sin(balla.angle))+25;
              xa=floor(before[1].x+25);
              ya=floor(before[1].y+25);
              xb=floor(before[2].x+25);
              yb=floor(before[2].y+25);
              xc=floor(before[3].x+25);
              yc=floor(before[3].y+25);
              
              arena[xa][ya]='1';
              arena[xb][yb]='2';
              arena[xc][yc]='3';
              arena[25][25]='B';
              arena[xfloor][yfloor] = 'O';
              printf("\n");
              for (k=0;k<=MAX;k++)
              {
                  for (l=0;l<=MAX;l++)
                  {
                      printf("%c",arena[k][l]);
                  }
                  printf("\n");
              }
              //printf("\n\n\t\tRUNS = %d",runs);
              
              //ARENA
	          for (k=0;k<=MAX;k++)
	              for (l=0;l<=MAX;l++)
	                  arena[k][l]='.';
          
              fielder=t2.play(before,balla,catch1,run_time);
              for (i=0;i<4;i++)
              {
                  before[i]=after[i];
              }
              chk=valid_move(balla,catch1,fielder,run_time);
              /*for (i=0;i<4;i++)
              {
                  before[i]=after[i];
              }*/
              if (chk==2)
              {
                 out=1;
              }
              else if(chk==1)
              {
                   out2=is_out(run_time,balla,fielder);
                   
                   if (out2==-1)
                   {
                      runs+=run_calc(run_time);
                      
                      out=0;
                   }//change here
                   else 
                   {
                        out=1;
                        
                        if (out2>run_time)
                           runs+=run_calc(run_time);
                        else 
                             runs+=run_calc(out2);
                   }
                   
              }
              else  //invalid move
              {
                 runs+=run_calc(run_time);
              }
           }
           else if(chk2==-1)
           {
                continue;
           }
           else
           {
               out=1;
           }
           if (out==1)
           {
              printf("\n\n\t\tBATSMAN OUT\n");
              printf("\t\tRUNS = %d\n",runs);
              getch();
              getchar();
              break;
           }
              for (i=0;i<4;i++)
              {
                  before[i]=after[i];
              }
              xa=floor(before[1].x+25);
              ya=floor(before[1].y+25);
              xb=floor(before[2].x+25);
              yb=floor(before[2].y+25);
              xc=floor(before[3].x+25);
              yc=floor(before[3].y+25);
              arena[xa][ya]='1';
              arena[xb][yb]='2';
              arena[xc][yc]='3';
              arena[25][25]='B';
           printf("\n");
           for (k=0;k<=MAX;k++)
           {
               for (l=0;l<=MAX;l++)
               {
                   printf("%c",arena[k][l]);
               }
               printf("\n");
           }
           printf("\n\n\t\tRUNS = %d",runs);
           printf("\t\tMOVES = %d \n",moves); 
           //printf("\t\tenergy = %d chk %d\n",energy[0],chk);
           //printf("\t\tx= %f y= %f\n",after[fielder].x,after[fielder].y);  
              if(moves==49)
              getchar();            
     }
}
int main()
{
    hawk_eye h;
    h.game();
}

              
