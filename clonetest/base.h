#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes


void add_a_record(Record[]); 
// 1. Add a new car

void add_a_data(Record records[]); 
// 2. Add new data from text file

void delete_a_data(Record records[]);
// 3. Delete a car

void delete_all(Record records[]);
// 4. Delete all cars

void print_all_records(Record[]); 
// 5. Print all cars

void print_specific_records(Record records[]); 
// 6. Print specific car

void print_multi_records(Record records[]); 
// 7. Print specific number of cars

void save_a_data(Record records[]); 
// 8. Save data to the text file

void sort_in_date(Record records[]);
// 9. Sort data in manufacture date

void swap_record(Record* a, Record* b);

#endif
