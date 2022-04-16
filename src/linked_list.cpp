#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ <=  1){
      return;
    }
    Node* current = front_;
    Node* previous  = nullptr;
    while (current != back_) {
      Node* temp = current -> next;
      current -> next = previous;
      previous = current;
      current = temp;
    }
    Node* temp = back_;
    current -> next = previous;
    back_ = front_;
    front_ = temp;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    Node* frontNode = front_;
    front_ = back_;
    back_ = frontNode;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr) {
      return;
    }
    reverse_recursive_helper(curr -> next, curr);
    curr -> next = prev;
  }
}
