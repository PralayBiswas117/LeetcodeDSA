class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int turn = 0; // 0 = zero, 1 = odd, 2 = even

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i++) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return turn == 0;
            });

            printNumber(0);

            if (i % 2 == 1)
                turn = 1; // odd's turn
            else
                turn = 2; // even's turn

            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return turn == 2;
            });

            printNumber(i);

            turn = 0; // zero's turn
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() {
                return turn == 1;
            });

            printNumber(i);

            turn = 0; // zero's turn
            cv.notify_all();
        }
    }
};