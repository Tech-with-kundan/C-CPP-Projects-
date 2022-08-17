
                                                      /******* Number Shifting Game *******/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>  // these header has included for printing multiple colors 
#include<conio.h>


    int row =3 ;
    int col = 3 ;

 /*
*******  these are color section whose I  have used to print different kinds of colorful text .**********
     color code
     cyan 3
      red 4
      purple 5
      yellow (dark) 6
      default 7
      gray    8

      bright blue  9
      bright green  10
      bright cyan  11
      bright red  12
      pink 13
      yellow  14
      bright white    15


     */
int matrix[4][4];  //  global matrix .

 int move=301;
 //char * ch;
// I have coded this function to generate the random number at every time  .
void NumberGenerator(void)   

{
        // this  function is generating the numbers randomly from 1 to till 15  .

     int arr[15];
     int upper= 15;
     int lower= 1;
     int number ;
     int j;
     //int matrix[4][4];
     int index=0;
     srand(time(0));
     for(int i=0; i< 15; i++){
         number= (rand() % (upper- lower +1 )) + lower ;

         for(j=0; j<= i-1; j++){
            if(number == arr[j])
                 break;
         }
         if(i==j)
            arr[i]= number ;
         else
            i--;
     }

        for(int i=0; i< 4; i++){


            for(int j=0; j< 4; j++){
                 matrix[i][j]= arr[index++];
            }
        }




}
// Here I have coded this funtion for printing the whole matrixes . 
 void print_the_number( )
 {
      // this function is printing the randomly values on the screen   .
       for(int i=0; i<4  ; i++){
             printf("\t[");
            for(int j=0; j<4; j++)
            {

                    if(i== row   && j== col   )
                    {

                        matrix[i][j]=32;
                        printf("%4c", matrix[i][j]);
                    }
                    else
                    {

                         printf("%4d", matrix[i][j]);
                    }
            }


            printf("]\n");
         }


 }

 void upshift()
 {
    if((row>=0 && row< 4)  || ( col>=0 && col < 4 ))
    {
        // here we will perform  the swapping game
          if(row!=0){
        int temp=  matrix[row][col];
        matrix[row][col]= matrix[row-1][col];
        matrix[row-1][col]= temp ;
        row--;
          }
          else
         {

          printf("You can not go further Up  from  this  current  position  (%c) \n press any key to continue....",30);
             move++;
             getch();
         }

    }


 }
 void downshift()
 {
    if((row>=0 && row< 4) || ( col>=0 && col < 4 ))
    {
        // here we will perform  the swapping game
         if(row!=3){
         int temp =  matrix[row][col];
        matrix[row][col] = matrix[row+1][col];
        matrix[row+1][col] = temp ;
       row++;
         }
         else
         {

            printf("You can not go further down from  this  current  position   (%c) \n press any key to continue....",31);
             move++; getch();
         }

    }

 }
 void leftshift()
 {
     if((row>=0 && row< 4) || ( col>=0 && col < 4 ))
    {
        // here we will perform  the swapping game
         if(col!=0){
         int temp =  matrix[row][col];
        matrix[row][col] = matrix[row][col-1];
        matrix[row][col-1] = temp ;
       col--;
         }
         else
         {

            printf("You can not go further left from  this   current position  (%c)  \n press any key to continue.........\n",17);
             getch();
             move++;
         }

    }


 }

 void rightshift()
 {
      if((row>=0 && row<4 ) || ( col>=0 && col < 4 ))
    {
        // here we will perform  the swapping game
         if(col!=3){
         int temp =  matrix[row][col];
        matrix[row][col] = matrix[row][col+1];
        matrix[row][col+1] = temp ;
       col++;
         }
         else
         {

             printf("You can not go further  right from  this current  position  (%c)  \n press any key to continue.........\n",16);
             move++; getch();
         }

    }

 }


    int menu()
    {
          char inputkey;
     while(1)
     {

             inputkey= getch();
             if(inputkey==37 || inputkey==75)
             {


              return inputkey;
             }
            else  if(inputkey ==38 || inputkey==72)
             {

              return inputkey;
             }

             else  if(inputkey==39 || inputkey==77)
             {

              return inputkey;
             }
             else  if(inputkey==80)
             {

               return inputkey;
             }


             if(inputkey == 'E'|| inputkey == 'e')
                exit(0);
     }

    }


    void  print_the_number_in_sortted()
    {
         int  data=1;
          HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(h,14);
          printf("\t------------------\n");
          SetConsoleTextAttribute(h,15);
          for(int i=0; i<4  ; i++){
             printf("\t[");
            for(int j=0; j<4; j++)
            {
                   if(i==3 && j==3)
                   {

                       printf("    ");
                   }
                   else
                   printf("%4d", data++);
            }


            printf("]\n");
         }
          SetConsoleTextAttribute(h,14);
          printf("\t------------------\n");

    }
// I have coded this function for print all that rules of the game . 
 void Rules_of_Game()
 {
      HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,5);
       printf("\t\t\t\t MATRIX PUZZLE\t\t\t\n");
        SetConsoleTextAttribute(h,14);
       printf("\t\t\t\t---------------\t\t\n\n");
      printf("\t\t RULE OF THIS GAME\t\t\t\n\n");

       SetConsoleTextAttribute(h,6);
      printf("\t1.You can move only 1 step at a time by arrow key . \n\n");
       SetConsoleTextAttribute(h,4);
         printf("\t\tMove Left: By Left  arrow key (%c)\n",17 );
         printf("\t\tMove Right:By Right arrow key (%c) \n",16);
         printf("\t\tMove Up:   By Up arrow key    (%c)\n",30);
         printf("\t\tMove Down: By Down arrow key  (%c)\n\n",31);


       SetConsoleTextAttribute(h,3);
        printf("\t2.You can move number at empty position only  . \n");
      //  printf("\t3.You can move number at empty position only  . \n");
        printf("\t3.For each valid move : you total number of moves will decrease by 1 . \n");
        printf("\t4.Wining situation :- Number in 4 * 4 matrix should be in order from 1 to 15 . \n\n");
        printf("\t\t\tWinning situation :- \n\n");
         print_the_number_in_sortted();
          SetConsoleTextAttribute(h,13);
         printf("\n\n\tYou can exit the game at any time by pressing E or e , \n \t\tso try to win in minimum no of move \n \n");
          printf("\t\tHappy Gaming , GOOD LUCK \n\n");
          printf("\tEnter any key to start....... ");
          getch();


 }

// This printing _name is taking the user  . 
    char *  printing_name(char * ch)
      {
          HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
          SetConsoleTextAttribute(h,6);
          printf("\n\nPlayer Name: ");
          fgets(ch,   30, stdin);
          return ch;

      }
// This function I have coded here for checiking is matrix sort or not from 1 to 15 
      int Check_matrix_sort_or_NOT()
      {
          int tar= 1  ;
            for(int i=0; i<4; i++){
                for(int j=0; j<4; i++){
                        if(i==row && j==col)
                           continue;
                     if(matrix[i][j]== tar)
                            tar++;
                     else
                        return 0 ;

                }
            }
              return 1 ;

      }

       void  printing_The_matrix()
       {


            for(int i=0; i<4; i++){

                    printf("\t[") ;
                for(int j=0; j<4; j++)
                {

                    if(i==row && j== col )
                    {

                        printf("  - ");
                    }
                    else
                    {

                        printf("%4d", matrix[i][j]);
                    }
                }
                printf(" ]\n");
            }
       }
      int main()

      {


           HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);   

                char  name[30];
                char * ch= printing_name(name);
                system("cls");  // for clear the screen
             SetConsoleTextAttribute(h,4 );  // Here I have called this function for changing the color .

           Rules_of_Game();  // this function is printing all the legal rules of Game .
           system("cls");

           char c;

          NumberGenerator(); // this function is generating the randomly number .
            while(1)
            {
                   system("cls"); // this function for cleaning the screen .
                 printf("\n\n\tPlayer Name: %s ",ch);
                 printf("\n\tMove remaining : %d", move-1) ;
                  printf("\n\n");
                printf("\t------------------\n");
                 printing_The_matrix(); // Here this function is printing  all update matrix .
                printf("\t------------------\n");
                 switch(menu())
                 {

                 case 72 :
                     upshift();
                     move--;
                    break;
                 case 80 :
                     downshift();
                    move--;
                    break;
                 case 77:
                     rightshift();
                    move-- ;
                    break;
                 case 75:
                     leftshift();
                    move--;
                    break;

                 default:
                    printf("\nSorry you  can press only Left , Right, Up  and Down arrows\n");
                    getch();
                 }

                  if(move<=0)
                  {
                       if(Check_matrix_sort_or_NOT())
                       {
                             printf("\n\tMove remaining : %d", move) ;
                           SetConsoleTextAttribute(h,10 );
                           printf("\t\t YOU WIN   !");
                           printf("\nWant to play again ? ");
                            SetConsoleTextAttribute(h,9 );
                            printf("\n 'y' to play again : ");
                             fflush(stdin);
                             scanf("%c", &c);
                              if(c ==121) // I have taken ASCII code for checking  that use wants to play or not.
                              {
                                 move=300;
                                 row=3;
                                 col=3;
                                 NumberGenerator();
                              }
                              else
                              {
                                  printf("\nThank You  Press any key to exit.......");
                                  getch();
                                  exit(0);

                              }


                       }
                       else
                       {


                              SetConsoleTextAttribute(h,10 ); // Here I have called this function again to change the color text
                               printf("\t\t YOU LOSE   !");
                               printf("\nWant to play again ? ");
                               printf("\n 'y' to play again : ");
                               fflush(stdin);
                               scanf("%c", &c);

                              if(c ==121)
                              {

                                   move=300;
                                   row = 3;
                                   col = 3;
                                   NumberGenerator();
                              }
                              else
                              {
                                  printf("\nThank You  Press any key to exit.......");
                                  getch();
                                  exit(0);

                              }
                       }


                  } //this 's braces belongs to while  switch case



            }  // this 's braces belongs to while loop


          return 0;

      }  // this 's braces belongs to  main function.







