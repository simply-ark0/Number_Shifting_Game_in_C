#include<stdio.h>
#include<stdlib.h>

#define DIM 4
#define MOV 5


struct indexLoc{
    int r;
    int c;
};

int strLength(char *str){
    int i=0;
    while(str[i])
        i++;

    return i;
}

void init(int* arr){

    int temp[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    srand(time(NULL));
    int lIndex = DIM*DIM-2;
    for(int i=0; i<(DIM*DIM)-1; i++){
        int index = rand()%(lIndex+1);
        arr[i] = temp[index];
        temp[index] = temp[lIndex--];
    }

    arr[DIM*DIM-1] = 0;
}

void display(int *arr){
    printf("----------------------\n");
    for(int i=0; i<DIM; i++){
        printf("| ");
        for(int j=0; j<DIM; j++){
            if(arr[i*DIM + j] == 0){
                printf("    |");
                continue;
            }
            (arr[i*DIM + j] < 10) ? printf(" %d  |", arr[i*DIM + j])
                                  : printf(" %d |", arr[i*DIM + j]);
        }
        printf("\n");
    }
    printf("----------------------\n");
}

int checkScope(int r, int c){
    if(r>DIM-1 || r<0 || c>DIM-1 || c<0){
        printf("Outta scope!\n");
        sleep(1);
        return 0;
    }
    return 1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shift(int* arr,struct indexLoc *focus, int r, int c){
    swap(&arr[r*DIM+c], &arr[focus->r*DIM+focus->c]);
    focus->r = r;
    focus->c = c;
}

int checkWinCondition(int *arr){
    int flag = 1;
    for(int i=0; i<DIM*DIM-1; i++)
        if(arr[i] != (i+1))
            return 0;
    
    return flag;
}

void startScreen(char *name){
    system("clear");
    
    printf("Enter Your Name: ");
    fgets(name, 100, stdin);
    name[strLength(name)-1] = '\0';
}

void instructionScreen(void){

    int win[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

    system("clear");
    printf("\t\t\t\t\t-:RULE OF THIS GAME:-\n\n");
    printf("1. You can move only one step at a time by any arrow key\n");
    printf("Move Up    : by Up arrow key\n");
    printf("Move Down  : by Down arrow key\n");
    printf("Move Left  : by Left arrow key\n");
    printf("Move Right : by Right arrow key\n\n");
    printf("2. You can move number at empty position only\n\n");
    printf("3. For each valid move the total number moves will be decreased by 1\n\n");
    printf("4. Numbers in 4*4 matrix should be in order from 1 to 15\n\n");
    printf("\t\t-:Winning Situation:-\n\n");

    display(win);    

    printf("\n5. You can exit the anytime by pressing \'E\' or \'e\'\n\n");
    printf("So try to win the game in minimum number of moves!\n\n");
    printf("\t\t\t\t\tHappy Gaming, Good Luck!\n\n");
    printf("Press [Enter] to start...");
    getchar();

}

void exitScreen(int *arr, int *moves, struct indexLoc *ptr){
    if(checkWinCondition(arr)){
        system("clear");
        printf("YOU WIN, CONGO!!....:)\n");
    }
    else{
        system("clear");
        printf("YOU LOSE....:(\n");
    }

    printf("Wanna play again? [Y/N]: ");
    fflush(stdin);
    char ip = getchar();
    if((ip == 'Y') || (ip == 'y')){
        init(arr);
        *moves = 5;
        ptr->r = ptr->c = DIM-1;
    }
    else
        exit(EXIT_SUCCESS);
}