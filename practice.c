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

// PSET 1 - Ask user for name, then print Hello [username] 

int main(void)
{
    char name[100];
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    printf("hello, %s\n", name);

    return 0
}
