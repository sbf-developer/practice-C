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
    {
        for (int space = 0; space < height - row; space++)
        {
            printf(" ");
        }

        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        printf("  ");

        for (int hash = 0; hash < row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }
}



// PSET 1 - Credit (more comfortable)

#include <stdio.h>

int main(void)
{
    long long card;

    printf("Insert card number: ");
    scanf("%lld", &card);

    long long number = card;

    int sum = 0;
    int digit_count = 0;

    // Luhn algorithm
    while (number > 0)
    {
        int digit = number % 10;

        if (digit_count % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            int doubled = digit * 2;

            if (doubled > 9)
            {
                sum += doubled / 10;
                sum += doubled % 10;
            }
            else
            {
                sum += doubled;
            }
        }

        number /= 10;
        digit_count++;
    }

    // If Luhn fails, card is invalid
    if (sum % 10 !=0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Get first one and two digits
    long long start = card;

    while (start >= 100)
    {
        start /= 10;
    }

    int first_two = start;
    int first_one = first_two / 10;

    // Determine card type
    if (digit_count == 15 &&
        (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (digit_count == 16 && 
            first_two >= 51 && first_two <=55)

    {
        printf("MASTERCARD\n");
    }
    else if ((digit_count == 13 || digit_count == 16) &&
              first_one == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

// PSET 2 - Readability

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    char text[1000];

    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

    return 0;
}


// PSET 2 - Substition

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain letters.\n");
            return 1;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not contain repeated letters.\n");
                return 1;
            }
        }
    }

    char text[1000];

    printf("plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        char c = text[i];

        if (isupper(c))
        {
            int position = c - 'A';
            printf("%c", toupper(key[position]));
        }
        else if (islower(c))
        {
            int position = c - 'a';
            printf("%c", tolower(key[position]));
        }
        else
        {
            printf("%c", c);
        }
    }

    return 0;
}



// PSET 3 - Plurality



// PSET 3 - Tideman














































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