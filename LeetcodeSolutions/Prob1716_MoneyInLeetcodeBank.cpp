class Solution {
public:
    int totalMoney(int n) {
        auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        int w = n / 7;
        int money = w * 28;
        money += (7 * w * (w - 1)) / 2;

        if (n % 7) {
            int extra_days = n % 7;
            int money_to_add = w + 1;
            for (int i = 0; i < extra_days; ++i) {
                money += money_to_add;
                money_to_add += 1;
            }
        }
        return money;
    }
};
// time complexity: O(1)
// space complexity: O(1)
// Above code  computes the value of the first week and then adds the value of the remaining weeks.