#include <iostream>
#include "./classes/game.h"
#define STARTED_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"

using namespace std;

int main() {
    Board board;
    board.set_start_pos(STARTED_POS);
    board.show();

    return 0;
}
