class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        bool swapped;
        do {
            swapped = false;
            for (int i = 0; i < n - 1; i++) {
                if (citations[i] > citations[i + 1]) {
                    swap(citations[i], citations[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped);
        int tracker = 1;
        for(int i = n - 1; i >= 0; i--){
            if(citations[i] < tracker)
                break;
            tracker++;
        }
        return tracker - 1;
    }
};
