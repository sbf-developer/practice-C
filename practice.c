// Positive, negative or neutral number

#include <stdio.h>

int main(void)
{
    int number;
    printf("Enter a number ");
    scanf("%d", &number);
    
    if (number > 0)
    {
        printf("positive\n");
    }
    else if (number < 0)
    {
        printf("negative\n");
    }
    else 
    {
        printf("neutral\n");
    }
    return 0;
}
