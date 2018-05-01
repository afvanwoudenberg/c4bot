/* c4bot.h
 * Created by Aswin van Woudenberg <https://github.com/afvanwoudenberg>
 * Collaboration of Leonardo Mauro <https://github.com/leomaurodesenv>
 * link: https://github.com/afvanwoudenberg/c4bot
 */

#ifndef C4BOT_H
#define C4BOT_H

#include <string>
#include <vector>

#include "c4.h"

using namespace std;

class C4Bot {
    // Variables
	int timebank;
	int time_per_move;
	string player_names[2];
	string your_bot;
	int your_botid;
	int field_columns;
	int field_rows;

	int round;
	State state = { { { { Player::None } } } };

	// Support functions
	vector<string> split(const string &s, char delim);
	int string2int(string &str);
	void print(State &state);
	Player get_player(bool your_bot);

	// Structure functions
	void setting(string &key, string &value);
	void update(string &key, string &value);
	void move(int timeout);

public:
	void run();
};

#endif // C4BOT_H

