class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> answer;

        for (int num = left; num <= right; num++) {
            int x = num;
            bool valid = true;

            while (x > 0) {
                int digit = x % 10;

                // A number containing 0 is invalid
                if (digit == 0 || num % digit != 0) {
                    valid = false;
                    break;
                }

                x /= 10;
            }

            if (valid)
                answer.push_back(num);
        }

        return answer;
    }
};