class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if (k > q.size())
            return q;
        stack<int> temp;
        for (int i = 0; i < k; i++) {
            temp.push(q.front());
            q.pop();
        }
        while (!temp.empty()) {
            q.push(temp.top());
            temp.pop();
        }
        int remaining = q.size() - k;
        for (int i = 0; i < remaining; i++) {
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize queue with n friends
        queue<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push(i);
        }

        // Perform eliminations while more than 1 player remains
        while (circle.size() > 1) {
            // Process the first k-1 friends without eliminating them
            for (int i = 0; i < k - 1; i++) {
                circle.push(circle.front());
                circle.pop();
            }
            // Eliminate the k-th friend
            circle.pop();
        }

        return circle.front();
    }
};