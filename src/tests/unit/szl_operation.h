#pragma once

#include <gtest/gtest.h>
#include "common/szl.h"

// TEST(foo,critic){}
// TEST(foo,error){}
// TEST(foo,warning){}
// TEST(foo,info){}
// TEST(foo,trace){}
// TEST(foo,crazy){}

TEST(foo, log_levels){
  std::ostringstream local;
  auto cout_buff = std::cout.rdbuf();
  std::cout.rdbuf(local.rdbuf()); // cout-buffer points to local
  LOG(LogLevel::FATAL) << "test";
  ASSERT_STREQ( "[fatal]: test", local.str().c_str() );
  // go back to old buffer
  std::cout.rdbuf(cout_buff);
}

TEST(foo, log_levels_default){
  std::ostringstream local;
  auto cout_buff = std::cout.rdbuf();
  std::cout.rdbuf(local.rdbuf()); // cout-buffer points to local
  LOG() << "test";
  ASSERT_STREQ( "[fatal]: test", local.str().c_str() );
  // go back to old buffer
  std::cout.rdbuf(cout_buff);
}

TEST(foo, wrong_enum){
  std::ostringstream local;
  auto cout_buff = std::cout.rdbuf();
  std::cout.rdbuf(local.rdbuf()); // cout-buffer points to local
  try {
    LOG( static_cast<LogLevel>(-1) ) << "test";
  } catch(std::bad_cast const & err) {
    EXPECT_EQ( std::string("Wrong LogLevel"), err.what() );
  }
  // go back to old buffer
  std::cout.rdbuf(cout_buff);
}

TEST(foo, wrong_enum2){
  std::ostringstream local;
  try {
    local << static_cast<LogLevel>(-1);
  } catch(std::bad_cast const & err) {
    EXPECT_EQ( std::string("Wrong LogLevel"), err.what() );
  }
}

TEST(foo, log_unknown_object){
  /* Here you don't see if the problem is with streaming the LogLevel or the
   * object after it
   */

  std::ostringstream local;
  auto cout_buff = std::cout.rdbuf();
  std::cout.rdbuf(local.rdbuf()); // cout-buffer points to local
  try {
    LOG() << NULL;
  } catch(std::bad_cast const & err) {
    EXPECT_EQ( std::string("Wrong LogLevel"), err.what() );
  }
  // go back to old buffer
  std::cout.rdbuf(cout_buff);
}

struct UnknownObject{};
TEST(foo, log_unknown_object2){
  /* Here you don't see if the problem is with streaming the LogLevel or the
   * object after it
   */

  std::ostringstream local;
  UnknownObject unknwn_obj;
  auto cout_buff = std::cout.rdbuf();
  std::cout.rdbuf(local.rdbuf()); // cout-buffer points to local
  try {
    LOG() << static_cast<void*>(&unknwn_obj) ; //void* is the most basic type available for <<
  } catch(std::bad_cast const & err) {
    EXPECT_EQ( std::string("Wrong LogLevel"), err.what() );
  }
  // go back to old buffer
  std::cout.rdbuf(cout_buff);
}
