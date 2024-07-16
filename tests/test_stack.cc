#include "tests.h"

class StackTests : public testing::Test {
 protected:
  s21::stack<int> test_st{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::stack<int> orig_st;
  s21::stack<int> empty_st;

  void SetUp() override {
    for (int i = 1; i <= 10; i++) orig_st.push(i);
  }
};

class StackTestsStrings : public testing::Test {
 protected:
  s21::stack<std::string> test_st{"1", "2", "3", "4", "5",
                                  "6", "7", "8", "9", "10"};
  std::stack<std::string> orig_st;
  s21::stack<std::string> empty_st;

  void SetUp() override {
    orig_st.push("1");
    orig_st.push("2");
    orig_st.push("3");
    orig_st.push("4");
    orig_st.push("5");
    orig_st.push("6");
    orig_st.push("7");
    orig_st.push("8");
    orig_st.push("9");
    orig_st.push("10");
  }
};

TEST_F(StackTests, ConstructorTest0) {
  s21::stack<int> test_stack;
  EXPECT_EQ(test_stack.size(), 0);
}

TEST_F(StackTests, ConstructorTest1) {
  s21::stack<int> test_stack{1, 2, 3, 4, 5, 6, 7};
  std::stack<int> orig_stack({1, 2, 3, 4, 5, 6, 7});
  EXPECT_EQ(test_stack.size(), orig_stack.size());

  for (int i = 7; i > 0; i--) {
    EXPECT_EQ(test_stack.top(), orig_stack.top());
    test_stack.pop();
    orig_stack.pop();
  }
}

TEST_F(StackTests, ConstructorTest2) {
  s21::stack<int> test_stack({1, 2, 3, 4, 5, 6, 7});
  EXPECT_EQ(test_stack.size(), 7);
  std::stack<int> expect({1, 2, 3, 4, 5, 6, 7});
  while (test_stack.size() != 0) {
    EXPECT_EQ(test_stack.top(), expect.top());
    test_stack.pop();
    expect.pop();
  }
}

TEST_F(StackTests, CopyTest0) {
  s21::stack<int> copy_st = test_st;
  EXPECT_EQ(copy_st.size(), test_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), test_st.top());
    copy_st.pop();
    test_st.pop();
  }
}

TEST_F(StackTests, CopyTest1) {
  s21::stack<int> copy_st = empty_st;
  EXPECT_EQ(copy_st.size(), empty_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), empty_st.top());
    copy_st.pop();
    empty_st.pop();
  }
}

TEST_F(StackTests, CopyOperatorTest0) {
  s21::stack<int> copy_st;
  copy_st = test_st;
  EXPECT_EQ(copy_st.size(), test_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), test_st.top());
    copy_st.pop();
    test_st.pop();
  }
}

TEST_F(StackTests, CopyOperatorTest1) {
  s21::stack<int> copy_st = {300, 600, 890};
  copy_st = test_st;
  EXPECT_EQ(copy_st.size(), test_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), test_st.top());
    copy_st.pop();
    test_st.pop();
  }
}

TEST_F(StackTests, CopyOperatorTest2) {
  s21::stack<int> copy_st;
  ;
  test_st = copy_st;
  EXPECT_EQ(copy_st.size(), test_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), test_st.top());
    copy_st.pop();
    test_st.pop();
  }
}

TEST_F(StackTests, MoveTest0) {
  s21::stack<int> moved_st = std::move(test_st);
  EXPECT_EQ(test_st.size(), 0);
  EXPECT_EQ(moved_st.size(), 10);

  for (int i = 10; i > 0; i--) {
    EXPECT_EQ(moved_st.top(), i);
    moved_st.pop();
  }
}

TEST_F(StackTests, EmptyTest) {
  s21::stack<double> test_stack;
  EXPECT_TRUE(test_stack.empty());
  test_stack.push(234.5789);
  EXPECT_FALSE(test_stack.empty());
  test_stack.pop();
  EXPECT_TRUE(test_stack.empty());
}

TEST_F(StackTests, SizeTest) {
  EXPECT_EQ(test_st.size(), 10);
  for (int i = 0; i < 10; i++) test_st.push(i);
  EXPECT_EQ(test_st.size(), 20);
  for (int i = 0; i < 20; i++) test_st.pop();
  EXPECT_EQ(test_st.size(), 0);
}

TEST_F(StackTests, PushTest) {
  for (int i = 11; i <= 15; i++) test_st.push(i);
  EXPECT_EQ(test_st.size(), 15);
  for (int i = 15; i > 0; i--) {
    EXPECT_EQ(test_st.top(), i);
    test_st.pop();
  }
}

TEST_F(StackTests, PopTest) {
  test_st.pop();
  EXPECT_EQ(test_st.size(), 9);
  for (int i = 0; i < 20; i++) test_st.pop();
  EXPECT_EQ(test_st.size(), 0);
}

TEST_F(StackTests, SwapTest0) {
  s21::stack<int> test_st2;
  test_st.swap(test_st2);
  EXPECT_EQ(test_st.size(), 0);
  EXPECT_EQ(test_st2.size(), 10);
  for (int i = 10; i > 0; i--) {
    EXPECT_EQ(test_st2.top(), i);
    test_st2.pop();
  }
}

TEST_F(StackTests, SwapTest1) {
  s21::stack<int> test_st2{10, 20, 30, 40, 50, 60};
  test_st.swap(test_st2);
  EXPECT_EQ(test_st.size(), 6);
  EXPECT_EQ(test_st2.size(), 10);
  for (int i = 10; i > 0; i--) {
    EXPECT_EQ(test_st2.top(), i);
    test_st2.pop();
  }
  for (int i = 60; i > 0; i -= 10) {
    EXPECT_EQ(test_st.top(), i);
    test_st.pop();
  }
}

TEST_F(StackTestsStrings, ConstructorTest0) {
  s21::stack<std::string> test_stack;
  EXPECT_EQ(test_stack.size(), 0);
}

TEST_F(StackTestsStrings, ConstructorTest1) {
  s21::stack<std::string> test_stack{"1", "2", "3", "4", "5", "6", "7"};
  std::stack<std::string> orig_stack({"1", "2", "3", "4", "5", "6", "7"});
  EXPECT_EQ(test_stack.size(), orig_stack.size());

  for (int i = 7; i > 0; i--) {
    EXPECT_EQ(test_stack.top(), orig_stack.top());
    test_stack.pop();
    orig_stack.pop();
  }
}

TEST_F(StackTestsStrings, CopyTest0) {
  s21::stack<std::string> copy_st = test_st;
  EXPECT_EQ(copy_st.size(), test_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), test_st.top());
    copy_st.pop();
    test_st.pop();
  }
}

TEST_F(StackTestsStrings, CopyTest1) {
  s21::stack<std::string> copy_st = empty_st;
  EXPECT_EQ(copy_st.size(), empty_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), empty_st.top());
    copy_st.pop();
    empty_st.pop();
  }
}

TEST_F(StackTestsStrings, CopyOperatorTest0) {
  s21::stack<std::string> copy_st;
  copy_st = test_st;
  EXPECT_EQ(copy_st.size(), test_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), test_st.top());
    copy_st.pop();
    test_st.pop();
  }
}

TEST_F(StackTestsStrings, CopyOperatorTest1) {
  s21::stack<std::string> copy_st = {"300", "600", "890"};
  copy_st = test_st;
  EXPECT_EQ(copy_st.size(), test_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), test_st.top());
    copy_st.pop();
    test_st.pop();
  }
}

TEST_F(StackTestsStrings, CopyOperatorTest2) {
  s21::stack<std::string> copy_st;
  ;
  test_st = copy_st;
  EXPECT_EQ(copy_st.size(), test_st.size());
  while (copy_st.size() != 0) {
    EXPECT_EQ(copy_st.top(), test_st.top());
    copy_st.pop();
    test_st.pop();
  }
}

TEST_F(StackTestsStrings, MoveTest0) {
  s21::stack<std::string> moved_st = std::move(test_st);
  EXPECT_EQ(test_st.size(), 0);
  EXPECT_EQ(moved_st.size(), 10);

  for (int i = 10; i > 0; i--) {
    EXPECT_EQ(moved_st.top(), orig_st.top());
    orig_st.pop();
    moved_st.pop();
  }
}

TEST_F(StackTestsStrings, MoveTest1) {
  s21::stack<std::string> moved_st;
  moved_st = std::move(test_st);

  EXPECT_EQ(test_st.size(), 0);
  EXPECT_EQ(moved_st.size(), 10);

  for (int i = 10; i > 0; i--) {
    EXPECT_EQ(moved_st.top(), orig_st.top());
    orig_st.pop();
    moved_st.pop();
  }
}

TEST_F(StackTestsStrings, EmptyTest) {
  s21::stack<std::string> test_stack;
  EXPECT_TRUE(test_stack.empty());
  test_stack.push("qwertyu");
  EXPECT_FALSE(test_stack.empty());
  test_stack.pop();
  EXPECT_TRUE(test_stack.empty());
}

TEST_F(StackTestsStrings, SizeTest) {
  EXPECT_EQ(test_st.size(), 10);
  test_st.push("ooo");
  test_st.push("ooo");
  EXPECT_EQ(test_st.size(), 12);
  for (int i = 0; i < 12; i++) test_st.pop();
  EXPECT_EQ(test_st.size(), 0);
}

TEST_F(StackTestsStrings, PushTest) {
  test_st.push("qqqqqqq");
  test_st.push("rrrrr");
  test_st.push("zxcvbnm,.");
  EXPECT_EQ(test_st.size(), 13);
}

TEST_F(StackTestsStrings, PopTest) {
  test_st.pop();
  EXPECT_EQ(test_st.size(), 9);
  for (int i = 0; i < 20; i++) test_st.pop();
  EXPECT_EQ(test_st.size(), 0);
}

TEST_F(StackTestsStrings, SwapTest0) {
  s21::stack<std::string> test_st2;
  test_st.swap(test_st2);
  EXPECT_EQ(test_st.size(), 0);
  EXPECT_EQ(test_st2.size(), 10);
  for (int i = 10; i > 0; i--) {
    EXPECT_EQ(test_st2.top(), orig_st.top());
    test_st2.pop();
    orig_st.pop();
  }
}

TEST_F(StackTests, EmplaceManyFrontTest0) {
  test_st.insert_many_front(600, 700, 800);
  orig_st.push(600);
  orig_st.push(700);
  orig_st.push(800);
  while (orig_st.size() != 0) {
    EXPECT_EQ(test_st.top(), orig_st.top());
    test_st.pop();
    orig_st.pop();
  }
}

TEST_F(StackTests, EmplaceManyFrontTest1) {
  test_st.insert_many_front(600);
  orig_st.push(600);
  while (orig_st.size() != 0) {
    EXPECT_EQ(test_st.top(), orig_st.top());
    test_st.pop();
    orig_st.pop();
  }
}

TEST_F(StackTests, EmplaceManyFrontTest2) {
  test_st.insert_many_front();
  while (orig_st.size() != 0) {
    EXPECT_EQ(test_st.top(), orig_st.top());
    test_st.pop();
    orig_st.pop();
  }
}
