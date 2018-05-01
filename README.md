# C4Bot

A C++ [connect four](https://playground.riddles.io/competitions/four-in-a-row) starter bot for the [riddles.io](https://www.riddles.io) platform.    
This class offers support to begin your artificial intelligence to play connect four.    
    
----

### Compile
    
To compile your code using the Code::Blocks IDE `codeblocks/c4bot.cbp`, or command line:    
    

```sh
g++ -std=c++1y -static -Isrc -O2 -lm $SOURCE
```
    
----

### Class Structure

```cpp
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
```
    
----
   
## Also look ~
    
* [License MIT](https://opensource.org/licenses/MIT)
* Github: [c4bot](https://github.com/afvanwoudenberg/c4bot)
