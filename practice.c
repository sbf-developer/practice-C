// Harvard CS50x Problem Sets

// PSET 1 - Ask user for name, then print Hello [username] 

#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[100];
    printf("What is your name? ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    printf("hello, %s\n", name);

    return 0;
}

// PSET 1 - Mario (more comfortable)

#include <stdio.h>

int main(void)
{
    int height = 0;

    while (height < 1 || height > 8)
    {
        printf("Height: ");
        scanf("%d", &height);
    }
    
    for (int row = 1; row <= height; row++)

}


























































// Other tasks (not CS50x)

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