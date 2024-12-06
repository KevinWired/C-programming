#include "pair.h"


pair_t pair_new(int x, int y) {
	pair_t pair_new = {x, y};
	return pair_new;
}

int pair_first(pair_t p) {
	return p.fst;
}

int pair_second(pair_t p) {
	return p.snd;
}
pair_t pair_swapped(pair_t p) {
	int aux = pair_first(p);
	p.fst = pair_second(p);
	p.snd = aux;
	return p;
}

pair_t pair_destroy(pair_t p) {
	return p;
}
