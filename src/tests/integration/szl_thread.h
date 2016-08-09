#pragma once

#include <gtest/gtest.h>
#include "common/szl.h"
#include <thread>
#include <iostream>
#include <vector>

int var_loker = 0;

void thread_call(){
  auto id(std::this_thread::get_id());
  while(var_loker > 0){};
  LOG() << "Hello from thread " << id << "\n";
}

TEST(thread, foo){
  var_loker = 1;
  /// CONSTRUCT THE LOG WITH THREADS
  std::ostringstream local;
  auto cout_buff = std::cout.rdbuf();
  std::cout.rdbuf(local.rdbuf()); // cout-buffer points to local

  const int _n_threads(4);
  std::vector<std::thread> threads;

  for(int i = 0; i < _n_threads; ++i){
    threads.push_back( std::thread(thread_call) );
    /* std::thread t(thread_call); */
    /* threads.push_back(t); */
    /* threads_name.push_back(t.get_id()); */
  }
  var_loker=0;
  for(auto& thread : threads){
    thread.join();
  }

  // go back to old buffer
  std::cout.rdbuf(cout_buff);
  std::cout << local.str();
}
