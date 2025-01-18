//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkBit( int pattern, vector<int> arr, int n ){
        int count = 0;
        for( int i = 0; i < n; i++ ){
            if( (arr[i] & pattern) == pattern ) count++;
        }
        return count;
    }
    
    int findMaxAnd( vector<int>& arr ){
        int n = arr.size();
        int answer = 0;
        for( int bit = 32; bit >= 0; bit-- ){
            int power = pow(2, bit);
            int pattern = answer | power;
            int count = checkBit( pattern, arr, n);
            
            if( count >= 2 )    answer |= (1 << bit);
        }
        return answer;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);
        Solution ob;
        cout << ob.findMaxAnd(arr) << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends