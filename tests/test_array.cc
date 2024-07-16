#include "tests.h"

struct ArrayTests : public testing::Test {
 protected:
  s21::array<int, 5> s21_arr = {1, 2, 3, 4, 5};
  std::array<int, 5> orig_arr = {1, 2, 3, 4, 5};
  s21::array<int, 7> s21_arr2 = {-9, -8, -7, -6, -5, -4, -3};
  std::array<int, 7> orig_arr2 = {-9, -8, -7, -6, -5, -4, -3};
  s21::array<int, 0> s21_empty;
  std::array<int, 0> orig_empty;
};

struct ArrayTestsStrings : public testing::Test {
 protected:
  s21::array<std::string, 5> s21_arr = {"1", "2", "3", "4", "5"};
  std::array<std::string, 5> orig_arr = {"1", "2", "3", "4", "5"};
  s21::array<std::string, 7> s21_arr2 = {"-9", "-8", "-7", "-6",
                                         "-5", "-4", "-3"};
  std::array<std::string, 7> orig_arr2 = {"-9", "-8", "-7", "-6",
                                          "-5", "-4", "-3"};
  s21::array<std::string, 0> s21_empty;
  std::array<std::string, 0> orig_empty;
};

TEST_F(ArrayTests, ConstructorTest0) {
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
}

TEST_F(ArrayTests, ConstructorTest1) {
  EXPECT_EQ(s21_arr.size(), orig_arr.size());
}

TEST_F(ArrayTests, ConstructorTest2) {
  for (size_t i = 0; i < s21_arr.size(); i++)
    EXPECT_EQ(s21_arr[i], orig_arr[i]);
}

TEST_F(ArrayTests, ConstructorTest3) {
  s21::array<int, 10> test_array = {1, 2, 3};
  std::array<int, 10> orig_array = {1, 2, 3};
  for (size_t i = 0; i < test_array.size(); i++)
    EXPECT_EQ(test_array[i], orig_array[i]);
}

TEST_F(ArrayTests, CopyTest0) {
  s21::array<int, 5> copy_arr = s21_arr;
  for (size_t i = 0; i < copy_arr.size(); i++)
    EXPECT_EQ(s21_arr[i], copy_arr[i]);
}

TEST_F(ArrayTests, CopyOperatorTest0) {
  s21::array<int, 5> copy_arr;
  copy_arr = s21_arr;
  for (size_t i = 0; i < copy_arr.size(); i++)
    EXPECT_EQ(s21_arr[i], copy_arr[i]);
}

TEST_F(ArrayTests, MoveTest0) {
  s21::array<int, 5> moved_arr = std::move(s21_arr);
  for (size_t i = 0; i < moved_arr.size(); i++) EXPECT_EQ(moved_arr[i], i + 1);
}
TEST_F(ArrayTests, MoveOpTest0) {
  s21::array<int, 5> moved_arr;
  moved_arr = std::move(s21_arr);
  for (size_t i = 0; i < moved_arr.size(); i++) EXPECT_EQ(moved_arr[i], i + 1);
}

TEST_F(ArrayTests, ElemAccess0) {
  for (size_t i = 0; i < s21_arr.size(); i++) EXPECT_EQ(s21_arr[i], i + 1);
}

TEST_F(ArrayTests, ElemAccess1) {
  for (size_t i = 0; i < s21_arr.size(); i++) s21_arr[i] = s21_arr[i] * 10;
  for (size_t i = 0; i < orig_arr.size(); i++) orig_arr[i] = orig_arr[i] * 10;
  for (size_t i = 0; i < orig_arr.size(); i++)
    EXPECT_EQ(orig_arr.at(i), s21_arr.at(i));
}

TEST_F(ArrayTests, AtTest0) {
  for (size_t i = 0; i < orig_arr.size(); i++)
    EXPECT_EQ(orig_arr.at(i), s21_arr.at(i));
}

TEST_F(ArrayTests, AtTest1) {
  s21_arr.at(0) = 234;
  orig_arr.at(0) = 234;
  s21_arr.at(3) = 100000;
  orig_arr.at(3) = 100000;
  for (size_t i = 0; i < orig_arr.size(); i++)
    EXPECT_EQ(orig_arr.at(i), s21_arr.at(i));
}

TEST_F(ArrayTests, AtTest2) {
  EXPECT_THROW(orig_arr.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr.at(5), std::out_of_range);
}

TEST_F(ArrayTests, FrontTest) {
  EXPECT_EQ(orig_arr.front(), s21_arr.front());
  EXPECT_EQ(orig_arr2.front(), s21_arr2.front());
}

TEST_F(ArrayTests, BackTest) {
  EXPECT_EQ(orig_arr.back(), s21_arr.back());
  EXPECT_EQ(orig_arr2.back(), s21_arr2.back());
}

TEST_F(ArrayTests, DataTest) {
  EXPECT_EQ(*(orig_arr.data()), *(s21_arr.data()));
  EXPECT_EQ(*(orig_arr2.data()), *(s21_arr2.data()));
}

TEST_F(ArrayTests, BeginTest) {
  EXPECT_EQ(*(orig_arr.begin()), *(s21_arr.begin()));
  EXPECT_EQ(*(orig_arr2.begin()), *(s21_arr2.begin()));
  EXPECT_EQ(s21_empty.begin(), s21_empty.end());
}

TEST_F(ArrayTests, EndTest) {
  EXPECT_EQ(*(orig_arr.end() - 1), *(s21_arr.end() - 1));
  EXPECT_EQ(*(orig_arr2.end() - 1), *(s21_arr2.end() - 1));
}

TEST_F(ArrayTests, EmptyTest) {
  EXPECT_TRUE(s21_empty.empty());
  EXPECT_FALSE(s21_arr.empty());
}

TEST_F(ArrayTests, SizeTest) {
  EXPECT_EQ(s21_arr.size(), orig_arr.size());
  EXPECT_EQ(s21_arr2.size(), orig_arr2.size());
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
}

TEST_F(ArrayTests, MaxSizeTest) {
  EXPECT_EQ(s21_arr.max_size(), orig_arr.max_size());
  EXPECT_EQ(s21_arr2.max_size(), orig_arr2.max_size());
  EXPECT_EQ(s21_empty.max_size(), orig_empty.max_size());
}

TEST_F(ArrayTests, SwapTest) {
  std::array<int, 5> swap_orig = {9, 9, 9, 9, 9};
  s21::array<int, 5> swap_s21 = {9, 9, 9, 9, 9};
  swap_orig.swap(orig_arr);
  swap_s21.swap(s21_arr);
  for (size_t i = 0; i < swap_orig.size(); i++)
    EXPECT_EQ(swap_orig[i], swap_s21[i]);
  for (size_t i = 0; i < orig_arr.size(); i++) {
    EXPECT_EQ(orig_arr[i], s21_arr[i]);
    EXPECT_EQ(s21_arr[i], 9);
  }
}

TEST_F(ArrayTests, FillTest) {
  s21_arr.fill(9);
  orig_arr.fill(9);
  for (size_t i = 0; i < orig_arr.size(); i++)
    EXPECT_EQ(orig_arr[i], s21_arr[i]);
  s21_empty.fill(9);
  orig_empty.fill(9);
  for (size_t i = 0; i < orig_empty.size(); i++)
    EXPECT_EQ(orig_empty[i], s21_empty[i]);

  s21_empty.fill(8);
}

TEST_F(ArrayTestsStrings, ConstructorTest0) {
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
}

TEST_F(ArrayTestsStrings, ConstructorTest1) {
  EXPECT_EQ(s21_arr.size(), orig_arr.size());
}

TEST_F(ArrayTestsStrings, ConstructorTest2) {
  for (size_t i = 0; i < s21_arr.size(); i++)
    EXPECT_EQ(s21_arr[i], orig_arr[i]);
}

TEST_F(ArrayTestsStrings, ConstructorTest3) {
  s21::array<std::string, 10> test_array = {"1", "2", "3"};
  std::array<std::string, 10> orig_array = {"1", "2", "3"};
  for (size_t i = 0; i < test_array.size(); i++)
    EXPECT_EQ(test_array[i], orig_array[i]);
}

TEST_F(ArrayTestsStrings, CopyTest0) {
  s21::array<std::string, 5> copy_arr = s21_arr;
  for (size_t i = 0; i < copy_arr.size(); i++)
    EXPECT_EQ(s21_arr[i], copy_arr[i]);
}

TEST_F(ArrayTestsStrings, CopyOperatorTest0) {
  s21::array<std::string, 5> copy_arr;
  copy_arr = s21_arr;
  for (size_t i = 0; i < copy_arr.size(); i++)
    EXPECT_EQ(s21_arr[i], copy_arr[i]);
}

TEST_F(ArrayTestsStrings, MoveTest0) {
  s21::array<std::string, 5> moved_arr = std::move(s21_arr);
  for (size_t i = 0; i < moved_arr.size(); i++)
    EXPECT_EQ(moved_arr[i], orig_arr[i]);
}
TEST_F(ArrayTestsStrings, MoveOpTest0) {
  s21::array<std::string, 5> moved_arr;
  moved_arr = std::move(s21_arr);
  for (size_t i = 0; i < moved_arr.size(); i++)
    EXPECT_EQ(moved_arr[i], orig_arr[i]);
}

TEST_F(ArrayTestsStrings, ElemAccess0) {
  for (size_t i = 0; i < s21_arr.size(); i++) {
    EXPECT_EQ(s21_arr[i], orig_arr[i]);
  }
}

TEST_F(ArrayTestsStrings, ElemAccess1) {
  s21_arr[0] = "lost";
  orig_arr[0] = "lost";
  s21_arr[3] = "babube";
  orig_arr[3] = "babube";
  for (size_t i = 0; i < orig_arr.size(); i++)
    EXPECT_EQ(orig_arr.at(i), s21_arr.at(i));
}

TEST_F(ArrayTestsStrings, AtTest0) {
  for (size_t i = 0; i < orig_arr.size(); i++)
    EXPECT_EQ(orig_arr.at(i), s21_arr.at(i));
}

TEST_F(ArrayTestsStrings, AtTest1) {
  s21_arr.at(0) = "234";
  orig_arr.at(0) = "234";
  s21_arr.at(3) = "100000";
  orig_arr.at(3) = "100000";
  for (size_t i = 0; i < orig_arr.size(); i++)
    EXPECT_EQ(orig_arr.at(i), s21_arr.at(i));
}

TEST_F(ArrayTestsStrings, AtTest2) {
  EXPECT_THROW(orig_arr.at(5), std::out_of_range);
  EXPECT_THROW(s21_arr.at(5), std::out_of_range);
}

TEST_F(ArrayTestsStrings, FrontTest) {
  EXPECT_EQ(orig_arr.front(), s21_arr.front());
  EXPECT_EQ(orig_arr2.front(), s21_arr2.front());
}

TEST_F(ArrayTestsStrings, BackTest) {
  EXPECT_EQ(orig_arr.back(), s21_arr.back());
  EXPECT_EQ(orig_arr2.back(), s21_arr2.back());
}

TEST_F(ArrayTestsStrings, DataTest) {
  EXPECT_EQ(*(orig_arr.data()), *(s21_arr.data()));
  EXPECT_EQ(*(orig_arr2.data()), *(s21_arr2.data()));
}

TEST_F(ArrayTestsStrings, BeginTest) {
  EXPECT_EQ(*(orig_arr.begin()), *(s21_arr.begin()));
  EXPECT_EQ(*(orig_arr2.begin()), *(s21_arr2.begin()));
  EXPECT_EQ(s21_empty.begin(), s21_empty.end());
}

TEST_F(ArrayTestsStrings, EndTest) {
  EXPECT_EQ(*(orig_arr.end() - 1), *(s21_arr.end() - 1));
  EXPECT_EQ(*(orig_arr2.end() - 1), *(s21_arr2.end() - 1));
}

TEST_F(ArrayTestsStrings, EmptyTest) {
  EXPECT_TRUE(s21_empty.empty());
  EXPECT_FALSE(s21_arr.empty());
}

TEST_F(ArrayTestsStrings, SizeTest) {
  EXPECT_EQ(s21_arr.size(), orig_arr.size());
  EXPECT_EQ(s21_arr2.size(), orig_arr2.size());
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
}

TEST_F(ArrayTestsStrings, MaxSizeTest) {
  EXPECT_EQ(s21_arr.max_size(), orig_arr.max_size());
  EXPECT_EQ(s21_arr2.max_size(), orig_arr2.max_size());
  EXPECT_EQ(s21_empty.max_size(), orig_empty.max_size());
}

TEST_F(ArrayTestsStrings, SwapTest) {
  std::array<std::string, 5> swap_orig = {"9", "9", "9", "9", "9"};
  s21::array<std::string, 5> swap_s21 = {"9", "9", "9", "9", "9"};
  swap_orig.swap(orig_arr);
  swap_s21.swap(s21_arr);
  for (size_t i = 0; i < swap_orig.size(); i++)
    EXPECT_EQ(swap_orig[i], swap_s21[i]);
  for (size_t i = 0; i < orig_arr.size(); i++) {
    EXPECT_EQ(orig_arr[i], s21_arr[i]);
    EXPECT_EQ(s21_arr[i], "9");
  }
}

TEST_F(ArrayTestsStrings, FillTest) {
  s21_arr.fill("9");
  orig_arr.fill("9");
  for (size_t i = 0; i < orig_arr.size(); i++)
    EXPECT_EQ(orig_arr[i], s21_arr[i]);
  s21_empty.fill("9");
  orig_empty.fill("9");
  for (size_t i = 0; i < orig_empty.size(); i++)
    EXPECT_EQ(orig_empty[i], s21_empty[i]);
}
