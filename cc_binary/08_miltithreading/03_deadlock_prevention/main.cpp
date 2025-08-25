#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutexA;
std::mutex mutexB;

void threadFuncA() {
   std::lock_guard<std::mutex> lockA(mutexA);
   std::this_thread::sleep_for(std::chrono::milliseconds(50));
   std::lock_guard<std::mutex> lockB(mutexB); // Potential deadlock here
}

void threadFuncB() {
   std::lock_guard<std::mutex> lockB(mutexB);
   std::this_thread::sleep_for(std::chrono::milliseconds(50));
   std::lock_guard<std::mutex> lockA(mutexA); // Potential deadlock here
}