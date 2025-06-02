#include <iostream>
#include "./classes/game.h"
#include "./classes/figure.h"
#include "./classes/figures/pawn.h"

using namespace std;


int main() {
    Game game;
    game.main_cycle();

    // Board tmp;
    // Figure *k = tmp.create_figure(21);
    // cout << k->get_pos() << endl;


    return 0;
}
