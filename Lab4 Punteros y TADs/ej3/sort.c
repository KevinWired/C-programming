/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y) {
    return x->rank <= y->rank;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

static unsigned int partition(player_t a[], unsigned int lft, unsigned int rgt) {
	unsigned int ppiv = lft;
	unsigned int index_i = lft + 1;
	unsigned int index_j = rgt;
	while (index_i <= index_j) {
		if (goes_before(a[index_i], a[ppiv])) {
			index_i++;
		} else if (goes_before(a[ppiv], a[index_j])) {
			index_j--;
		} else {
			swap(a, index_i, index_j);
			index_i++;
			index_j--;
		}
	}
	swap(a, ppiv, index_j);
	ppiv = index_j;
	return (ppiv);
}

static void quick_sort_rec(player_t a[], unsigned int lft, unsigned int rgt) {
    if (lft < rgt) {
        unsigned int ppiv = partition(a, lft, rgt);
        quick_sort_rec(a, lft, (ppiv == 0u ? 0u : ppiv - 1));
        quick_sort_rec(a, ppiv + 1, rgt);
    }
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

