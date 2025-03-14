#pragma once
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>

using namespace std;

//EXAMPLE 1 : TRIANGLE
//PRE: accepts an integer n ('tallest column')
//POST: calculates the number of blocks needed to complete a right-angled triangle
//      triangle - non-recursive
//     rTriangle - recursive
int triangle(int n);
int rTriangle(int n);

//EXAMPLE 2 : FIBONACCI
//PRE: accepts an integer n  
//POST: calculates the fibonacci sum to that position
//      fib - non-recursive  //TASK  
//     rFib - recursive
//     fib2 - recursive (better)
int fib(int n);
int rFib(int n);
int fib2Wrap(int n);

//EXAMPLE 3 TASK : AVERAGE
//PRE: accepts a list that has been initialized  
//POST: calculates the average recursively for that list
//     rAvg - recursive 
int rAvgWrap(const list<int>& myList);

//EXAMPLE 4 TASK : BINARY SEARCH 
//PRE:  v1 is a vector that contains integers
//POST: returns the position of target in the
//      vector or -1 if it is not in the vector
int binarySearchWrap(const vector<int>& v1, int target);

//EXAMPLE 5 : PERMUTATIONS
void printVector(vector<string> s);
void printVector(vector<int> s);

//PRE:  function accepts a string
//POST: function prints all combinations of the text
void AnagramWrap(string text);
void permute5B(vector<string>& list, int left, int right);
void permute5C(vector<int> listOld, vector<int> listNew);
void permute5D(vector<string>& s, int idx);

class Item {
public:
    string itemName;  // Name of item
    int priceDollars; // Price of item
};

void ShoppingBagCombinations(vector<Item> currBag, vector<Item> remainingItems);
void ShoppingBagCombinationsWrap();


//EXAMPLE 6 : BINARY TREE
void printBinaryTree();

//EXAMPLE 7 : BACKTRACKING TO FIND PATH
void backTrackingWrap();

//EXAMPLE 8 : FINDING FASTEST TRACK
void fastestTrackWrap();

//EXAMPLE 9 : QUEENS MOVE PROBLEM
void queensMovesWrap();
