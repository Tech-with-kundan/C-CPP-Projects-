#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#define  SIDE 3
#define Player1 '0'
#define Player2  'X'
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std ;
 /// int round ; //1
  char turn ;
  int row=5 ;
  int col=5 ;
  char comp;
  int r ;
  char  t ;

 class Pair
 {
  public :

  pair<int,int>  p ;
  public :
   void set_Data(int r, int c)
   {
    p={r,c};
   }

    pair<int,int>  show_data()
    {
       pair<int,int> temp ;
       temp.first=p.first;
       temp.second=p.second ;
       return temp ;
    }
 };








 bool check2(char data)
 {

      if(data >= 49 && data <= 57 )
           return true;
      return false;
 }

 int menu (void);  // declaratioin of menu function .
 void CreateMatrix(char  gameboard[SIDE][SIDE])
{
  // this function is responsible for creating the  matrix of 3 * 3 and this will be our game board .
    char ch='1';
   for(int i=0; i<SIDE; i++)
   {

       for(int j=0; j<SIDE; j++)
       {

            gameboard[i][j]=ch++;
       }
   }

  turn='X';


}

 void showTheGameBoard (char gameboard[][SIDE]){
  // from the name of this function () we can easily guess that what works it might have done .  Just printing game board on the screen.
      system("cls");
   cout <<"######################################## Tic Tac Toe ############################ "<< endl<< endl;
   if( r == 1)
   {
         cout<<" Player 1 [o] :  "<<  endl ;
   }
   else if(r==3) {
   cout<<" Player 1  ["<< Player1<< "]"<<endl ;
   cout <<" Player 2  [" << Player2<<"]" <<endl;
   }
   else
   {
       cout<<" Player 1 [o] :  " ;
   }
  cout<< endl;
   cout <<"\t\t__________________"<< endl;
   cout <<"\t\t|    |     |     |"<< endl;
   cout <<"\t\t|    |     |     |"<< endl;
   cout <<"\t\t|"<<gameboard[0][0]<<"   |"<<" "<<gameboard[0][1]<<"   |"<<" "<<gameboard[0][2]<<"   |"<<endl;
   cout <<"\t\t|____|_____|_____|"<< endl;
   cout <<"\t\t|    |     |     |"<< endl;
   cout <<"\t\t|    |     |     |"<< endl;
   cout <<"\t\t|"<<gameboard[1][0]<<"   |"<<" "<<gameboard[1][1]<<"   |"<<" "<<gameboard[1][2]<<"   |"<<endl;
   cout <<"\t\t|____|_____|_____|"<< endl;
   cout <<"\t\t|    |     |     |"<< endl;
   cout <<"\t\t|    |     |     |"<< endl;
   cout <<"\t\t|"<<gameboard[2][0]<<"   |"<<" "<<gameboard[2][1]<<"   |"<<" "<<gameboard[2][2]<<"   |"<<endl;
   cout <<"\t\t|____|_____|_____|"<< endl<<endl<<endl;
   cout<<"##################################################################################"<< endl;



  }

   bool check(char data)
   {
    // Why Have I wiritten this check () function , if you want to understand about this function
    // see rowcrossed (), columncrossed() and diagonalCrossed() and then  you will get to know what exactly this function is doing .
       if (data >= 49 && data <= 57 )
        return false;
       return true ;

   }
  bool rowCrossed(char board[][SIDE])
{
  // from this function we are trying to do this work that the one by one   row is full with 'X' or 'O'
  // if it is full then return  true otherwise false
    for (int i=0; i<SIDE; i++)
    {
      if (board[i][0] == board[i][1] &&  board[i][1] == board[i][2] && check(board[i][0])) {
             t= board[i][0];
        return (true);
      }
    }

    return(false);
}
bool columnCrossed(char board[][SIDE])
{
  // from this function we are trying to do this work that one by one column is full with 'X' or 'O'
  // if it is full then return  true otherwise false
   for (int i=0; i<SIDE; i++)
   {
    if ( board[0][i] == board[1][i] &&  board[1][i] == board[2][i] &&  check(board[0][i])) {
             t= board[0][i];
    return (true);
    }
}
return(false);
}
bool diagonalCrossed(char board[][SIDE])
{

  // from this function we are trying to do this work that left diagonal  is full with 'X' or 'O'
  // if it is full then return  true otherwise false
if (board[0][0] == board[1][1]  &&   board[1][1] == board[2][2] &&  check(board[0][0])) {
                 t= board[0][0];
           return(true);
}

           // from this function we are trying to do this work that right diagonal is full with 'X' or 'O'
             // if it is full then return  true otherwise false
if (board[0][2] == board[1][1] &&  board[1][1] == board[2][0]  &&  check(board[0][2]) ) {
         t= board[0][2];
      return(true);
}
      return(false);
}


  bool Gamewinner(char gameboard[SIDE][SIDE])
 {
     // inside this function we are finding who is winner

        return (rowCrossed(gameboard) || columnCrossed(gameboard) || diagonalCrossed(gameboard)) ;


 }





 void playTicToeTacGame1(char gameboard[SIDE][SIDE], unordered_map<int, Pair> umap )
 {

     // inside this function we are creating our game board using CreateMatrix function .
   CreateMatrix(gameboard) ;   // Here With the help of  this function I am creating 3*3 matrix .

    // int c=  menu ();
     int moveindex=0;
     char id ;

     // this showTheBoard function() is only showing the our gameboard .
     showTheGameBoard(gameboard);

       bool flag=false ;
       while(true){
       int  ch ;

       // inside the while we will check each and every times which players  times has come .
       if( r ==3){
       if(turn=='X')
       {

            cout<<endl<<" Player 1 [X]  turn  : ";
       }
       else
         cout<<endl<<" Player 2 [O]  turn  : " ;
       }
       else if (r==2)
       {
             cout<<endl<<" Player 1 [O]  turn  : ";
       }
       else
         cout<<endl<<" Player 1 [O]  turn  : ";




        cin>> ch;

         // this ch varaible we  have taken in basically to match cases .
         switch(ch)
         {

           case 1:  row=0; col=0;
            break;

             case 2:  row=0; col=1;
            break;
             case 3:  row=0; col=2;
            break;
             case 4:  row=1; col=0;
            break;
             case 5:  row=1; col=1;
            break;
             case 6:  row=1; col=2;
            break;
             case 7:  row=2; col=0;
            break;
             case 8:  row=2; col=1;
            break;
             case 9:  row=2; col=2;
            break;

             default:
                cout<<" Invalid choices " ;
                getch();
                system("cls");
                break ;

         }
             bool f= false;
         if (r==3){
         if(turn =='X' && gameboard[row][col] != 'X' && gameboard[row][col] != 'O')
         {
              id=turn ;
              moveindex++;

              // cout<<endl << moveindex  ;
               //getch();
               turn = 'O';     // after the playing the first players we will give to chances to another player to play the game . That's why we are changing here turn variable .
             gameboard[row][col]='X';

             showTheGameBoard(gameboard);
         }
         else   if(turn =='O' && gameboard[row][col] != 'o' && gameboard[row][col] != 'X')
         {
             id=turn;
             moveindex++;
             //cout<<endl << moveindex  ;
             // getch();
             turn = 'X'; // // after the playing the first players we will give to chances to another player to play the game .  That's why we are changing here turn variable .
             gameboard[row][col]='O';
              showTheGameBoard(gameboard);
         }

         else
         {
               cout<<" ! BOX is already filled ! \n\t Please try again  !!!! ";
               getch();
               showTheGameBoard(gameboard); //// Here again we are printing the   new updating new board .

         }
           }
         else if ( r  == 1 )
         {
                 // this code for computer .
                 bool f= true;
                     if(row < 5 && col < 5 ) {
                    if(check2( gameboard[row][col])){
                           gameboard[row][col]='O';
                     moveindex++;
                      if(moveindex==SIDE*SIDE)
                      {
                            showTheGameBoard(gameboard);
                             cout<<" \t\t !! GAME TIE !!\n\n " << endl;
                         // getch();

                            char dec ;
                    cout<<endl <<" \t Do want to play again  !!  press ' y '  otherwise press 'n' or  any key to exit the game .... " ;
                    cin >> dec ;
                   if(dec =='y')
                   {
                    // in the case they enter y then the game will be started .
                       CreateMatrix(gameboard);
                       showTheGameBoard(gameboard);
                       moveindex=0;


                   }
                   else

                   {
                    // if they don't play again then we will simply terminate the program  by calling exit(0).
                       cout<<"---------------------------------------------------------------------------\n";
                     cout<<"| \t\t !! Thank You !!                                           | \n|\t\t Press any key to exit.....                                |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"----------------------------------------------------------------------------\n";
                      getch();

                      exit(0);
                   }
                      }
                    }
                    else
                    {
                        cout<<" BOX is already occupied " ;
                        getch();
                    }
                     }
                     showTheGameBoard(gameboard);

                    if(ch==1  || ch == 3 )
                    {
                          Pair N=umap[ch+6];
                         // N=umap[ch+8];
                          pair <int,int> D= N.show_data();
                            if(ch==1)
                            N=umap[ch+8];
                            else
                                 N=umap[ch+4];
                          pair <int,int> D1= N.show_data();

                           if (check2(gameboard[D.first][D.second]))
                           {
                               gameboard[D.first][D.second] = 'X';
                               moveindex++;
                               f=false;


                           }


                             if (check2(gameboard[D1.first][D1.second]))
                           {
                               gameboard[D1.first][D1.second] = 'X';
                               moveindex++;
                               f=false;


                           }

                            showTheGameBoard(gameboard);

                    }
                    else if(ch  == 2  || ch == 8)
                    {
                         bool flag= true;

                             // gameboard[row][col]='O';
                                if(ch==2)
                                {
                                    Pair N=umap[ch+6];
                         // N=umap[ch+8];
                              pair <int,int> D= N.show_data();
                                   if(gameboard[D.first][D.second])
                                   {

                                        gameboard[D.first][D.second]='X';
                                        moveindex++;
                                        flag=false;
                                   }


                                }
                                else
                                {
                                     Pair N=umap[ch-6];
                         // N=umap[ch+8];
                              pair <int,int> D= N.show_data();
                                   if(gameboard[D.first][D.second])
                                   {

                                        gameboard[D.first][D.second]='X';
                                        moveindex++;
                                        flag= false;
                                   }

                                }

                                 showTheGameBoard(gameboard);


                           }

                     else if (ch == 4 || ch == 6 )
                     {

                               bool flag= true;
                                if(ch==4)
                                {
                                    Pair N=umap[ch+2];
                         // N=umap[ch+8];
                              pair <int,int> D= N.show_data();
                                   if(gameboard[D.first][D.second])
                                   {

                                        gameboard[D.first][D.second]='X';
                                        moveindex++;
                                        flag= false;
                                   }


                                }
                                else
                                {
                                     Pair N=umap[ch-2];
                         // N=umap[ch+8];
                              pair <int,int> D= N.show_data();
                                   if(gameboard[D.first][D.second])
                                   {

                                        gameboard[D.first][D.second]='X';
                                        moveindex++;
                                        flag= false ;
                                   }



                           }

                              showTheGameBoard(gameboard);





                   }
                    showTheGameBoard(gameboard);
         }
         else {


                  bool f= true;
                     if(row < 5 && col < 5 ) {
                    if(check2( gameboard[row][col])){

                           gameboard[row][col]='O';
                     moveindex++;

                       if(moveindex==SIDE*SIDE)
                       {
                            showTheGameBoard(gameboard);
                          cout<<" \t\t !! GAME TIE !!\n\n " << endl;
                         // getch();

                            char dec ;
                    cout<<endl <<" \t Do want to play again  !!  press ' y '  otherwise press 'n' or any key to exit the game .... " ;
                    cin >> dec ;
                   if(dec =='y')
                   {
                    // in the case they enter y then the game will be started .
                       CreateMatrix(gameboard);
                       showTheGameBoard(gameboard);
                       moveindex=0;


                   }
                   else

                   {
                    // if they don't play again then we will simply terminate the program  by calling exit(0).
                       cout<<"---------------------------------------------------------------------------\n";
                     cout<<"| \t\t !! Thank You !!                                           | \n|\t\t Press any key to exit.....                                |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"----------------------------------------------------------------------------\n";
                      getch();

                      exit(0);
                   }
                       }

                    }
                    else
                    {

                         cout<<" BOX  is already occupied "  ;
                         getch();
                    }

                     }
                     showTheGameBoard(gameboard);

                    if(ch==1  || ch == 3 )
                    {
                          Pair N=umap[ch+6];
                         // N=umap[ch+8];
                          pair <int,int> D= N.show_data();
                            if(ch==1)
                            N=umap[ch+8];
                            else
                                 N=umap[ch+4];
                          pair <int,int> D1= N.show_data();

                           if (check2(gameboard[D.first][D.second]))
                           {
                               gameboard[D.first][D.second] = 'X';
                               moveindex++;
                               f=false;


                           }


                             if (check2(gameboard[D1.first][D1.second]))
                           {
                               gameboard[D1.first][D1.second] = 'X';
                               moveindex++;
                               f=false;


                           }


                            showTheGameBoard(gameboard);

                    }
                    else if(ch  == 2  || ch == 8)
                    {
                         bool flag= true;

                             // gameboard[row][col]='O';
                                if(ch==2)
                                {
                                    Pair N=umap[ch+6];
                         // N=umap[ch+8];
                              pair <int,int> D= N.show_data();
                                   if(gameboard[D.first][D.second])
                                   {

                                        gameboard[D.first][D.second]='X';
                                        moveindex++;
                                        flag=false;
                                   }


                                }
                                else
                                {
                                     Pair N=umap[ch-6];
                         // N=umap[ch+8];
                              pair <int,int> D= N.show_data();
                                   if(gameboard[D.first][D.second])
                                   {

                                        gameboard[D.first][D.second]='X';
                                        moveindex++;
                                        flag= false;
                                   }

                                }

                                 showTheGameBoard(gameboard);


                           }

                     else if (ch == 4 || ch == 6 )
                     {

                               bool flag= true;
                                if(ch==4)
                                {
                                    Pair N=umap[ch+2];
                         // N=umap[ch+8];
                              pair <int,int> D= N.show_data();
                                   if(gameboard[D.first][D.second])
                                   {

                                        gameboard[D.first][D.second]='X';
                                        moveindex++;
                                        flag= false;
                                   }


                                }
                                else
                                {
                                     Pair N=umap[ch-2];
                         // N=umap[ch+8];
                              pair <int,int> D= N.show_data();
                                   if(gameboard[D.first][D.second])
                                   {

                                        gameboard[D.first][D.second]='X';
                                        moveindex++;
                                        flag= false ;
                                   }



                           }

                              showTheGameBoard(gameboard);





                   }
                    showTheGameBoard(gameboard);


         }



          if ( Gamewinner(gameboard) )
         {


             // this is for winner
             if(r == 1)
             {          if(t=='O')
                   cout<<"\t\t !! Player [o]  has won !! \t\t " << endl;
                    else
                        cout<<"\t\t !! Smart Computer   has won !! \t\t " << endl;
                  // getch();
                   char dec ;
                  cout<<endl <<" \t Do want to play again  !!  press y  oterwise press 'n' or  any key to exit the game ..." ;
                  cin>> dec ;
                  // After winning the match basically the we will ask from user they want to restart game or not that's why I have wriiten this code .
                   if(dec =='y')
                   {
                       CreateMatrix(gameboard);
                       showTheGameBoard(gameboard);
                       moveindex=0;


                   }
                   else

                   {
                    // if they do not want to play again in that case this  else part will execute  and the game  will get over .
                      // if they don't play again then we will simply terminate the program  by calling exit(0).
                       cout<<"---------------------------------------------------------------------------\n";
                     cout<<"| \t\t !! Thank You !!                                           | \n|\t\t Press any key to exit.....                                |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"----------------------------------------------------------------------------\n";
                      getch();

                      exit(0);

                   }

             }
             else if (r==2)
             {


                      if(t=='O') {
                        cout<<"\t\t !! Player [o]  has won !! \t\t " << endl;
                      }
                      else
                       cout<<"\t\t !! Evil Computer   has won !! \t\t " << endl;

                  //cout<<"\t\t !! Player [o]  has won !! \t\t " << endl;
                  // getch();
                   char dec ;
                  cout<<endl <<" \t Do want to play again  !!  press y  oterwise press 'n' or any key to exit the game ..." ;
                  cin>> dec ;
                  // After winning the match basically the we will ask from user they want to restart game or not that's why I have wriiten this code .
                   if(dec =='y')
                   {
                       CreateMatrix(gameboard);
                       showTheGameBoard(gameboard);
                       moveindex=0;


                   }
                   else

                   {
                    // if they do not want to play again in that case this  else part will execute  and the game  will get over .
                       // if they don't play again then we will simply terminate the program  by calling exit(0).
                       cout<<"---------------------------------------------------------------------------\n";
                     cout<<"| \t\t !! Thank You !!                                           | \n|\t\t Press any key to exit.....                                |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"----------------------------------------------------------------------------\n";
                      getch();

                      exit(0);

                   }




             }
             else
             {

                if(turn=='x')
                      {
                          cout<<"\t\t Player 2 won " ;

                      }
                      else {
                         cout<<"\t\t Player 2 won " ;
                      }
                  //cout<<"\t\t !! Player [o]  has won !! \t\t " << endl;
                  // getch();
                   char dec ;
                  cout<<endl <<" \t Do want to play again  !!  press y  oterwise press 'n' or any key to exit the game ..." ;
                  cin>> dec ;
                  // After winning the match basically the we will ask from user they want to restart game or not that's why I have wriiten this code .
                   if(dec =='y')
                   {
                       CreateMatrix(gameboard);
                       showTheGameBoard(gameboard);
                       moveindex=0;


                   }
                   else

                   {
                    // if they don't play again then we will simply terminate the program  by calling exit(0).
                       cout<<"---------------------------------------------------------------------------\n";
                     cout<<"| \t\t !! Thank You !!                                           | \n|\t\t Press any key to exit.....                                |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"----------------------------------------------------------------------------\n";
                      getch();

                      exit(0);

                   }


             }





              }
              else  if(moveindex == SIDE * SIDE )
              {
                   if(r==1)
                   {
                          cout<<" \t\t !! GAME TIE !!\n\n " << endl;
                         // getch();

                            char dec ;
                    cout<<endl <<" \t Do want to play again  !!  press ' y '  otherwise press 'n' or any key to exit the game .... " ;
                    cin >> dec ;
                   if(dec =='y')
                   {
                    // in the case they enter y then the game will be started .
                       CreateMatrix(gameboard);
                       showTheGameBoard(gameboard);
                       moveindex=0;


                   }
                   else

                   {
                    // if they don't play again then we will simply terminate the program  by calling exit(0).
                       cout<<"---------------------------------------------------------------------------\n";
                     cout<<"| \t\t !! Thank You !!                                           | \n|\t\t Press any key to exit.....                                |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"----------------------------------------------------------------------------\n";
                      getch();

                      exit(0);
                   }
                   }
                   else  if(r==3){



                    cout<<" \t\t !! GAME TIE !! " << endl;
                    // this last code for checking the match has got tie or not , if  suppopse  in the case noone wins this game so simply this match will be tie
                    // in that we will simply do one thing what ? just we will ask from the user that they want to  play this game agian ,
                    // if they want  then they will enter 'Y'  after entering the 'Y' we we start the game from starting . Starting means new game will be started .

                     char dec ;
                    cout<<endl <<" \t Do want to play again  !!  press ' y '  otherwise press 'n' or any key to exit the game .... " ;
                    cin >> dec ;
                   if(dec =='y')
                   {
                    // in the case they enter y then the game will be started .
                       CreateMatrix(gameboard);
                       showTheGameBoard(gameboard);
                       moveindex=0;


                   }
                   else

                   {
                    // if they don't play again then we will simply terminate the program  by calling exit(0).
                        cout<<"---------------------------------------------------------------------------\n";
                     cout<<"| \t\t !! Thank You !!                                           | \n|\t\t Press any key to exit.....                                |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"----------------------------------------------------------------------------\n";
                      getch();

                      exit(0);

                   }

              }
              }


      }



 }

int menu()

{
  // this is the menu () it is only printing the some rules  game starting rules on the screen .
      cout<<"Enter your choice"<< endl;
     cout<<"\n1. Want to play with Smart Computer";
     cout<<"\n2. Want to play with Evil Computer";
     cout<<"\n3. Want to play with player ";
      cout<<"\n4.Exit" << endl;
      int ch;
      cin>>  ch;
      return ch;

}

//driver function .
  int main()
 {
  unordered_map<int, Pair> umap;
  Pair p1,p2,p3,p4,p5,p6,p7,p8,p9;
  p1.set_Data(0,0);
  umap[1]= p1 ;
  p2.set_Data(0,1);
  umap[2]= p2 ;
  p3.set_Data(0,2);
  umap[3]= p3 ;
  p4.set_Data(1,0);
  umap[4]= p4 ;
  p5.set_Data(1,1);
  umap[5]= p5 ;
  p6.set_Data(1,2);
  umap[6]= p6 ;
  p7.set_Data(2,0);
  umap[7]= p7 ;
  p8.set_Data(2,1);
  umap[8]= p8 ;
  p9.set_Data(2,2);
  umap[9]= p9 ;


     char gameboard[SIDE][SIDE];




        while (true)
        {
         r=menu();

             switch(r)
             {

             case 1:
                  playTicToeTacGame1(gameboard,umap);
                break;
             case 2:
                   playTicToeTacGame1(gameboard,umap);
                break;
             case 3:
                  playTicToeTacGame1(gameboard,umap);

                break  ;
             case 4:
                   cout<<"---------------------------------------------------------------------------\n";
                     cout<<"| \t\t !! Thank You !!                                           | \n|\t\t Press any key to exit.....                                |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"|                                                                          |\n";
                     cout<<"----------------------------------------------------------------------------\n";
                      getch();

                      exit(0);
                break ;
             default:
                cout<<" Invalid choices " ;
                 getch();

                system("cls");

             }


        }








         return  0;
 }

