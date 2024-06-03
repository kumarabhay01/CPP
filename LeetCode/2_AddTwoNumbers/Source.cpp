#include<iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    void insertValue(ListNode** newList, int val) {
        ListNode* tempNode = new ListNode(val);
        if (*newList == nullptr)
            *newList = tempNode;
        else {
            ListNode* temp = *newList;
            while (temp->next)
                temp = temp->next;

            temp->next = tempNode;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* returnList = nullptr;
        if (l1 == nullptr && l2 == nullptr)
            return returnList;
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode* headl1 = l1;
        ListNode* headl2 = l2;
        int carry{}, digitSum{};

        while (headl1 != nullptr && headl2 != nullptr) {
            digitSum = headl1->val + headl2->val + carry;
            headl1 = headl1->next;
            headl2 = headl2->next;
            if (carry)
                carry--;
            if (digitSum < 10)
                insertValue(&returnList, digitSum);
            else {
                insertValue(&returnList, (digitSum%10));
                carry = digitSum / 10;
            }
        }

        if (headl1 == nullptr) {
            while (headl2 != nullptr) {
                digitSum = headl2->val + carry;
                headl2 = headl2->next;
                if (carry)
                    carry--;
                if (digitSum < 10)
                    insertValue(&returnList, digitSum);
                else {
                    insertValue(&returnList, (digitSum % 10));
                    carry = digitSum / 10;
                }
            }
        }

        if (headl2 == nullptr) {
            while (headl1 != nullptr) {
                digitSum = headl1->val + carry;
                headl1 = headl1->next;
                if (carry)
                    carry--;
                if (digitSum < 10)
                    insertValue(&returnList, digitSum);
                else {
                    insertValue(&returnList, (digitSum % 10));
                    carry = digitSum / 10;
                }
            }
        }

        if (carry)
            insertValue(&returnList, carry);

        return returnList;
    }

    ListNode* addTwoNumberscopy(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            int sum = digit1 + digit2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

int main() {
    return 0;
}
