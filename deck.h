#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - Enumerate.
 * @SPADE: Spades card.
 * @HEART: Hearts card.
 * @CLUB: Clubs card.
 * @DIAMOND: Diamonds card.
 */
typedef enum kind_c
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_d;

/**
 * struct card_suit - Card
 *
 * @value: Value of the card
 * @kind: Kind of the card
 */
typedef struct card_suit
{
	const char *value;
	const kind_d kind;
} card_d;

/**
 * deck_node_a - Deck of card
 *
 * @card: Pointer to the card
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct deck_node_a
{
	const card_d *card;
	struct deck_node_a *prev;
	struct deck_node_a *next;
} deck_node_b;

void sort_deck(deck_node_b **deck);

#endif /* DECK_H */
