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

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

typedef struct
{
    char *name;
    int votes;
}
candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(char *name);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check that at least one candidate was entered
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Number of candidates
    candidate_count = argc - 1;

    // Make sure there are not too many candidates
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Store candidate names and start everyone at 0 votes
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;

    printf("Number of voters: ");
    scanf("%i", &voter_count);

    // Ask each voter for their vote
    for (int i = 0; i < voter_count; i++)
    {
        char name[100];

        printf("Vote: ");
        scanf("%99s", name);

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Print winner or winners
    print_winner();

    return 0;
}

bool vote(char *name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }

    return false;
}

void print_winner(void)
{
    int highest_votes = 0;

    // Find the highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest_votes)
        {
            highest_votes = candidates[i].votes;
        }
    }

    // Print everyone who has that number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}








// PSET 3 - Tideman


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

int preferences[MAX][MAX];
bool locked[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
}
pair;

char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count = 0;
int candidate_count;

bool vote(int rank, char *name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool creates_cycle(int winner, int loser);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    int voter_count;

    printf("Number of voters: ");
    scanf("%i", &voter_count);

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++)
        {
            char name[100];

            printf("Rank %i: ", j + 1);
            scanf("%99s", name);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

bool vote(int rank, char *name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            int strength_i =
                preferences[pairs[i].winner][pairs[i].loser];

            int strength_j =
                preferences[pairs[j].winner][pairs[j].loser];

            if (strength_j > strength_i)
            {
                pair temp = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = temp;
            }
        }
    }
}

bool creates_cycle(int winner, int loser)
{
    if (loser == winner)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (creates_cycle(winner, i))
            {
                return true;
            }
        }
    }

    return false;
}

void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        if (!creates_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }
}

void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool has_incoming_edge = false;

        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                has_incoming_edge = true;
                break;
            }
        }

        if (!has_incoming_edge)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
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