#pragma once

#include <gtest/gtest.h>
#include "common/szl.h"
#include <thread>
#include <iostream>
#include <vector>

template <typename T>
void log_id(T id){
  LOG() << "Hello from thread " << id << "\n";
}

void thread_call(){
  log_id( std::this_thread::get_id() ) ;
}

TEST(thread, foo){

  /// CONSTRUCT THE LOG WITH THREADS
  std::ostringstream local;
  auto cout_buff = std::cout.rdbuf();
  std::cout.rdbuf(local.rdbuf()); // cout-buffer points to local

  const int _n_threads(4);
  std::vector<std::thread> threads;
  std::vector<std::thread::id> threads_name;

  for(int i = 0; i < _n_threads; ++i){
    threads.push_back( std::thread(thread_call) );
    /* std::thread t(thread_call); */
    /* threads.push_back(t); */
    /* threads_name.push_back(t.get_id()); */
  }

  for(auto& thread : threads){
    thread.join();
  }

  /// CONSTRUCT THE LOG WITHOUT THREADS
  std::ostringstream local_no_thread;
  std::cout.rdbuf(local_no_thread.rdbuf());

  for(auto& thread : threads){
    threads_name.push_back(thread.get_id()) ;
  }
  for(auto& name : threads_name){
    log_id(name);
  }

  // go back to old buffer
  std::cout.rdbuf(cout_buff);
  std::cout << local.str();
  std::cout << local_no_thread.str();
}
