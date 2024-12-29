#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool is_loop_global;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void clear_preferences(void);
void is_loop(int father, int son);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
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

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    clear_preferences();

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

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

// clear preferences
void clear_preferences(void)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            preferences[i][j] = 0;
        }
    }
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    bool have_candidate = false;
    int aux = 0;
    // make linear search to verify if there is a candidate equals the user's input
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            have_candidate = true;
            aux = i;
            break;
        }
    }
    if (have_candidate)
    {
        ranks[rank] = aux;
        return true;
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // update ranks without go over the bounds of the array
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0, length = (candidate_count * (candidate_count - 1)) / 2; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            // verify if the preference is not equal itself to linear search the greater win margin
            if (preferences[i][j] != preferences[j][i])
            {
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                }
                else
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                }
                pair_count += 1;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int greater;
    int aux;
    pair greater_pair;
    // do selection sort ordering by the greatest number
    for (int i = 0; i < pair_count; i++)
    {
        aux = i;

        for (int j = i; j < pair_count; j++)
        {
            if (j == i)
            {
                greater = preferences[pairs[i].winner][pairs[i].loser];
            }
            if (preferences[pairs[j].winner][pairs[j].loser] > greater)
            {
                greater = preferences[pairs[j].winner][pairs[j].loser];
                aux = j;
            }
        }

        greater_pair = pairs[aux];

        pairs[aux] = pairs[i];
        pairs[i] = greater_pair;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // lock pairs when no loop
    for (int i = 0; i < pair_count; i++)
    {
        is_loop_global = false;

        is_loop(pairs[i].winner, pairs[i].loser);

        if (is_loop_global == false)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // search for the one with no lock-ins and declares it the winner
    for (int i = 0; i < pair_count; i++)
    {
        int possible_pair = 0;
        bool is_winner = false;
        while (locked[possible_pair][i] == false)
        {
            if (possible_pair == pair_count)
            {
                is_winner = true;
                break;
            }
            possible_pair += 1;
        }
        if (is_winner)
        {
            printf("%s\n", candidates[i]);
            break;
        }
    }
    return;
}

// recursive function that verify if there is a loop when making a new "lock-in"
void is_loop(int father, int son)
{
    if (father == son)
    {
        is_loop_global = true;
    }

    for (int i = 0; i < pair_count; i++)
    {
        if (locked[son][i] == true)
        {
            is_loop(father, i);
        }
    }
}
