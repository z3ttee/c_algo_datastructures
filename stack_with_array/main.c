#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 32

typedef enum GameColor { Schell = 9, Rot, Gruen, Kreuz } GameColor;

typedef struct GameCard {
    char *name;
    GameColor color;
    int value;
} GameCard;

GameCard *createCard(GameColor color, char *name, int value);
void push(int *top, GameCard *card, GameCard **stack);
GameCard pop(int *top, GameCard **stack);

int main(void) {

    // GameCard stack[32];
    GameCard *stack = (GameCard *) malloc(sizeof(GameCard) * MAX_CARDS);
    int top = 0;

    GameCard *card1 = createCard(Kreuz, "Seven", 0);
    GameCard *card2 = createCard(Kreuz, "King", 4);
    GameCard *card3 = createCard(Kreuz, "Ten", 10);
    GameCard *card4 = createCard(Gruen, "Nine", 0);

    push(&top, card1, &stack);
    push(&top, card2, &stack);
    push(&top, card3, &stack);
    push(&top, card4, &stack);

    GameCard poppedCard = pop(&top, &stack);
    printf("%s\n", poppedCard.name); // Seven

    poppedCard = pop(&top, &stack);
    printf("%s", poppedCard.name); // King
    return 0;
}

/**
 * Add element to the stack
 * @param top Top index
 * @param card Card to push to stack
 * @param stack Stack to push to
 */
void push(int *top, GameCard *card, GameCard **stack) {
    (*stack)[*top] = *card;
    ++(*top);
}

/**
 * Get the top element from the stack
 * @param top Current index of top
 * @param stack Stack of GameCard
 * @return Instance of GameCard
 */
GameCard pop(int *top, GameCard **stack) {
    GameCard *cardPtr = (stack)[*top];
    --(*top);

    GameCard card = *cardPtr;
    free(cardPtr);
    return card;
}

/**
 * Create a new card for the game
 * @param color Color of the card
 * @param name Name of the card
 * @param value Numerical value of the card
 * @return GameCard
 */
GameCard *createCard(GameColor color, char *name, int value) {
    GameCard *tmp = (GameCard *) malloc(sizeof(GameCard));

    if(tmp == NULL) {
        return NULL;
    }

    tmp->value = value;
    tmp->color = color;
    tmp->name = name;

    return tmp;
}
