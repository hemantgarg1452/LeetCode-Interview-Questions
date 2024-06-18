class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        priority_queue<pair<int, int>>pq;
        for(int i=0; i<n; i++){
            int diff = difficulty[i];
            int pro = profit[i];

            pq.push({pro, diff});
        }

        sort(worker.begin(), worker.end(), greater<int>());

        int i=0;
        int totalProfit=0;
        while(i<m && !pq.empty()){
            if(pq.top().second > worker[i]){ 
                pq.pop();
            }
            else{ 
            totalProfit += pq.top().first;
            i++;
            }
        }
        return totalProfit;
    }
};