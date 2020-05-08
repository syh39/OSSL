#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(int, Record[]);
void display_menu();

int catcherror = 0;
// main function
int main(){

	Record records[MAX_RECORDS];
	//char user_input[64] = ""; / why char?
  int user_input;
	while(user_input!=99 && !catcherror){
		display_menu();
		printf("\nSelect a menu> ");
		//fgets(user_input, 64, stdin); / why fgets?
    scanf("%d", &user_input);
		//user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(int input, /* char input[],*/ Record records[]){

	// TODO: Modify this function as you need

  switch(input) {
    case 1 : add_a_record(records); break;
    case 2 : add_a_data(records); break;
    case 3 : update_data(records); break;
    case 4 : delete_a_data(records); break;
    case 5 : delete_all(records); break;
    case 6 : print_all_records(records); break;
    case 7 : print_specific_records(records); break;
    case 8 : print_multi_records(records); break;
    case 9 : save_a_data(records); break;
    case 10 : sort_in_date(records); break;
    case 11 : defragment(records); break;
    case 12 : display_stats(records); break;
    case 99 : printf("Terminating... bye!\n"); break;
    default : printf("Unknown menu\n\nProgram Terminating\n"); catcherror = 1; break;
    //case 11 : add_a_record(records); break;
  }
	/* if(!strcmp(input, "1"))
		add_a_record(records);
  else if(!strcmp(input, "2"))
    add_a_data(records);
	else if(!strcmp(input, "3"))
		print_all_records(records);	
  else if(!strcmp(input, "4"))
    print_specific_records(records);	
  else if(!strcmp(input, "5"))
    print_multi_records(records);
  else if(!strcmp(input, "6"))
    save_a_data(records);
	else if(!strcmp(input, "7"))
		defragment(records);
	else if(!strcmp(input, "8"))
		display_stats(records);	
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input); */
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need
	printf("\n*******************************\n");
	printf("|    Car Management System    | \n");
	printf("*******************************\n");
	printf(" 1. Add a new car\n");
  printf(" 2. Add new data from text file\n");
  printf(" 3. Update data\n");
  printf(" 4. Delete a car\n");
  printf(" 5. Delete all cars\n");
	printf(" 6. Print all cars\n");
  printf(" 7. Print specific car\n");
  printf(" 8. Print specific number of cars\n");
  printf(" 9. Save data to the text file\n");
  printf(" 10. Sort data in manufacture date\n");
	printf(" 11. Optimize (defragment) the records\n");
	printf(" 12. Member statistics\n");
	printf(" 99. Quit\n");
}
