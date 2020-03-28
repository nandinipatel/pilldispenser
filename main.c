#include <stdio.h>
#include <stdbool.h>

int main() {
   int d, m, year, time, pin, pinF, pinP, checkP, choice, choice1, choice2, compN, quantity;
   checkP = 0000;
   pinF = 1111;
   pinP = 1111;
   bool lock = false;
   
   //patient inputs date
   do { 
    printf("\nEnter date MM/DD/YY: ");
    scanf("%d/%d/%d", &m, &d, &year);
   } while((m<1 || m>12) || (d<1 || d>28) || (year>2020));  
   //check for a valid date here

   //TO-DO: what should be done with the date now?
   
   //patient inputs time
   printf("\nEnter time 24H Clock: ");
   scanf("%d", &time);

   //TO-DO: get minutes and hour separately
   //TO-DO: what should be done with time now?

   //TO-DO: check for a valid time here (between 1-24);
   //clock needs to be programmed at this point

   //set up filling pin
   printf("\nSet Up Filling Pin\n");
   while (checkP != pinF) {
      printf("Enter Pin: ");
      scanf("%d", &pinF);

      //TO-DO: check for a valid pin here (only numbers and 4 digits)
      printf("Re-Enter Pin: ");
      scanf("%d", &checkP);
   }
   
   //reset the check pin
   checkP = 0000;

   //set up programming pin
   printf("\nSet Up Programming Pin\n");
   while(checkP != pinP) {
      printf("Enter Pin: ");
      scanf("%d", &pinP);

      //TO-DO: check for a valid pin here (only numbers and 4 digits)
      printf("Re-Enter Pin: ");
      scanf("%d", &checkP);
   }
   //display the homescreen
   //TO-DO: clear console at this point
   while(true) {
        printf("\nWelcome to the homescreen\n");

        do {
            printf("Enter passcode: ");
            scanf("%d", &pin);
        } while (pin != pinP && pin != pinF);
        printf("1.Filling\n2.Programming\nEnter Choice: ");
        scanf("%d", &choice);

        //TO-DO: check here for a valid choice (can only be 1 or 2)
        if ((choice == 1) && (pin = pinF)) {
            //lock is triggered
            lock = true;
            printf("Please Fill Medication, Close Lid When Finished");
            //medicine is filled at this point
            lock = false;
            //lid is locked 
        }
        else if ((choice == 2) && (pin = pinP))  {
            do {
                    //ask the user to choose a day
                    printf("1.SUN\n2/MON\n3.TUES\n4.WED\n5.THU\n6.FRI\n7.SAT");
                    printf("Enter Choice: ");
                    scanf("%d", &choice2);
                    //TO-DO: check here if its a valid day
                    //TO-DO: a place to store all the medications with its time on each day (possibly an array or struct?)

                    printf("Enter Time: ");
                    scanf("%d", &time);
                    //TO-DO: need to retrieve mins and hour separately
                    //TO-DO: needs a validation method (for time)

                    do {
                            //get the compartment number
                            printf("Enter Compartment Number: ");
                            scanf("%d", &compN);

                            //get quantity
                            do {
                                    printf("Enter quantity: ");
                                    scanf("%d", &quantity);
                            } while (quantity>4);
                            
                            //TO-DO: clear the screen
                            printf("1.Input additional pills for this time\n2.Input pills for new day\n3.Done");
                            printf("Enter Choice: ");
                            scanf("%d", &choice1);
                    } while(choice1 == 1); 
            } while(choice1 == 2);
        }
   }
}