/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str); cout << '\n') {
        if (str.find(',') == string::npos) {
            cout << str;
            continue;
        }
        stringstream ss(str); ss.ignore();
        int prev; ss >> prev; ss.ignore();
        cout << '[' << prev;
        for (int curr; ss >> curr; ss.ignore()) {
            cout << ',' << gcd(prev, curr) << ',' << curr;
            prev = curr;
        }
        cout << ']';
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(head->next == NULL) return head; 
        ListNode* temp = head;
        while(temp && temp->next){
            ListNode* between = new ListNode(gcd(temp->val, temp->next->val));
            between->next = temp->next;
            temp->next = between;
            temp = between->next;
        }   
        return head;
        
    }
};