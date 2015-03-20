#include "MMServer.h"
using namespace std;
MMServer::MMServer(){
    msgCallback = NULL;
    mainThread = NULL;
}

MMServer::~MMServer(){
    delete mainThread;
}

void MMServer::run(){
    if(mainThread != NULL){
        delete mainThread;
    }
    mainThread = new thread(MMServer::mainRoutineCallable, this);
}

void MMServer::mainRoutine(){
    while(true){
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        if(msgCallback != NULL){
            msgCallback("teste");
        }
    }
}

void MMServer::wait(){
    if(mainThread != NULL) {
        mainThread->join();
    }
}

void MMServer::mainRoutineCallable(MMServer* s){
    if(s!=NULL)
        s->mainRoutine();
}

void MMServer::setMsgCallback(void(*newMsgCallback)(std::string)){
    msgCallback = newMsgCallback;
}
