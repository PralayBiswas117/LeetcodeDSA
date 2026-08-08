#include <mutex>
#include <condition_variable>
using namespace std;

class H2O {
private:
    mutex mtx;
    condition_variable cv;
    int h = 0;
    int o = 0;

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [&] { return h < 2; });

        releaseHydrogen();
        h++;

        if (h == 2 && o == 1) {
            h = 0;
            o = 0;
            cv.notify_all();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [&] { return o < 1; });

        releaseOxygen();
        o++;

        if (h == 2 && o == 1) {
            h = 0;
            o = 0;
            cv.notify_all();
        }
    }
};