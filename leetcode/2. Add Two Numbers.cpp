#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *result;
    ListNode *result_tail;

    void append(int num) {
        result_tail->next = new ListNode(num);
        result_tail = result_tail->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *first = l1;
        ListNode *second = l2;
        result = new ListNode(0);
        result_tail = result;

        while (first != nullptr || second != nullptr) {
            int sum = 0;
            if (first) {
                sum += first->val;
            }
            if (second) {
                sum += second->val;
            }

            append(sum % 10);

            if (sum >= 10) {
                if (first && first->next) {
                    first->next->val += 1;
                } else if (second && second->next) {
                    second->next->val += 1;
                } else {
                    append(1);
                }
            }

            if (first != nullptr) {
                first = first->next;
            }

            if (second) {
                second = second->next;
            }
        }

        return result->next;
    }
};

int main() {
}