//Cengiz Demiray
//2526960
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int roll_a_dice();
int play_user();
int play_computer();
void scoresheet(int,int);
int main() {
    srand(time(NULL));
    int round,roll1,roll2,myscore=0,yourscore=0,i=1;
    printf("Welcome to Drop Dead game.\n");
    printf("Lets get started!\n");
    printf("How many round would you like to play? "); // to determine how many rounds we play
    scanf("%d",&round);
    roll1=roll_a_dice(); // roll dice only once for who begin first
    roll2=roll_a_dice();  // roll dice only once for who begin first
    while(roll1==roll2){  //if dices are equal this is invalid roll dices again
        printf("I have rolled dice and got %d\n",roll1);
        printf("I have rolled dice for you and you got %d\n",roll2);
        printf("Dice can not be same!\nPlease roll dice again.");
        roll1=roll_a_dice();
        roll2=roll_a_dice();
    }
    printf("I have rolled dice and got %d\n",roll1);
    printf("I have rolled dice for you and you got %d\n",roll2);
    if(roll2>roll1){  //if roll2 greater than roll1 user begin first
        while(i<=round){ //this while loop executes number of rounds time
            printf("\nRound %d -- Your turn:", i);
            printf("\n=================================================================================================\n");
            yourscore+=play_user(); // at the end of every tour for obtaining total yourscore add function return value
            printf("\nRound %d -- My turn:", i);
            printf("\n==================================================================================================\n");
            myscore+=play_computer(); // at the end of every tour for obtaining total myscore add function return value
            i++;    //increment i until i greater than round
        }
    }
    else{
        while(i<=round){ //this while loop executes number of rounds time
            printf("\nRound %d -- My turn:",i);
            printf("\n=================================================================================================\n");
            myscore+=play_computer(); // at the end of every tour for obtaining total myscore add function return value
            printf("\nRound %d -- Your turn:",i);
            printf("\n==================================================================================================\n");
            yourscore+=play_user(); // at the end of every tour for obtaining total yourscore add function return value
            i++;   //increment i until i greater than round
        }

    }
    scoresheet(myscore,yourscore);  //scoresheet function called to print final scores
    return 0;
}
int roll_a_dice(){    // for taking random values of dice
    return 1+(int)rand()%6;
}
int play_user(){
    int dice1,dice2,dice3,dice4,dice5,dicenum=5,x,i=1,yourscore,totalscore=0,valid1=1,valid2=1,valid3=1,valid4=1,valid5=1;
    printf("\nAre you ready to play!\n");
    printf("I rolled them for you and you got\n");
    dice1=roll_a_dice();  //for taking random values of dice 1 roll_a_dice function called
    dice2=roll_a_dice();  //for taking random values of dice 2 roll_a_dice function called
    dice3=roll_a_dice();  //for taking random values of dice 3 roll_a_dice function called
    dice4=roll_a_dice();  //for taking random values of dice 4 roll_a_dice function called
    dice5=roll_a_dice();  //for taking random values of dice 5 roll_a_dice function called

    printf("[dice1]: %d [dice2]: %d [dice3]: %d [dice4]: %d [dice5]: %d\n", dice1, dice2, dice3, dice4, dice5); //when dices rolled first time print all of them
    do{
        yourscore=0; // at the beggining of rolling dice again assign yourscore to 0 for calculating values of each tour
        x=1;         // assume that at the begining of every tour all dices are valid then according to values change x value
        if(dice1==2 || dice1==5){  //if dice1 2 or 5 dice1 are invalid
            x=0;                   // assign x to 0 because dice 1 is invalid
            valid1=0;              // for future use keep valid1 equal to 0
            dicenum--;             // because of the invalid dice decrement number of dice
        }
        if(dice2==2 || dice2==5){  //if dice2 2 or 5 dice2 are invalid
            x=0;                   // assign x to 0 because dice 2 is invalid
            valid2=0;              // for future use keep valid2 equal to 0
            dicenum--;             // because of the invalid dice decrement number of dice
        }
        if(dice3==2 || dice3==5){  //if dice3 2 or 5 dice3 are invalid
            x=0;                   // assign x to 0 because dice 3 is invalid
            valid3=0;              // for future use keep valid3 equal to 0
            dicenum--;             // because of the invalid dice decrement number of dice
        }
        if(dice4==2 || dice4==5){  //if dice4 2 or 5 dice4 are invalid
            x=0;                   // assign x to 0 because dice 4 is invalid
            valid4=0;              // for future use keep valid4 equal to 0
            dicenum--;             // because of the invalid dice decrement number of dice
        }
        if(dice5==2 || dice5==5){  //if dice5 2 or 5 dice5 are invalid
            x=0;                   // assign x to 0 because dice 5 is invalid
            valid5=0;              // for future use keep valid1 equal to 0
            dicenum--;             // because of the invalid dice decrement number of dice
        }
        if(x==1){                 // if x==1 this means if my dice values are valid
            if(valid1==1)
                yourscore+=dice1;  // add to dice 1 value to yourscore
            if(valid2==1)
                yourscore+=dice2;  // add to dice 2 value to yourscore
            if(valid3==1)
                yourscore+=dice3;  // add to dice 3 value to yourscore
            if(valid4==1)
                yourscore+=dice4;  // add to dice 4 value to yourscore
            if(valid5==1)
                yourscore+=dice5;  // add to dice 5 value to yourscore
        }
        printf("\nyourscore:%d",yourscore);  // if all of the dices is valid print yourscore
        totalscore+=yourscore;     // add yourscore to total score for storing values of previous tour
        printf(" totalscore:%d\n",totalscore);
        if(x==0){       // if x==0 this means that if at least one of my dices are invalid
            yourscore=0;    //yourscore will be 0 if at least one of my dices are invalid
            if(valid1==0) {  // if dice 1 is invalid executes if loop
                printf("Dice 1 ");
                valid1 = 2;   // for not printing again and again same excluded dice assign valid1 to 2.
                dice1=0;      //again for not assigning valid1 to 0 assign dice 1 to 0 otherwise dice 1 are printed again
            }
            if(valid2==0) {
                printf("Dice 2 ");
                valid2 = 2;  // for not printing again and again same excluded dice assign valid2 to 2.
                dice2=0;     //again for not assigning valid2 to 0 assign dice 2 to 0 otherwise dice 2 are printed again
            }
            if(valid3==0) {
                printf("Dice 3 ");
                valid3 = 2;  // for not printing again and again same excluded dice assign valid3 to 2.
                dice3=0;     //again for not assigning valid3 to 0 assign dice 3 to 0 otherwise dice 1 are printed again
            }
            if(valid4==0) {
                printf("Dice 4 ");
                valid4=2;  // for not printing again and again same excluded dice assign valid4 to 2.
                dice4=0;   //again for not assigning valid4 to 0 assign dice 1 to 0 otherwise dice 4 are printed again
            }
            if(valid5==0) {
                printf("Dice 5 ");
                valid5=2;  // for not printing again and again same excluded dice assign valid5 to 2.
                dice5=0;   //again for not assigning valid5 to 0 assign dice 5 to 0 otherwise dice 1 are printed again
            }
            printf(" are excluded.\n");
        }
        if(dicenum>=1 && x==1){
            printf("\nI rolled and you got.\n");
        }
        if (valid1 == 1) {  // if dice1 is valid roll the dice again
            dice1 = roll_a_dice();
            printf("\n[dice1]: %d ", dice1);
        }
        if (valid2 == 1) {  // if dice2 is valid roll the dice again
            dice2 = roll_a_dice();
            printf("[dice2]: %d ", dice2);
        }
        if (valid3 == 1) {  // if dice3 is valid roll the dice again
            dice3 = roll_a_dice();
            printf("[dice3]: %d ", dice3);
        }
        if (valid4 == 1) {  // if dice4 is valid roll the dice again
            dice4 = roll_a_dice();
            printf("[dice4]: %d ", dice4);
        }
        if (valid5 == 1) {  // if dice5 is valid roll the dice again
            dice5 = roll_a_dice();
            printf("[dice5]: %d ", dice5);
        }
    }while(dicenum>=1);  // executes this while loop until number of dice is equal to 0
    if(dicenum==0){  //if dicenum is equal to o print total score for this round
        printf("\nDrop Dead!\n");
        printf("Yourscore:%d  Total score:%d",yourscore,totalscore);
    }
    return totalscore;
}
int play_computer() {
    int dice1,dice2,dice3,dice4,dice5,dicenum=5,x,i=1,myscore,totalscore=0,valid1=1,valid2=1,valid3=1,valid4=1,valid5=1;
    dice1=roll_a_dice();  //for taking random values of dice 1 roll_a_dice function called
    dice2=roll_a_dice();  //for taking random values of dice 2 roll_a_dice function called
    dice3=roll_a_dice();  //for taking random values of dice 3 roll_a_dice function called
    dice4=roll_a_dice();  //for taking random values of dice 4 roll_a_dice function called
    dice5=roll_a_dice();  //for taking random values of dice 5 roll_a_dice function called
    printf("[dice1]: %d [dice2]: %d [dice3]: %d [dice4]: %d [dice5]: %d\n", dice1, dice2, dice3, dice4, dice5); //when dices rolled first time print all of them
    do{
        myscore=0; // at the beggining of rolling dice again assign myscore to 0 for calculating values of each tour
        x=1;       // assume that at the begining of every tour all dices are valid then according to values change x value
        if(dice1==2 || dice1==5){  //if dice1 2 or 5 dice1 are invalid
            x=0;                   // assign x to 0 because dice 1 is invalid
            valid1=0;              // for future use keep valid1 equal to 0
            dicenum--;             // because of the invalid dice decrement number of dice
        }
        if(dice2==2 || dice2==5){   //if dice2 2 or 5 dice2 are invalid
            x=0;                    // assign x to 0 because dice 2 is invalid
            valid2=0;               // for future use keep valid2 equal to 0
            dicenum--;              // because of the invalid dice decrement number of dice
        }
        if(dice3==2 || dice3==5){  //if dice3 2 or 5 dice3 are invalid
            x=0;                  // assign x to 0 because dice 3 is invalid
            valid3=0;             // for future use keep valid3 equal to 0
            dicenum--;            // because of the invalid dice decrement number of dice
        }
        if(dice4==2 || dice4==5){  //if dice4 2 or 5 dice4 are invalid
            x=0;                   // assign x to 0 because dice 4 is invalid
            valid4=0;              // for future use keep valid4 equal to 0
            dicenum--;             // because of the invalid dice decrement number of dice
        }
        if(dice5==2 || dice5==5){  //if dice5 2 or 5 dice5 are invalid
            x=0;                   // assign x to 0 because dice 5 is invalid
            valid5=0;              // for future use keep valid5 equal to 0
            dicenum--;             // because of the invalid dice decrement number of dice
        }
        if(x==1){                 // if x==1 this means if my dice values are valid
            if(valid1==1)
                myscore+=dice1;   // add to dice 1 value to myscore
            if(valid2==1)
                myscore+=dice2;  // add to dice 2 value to myscore
            if(valid3==1)
                myscore+=dice3;  // add to dice 3 value to myscore
            if(valid4==1)
                myscore+=dice4;  // add to dice 4 value to myscore
            if(valid5==1)
                myscore+=dice5;  // add to dice 5 value to myscore
        }
        printf("\nmyscore:%d",myscore);  // if all of the dices is valid print myscore
        totalscore+=myscore;             // add myscore to total score for storing values of previous tour
        printf(" totalscore:%d\n",totalscore);
        if(x==0){       // if x==0 this means that if at least one of my dices are invalid
            myscore=0;  //myscore will be 0 if at least one of my dices are invalid
            if(valid1==0) {  // if dice 1 is invalid executes if loop
                printf("Dice 1");
                valid1 = 2;  // for not printing again and again same excluded dice assign valid1 to 2.
                dice1=0;     //again for not assigning valid1 to 0 assign dice 1 to 0 otherwise dice 1 are printed again
            }
            if(valid2==0) {   // if dice 2 is invalid executes if loop
                printf("Dice 2 ");
                valid2 = 2;    // for not printing again and again same excluded dice assign valid2 to 2.
                dice2=0;       //again for not assigning valid2 to 0 assign dice 2 to 0 otherwise dice 2 are printed again
            }
            if(valid3==0) {   // if dice 3 is invalid executes if loop
                printf("Dice 3 ");
                valid3 = 2;    // for not printing again and again same excluded dice assign valid3 to 2.
                dice3=0;       //again for not assigning valid3 to 0 assign dice 3 to 0 otherwise dice 3 are printed again
            }
            if(valid4==0) {   // if dice 4 is invalid executes if loop
                printf("Dice 4 ");
                valid4=2;     // for not printing again and again same excluded dice assign valid4 to 2.
                dice4=0;      //again for not assigning valid4 to 0 assign dice 1 to 0 otherwise dice 4 are printed again
            }
            if(valid5==0) {    // if dice 5 is invalid executes if loop
                printf("Dice 5 ");
                valid5=2;      // for not printing again and again same excluded dice assign valid5 to 2.
                dice5=0;       //again for not assigning valid5 to 0 assign dice 5 to 0 otherwise dice 5 are printed again
            }
            printf(" are excluded.\n");
        }
        if (valid1 == 1) {   // if dice1 is valid roll the dice again
            dice1 = roll_a_dice();
            printf("\n[dice1]: %d ", dice1);
        }
        if (valid2 == 1) {  // if dice2 is valid roll the dice again
            dice2 = roll_a_dice();
            printf("[dice2]: %d ", dice2);
        }
        if (valid3 == 1) {  // if dice3 is valid roll the dice again
            dice3 = roll_a_dice();
            printf("[dice3]: %d ", dice3);
        }
        if (valid4 == 1) {  // if dice4 is valid roll the dice again
            dice4 = roll_a_dice();
            printf("[dice4]: %d ", dice4);
        }
        if (valid5 == 1) {  // if dice5 is valid roll the dice again
            dice5 = roll_a_dice();
            printf("[dice5]: %d ", dice5);
        }
    }while(dicenum>=1); // executes this while loop until number of dice is equal to 0
    if(dicenum==0){     //if dicenum is equal to o print total score for this round
        printf("\nDrop Dead!\n");
        printf("myscore:%d  Total score:%d",myscore,totalscore);
    }
    return totalscore;
}
void scoresheet(int myscore,int yourscore){   //this function is used for printing total values and who is the winner
    printf("\nOur scorsheet after round 2:\n");
    printf("==============================");
    printf("\nYour score     My score");
    printf("\n%d            %d",yourscore,myscore);
    if(yourscore>myscore){  //if yourscore is greater than myscore user win
        printf("\nYou are the winner!");
    }
    else if(myscore>yourscore){  //if myscore greater than yourscore computer win
        printf("\nI am the winner!");
    }
    else{                      //if myscore is equal to yourscore there are no winner.
        printf("\nThere are no winner!");
    }
}