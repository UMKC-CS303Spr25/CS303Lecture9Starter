// CS303Lecture9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Recursive.h"

int main() {
    
    cout << "EXAMPLE 1\n";
    cout << triangle(5) << endl;
    cout << rTriangle(5) << endl;
    cout << endl << endl << endl;
    
    cout << "EXAMPLE 2\n";
    cout << fib(13) << endl;   //TASK  
    cout << rFib(13) << endl;
    cout << fib2Wrap(13) << endl;
    cout << endl << endl << endl;
    

    //EXAMPLE 3 TASK: AVERAGE
    //using recursion, find the average of a list of integers
    //using an iterator & wrapper function
    
    cout << "EXAMPLE 3 TASK\n";
    list <int> myList = { 1,3,5,7,9,11,13,15 };
    cout << rAvgWrap(myList) << endl;
    cout << endl << endl << endl;
    
    
    //EXAMPLE 4 TASK: BINARY SEARCH
    //write the binary search function - using recursion
    vector<int> v1 = { 15, 16, 23, 26, 37 ,48 ,68, 78, 99 };
    cout << "15 found in position:  " << binarySearchWrap(v1, 15) << endl;
    cout << "99 found in position:  " << binarySearchWrap(v1, 99) << endl;
    cout << "101 found in position: " << binarySearchWrap(v1, 101) << endl;
    cout << endl << endl << endl;
    
    
    
    //EXAMPLE 5 ANAGRAM
    cout << "\n\nEXAMPLE 5A: PERMUTATIONS WITH ANAGRAMS\n";
    string text = "cat";
    AnagramWrap(text);
    cout << endl << endl << endl;
    
    //OTHER EXAMPLES
    cout << "\n\nEXAMPLE 5B: PERMUTATIONS 5B\n";
    vector<string> wordList = {"C", "A", "T"};
    permute5B(wordList, 0, 2);
    cout << endl << endl << endl;

    cout << "\n\nEXAMPLE 5C: PERMUTATIONS 5C\n";
    vector<int> numbList = { 1,2,3 };
    vector<int> numbListNew;
    permute5C(numbList, numbListNew);

    cout << "\n\nEXAMPLE 5D: PERMUTATIONS 5D\n";
    wordList = { "C", "A", "T" };
    permute5D(wordList, 0);
    cout << endl << endl << endl;

    cout << "\n\nEXAMPLE 5E: PERMUATIONS 5E\n";
    ShoppingBagCombinationsWrap();
    cout << endl << endl << endl;
    
    
    
    cout << "\n\nEXAMPLE 6: PRINT BINARY TREES\n";
    printBinaryTree();
    cout << endl << endl << endl;
    
    
    
    cout << "\n\nEXAMPLE 7: BACKTRACKING\n";
    backTrackingWrap();
    cout << endl << endl << endl;
    /*
    cout << "\n\nEXAMPLE 8: FASTEST ROUTE\n";
    fastestTrackWrap();
    cout << endl << endl << endl;
    */ 

    /*
    cout << "\n\nEXAMPLE 9: QUEENS MOVE\n";
    queensMovesWrap();
    cout << endl << endl << endl;
    */

}