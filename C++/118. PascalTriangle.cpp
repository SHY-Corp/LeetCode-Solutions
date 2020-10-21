// Pascal's Triangle 
/*
    Pascal’s triangle is an array of binomial coefficients. The top row is numbered as n=0, 
    and in each row are numbered from the left beginning with k = 0. 
    Each number is found by adding two numbers which are residing in the previous row and exactly top of the current cell. 
    It is also being formed by finding (𝑛𝑘) for row number n and column number k.
*/

#include<iostream>
using namespace std;
 
// Function to print the Pascal's Triangle
void print_pascal(int row_num){
 
    // Loop to print each row
    for(int n = 1; n <= row_num; n++){
 
        for(int r = 1; r < row_num-n+1; r++)
            cout<<"  ";
 
        int val = 1;
        for(int r = 1; r <= n; r++){
            cout<<val<<"   ";
             
            val = val * (n - r)/r;
        }
        cout<<endl;
    }
}
 
int main(){
    
    // Number of rows for Pascal's Triangle
    int row_num ;
    cout << "Enter Number of Rows: ";
    cin >> row_num ;
 
    //Function call to print Pascal's Triangle
    print_pascal(row_num);
 
    return 1;
}