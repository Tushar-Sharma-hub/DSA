// 295. Find Median from Data Stream

//Hint-two heaps ek left and right , left vaale mai right se chote elements maintain krenge and last mai maintain krne ke baad 
//agr size equal hue toh mtlb top ka avg nikalke median mil jayga , or agr size ni hua equal toh mtlb jayda size jiska h uska top ans hoga.
// Ab maintain kaise krta h voo addNum fxn mai h.
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    void addNum(int num) {
        if(left.size()==0 || num<left.top()) left.push(num);
        else right.push(num);
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }
        if(right.size()>left.size()+1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()) return (left.top()+right.top())/2.0;
        if(left.size()>right.size()) return left.top();
        return right.top();
    }
};