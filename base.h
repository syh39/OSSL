
#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes


void add_a_record(Record[]); 
// 1. Add a new car

void add_a_data(Record records[]); 
// 2. Add new data from text file

void update_data(Record records[]);
// 3. Update data

void delete_a_data(Record records[]);
// 4. Delete a car

void delete_all(Record records[]);
// 5. Delete all cars

void delete_condition(Record records[]);
// Delete all except condition

void print_all_records(Record[]); 
// 6. Print all cars

void print_specific_records(Record records[]); 
// 7. Print specific car

void print_multi_records(Record records[]); 
// 8. Print specific number of cars

void save_a_data(Record records[]); 
// 9. Save data to the text file

void sort_in_date(Record records[]);
// 10. Sort data in manufacture date

void swap_record(Record* a, Record* b);

#endif
