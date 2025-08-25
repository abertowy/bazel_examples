#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
const size_t bufferSize = 5;
std::mutex mtx;
std::condition_variable cv;

void producer() {
    for (int i = 1; i <= 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < bufferSize; });

        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;

        cv.notify_all();
    }
}

void consumer() {
    for (int i = 1; i <= 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock