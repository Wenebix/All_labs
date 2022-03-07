#include <iostream>
#include "Priority_queue.h"

int main() {
    Priority_queue pq;
    pq.push(2, "Medium");
    pq.push(3, "Medium");
    pq.push(4, "Medium");
    pq.push(8, "Low");
    pq.push(1, "High");
    pq.push(5, "Medium");
    pq.push(6, "Medium");
    pq.push(7, "Medium");
    pq.Print();
    std::cout << endl;
    Priority_queue pq2(pq);
    pq2.Print();
    std::cout << endl;
    pq2.pop();
    pq2.pop();
    pq2.pop();
    pq2.InfFirst();
    std::cout << endl;
    pq2.Print();
    std::cout << endl;
    std::cout << "Size of high: " << pq.GetSizeHigh() << '\n'
        << "Size of medium: " << pq.GetSizeMedium() << '\n'
        << "Size of low: " << pq.GetSizeLow() << '\n'
        << "Size of all queue: " << pq.GetSize() << '\n';
    pq2 = pq;
    pq2.Print();
    std::cout << endl;
    while (pq2.GetSize() > 0) {
        pq2.pop();
    }
    pq2.Print();
    pq2.pop();

    return 0;
}
