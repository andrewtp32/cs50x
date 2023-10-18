#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();
        // for (int i = 0; i < candidate_count; i++)
        //     printf("%s has %i votes\n", candidates[i].name, candidates[i].votes);

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO

    // loop through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // check if name matches a candidate
        if (strcmp(name, candidates[i].name) == 0)
        {
            // the preferences array gets the index of the candidate (e.g., 1st candidate's index is 0, 2nd candidates index is 1,
            // and so on)
            preferences[voter][rank] = i;
            // break the function
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO

    // query each voter
    for (int i = 0; i < voter_count; i++)
    {
        // query each rank
        for (int j = 0; j < candidate_count; j++)
        {
            // check if candidate is eliminated. if eliminated, we pass over this if statement and look to to the next rank (aka
            // make from rank one to rank 2)
            if (candidates[preferences[i][j]].eliminated == false)
            {
                // add one to the votes
                candidates[preferences[i][j]].votes++;
                // break out of loop so we don't keep adding votes (aka so we dont keep querying through the ranks and adding votes)
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO

    int winning_count = voter_count / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winning_count)
        {
            printf("%s", candidates[i].name);
            printf("\n");
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO

    // initalize min_votes variable to be one larger than the highest possible amount of votes
    int min_votes = voter_count + 1;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }

    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    float available_candidate_count = 0.0;
    float sum = 0;
    // loop through all candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // check if a candidate has been eliminated
        if (candidates[i].eliminated == false)
        {
            sum += candidates[i].votes;
            available_candidate_count++;
        }
    }

    if (sum / available_candidate_count == min)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
            candidates[i].eliminated = true;
    }
    return;
}