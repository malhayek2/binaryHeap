/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <algorithm> 
#include <bits/stdc++.h> 
using namespace std;
using namespace std::chrono; 
//268435456
const int MAX_N = 270000000;


//std::vector<int> dist;
std::vector<int> heap;
std::vector<int> xposa;

// int level[SIZE];
int dist[MAX_N];

bool runtimemeasure = false;


int heapsize;

void decreasekey(int x);
void insert(int x);
int deletemin();
void makeheap(int n);
int key(int i);
void shiftdown(int x, int i);
void bubbleup(int x, int i);
int minchild(int i);



// x position

// get key
int key(int i)
{
    return dist[i];
}

void insert(int x)
{

    heapsize += 1;
    // x postion is 
    
    xposa[x] = heapsize - 1;
    bubbleup(x, heapsize - 1);
}


void decreasekey(int x)
{
    bubbleup(x, xposa[x]);
}


int deletemin()
{
    int x = -1;
    if( heapsize != 0){
        x = heap[0];
        //heap[0] = heap[heapsize - 1];
        xposa[(heap[heapsize - 1])] = 0;
        --heapsize;
        shiftdown(heap[heapsize - 1], 0);
    }
    return x;
}
void makeheap(int n)
{
    heapsize = n;
    for (int i = 0; i < n; ++i){
        //heap[i] = i;
        heap.push_back(i);
        //xpos(i) = i;
        xposa.push_back(i);
    }

    for (int i = n -1; i > -1; --i){
        shiftdown(heap[i],i);
    }
}
//element x , pos i
void bubbleup(int x, int i)
{
    int p = (i - 1)/2;
    while (i != 0 && key(heap[p]) > key(x)){
        heap[i] = heap[p];
        xposa[(heap[p])] = i;
        i = p;
        p = (i -1)/2;
    }
    heap[i] = x;
    //keep track
    xposa[x] = i;
}

void shiftdown(int x, int i)
{
    int c = minchild(i);
    while (c != -1 && key(heap[c]) < key(x)) {
        heap[i] = heap[c];
        xposa[heap[c]] = i;
        i = c;
        c = minchild(i);
    }
    heap[i] = x;
    xposa[x] = i;
}

int minchild(int i)
{
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if ( leftchild > heapsize -1 )
        return -1;
    else if ( rightchild > heapsize -1) {
        return leftchild;
    } else {
        return key(heap[leftchild]) < key(heap[rightchild]) ? leftchild : rightchild;
    }
}

void printheap(){
    for (int i = 0; i < heapsize; i++){
        std::cout << heap[i] << std::endl;
    }
    
}
void testheap()
{
    makeheap(10);
    insert(12);
    insert(10);
    decreasekey(5);
    for(int i = 0; i < 3; i++){
    std::cout << "deletemin " << "i " << i << " " << deletemin() << std::endl;    
    }
    
    
    std::cout << "minchild" << minchild(3) << std::endl;
}

void measure(int heapsize){
    //runtimemeasure = true;
    std::ofstream myfile;
    myfile.open ("output.csv", std::ios_base::app);

    clock_t start_makeheap, end_makeheap, start_insert, end_insert, start_decreseKey, end_decreseKey,
    start_deletemin, end_deletemin;
    // start_bubbleup, end_bubbleup,start_siftdown, end_siftdown, start_minchild, end_minchild; 
    //myfile << "heapsize" << "," << "makeheap()" << "," << "determin()" << "," << "insert()" << "," << ;
    myfile << heapsize << ",";
    //std::cout << "makeheap " << std::endl;
    start_makeheap = clock(); 
    makeheap(heapsize);
    end_makeheap = clock();
    double time_taken_makeheap = double(end_makeheap - start_makeheap) / double(CLOCKS_PER_SEC) ; 
    //std::cout << "makeheap() " << fixed << time_taken_makeheap << setprecision(6) << " seconds" << std::endl;
    myfile  << fixed << time_taken_makeheap << setprecision(6) << ",";
    
    start_deletemin = clock(); 
    deletemin();
    end_deletemin = clock();
    double time_taken_deletemin = double(end_deletemin - start_deletemin) / double(CLOCKS_PER_SEC) ; 
    //std::cout << "deletemin() " << fixed << time_taken_deletemin << setprecision(6) << " seconds" << std::endl;
    myfile  << fixed << time_taken_deletemin << setprecision(6) << ",";
    
    start_insert = clock(); 
    insert(heapsize+1);
    end_insert = clock();
    double time_taken_insert = double(end_insert - start_insert) / double(CLOCKS_PER_SEC) ; 
    //std::cout << "insert() " << fixed << time_taken_insert << setprecision(6) << " seconds" << std::endl;
    myfile  << fixed << time_taken_insert << setprecision(6) << ",";
    
    start_decreseKey = clock(); 
    decreasekey(heapsize/2);
    end_decreseKey = clock();
    double time_taken_decreseKey = double(end_decreseKey - start_decreseKey) / double(CLOCKS_PER_SEC) ; 
    //std::cout << "decreseKey() " << fixed << time_taken_decreseKey << setprecision(6) << " seconds" << std::endl;
    myfile  << fixed << time_taken_decreseKey << setprecision(6) << "\n";

    myfile.close();
    // start_bubbleup = clock(); 
    // bubbleup(heapsize/2, heapsize-1);
    // end_bubbleup = clock();
    // double time_taken_bubbleup = double(end_bubbleup - start_bubbleup) / double(CLOCKS_PER_SEC) ; 
    // std::cout << "bubbleup() " << fixed << time_taken_bubbleup << setprecision(6) << " seconds" << std::endl;

    // start_siftdown = clock(); 
    // shiftdown(heapsize/2, 1);
    // end_siftdown = clock();
    // double time_taken_siftdown = double(end_siftdown - start_siftdown) / double(CLOCKS_PER_SEC) ; 
    // std::cout << "siftdown() " << fixed << time_taken_siftdown << setprecision(6) << " seconds" << std::endl;

    // start_minchild = clock(); 
    // minchild(heapsize/2);
    // end_minchild = clock();
    // double time_taken_minchild = double(end_minchild - start_minchild) / double(CLOCKS_PER_SEC) ; 
    // std::cout << "minchild() " << fixed << time_taken_minchild << setprecision(6) << " seconds" << std::endl;


}
int main(int argc, char **argv)
{
    // testheap();
    // printheap();
    std::string arg(argv[1]);
    std::stringstream ss(arg);
    int size;
    ss >> size;
    std::cout << "size " << size << std::endl;

    measure(size);



    return 0;
}
