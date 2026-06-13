#include <bits/stdc++.h>
using namespace std;

int getNumberTransmittedLogs(
    vector<int>& logTimestamp,
    vector<string>& logTag,
    int bufferCapacity,
    int transmissionWindow
) {
    int n = logTimestamp.size();

    long long transmitted = 0;

    queue<pair<int,string>> buffer;

    unordered_map<string, deque<int>> mp;

    for(int i = 0; i < n; i++) {

        int t = logTimestamp[i];
        string tag = logTag[i];

        while(!mp[tag].empty() &&
              t - mp[tag].front() > transmissionWindow) {
            mp[tag].pop_front();
        }

        transmitted += mp[tag].size() + 1;

        buffer.push({t, tag});
        mp[tag].push_back(t);

        if(buffer.size() > bufferCapacity) {

            auto oldest = buffer.front();
            buffer.pop();

            string oldTag = oldest.second;
            int oldTime = oldest.first;

            if(!mp[oldTag].empty() &&
               mp[oldTag].front() == oldTime) {

                mp[oldTag].pop_front();
            }
        }
    }

    return (int)transmitted;
}
