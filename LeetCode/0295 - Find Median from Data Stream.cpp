class MedianFinder {
public:

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    MedianFinder() { }
    
    void addNum(int num) {
        max_pq.push(num);
        
        if(max_pq.size() - min_pq.size() > 1){
            int x = max_pq.top(); 
            max_pq.pop();
            min_pq.push(x);
        }

        if(!min_pq.empty() && min_pq.top() < max_pq.top()){
            int x = max_pq.top(); max_pq.pop();
            int y = min_pq.top(); min_pq.pop();
            min_pq.push(x);
            max_pq.push(y);
        }
    }
    
    double findMedian() {
        
        int maxs = max_pq.size();
        int mins = min_pq.size();
    
        if( (maxs + mins)%2 ==0 )
            return (double)(max_pq.top() + min_pq.top())/2.0;
        
        return max_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */