#include <vector>
#include <algorithm>
using namespace std;

bool canFinish(vector<int>& jobs, vector<int>& workers, int idx, int limit) {
    if (idx == jobs.size()) return true;
    for (int i = 0; i < workers.size(); i++) {
        if (workers[i] + jobs[idx] <= limit) {
            workers[i] += jobs[idx];
            if (canFinish(jobs, workers, idx + 1, limit)) return true;
            workers[i] -= jobs[idx];
        }
        if (workers[i] == 0) break;
    }
    return false;
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    sort(jobs.rbegin(), jobs.rend());
    int left = jobs[0], right = accumulate(jobs.begin(), jobs.end(), 0);
    while (left < right) {
        int mid = left + (right - left) / 2;
        vector<int> workers(k, 0);
        if (canFinish(jobs, workers, 0, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
