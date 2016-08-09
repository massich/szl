#pragma once

#include <gtest/gtest.h>
#include <strstream>
#include "common/szl.h"


class szlBasicFixture: public ::testing::Test {
 public:
  szlBasicFixture( ) {
    // initialization code here
  }

  void SetUp( ) {
    // code here will execute just before the test ensues
    captured_stream = new std::ostringstream();
    cout_buff = std::cout.rdbuf();
    std::cout.rdbuf(captured_stream->rdbuf()); // cout-buffer points to local

  }

  void TearDown( ) {
    // code here will be called just after the test completes
    // ok to through exceptions from here if need be
    delete(captured_stream);
    std::cout.rdbuf(cout_buff);
  }

  ~szlBasicFixture( )  {
    // cleanup any pending stuff, but no exceptions allowed
  }

  // put in any custom data members that you need
  std::ostringstream * captured_stream;
  std::strstreambuf::basic_streambuf * cout_buff;
};

// TEST(szlBasicFixture,critic){}
// TEST(szlBasicFixture,error){}
// TEST(szlBasicFixture,warning){}
// TEST(szlBasicFixture,info){}
// TEST(szlBasicFixture,trace){}
// TEST(szlBasicFixture,crazy){}

TEST_F(szlBasicFixture, log_levels){
  LOG(LogLevel::FATAL) << "test";
  ASSERT_STREQ( "[fatal]: test", captured_stream->str().c_str() );
}

TEST_F(szlBasicFixture, log_levels_default){
  LOG() << "test";
  ASSERT_STREQ( "[fatal]: test", captured_stream->str().c_str() );
}

TEST_F(szlBasicFixture, wrong_enum){
  try {
    LOG( static_cast<LogLevel>(-1) ) << "test";
  } catch(std::bad_cast const & err) {
    EXPECT_EQ( std::string("Wrong LogLevel"), err.what() );
  }
}

TEST_F(szlBasicFixture, wrong_enum2){
  std::ostringstream local;
  try {
    local << static_cast<LogLevel>(-1);
  } catch(std::bad_cast const & err) {
    EXPECT_EQ( std::string("Wrong LogLevel"), err.what() );
  }
}

TEST_F(szlBasicFixture, log_unknown_object){
  /* Here you don't see if the problem is with streaming the LogLevel or the
   * object after it
   */

  try {
    LOG() << NULL;
  } catch(std::bad_cast const & err) {
    EXPECT_EQ( std::string("Wrong LogLevel"), err.what() );
  }
}

struct UnknownObject{};
TEST_F(szlBasicFixture, log_unknown_object2){
  /* Here you don't see if the problem is with streaming the LogLevel or the
   * object after it
   */

  UnknownObject unknwn_obj;
  try {
    LOG() << static_cast<void*>(&unknwn_obj) ; //void* is the most basic type available for <<
  } catch(std::bad_cast const & err) {
    EXPECT_EQ( std::string("Wrong LogLevel"), err.what() );
  }
}
