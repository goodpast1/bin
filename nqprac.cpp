#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<string> &board, int row, int col, int n)
{

  for (int i = 0; i < row; i++)
  {
    if (board[i][col] == 'Q')
      return false;
  }
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
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

void solve_nqueens(vector<vector<string>> &res, vector<string> &board, int row, int n)
{
  if (row == n)
  {
    res.push_back(board);
    return;
  }
  for (int col = 0; col < n; col++)
  {
    if (is_safe(board, row, col, n))
    {
      board[row][col] = 'Q';
      solve_nqueens(res, board, row + 1, n);
      board[row][col] = '.';
    }
  }
}
void solve_nqueens_branch(vector<vector<string>> &res, vector<string> board, int row, int n, vector<int> &leftrow, vector<int> upperdiagonal, vector<int> lowerdiagonal)
{
  if (row == n)
  {
    res.push_back(board);
    return;
  }
  for (int col = 0; col < n; col++)
  {
    if (leftrow[col] == 0 && upperdiagonal[row + col] == 0 && lowerdiagonal[n - 1 + col - row] == 0)
    {
      board[row][col] = 'Q';
      leftrow[col] = 1;
      upperdiagonal[row + col] = 1;
      lowerdiagonal[n - 1 + col - row] = 1;

      solve_nqueens_branch(res, board, row + 1, n, leftrow, upperdiagonal, lowerdiagonal);

      board[row][col] = '.';
      leftrow[col] = 0;
      upperdiagonal[row + col] = 0;
      lowerdiagonal[n - 1 + col - row] = 0;
    }
  }
}

int main()
{
  int n;
  cout << "enter size of n :";
  cin >> n;
  vector<vector<string>> res;
  vector<string> board(n, string(n, '.'));
  vector<int> leftrow(n, 0);
  vector<int> upperdiagonal(2 * n - 1, 0);
  vector<int> lowerdiagonal(2 * n - 1, 0);

  solve_nqueens(res, board, 0, n);
  int sol = res.size();
  if (sol == 0)
  {
    cout << "No possible solution " << endl;
  }
  else
  {
    cout << "Number of possible solutions are: " << sol << endl;
    cout << "Possible solutions [BACKTRACKING]: " << endl;
    for (vector<string> board : res)
    {
      print_board(board);
    }
  }

  res.clear();

  solve_nqueens_branch(res, board, 0, n, leftrow, upperdiagonal, lowerdiagonal);
  // int sol = res.size();
  if (sol == 0)
  {
    cout << "No possible solution " << endl;
  }
  else
  {
    cout << "Number of possible solutions are: " << sol << endl;
    cout << "Possible solutions [BRANCH AND BOUND]: " << endl;
    for (vector<string> board : res)
    {
      print_board(board);
    }
  }
  return 0;
}