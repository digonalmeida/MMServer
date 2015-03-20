#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <string>
#include <list>
#include <map>
#include <chrono>
#include "MMServer.h"

using namespace std;

void message_received(string s){
    cout <<"msg " << s;
}

int main(){
    MMServer* server = new MMServer();
    server->setMsgCallback(message_received);
    server->run();
    server->wait();
}


/*
using namespace std;
list<string> players;
map<string, int> playerScore;
mutex playersMutex;

void add_player(string name){
	players.push_back(name);
}
void consoleThread(){

}
void mainUpdateThread(){
	for(;;){
		this_thread::sleep_for(std::chrono::milliseconds(1000));
		cout << "update" << endl;
	}
}
int main()
{
	mainUpdateThread();
  return 0;
}
*/
