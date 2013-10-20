#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MOVES 500
#define velocity 10  



using namespace std;
class planet
{
      float x;
      float y;
      int total_ships;
      int growth;
      int owner;
      public :
             float get_x()
             {
                   return x;
             }
             float get_y(){return y;}
             int get_ships(){return total_ships;}
             int get_growth(){return growth;}
             int get_owner(){return owner;}
             
             void set_x(float x1)
             {x = x1;
                
             }
             void set_y(float y1){y = y1;}
             void set_ships(int ships1){total_ships = ships1;}
             void set_growth(int growth1){growth = growth1;}
             void set_owner(int owner1){owner = owner1;}                        
      
};
class maps
{
      public:
             planet empire[10];     
             maps ()
             {
                  //printf("am i being called \n");
                  empire[0].set_owner(1);
                  empire[9].set_owner(2);
                  for( int i = 1; i <= 8; i ++)
                       empire[i].set_owner(0);
                  if (1)
                  {
                       float a ;
                       empire[0].set_x(201.0); 
                       
                       empire[1].set_x(133.0);         
                       empire[2].set_x(486.0);         
                       empire[3].set_x(466.0);         
                       empire[4].set_x(202.0);         
                       empire[5].set_x(440.0);
                       empire[6].set_x(701.0);
                       empire[7].set_x(609.0);
                       empire[8].set_x(642.0);
                       
                       empire[9].set_x(543.0);
                       empire[0].set_y(309.0);
                       empire[1].set_y(429.0);
                       empire[2].set_y(344.0);
                       empire[3].set_y(518.0);
                       empire[4].set_y(547.0);
                       empire[5].set_y(244.0);
                       empire[6].set_y(288.0);
                       empire[7].set_y(342.0);
                       empire[8].set_y(509.0);
                       empire[9].set_y(559.0);
                       empire[0].set_ships(100); 
                       empire[1].set_ships(46);         
                       empire[2].set_ships(34);         
                       empire[3].set_ships(30);         
                       empire[4].set_ships(45);         
                       empire[5].set_ships(56);
                       empire[6].set_ships(33);
                       empire[7].set_ships(23);
                       empire[8].set_ships(45);
                       empire[9].set_ships(100);
                       empire[0].set_growth(6);
                       empire[1].set_growth(5);
                       empire[2].set_growth(4);
                       empire[3].set_growth(2);
                       empire[4].set_growth(1);
                       empire[5].set_growth(3);
                       empire[6].set_growth(5);
                       empire[7].set_growth(4);
                       empire[8].set_growth(4);
                       empire[9].set_growth(6);
                       
                  }                    
             }
};

class ships
{
      float x1;
      float y1;
      float x2;
      float y2;
      float x;
      float y;
      float dist;
      int owner;
      int active;
      int moves;
      int cur ;
      int total; 
      public :
             ships()
             {
                    active = 0;
             }
             void set_source(float a , float b)
             {
                  x1 = a;
                  y1 = b;
             }
             void set_target ( float a, float b )
             {
                  x2 = a;
                  y2 = b;
                  dist = sqrt((x1- x2)*(x1-x2) + (y1-y2)*(y1-y2));
                  moves = ceil(dist/velocity);
                  cur = 0;
                  active = 1;
             }
             void set_owner(int owned)
             {
                  owner = owned;
             }
             void set_xy ()
             {
                  cur = cur + 1;
                  x = (x2*cur + x1*(moves - cur))/(moves + 1);
                  y = (y2*cur + y1*(moves - cur))/(moves + 1);
                  if ( cur == moves )
                  {
                       x = x2;
                       y = y2;
                       active = 0;
                  }
             }
             float get_x1()
             {
                   return x1;
             }
             float get_x2()
             {
                   return x2;
             }
             float get_y1()
             {
                   return y1;
             }
             float get_y2()
             {
                   return y2;
             }
             float get_x ()
             {
                   return x;
             }
             float get_y ()
             {
                   return y;
             }
             int get_owner()
             {
                 return owner;
             }
             void set_ships(int ship)
             {
                  total = ship;
             }
             int get_ships()
             {
                 return total;
             }
             int get_active()
             {
                 return active;
             }             
};
             
             
                  
             
      
             /*
             we now initialise the coordinates of the planets for the 3 maps
             corresponding to m[1],m[2] and m[3]. 

             m[1].coord_x[1]=345;
             m[1].coord_x[2]=345;
             m[1].coord_x[3]=345;
             m[1].coord_x[4]=345;
             AND SO ON FOR m[2] and m[3] for x and y coordinates.
             We choose map using random function random(3) and then use map m[random(3)+1] as n.coord_x[i]= m[random(3)+1].coord_x[i] by running for loop.
             
             Similarly for no of spacesips m[1].spaceship_no[1]=1345 etc. and n.spaceship_no[i]= m[random(3)+1].spaceship_no[i].
             
             */
#include "player1.cpp"
#include "player2.cpp"
                  
class yoda
{
      maps map;
      ships transit[9000];
      
      player1 p1;
      player2 p2;
      int moves;
      //void validity1();//so that the planet is sending the spaceships from its own planet only and not from other planets
      int validity2(ships transit[90],int sent, int owner);//so that the planet does not send more number of spceships than it possesses
      void growth_rate();//for changing the ownership according to the growth rate of the planet
      void transit_add (ships transit1 [],int sent ) ;
      void transit_move();
      int win(int);             
      public:
             
             yoda()
             {
                       moves=0;
             } 
                       
                      // "WHERE IS MOVES DECLARED ?"
             void game();
}h;
                 
int yoda::validity2(ships transit[90],int sent, int owner)
{
     //printf("%d = sent\n", sent);
     ships transit1[90];
     int i,j,k,kkk;
     float x1 , y1, x2, y2 ,x ,y;
     int ctr = 0;
     for ( i = 0; i < 10; i ++)
     {
         x1 = map.empire[i].get_x();
         y1 = map.empire[i].get_y();
         
         //printf("first place %f %f ships = %d\n",x1,y1,map.empire[i].get_ships());
         for ( j  = 0 ; j < 10 ; j ++ ) 
         {
             if ( j == i )
                continue ;
             x2 = map.empire[j].get_x();
             y2 = map.empire[j].get_y();
             for (  k =0 ; k < sent ; k ++)
             {
                     //printf (" x1 = %f %f\n",transit[k].get_x1() , x1);
                    // printf (" y1 = %f %f\n",transit[k].get_y1() , y1);
                     //printf (" x2 = %f %f\n",transit[k].get_x2() , x2);
                     //printf (" y2 = %f %f\n",transit[k].get_y2() , y2);
                     //getchar();        
             
                 if( ( transit[k].get_x1() == x1) && ( transit[k].get_y1() == y1) && ( transit[k].get_y2() == y2) && ( transit[k].get_x2() == x2) ) 
                 {
                     //printf (" x1 = %f %f\n",transit[k].get_x1() , x1);
                    // printf (" y1 = %f %f\n",transit[k].get_y1() , y1);
                     //printf (" x2 = %f %f\n",transit[k].get_x2() , x2);
                     //printf (" y2 = %f %f\n",transit[k].get_y2() , y2);
                     //printf (" x1 = %d %d\n",transit[k].get_x1() , x1);
                     transit1[ctr] = transit[k];
                     ctr ++ ; 
         
                     break;
                 }
                 
             } 
             
         }
     }
     //printf ("ctr = %d\n",ctr);
     for ( k = 0 ; k < ctr ; k ++ )
     {
         x1 = transit1[k].get_x1();
         y1 = transit1[k].get_y1();
         x2 = transit1[k].get_x2();
         y2 = transit1[k].get_y2();
         //printf("%f %f %f %f\n",x1,y1,x2,y2);
         //getchar();
         for (i = 0; i < 10; i ++)
         {
             if (x1 == map.empire[i].get_x() && y1 == map.empire[i].get_y())
                break;
         }
         if ( i == 10 ) 
            return 0 ; // that is wrong start co-ordinates sent
            
         if ( map.empire[i].get_owner() != owner )
              return 1; // no rights to send shipd from that planet
         for (kkk = 0; kkk < 10; kkk ++)
         {
             if (x2 == map.empire[kkk].get_x() && y2 == map.empire[kkk].get_y())
                break;
         }
         if ( kkk == 10)
            return 0 ; // wrong destination co-ordinates
          
         if ( (map.empire[i].get_ships() -1 ) < transit1[k].get_ships() )
            return 2;
         else
         {
             map.empire[i].set_ships(map.empire[i].get_ships() - transit1[k].get_ships());
         }
         
     }
     
     return 3;
} // 0 for incorrect co-ordiantes 
  // 1 for incorrect ownership
  // 2 sent more no of ships than actuall  had
  // 3 everything is fine 
     

void yoda::growth_rate()
{      for(int i=0;i<10;i++)
       {
               if (map.empire[i].get_owner()!=0)
               {
                  map.empire[i].set_ships(map.empire[i].get_ships() + map.empire[i].get_growth());
               }
       }
}
void yoda :: transit_move ()
{
     float x2,y2;
     int i , j ;
     for ( i = 0 ; i < 9000 ; i ++ ) 
     {
         if ( transit[i].get_active() == 1 )
         {
              transit[i].set_xy();
              if ( transit[i].get_active() == 0 )
              {
                   x2 = transit[i].get_x2();
                   y2 = transit[i].get_y2();
                   for ( j =0 ; j < 10 ; j ++)
                   {
                       if (  x2 == map.empire[j].get_x() && y2 == map.empire[j].get_y() )
                       {
                             int cur_owner = map.empire[j].get_owner();
                             int cur_ships = map.empire[j].get_ships();
                             int transit_owner = transit[i].get_owner();
                             if ( transit_owner == cur_owner )
                             {
                                  map.empire[j].set_ships(map.empire[j].get_ships() + transit[i].get_ships() );
                             }
                             else if ( map.empire[j].get_ships() < transit[i].get_ships() )
                             {
                                  map.empire[j].set_ships(transit[i].get_ships() - map.empire[j].get_ships());
                                  map.empire[j].set_owner(transit_owner);
                                  
                             }
                             else
                             {
                                 map.empire[j].set_ships( map.empire[j].get_ships() - transit[i].get_ships());
                                  
                             }
                       }
                   }
              }
         }
     }
}
void yoda :: transit_add (ships transit1[90], int sent1)
{
     int i , j ;
     j = 0 ;
     for ( i = 0 ; i < 9000 ; i ++ )
     {
         //printf("%f %f %f %f\n",transit1[j].get_x1(),transit1[j].get_y1(),transit1[j].get_x2(),transit1[j].get_y2());
              
         if ( transit[i].get_active() == 0 )
         {
              transit[i] = transit1[j];
              
              
              
              //printf("%f %f %f %f\n",transit[i].get_x1(),transit[i].get_y1(),transit[i].get_x2(),transit[i].get_y2());
              j ++;
              //getchar();
         }
         
         
         if (j == sent1)
            break;
     }
         
     
}
int yoda :: win(int state)
{
     int i, j, owner1,owner2;
     owner1 = owner2 = 0;
     for ( i = 0 ; i < 10 ; i ++ )
     {
         if ( map.empire[i].get_owner() == 1 )
            owner1 += map.empire[i].get_ships();
         if ( map.empire[i].get_owner() == 2 )
            owner2 += map.empire[i].get_ships();
     }     
     
     printf ("ships of player1 = %d  ships of player 2 = %d\n",owner1,owner2);       
         if ( owner2 == 0 )
         {  printf ("Player 1 wins\n");
            return 1;
         }
         else if ( owner1 == 0 )
         {    
               printf (" Player 2 wins \n");
               return 1;
         }
         else if ( state == 2)
         {
              if ( owner2 < owner1 )
                 printf (" Player 1 wins " );
              else if ( owner2 > owner1 )
                   printf (" Player 2 wins " );
              else
                  printf (" plyaer1 = %d player2 = %d Match Tied\n ",owner1 , owner2 ) ;
         return 0;
         }
         return 0;
}      
          
               
void yoda::game()
{
     int flags = 0;
     while (moves<MOVES)
     {   
         moves++;
         printf (" MOVE no %d \n",moves );
         int i,vald1,vald2;
         maps tempMap,tempMap2;
         ships tempTransit[9000],tempTransit2[9000],transit1[90],transit2[90];
         int sent1, sent2;
         sent1= sent2 = 0;
         for (i = 0; i< 10 ; i++)
             tempMap2.empire[i] = map.empire[i];
         for (i = 0; i< 9000; i++)
             tempTransit2[i] = transit[i];
         
         for (i = 0; i< 10 ; i++)
             tempMap.empire[i] = map.empire[i];
         for (i = 0; i< 9000; i++)
             tempTransit[i] = transit[i];
         
         printf ( "PLAYER 1 turn \n") ;
         p1.play(tempMap,tempTransit,sent1,transit1);
         //printf ("here\n");
         vald1 = validity2(transit1,sent1,1);
         if ( vald1 == 0 )
            printf ("incorrect co-ordinates sent for planets \n"); 
         else if (vald1 == 1 )
              printf ("First you need to capture that planet, then nly  u can send ships from there \n" );
         else if (vald1 == 2 )
              printf ("Do not have that many ships\n");
         else if (vald1 == 3 )
         {
              //printf("Valid move\n\n");
              transit_add(transit1,sent1);
         }
         else
             printf ("something wrong\n");
         
         
         
         printf ( "PLAYER 2 turn \n") ;
             
         for (i = 0; i< 10 ; i++)
             tempMap.empire[i] = tempMap2.empire[i];
         for (i = 0; i< 9000; i++)
             tempTransit[i] = tempTransit2[i];
         p2.play(tempMap,tempTransit,sent2,transit2);
         
         vald2 = validity2(transit2,sent2,2);
         if ( vald2 == 0 )
            printf ("incorrect co-ordinates sent for planets \n"); 
         else if (vald2 == 1 )
              printf ("First you need to capture that planet, then only  u can send ships from there \n" );
         else if (vald2 == 2 )
              printf ("Do not have that many ships\n");
         else if (vald2 == 3 )
         {
              printf("Valid move \n\n");
              transit_add(transit2,sent2);
         }
         else
             printf ("something wrong\n");
         
         growth_rate();
        
         
         transit_move ();
         
         if (win(1))
         {
         flags = 1;
         break;
         }
         for ( int zz = 0 ; zz < 10 ; zz ++ );
             //printf (" owner = %d ships = %d \n",map.empire[zz].get_owner(),map.empire[zz].get_ships()); 
         for ( int zzz= 0 ; zzz < 9000; zzz++)
         {
             //if (transit[zzz].get_owner() == 2 )
             //{printf("%f %f %f %f\n",transit[zzz].get_x1(),transit[zzz].get_y1(),transit[zzz].get_x2(),transit[zzz].get_y2());}
         }
         getchar();        
     }
     if (!flags){
        for (int z = 0; z < 1000; z ++)
            transit_move();
            win(2);
     }
}
                    
int main()
{  
     yoda h;
     h.game();
     getch();
     
}
             
               

