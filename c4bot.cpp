// c4bot.cpp
// Aswin van Woudenberg

#include "c4bot.h"

#include <iostream>
#include <sstream>

void C4Bot::run() {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::vector<std::string> command = split(line, ' ');
		if (command[0] == "settings") {
			setting(command[1], command[2]);
		} else if (command[0] == "update" && command[1] == "game") {
			update(command[2], command[3]);
		} else if (command[0] == "action" && command[1] == "move") {
			move(std::stoi(command[2]));
		} else {
			std::cerr << "Unknown command: " << line << std::endl;
		}
	}
}

void C4Bot::move(int timeout) {
	// Do something more intelligent here instead of returning a random move
	std::vector<Move> moves = getMoves(state);
	std::cout << "place_disc " << *select_randomly(moves.begin(), moves.end()) << std::endl;
}

void C4Bot::update(std::string &key, std::string &value) {
	if (key == "round") {
		round = std::stoi(value);
	} else if (key == "field") {
		int row = 0;
		int col = 0;
		std::vector<std::string> fields = split(value, ',');
		for (std::string &field : fields) {
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

void C4Bot::setting(std::string &key, std::string &value) {
	if (key == "timebank") {
		timebank = std::stoi(value);
	} else if (key == "time_per_move") {
		time_per_move = std::stoi(value);
	} else if (key == "player_names") {
		std::vector<std::string> names = split(value, ',');
		player_names[0] = names[0];
		player_names[1] = names[1];
	} else if (key == "your_bot") {
		your_bot = value;
	} else if (key == "your_botid") {
		your_botid = std::stoi(value);
	} else if (key == "field_width") {
		field_columns = std::stoi(value);
	} else if (key == "field_height") {
		field_rows = std::stoi(value);
	}
}

std::vector<std::string> C4Bot::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

