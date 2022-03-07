#include "Priority_queue.h"
#include <exception>
#include <iostream>

using namespace std;

Priority_queue::Priority_queue() {}

bool Priority_queue::is_empty() {
    if (FirstItem == nullptr) {
        return true;
    }
    return false;
}

int Priority_queue::GetSizeLow() const {
    return SizeLow;
}

int Priority_queue::GetSizeMedium() const {
    return SizeMedium;
}

int Priority_queue::GetSizeHigh() const {
    return SizeHigh;
}

int Priority_queue::GetSize() const {
    return SizeLow + SizeMedium + SizeHigh;
}

void Priority_queue::push(int num, string priority) {
    if (priority == "High") {
        Queue_item* element = new Queue_item(num, priority);
        SizeHigh++;
        if (is_empty()) {
            FirstItem = element;
            LastItemHigh = element;
            return;
        }
        if (LastItemHigh == nullptr) {
            element->next = FirstItem;
            FirstItem = element;
            LastItemHigh = element;
            return;
        }
        element->next = LastItemHigh->next;
        LastItemHigh->next = element;
        LastItemHigh = element;
    }
    else if (priority == "Medium") {
        Queue_item* element = new Queue_item(num, priority);
        SizeMedium++;
        if (is_empty()) {
            FirstItem = element;
            LastItemMedium = element;
            return;
        }
        if (LastItemHigh == nullptr && LastItemMedium == nullptr) {
            element->next = FirstItem;
            FirstItem = element;
            LastItemMedium = element;
            return;
        }
        if (LastItemMedium == nullptr) {
            element->next = LastItemHigh->next;
            LastItemHigh->next = element;
            LastItemMedium = element;
            return;
        }
        element->next = LastItemMedium->next;
        LastItemMedium->next = element;
        LastItemMedium = element;
    }
    else if (priority == "Low") {
        Queue_item* element = new Queue_item(num, priority);
        SizeLow++;
        if (is_empty()) {
            FirstItem = element;
            LastItemLow = element;
            return;
        }
        if (LastItemMedium == nullptr && LastItemLow == nullptr) {
            LastItemHigh->next = element;
            LastItemLow = element;
            return;
        }
        if (LastItemLow == nullptr && LastItemHigh == nullptr) {
            LastItemMedium->next = element;
            LastItemLow = element;
            return;
        }
        if (LastItemLow == nullptr) {
            LastItemMedium->next = element;
            LastItemLow = element;
            return;
        }
        LastItemLow->next = element;
        LastItemLow = element;
    }
    else
        throw exception("incoreect priority");
}

void Priority_queue::Print() {
    Queue_item* el = FirstItem;
    cout << "Queue:";
    while (el != nullptr) {
        cout << ' ' << el->value;
        el = el->next;
    }
}

void Priority_queue::pop() {
    if (FirstItem == nullptr) {
        return;
    }
    Queue_item* el = FirstItem->next;
    if (FirstItem->priority == "High")
        SizeHigh--;
    if (FirstItem->priority == "Medium")
        SizeMedium--;
    if (FirstItem->priority == "Low")
        SizeLow--;
    if (SizeHigh == 0)
        LastItemHigh = nullptr;
    if (SizeMedium == 0)
        LastItemMedium = nullptr;
    if (SizeLow == 0)
        LastItemLow = nullptr;
    delete FirstItem;
    FirstItem = el;
}

void Priority_queue::operator=(Priority_queue& pq) {
    Queue_item* el = pq.FirstItem;
    Priority_queue out;
    if (this == &pq) {
        return;
    }

    while (FirstItem != nullptr) {
        pop();
    }
    while (el != nullptr) {
        push(el->value, el->priority);
        el = el->next;
    }
}

void Priority_queue::operator=(Priority_queue&& pq) noexcept {
    Priority_queue out;
    if (this == &pq) {
        return;
    }

    while (FirstItem != nullptr) {
        pop();
    }

    FirstItem = pq.FirstItem;
    LastItemHigh = pq.LastItemHigh;
    LastItemMedium = pq.LastItemMedium;
    LastItemLow = pq.LastItemLow;
    SizeHigh = pq.SizeHigh;
    SizeMedium = pq.SizeMedium;
    SizeLow = pq.SizeLow;

    pq.FirstItem = nullptr;
    pq.LastItemHigh = nullptr;
    pq.LastItemMedium = nullptr;
    pq.LastItemLow = nullptr;
    pq.SizeHigh = 0;
    pq.SizeMedium = 0;
    pq.SizeLow = 0;
}

void Priority_queue::InfFirst() {
    if (FirstItem == nullptr) {
        std::cout << "queue is empty";
        return;
    }
    std::cout << "first element: " << FirstItem->value << " Priority: " << FirstItem->priority << endl;
}

Priority_queue::Priority_queue(Priority_queue& pq) {
    if (this == &pq) {
        return;
    }

    while (FirstItem != nullptr) {
        pop();
    }

    Queue_item* el = pq.FirstItem;

    while (el != nullptr) {
        push(el->value, el->priority);
        el = el->next;
    }
}

