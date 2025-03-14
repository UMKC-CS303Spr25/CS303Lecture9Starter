#include "Recursive.h"

//EXAMPLE 1
int triangle(int n) {
    int sum = 0;

    while (n > 0) {
        sum += n;
        --n;
    }
    return sum;
}

//EXAMPLE 1
int rTriangle(int n) {
    if (n == 1)
        return 1;

    return n + rTriangle(n - 1);

}

//EXAMPLE 2 - TASK 
int fib(int n) {
    int sum = 1, hold_1 = 1, hold_2 = 1;
    if (n <= 2)
        return 1;

    for (int i = 3; i <= n; ++i) {
        sum = hold_1 + hold_2;
        hold_1 = hold_2;
        hold_2 = sum;
    }
    return sum;
}

//EXAMPLE 2 
int rFib(int n) {
    if (n == 1 || n == 2)
        return 1;
    return rFib(n - 1) + rFib(n - 2);
}

//EXAMPLE 2 
int fib2(int n1, int n2, int n) {
    if (n <= 2)
        return n1;

    return fib2(n1 + n2, n1, n - 1);
}

//EXAMPLE 2 
int fib2Wrap(int n) {
    if (n <= 2)
        return 1;
    return fib2(1, 1, n);
}

//EXAMPLE 3 TASK : AVERAGE
//recursive function
int rAvg(list<int> myList, list<int>::iterator itr, int total) {
    //is list at the end?

    //add to total

    //call recursive function incrementing itr
    return total;
}


//EXAMPLE 3 TASK :AVERAGE 
//wrapper function
int rAvgWrap(const list<int>& myList) {
    // check for empty list

    //call recursive function
    //send list, iterator to beginning of list, and 0 (total)

    return -1;
}

//EXAMPLE 4 TASK:  BINARY SEARCH
//recursive function
//correct function header to include all values needed to narrow search
int binarySearch(const vector<int>& v1) {



    return -1;
}
//TASK 4 BINARY SEARCH
//PRE:  v1 is a vector that contains integers
//POST: returns the position of target in the
//      vector or -1 if it is not in the vector

//wrapper function
int binarySearchWrap(const vector<int>& v1, int target) {
    //correct call to include all values needed to narrow search
    return binarySearch(v1);
}


//EXAMPLE 5A ANAGRAM
//PRE:  v1 is a vector that contains integers
//POST: returns the position of target in the
//      vector or -1 if it is not in the vector

void Anagram(string original, string text, size_t size, int pos, int& i) {

    //cout << original << " : " << text << " : " << size << " : " << pos << " : " << i << endl;
    if (size > 2 && pos == 1) //look at a smaller string
        Anagram(text, text, size - 1, 1, i);

    if (pos >= 1) {
        text = original;
        swap(text[original.size() - size], text[original.size() - size + pos]);
        cout << "\t" << ++i << " : " << text << endl; //print the permutation
    }

    if (size > 2) //look at a smaller string
        Anagram(text, text, size - 1, 1, i);

    if (pos + 1 < size) //change the pos of the char you want to swap
        Anagram(original, text, size, pos + 1, i);
}



//EXAMPLE 5A ANAGRAM
//wrapper function
void AnagramWrap(string text) { //wrapper function
    int i = 1;
    cout << "\t" << i << " : " << text << endl; //print the first premutaion 
    if (text.size() <= 1)
        return;
    Anagram(text, text, text.size(), 1, i);
}

//EXAMPLE 5B PERMUTATIONS
// Function to print permutations of the string
// This function takes two parameters:
// 1. String
// 2. Starting index of the string.

void permute5B(vector<string>& list, int left, int right) {
    // Base case
    if (left == right) {
        cout << "\t";
        printVector(list);
    }
    else {
        for (int i = left; i <= right; ++i) {
            swap(list[left], list[i]);
            permute5B(list, left + 1, right);
            swap(list[left], list[i]);
        }
    }
}

//EXAMPLE 5C PERMUTATIONS
void permute5C(vector<int> listOld, vector<int> listNew) {
    // Base case
    vector<int>::iterator it;
    int hold;

    if (listOld.size() == 0) {
        cout << "\t";
        printVector(listNew);
    }
    else {
        for (int i = 0; i < listOld.size(); ++i) {
            hold = listOld[i];
            it = listOld.begin() + i;
            listOld.erase(it);
            listNew.push_back(hold);

            permute5C(listOld, listNew);

            it = listOld.begin() + i;
            listOld.insert(it, hold);
            listNew.pop_back();


        }
    }
}

//EXAMPLE 5D PERMUTATIONS
void permute5D(vector<string>& s, int idx) {
    // Base case
    cout << "\n\tPERMUTE1 CURRENT INDEX: " << idx << " VALUE: " << s[idx] << " : \t";
    printVector(s);
    if (idx == s.size() - 1) {
        cout << "\t";
        printVector(s);
    }
    else {
        for (int i = idx; i < s.size(); ++i) {
            swap(s[idx], s[i]);
            cout << "\t\t\tAfter swap 1: (" << s[idx] << ", " << s[i] << ") : \t";
            printVector(s);
            permute5D(s, idx + 1);   // First idx+1 characters fixed
            swap(s[idx], s[i]);
            cout << "\t\t\tAfter swap 2: (" << s[idx] << ", " << s[i] << ") : \t";
            printVector(s);
        }
    }
}

//EXAMPLE 5E PERMUTATIONS
/* Output every combination of items that fit
   in a shopping bag. Each recursive call moves
   one item into the shopping bag.
*/
void ShoppingBagCombinations(vector<Item> currBag,          // Bag contents
    vector<Item> remainingItems) { // Available items

    const unsigned int MAX_ITEMS_IN_SHOPPING_BAG = 3; // Max num items
    int bagValue;        // Cost of items in shopping bag
    Item tmpGroceryItem; // Grocery item to add to bag
    unsigned int i;      // Loop index

    if (currBag.size() == MAX_ITEMS_IN_SHOPPING_BAG) { // Base case: Shopping bag full
        bagValue = 0;
        for (i = 0; i < currBag.size(); ++i) {
            bagValue += currBag.at(i).priceDollars;
            cout << currBag.at(i).itemName << "  ";
        }
        cout << "= $" << bagValue << endl;
    }
    else {                                              // Recursive case: move one
        for (i = 0; i < remainingItems.size(); ++i) {     // item to bag
            // Move item into bag
            tmpGroceryItem = remainingItems.at(i);
            remainingItems.erase(remainingItems.begin() + i);
            currBag.push_back(tmpGroceryItem);

            ShoppingBagCombinations(currBag, remainingItems);

            // Take item out of bag
            remainingItems.insert(remainingItems.begin() + i, tmpGroceryItem);
            currBag.pop_back();
        }
    }
}

void ShoppingBagCombinationsWrap() {
    vector<Item> possibleItems(0); // Possible shopping items
    vector<Item> shoppingBag(0);   // Current shopping bag
    Item tmpGroceryItem;           // Temp item

    // Populate grocery with different items
    tmpGroceryItem.itemName = "Milk";
    tmpGroceryItem.priceDollars = 2;
    possibleItems.push_back(tmpGroceryItem);

    tmpGroceryItem.itemName = "Belt";
    tmpGroceryItem.priceDollars = 24;
    possibleItems.push_back(tmpGroceryItem);

    tmpGroceryItem.itemName = "Toys";
    tmpGroceryItem.priceDollars = 19;
    possibleItems.push_back(tmpGroceryItem);

    tmpGroceryItem.itemName = "Cups";
    tmpGroceryItem.priceDollars = 12;
    possibleItems.push_back(tmpGroceryItem);

    // Try different combinations of three items
    ShoppingBagCombinations(shoppingBag, possibleItems);
}

//EXAMPLE 6 : BINARY TREE
//Only review the following if there is time
//geeksforgeeks tree traversal (preOrder)
struct node {
    int data;
    node* left;
    node* right;
};
node* newNode(int d) {
    node* newN = new node;
    newN->data = d;
    newN->left = nullptr;
    newN->right = nullptr;
    return newN;
}

//Only review the following if there is time
//geeksforgeeks tree traversal (preOrder)
//this is one example of a depth first search (DFS)

void printPreOrder(struct node* n) {
    if (n == nullptr)
        return;
    //print node data
    cout << n->data << " ";
    printPreOrder(n->left);  //traverse left side
    printPreOrder(n->right); //traverse right side
}

//Only review the following if there is time
//geeksforgeeks tree traversal (postOrder)
//this is also an example of a depth first search (DFS)

void printPostOrder(struct node* n) {
    if (n == nullptr)
        return;

    printPostOrder(n->left);  //traverse left side
    printPostOrder(n->right); //traverse right side
    //print node data
    cout << n->data << " ";
}
//Only review the following if there is time
//geeksforgeeks tree traversal (postOrder)
//this is also an example of a depth first search (DFS)

void printInOrder(struct node* n) {
    if (n == nullptr)
        return;

    printInOrder(n->left);  //traverse left side
    //print node data
    cout << n->data << " ";
    printInOrder(n->right); //traverse right side
}
void printBinaryTree() {
    //create 'tree'
    //         1
    //     2      3
    //   4   5       6
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    cout << "\nBinary Tree: PreOrder\n";
    printPreOrder(root);
    cout << "\nBinary Tree: PostOrder\n";
    printPostOrder(root);
    cout << "\nBinary Tree: InOrder\n";
    printInOrder(root);
}

void printVector(vector<string> s) {
    for (auto wrd : s)
        cout << left << setw(10) << wrd;
    cout << endl;
}

void printVector(vector<int> s) {
    for (auto wrd : s)
        cout << right << setw(5) << wrd;
    cout << endl;
}

//EXAMPLE 7 : BACKTRACKING
const int ROWSIZE = 5, COLSIZE = 5;
const int  BACKGROUND = 0, DEADEND = 1, WALLS = 2, PATH = 3;

void printGrid(int grid[ROWSIZE][COLSIZE]) {
    for (int i = 0; i < ROWSIZE; ++i) {
        for (int j = 0; j < COLSIZE; ++j)
            cout << "\t" << grid[i][j];
        cout << endl;
    }
    cout << endl << endl;
}

//EXAMPLE 7 : BACKTRACKING
bool backTrackPath(int grid[ROWSIZE][COLSIZE], int r, int c) {
    if (r < 0 || c < 0 || r >= ROWSIZE || c >= COLSIZE)
        return false;      // Cell is out of bounds.
    else if (grid[r][c] != BACKGROUND)
        return false;      // Cell is on barrier or dead end.
    else if (r == ROWSIZE - 1 && c == COLSIZE - 1) {
        grid[r][c] = PATH;         // Cell is on path
        printGrid(grid);
        return true;               // and is maze exit.
    }
    else {
        grid[r][c] = PATH;
        printGrid(grid);
        if (backTrackPath(grid, r - 1, c)
            || backTrackPath(grid, r + 1, c)
            || backTrackPath(grid, r, c - 1)
            || backTrackPath(grid, r, c + 1)) {
            return true;
        }
        else {
            grid[r][c] = DEADEND;  // Dead end.
            return false;
        }
    }
}

//EXAMPLE 7 : BACKTRACKING
void backTrackingWrap() {
    int grid[ROWSIZE][COLSIZE]{ 0 };
    //set up the path and add 'walls'
    grid[0][1] = grid[0][3] = grid[0][4] = grid[1][1] = grid[1][3] = grid[1][4] = 2;
    grid[2][3] = grid[3][1] = grid[4][1] = grid[4][3] = 2;

    printGrid(grid);
    backTrackPath(grid, 0, 0);

}

//EXAMPLE 8 : FASTEST TRACK
//Setting 'global value' for fastestTrack
int minTime = INT_MAX;

// Recursive function to find the fastest route
void fastestTrack(int grid[ROWSIZE][COLSIZE], bool visited[ROWSIZE], int curr, int count, int currTime) {
    if (count == ROWSIZE - 1) {  // If all locations visited, return to M
        currTime += grid[curr][0];  // Add time to return to M
        minTime = min(minTime, currTime);  // Update minimum time
        return;
    }

    for (int next = 1; next < ROWSIZE; next++) {  // Try all possible locations
        if (!visited[next]) {
            visited[next] = true;  // Mark as visited
            fastestTrack(grid, visited, next, count + 1, currTime + grid[curr][next]);
            visited[next] = false;  // Backtrack
        }
    }
}

void fastestTrackWrap() {
    //note: grid is also 5x5
    //set up initial distances from each node to each node in the map
    int grid[ROWSIZE][COLSIZE] = {
        {0, 10, 15, 20, 25},  // M -> (M, A, B, C, D)
        {10, 0, 35, 25, 30},  // A -> (M, A, B, C, D)
        {15, 35, 0, 30, 20},  // B -> (M, A, B, C, D)
        {20, 25, 30, 0, 15},  // C -> (M, A, B, C, D)
        {25, 30, 20, 15, 0}   // D -> (M, A, B, C, D)
    };

    bool visited[ROWSIZE];
    for (int i = 0; i < ROWSIZE; i++) visited[i] = false;

    visited[0] = true;  // Start from M
    fastestTrack(grid, visited, 0, 0, 0);

    cout << "The shortest travel time from M is: " << minTime << " minutes\n";
    cout << endl << endl;
}

//EXAMPLE 9 : QUEENS MOVE
const int ROWSIZEQ = 8, COLSIZEQ = 8;
void printGridQ(int grid[ROWSIZEQ][COLSIZEQ]) {
    for (int i = 0; i < ROWSIZEQ; ++i) {
        for (int j = 0; j < COLSIZEQ; ++j)
            cout << "\t" << grid[i][j];
        cout << endl;
    }
    cout << endl << endl;
}

bool isSolution(int grid[ROWSIZEQ][COLSIZEQ], int row, int col) {

    //check current column
    for (int i = 0; i < row; ++i)
        if (grid[i][col])
            return false;

    //check upper diagonal on left
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (grid[i][j])
            return false;
    }
    //check upper diagonal on right
    for (int i = row, j = col; i >= 0 && j < COLSIZEQ; --i, ++j) {
        if (grid[i][j])
            return false;
    }
    return true;
}

bool placeQueen(int grid[ROWSIZEQ][COLSIZEQ], int i, int& numSolutions) {

    if (i == 8) {
        cout << "Solution # "
            << (++numSolutions) << endl;

        printGridQ(grid);
        cout << "\n";
        return true;
    }

    bool success = false;

    for (int j = 0; j < COLSIZEQ; ++j) {
        if (isSolution(grid, i, j)) {
            grid[i][j] = 1;
            success = placeQueen(grid, i + 1, numSolutions) || success;
            grid[i][j] = 0;   //backtrack
        }
    }
    return false;
}


void queensMovesWrap() {
    cout << "\n\n\n";
    //create 'blank' grid
    int grid[ROWSIZEQ][COLSIZEQ]{ 0 };

    int numSolutions = 0;
    if (placeQueen(grid, 0, numSolutions))
        cout << "Found solution\n\n";

    cout << "ENDING QUEENS MOVES\n\n";
}