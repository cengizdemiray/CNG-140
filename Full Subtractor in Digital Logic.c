//Cengiz Demiray
//2526960
#include <stdio.h>
#include<math.h>
#define LF 10
int main() {
    int A, B, BIN, D, BOUT, choice, base, bnum = 0, i = 1, count, x;
    char input;
    printf("\nWelcome to Full Subtractor!\n   (1) Compute and display the outputs\n   (2) Quit\n");
    printf("You choose:");
    scanf("%d", &choice);
    printf("You have chosen option %d\n", choice);
    while (choice == 1) {           //if choice 1 enter while loop
        printf("Which base will you use to enter input (base 2 or base 16) ?");
        scanf("%d", &base);
        if (base == 16) {
            printf("Please enter your input:");
            scanf("\n%c", &input);     // newline for enter char.
            while (!((input >= 48 && input <= 57) ||(input >= 65 && input <= 70))) {    // if char is not between 0-9 or A-F run while loop.
                printf("Invalid number in base 16! Please try again!");
                printf("\nEnter your input:");    //take input again.
                scanf("\n%c", &input);      //newline for enter char.
            }
            input = input - 48;            //subtract from every input to take actual values of every input.
            while (input > 7) {            //for writing with three digits my input must smaller than 7.
                printf("Not possible to convert it to 3-digit binary number. Please try again!\n");
                printf("Please enter your input:");        //if input greater than 7 take value again.
                scanf("\n%c", &input);
                input = input -48;                           //subtract from every input to take actual values of every input.
            }
            while (input > 0) {                              //converting my input to binary digits.
                bnum = bnum + (input % 2) * i;

                input = input / 2;
                i = i * 10;
            }
            BIN = bnum % 2;          //modulus by two and remainders digit is equal to our BIN
            bnum = bnum / 2;        //divide by two to leave second digit in the bnum at righmost.
            B = bnum % 2;          //modulus by two with the uptated bnum and remainder digit is equal to our B
            bnum = bnum / 2;       //divide by two to leave third digit in the bnum at the rightmost.
            A = bnum % 2;          // modulus by two with the uptaded bnum is equal to our A
            if ((A == 0 && B == 0 && BIN == 0) || (A == 1 && B == 1 && BIN == 0) ||//for D=0 I wrote possible A and B by looking truth table
                (A == 1 && B == 0 && BIN == 1) || (A == 0 && B == 1 && BIN == 1)) {
                D = 0;
            } else {
                D = 1;
            }
            BOUT = (!A && BIN) || (!A && B) || (B && BIN);
            printf("D is %d bout is %d\n", D, BOUT);
        }

        else {                  //code of base 2 stars here.
            x = 1;               //I assign x value for just entering while loop.
            while (x == 1) {
                printf("Please enter your input:");
                fflush(stdin);           // to clear char buffer when I enter new input.
                input = 0;                // initialized input to 0
                count = 0;                //I assign count for counting how many digits.
                while (input != LF - 48) {   // again for taking actual values

                    scanf("%c", &input);
                    input = input - 48;        //for taking actual values of every char in the buffer.

                    if (input != 0 && input != 1) {

                        if (input != LF - 48) {
                            x = 1;//input is invalid to take input again we assign x=1 to enter while.
                            printf("Invalid number in base 2! Please try again!\n");
                            break;
                        }
                    }
                    else {// if number okey for base enter else
                        x = 0;    // I reassign x to 0 for showing my input is in suitable base and formed with only 1 and 0.
                        if (count == 0)         //assign first digit to A.
                            A = input;
                        else if (count == 1)   //assign second digit to B.
                            B = input;
                        else
                            BIN = input;     //assign last digit to BIN.
                        count++;    // increment count by 1.
                    }

                }

                if (x == 0 && count > 3) {
                    printf("You entered more than 3 bits! Please try again!\n");
                    x = 1;  // if count greater than 3 for taking input again x must be 1.
                }
                else if (x == 0 && count < 3) {
                    printf("You entered less than 3 bits! Please try again!\n");
                    x = 1;  // if count smaller than 3 for taking input again x must be 1.
                }

                else if(x==0 && count==3) {  // if input satisfy all conditions we can assign outputs and print them
                    if ((A == 0 && B == 0 && BIN == 0) || (A == 1 && B == 1 && BIN == 0) ||
                        //for D=0 I wrote possible A and B by looking truth table
                        (A == 1 && B == 0 && BIN == 1) || (A == 0 && B == 1 && BIN == 1)) {
                        D = 0;
                    } else {
                        D = 1;
                    }
                    BOUT = (!A && BIN) || (!A && B) || (B && BIN);         //logical expression for BOUT.
                    printf("D is %d bout is %d", D, BOUT);
                }
            }
        }
        printf("\nWelcome to Full Subtractor!\n   (1) Compute and display the outputs\n   (2) Quit\n");
        printf("You choose:");
        scanf("%d", &choice);
        printf("You have chosen option %d\n", choice);
    }
    if (choice == 2) {

        printf("BYEE!");
    }
    return 0;
}