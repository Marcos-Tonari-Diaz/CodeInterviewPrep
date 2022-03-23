// deck of cards

#include <vector>
using namespace std;

enum Rank {
  ACE = 1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  Jack,
  Queen,
  King
};
enum Suit { DIAMONDS, HEARTS, CLUBS, SPADES };

class Card {
  Rank rank;
  Suit suit;
};

class Player {
  unsigned score;
  vector<vector<Card>> player_cards;

 public:
  void draw_card();
  void discard_card(Rank rank, Suit Suit);
  void play_card(Rank rank, Suit Suit);
};

class Deck {
  vector<Card> card_stack;

 public:
  Deck(){};
  virtual void deal_cards();
  void draw_card();    // random draw from stack
  void insert_card();  // insert card intp stack
  void shuffle_stack();
};

class Game {
  Deck table_cards;
  vector<Player> players;
};

class Rummy_Deck : Deck {
 public:
  void deal_cards();
};