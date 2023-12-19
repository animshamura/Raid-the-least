/* Author - Shamura Ahmad /*
  
#include <bits/stdc++.h>
using namespace std;

int row, col;
int matrix[1000][1000];
int matrix2[1000][1000];

int findHighestTotal() {

  for (int i = row - 2; i >= 0; i--) {
    for (int j = 0; j < col; j++) {
      int highestAdjacent = matrix2[i + 1][j];
      if (j > 0) highestAdjacent = max(highestAdjacent, matrix2[i + 1][j - 1]);
      if (j < col - 1) highestAdjacent = max(highestAdjacent, matrix2[i + 1][j + 1]);
      matrix2[i][j] += highestAdjacent;
    }
  }

  int highestTotal = matrix2[0][0];
  for (int j = 1; j < col; j++)
    if (matrix2[0][j] > highestTotal) highestTotal = matrix2[0][j];

  return highestTotal;
}

int findLowestTotal() {

  for (int i = row - 2; i >= 0; i--) {
    for (int j = 0; j < col; j++) {
      int lowestAdjacent = matrix[i + 1][j];
      if (j > 0) lowestAdjacent = min(lowestAdjacent, matrix[i + 1][j - 1]);
      if (j < col - 1) lowestAdjacent = min(lowestAdjacent, matrix[i + 1][j + 1]);
      matrix[i][j] += lowestAdjacent;
    }
  }

  int lowestTotal = matrix[0][0];
  for (int j = 1; j < col; j++)
    if (matrix[0][j] < lowestTotal) lowestTotal = matrix[0][j];

  return lowestTotal;
}

int main() {

  cout << "Please enter the desired grid dimension: ";
  cin >> row >> col;
  
  cout << "Please enter the desired input:" << endl;

  for (int i = 0; i < row; i++) 
    for (int j = 0; j < col; j++) 
           { cin>>matrix[i][j]; matrix2[i][j] = matrix[i][j];}
  

  cout << "The highest total: " << findHighestTotal() << endl;
  cout << "The lowest total: " << findLowestTotal() << endl;

  return 0;
}
