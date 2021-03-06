/* -Use a struct to define a card as an enumerated member that is its suit value and a short that is its pips value.
-Write a function that randomly shuffles the deck.
-Submit your work as a text file. 
-Then deal out 7 card hands and evaluate the probability that a hand has no pair, one pair, two pair, three of a kind, full house and 4 of a kind.
-This is a Monte Carlo method to get an approximation to these probabilities.  Use at least 1 million randomly generated hands.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define PIPES 13
#define HAND_SIZE 7
#define TRIALS 1000000
#define DECK_SIZE (SUITS*PIPES)

typedef struct playing_card{
    enum suit{clubs, diamonds, hearts, spades} s;
    short p;
}card;

struct hand_stats
{
    unsigned long total;
    unsigned long no_pair;
    unsigned long one_pair;
    unsigned long three_of_kind;
    unsigned long two_pair;
    unsigned long four_of_kind;
    unsigned long full_house;
};

void shuffle_deck(card *deck, int length)
{
    int i, j;
    card temp;
    for(i = 0; i < length; i++)
    {
        j = rand() % length;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void evaluate_hand(card *hand, int length, struct hand_stats *stats)
    {
    unsigned value_count[PIPES] = { 0 }; /* how many cards of each pip value */
    for (int i = 0;  i < length;  ++i) {
        ++value_count[hand[i].p];
    }

    unsigned count[SUITS+1] = { 0 }; /* how many singletons, pairs etc */
    for (int i = 0;  i < PIPES;  ++i) {
        ++count[value_count[i]];
    }

    if (count[4]) {
        ++stats->four_of_kind;
    }
    else if (count[3] && count[2] || count[3] >= 2) {
        ++stats->full_house;
    }
    else if (count[3]) {
        ++stats->three_of_kind;
    }
    else if (count[2] >= 2) {
        ++stats->two_pair;
    }
    else if (count[2]) {
        ++stats->one_pair;
    }
    else {
        ++stats->no_pair;
    }
    ++stats->total;
}


int main(void)
{
    srand((unsigned)time(0));
    card deck[DECK_SIZE];

    int i=0;
    for (short j=1, k=0; j<=SUITS; j++){
        for (short l=1; l<=PIPES; l++){
            deck[i].s = j;
            deck[i].p = l;
            //printf("%d %d\n", deck[i].s, deck[i].p); //for testing
            i++;
        }
    }
    
    struct hand_stats stats = {0, 0, 0, 0, 0, 0, 0};
    for (int i=0; i<TRIALS; i++){
        shuffle_deck(deck, DECK_SIZE);
        for (int j = 0;  j + HAND_SIZE < DECK_SIZE;  j += HAND_SIZE) {
            evaluate_hand(deck+j, HAND_SIZE, &stats);
        } 
    }
    const long double total = stats.total;
    printf("No pair probablity =  %Lf\n",        stats.no_pair       / total);
    printf("One pair probability = %Lf\n",       stats.one_pair      / total);
    printf("Two pair probability = %Lf\n",       stats.two_pair      / total);
    printf("Three of a kind probablity = %Lf\n", stats.three_of_kind / total);
    printf("Four of a kind probability = %Lf\n", stats.four_of_kind  / total);
    printf("Full house probability = %Lf\n",     stats.full_house    / total);
}

