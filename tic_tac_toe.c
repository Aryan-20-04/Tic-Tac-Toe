/*
 * Tic-Tac-Toe Game in C
 * Author: Aryan Sinha
 * Description: A simple two-player Tic-Tac-Toe game implemented in C. Players take turns
 * placing their symbols (X or O) on a 3x3 grid. The first player to align three symbols
 * in a row, column, or diagonal wins. If the grid is filled without a winner, the game ends in a draw.
 * 
 * Usage: Compile the program using a C compiler (e.g., gcc). Run the executable to play.
 */

#include<stdio.h>
#define BOARD_SIZE 3 //Defined board size

//function to create the board and initialize its numbers
void create_board(char board[BOARD_SIZE][BOARD_SIZE]){
    int num=1;
    for(int i=0;i<BOARD_SIZE;i++){
        for (int j=0;j<BOARD_SIZE;j++){
            board[i][j]='0'+num++;
        }
    }
}

//function to display the board after every move
void display(char board[BOARD_SIZE][BOARD_SIZE]){
    printf("\n");
    for(int i=0;i<BOARD_SIZE;i++){
        for (int j = 0; j <BOARD_SIZE;j++)
        {
            printf(" %c",board[i][j]);
            if(j<2) printf("|");
        }printf("\n");
        if(i<2) printf("---------\n");
    }
    printf("\n");
}

//function to understand player moves
int player(char board[BOARD_SIZE][BOARD_SIZE],char symbol){
    int move;
    printf("Player %c, enter your move: ",symbol);
    while (1) {
        if (scanf("%d", &move) != 1){
            printf("Invalid input! Please enter a number between 1 and 9: ");
            while (getchar() != '\n');
            continue;
        }
    
        if (move < 1 || move > 9) {
            printf("Invalid input! Please enter a number between 1 and 9: ");
            continue;
        }

        int row=(move-1)/BOARD_SIZE;
        int col=(move-1)%BOARD_SIZE;
    
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Cell already occupied! Choose another cell: ");
            continue;
        }
    
        board[row][col]=symbol;
        return 1;
    }
}

//function to check wins
int checkWin(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return 1;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return 1;
    }

    return 0;
}

//function to check draws
int checkDraw(char board[BOARD_SIZE][BOARD_SIZE]){
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 'X'&& board[i][j]!='O') {
                return 0;
            }
        }
    }
    return 1;
}

//function which starts the game
void play(){
    char board[BOARD_SIZE][BOARD_SIZE];
    create_board(board);
    int turn=0;
    char playerSymbol[2]={'X','O'};
    while(1){
        display(board);
        if (checkWin(board)){
            display(board);
            printf("Player %c wins!\n",playerSymbol[turn]);
            break;
        }
        if (checkDraw(board)){
            display(board);
            printf("It is a draw");
            break;
        }
        turn=1-turn;
    }
}

//main function
int main(){
    printf("Welcome \n");
    play();
    return 0;
}