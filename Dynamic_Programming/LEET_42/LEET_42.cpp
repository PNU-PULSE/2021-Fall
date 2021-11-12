class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_maximum(height.size());
        
        for(int i = 1; i < height.size(); ++i) {
            left_maximum[i] = max(left_maximum[i - 1], height[i - 1]);
        }
        
        int water = 0;
        int right_maximum = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; --i) {
            water += max(min(left_maximum[i], right_maximum) - height[i], 0);
            
            right_maximum = max(right_maximum, height[i]);
        }
        
        return water;
    }
};