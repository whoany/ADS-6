// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T value;
    Node* next;
  };
  Node* head;

 public:
  TPQueue() : head(nullptr) {}
 
  ~TPQueue() {
    while (head != nullptr) {
      Node* tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void push(const T& item) {
    Node* newNode = new Node{item, nullptr};

    if (head == nullptr || item.prior > head->value.prior) {
      newNode->next = head;
      head = newNode;
      return;
    }

    Node* cur = head;
    while (cur->next != nullptr && cur->next->value.prior >= item.prior) {
      cur = cur->next;
    }
    newNode->next = cur->next;
    cur->next = newNode;
  }

  T pop() {
    T value = head->value;
    Node* tmp = head;
    head = head->next;
    delete tmp;
    return value;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
