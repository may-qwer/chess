#include <iostream>
#include "./classes/game.h"
// #include "./classes/figure.h"
#include "./classes/figures/pawn.h"

using namespace std;


int main() {
    // Game game;
    // game.main_cycle();

    const int i = 73;
    Pawn tmp("\033[1;34mp", i);
    cout << tmp.get_pos() << endl;
    cout << tmp.get_color_and_figure() << endl;

    return 0;
}
