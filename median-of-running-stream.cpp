#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

void median(vector<int> v ){

    priority_queue<int , vector<int>> maxHeap ;
    priority_queue<int , vector<int> , greater<int>> minHeap;
    float med ;

    for(int i = 0 ; i < v.size() ; i++){

        if(maxHeap.empty()){
            maxHeap.push(v[i]);
        }
        else if(v[i] < maxHeap.top()){
            maxHeap.push(v[i]);
        }
        else{
            minHeap.push(v[i]);
        }

        if(maxHeap.size() == minHeap.size()){
            med = static_cast<float>((maxHeap.top() + minHeap.top())) / 2;
        }
        else if(abs(maxHeap.size() - minHeap.size()) == 1){
            med = (maxHeap.size() > minHeap.size()) ? maxHeap.top() : minHeap.top() ;
        }
        else{

            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else{
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            med = static_cast<float>((maxHeap.top() + minHeap.top())) / 2;
            
        }

        cout << med << " ";

    }

}

int main(){ 

    vector<int> v = {3,8,2,1,6};

    median(v);

}