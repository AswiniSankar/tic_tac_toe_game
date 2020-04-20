/*#include <stdio.h>
int main() {
        int winner = 0, count = 0;
        int data[9], index, sign, player, flag, i, k, j;

        for (i = 0; i < 9; i++)
                data[i] = ' ';

        while (count < 9) {
                flag = 0;
                //system("clear");
                printf("\n\n");
                printf("\t\t\t  %c | %c  | %c  \n", data[0], data[1], data[2]);
                printf("\t\t\t----+----+----\n");
                printf("\t\t\t  %c | %c  | %c  \n", data[3], data[4], data[5]);
                printf("\t\t\t----+----+---\n");
                printf("\t\t\t  %c | %c  | %c  \n", data[6], data[7], data[8]);
                if (count % 2 == 0) {
                        sign = 'X';
                        player = 1;
                } else {
                        sign = 'Y';
                        player = 2;
                }
                printf("Move for player%d(1-9):", player);
                scanf("%d", &index);
                if (index < 1 || index > 9) {
                        printf("Allowed index is 1 to 9!!\n");
                        continue;
                }
                if (data[index - 1] == 'X' || data[index - 1] == 'Y') {
                        printf("Position Already occupied!!\n");
                        //sleep(1);
                        continue;
                }
                data[index - 1] = sign;
                count++;

                for (i = 0; i < 9; i++) {
                        if (i % 3 == 0)
                                flag = 0;

                        if (data[i] == sign)
                                flag++;

                        if (flag == 3) {
                                winner = 1;
                                goto win;
                        }
                }

                flag = 0;
                for (i = 0; i < 3; i++) {
                        for (k = i; k <= i + 6; k = k + 3) {
                                if (data[k] == sign)
                                        flag++;
                        }
                        if (flag == 3) {
                                winner = 1;
                                goto win;
                        }
                        flag = 0;
                }
                if ((data[0] == sign && data[4] == sign && data[8] == sign) ||
                        (data[2] == sign && data[4] == sign && data[6] ==  sign)) {
                        winner = 1;
                        goto win;
                }
        }
  win:
        //system("clear");
        printf("\n\n");
        printf("\t\t\t  %c | %c  | %c  \n", data[0], data[1], data[2]);
        printf("\t\t\t----+----+----\n");
        printf("\t\t\t  %c | %c  | %c  \n", data[3], data[4], data[5]);
        printf("\t\t\t----+----+---\n");
        printf("\t\t\t  %c | %c  | %c  \n\n", data[6], data[7], data[8]);
        if (winner) {
                printf("Player %d is the winner. Congrats!!\n", player);
        } else {
                printf("Match draw.. Best of luck for both\n");
        }
        return 0;
  }
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void display();
int board[9]={' '};
int main()
{
 char name1[20],name2[20],name[20];
 int i,j,count,player=1,symbol,move,choice=1,flag,winner;
  printf("\n ^!!^ WELCOME TO THE GAME WORLD ^!!^ \n");
  printf("==========================================\n");
 
 while(choice)
 {
   player=1;flag=0;winner=0,count=0;
   printf("enter the player1 name:\n");
   scanf("%s",name1);
   printf("enter the player2 name:\n");
   scanf("%s",name2);
  while(count<9)
 {
   flag = 0;
   display();
   player = (player % 2) ? 1 : 2;
   if(player==1)
     strcpy(name,name1);
   else
     strcpy(name,name2);
   printf("%s your move is[*from(1-9)]:",name);
   scanf("%d",&move);
   symbol = (player == 1) ? 'X' : 'O';

   if (move< 1 || move > 9) {
                        printf("*invalid move.the move should be from 1 to 9!!\n");
                        continue;
                }
                if (board[move - 1] == 'X' || board[move - 1] == 'O') {
                        printf("*Already moved.please enter the unoccupied positions!!\n");
                        continue;
                }
                board[move - 1] = symbol;
             count++;
         for (i = 0; i < 9; i++) {
                        if (i % 3 == 0)
                                flag = 0;

                        if (board[i] == symbol)
                                flag++;

                        if (flag == 3) {
                                winner = 1;
                                goto result;
                        }
                }

                flag = 0;
                for (i = 0; i < 3; i++) {
                        for (j = i; j <= i + 6; j = j + 3) {
                                if (board[j] == symbol)
                                        flag++;
                        }
                        if (flag == 3) {
                                winner = 1;
                                goto result;
                        }
                        flag = 0;
                }
                if ((board[0] == symbol && board[4] == symbol && board[8] ==symbol) ||
                        (board[2] == symbol && board[4] == symbol &&board[6] == symbol)) {
                        winner = 1;
                        goto result;
                }
   player++;
  
 }
 

 result:
        display();
        if (winner) 
                printf("Congrats!! %s , you won this game...\n", name);
         else
              printf("Match draw.. Better luck next time\n");
      printf("do you want an other game 1/0\n");
      scanf("%d",&choice);
      for(i=0;i<9;i++)
        board[i]=' ';
 }
return 0;
}
void display()
{  printf("\n\n");
                printf("\t\t\t  %c | %c  | %c  \n", board[0], board[1], board[2]);
                printf("\t\t\t----+----+----\n");
                printf("\t\t\t  %c | %c  | %c  \n",board[3], board[4], board[5]);
                printf("\t\t\t----+----+---\n");
                printf("\t\t\t  %c | %c  | %c  \n", board[6],board[7],board[8]);
   printf("\n\n");
}
