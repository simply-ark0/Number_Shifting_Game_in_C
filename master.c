#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include "helperFile.c"


int main(){
    
    int game[DIM*DIM], moves = MOV;
    char name[100];
    init(game);
    struct indexLoc focus = {DIM-1,DIM-1};

    startScreen(name);
    instructionScreen();

    while(1){

         if(moves == 0){
            system("clear");
            printf("\tPlayer name: %s, Moves Remaining: %d\n\n", name, moves);
            display(game);
            exitScreen(game, &moves, &focus);
         }
        fflush(stdin);

        system("clear");
        printf("\tPlayer name: %s, Moves Remaining: %d\n\n", name, moves);
        display(game);


        if(getchar() == '\033'){
            getchar();
            switch(getchar()){
                case 'A':
                    if(checkScope(focus.r-1, focus.c)==0)
                        continue;
                    shift(game, &focus, focus.r-1, focus.c);
                    break;
                case 'B':
                    if(checkScope(focus.r+1, focus.c)==0)
                        continue;
                    shift(game, &focus, focus.r+1, focus.c);
                    break;
                case 'C':
                    if(checkScope(focus.r, focus.c+1)==0)
                        continue;
                    shift(game, &focus, focus.r, focus.c+1);
                    break;
                case 'D':
                    if(checkScope(focus.r, focus.c-1)==0)
                        continue;
                    shift(game, &focus, focus.r, focus.c-1);
                    break;
                default:
                    printf("INVALID I/P");
            }
        }
        else{
            printf("INVALID I/P\n");
            sleep(1);
            continue;
        }

        if(checkWinCondition(game)){
            printf("YOU WON!\n");
            return 0;
        }

        moves--;
    }

    return 0;
}