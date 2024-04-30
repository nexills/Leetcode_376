class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // initialize iterators
        vector<int>::iterator itr = nums.begin();
        vector<int>::iterator next = itr + 1;
        bool increasing = false;
        // check for cases with only 1 entry or if initial entries have differences of zero
        if (next == nums.end()) return 1;
        while (*next - *itr == 0) {
            itr++;
            next++;
            if (next == nums.end()) return 1;
        }
        // calculate the number of alternating differences
        bool prev_increasing = (*next - *itr) > 0;
        int length = 2;
        itr++;
        next++;
        while (next != nums.end()) {
            int difference = *next - *itr;
            if (difference < 0) increasing = false;
            else if (difference > 0) increasing = true;
            if (increasing == !prev_increasing) {
                length++;
                prev_increasing = increasing;
            }
            itr++;
            next++;
        }
        return length;
    }
};
