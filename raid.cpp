/* Author - Shamura Ahmad */

#include <bits/stdc++.h>
using namespace std;

int row, col;

int findHighestTotal(vector<vector<int>> matrix) {
  
    for (int i = row - 2; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            int highestAdjacent = max(max(matrix[i + 1][j], matrix[i + 1][j - 1]), matrix[i + 1][j + 1]);
            matrix[i][j] += highestAdjacent;
        }
    }

    int highestTotal = matrix[0][0];
    for (int j = 1; j < col; j++) 
        if (matrix[0][j] > highestTotal) highestTotal = matrix[0][j];
        
    return highestTotal;
}

int findLowestTotal(vector<vector<int>> matrix) {
  
    for (int i = row - 2; i >= 0; i--) {
        for (int j = 0; j < col; j++) {
            int lowestAdjacent = min(min(matrix[i + 1][j], matrix[i + 1][j - 1]), matrix[i + 1][j + 1]);
            matrix[i][j] += lowestAdjacent;
        }
    }

    int lowestTotal = matrix[0][0];
    for (int j = 1; j < col; j++) 
        if (matrix[0][j] < lowestTotal) lowestTotal = matrix[0][j];
        
    return lowestTotal;
}

int main() {

    cout<<"Please enter the desired greed dimension : ";
    cin>>row>>col;
    
    std::vector<vector<int>> matrix;
    
    cout<<"Please enter the desired input : "<<endl;
    
    for(int i = 0; i < row; i++){
        vector<int> column;
        int n;
       for(int j = 0; j < col; j++){
           cin>>n;
           column.push_back(n);
       }
        matrix.push_back(column);
    }
    
    cout<<"The highest total : "<<findHighestTotal(matrix)<<endl;
    cout<<"The lowest total  : "<<findLowestTotal(matrix)<<endl;
    

    return 0;
}


