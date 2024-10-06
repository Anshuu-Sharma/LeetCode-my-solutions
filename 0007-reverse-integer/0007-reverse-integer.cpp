class Solution {
public:
    int reverse(int x) {
        // Your implementation here
        long num =0;
        while(x !=0){
            num *=10;
            num += x%10;
            x = x/10;
        }
        if(num >= INT_MAX || num<=INT_MIN)
            return 0;
        
        return int(num);
    }
};