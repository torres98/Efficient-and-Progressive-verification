#ifndef RANDOM_UTILS_H
#define RANDOM_UTILS_H

#include <algorithm>
#include <random>

#include <zephyr/random/rand32.h>

#include "math_utils.h"

static std::mt19937 rng(sys_rand32_get());


template <typename Element>
void fill_matrix_randomly(MatrixDS<Element> &M, uint8_t min = 0, uint8_t max = 255) {
    std::uniform_int_distribution<uint8_t> element_dist(min, max);
    
    for (unsigned int i = 0; i < M.nrows(); i++)
        for (unsigned int j = 0; j < M.ncolumns(); j++)
            M.set(i, j, Element(element_dist(rng)));

}

template <typename Element>
void shuffle_array(Element* arr, unsigned int n) {
    shuffle(arr, arr + n, rng);
}

#endif
