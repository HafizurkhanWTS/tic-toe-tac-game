#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 3
#define x 'x'
#define o 'o'

typedef struct 
{
    int plyear;
    int computer;
    int draw;
}Score;

int  difficulty;
Score score ={.plyear = 0, .computer = 0, .draw =0};


void input_difficulty();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);
void play_game();
void player_move(char board[BOARD_SIZE][BOARD_SIZE], char player);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE], char player);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE],int row, int col);


int main(){
    srand( time(NULL));
    int choice;
     input_difficulty();
     do{
     play_game();
     printf("\nDo Play agine? (1 for YES, 0 for NO): ");
     scanf("%d", &choice);
     } while (choice == 1);
    printf("\nThanks for plying...!!");
     return 0;
}

void play_game(){
 
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},

    };
    char current_player = rand() % 2 == 0 ? x: o;  // "x" for plyear | "0" for computer
    
     print_board(board);
    while (1){
        
            if (current_player == x) {
                player_move(board,x);
                print_board(board);
                if(check_win(board, x)) {
                    score.plyear++;
                     print_board(board);
                    printf("Congratulation You Have  Won..!!");
                    break;
                }
                    current_player = o;
            }
            else{
                computer_move(board,o);
                print_board(board);
                if(check_win(board, o)) {
                    score.computer++;
                     print_board(board);
                    printf("I won !! But you Plyed Well...");
                    break;
                }
                current_player = x;
            }

            if(check_draw(board)){
                score.draw++;
                 print_board(board);
                printf("It's a draw!");
                break;
            }
        }

     
}

int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE],int row, int col){

    return !(row < 0 || col <0 || 
            row>2|| col >2 || 
            board[row][col] != ' ') ;
}

 void player_move(char board[BOARD_SIZE][BOARD_SIZE], char player){
    int row, col;
    do{
        printf("\nPlayer %c turn.", player);
        printf("\nEnter row and colum (1-3) for %c: ",player);
        scanf("%d", &row);
        scanf("%d", &col);

        row--;
        col--; //converting zero based
    } while (!is_valid_move(board,row,col));
    board[row] [col] = player;
    
    }

void computer_move(char board[BOARD_SIZE][BOARD_SIZE], char player){
    player_move(board,player);
}

int check_draw(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i= 0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player){
    for(int i=0; i< BOARD_SIZE; i++){
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player){
            return 1;
        }

        if(board[0][i] == player && board[1][i] == player && board[2][i] == player ) {
            return 1;
        }
    }

    if( (board[0][0] == player && board[1][1] == player && board[2][2] == player)||
           board[2][0] == player && board[1][1] == player && board[0][2] == player){
            return 1;
           }
           return 0;

} 


void print_board( char board[BOARD_SIZE][BOARD_SIZE]) {
    clear_screen();
    printf("Score - plyear X: %d, Computer: %d, Draws: %d",score.plyear, score.computer, score.draw);
    printf("\nTic-Tac-Toe\n");

    for(int i=0; i< BOARD_SIZE; i++){
        printf("\n");
        for(int j=0; j< BOARD_SIZE; j++){
            printf(" %c ", board[i] [j]);
            if (j < BOARD_SIZE -1){
                printf("|");
            }
        }
        if (i < BOARD_SIZE -1)
        {
            printf("\n---+---+---");
        }
        
    }
    printf("\n\n");

}


void input_difficulty(){
     while(1){
        printf("\nSelect difficulty level:");
        printf("\n1. Human(Standard)");
        printf("\n2. God(Impossible to win)");
        printf("\nEnter your choice: ");
        scanf("%d",&difficulty); 
        
        if(difficulty != 1 && difficulty != 2){
            printf("\nIncorrect choice(1/2)!!");
        }else{
            break;
        }
     };
}

void clear_screen(){
    #ifdef _Win32
     system("cls");
    #else
    system("clear");
    #endif
}