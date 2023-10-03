#include <algorithm> 
#include <iostream>

using namespace std;

int main() {
    int n;
    std::cin >> n;
    long long cost[10];
    for (int i = 0; i < n; ++i) {
    cin >> cost[i];
    }
    for (int i = n; i < 10; ++i) {
        cost[i] = 1e16;
    }
    long long max_num, money;
    cin >> money >> max_num;
    sort(begin(cost), end(cost));
    int i = 0, ans = 0;
    while (i < n && money > 0) {
        int num = min(max_num, money / cost[i]);
        money -= num * cost[i];
        ans += num;
        ++i;
    }
    cout << ans;
}



int main() {
  JumpList *elements = new JumpList[6];
  elements[0] = JumpList{.next = &elements[1], .jump = &elements[3], .id = 1u};
  elements[1] = JumpList{.next = &elements[2], .jump = &elements[4], .id = 2u};
  elements[2] = JumpList{.next = &elements[3], .jump = &elements[5], .id = 3u};
  elements[3] = JumpList{.next = &elements[4], .jump = &elements[5], .id = 4u};
  elements[4] = JumpList{.next = &elements[5], .jump = nullptr, .id = 5u};
  elements[5] = JumpList{.next = nullptr, .jump = nullptr, .id = 6u};
  JumpList *clone = clone_jump_list(elements);

  JumpList *a = elements, *b = clone;
  while (nullptr != a) {
    assert(a->id == b->id and a != b);
    if (nullptr != a->jump) 
      assert(a->jump->id == b->jump->id and a->jump != b->jump);
    a = a->next;
    b = b->next;
  }
  assert(nullptr == b);
  delete[] elements;
  erase_jump_list(clone);

	return 0;
}