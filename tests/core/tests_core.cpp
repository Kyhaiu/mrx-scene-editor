#include <gtest/gtest.h>
#include <core/vector.hpp>

// // Test Certdsa fixture
// class LibTest : public ::testing::Test
// {
// protected:
//   const std::string expected = "test";

//   void SetUp() override {}
// };

// TEST_F(LibTest, test_cert_dsa_512b)
// {
//   // Arrange
//   const std::string actual = lib::test();

//   // Act
//   const bool result = (actual == expected);

//   // Expect
//   EXPECT_TRUE(result);
// }

class VectorTest : public ::testing::Test
{
protected:
  vector::Vector *vector_expected = new vector::Vector(1.0, 2.0, 3.0, 4.0, nullptr);

  void SetUp() override {}
};

TEST_F(VectorTest, test_cert_dsa_512b)
{
  // Arrange
  const double expected_X = 1.0;
  const double expected_Y = 2.0;
  const double expected_Z = 3.0;
  const double expected_H = 4.0;
  const std::nullptr_t expected_halfedge = nullptr;

  // Act
  const double actual_X = vector_expected->getX();
  const double actual_Y = vector_expected->getY();
  const double actual_Z = vector_expected->getZ();
  const double actual_H = vector_expected->getH();
  const std::nullptr_t actual_halfedge = vector_expected->getHalfEdge();

  // Expect
  EXPECT_EQ(actual_X, expected_X);
  EXPECT_EQ(actual_Y, expected_Y);
  EXPECT_EQ(actual_Z, expected_Z);
  EXPECT_EQ(actual_H, expected_H);
  EXPECT_EQ(actual_halfedge, expected_halfedge);
}
