// Problem Link : https://leetcode.com/problems/132-pattern/submissions/?envType=daily-question&envId=2023-09-30

// INTUITION: here nums3 is basically nums[k], we know that nums[k] should be 
// greater thatn nums [i] and smaller than nums[j]. SO we will try to keep the value
// of nums3 as large as possible but also smaller than nums[j], so
// that there is high chance that nums[i], will definetly be smaller than both.
// Therfore in stack, whenever I am getting a value greater than top element of stack
// i pop the element from stack and keep it in nums3, because 
// top element is always nums[j] , and the poped element is nums[k],
// which we are keep on updating.

// Here we are starting from last so that we can satiy the conditon
// of nums[i] <nums[k] < nums[j] && i < j< k.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=  nums.size();

        int nums3 = INT_MIN;
        stack<int> st;
         for(int i= n-1 ; i>= 0 ;  i--)
         {  
             if(!st.empty() && nums[i] < st.top() && nums[i] < nums3)
             {
                 return true;
             }
            while(!st.empty() && nums[i] > st.top() )
            {
                int val = st.top();
                st.pop();
                nums3 = val;
            }
            if(st.empty() || nums[i] > nums3)
            st.push(nums[i]);
         }

         return false;
    }
};