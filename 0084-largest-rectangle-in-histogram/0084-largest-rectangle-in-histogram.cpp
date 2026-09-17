class Solution {
public:
    vector<int> getNSE( vector<int>& heights , int n ) {

        stack<int> st ;
        vector<int> NSE(n,0) ;

        for ( int i = n-1 ; i >= 0 ; i-- ) {

            while( !st.empty() && heights[st.top()] >=  heights[i] ) st.pop() ;

            if ( st.empty() ) NSE[i] = n ;

            else NSE[i] = st.top() ;

            st.push(i) ;

        }

        return NSE ;

    }

        vector<int> getPSE( vector<int>& heights , int n ) {

        stack<int> st ;
        vector<int> PSE(n,0) ;

        for ( int i = 0 ; i < n ; i++ ) {

            while( !st.empty() && heights[st.top()] >=  heights[i] ) st.pop() ;

            if ( st.empty() ) PSE[i] = -1 ;

            else PSE[i] = st.top() ;

            st.push(i) ;

        }

        return PSE ;

    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size() ;
        
        // NSE --> next smaller element
        // PSE --> previous smaller element
        vector<int> NSE = getNSE(heights,n) ;
        vector<int> PSE = getPSE(heights,n) ;

        int maxi = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            // area of rectangle = L X B or width * height
            int length = NSE[i] - PSE[i] - 1 ;
            int area = length * heights[i] ;
            
            maxi = max( maxi , area ) ;

        }

        return maxi ;

        // getNSE()
        // for loop → O(n)
        // while → O(n) amortized (each element pushed/popped once)
        // Vector + stack space → O(2n)
        // T.C = O(2n), S.C = O(2n)

        // getPSE()
        // Same logic
        // T.C = O(2n), S.C = O(2n)

        // largestRectangleArea()
        // getNSE() → O(2n)
        // getPSE() → O(2n)
        // Final for loop → O(n)

        // So:

        // T.C = O(2n) + O(2n) + O(2n) = O(5n)
        // S.C = O(n)

        // Final: Time = O(5n), Space = O(3n).
        
    }
};