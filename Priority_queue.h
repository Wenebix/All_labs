#pragma once

#include <string>

using namespace std;

class Priority_queue {
public:
    Priority_queue();

    Priority_queue(Priority_queue& pq);

    Priority_queue(Priority_queue&& pq) noexcept :
        FirstItem(std::move(pq.FirstItem)), LastItemHigh(std::move(pq.LastItemHigh)),
        LastItemMedium(std::move(pq.LastItemMedium)), LastItemLow(std::move(pq.LastItemLow)),
        SizeHigh(std::move(pq.SizeHigh)), SizeMedium(std::move(pq.SizeMedium)),
        SizeLow(std::move(pq.SizeLow)) {
        pq.FirstItem = nullptr;
        pq.LastItemHigh = nullptr;
        pq.LastItemMedium = nullptr;
        pq.LastItemLow = nullptr;
        pq.SizeHigh = 0;
        pq.SizeMedium = 0;
        pq.SizeLow = 0;
    };

    void operator=(Priority_queue&);

    void operator=(Priority_queue&&) noexcept;

    bool is_empty();

    void push(int, string);

    void pop();

    void InfFirst();

    int GetSizeLow() const;

    int GetSizeMedium() const;

    int GetSizeHigh() const;

    int GetSize() const;

    void Print();

private:
    struct Queue_item {
        int value;
        string priority;
        Queue_item* next;

        Queue_item(int number, string prior)
            : value(number), priority(prior), next(nullptr) {};
    };

    Queue_item* FirstItem = nullptr;
    Queue_item* LastItemHigh = nullptr;
    Queue_item* LastItemMedium = nullptr;
    Queue_item* LastItemLow = nullptr;
    int SizeHigh = 0;
    int SizeMedium = 0;
    int SizeLow = 0;
};

