#include <gtest/gtest.h>
#include <core/vector.hpp>
#include <math/math.hpp>
#include <iostream>

class MathVectorTest : public ::testing::Test
{
protected:
  HalfMesh::Vector *v1 = new HalfMesh::Vector(1.0, 0.0, 0.0, 1.0, nullptr);
  HalfMesh::Vector *v2 = new HalfMesh::Vector(0.0, 1.0, 0.0, 1.0, nullptr);

  void SetUp() override {}
};

/**
 * @brief Test case for the angle function.
 *
 */
TEST_F(MathVectorTest, angle)
{
  // Arrange
  const double expected_angle = 0.0;

  // Act
  double actual_angle = Math::angle(v1, v2);

  // Expect
  EXPECT_EQ(actual_angle, expected_angle);
}

/**
 * @brief Test case for the dot function.
 *
 */
TEST_F(MathVectorTest, dot)
{
  // Arrange
  const double expected_dot = 0.0;

  // Act
  double actual_dot = Math::dot(v1, v2);

  // Expect
  EXPECT_EQ(actual_dot, expected_dot);
}

/**
 * @brief Test case for the length function.
 *
 */
TEST_F(MathVectorTest, length)
{
  // Arrange
  const double expected_length = 1.0;

  // Act
  double actual_length = Math::v_module(v1);

  // Expect
  EXPECT_EQ(actual_length, expected_length);
}

/**
 * @brief Test case for the normalize function.
 *
 */
TEST_F(MathVectorTest, normalize)
{
  // Arrange
  const double expected_X = 1.0;
  const double expected_Y = 0.0;
  const double expected_Z = 0.0;
  const double expected_H = 1.0;
  const std::nullptr_t expected_halfedge = nullptr;

  // Act
  HalfMesh::Vector *actual_vector = Math::normalize(v1);

  // Expect
  EXPECT_EQ(actual_vector->getX(), expected_X);
  EXPECT_EQ(actual_vector->getY(), expected_Y);
  EXPECT_EQ(actual_vector->getZ(), expected_Z);
  EXPECT_EQ(actual_vector->getH(), expected_H);
  EXPECT_EQ(actual_vector->getHalfEdge(), expected_halfedge);

  // Arrange
  const double expected_X2 = 0.0;
  const double expected_Y2 = 1.0;
  const double expected_Z2 = 0.0;

  // Act
  HalfMesh::Vertex v2 = {0.0, 4.0, 0.0};
  HalfMesh::Vertex actual_vector2 = Math::normalize(v2);

  // Expect
  EXPECT_EQ(actual_vector2.x, expected_X2);
  EXPECT_EQ(actual_vector2.y, expected_Y2);
  EXPECT_EQ(actual_vector2.z, expected_Z2);
}

/**
 * @brief Test case for the cross function.
 *
 */
TEST_F(MathVectorTest, cross)
{
  // Arrange
  const double expected_X = 0.0;
  const double expected_Y = 0.0;
  const double expected_Z = 1.0;
  const double expected_H = 1.0;
  const std::nullptr_t expected_halfedge = nullptr;

  // Act
  HalfMesh::Vector *actual_vector = Math::cross(v1, v2);

  // Expect
  EXPECT_EQ(actual_vector->getX(), expected_X);
  EXPECT_EQ(actual_vector->getY(), expected_Y);
  EXPECT_EQ(actual_vector->getZ(), expected_Z);
  EXPECT_EQ(actual_vector->getH(), expected_H);
  EXPECT_EQ(actual_vector->getHalfEdge(), expected_halfedge);
}
