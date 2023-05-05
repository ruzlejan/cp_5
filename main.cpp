#include <iostream>
#include "MaxHeap.h"
#include "Node.h"
#include "pr_check.h"
#include "sch_check.h"

using namespace std;

int main(){
    // MaxHeap* heapobj = new MaxHeap("CS_310");


    // heapobj->add("B00968771","CS_310",10);
    // heapobj->add("B00963211","CS_310",20);
    // heapobj->add("B04218771","CS_310",50);
    // heapobj->add("1234567","CS_310",7);
    // heapobj->add("B05218771","CS_310",30);
    // heapobj->add("B05318771","CS_310",100);

    // heapobj->printHeap();
    // heapobj->promote("1234567",500);
    // heapobj->enroll();
    // heapobj->printHeap();

//     pr_check* prcheckObj =  new pr_check();
//    string result = prcheckObj->pr_reader();
// cout<< result << endl;

    sch_check* schCheckObj = new sch_check();
    string result2 = schCheckObj->sch_reader();
    cout << result2 << endl;
    return 0;


}