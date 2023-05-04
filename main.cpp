#include <iostream>
#include "MaxHeap.h"
#include "Node.h"

using namespace std;

int main(){
    MaxHeap* heapobj = new MaxHeap("CS_310");


    heapobj->add("B00968771","CS_310",10);
    heapobj->add("B00963211","CS_310",20);
    heapobj->add("B04218771","CS_310",50);
    heapobj->add("1234567","CS_310",7);
    heapobj->add("B05218771","CS_310",30);
    heapobj->add("B05318771","CS_310",100);

    heapobj->printHeap();

    heapobj->promote("1234567",500);

    heapobj->enroll();

    heapobj->printHeap();

    return 0;


}