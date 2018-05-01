/* c4bot.cpp
 * Created by Aswin van Woudenberg <https://github.com/afvanwoudenberg>
 * Collaboration of Leonardo Mauro <https://github.com/leomaurodesenv>
 * link: https://github.com/afvanwoudenberg/c4bot
 */

#include "c4bot.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void C4Bot::run() {
	string line;
	while (getline(cin, line)) {
		vector<string> command = split(line, ' ');
		if (command[0] == "settings") {
			setting(command[1], command[2]);
		} else if (command[0] == "update" && command[1] == "game") {
			update(command[2], command[3]);
		} else if (command[0] == "action" && command[1] == "move") {
			move(string2int(command[2]));
		} else {
			cerr << "Unknown command: " << line << endl;
		}
	}
}

vector<string> C4Bot::split(const string &s, char delim) {
	vector<string> elems;
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

int C4Bot::string2int(string &str){
    istringstream buffer(str);
    int value;
    buffer >> value;
    return value;
}

void C4Bot::print(State &state){
    for(int row = 0; row < field_rows; row++){
	    for(int col = 0; col < field_columns; col++){
        	if(state[row][col] == Player::None) cout<<"-";
        	else if(state[row][col] == Player::X) cout<<"0";
        	else if(state[row][col] == Player::O) cout<<"1";
            cout<<" ";
	    }
	    cout<<endl;
    }
}

Player C4Bot::get_player(bool your_bot){
    Player player = (your_botid == 0) ? Player::X : Player::O;
    Player opponent = (your_botid == 0) ? Player::O : Player::X;
    return (your_bot) ? player : opponent;
}

void C4Bot::update(string &key, string &value) {
	if (key == "round") {
		round = string2int(value);
	} else if (key == "field") {
		int row = 0;
		int col = 0;
		vector<string> fields = split(value, ',');
		for (string &field : fields) {
			if (field == "0") {
				state[row][col] = Player::X;
			} else if (field == "1") {
				state[row][col] = Player::O;
			} else {
				state[row][col] = Player::None;
			}
			col++;
			if (col == 7) {
				row++;
				col = 0;
			}
		}
	}
}

void C4Bot::setting(string &key, string &value) {
	if (key == "timebank") {
		timebank = string2int(value);
	} else if (key == "time_per_move") {
		time_per_move = string2int(value);
	} else if (key == "player_names") {
		vector<string> names = split(value, ',');
		player_names[0] = names[0];
		player_names[1] = names[1];
	} else if (key == "your_bot") {
		your_bot = value;
	} else if (key == "your_botid") {
		your_botid = string2int(value);
	} else if (key == "field_width") {
		field_columns = string2int(value);
	} else if (key == "field_height") {
		field_rows = string2int(value);
	}
}

void C4Bot::move(int timeout) {
	// Do something more intelligent here instead of returning a random move
	vector<Move> moves = getMoves(state);
	// print(state); // print boardř
	cout << "place_disc " << *select_randomly(moves.begin(), moves.end()) << endl;
}
