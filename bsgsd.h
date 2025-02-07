#ifndef BSGSD_H
#define BSGSD_H
#include <stdint.h>

void compute_ripemd160(uint64_t key, char *output);
void bsgsd_search(uint64_t start, uint64_t end, int k_factor);

#endif