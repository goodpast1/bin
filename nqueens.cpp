#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<string> &board, int row, int col, int n)
{
  for (int i = 0; i < row; i++)
  {
    if (board[i][col] == 'Q')
      return false;
  }
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) // upper left diagonal
  {
    if (board[i][j] == 'Q')
      return false;
  }
  for (int i = row, j = col; i >= 0 && j < n; i--, j++)
  {
    if (board[i][j] == 'Q')
      return false;
  }
  return true;
}
void print_board(vector<string> &board)
{
  for (string row : board)
  {
    cout << row << endl;
  }
  cout << endl;
}
void solve_nqueens_bt(vector<vector<string>> &res, vector<string> &board, int row, int n)
{
  if (row == n)
  {
    res.push_back(board);
    print_board(board);
    return;
  }
  for (int col = 0; col < n; col++)
  {
    if (is_safe(board, row, col, n))
    {
      board[row][col] == 'Q';
      print_board(board);
      solve_nqueens_bt(res, board, row + 1, n);
      board[row][col] = '.';
    }
  }
}