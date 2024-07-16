#include "tests.h"

class VectorTests : public testing::Test {
 protected:
  std::vector<int> orig_empty;
  s21::vector<int> s21_empty;
  std::vector<int> orig_vector = {1, 2, 3, 4, 5, 6, 7};
  s21::vector<int> s21_vector = {1, 2, 3, 4, 5, 6, 7};

  s21::vector<int>::iterator iter_b = s21_vector.begin();
  s21::vector<int>::iterator iter_e = s21_vector.end();
  std::vector<int>::iterator iter_orig_b = orig_vector.begin();
  std::vector<int>::iterator iter_orig_e = orig_vector.end();

  s21::vector<int>::const_iterator citer_b = s21_vector.cbegin();
  s21::vector<int>::const_iterator citer_e = s21_vector.cend();
  std::vector<int>::const_iterator citer_orig_b = orig_vector.begin();
  std::vector<int>::const_iterator citer_orig_e = orig_vector.end();
};

class VectorTestsStrings : public testing::Test {
 protected:
  std::vector<std::string> orig_empty;
  s21::vector<std::string> s21_empty;
  std::vector<std::string> orig_vector = {"111",    "2 2 2",   "333", "444",
                                          "555555", "6666 66", "77"};
  s21::vector<std::string> s21_vector = {"111",    "2 2 2",   "333", "444",
                                         "555555", "6666 66", "77"};

  s21::vector<std::string>::iterator iter_b = s21_vector.begin();
  s21::vector<std::string>::iterator iter_e = s21_vector.end();
  std::vector<std::string>::iterator iter_orig_b = orig_vector.begin();
  std::vector<std::string>::iterator iter_orig_e = orig_vector.end();

  s21::vector<std::string>::const_iterator citer_b = s21_vector.cbegin();
  s21::vector<std::string>::const_iterator citer_e = s21_vector.cend();
  std::vector<std::string>::const_iterator citer_orig_b = orig_vector.begin();
  std::vector<std::string>::const_iterator citer_orig_e = orig_vector.end();
};

TEST_F(VectorTests, ConstructorTest0) {
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
  EXPECT_EQ(s21_empty.capacity(), orig_empty.capacity());
  EXPECT_EQ(s21_empty.data(), orig_empty.data());
  EXPECT_TRUE(s21_empty.data() == nullptr);
}

TEST_F(VectorTests, ConstructorTest1) {
  s21::vector<int> test_v(5);
  std::vector<int> orig_v(5);
  EXPECT_EQ(test_v.size(), orig_v.size());
  EXPECT_EQ(test_v.capacity(), orig_v.capacity());
  EXPECT_TRUE(test_v.data() != nullptr);
}

TEST_F(VectorTests, ConstructorTest2) {
  std::vector<int> orig_v = {7, 8, 9};
  s21::vector<int> test_v = {7, 8, 9};
  EXPECT_EQ(test_v.size(), orig_v.size());
  EXPECT_EQ(test_v.capacity(), orig_v.capacity());
  for (size_t i = 0; i < orig_v.size(); i++) EXPECT_EQ(orig_v[i], test_v[i]);
}

TEST_F(VectorTests, CopyTest0) {
  s21::vector<int> copy_v = s21_vector;
  EXPECT_EQ(copy_v.size(), s21_vector.size());
  EXPECT_EQ(copy_v.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < s21_vector.size(); i++)
    EXPECT_EQ(copy_v[i], s21_vector[i]);
}

TEST_F(VectorTests, CopyTest1) {
  s21::vector<int> copy_v = s21_empty;
  EXPECT_EQ(copy_v.size(), s21_empty.size());
  EXPECT_EQ(copy_v.capacity(), s21_empty.capacity());
  for (size_t i = 0; i < s21_empty.size(); i++)
    EXPECT_EQ(copy_v[i], s21_empty[i]);
}

TEST_F(VectorTests, MoveTest0) {
  s21::vector<int> copy_v = s21_vector;
  s21::vector<int> moved_v = std::move(s21_vector);
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.capacity(), 0);
  EXPECT_EQ(s21_vector.data(), nullptr);

  EXPECT_EQ(moved_v.size(), copy_v.size());
  EXPECT_EQ(moved_v.capacity(), copy_v.capacity());
  for (size_t i = 0; i < copy_v.size(); i++) EXPECT_EQ(copy_v[i], moved_v[i]);
}

TEST_F(VectorTests, MoveTest1) {
  s21::vector<int> copy_v = s21_empty;
  s21::vector<int> moved_v = std::move(s21_empty);
  EXPECT_EQ(s21_empty.size(), 0);
  EXPECT_EQ(s21_empty.capacity(), 0);
  EXPECT_EQ(s21_empty.data(), nullptr);

  EXPECT_EQ(moved_v.size(), copy_v.size());
  EXPECT_EQ(moved_v.capacity(), copy_v.capacity());
  for (size_t i = 0; i < copy_v.size(); i++) EXPECT_EQ(copy_v[i], moved_v[i]);
}

TEST_F(VectorTests, MoveOperatorTest0) {
  s21::vector<int> copy_v = s21_vector;
  s21::vector<int> moved_v = {90, 80, 45};
  moved_v = std::move(s21_vector);

  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.capacity(), 0);
  EXPECT_EQ(s21_vector.data(), nullptr);

  EXPECT_EQ(moved_v.size(), copy_v.size());
  EXPECT_EQ(moved_v.capacity(), copy_v.capacity());
  for (size_t i = 0; i < copy_v.size(); i++) EXPECT_EQ(copy_v[i], moved_v[i]);
}

TEST_F(VectorTests, MoveOperatorTest1) {
  s21::vector<int> copy_v = s21_empty;
  s21::vector<int> moved_v = {90, 80, 45};
  moved_v = std::move(s21_empty);

  EXPECT_EQ(s21_empty.size(), 0);
  EXPECT_EQ(s21_empty.capacity(), 0);
  EXPECT_EQ(s21_empty.data(), nullptr);

  EXPECT_EQ(moved_v.size(), copy_v.size());
  EXPECT_EQ(moved_v.capacity(), copy_v.capacity());
  for (size_t i = 0; i < copy_v.size(); i++) EXPECT_EQ(copy_v[i], moved_v[i]);
}

TEST_F(VectorTests, ElemAccess0) {
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTests, ElemAccess1) {
  for (size_t i = 0; i < orig_vector.size(); i++) {
    orig_vector[i] = i * 100;
    s21_vector[i] = i * 100;
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
  }
  orig_vector[3] = 7000045;
  s21_vector[3] = 7000045;
  EXPECT_EQ(orig_vector[3], s21_vector[3]);
}

TEST_F(VectorTests, AtTest0) {
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTests, AtTest1) {
  s21_vector.at(0) = 234;
  orig_vector.at(0) = 234;
  s21_vector.at(3) = 100000;
  orig_vector.at(3) = 100000;
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTests, AtTest2) {
  EXPECT_THROW(orig_vector.at(7), std::out_of_range);
  EXPECT_THROW(s21_vector.at(7), std::out_of_range);
  EXPECT_THROW(orig_vector.at(10), std::out_of_range);
  EXPECT_THROW(s21_vector.at(10), std::out_of_range);
}

TEST_F(VectorTests, FrontTest) {
  EXPECT_EQ(s21_vector.front(), orig_vector.front());
}

TEST_F(VectorTests, BackTest) {
  EXPECT_EQ(s21_vector.back(), orig_vector.back());
}

TEST_F(VectorTests, DataTest) {
  EXPECT_EQ(*(s21_vector.data()), *(orig_vector.data()));
}

TEST_F(VectorTests, BeginTest) {
  EXPECT_EQ(*(orig_vector.begin()), *(s21_vector.begin()));
}

TEST_F(VectorTests, EndTest) {
  EXPECT_EQ(*(--orig_vector.end()), *(--s21_vector.end()));
}

TEST_F(VectorTests, EmptyTest) {
  EXPECT_TRUE(s21_empty.empty());
  EXPECT_FALSE(s21_vector.empty());
}

TEST_F(VectorTests, SizeTest) {
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  s21_vector.push_back(100);
  orig_vector.push_back(100);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
}

TEST_F(VectorTests, MaxSizeTest) {
  EXPECT_EQ(s21_vector.max_size(), orig_vector.max_size());
  s21::vector<char> s21_char;
  std::vector<char> orig_char;
  EXPECT_EQ(s21_char.max_size(), orig_char.max_size());
}

TEST_F(VectorTests, ReserveTest0) {
  orig_vector.reserve(10);
  s21_vector.reserve(10);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(12);
  s21_vector.reserve(12);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(11);
  s21_vector.reserve(11);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(20);
  s21_vector.reserve(20);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(2);
  s21_vector.reserve(2);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTests, ReserveTest1) {
  orig_empty.reserve(4);
  s21_empty.reserve(4);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.reserve(2);
  s21_empty.reserve(2);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.reserve(7);
  s21_empty.reserve(7);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
}

TEST_F(VectorTests, ReserveTest2) {
  EXPECT_THROW(s21_vector.reserve(s21_vector.max_size() + 1),
               std::length_error);
}

TEST_F(VectorTests, CapacityTest) {
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
  s21_vector.reserve(20);
  orig_vector.reserve(20);
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
  EXPECT_EQ(s21_empty.capacity(), orig_empty.capacity());
}

TEST_F(VectorTests, ShrinkToFitTest0) {
  orig_vector.reserve(10);
  s21_vector.reserve(10);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.shrink_to_fit();
  s21_vector.shrink_to_fit();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.shrink_to_fit();
  s21_vector.shrink_to_fit();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(30);
  s21_vector.reserve(30);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTests, ShrinkToFitTest1) {
  orig_empty.reserve(4);
  s21_empty.reserve(4);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.shrink_to_fit();
  s21_empty.shrink_to_fit();
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.shrink_to_fit();
  s21_empty.shrink_to_fit();
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.reserve(7);
  s21_empty.reserve(7);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.shrink_to_fit();
  s21_empty.shrink_to_fit();
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
}

TEST_F(VectorTests, ClearTest0) {
  orig_vector.clear();
  s21_vector.clear();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTests, ClearTest1) {
  orig_empty.clear();
  s21_empty.clear();
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
}

TEST_F(VectorTests, InsertTest0) {
  s21_vector.reserve(10);
  orig_vector.reserve(10);

  s21::vector<int>::iterator a = s21_vector.insert(s21_vector.end(), 450);
  std::vector<int>::iterator b = orig_vector.insert(orig_vector.end(), 450);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, InsertTest1) {
  s21_vector.reserve(10);
  orig_vector.reserve(10);

  s21::vector<int>::iterator a = s21_vector.insert(--s21_vector.end(), 450);
  std::vector<int>::iterator b = orig_vector.insert(--orig_vector.end(), 450);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, InsertTest2) {
  s21_vector.reserve(10);
  orig_vector.reserve(10);

  s21::vector<int>::iterator a = s21_vector.insert(s21_vector.begin(), 450);
  std::vector<int>::iterator b = orig_vector.insert(orig_vector.begin(), 450);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, InsertTest3) {
  for (int i = 0; i < 4; i++) {
    iter_b++;
    iter_orig_b++;
  }

  s21::vector<int>::iterator a = s21_vector.insert(iter_b, 450);
  std::vector<int>::iterator b = orig_vector.insert(iter_orig_b, 450);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, InsertTest4) {
  s21::vector<int>::iterator a = s21_vector.insert(iter_b, 450);
  std::vector<int>::iterator b = orig_vector.insert(iter_orig_b, 450);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, InsertTest5) {
  s21::vector<int>::iterator a = s21_vector.insert(iter_e, 450);
  std::vector<int>::iterator b = orig_vector.insert(iter_orig_e, 450);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, InsertTest6) {
  std::vector<int>::iterator a = orig_empty.insert(orig_empty.end(), 450);
  s21::vector<int>::iterator b = s21_empty.insert(s21_empty.end(), 450);

  for (size_t i = 0; i < orig_empty.size(); i++)
    EXPECT_EQ(s21_empty[i], orig_empty[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
  EXPECT_EQ(s21_empty.capacity(), orig_empty.capacity());

  orig_empty.insert(orig_empty.end(), 560);
  s21_empty.insert(s21_empty.end(), 560);
}

TEST_F(VectorTests, EraseTest0) {
  orig_vector.erase(iter_orig_b);
  s21_vector.erase(iter_b);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, EraseTest1) {
  orig_vector.erase(++iter_orig_b);
  s21_vector.erase(++iter_b);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, EraseTest2) {
  orig_vector.erase(--iter_orig_e);
  s21_vector.erase(--iter_e);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTests, PushBack0) {
  orig_vector.push_back(200);
  s21_vector.push_back(200);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.push_back(0);
  s21_vector.push_back(0);
  orig_vector.push_back(4678);
  s21_vector.push_back(4678);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTests, PushBack1) {
  orig_empty.push_back(90);
  s21_empty.push_back(90);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
  for (size_t i = 0; i < orig_empty.size(); i++)
    EXPECT_EQ(orig_empty[i], s21_empty[i]);

  orig_empty.push_back(9000);
  s21_empty.push_back(9000);
  orig_empty.push_back(123);
  s21_empty.push_back(123);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
  for (size_t i = 0; i < orig_empty.size(); i++)
    EXPECT_EQ(orig_empty[i], s21_empty[i]);
}

TEST_F(VectorTests, PopBack1) {
  orig_vector.pop_back();
  s21_vector.pop_back();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.pop_back();
  s21_vector.pop_back();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  for (int i = 0; i < 5; i++) {
    orig_vector.pop_back();
    s21_vector.pop_back();
  }

  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTests, SwapTest0) {
  s21::vector<int> test_v = {20000, 345};
  s21::vector<int> test_copy = test_v;
  s21::vector<int> s21_copy = s21_vector;
  s21_vector.swap(test_v);

  EXPECT_EQ(s21_vector.size(), test_copy.size());
  EXPECT_EQ(s21_vector.capacity(), test_copy.capacity());
  for (size_t i = 0; i < s21_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], test_copy[i]);

  EXPECT_EQ(test_v.size(), s21_copy.size());
  EXPECT_EQ(test_v.capacity(), s21_copy.capacity());
  for (size_t i = 0; i < test_v.size(); i++) EXPECT_EQ(test_v[i], s21_copy[i]);
}

TEST_F(VectorTests, SwapTest1) {
  s21::vector<int> test_v;
  s21::vector<int> test_copy = test_v;
  s21::vector<int> s21_copy = s21_vector;
  s21_vector.swap(test_v);

  EXPECT_EQ(s21_vector.size(), test_copy.size());
  EXPECT_EQ(s21_vector.capacity(), test_copy.capacity());
  for (size_t i = 0; i < s21_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], test_copy[i]);

  EXPECT_EQ(test_v.size(), s21_copy.size());
  EXPECT_EQ(test_v.capacity(), s21_copy.capacity());
  for (size_t i = 0; i < test_v.size(); i++) EXPECT_EQ(test_v[i], s21_copy[i]);
}

TEST_F(VectorTests, IterConstructorTest) {
  s21::vector<int>::iterator iter;
  EXPECT_TRUE(iter == nullptr);
  EXPECT_EQ(*iter_b, s21_vector.front());
  EXPECT_EQ(*(--iter_e), s21_vector.back());

  s21::vector<int>::iterator iter2(++iter_b);
  EXPECT_EQ(*iter2, s21_vector[1]);
}

TEST_F(VectorTests, IterOperationsTest0) {
  EXPECT_EQ(*(++iter_b), s21_vector[1]);
  EXPECT_EQ(*(iter_b), s21_vector[1]);
  EXPECT_EQ(*(iter_b++), s21_vector[1]);
  EXPECT_EQ(*(iter_b), s21_vector[2]);

  EXPECT_EQ(*(--iter_e), s21_vector[6]);
  EXPECT_EQ(*(iter_e), s21_vector[6]);
  EXPECT_EQ(*(iter_e--), s21_vector[6]);
  EXPECT_EQ(*(iter_e), s21_vector[5]);

  EXPECT_TRUE(iter_e != iter_b);
  iter_e = iter_b;
  EXPECT_TRUE(iter_e == iter_b);
}

TEST_F(VectorTests, IterOperationsTest1) {
  EXPECT_EQ(iter_e - iter_b, iter_orig_e - iter_orig_b);
  iter_b++;
  iter_orig_b++;
  EXPECT_EQ(iter_e - iter_b, iter_orig_e - iter_orig_b);
}

TEST_F(VectorTests, IterOperationsTest2) {
  *iter_b = 7000;
  EXPECT_EQ(s21_vector[0], 7000);
}

TEST_F(VectorTests, ConstIterConstructTest0) {
  s21::vector<int>::const_iterator iter;
  EXPECT_TRUE(iter == nullptr);

  EXPECT_EQ(*citer_b, s21_vector.front());
  EXPECT_EQ(*(--citer_e), s21_vector.back());

  citer_b++;
  EXPECT_EQ(*citer_b, s21_vector[1]);
}

TEST_F(VectorTests, ConstIterOperationsTest0) {
  EXPECT_EQ(*(++citer_b), s21_vector[1]);
  EXPECT_EQ(*(citer_b), s21_vector[1]);
  EXPECT_EQ(*(citer_b++), s21_vector[1]);
  EXPECT_EQ(*(citer_b), s21_vector[2]);

  EXPECT_EQ(*(--citer_e), s21_vector[6]);
  EXPECT_EQ(*(citer_e), s21_vector[6]);
  EXPECT_EQ(*(citer_e--), s21_vector[6]);
  EXPECT_EQ(*(citer_e), s21_vector[5]);

  EXPECT_TRUE(citer_e != citer_b);
  citer_e = citer_b;
  EXPECT_TRUE(citer_e == citer_b);
}

TEST_F(VectorTests, ConstIterOperationsTest1) {
  EXPECT_EQ(citer_e - citer_b, citer_orig_e - citer_orig_b);
  citer_b++;
  citer_orig_b++;
  EXPECT_EQ(citer_e - citer_b, citer_orig_e - citer_orig_b);
}

TEST_F(VectorTestsStrings, ConstructorTest0) {
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
  EXPECT_EQ(s21_empty.capacity(), orig_empty.capacity());
  EXPECT_EQ(s21_empty.data(), orig_empty.data());
  EXPECT_TRUE(s21_empty.data() == nullptr);
}

TEST_F(VectorTestsStrings, ConstructorTest1) {
  s21::vector<std::string> test_v(5);
  std::vector<std::string> orig_v(5);
  EXPECT_EQ(test_v.size(), orig_v.size());
  EXPECT_EQ(test_v.capacity(), orig_v.capacity());
  EXPECT_TRUE(test_v.data() != nullptr);
}

TEST_F(VectorTestsStrings, ConstructorTest2) {
  std::vector<std::string> orig_v = {"west", "east", "north"};
  s21::vector<std::string> test_v = {"west", "east", "north"};
  EXPECT_EQ(test_v.size(), orig_v.size());
  EXPECT_EQ(test_v.capacity(), orig_v.capacity());
  for (size_t i = 0; i < orig_v.size(); i++) EXPECT_EQ(orig_v[i], test_v[i]);
}

TEST_F(VectorTestsStrings, CopyTest0) {
  s21::vector<std::string> copy_v = s21_vector;
  EXPECT_EQ(copy_v.size(), s21_vector.size());
  EXPECT_EQ(copy_v.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < s21_vector.size(); i++)
    EXPECT_EQ(copy_v[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, CopyTest1) {
  s21::vector<std::string> copy_v = s21_empty;
  EXPECT_EQ(copy_v.size(), s21_empty.size());
  EXPECT_EQ(copy_v.capacity(), s21_empty.capacity());
  for (size_t i = 0; i < s21_empty.size(); i++)
    EXPECT_EQ(copy_v[i], s21_empty[i]);
}

TEST_F(VectorTestsStrings, MoveTest0) {
  s21::vector<std::string> copy_v = s21_vector;
  s21::vector<std::string> moved_v = std::move(s21_vector);
  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.capacity(), 0);
  EXPECT_EQ(s21_vector.data(), nullptr);

  EXPECT_EQ(moved_v.size(), copy_v.size());
  EXPECT_EQ(moved_v.capacity(), copy_v.capacity());
  for (size_t i = 0; i < copy_v.size(); i++) EXPECT_EQ(copy_v[i], moved_v[i]);
}

TEST_F(VectorTestsStrings, MoveTest1) {
  s21::vector<std::string> copy_v = s21_empty;
  s21::vector<std::string> moved_v = std::move(s21_empty);
  EXPECT_EQ(s21_empty.size(), 0);
  EXPECT_EQ(s21_empty.capacity(), 0);
  EXPECT_EQ(s21_empty.data(), nullptr);

  EXPECT_EQ(moved_v.size(), copy_v.size());
  EXPECT_EQ(moved_v.capacity(), copy_v.capacity());
  for (size_t i = 0; i < copy_v.size(); i++) EXPECT_EQ(copy_v[i], moved_v[i]);
}

TEST_F(VectorTestsStrings, MoveOperatorTest0) {
  s21::vector<std::string> copy_v = s21_vector;
  s21::vector<std::string> moved_v = {"wanna", "die", ";)"};
  moved_v = std::move(s21_vector);

  EXPECT_EQ(s21_vector.size(), 0);
  EXPECT_EQ(s21_vector.capacity(), 0);
  EXPECT_EQ(s21_vector.data(), nullptr);

  EXPECT_EQ(moved_v.size(), copy_v.size());
  EXPECT_EQ(moved_v.capacity(), copy_v.capacity());
  for (size_t i = 0; i < copy_v.size(); i++) EXPECT_EQ(copy_v[i], moved_v[i]);
}

TEST_F(VectorTestsStrings, MoveOperatorTest1) {
  s21::vector<std::string> copy_v = s21_empty;
  s21::vector<std::string> moved_v = {"wanna", "die", ";)"};
  moved_v = std::move(s21_empty);

  EXPECT_EQ(s21_empty.size(), 0);
  EXPECT_EQ(s21_empty.capacity(), 0);
  EXPECT_EQ(s21_empty.data(), nullptr);

  EXPECT_EQ(moved_v.size(), copy_v.size());
  EXPECT_EQ(moved_v.capacity(), copy_v.capacity());
  for (size_t i = 0; i < copy_v.size(); i++) EXPECT_EQ(copy_v[i], moved_v[i]);
}

TEST_F(VectorTestsStrings, ElemAccess0) {
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, ElemAccess1) {
  for (size_t i = 0; i < orig_vector.size(); i++) {
    orig_vector[i] = "zhopa";
    s21_vector[i] = "zhopa";
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
  }
  orig_vector[3] = "helloworld";
  s21_vector[3] = "helloworld";
  EXPECT_EQ(orig_vector[3], s21_vector[3]);
}

TEST_F(VectorTestsStrings, AtTest0) {
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, AtTest1) {
  s21_vector.at(0) = "aaa";
  orig_vector.at(0) = "aaa";
  s21_vector.at(3) = "qqqqqqq";
  orig_vector.at(3) = "qqqqqqq";
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, AtTest2) {
  EXPECT_THROW(orig_vector.at(7), std::out_of_range);
  EXPECT_THROW(s21_vector.at(7), std::out_of_range);
  EXPECT_THROW(orig_vector.at(10), std::out_of_range);
  EXPECT_THROW(s21_vector.at(10), std::out_of_range);
}

TEST_F(VectorTestsStrings, FrontTest) {
  EXPECT_EQ(s21_vector.front(), orig_vector.front());
}

TEST_F(VectorTestsStrings, BackTest) {
  EXPECT_EQ(s21_vector.back(), orig_vector.back());
}

TEST_F(VectorTestsStrings, DataTest) {
  EXPECT_EQ(*(s21_vector.data()), *(orig_vector.data()));
}

TEST_F(VectorTestsStrings, BeginTest) {
  EXPECT_EQ(*(orig_vector.begin()), *(s21_vector.begin()));
}

TEST_F(VectorTestsStrings, EndTest) {
  EXPECT_EQ(*(--orig_vector.end()), *(--s21_vector.end()));
}

TEST_F(VectorTestsStrings, EmptyTest) {
  EXPECT_TRUE(s21_empty.empty());
  EXPECT_FALSE(s21_vector.empty());
}

TEST_F(VectorTestsStrings, SizeTest) {
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  s21_vector.push_back("qqqqqqq");
  orig_vector.push_back("qqqqqqq");
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
}

TEST_F(VectorTestsStrings, MaxSizeTest) {
  EXPECT_EQ(s21_vector.max_size(), orig_vector.max_size());
  s21::vector<char> s21_char;
  std::vector<char> orig_char;
  EXPECT_EQ(s21_char.max_size(), orig_char.max_size());
}

TEST_F(VectorTestsStrings, ReserveTest0) {
  orig_vector.reserve(10);
  s21_vector.reserve(10);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(12);
  s21_vector.reserve(12);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(11);
  s21_vector.reserve(11);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(20);
  s21_vector.reserve(20);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(2);
  s21_vector.reserve(2);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, ReserveTest1) {
  orig_empty.reserve(4);
  s21_empty.reserve(4);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.reserve(2);
  s21_empty.reserve(2);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.reserve(7);
  s21_empty.reserve(7);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
}

TEST_F(VectorTestsStrings, ReserveTest2) {
  EXPECT_THROW(s21_vector.reserve(s21_vector.max_size() + 1),
               std::length_error);
}

TEST_F(VectorTestsStrings, CapacityTest) {
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
  s21_vector.reserve(20);
  orig_vector.reserve(20);
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
  EXPECT_EQ(s21_empty.capacity(), orig_empty.capacity());
}

TEST_F(VectorTestsStrings, ShrinkToFitTest0) {
  orig_vector.reserve(10);
  s21_vector.reserve(10);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.shrink_to_fit();
  s21_vector.shrink_to_fit();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.shrink_to_fit();
  s21_vector.shrink_to_fit();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.reserve(30);
  s21_vector.reserve(30);
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, ShrinkToFitTest1) {
  orig_empty.reserve(4);
  s21_empty.reserve(4);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.shrink_to_fit();
  s21_empty.shrink_to_fit();
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.shrink_to_fit();
  s21_empty.shrink_to_fit();
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.reserve(7);
  s21_empty.reserve(7);
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());

  orig_empty.shrink_to_fit();
  s21_empty.shrink_to_fit();
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
}

TEST_F(VectorTestsStrings, ClearTest0) {
  orig_vector.clear();
  s21_vector.clear();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, ClearTest1) {
  orig_empty.clear();
  s21_empty.clear();
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
}

TEST_F(VectorTestsStrings, InsertTest0) {
  s21_vector.reserve(10);
  orig_vector.reserve(10);

  iter_e = s21_vector.end();
  iter_orig_e = orig_vector.end();

  s21::vector<std::string>::iterator a =
      s21_vector.insert(iter_e, "lalalalalala!!");
  std::vector<std::string>::iterator b =
      orig_vector.insert(iter_orig_e, "lalalalalala!!");

  for (size_t i = 0; i < s21_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, InsertTest1) {
  s21_vector.reserve(10);
  orig_vector.reserve(10);

  s21::vector<std::string>::iterator a =
      s21_vector.insert(--s21_vector.end(), "lalalalalala!!");
  std::vector<std::string>::iterator b =
      orig_vector.insert(--orig_vector.end(), "lalalalalala!!");

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, InsertTest2) {
  s21_vector.reserve(10);
  orig_vector.reserve(10);

  s21::vector<std::string>::iterator a =
      s21_vector.insert(s21_vector.begin(), "lalalalalala!!");
  std::vector<std::string>::iterator b =
      orig_vector.insert(orig_vector.begin(), "lalalalalala!!");

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, InsertTest3) {
  for (int i = 0; i < 4; i++) {
    iter_b++;
    iter_orig_b++;
  }

  s21::vector<std::string>::iterator a =
      s21_vector.insert(iter_b, "guess what");
  std::vector<std::string>::iterator b =
      orig_vector.insert(iter_orig_b, "guess what");

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, InsertTest4) {
  s21::vector<std::string>::iterator a =
      s21_vector.insert(iter_b, "guess what");
  std::vector<std::string>::iterator b =
      orig_vector.insert(iter_orig_b, "guess what");

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, InsertTest5) {
  s21::vector<std::string>::iterator a =
      s21_vector.insert(iter_e, "guess what");
  std::vector<std::string>::iterator b =
      orig_vector.insert(iter_orig_e, "guess what");

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, InsertTest6) {
  std::vector<std::string>::iterator a =
      orig_empty.insert(orig_empty.end(), "guess what");
  s21::vector<std::string>::iterator b =
      s21_empty.insert(s21_empty.end(), "guess what");

  for (size_t i = 0; i < orig_empty.size(); i++)
    EXPECT_EQ(s21_empty[i], orig_empty[i]);
  EXPECT_EQ(*a, *b);
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
  EXPECT_EQ(s21_empty.capacity(), orig_empty.capacity());

  orig_empty.insert(orig_empty.end(), "hihihaha");
  s21_empty.insert(s21_empty.end(), "hihihaha");
}

TEST_F(VectorTestsStrings, EraseTest0) {
  orig_vector.erase(iter_orig_b);
  s21_vector.erase(iter_b);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, EraseTest1) {
  orig_vector.erase(++iter_orig_b);
  s21_vector.erase(++iter_b);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, EraseTest2) {
  orig_vector.erase(--iter_orig_e);
  s21_vector.erase(--iter_e);

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  EXPECT_EQ(s21_vector.capacity(), orig_vector.capacity());
}

TEST_F(VectorTestsStrings, PushBack0) {
  orig_vector.push_back("holy crap");
  s21_vector.push_back("holy crap");
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.push_back("zzz");
  s21_vector.push_back("zzz");
  orig_vector.push_back("xxxxxx");
  s21_vector.push_back("xxxxxx");
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, PushBack1) {
  orig_empty.push_back("plants vs zombies?!");
  s21_empty.push_back("plants vs zombies?!");
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
  for (size_t i = 0; i < orig_empty.size(); i++)
    EXPECT_EQ(orig_empty[i], s21_empty[i]);

  orig_empty.push_back("hm");
  s21_empty.push_back("hm");
  orig_empty.push_back("hmmm");
  s21_empty.push_back("hmmm");
  EXPECT_EQ(orig_empty.size(), s21_empty.size());
  EXPECT_EQ(orig_empty.capacity(), s21_empty.capacity());
  for (size_t i = 0; i < orig_empty.size(); i++)
    EXPECT_EQ(orig_empty[i], s21_empty[i]);
}

TEST_F(VectorTestsStrings, PopBack1) {
  orig_vector.pop_back();
  s21_vector.pop_back();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  orig_vector.pop_back();
  s21_vector.pop_back();
  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);

  for (int i = 0; i < 3; i++) {
    orig_vector.pop_back();
    s21_vector.pop_back();
  }

  EXPECT_EQ(orig_vector.size(), s21_vector.size());
  EXPECT_EQ(orig_vector.capacity(), s21_vector.capacity());

  for (size_t i = 0; i < orig_vector.size(); i++)
    EXPECT_EQ(orig_vector[i], s21_vector[i]);
}

TEST_F(VectorTestsStrings, SwapTest0) {
  s21::vector<std::string> test_v = {"west", "east", "north"};
  s21::vector<std::string> test_copy = test_v;
  s21::vector<std::string> s21_copy = s21_vector;
  s21_vector.swap(test_v);

  EXPECT_EQ(s21_vector.size(), test_copy.size());
  EXPECT_EQ(s21_vector.capacity(), test_copy.capacity());
  for (size_t i = 0; i < s21_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], test_copy[i]);

  EXPECT_EQ(test_v.size(), s21_copy.size());
  EXPECT_EQ(test_v.capacity(), s21_copy.capacity());
  for (size_t i = 0; i < test_v.size(); i++) EXPECT_EQ(test_v[i], s21_copy[i]);
}

TEST_F(VectorTestsStrings, SwapTest1) {
  s21::vector<std::string> test_v;
  s21::vector<std::string> test_copy = test_v;
  s21::vector<std::string> s21_copy = s21_vector;
  s21_vector.swap(test_v);

  EXPECT_EQ(s21_vector.size(), test_copy.size());
  EXPECT_EQ(s21_vector.capacity(), test_copy.capacity());
  for (size_t i = 0; i < s21_vector.size(); i++)
    EXPECT_EQ(s21_vector[i], test_copy[i]);

  EXPECT_EQ(test_v.size(), s21_copy.size());
  EXPECT_EQ(test_v.capacity(), s21_copy.capacity());
  for (size_t i = 0; i < test_v.size(); i++) EXPECT_EQ(test_v[i], s21_copy[i]);
}

TEST_F(VectorTestsStrings, IterConstructorTest) {
  s21::vector<std::string>::iterator iter;
  EXPECT_TRUE(iter == nullptr);
  EXPECT_EQ(*iter_b, s21_vector.front());
  EXPECT_EQ(*(--iter_e), s21_vector.back());

  s21::vector<std::string>::iterator iter2(++iter_b);
  EXPECT_EQ(*iter2, s21_vector[1]);
}

TEST_F(VectorTestsStrings, IterOperationsTest0) {
  EXPECT_EQ(*(++iter_b), s21_vector[1]);
  EXPECT_EQ(*(iter_b), s21_vector[1]);
  EXPECT_EQ(*(iter_b++), s21_vector[1]);
  EXPECT_EQ(*(iter_b), s21_vector[2]);

  EXPECT_EQ(*(--iter_e), s21_vector[6]);
  EXPECT_EQ(*(iter_e), s21_vector[6]);
  EXPECT_EQ(*(iter_e--), s21_vector[6]);
  EXPECT_EQ(*(iter_e), s21_vector[5]);

  EXPECT_TRUE(iter_e != iter_b);
  iter_e = iter_b;
  EXPECT_TRUE(iter_e == iter_b);
}

TEST_F(VectorTestsStrings, IterOperationsTest1) {
  EXPECT_EQ(iter_e - iter_b, iter_orig_e - iter_orig_b);
  iter_b++;
  iter_orig_b++;
  EXPECT_EQ(iter_e - iter_b, iter_orig_e - iter_orig_b);
}

TEST_F(VectorTestsStrings, IterOperationsTest2) {
  *iter_b = "just kidding ;)";
  EXPECT_EQ(s21_vector[0], "just kidding ;)");
}

TEST_F(VectorTests, VectorOfVectors) {
  s21::vector<s21::vector<int>> vv = {{1, 2, 3}, {4, 5}};
  std::vector<std::vector<int>> orig_vv = {{1, 2, 3}, {4, 5}};
  EXPECT_EQ(vv.size(), orig_vv.size());
  EXPECT_EQ(vv.capacity(), orig_vv.capacity());
  for (size_t i = 0; i < orig_vv.size(); i++) {
    for (size_t j = 0; j < orig_vv[i].size(); j++) {
      EXPECT_EQ(vv[i][j], orig_vv[i][j]);
    }
  }
}

TEST_F(VectorTests, CopyOperatorTest0) {
  s21_empty = s21_vector;
  EXPECT_EQ(s21_empty.size(), s21_vector.size());
  EXPECT_EQ(s21_empty.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < s21_empty.size(); i++) {
    EXPECT_EQ(s21_empty[i], s21_vector[i]);
  }
}

TEST_F(VectorTests, CopyOperatorTest1) {
  s21_vector = s21_empty;
  EXPECT_EQ(s21_empty.size(), s21_vector.size());
  EXPECT_EQ(s21_empty.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < s21_empty.size(); i++) {
    EXPECT_EQ(s21_empty[i], s21_vector[i]);
  }
}

TEST_F(VectorTestsStrings, CopyOperatorTest0) {
  s21_empty = s21_vector;
  EXPECT_EQ(s21_empty.size(), s21_vector.size());
  EXPECT_EQ(s21_empty.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < s21_empty.size(); i++) {
    EXPECT_EQ(s21_empty[i], s21_vector[i]);
  }
}

TEST_F(VectorTestsStrings, CopyOperatorTest1) {
  s21_vector = s21_empty;
  EXPECT_EQ(s21_empty.size(), s21_vector.size());
  EXPECT_EQ(s21_empty.capacity(), s21_vector.capacity());
  for (size_t i = 0; i < s21_empty.size(); i++) {
    EXPECT_EQ(s21_empty[i], s21_vector[i]);
  }
}

TEST_F(VectorTests, insertBackTest0) {
  s21_vector.insert_many_back(700, 800, 900);
  orig_vector.push_back(700);
  orig_vector.push_back(800);
  orig_vector.push_back(900);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  }
}

TEST_F(VectorTests, insertBackTest1) {
  s21_vector.insert_many_back(700);
  orig_vector.push_back(700);
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  }
}

TEST_F(VectorTests, insertBackTest2) {
  s21_vector.insert_many_back();
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  }
}

TEST_F(VectorTests, insertBackTest3) {
  s21_empty.insert_many_back();
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
  for (size_t i = 0; i < s21_empty.size(); i++) {
    EXPECT_EQ(s21_empty[i], orig_empty[i]);
  }
}

TEST_F(VectorTests, insertBackTest4) {
  s21_empty.insert_many_back(700, 800, 900);
  orig_empty.push_back(700);
  orig_empty.push_back(800);
  orig_empty.push_back(900);
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
  for (size_t i = 0; i < s21_empty.size(); i++) {
    EXPECT_EQ(s21_empty[i], orig_empty[i]);
  }
}

TEST_F(VectorTestsStrings, insertBackTest0) {
  s21_vector.insert_many_back("700", "800", "900");
  orig_vector.push_back("700");
  orig_vector.push_back("800");
  orig_vector.push_back("900");
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  }
}

TEST_F(VectorTestsStrings, insertBackTest1) {
  s21_vector.insert_many_back("700");
  orig_vector.push_back("700");
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  }
}

TEST_F(VectorTestsStrings, insertBackTest2) {
  s21_vector.insert_many_back();
  EXPECT_EQ(s21_vector.size(), orig_vector.size());
  for (size_t i = 0; i < s21_vector.size(); i++) {
    EXPECT_EQ(s21_vector[i], orig_vector[i]);
  }
}

TEST_F(VectorTestsStrings, insertBackTest3) {
  s21_empty.insert_many_back("800000");
  orig_empty.push_back("800000");
  EXPECT_EQ(s21_empty.size(), orig_empty.size());
  for (size_t i = 0; i < s21_empty.size(); i++) {
    EXPECT_EQ(s21_empty[i], orig_empty[i]);
  }
}
