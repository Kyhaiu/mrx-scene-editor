#include <gtest/gtest.h>
#include <iostream>
#include <pipeline/pipeline.hpp>

class PipelineTest : public ::testing::Test
{
protected:
  void SetUp() override {}
};

/**
 * @brief Test case for the function sru2src.
 *
 */
TEST_F(PipelineTest, sru2src)
{
  HalfMesh::Vertex vrp = {25, 15, 80};
  HalfMesh::Vertex fp = {20, 10, 25};
  std::vector<std::vector<double>> result = pipeline::santa_catarina::sru2src(vrp, fp);

  std::vector<std::vector<double>> expected = {
      {0.995893206467705, 0.000000000000000, -0.090535746042518, -17.654470478291100},
      {-0.008163333305850, 0.995926663313714, -0.089796666364351, -7.551083307911350},
      {0.090166963466743, 0.090166963466743, 0.991836598134176, -82.953606389403800},
      {0.000000000000000, 0.000000000000000, 0.000000000000000, 1.000000000000000}};

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      // after the 3rd decimal place, the error is insignificant.
      EXPECT_NEAR(result[i][j], expected[i][j], 0.0001);
    }
  }
}

/**
 * @brief Test case for the function projection.
 *
 */
TEST_F(PipelineTest, projection)
{
  HalfMesh::Vertex vrp = {25, 15, 80};
  HalfMesh::Vertex p = {20, 10, 25};
  double d = 40;
  std::vector<std::vector<double>> result = pipeline::santa_catarina::projection(vrp, p, d);

  std::vector<std::vector<double>> expected = {
      {1, 0, 0, 0},
      {0, 1, 0, 0},
      {0, 0, 1, 0},
      {0, 0, -0.025, 0}};

  // 1	0	0	0
  // 0	1	0	0
  // 0	0	1	0
  // 0	0	-0,025	0

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      // after the 3rd decimal place, the error is insignificant.
      EXPECT_NEAR(result[i][j], expected[i][j], 0.0001);
    }
  }
}