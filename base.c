#include <stdio.h>
#include <string.h>
#include "base.h"

int Index = 0;
int NumberOfCars = 0;


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void add_a_record(Record records[]){ 
  // 1: Add a new car (Get car info from stdin)
	printf("Enter car name (ex : SantaFe): ");
  scanf("%s", records[Index].carname);
  printf("Enter car number (ex : 32가2890) : ");
  scanf("%s", records[Index].carnumber);
  printf("Enter car color (ex : black) : ");
  scanf("%s", records[Index].carcolor);
  printf("Enter car manufacture date (ex : 20200403) : ");
  scanf("%d", &records[Index].manufacturedate);
  Index++;
  NumberOfCars += Index;
  printf("\n> Record added\n");
  printf("> Number of cars : %d\n\n", NumberOfCars);
  
}


void add_a_data(Record records[]){  
  // 2: Add new data from text file 
  //   (Get car info from txt file)
  FILE* fp = fopen("cars.txt", "r");

  while(1){
    int k = fscanf(fp, "%s %s %s %d", 
    records[Index].carname, 
    records[Index].carnumber,
    records[Index].carcolor,
    &records[Index].manufacturedate);
    if(k==EOF) break;
    Index++;
    NumberOfCars++;
  }
  printf("\n> Record added\n");
  printf("> Number of cars : %d\n\n", NumberOfCars);
  fclose(fp);
}

void update_data(Record records[]){
  // 3: Update data
  int input;
  char nullStr[20] = {"\0"};

  printf("Enter number for specific car (ex : 2) : ");
  scanf("%d", &input);
  
  strcpy(records[input-1].carname, nullStr);
  strcpy(records[input-1].carnumber, nullStr);
  strcpy(records[input-1].carcolor, nullStr);
  records[input-1].manufacturedate = 0;

  printf("Enter new car name (ex : SantaFe): ");
  scanf("%s", records[input-1].carname);
  printf("Enter new car number (ex : 32가2890) : ");
  scanf("%s", records[input-1].carnumber);
  printf("Enter new car color (ex : black) : ");
  scanf("%s", records[input-1].carcolor);
  printf("Enter new car manufacture date (ex : 20200403) : ");
  scanf("%d", &records[input-1].manufacturedate);
  printf("\n> Record Updated\n");
  printf("> Number of cars : %d\n\n", NumberOfCars);
}





void delete_a_data(Record records[]){
  // 4: Delete a car
  
  int input;
  char nullStr[20] = {"\0"};

  printf("Enter number for specific car (ex : 2) : ");
  scanf("%d", &input);
  
  strcpy(records[input-1].carname, nullStr);
  strcpy(records[input-1].carnumber, nullStr);
  strcpy(records[input-1].carcolor, nullStr);
  records[input-1].manufacturedate = 0;
  
  NumberOfCars --;
  printf("\n> Car Deleted\n");
  printf("> Number of cars : %d\n\n", NumberOfCars);
}


void delete_all(Record records[]){
  // 5: Delete all cars
  char nullStr[20] = {"\0"};

  for(int i = 0 ; i < Index ; i++) {
    strcpy(records[i].carname, nullStr);
    strcpy(records[i].carnumber, nullStr);
    strcpy(records[i].carcolor, nullStr);
    records[i].manufacturedate = 0;
  }

  NumberOfCars = 0;
  Index = 0;

  printf("\n> All Cars Deleted\n");
  printf("> Number of cars : %d\n\n", NumberOfCars);
  return;
}


// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void print_all_records(Record records[]){
	// 6: Print all cars
  for(int i = 0 ; i < Index ; i++) {
    printf("\n[%d번째 자동차]\n", i+1);
    printf("> Car name: %s\n", records[i].carname);
    printf("> Car number: %s\n", records[i].carnumber);
    printf("> Car color: %s\n", records[i].carcolor);
    printf("> Car manufacture date: %d\n", records[i].manufacturedate);
  }
  return;
}


void print_specific_records(Record records[]) {
  // 7: Print specific car
  int input;
  printf("Enter number for specific car (ex : 2) : ");
  scanf("%d", &input);
  printf("\n[%d번째 자동차]\n", input);
  printf("> Car name: %s\n", records[input-1].carname);
  printf("> Car number: %s\n", records[input-1].carnumber);
  printf("> Car color: %s\n", records[input-1].carcolor);
  printf("> Car manufacture date: %d\n", records[input-1].manufacturedate);
  return;
}


void print_multi_records(Record records[]){
  // 8: Print specific number of cars
  int input;
  printf("Enter number to print cars (ex : 5) : ");
  scanf("%d", &input);
  for(int i = 0 ; i < input ; i++) {
    printf("\n[%d번째 자동차]\n", i+1);
    printf("> Car name: %s\n", records[i].carname);
    printf("> Car number: %s\n", records[i].carnumber);
    printf("> Car color: %s\n", records[i].carcolor);
    printf("> Car manufacture date: %d\n", records[i].manufacturedate);
  }
}


void save_a_data(Record records[]){ 
  // 9: Save data to the text file
  FILE* fp1 = fopen("carsave.txt", "w");
  if(fp1==NULL) {
    printf("Error opening the file\n");
    return ;
  }
  for(int i = 0 ; i < Index ; i++) {
    fprintf(fp1, "\n[%d번째 자동차]\n", i+1);
    fprintf(fp1, "> Car name: %s\n", records[i].carname);
    fprintf(fp1, "> Car number: %s\n", records[i].carnumber);
    fprintf(fp1, "> Car color: %s\n", records[i].carcolor);
    fprintf(fp1, "> Car manufacture date: %d\n", records[i].manufacturedate);
  }
  fclose(fp1);
}


// TODO: Add more functions to fulfill the requirements

void sort_in_date(Record records[]){
  // 10. Sort data in manufacture date
  int i, j, least, temp;

  // 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수-1) 만큼 반복한다.
  for(i=0; i<Index-1; i++){
    least = i;

    // 최솟값을 탐색한다.
    for(j=i+1; j<Index; j++){
      if(records[j].manufacturedate<records[least].manufacturedate)
        least = j;
    }

    // 최솟값이 자기 자신이면 자료 이동을 하지 않는다.
    if(i != least){
        swap_record(&records[i], &records[least]);
    }
  }
}

void swap_record(Record* a, Record* b){
  Record c;
  strcpy(c.carname,a->carname);
  strcpy(c.carnumber,a->carnumber);
  strcpy(c.carcolor,a->carcolor);
  c.manufacturedate = a->manufacturedate;

  strcpy(a->carname,b->carname);
  strcpy(a->carnumber,b->carnumber);
  strcpy(a->carcolor,b->carcolor);
  a->manufacturedate = b->manufacturedate;

  strcpy(b->carname,c.carname);
  strcpy(b->carnumber,c.carnumber);
  strcpy(b->carcolor,c.carcolor);
  b->manufacturedate = c.manufacturedate;
}
