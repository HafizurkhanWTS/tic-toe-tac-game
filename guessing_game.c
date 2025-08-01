#include<stdio.h>
#include <stdlib.h>
#include<time.h>


int main(){
    int random, guess;
    int No_of_guess=0;
    srand(time(NULL));
    printf("welcome.. to The  World of gassing Number\n");
    random= rand()%100 +1; // Nunber Btewwn (1-100)

    do{
        printf("\nplease enter your guess number between(1 to 100) : ");
        scanf("%d",&guess);
        No_of_guess++;

        if(guess <random){
            printf("Guess larger Number. \n");
        } else if(guess> random){
        printf("Guess smaller Number. \n");
        } else{
            printf("Congratulation...!! you have seccesfully guessed the Number in %d attempts\n",No_of_guess);
        }
    }while (guess != random);
    {
        // printf("thanks for plying ...!!!");
       
    }
   return 0; 
}