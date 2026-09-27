class MedianFinder {
public:
    priority_queue<int>smallHeap;//max heap
    priority_queue<int, vector<int>, greater<int>>largeHeap;//min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (smallHeap.empty() || num <= smallHeap.top()) {
            smallHeap.push(num);
        } else {
            largeHeap.push(num);
        }
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        else if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        if(smallHeap.size()!=largeHeap.size()){
            return smallHeap.size()>largeHeap.size()?smallHeap.top():largeHeap.top();
        }
        int x = smallHeap.top(), y = largeHeap.top();
        return (double)(x+y)/2.0;
    }
};
