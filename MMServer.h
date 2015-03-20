#ifndef MMSERVER_H
#define MMSERVER_H
#include <iostream>
#include <thread>
#include <chrono>
#include <list>
#include <string>

using namespace std;

class MMServer{
public:
    MMServer();
    ~MMServer();
    void run();
    void wait();
    void setMsgCallback(void(*msgCallback)(std::string));


private:
    std::thread* mainThread;
    void (*msgCallback)(std::string msg);
    void mainRoutine();
    static void mainRoutineCallable(MMServer* s);

};
#endif
