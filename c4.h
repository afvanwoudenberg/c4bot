/* c4.h
 * Created by Aswin van Woudenberg <https://github.com/afvanwoudenberg>
 * Collaboration of Leonardo Mauro <https://github.com/leomaurodesenv>
 * link: https://github.com/afvanwoudenberg/c4bot
 */

#ifndef C4_H
#define C4_H

#include <array>
#include <vector>
#include <ctime>
#include <random>
#include <iterator>
#include <iostream>

using namespace std;

enum class Player { None, X, O };
using Move = int;
using State = array<array<Player,7>,6>;

// used to get a random element from a container
template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    uniform_int_distribution<> dis(0, distance(start, end) - 1);
    advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static random_device rd;
    static mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

ostream &operator<<(ostream& os, const Player &p);
ostream &operator<<(ostream& os, const State &s);
Player getCurrentPlayer(const State &state);
State doMove(const State &state, const Move &m);
Player getWinner(const State &state);
vector<Move> getMoves(const State &state);

#endif // C4_H

