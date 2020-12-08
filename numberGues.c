#include <stdio.h> 
#include <stdlib.h>

int randomNumber =0; 
int userInput = 0;


void makeRandomNumber(); 
void guesNumber();
void win();


void makeRandomNumber(int min, int max){ 
    randomNumber = min + rand() % (max +1 -  min);
}

void guesNumber (){
    int amountGueses =0;
    while (userInput != randomNumber)
    {
        printf("Write down your Number please\n"); 
        scanf("%i\n", &userInput);
        printf("\n");

        if (userInput == randomNumber){ 
            amountGueses+=0;
            win(amountGueses);
        }

        if (amountGueses >10){ 
            printf("This is a extra hint:\n");
            if (randomNumber %2 == 0){ 
                printf("It is a even number\n");
            }
            else {
                printf("The number is odd\n");         
            }
            
        }
        if (amountGueses >20){
            printf("\n");
            printf("This is a extra hint:\n"); 
            if (randomNumber %10 == 0 ){ 
                printf("You can devide it by 10\n");
                printf("\n");
            }
            else {
                printf("You can not devide it by 10\n");
                printf("\n");
            }
        }

        if (userInput > randomNumber){ 
            printf("The chosen numner is lower than your input\n");
            if (userInput + 10 > randomNumber){ 
                printf("You need to go lower minimus 10\n");
            }
            amountGueses++;
        }
        if (userInput < randomNumber){
            printf("The chosen number is higher than your input\n");
             if (userInput - 10 < randomNumber){ 
                printf("You need to go higher minimus 10\n");
            }
            amountGueses++;
        }

    }
    
    
}
void win(int finalAmount){ 
    printf("Congratzz\nYou have guest the number\n"); 
    printf("The number was %i\n", randomNumber);
    printf("It took you: %i amount of gueses" , finalAmount);
    exit(0);

}

int main(){ 
    makeRandomNumber(1,1000); 
    printf("Welkom to: Gues the Numer\n"); 
    printf("We've picked a numeber for you between 1 and 1000\n"); 
    printf("Goodluck in guessing the answer\n");
    guesNumber();
}
