class Solution {
public:
    int gettime(string time) {
        int hour = stoi(time.substr(0 , 2));
        int min = stoi(time.substr(3 , 2));
        int total = hour*60 + min;
        return total;
    }
    int convertTime(string current, string correct) {
        int diff = gettime(correct) - gettime(current);
        int ops = 0;

        ops += diff/60;
        diff = diff%60;

        ops += diff/15;
        diff = diff%15;

        ops += diff/5;
        diff = diff%5;

        ops += diff;
        return ops;
    }
};