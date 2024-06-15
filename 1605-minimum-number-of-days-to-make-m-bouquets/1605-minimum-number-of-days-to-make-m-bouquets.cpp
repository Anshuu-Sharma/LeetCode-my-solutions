class Solution {
public:
bool possible(vector<int> arr, int day , int m , int k, int n){
        int cnt = 0;
        int boq = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            boq += cnt/k;
            cnt = 0;
        }
    }
    boq += cnt/k;
    if( boq >= m) return true;
    else return false;
}
int min(vector<int> arr, int n){
    int mini = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    return mini;
}

int max(vector<int> arr, int n){
    int max = arr[0];
    for(int i = 0;i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = min(bloomDay,n), high = max(bloomDay,n);
        int ans = -1;
        while(low <= high){
            int mid = (low+high) / 2;
            if(possible(bloomDay,mid, m ,k,n)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};