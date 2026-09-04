class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int finalSum = 0;
        for(int i = 0; i<n; i++){
            if(grumpy[i] == 0) finalSum += customers[i]; 
        }

        // now we will find maximum sum in a window of minutes length
        int sum = 0;
        for(int i = 0; i<minutes; i++){
            if(grumpy[i] == 1) sum+= customers[i];
        }

        int maxi = sum;
        int l = 0;
        int r = minutes-1;
        while(r<n){
            if(grumpy[l] == 1){
                sum -= customers[l];
            }
            l++;
            r++;
            if(r<n && grumpy[r] == 1) sum += customers[r];
            maxi = max(maxi, sum);
        }

        return finalSum + maxi;


        

    }
};