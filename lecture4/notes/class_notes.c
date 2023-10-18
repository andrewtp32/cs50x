#include <stdio.h>

int main(void)
{
    int n = 50;

    // get address of var: &var
    printf("address of n: %p\n", &n);

    // store pointer address of var in p: *p (this can be used for assignment, e.g. *p = 42. note that this requires p to be already stored in memory)
    int *p = &n;
    printf("address of n: %p\n", p);

}