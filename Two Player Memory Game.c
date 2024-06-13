#Cengiz Demiray
#2526960
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int boardsize(int );
int initializeboard(char **,int);
int getcoordinates(char **,char**,int *,int *,int *,int *,int);
void display(char **,int);
int checkcharacters(char **,char **,int *,int *,int *,int *,int);
int yourscore(char **,char **,int *,int *, int *, int *,int);
int main() {

    srand(time(NULL));
    int size,valid_size,i,row1,row2,column1,column2,j;
    char ch;
    char **p,**arr;
    printf("Welcome to MemoME\n");
    do {
        printf("Please specify the board size (2-32):");
        scanf("%d", &size);
        valid_size = boardsize(size);    // function call that aims to determine size of board
        printf("A board is created for you with the size of %dx%d\n", valid_size, valid_size);
        p = (char **) malloc(sizeof(char *) * valid_size);   // dynamic memory allocation
        if (p == NULL) {   // ın case of allocation fail
            printf("There are memory problem");
            exit(1);
        }
        for (i = 1; i <= valid_size; i++) {
            p[i] = (char *) malloc(sizeof(char) * valid_size);   //dynamic memory allocation
            if (p[i] == NULL) {   //in case of allocation fail
                printf("There are memory problem");
                exit(1);
            }
        }
        for (i = 1; i <=valid_size; i++) {
            for (j = 1; j <=valid_size; j++) {
                p[i][j] = ' ';    //assigning every element of p to space
            }
        }

        arr = (char **) malloc(sizeof(char *) * valid_size);  //dynamic memory allocation
        if (arr == NULL) {      //in case of allocation failed
            printf("There is a problem in memory");
            exit(1);
        }
        for (i = 1; i <= valid_size; i++) {
            arr[i] = (char *) malloc(sizeof(char) * valid_size);   //continuation of dynamic memory allocation
            if (arr[i] == NULL) {   // in case of allocation failed
                printf("There is a problem in memory");
                exit(1);
            }
        }
        for (i = 1; i <= valid_size; i++) {
            for (j = 1; j <= valid_size; j++) {
                arr[i][j] = '@';    //assigning every element of arr to @
            }
        }

        initializeboard(p, valid_size);  //function call to initialize my array
        getcoordinates(p, arr, &row1, &column1, &row2, &column2, valid_size);  //function call that take some numbers from user
        printf("\nWould you like to play again (Y/N) ?");
        fflush(stdin);  //for cleaining buffer
        scanf("%c",&ch);
    }while(ch=='Y');//if user enter Y do not break out while loop
    if(ch=='N')
        printf("Byee");

    return 0;
}
int boardsize(int size){
    int x=1;
    while(x==1) {   // I used x variable as controller if I enter one of the if, then for taking input again I need stay in while loop
        if ((size % 2 != 0) && ((size >= 2) && (size <= 32))) {   // if my input between 2-32 and not dividable by 2 take input again
            printf("Board size can only be multiple of two.\n");
            printf("Please specify the boardsize (2-32):");
            scanf("%d", &size);
            x=1;
        }
        else if (!((size >= 2) && (size <= 32))) {  //if my input is not between 2-32 take input again
            printf("Board size can only be between 2-32!\n");
            printf("Please specify the boardsize (2-32):");
            scanf("%d", &size);
            x=1;
        }
        else
            x=0;
    }
    return size;
}
int initializeboard(char **p,int valid_size){
    int i,j,k,counter;
    for(i=1;i<=valid_size;i++) { // I used this for loop for taking different char that is equal to number of my size
        counter=0;
        while (counter < valid_size) {  //I used while for showing how many times I pick up only one character
            j = 1+ (int) rand() % valid_size;   // I assign indexs randomly
            k = 1 + (int) rand() % valid_size;

            while (p[j][k] == ' ') {
                p[j][k] = '!'+i;   //I assign elements of array by starting with ! , and then other characters based on i value.
                counter++;
            }
        }
    }

    return 1;
}

int getcoordinates(char **p,char **arr,int *row1,int *column1, int *row2,int *column2,int valid_size) {
    int check = 1, check2 = 1, count = 0, y, total1 = 0, total2 = 0;

    display(arr, valid_size);  // this function called for showing initial board
    while (count < (valid_size * valid_size)) {  //while loop determines how many times executed by looking at number of opened elements
        printf("\n--Player1 Turn:--\n");
        printf("Enter coordinates of doors to open:");
        scanf("%d %d %d %d", row1, column1, row2, column2);
        while (check) {   // I used check as a controller, if it's value other than zero we will execute while loop
            check = 0;  //I assume every coordinat is valid at the initial
            while ((*row1 >= valid_size) || (*row2 >= valid_size) || (*column1 >= valid_size) ||
                   (*column2 >= valid_size)) {
                printf("Sorry wrong coordinates!\n");
                printf("Enter the coordinates of doors to open:");
                scanf("%d %d %d %d", row1, column1, row2, column2);
                check = 1; //if it is not valid assign check to 1 for entering coordinate again
            }
            while ((*row1 == *row2) && (*column1 == *column2)) {
                printf("Sorry two coordinates are the same!\n");
                printf("Enter the coordinates of the doors to open");
                scanf("%d %d %d %d", row1, column1, row2, column2);
                check = 1;
            }
        }
        while (arr[*row1][*column1] != '@') {   // if my elements of array are not @ then these elements matched and we can not use them again
            printf("(%d %d) are already opened\n", *row1, *column1);
            printf("Enter the coordinates of the doors to open");
            scanf("%d %d %d %d", row1, column1, row2, column2); //entering value again for taking unopenned elements
        }
        while (arr[*row2][*column2] != '@') {      // same as above but for second row and column
            printf("(%d %d) are already opened\n", *row2, *column2);
            printf("Enter the coordinates of the doors to open");
            scanf("%d %d %d %d", row1, column1, row2, column2);
        }
        y = checkcharacters(p, arr, row1, column1, row2, column2, valid_size);  // after taking valid coordinates I call function for checking my character matched
        if (y == 0) {  // if it is not matched enter if
            arr[*row1][*column1] = p[*row1][*column1];  //I assign new elements for just showing board
            arr[*row2][*column2] = p[*row2][*column2];  // same as above
            display(arr, valid_size);  //for displaying board
            printf("Unlucky!");
            total1 += yourscore(p, arr, row1, column1, row2, column2, valid_size);  //When unmatched call function for calculating score
            printf(",totalscore:%d", total1);
            arr[*row1][*column1] = '@';   //when it is unmatched for closing these elements I reassign them to @
            arr[*row2][*column2] = '@';   //same as above
        } else {  // if it is matched enter else
            arr[*row1][*column1] = p[*row1][*column1];    //when matched for showing matched elements I assign these elements to second array
            arr[*row2][*column2] = p[*row2][*column2];    // same as above
            display(arr, valid_size);                     //for showing opened elements
            printf("Lucky you!");
            total1 += yourscore(p, arr, row1, column1, row2, column2, valid_size);  //when matched call function for calculating score
            printf(",totalscore:%d", total1);
            count += 2;   //I increment count only if opened character matched and every step I open 2 char if it is matched I added count to 2 for ending at the top of the while loop at some point
        }
        if(count<valid_size*valid_size) {  // I used this if for if my count is not equal to square valid size continue with player2
            printf("\n--Player2 Turn:--\n");  // everythig remains until ending of if is same as above I used same algorithm for player2
            printf("Enter coordinates of doors to open:");
            scanf("%d %d %d %d", row1, column1, row2, column2);
            while (check2) {
                check2 = 0;
                while ((*row1 > valid_size) || (*row2 > valid_size) || (*column1 > valid_size) ||
                       (*column2 > valid_size)) {
                    printf("Sorry wrong coordinates!\n");
                    printf("Enter the coordinates of doors to open:");
                    scanf("%d %d %d %d", row1, column1, row2, column2);
                    check2 = 1;
                }
                while (*row1 == *row2 && *column1 == *column2) {
                    printf("Sorry two coordinates are the same!\n");
                    printf("Enter the coordinates of the doors to open");
                    scanf("%d %d %d %d", row1, column1, row2, column2);
                    check2 = 1;
                }
            }
            while (arr[*row1][*column1] != '@') {
                printf("(%d %d) are already opened\n", *row1, *column1);
                printf("Enter the coordinates of the doors to open");
                scanf("%d %d %d %d", row1, column1, row2, column2);
            }
            while (arr[*row2][*column2] != '@') {
                printf("(%d %d) are already opened", *row2, *column2);
                printf("Enter the coordinates of the doors to open");
                scanf("%d %d %d %d", row1, column1, row2, column2);
            }
            y = checkcharacters(p, arr, row1, column1, row2, column2, valid_size);
            if (y == 0) {
                arr[*row1][*column1] = p[*row1][*column1];
                arr[*row2][*column2] = p[*row2][*column2];
                display(arr, valid_size);
                printf("Unlucky!");
                total2 += yourscore(p, arr, row1, column1, row2, column2, valid_size);
                printf(",totalscore:%d", total2);
                arr[*row1][*column1] = '@';
                arr[*row2][*column2] = '@';
            } else {
                arr[*row1][*column1] = p[*row1][*column1];
                arr[*row2][*column2] = p[*row2][*column2];
                display(arr, valid_size);
                printf("Lucky you!");
                total2 += yourscore(p, arr, row1, column1, row2, column2, valid_size);
                printf(",totalscore:%d", total2);
                count += 2;
            }
        }
}
    if(total2>total1){     // when all elemetns opened for deciding who is the winner if total 2 is greater than total 1 player2 wins
        printf("\n***Winner is Player 2***");
    }
    else if(total1==total2){ // when total1 is equal to total 2 there are no winner
               printf("\n***There are no winner***");
    }
    else //if total1 is greater than total2 player1 wins
        printf("\n***Winner is Player 1");

    return 1;
}
void display(char **arr, int valid_size) {  //this algorithm for printing to screen two dimensional array
    int i, j;
    printf("\n");
    for (i = 1; i <= valid_size; i++) {

        for (j = 1; j <=valid_size; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}
int checkcharacters(char **p,char **arr,int *row1,int *column1, int *row2, int *column2, int valid_size){ //take two elements from the array compare them if they are equal return 1 otherwise return 0
    if(p[*row1][*column1]==p[*row2][*column2]){
        return 1;
    }
    return 0;
}
int yourscore(char **p,char **arr, int *row1, int *column1, int *row2, int *column2 ,int valid_size){
    int yourscore=0,totalscore=0,y;
    y=checkcharacters(p,arr,row1,column1,row2,column2,valid_size);
    if(y==1){ //if my elements matched yourscore is 2 and add this yourscore to totalscore
        yourscore+=2;
        totalscore+=yourscore;
        printf("Your score:%d",yourscore);
    }
    else{ //if my elements unmatched yourscore is -1 and add this yourscore to totalscore
        yourscore-=1;
        totalscore+=yourscore;
        printf("Yourscore:%d",yourscore);
    }
    return totalscore;
}
