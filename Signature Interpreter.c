#include <stdio.h>
#include<string.h>
#include<stdlib.h>

struct Signatures{   //signatures struct to hold the data of the signatures
    char full_name[30];
    int x_initial;
    int x_final;
    int y_initial;
    int y_final;
    int height;
    int width;
};
typedef struct Signatures signatures; //instead of writing struct Signatures use just signatures
signatures *load_SignaturesTable(char *,int *);  // this function return an array therefore it has * in front of function_name
void displaysignaturetable(signatures*,int);
int search(signatures *, int num_fullname, char []);
void sort(signatures*,int);
int main(int argc, char *argv[]) { // we can run this program from the command line
    int num_fullname=0,option=0;
    char name[70];
    int count,j;
    signatures *signaturestable;
    signaturestable= load_SignaturesTable(argv[1],&num_fullname); //load function creates signature of array and in the main I will return it to *signaturestable
    displaysignaturetable(signaturestable,num_fullname);  //this function for printing our array into the screen
    while(option!=3){  //option is initially given 0, therefore enter this loop
        printf("To search for a signature, please press 1.\nTo sort signatures based on width and height,please press 2.\nTo exit,please press 3.");
        printf("\nYour choice:");
        scanf("%d",&option);  //take the value of the option from the user
        if(option==1){
            printf("Enter name of the signature owner:");
            fflush(stdin);  //to clean buffer every time we enter new name
            gets(name);
            count = search(signaturestable, num_fullname, name); //this function compares the list of names and user defined names
            while(count==-1) { // return value in the function body
                printf("That owner does not exist! Please try again!\n");
                fflush(stdin); //to take new name again we have to clean the buffer
                gets(name);
                count = search(signaturestable, num_fullname, name);  //function call again for doing operation again and again
            }
            for(j=0;j<num_fullname;j++){ //if there is a match between the name entered by the user and the list of names, it tells you which index it occurred.
                if(!strcmp(signaturestable[j].full_name,name))
                    break;
            }
            //After determining index we will print name and values of his/her signature's coordinates
            printf("\n%s start signing at x=%d and y=%d and finalized at x=%d and y=%d. Hence, %s has a signature of width %d and height %d.\n",name,signaturestable[j].x_initial,signaturestable[j].y_initial,signaturestable[j].x_final,signaturestable[j].y_final,name,signaturestable[j].width,signaturestable[j].height);

        }
        if(option==2){ //if user enter option 2 we will do some sorting operations
            sort(signaturestable,num_fullname);
        }
    }
    printf("\nBYEE!"); //if my option is 3 code do nothing and printing only BYEE!
    return 0;
}
signatures *load_SignaturesTable(char *argv, int *num_fullname){
    signatures *signaturetable;  //this is an array that type of signatures and function is returning it
    int i=0,j;
    char counter='a'; //initilization of counter
    FILE *infile;   //to take names and values of signatures from the file
    infile=fopen(argv,"r");  //open signatures.txt for only reading
    while(infile==NULL){ // this is for if we can not open file
        printf("This file does not exist, please enter again:");
        gets(argv);  // take again file name
        infile=fopen(argv,"r");
    }
    printf("The signature records file  has been successfully loaded!\n");

    while(counter!=EOF){  //until end of the file run this loop
        counter=fgetc(infile);   // get all char one by one
        if(counter=='\n'){   //if char is new line incerement num_fullname there are no new line in the last row there are nine rows in the file but I will escape firstline which is the headings I did not incerement num_fullname extra after loop
            (*num_fullname)++;
        }
    }

    rewind(infile); // cursor goes to beginning of the file

    signaturetable=(signatures *)malloc((*num_fullname)*sizeof(signatures)); //memory allocation for signaturetable array
    if(signaturetable==NULL){
        printf("There is a memory problem");
        exit(1);
    }
    char temp[150];
    fgets(temp,150,infile);// in the struct we don't have the line that is formed by 7 strings we skip first line
    while(i<*num_fullname){ // this loop reads information from the file and assigns it array one by one
        fscanf(infile,"%[^;];%d;%d;%d;%d;\n",signaturetable[i].full_name,&signaturetable[i].x_initial,&signaturetable[i].x_final,&signaturetable[i].y_initial,&signaturetable[i].y_final);
        i++;
    }
    for(j=0;j<*num_fullname;j++){ // this is for calculating width and height by using coordinates
        signaturetable[j].width=signaturetable[j].x_final-signaturetable[j].x_initial;
        signaturetable[j].height=signaturetable[j].y_final-signaturetable[j].y_initial;
    }
    return signaturetable;
}
void displaysignaturetable(signatures* signaturestable,int num_fullname){  // here we printed all array to the screen
    int i;
    printf("The following records have been loaded:\n");
    printf("full_name   x_initial x_final y_initial y_final width height"); // I skipped first line therefore we print headings seperately
    for(i=0;i<num_fullname;i++){
        printf("\n%s\t%d\t%d\t%d\t%d\t%d\t%d\n",signaturestable[i].full_name,signaturestable[i].x_initial,signaturestable[i].x_final,signaturestable[i].y_initial,signaturestable[i].y_final,signaturestable[i].width,signaturestable[i].height);
    }
}
int search(signatures* signaturestable, int num_fullname, char name[70]){ // we take name string because we enter name of the student and this function tells us that whether we enter one of the name in the list
    int i;
    for (i = 0; i < num_fullname; i++) {  // we run this loop as many times as the number of names
        if (!strcmp(name,signaturestable[i].full_name)){ // compare all the names in the list with the one that we enered by using str function
            return i;  // if entered name is one of the name in the list return its position
        }
    }
    return -1;  // if it is not found that name in the list return -1
}
void sort(signatures* signaturestable,int num_fullname){  // in this function we will do sorting based on width or height
    char select;
    int i,j;
    signatures temporary;
    printf("Sort by (w:width, h:height):");
    fflush(stdin);
    scanf("%c",&select); // this takes char which one according to we sort
    if(select=='w'){  // if select is w sort according to with
        for(i=0;i<num_fullname-1;i++){ // this nested loop do sort by using buble sort
            for(j=0;j<num_fullname-i-1;j++){
                if(signaturestable[j+1].width>signaturestable[j].width){
                    temporary=signaturestable[j];
                    signaturestable[j]=signaturestable[j+1];
                    signaturestable[j+1]=temporary;
                }
            }
        }
        displaysignaturetable(signaturestable,num_fullname);
    }
    if(select=='h'){ // this nested loop do sort by using buble sort
        for(i=0;i<num_fullname-1;i++){
            for(j=0;j<num_fullname-i-1;j++){
                if(signaturestable[j+1].height>signaturestable[j].height){
                    temporary=signaturestable[j];
                    signaturestable[j]=signaturestable[j+1];
                    signaturestable[j+1]=temporary;
                }
            }
        }
        displaysignaturetable(signaturestable,num_fullname);  // to display sorted version call again display function
    }
}