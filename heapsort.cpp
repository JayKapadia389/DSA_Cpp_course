#include <iostream>
#include <vector>

using namespace std ;

void swap(vector<int> &heap , int i , int j ){

    heap[i] = heap[i] + heap[j] ;
    heap[j] = heap[i] - heap[j] ;
    heap[i] = heap[i] - heap[j] ;
}

void heapifyCore(vector<int> &heap ,int i){

    int l = 2*i +1;
    int r = 2*i +2;
    int largest = i ;

    if(l < heap.size() && heap[i] < heap[l]){
        largest = l ;
    }

    if(r < heap.size() && heap[largest] < heap[r]){
        largest = r ;
    }

    if(largest == i){
        return ;
    }
    else{
        swap(heap , largest , i);
        heapifyCore(heap , largest);
        return ;
    }
    
}

void heapify(vector<int> &heap ){

    int size = heap.size();

    for(int i = heap.size()-1 ; i >= 0 ; i--){
        heapifyCore(heap , i);
    }

    return ;
}

void heapsort(vector<int> heap){

    // swap f and l ele
    //cout l and pop
    //heapify i=0

    for(int i = 1 ; i < heap.size() ; i++){

        cout << heap[0] << " " ;

        swap(heap , 0 , heap.size()-1 );

        heap.pop_back();

        heapifyCore(heap , 0);

    } 

    cout << heap[0] ;

    return ;

}

int main(){

     vector<int> heap = {2,1,7,9,3,6,5,12};

     heapify(heap) ; 

     for(int i = 0 ; i < heap.size() ; i++){
        cout << heap[i] << " " ;
     }
     cout << endl ;

     heapsort(heap);
}