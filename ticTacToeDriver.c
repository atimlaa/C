/**
 * Debugger: Aryan Timla
 * Hack 09
 * Date: 10-28-2019
 * We were provided source files and a makefile that builds a tic-tac- toe game project to debug.
 * The game allows a player to select several different modes including a 2-player game,
 * a 1-player versus the computer (which makes random moves) and a 1-player versus a “smart” computer.
 */
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#include "gameUtils.h"
#include "playerUtils.h"

int main(int argc, char **argv) {

  srandom(time(NULL));

  int gameChoice = mainMenu();
  Move **board = newBoard();
  Status s = getStatus(board);

  while(s == PLAYING) {

    //x moves
    printBoard(board);
    userMove(board, X);
    s = getStatus(board);
    if(s != PLAYING) {
      break;
    }

    //o moves
    printBoard(board);
    if(gameChoice == TWO_PLAYER) { //bugfound
      userMove(board, O);
    } else if(gameChoice == ONE_PLAYER_RANDOM) {
      randomComputerMove(board);
    } else if(gameChoice == ONE_PLAYER_SMART) {
      smartComputerMove(board);
    }
    s = getStatus(board);

  }

  printf("Final Board:\n");
  printBoard(board);

  if(s == O_WINS) {
    printf("O Wins!\n");
  } else if(s == X_WINS) {
    printf("X Wins!\n");
  } else if(s == TIE) {
    printf("Tie\n");
  }

  return 0;
}
