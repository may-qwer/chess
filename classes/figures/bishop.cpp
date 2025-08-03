#include "bishop.h"
#include "../staps.h"

Bishop::Bishop(const char t, const char* c, const int p, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS, MAX_COUNT_OF_EATING_STAPS);
}

void Bishop::set_staps() {
    int arr_of_directions[4] = {11, 9, -9, -11};
    for (int index_of_direction = 0; index_of_direction < 4; index_of_direction++) {

    }
}