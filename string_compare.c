#include <stdio.h>
#include <string.h>

int main(){
  /*
    int strcmp(const char *s1, const char *s2)
    Compares every element of each string, concludes upon a difference in characters
    Returns an int that compares the stopping character of the two.
   */
  //helper variables
  int a;
  int b;
  
  //Case 1: stopping character is null; returns 0
  //i.e. the strings are equal

  //if they are the same pointer
  a = strcmp("doggy", "doggy"); //returns 0

  //if they are different pointers
  char str[100] = "doggy";
  b = strcmp(str, "doggy"); //returns 0

  printf("[doggy] vs itself: %d\n", a);// 0
  printf("[doggy] vs a copy: %d\n", b);// 0

  //Case 2: stopping character is different
  //a) stopping char s1 < stopping char s2 (in ASCII)
  
  a = strcmp("doagy", "doggy");// a < g, so -1

  //b) stopping char s1 > stopping char s2 (in  ASCII)

  b = strcmp("doggy", "doagy");// d > a, so 1

  printf("[doagy] vs [doggy]: %d\n", a);// -1
  printf("[doggy] vs [doagy: %d\n", b);// 1

  //Case 3: different lengths
  a = strcmp("dogg", "doggy");
  b = strcmp("doggy", "dogg");

  printf("[dogg] vs [doggy]: %d\n", a);// -1
  //in this case, 0 is being compared to y, 0 is lower than y thus resolving in -1
  //in the same vein, y can be compared to 0 for 1
  printf("[doggy] vs [dogg]: %d\n", b);// 1

  /*
    int strncmp(const char *s1, const char *s2, size_t n)
    Does the same as strcmp, but you may specify a substring starting at index 0.
    Argument size_t specifies the end as index + 1.
    It will only return based on the substring.
   */

  //This can be used to stop length discrepencies
  a = strncmp("dogg", "doggy", 4);
  b = strncmp("doggy", "dogg", 4);

  printf("[dogg] vs [doggy] n=4 : %d\n", a);// 0
  printf("[doggy] vs [dogg] n=4 : %d\n", b);// 0

  //if n > length, it will simply stop at the first null
  a = strncmp("dogg", "doggy", 10);
  b = strncmp("doggy", "dogg", 10);

  printf("[dogg] vs [doggy] n=10 : %d\n", a);// -1
  printf("[doggy] vs [dogg] n=10 : %d\n", b);// 1

  //---------------------------------------------------
  //Now, let's say there is no null
  char test[] = "doggy";
  test[5] = 'a';

  //compared to an equal string with null
  a = strcmp(test, "doggy");

  printf("[doggy] (no null) vs [doggy] (different adresses) : %d\n", a);// 1
  //This is because 'a' > 0

  //compared to itself
  //b = strcmp(test, test);
  //commented in case of seg fault

  //printf("[doggy] vs [doggy] (same address + no null) : %d\n", a);
  
  //compared to another copy
  char test2[] = "doggy";
  test2[5] = 'a';

  //Warning: may produce seg fault
  a = strcmp(test, test2);

  printf("[doggy] vs [doggy] (different addresses + no null) : %d\n", a); //should be varied depending on memory after
  //author's note: I can only seem to get 1, likely due to how my pc is allocating memory, but i'm not entirely sure...
}
