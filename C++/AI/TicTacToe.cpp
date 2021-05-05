//Author: Dhruvil Patel

//TicTacToe Solution

#include<bits/stdc++.h>

using namespace std;

//A structure with row,column and score of a move as attributes
struct Move
{
  int r, c, score;
};

//a structure of TicTacToe with attributes and functions
struct TicTacToe
{
  //initializing
  char player_mark, computer_mark, board[3][3];

  //constructor---initializing the bord with white space
  TicTacToe()
  {
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        board[i][j]=' ';
      }
    }
  }

  //function to check for win
  bool win() {
      //these are the cells possible for winning
      int win_states[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

      //traversing the win_states
      for (int i = 0; i < 8; i++) {
          //initializing the win varibale with true
          bool win = true;

          //getting the first cell as (first_r,first_c)
          int first_r = win_states[i][0]/3, first_c = win_states[i][0] % 3;
          for (int j = 0; j < 3; j++) {
              //converting each state into cell number
              int r = win_states[i][j]/3, c = win_states[i][j] % 3;

              //if any corner is empty OR the marks in the whole particular line doesnt match then win=false
              if (board[first_r][first_c] == ' ' || board[first_r][first_c] != board[r][c]) {
                  win = false;
              }
          }
          //returning true if win=true
          if (win)
              return true;
      }
      //else returning false
      return false;
  }

  //function to check for tie
  bool tie()
  {
    //if already wins then return false
    if(win())
    {
      return false;
    }


    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        //if still any empty cell remains then return false
        if(board[i][j]==' ')
        {
          return false;
        }
      }
    }

    return true;
  }

  //human player_move
  void player_move()
  {
    while(1)
    {
      //Taking input from the user to place his/her mark
      cout<<"Enter a valid cell(1-9)";
      int cell;
      cin>>cell;

      //converting the cell number (0-9) in row and column
      int r = (cell-1)/3;
      int c = (cell-1)%3;

      //chekcing if the cell is valid
      if(cell>=1 && cell<=9 && board[r][c]==' ')
      {
        //marking the cell with players mark
        board[r][c] = player_mark;
        break;
      }
     }
  }


  //Computer move
  void computer_move()
  {
    //Getting the best move for the computer
    Move bestMove = core_algo();
    //Marking the cell with computer mark
    board[bestMove.r][bestMove.c] = computer_mark;
  }

    //Core algo for calculating the move for computer
                  //Initially the computer is marked as maximizing_player player
    Move core_algo(bool maximizing_player = true)
    {
        Move best_move;
        //if computer is going to make a move but before that already win state is achieved
        if (win())
        {
            if (maximizing_player) {
                //then mark that state with -1 score
                best_move.score = -1;
            } else {
                //mark that state with +1 score
                best_move.score = 1;
            }
            return best_move;
         }
         else if (tie())
         {  //tie state with 0 score
            best_move.score = 0;
            return best_move;
         }

        //Initially the best_move score will be -2 Or 2 depending on whose turn
        best_move.score = maximizing_player ? -2 : 2;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
              //if any empty cell then start recursing on that state
                if (board[i][j] == ' ')
                {
                    board[i][j] = maximizing_player ? computer_mark : player_mark;

                    //recursing here
                    Move board_state = core_algo(!maximizing_player);

                    //if its maximizing_player then it will choose the state with maximum points
                    if (maximizing_player)
                    {
                        if (board_state.score > best_move.score)
                        {
                            best_move.score = board_state.score;
                            best_move.r = i;
                            best_move.c = j;
                         }
                     }
                     //else it will choose the state with minimum points
                     else
                     {
                        if (board_state.score < best_move.score)
                        {
                            best_move.score = board_state.score;
                            best_move.r = i;
                            best_move.c = j;
                         }
                      }
                      //after all the calculation again mark the board with empty cell
                      board[i][j] = ' ';
                  }
              }
          }
          //return the best Move for computer
          return best_move;
      }

  //play function
  void play()
  {
    while(1)
    {
      //getting the human player's mark....here X goes first
      cout<<"Select symbol (X , O where X goes first)";
      cin>>player_mark;
      if(player_mark=='X' || player_mark=='O')
      {
        break;
      }
    }
    //assigning computer's mark
    computer_mark = player_mark=='X' ? 'O' : 'X';

    if(player_mark=='O')
    {
      //computer's turn
      computer_move();
    }

    //prints the board state
    print();

    while(1)
    {
      //players turn
      player_move();
      //prints the board state
      print();

      //checking for the win after human players turn
      if(win())
      {
        cout<<"Player wins\n";
        return;
      }

      //checking for tie after human players turn
      else if(tie())
      {
        cout<<"TIE\n";
        return;
      }

      cout<<"Computer makes the move\n";
      //computers turn
      computer_move();
      //prints the board state
      print();

      //checking for the win after computers move
      if(win())
      {
        cout<<"Computer wins\n";
        return;
      }
      //cheking for tie after computers move
      else if(tie())
      {
        cout<<"TIE\n";
        return;
      }

    }

  }

  //print function
  void print()
  {
    cout<<"\n";

    for(int i=0;i<3;i++)
    {
      if(i)
      {
        cout<<"------------\n";
      }

      for(int j=0;j<3;j++)
      {
        if(j)
        {
          cout<<"|";
        }

        cout<<" ";
        if(board[i][j]==' ')
        {
          cout<<3*i+j+1;
        }
        else{
          cout<<board[i][j];
        }
        cout<<" ";
      }
      cout<<"\n";
    }
    cout<<"\n";
    }

};


int main()
{
  //making an instance of the TicTacToe struct
  TicTacToe ticTacToe;
  //calling the play function
  ticTacToe.play();

  return 0;
}
