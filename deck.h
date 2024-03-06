#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_c - Enumerate.
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
} kind_t;

/**
 * struct card_s - Card
 *
 * @value: Value of the card
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * deck_node_a - Deck of card
 *
 * @card: Pointer to the card
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

void sort_deck(deck_node_t **deck);
int str_cmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
