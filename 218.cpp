#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Create a vector of events: (x-coordinate, height, type)
        vector<pair<int, pair<int, int>>> events;
        
        for (auto& building : buildings) {
            events.push_back({building[0], {building[2], 1}}); // Start event: (x, height, start)
            events.push_back({building[1], {building[2], -1}}); // End event: (x, height, end)
        }

        // Sort the events:
        // 1. First by x-coordinate
        // 2. If two events have the same x, prioritize end event (-1) before start event (+1)
        // 3. If both are start events, sort by descending height
        // 4. If both are end events, sort by ascending height
        sort(events.begin(), events.end(), [](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            if (a.first != b.first) return a.first < b.first;
            if (a.second.second != b.second.second) return a.second.second > b.second.second;
            return a.second.first > b.second.first;
        });
        
        vector<vector<int>> result;
        priority_queue<int> maxHeap; // Max heap to track the heights
        maxHeap.push(0); // The ground level (height 0)
        int prevMaxHeight = 0;

        // Process each event
        for (auto& event : events) {
            int x = event.first;
            int height = event.second.first;
            int type = event.second.second;
            
            // If it's a start event, add the building's height to the heap
            if (type == 1) {
                maxHeap.push(height);
            } else {
                // If it's an end event, remove the building's height from the heap
                // We can use a lazy removal approach
                vector<int> temp;
                while (maxHeap.top() != height) {
                    temp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
                maxHeap.pop();
                for (int h : temp) {
                    maxHeap.push(h);
                }
            }

            // Get the current max height from the heap
            int currentMaxHeight = maxHeap.top();

            // If the max height changes, add a new key point
            if (currentMaxHeight != prevMaxHeight) {
                result.push_back({x, currentMaxHeight});
                prevMaxHeight = currentMaxHeight;
            }
        }

        return result;
    }
};
