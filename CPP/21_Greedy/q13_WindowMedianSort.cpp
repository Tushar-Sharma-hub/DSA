// 480. Sliding Window Median
// The median is the middle value in an ordered integer list. If the size of the list is even, 
// there is no middle value. So the median is the mean of the two middle values.
// For examples, if arr = [2,3,4], the median is 3.
// For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
// You are given an integer array nums and an integer k. 
// There is a sliding window of size k which is moving from the very left of the array to the very right.
// You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the median array for each window in the original array.
// Answers within 10-5 of the actual value will be accepted.

/*
INTUITION
----------

We use 2 heaps:

1. maxHeap (left half)
   -> stores smaller elements
   -> top = largest among smaller half

2. minHeap (right half)
   -> stores larger elements
   -> top = smallest among larger half

We maintain:
---------------
minHeap size == maxHeap size
OR
minHeap has 1 extra element

Why?
Because then:
- odd window size  -> median = minHeap.top()
- even window size -> average of both tops


MAIN PROBLEM
------------

Priority Queue cannot remove random elements.

Suppose outgoing element is:
nums[i-k]

It may be buried inside heap.

Example:
maxHeap = [9,7,5,3]

Need to remove 5.
But priority_queue only allows removing TOP.

So we use:
LAZY DELETION


LAZY DELETION
--------------

Instead of removing immediately:
mp[x]++

Meaning:
"x is invalid now"

Whenever x reaches heap top later:
we remove it.

This is called PRUNING.


IMPORTANT
-----------

heap.size() becomes WRONG because heaps contain invalid elements too.

So we maintain:
smallSize -> valid elements in maxHeap
largeSize -> valid elements in minHeap


TIME COMPLEXITY
----------------

Insertion : O(log k)
Removal   : O(log k)
Median    : O(1)

Total     : O(n log k)

*/

class Solution {
public:

    // stores elements marked for deletion
    unordered_map<int,int> mp;

    // valid sizes only
    int smallSize = 0;
    int largeSize = 0;

    
    /*
    Removes invalid elements from maxHeap top
    */
    void pruneMax(priority_queue<int>& maxHeap){

        while(!maxHeap.empty() && mp[maxHeap.top()]){

            mp[maxHeap.top()]--;

            maxHeap.pop();
        }
    }

    
    /*
    Removes invalid elements from minHeap top
    */
    void pruneMin(priority_queue<int, vector<int>, greater<int>>& minHeap){

        while(!minHeap.empty() && mp[minHeap.top()]){

            mp[minHeap.top()]--;

            minHeap.pop();
        }
    }


    /*
    BALANCING RULE
    ----------------

    minHeap should contain:
    either equal elements
    OR
    one extra element

    */
    void balance(priority_queue<int>& maxHeap,
                 priority_queue<int, vector<int>, greater<int>>& minHeap){

        // too many elements in left side
        if(smallSize > largeSize){

            minHeap.push(maxHeap.top());
            maxHeap.pop();

            smallSize--;
            largeSize++;

            pruneMax(maxHeap);
        }

        // too many elements in right side
        else if(largeSize > smallSize + 1){

            maxHeap.push(minHeap.top());
            minHeap.pop();

            largeSize--;
            smallSize++;

            pruneMin(minHeap);
        }
    }


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        priority_queue<int> maxHeap;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        vector<double> ans;

        double median;


        /*
        STARTING
        ----------
        Put first element in minHeap
        */
        minHeap.push(nums[0]);

        largeSize++;

        median = nums[0];


        /*
        BUILD FIRST WINDOW
        */
        for(int i=1;i<k;i++){

            // insert into correct heap
            if(nums[i] >= median){

                minHeap.push(nums[i]);

                largeSize++;
            }
            else{

                maxHeap.push(nums[i]);

                smallSize++;
            }

            balance(maxHeap,minHeap);

            // calculate median
            if(smallSize == largeSize){

                median =
                ((double)maxHeap.top() + minHeap.top()) / 2.0;
            }
            else{

                median = (double)minHeap.top();
            }
        }

        ans.push_back(median);


        /*
        SLIDING WINDOW
        */
        int i=1;
        int j=k;

        while(j < nums.size()){


            /*
            STEP 1:
            INSERT NEW ELEMENT
            */
            if(nums[j] >= median){

                minHeap.push(nums[j]);

                largeSize++;
            }
            else{

                maxHeap.push(nums[j]);

                smallSize++;
            }



            /*
            STEP 2:
            REMOVE OUTGOING ELEMENT
            USING LAZY DELETION
            */
            int out = nums[i-1];

            mp[out]++;


            /*
            Decide which heap logically lost one valid element
            */
            if(out >= median){

                largeSize--;

                // if outgoing element is already at top
                // remove immediately
                if(out == minHeap.top()){

                    pruneMin(minHeap);
                }
            }
            else{

                smallSize--;

                if(!maxHeap.empty() && out == maxHeap.top()){

                    pruneMax(maxHeap);
                }
            }



            /*
            STEP 3:
            REBALANCE HEAPS
            */
            balance(maxHeap,minHeap);



            /*
            Extra pruning safety
            */
            pruneMax(maxHeap);

            pruneMin(minHeap);



            /*
            STEP 4:
            FIND MEDIAN
            */
            if(smallSize == largeSize){

                median =
                ((double)maxHeap.top() + minHeap.top()) / 2.0;
            }
            else{

                median = (double)minHeap.top();
            }

            ans.push_back(median);

            i++;
            j++;
        }

        return ans;
    }
};