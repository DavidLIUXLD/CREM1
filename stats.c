/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
                                print_array(test, SIZE);
                                print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char* array, int size) {
  printf("minimum: %d\n", find_minimum(array, size));
  printf("maximum: %d\n", find_maximum(array, size));
  printf("median: %f\n", find_median(array, size));
  printf("mean: %f\n", find_mean(array, size));
  return;
}

void print_array(unsigned char* array, int size) {
  for(int i = 0; i < size; i ++) {
    printf("%d", array[i]);
    if(i < size - 1) {
      printf(",");
    }
  }
  printf("\n");
  return;
}

double find_median(unsigned char* array, int size) {
  sort_array(array, size);
  if(size % 2 != 0) {
    return (double)array[size / 2];
  }
  return (double)(array[size / 2] + array[(size - 1) / 2])/2.0;
}

double find_mean(unsigned char* array, int size) {
  int sum = 0;
  for(int i = 0; i < size; i ++) {
    sum += array[i];
  }
  return (double)sum / (double)size;
}

int find_maximum(unsigned char* array, int size) {
  int max = array[0];
  for(int i = 1; i < size; i ++) {
    if(max <= array[i]) {
      max = array[i];
    }
  }
  return max;
}

int find_minimum(unsigned char* array, int size) {
  int min = array[0];
  for(int i = 1; i < size; i ++) {
    if(min >= array[i]) {
      min = array[i];
    }
  }
  return min;
}

void sort_array(unsigned char* array, int size) {
  int i, key, j;
    for (i = 1; i < size; i++) {
      key = array[i];
      j = i - 1;
      while(j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j = j - 1;
      }
      array[j + 1] = key;
    }
  return;
}
