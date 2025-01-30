class MedianFinder {
public:
    priority_queue<int> left; // Max heap (stores smaller half)
    priority_queue<int, vector<int>, greater<int>> right; // Min heap (stores larger half)
    bool even = true;

    MedianFinder() {}

    void addNum(int num) {
        if (even) 
        {
            left.push(num);
            right.push(left.top());
            left.pop();
        } else {
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        even = !even;
    }

    double findMedian() {
        if (even) {
            return (left.top() + right.top()) / 2.0; // Corrected median calculation
        } else {
            return right.top(); // Correct, as right has extra element
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */