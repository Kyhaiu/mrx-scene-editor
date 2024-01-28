#include <gtest/gtest.h>
#include <core/vector.hpp>
#include <iostream>
#include <string>

class VectorTest : public ::testing::Test
{
protected:
  Core::Vector *base_vector = new Core::Vector(0.0, 0.0, 0.0, 0.0, nullptr, "v0");

  void SetUp() override {}
};

/**
 * @brief Test case for the default constructor of a Vector class.
 *
 */
TEST_F(VectorTest, default_vector_constructor)
{
  // Arrange
  const double expected_X = 0.0;
  const double expected_Y = 0.0;
  const double expected_Z = 0.0;
  const double expected_H = 0.0;
  const std::nullptr_t expected_halfedge = nullptr;
  const std::string expected_id = "";

  // Act
  Core::Vector *canonical_vector = new Core::Vector();

  // Expect
  EXPECT_EQ(canonical_vector->getX(), expected_X);
  EXPECT_EQ(canonical_vector->getY(), expected_Y);
  EXPECT_EQ(canonical_vector->getZ(), expected_Z);
  EXPECT_EQ(canonical_vector->getH(), expected_H);
  EXPECT_EQ(canonical_vector->getHalfEdge(), expected_halfedge);
  EXPECT_EQ(canonical_vector->getId(), expected_id);
}

/**
 * @brief Test case for the parametrized constructor of a Vector class.
 *
 */
TEST_F(VectorTest, parametrized_vector_constructor)
{
  // Arrange
  const double expected_X = 1.0;
  const double expected_Y = 2.0;
  const double expected_Z = 3.0;
  const double expected_H = 4.0;
  const std::nullptr_t expected_halfedge = nullptr;
  const std::string expected_id = "v0";

  // Act
  Core::Vector *canonical_vector = new Core::Vector(1.0, 2.0, 3.0, 4.0, nullptr, "v0");

  // Expect
  EXPECT_EQ(canonical_vector->getX(), expected_X);
  EXPECT_EQ(canonical_vector->getY(), expected_Y);
  EXPECT_EQ(canonical_vector->getZ(), expected_Z);
  EXPECT_EQ(canonical_vector->getH(), expected_H);
  EXPECT_EQ(canonical_vector->getHalfEdge(), expected_halfedge);
  EXPECT_EQ(canonical_vector->getId(), expected_id);
}

/**
 * @brief Test case for the copy constructor of a Vector class.
 *
 */
TEST_F(VectorTest, copy_vector_constructor)
{
  // Arrange
  const double expected_X = 1.0;
  const double expected_Y = 2.0;
  const double expected_Z = 3.0;
  const double expected_H = 4.0;
  const std::nullptr_t expected_halfedge = nullptr;
  const std::string expected_id = "v0";

  // Act
  Core::Vector *canonical_vector = new Core::Vector(1.0, 2.0, 3.0, 4.0, nullptr, "v0");
  Core::Vector *copied_vector = new Core::Vector(*canonical_vector);

  // Expect
  EXPECT_EQ(copied_vector->getX(), expected_X);
  EXPECT_EQ(copied_vector->getY(), expected_Y);
  EXPECT_EQ(copied_vector->getZ(), expected_Z);
  EXPECT_EQ(copied_vector->getH(), expected_H);
  EXPECT_EQ(copied_vector->getHalfEdge(), expected_halfedge);
  EXPECT_EQ(copied_vector->getId(), expected_id);
}

/**
 * @brief Test case for the getters and setters of a Vector class.
 *
 * This test case verifies that the getters and setters of a Vector class
 * work correctly by checking the initial values and the values after setting
 * new values.
 */
TEST_F(VectorTest, test_getters_and_setters_vector)
{
  // Arrange
  const double expected_initial_X = 0.0;
  const double expected_initial_Y = 0.0;
  const double expected_initial_Z = 0.0;
  const double expected_initial_H = 0.0;
  const std::nullptr_t expected_halfedge = nullptr;
  const std::string expected_id = "v0";

  // Act
  double actual_X = base_vector->getX();
  double actual_Y = base_vector->getY();
  double actual_Z = base_vector->getZ();
  double actual_H = base_vector->getH();
  std::string actual_id = base_vector->getId();

  // Expect
  EXPECT_EQ(actual_X, expected_initial_X);
  EXPECT_EQ(actual_Y, expected_initial_Y);
  EXPECT_EQ(actual_Z, expected_initial_Z);
  EXPECT_EQ(actual_H, expected_initial_H);
  EXPECT_EQ(base_vector->getHalfEdge(), expected_halfedge);
  EXPECT_EQ(actual_id, expected_id);

  // Arrange
  double expected_final_X = 1.0;
  double expected_final_Y = 2.0;
  double expected_final_Z = 3.0;
  double expected_final_H = 4.0;
  std::string expected_final_id = "v1";

  // Act
  base_vector->setX(1.0);
  base_vector->setY(2.0);
  base_vector->setZ(3.0);
  base_vector->setH(4.0);
  base_vector->setId("v1");

  actual_X = base_vector->getX();
  actual_Y = base_vector->getY();
  actual_Z = base_vector->getZ();
  actual_H = base_vector->getH();
  actual_id = base_vector->getId();

  // Expect
  EXPECT_EQ(actual_X, expected_final_X);
  EXPECT_EQ(actual_Y, expected_final_Y);
  EXPECT_EQ(actual_Z, expected_final_Z);
  EXPECT_EQ(actual_H, expected_final_H);
  EXPECT_EQ(base_vector->getHalfEdge(), expected_halfedge);
  EXPECT_EQ(actual_id, expected_final_id);
}

/**
 * @brief Test case for the overloaded ostream operator of a Vector class.
 *
 */
TEST_F(VectorTest, test_ostream_operator_vector)
{
  // Arrange
  const std::string expected_output = "v0: (1, 2, 3, 4)";

  // Act
  Core::Vector *canonical_vector = new Core::Vector(1.0, 2.0, 3.0, 4.0, nullptr, "v0");
  std::stringstream ss;
  ss << *canonical_vector;

  std::cout << *canonical_vector << std::endl;
  std::string actual_output = ss.str();

  // Expect
  EXPECT_EQ(actual_output, expected_output);
}

/**
 * @brief Test case to assign a Vector to another Vector.
 *
 */
TEST_F(VectorTest, test_assignment_operator_vector)
{
  // Arrange
  Core::Vector *canonical_vector = new Core::Vector(1.0, 2.0, 3.0, 4.0, nullptr, "v0");
  Core::Vector *copied_vector = new Core::Vector();

  // Act
  *copied_vector = *canonical_vector;

  // Expect
  EXPECT_EQ(*copied_vector, *canonical_vector);
}

/**
 * @brief Test case for the overloaded equality operator of a Vector class.
 *
 */
TEST_F(VectorTest, test_equality_operator_vector)
{
  // Arrange
  Core::Vector *canonical_vector = new Core::Vector(1.0, 2.0, 3.0, 4.0, nullptr, "v0");
  Core::Vector *copied_vector = new Core::Vector(*canonical_vector);
  Core::Vector *modified_vector = new Core::Vector(2.0, 3.0, 4.0, 5.0, nullptr, "v1");

  // Act
  bool actual_equality = (*canonical_vector == *copied_vector);
  bool actual_inequality = (*canonical_vector == *modified_vector);

  // Expect
  EXPECT_TRUE(actual_equality);
  EXPECT_FALSE(actual_inequality);
}

/**
 * @brief Test case for the overloaded inequality operator of a Vector class.
 *
 */
TEST_F(VectorTest, test_inequality_operator_vector)
{
  // Arrange
  Core::Vector *canonical_vector = new Core::Vector(1.0, 2.0, 3.0, 4.0, nullptr, "v0");
  Core::Vector *copied_vector = new Core::Vector(*canonical_vector);
  Core::Vector *modified_vector = new Core::Vector(2.0, 3.0, 4.0, 5.0, nullptr, "v1");

  // Act
  bool actual_inequality = (*canonical_vector != *copied_vector);
  bool actual_equality = (*canonical_vector != *modified_vector);

  // Expect
  EXPECT_FALSE(actual_inequality);
  EXPECT_TRUE(actual_equality);
}

/**
 * @brief Test case for the overloaded index operator of a Vector class.
 *
 */
TEST_F(VectorTest, test_index_operator_vector)
{
  // Arrange
  const double expected_X = 1.0;
  const double expected_Y = 2.0;
  const double expected_Z = 3.0;
  const double expected_H = 4.0;

  Core::Vector *vector = new Core::Vector(1.0, 2.0, 3.0, 4.0, nullptr, "v0");

  // Act
  double actual_X = (*vector)[0];
  double actual_Y = (*vector)[1];
  double actual_Z = (*vector)[2];
  double actual_H = (*vector)[3];

  // Expect
  EXPECT_EQ(actual_X, expected_X);
  EXPECT_EQ(actual_Y, expected_Y);
  EXPECT_EQ(actual_Z, expected_Z);
  EXPECT_EQ(actual_H, expected_H);
}