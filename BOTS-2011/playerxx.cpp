#include<math.h>


class playerxx
{
      int energy[4];// u need t otake care of how energy is getting reduced urself
      
      //stores value 1 if energy is requested to be double
      //stores value 2 if energy has been requested to be doubled incorrectly
      //stores value 0 otherwise
      public:
             //int playerid;
             int energy_double[4];//make it 1 when u wish to double ur energy
             int moves;
             int my_players[4];// u need to choose all 4 types of players but not neccesarily in the order shown here
             
             float dist (float x1,float y1,float x2,float y2)
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
             
             
             playerxx()
             {
                      my_players[0]=1;
                      my_players[1]=2;
                      my_players[2]=3;
                      my_players[3]=4;
                      energy[0]=100;
                      energy[1]=100;
                      energy[2]=100;
                      energy[3]=100;
                      energy_double[0]=0;
                      energy_double[1]=0;
                      energy_double[2]=0;
                      energy_double[3]=0;
                      moves=0;
             }
             float play (player list[4],ball &balla)
             /*is called when u r batting
             u return the time upto which u wish to take runs
             list[1],list[2],list[3] gives postion of fielders
             balla , u need to specify distance and angle ,for where u wish to hit the ball
             */
             {
              moves++;
              float run_time;
                if (((moves-1)%5)==0)
                 {
                     run_time=0.5;
                     balla.distance=25;
                     balla.angle=M_PI;
                 }
                 else if (((moves-1)%5)==1)
                 {
                      run_time=0.5;
                      balla.distance=30;
                      balla.angle=3*M_PI/4;
                 }
                 else if (((moves-1)%5)==2)
                 {
                      run_time=0.5;
                      balla.distance=27;
                      balla.angle=atan(1.66);
                 }
                 else if (((moves-1)%5)==3)
                 {
                      run_time=0.5;
                      balla.distance=25;
                      balla.angle=0;
                 }
                 else 
                 {
                      run_time=0.5;
                      balla.distance=27;
                      balla.angle=-(atan(1.66));
                 }
     
                 return run_time;
                 }
             int play (player list[4],ball balla,int &catch1,float run_time)
             //would be called when u r fielding
             //list gives location of all players on field
             //player[1],player[2],player[3] gives position of ur players
             //balla gives postion of ball
             //make catch=1 if u are able to catch the ball
             //run_time is the duration for which batsman has decided to run
             {
                        moves++;
             float x,y;
             x=balla.distance*cos(balla.angle);
             y=balla.distance*sin(balla.angle);
             float dist1=dist(list[1].x,list[1].y,x,y);
             float dist2=dist(list[2].x,list[2].y,x,y);
             float dist3=dist(list[3].x,list[3].y,x,y);
             int max1,max2,max3;
             max1=max2=max3=1;
             if (dist1<dist2)
             {
               if (dist1<dist3)
                  return 1;
               else 
                    return 3;
               }
               else if (dist2 < dist3)
                    return 2;
               else 
                    return 3;
         
          
    
             }
             
};

