#include<math.h>

class player2
{

      int id_mine ;
      int id_enemy;
      int moves;
      planet mine [10];
      planet enemy[10];
      planet others[10];
      int ctr_mine;
      int ctr_enemy;  
      int ctr_others;
          
      public:
             
             player2()
             {   
                 id_mine = 2;
                 id_enemy = 1;
                    
                 moves = 0;
                 
             };
      void play(maps map, ships transit[], int& sent,ships transit1[])
      {
        //ships transit1 [90];
        moves ++ ;
        int i, j,k,l;
        j = k = l=0;
        for ( i = 0 ; i < 10 ; i ++)
        {
            if ( map.empire[i].get_owner() == id_mine)
            {
                 mine[j] = map.empire[i];
                 j ++;
            }
            else if ( map.empire[i].get_owner() == id_enemy)
            {
                 enemy[k] = map.empire[i];
                 k ++;
            }
            else
            {
                others[l] = map.empire[i];
                l++;
            }
        }
        ctr_mine = j;
        ctr_enemy = k;
        ctr_others = l;
        srand((unsigned)time(0));
        int from;
        from = (rand()%ctr_mine);
        srand((unsigned)time(0));
        
        int to1 ;
        to1 = (rand()%ctr_enemy);
        srand((unsigned)time(0));
        
        int to2 ;
        if ( ctr_others)
        {
           srand((unsigned)time(0));
        
           to2 = (rand()%(ctr_others));
        
        /***********************
         SET "sent" = to the total directions u r sending ships in 
        ************************/
        sent = 2;
        }
        else 
             sent = 1;
        
        transit1[0].set_owner(id_mine);
        transit1[0].set_ships(mine[from].get_ships()/4);
        transit1[0].set_source(mine[from].get_x(),mine[from].get_y());
        transit1[0].set_target(enemy[to1].get_x(),enemy[to1].get_y() );
        if ( sent == 2 )
        {
         transit1[1].set_owner(id_mine);
         transit1[1].set_ships(mine[from].get_ships()/4);
         transit1[1].set_source(mine[from].get_x(), mine[from].get_y());
         transit1[1].set_target(others[to2].get_x(),others[to2].get_y());
        }
        
        
}

            
             
};

                                          


