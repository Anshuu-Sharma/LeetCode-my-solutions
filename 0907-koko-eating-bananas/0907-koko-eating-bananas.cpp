class Solution {
public:
    long long findHRS(vector<int> piles, int mid, int n){
        long long total = 0;
        for(int i = 0;i<n;i++){
            total = total + ceil((double)piles[i]/(double)mid);
        }
        return total;
    }
    int maxEl(vector<int> piles, int n){
        int maxi=piles[0];
        for(int i = 0;i<n;i++){
            if(maxi < piles[i]){
                maxi = piles[i];
            }
        }
        return maxi;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n = piles.size();
        int low = 1, high = maxEl(piles,n);
        int ans;
        while( low <= high ){
            int mid = ( low + high ) / 2;
           long long total = findHRS(piles, mid, n);
            if(total <= h){
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;
            }
      }
      return ans;



    }
};