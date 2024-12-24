#include <vector>
#include <unordered_map>
using namespace std;

int maxHappyGroups(int batchSize, vector<int>& groups) {
    vector<int> count(batchSize, 0);
    int happyGroups = 0;

    for (int g : groups) {
        int mod = g % batchSize;
        if (mod == 0) {
            happyGroups++;
        } else if (count[batchSize - mod] > 0) {
            happyGroups++;
            count[batchSize - mod]--;
        } else {
            count[mod]++;
        }
    }

    return happyGroups + dfs(count, batchSize);
}

int dfs(vector<int>& count, int batchSize) {
    static unordered_map<string, int> memo;
    string key = to_string(count[0]);
    for (int i = 1; i < count.size(); i++) {
        key += "," + to_string(count[i]);
    }

    if (memo.count(key)) return memo[key];

    int result = 0;
    for (int i = 1; i < batchSize; i++) {
        if (count[i] > 0) {
            count[i]--;
            result = max(result, (i == 0 ? 1 : 0) + dfs(count, batchSize));
            count[i]++;
        }
    }

    return memo[key] = result;
}
