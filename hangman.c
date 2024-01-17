// HANGMAN GAME

#include<stdio.h>  
#include<string.h>
#include<stdbool.h>
           

// User defined fuctions...                           
            
void rules();                                      // Function to print the rules of the game...
void display_misses(int a);                        // Function to show the number of guesses left and position ofo the man to be hanged...
void display_status(char arr1[], char arr2[]);     // Function to show current status of answer and incorrect guesses...
int compstr(char arr1[], char arr2[]);             // Function to compare to strings "answer given by player" and the "codeword"...
void end_game(char arr1[], char arr2[]);           // Function to print ending scenerio of the game...


// Main function...

int main(){
   rules();
   char codeword[] = "ayana";
   char ans[] = "_____";
   char letter;
   int miss = 0;
   char incorrect[6] = "______";
   bool guess;


   int ind = 0;         // Defined to store the incorrect guesses in the "ind" index of the incorrect array/string...
   int check;           // To control while loop,  takes input from "compstr" function...

   while((check != 1) && (miss <= 6)){
      display_misses(miss);
      display_status(incorrect,ans);
      
      if(miss <= 5){                                    // To take input from the player only when he/she has done 5 wrong guesse,...at the 6th wrong guess it should nottake input from the player...
         printf("\n\n\t\tEnter a character: ");
         scanf(" %c", &letter);
      }

      for(int i=0; i<strlen(codeword); i++){            // Comparing the letter input by the player with each character of the codeword
         if(letter == codeword[i]){
            ans[i] = letter;                            // Storing the letter in the i'th index of "ans" array...
            guess = true;
         }
      }if(guess){
         printf("\n\n\t\tCongratulation!! Your guess is correct..");
      }else{
         printf("\n\n\t\tOops!! Your guess is wrong..");
         printf("\n\n\t\tAnother portion of your friend has been drawn..");
         incorrect[ind] = letter;                       // Storing the wrong guess in the ind'th index of "incorrect" array...
         ind++;                                         // Updating ind...
         miss++;                                        // Updating miss...
      }
      printf("\n\n\t------------------------------------------------------------------------------------------");
      guess = false;
      
      check = compstr(codeword,ans);            // Comparing "ans" with "codeword"...
   }

   end_game(ans,codeword);          // Printing ending scenerio of the game...

   if(check == 1){
      printf("\n\n\t\tHurrah!!You saved your friend..... :)");
   }else{
      printf("\n\n\t\tAlas!!You could not save your friend........ :(");
   }
   
   return 0;
}


// Function to print the rules of the game...

void rules(){

   printf("\t**********************************************************************************************\n");
   printf("\t**********************************************************************************************");
   printf("\n\n\t\t==> Welcome to the game");
   printf("\n\t\t--> You have to guess the 5 letter word and you have 6 chances");
   printf("\n\t\t--> After each wrong guess one part of the man will be drawn");
   printf("\n\t\t--> If you guess the word correctly the man will be saved otherwise he will be hung\n\n");
   printf("\t**********************************************************************************************\n");
   printf("\t**********************************************************************************************\n");

}


// Function to show the number of guesses left and position ofo the man to be hanged...

void display_misses(int a){
   if(a == 0){

      printf("\n\n\t\tYou hove 6 more chances left\n");

   }else if(a == 1){

      printf("\n\n\t\tYou have 5 more chances left\n");
      printf("_--------_\n");
      printf("         |\n");
      printf("         |\n");
      printf("         |\n");
      printf("         |\n");
      printf("         |\n");
      printf("         |\n");

   }else if(a == 2){

      printf("\n\n\t\tYou have 4 more chances left\n");
      printf("_--------_\n");
      printf("         |\n");
      printf("o        |\n");
      printf("         |\n");
      printf("         |\n");
      printf("         |\n");
      printf("         |\n");

   }else if(a == 3){

      printf("\n\n\t\tYou have 3 more chances left\n");
      printf("_--------_\n");
      printf("         |\n");
      printf("o        |\n");
      printf("|        |\n");
      printf("|        |\n");
      printf("         |\n");
      printf("         |\n");

   }else if(a == 4){

      printf("\n\n\t\tYou have 2 more chances left\n");
      printf("    _--------_\n");
      printf("             |\n");
      printf("    o        |\n");
      printf("    |        |\n");
      printf("    |        |\n");
      printf("  /***\\      |\n");
      printf(" /     \\     |\n");

   }else if(a == 5){

      printf("\n\n\t\tYou have 1 more chance left\n");
      printf("    _--------_\n");
      printf("             |\n");
      printf("  \\ o /      |\n");
      printf("   \\|/       |\n");
      printf("    |        |\n");
      printf("  /***\\      |\n");
      printf(" /     \\     |\n");

   }else if(a == 6){
      printf("\n\n\t\tSorry :( You lost your friend!!\n");
      printf("    _--------_\n");
      printf("    |        |\n");
      printf("  \\ o /      |\n");
      printf("   \\|/       |\n");
      printf("    |        |\n");
      printf("  /***\\      |\n");
      printf(" /     \\     |\n");

   }
}


// Function to show current status of answer and incorrect guesses...

void display_status(char arr1[], char arr2[]){

   printf("\n\n\t\tIncorrect guesses: ");
   for(int i=0; i<6; i++){
      printf("%c", arr1[i]);
   }

   printf("\n");

   printf("\n\n\t\tAnswer: ");
   for(int i=0; i<strlen(arr2); i++){
      printf("%c", arr2[i]);
   }
}


// Function to compare to strings "answer given by player" and the "codeword"...

int compstr(char arr1[], char arr2[]){
    int value;
    for(int i=0; i<strlen(arr1); i++){
        if(arr1[i] == arr2[i]){
            value = 1;
        }else{
            value = 0;
            break;
        }
    }
    return value;
}


// Function to print ending scenerio of the game...

void end_game(char arr1[], char arr2[]){
   printf("\n\n\t\tYour answer: ");
   puts(arr1);
   printf("\t\tCodeword: ");
   puts(arr2);
   printf("\n\n");
}
                       


