#include "ClientCounter.h"

ClientCounter::ClientCounter()
    : count(0), mutex(), cv() {}

ClientCounter::~ClientCounter() {}

void ClientCounter::add_client() {
  std::unique_lock<std::mutex> lock(mutex);
  count++;
} 

void ClientCounter::remove_client() {
  std::unique_lock<std::mutex> lock(mutex);
  count--;
  cv.notify_all();
} 

const bool ClientCounter::wait_until_no_more_clients() {
  std::unique_lock<std::mutex> lock(mutex);
  while (count > 0) {
  	cv.wait(lock);
  }
  return true;
} 
