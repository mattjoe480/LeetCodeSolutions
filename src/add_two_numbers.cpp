class Solution {
   public: ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) {
      if (!l1 && !l2)
         return new ListNode {
            0,
            nullptr
         };
      ListNode * result_list = nullptr;
      ListNode * temp_list = nullptr;
      bool carry = false;

      while (l1 || l2 || carry) {

         if (!result_list || !result_list -> next)
            temp_list = new ListNode;
         else {
            temp_list -> next = new ListNode;
            temp_list = temp_list -> next;
         }
         //NOTE If there is carry logic 
         if (carry) {
            if (!l1 && !l2)
               temp_list -> val = 1;
            else if (!l1)
               temp_list -> val = l2 -> val + 1;
            else if (!l2)
               temp_list -> val = l1 -> val + 1;
            else
               temp_list -> val = (l1 -> val + l2 -> val) + 1;
            carry = false;
         } 

         else {
            if (!l1 && !l2)
               temp_list -> val = 0;
            else if (!l1)
               temp_list -> val = l2 -> val;
            else if (!l2)
               temp_list -> val = l1 -> val;
            else
               temp_list -> val = l1 -> val + l2 -> val;

         }


         if (temp_list -> val > 9) {
            carry = true;
            temp_list -> val = temp_list -> val - 10;
         }

         if (!result_list)
            result_list = temp_list;

         
         else if (!result_list -> next)
            result_list -> next = temp_list;

         if (l1)
            l1 = l1 -> next;
         else
            l1 = nullptr;
         if (l2)
            l2 = l2 -> next;
         else
            l2 = nullptr;

      }
      return result_list;
   }
};