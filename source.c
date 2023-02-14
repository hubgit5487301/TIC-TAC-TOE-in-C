#include<stdio.h>
#include<conio.h>
#include<windows.h>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[45m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"

int input_arrow() //Function to return a value on a key press
{ while(1)
 {switch(getch())
  { case 72:    
     return 1;
    case 80:    
     return 2;
    case 75:    
     return 3;
    case 77:    
     return 4;
    case 13:
     return 5;
    case 27:
     return 6;
    default:
     return 7;
   }
  }
}


char display_grid_value(int b[],int grid_value)  //Function to display value in game grid
{  
   if(grid_value==1)
   {  
       return 'O';
   }
   else if(grid_value==0)
   {  
       return ' ';
   }
   else if(grid_value==-1)
   {  
       return 'X';
   }
   else if(grid_value==10)
   {
       return 'X';
   }
   else if(grid_value==11)
   {
       return 'O';
   }
   return 0;
}

void instructions_multi_player() //instructions for multi player mode
{   
    printf("                       !!!! TIC TAC TOE !!!!\n");
    printf("                    Made by Vikas Yadav 21cse71\n\n");
    printf("Instructions:- 1.Use arrow keys to move at your position of choice\n               2.Press enter to mark position\n               3.To exit at any time press escape key\n               4.Cursor always starts at center block\n");
    printf("%sX%s & %sO%s represents your current position\n",MAGENTA,RESET,MAGENTA,RESET);
    printf("Player 1 :  %sX%s\nPlayer 2 :  %sO%s\n\n",GREEN,RESET,RED,RESET);
}

void instructions_single_player() //instructions for single player mode
{   
    printf("                       !!!! TIC TAC TOE !!!!\n");
    printf("                    Made by Vikas Yadav 21cse71\n\n");
    printf("Instructions:- 1.Use arrow keys to move at your position of choice\n               2.Press enter to mark position\n               3.To exit at any time press escape key\n               4.Cursor always starts at center block\n");
    printf("%sX%s represents your current position\n",MAGENTA,RESET,MAGENTA,RESET);
    printf("Player :  %sX%s\n\n",GREEN,RESET);
}

char *color_display(int b[],int grid_value) //function to return color macro
{   
    char *color;
    if(b[grid_value]==-1)
    {    color=GREEN;
        return color;
    }
    else if(b[grid_value]==1)
    {
        color=RED;
        return color;
    } 
    else if(b[grid_value]==10||b[grid_value]==11)
    {
        color=MAGENTA;
        return color;
    }
    else
    return RESET;

}

void display_grid(int b[],int mode) //function to display the grid of game
{   
    system("cls");
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,9);
    if(mode==1)
    {
        instructions_multi_player();
    }
    else if(mode==2)
    {
        instructions_single_player();
    }
    printf("                     _________________\n");
    printf("                    |     |     |     |\n");
    printf("                    |  %s%c%s  |  %s%c%s  |  %s%c%s  |\n",color_display(b,0),display_grid_value(b,b[0]),RESET,color_display(b,1),display_grid_value(b,b[1]),RESET,color_display(b,2),display_grid_value(b,b[2]),RESET);
    printf("                    |_____|_____|_____|\n");
    printf("                    |     |     |     |\n");
    printf("                    |  %s%c%s  |  %s%c%s  |  %s%c%s  |\n",color_display(b,3),display_grid_value(b,b[3]),RESET,color_display(b,4),display_grid_value(b,b[4]),RESET,color_display(b,5),display_grid_value(b,b[5]),RESET);
    printf("                    |_____|_____|_____|\n");
    printf("                    |     |     |     |\n");
    printf("                    |  %s%c%s  |  %s%c%s  |  %s%c%s  |\n",color_display(b,6),display_grid_value(b,b[6]),RESET,color_display(b,7),display_grid_value(b,b[7]),RESET,color_display(b,8),display_grid_value(b,b[8]),RESET);
    printf("                    |_____|_____|_____|\n\n");
    
}

void store_current_position(int b[],int position,int mode,int turn) //function to store & display the marker to be pressed
{   
    int temp;
    temp=b[position];
    if(turn==1)
    {
        b[position]=10;
    }
    else if(turn==2)
    {
        b[position]=11;
    }
    display_grid(b,mode);
    b[position]=temp;
}

void player_Move(int b[],int mode,int type,int turn) // function to take & store input from player
{
    int move,position=4;
    again:
    move=0;
    while(move!=5)
   { 
    repeat:
    store_current_position(b,position,mode,turn);
    move=input_arrow();
    if(move==1)
    {
        position=position-3;
        if(position>=0&&position<=8)
        {   
            store_current_position(b,position,mode,turn);
        }
        else if(position==-1||position==-2||position==-3)
        {
            position=position+9;
            store_current_position(b,position,mode,turn);
        }
            goto repeat;
    }
    
    else if(move==2)
    {
        position=position+3;
        if(position>=0&&position<=8)
        {   
            store_current_position(b,position,mode,turn);
        }
        else if(position==10||position==9||position==11)
        {   
            position=position-9;
            store_current_position(b,position,mode,turn);
        }
        goto repeat;
    }
    
    else if(move==3)
    {   
        position--;
        if(position>=0&&position<=8)
        { 
            if(position==5)
            { 
               position=8;
            }
            else if (position==2)
            {
              position=5;
            }
            store_current_position(b,position,mode,turn); 
        }
        else if(position==-1)
        {
            position=2;
            store_current_position(b,position,mode,turn);
        }
        goto repeat;
    }
    
    else if(move==4)
    {    
        position++;
        if(position>=0&&position<=8)
         { 
           if(position==3)
            { 
                position=0;
            }
          else if (position==6)
           { 
                position=3;
                }
          store_current_position(b,position,mode,turn);}
         else
         { 
            if(position==9)
            {  
                position=6;
            }
            store_current_position(b,position,mode,turn);
         }
         goto repeat;
    }
    else if(move==6)
    {
        exit(0);
    }
   }
    if(b[position]==-1||b[position]==1)
    {
        printf("\nPosition already in use make another choice");
        getch();
        goto again;
    }
    if(type==-1)
    {
        b[position]=-1;
    }
    if(type==1)
    {
        b[position]=1;
    }
}

int winner_check(int b[]) // function to check game state of win,lose or draw
{   
    int position,wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for(position=0;position<8;position++) 
    {    
        if(b[wins[position][0]]!=0&&b[wins[position][0]]==b[wins[position][1]]&&b[wins[position][0]]==b[wins[position][2]])
        {
             return b[wins[position][2]];
        }
    }
    return 0;
}

int minimax(int b[9],int player,int depth,int max_depth) //function to return the score of next move 
{   
    int winner=winner_check(b);
    if(winner!=0||depth==max_depth) 
    {
        return winner*player;
    }
    int move=-1;
    int score=-2; 
    int i;
    for(i=0;i<9;++i) 
    {   
       if(b[i]==0) 
       {  
            b[i]=player;
            int thisScore=(-minimax(b,player*-1,depth+1,max_depth));
            if(thisScore>score) 
             {  
                score=thisScore;
                move=i;
             } 
            b[i]=0; 
        }
    }
    if(move==-1) 
    {
        return 0;
    }
    return score;
}
    
void computer_Move(int b[],int diffculty) //function to make move for the computer for single player mode
{   int max_depth;
    if(diffculty==1)
    {
        max_depth=1;
    }
    else if(diffculty==2)
    {
        max_depth=2;
    }
    else if(diffculty==3)
    {
        max_depth=10;
    }
    int move = -1;
    int score = -2;
    int i;
    for(i=0;i<9;i++) 
    {  
       if(b[i] == 0) 
       {   
            b[i] = 1;
            int tempScore=-minimax(b,-1,0,max_depth);
            b[i] = 0;
            if(tempScore > score) 
            {   
                score = tempScore;
                move = i;
            }
        }
    }
    b[move] = 1;
}

void display_game_result(int b,int mode) // function t display the  final game result
{ 
   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   if(mode==2) 
   { 
     SetConsoleTextAttribute(h,1);
     if(b==0)
      { 
        printf("\n                     !! MATCH DRAW !!\n");
       }
     else if(b==-1)
      { 
        printf("\n                       %s!! Player won !!%s\n",GREEN,RESET);
       }
     else if(b==1)
      { 
        printf("\n                     %s!! Computer won !!%s\n",RED,RESET);
      }
      SetConsoleTextAttribute(h,7);
    }  
    else if(mode==1) 
   { 
     SetConsoleTextAttribute(h,1);
     if(b==0)
      { 
        printf("\n                      !! MATCH DRAW !!\n");
       }
     else if(b==-1)
      { 
        printf("\n                     %s!! Player 1 won !!%s\n",GREEN,RESET);
       }
     else if(b==1)
      { 
        printf("\n                     %s!! Player 2 won !!%s\n",RED,RESET);
      }
      SetConsoleTextAttribute(h,7);
    } 
   
}

void display_choice(int choice) // function to display the choice of user in menu with different color
{
    if(choice==1)
    {
       printf("Choice: %s%d%s",RED,choice,RESET); 
    }
    else if(choice==2)
    {
        printf("Choice: %s%d%s",GREEN,choice,RESET);
    }
    else if(choice==3)
    {
        printf("Choice: %s%d%s",YELLOW,choice,RESET);
    }
}

void display_choice_for_difficulty(int choice)// function to display the choice of user in selecting difficulty
{
    if(choice==1)
    {
       printf("Choice: %s%d%s",YELLOW,choice,RESET); 
    }
    else if(choice==2)
    {
        printf("Choice: %s%d%s",ORANGE,choice,RESET);
    }
    else if(choice==3)
    {
        printf("Choice: %s%d%s",RED,choice,RESET);
    }
}

int menu() // function to display and return the choice of user from menu
{ 
  int choice=1,move;
  system("cls");
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(h,9);
  printf("                       !!!! TIC TAC TOE !!!!\n");
  printf("                    Made by Vikas Yadav 21cse71\n\n");
  printf("Instructions:-Use UP & DOWN arrow keys to make your choice and press enter\n");
  printf("\n     Menu\n%s1:Multiplayer Mode%s\n%s2:Singleplayer Mode%s\n%s3:Exit%s\n\n",RED,RESET,GREEN,RESET,YELLOW,RESET);
  SetConsoleTextAttribute(h,7);
  printf("Choice: %s%d%s",RED,choice,RESET);
  while(move!=5)
  { 
    repeat:
    move=0;
    move=input_arrow();
    if(move==1)
    {  
        choice--;
        if(choice>=1&&choice<=3)
        {
            printf("\x1b[2K");
            printf("\r");
            display_choice(choice);
        }
        else if(choice==0)
        {
            choice=3;
            printf("\x1b[2K");
            printf("\r");
            display_choice(choice);
        }
        goto repeat;
    }
    else if(move==2)
    { 
        choice++;
        if(choice>=1&&choice<=3)
        {
            printf("\x1b[2K");
            printf("\r");
            display_choice(choice);
        }
        else if(choice==4)
        {
            choice=1;
            printf("\x1b[2K");
            printf("\r");
            display_choice(choice);
        }
    
        goto repeat;
    }
 }
 return choice;
}

int difficulty_lvl_minimax() // function to select difficulty for single player mode
{
  int choice=1,move=0;
  system("cls");
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(h,9);
  printf("                       !!!! TIC TAC TOE !!!!\n");
  printf("                    Made by Vikas Yadav 21cse71\n\n");
  printf("Instructions:-Use UP & DOWN arrow keys to make your choice and press enter");
  printf("\nSelect Level\n");
  printf("\n%s1.Easy%s\n%s2.Meduim%s\n%s3.Hard%s\n",YELLOW,RESET,ORANGE,RESET,RED,RESET);
  SetConsoleTextAttribute(h,7);
  printf("Choice: %s%d%s",RED,choice,RESET);
  while(move!=5)
  { 
    repeat:
    move=0;
    move=input_arrow();
    if(move==1)
    {  
        choice--;
        if(choice>=1&&choice<=3)
        {
            printf("\x1b[2K");
            printf("\r");
            display_choice_for_difficulty(choice);
        }
        else if(choice==0)
        {
            choice=3;
            printf("\x1b[2K");
            printf("\r");
            display_choice_for_difficulty(choice);
        }
        goto repeat;
    }
    else if(move==2)
    { 
        choice++;
        if(choice>=1&&choice<=3)
        {
            printf("\x1b[2K");
            printf("\r");
            display_choice_for_difficulty(choice);
        }
        else if(choice==4)
        {
            choice=1;
            printf("\x1b[2K");
            printf("\r");
            display_choice_for_difficulty(choice);
        }
    
        goto repeat;
    }
 }
 return choice;
}


int main() // main function
{  
  int b[9],replay=0,grid_input_0;
  int mode;
  restart:
  grid_input_0=0;
  while(grid_input_0<=8)
  {
    b[grid_input_0]=0;
    grid_input_0++;
  }
  mode=menu();
  if(mode==3)
  { 
    system("cls");
    exit (0);
  }
  else if(mode==1)
  { 
    display_grid(b,mode);
    for(int t=0;t<9&&winner_check(b)==0;t++) 
    { 
      if ((t+1)%2==0)    
      {  
         player_Move(b,1,1,2);
         display_grid(b,1);
      }
      else    
      {
         player_Move(b,1,-1,1);
         display_grid(b,1);
      }
    }
  }
  
  else if(mode==2)
  { int lvl_choice;
    lvl_choice=difficulty_lvl_minimax();
    display_grid(b,mode);
    for(int t=0;t<9&&winner_check(b)==0;t++) 
    { 
      if ((t+1)%2==0)    
      {  
         computer_Move(b,lvl_choice);
         display_grid(b,2);
      }
      else    
      {
         player_Move(b,mode,-1,1);
         display_grid(b,2);
      }
    }
  }
  display_game_result(winner_check(b),mode);
  printf("\n1.Press Enter to Replay\n2.Press Escape to Exit\n");
  repeat1:
  replay=input_arrow();
  if(replay==5)
  {
    goto restart;
  }
  else if(replay==6)
  {   
      system("cls");
      printf("\nTHANK YOU FOR PLAYING\n");
      getch();
   }
   else if(replay==7)
   {
    printf("\x1b[2K");
    printf("\r");
    printf("Wrong input try again");
    goto repeat1;
   }
   else
   {
    printf("\x1b[2K");
    printf("\r");
    printf("Wrong input try again");
    goto repeat1;
   }
return 0;
}
