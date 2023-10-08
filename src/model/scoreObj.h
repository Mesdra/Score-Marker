#ifndef __SCOREOBJ__H__
#define __SCOREOBJ__H__
struct ScoreOBJ
{
  int score1;       // Score Team One
  int score2;       // Score Team Two
  int endGameScore; // Score u need have to win the game
  int value;        // Subtract or add value score
  int game;         // Selected Game
  bool endGame;
  bool hasChanged;
};
#endif //!__SCOREOBJ__H__
