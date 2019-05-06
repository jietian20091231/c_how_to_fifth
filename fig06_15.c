/* Fig. 6.15: fig06_15.c
   This program sorts an array's values into ascending order */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void random_generator(int a[], int size);
void print_array(int a[], int size, const char* msg);
void bubble_sort(int a[], int size);

int main(int argc, char *argv[])
{

  srand(time(NULL));

  int int_array[SIZE] = { 0 };
  random_generator(int_array, SIZE);
  print_array(int_array, SIZE, "Data items in original order");
  printf("%s\n", "bubble sorting");
  bubble_sort(int_array, SIZE);
  print_array(int_array, SIZE,"Data items in ascending order");
  
  
  return 0;
}

/* random generator function */
void random_generator(int a[], int size)
{

  int i;

  for (i = 0; i < size; i++) {
    a[i] = 1 + rand() % 99;
  }

}

/* print array's element on sreen */
void print_array(int a[], int size, const char* msg)
{
  int i;

  printf("%s\n", msg);

  for(i = 0; i < size; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
  
}

/* buble sort function */
void bubble_sort(int a[], int size)
{
  int i, j, tmp;
  for( i = 0; i < size; i++) {
    for( j = i + 1; j < size; j++) {
      if(a[i] >= a[j]) {
        	tmp = a[i];
        	a[i] = a[j];
        	a[j] = tmp;
      }
    }
  }
  
}



