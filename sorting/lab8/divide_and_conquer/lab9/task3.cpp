class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < n - 1; i++) {
                if (cost[i] > cost[i + 1]) {
                    swap(cost[i], cost[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped);
        int minCost = 0;
        for(int i = n - 1; i >= 0; i -= 3){
            minCost += cost[i];
            if(i >= 1){
                minCost += cost[i-1];
            }
        }
        return minCost;
    }
};
