#ifndef RNG_RAND_H
#define RNG_RAND_H

#include "types.h"

void rng_init();

int rng_rand_avail();
u32 rng_rand_get();

void rng_rand_set_rewind_point();
void rng_rand_rewind();
void rng_rand_clear_rewind_point();

void rng_rand_irq_enable(int en);

#endif
