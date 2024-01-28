#include <gtest/gtest.h>
#include <iostream>
#include <pipeline/pipeline.hpp>
#include <vector>

class PipelineTest : public ::testing::Test
{
protected:
  // The VRP (View Reference Point) of the SRC.
  Core::Vertex::Vertex vrp = {25, 15, 80};
  // The FP (Focal Point) of the SRC.
  Core::Vertex::Vertex p = {20, 10, 25};

  // The distance from the VRP to the focal point.
  double dp = 40;

  // The window of the SRC.
  std::vector<double> window = {0, 16, 0, 12};
  // The viewport of the SRC.
  std::vector<double> viewport = {0, 319, 0, 239};

  // The point that will be projected.
  // this points form a pyramid having 5 faces.
  Core::Vertex::Vertex a = {21.2, 0.7, 42.3};
  Core::Vertex::Vertex b = {34.1, 3.4, 27.2};
  Core::Vertex::Vertex c = {18.8, 5.6, 14.6};
  Core::Vertex::Vertex d = {5.9, 2.9, 29.7};
  Core::Vertex::Vertex e = {20, 20, 31.6};

  void SetUp() override {}
};

/**
 * @brief Test case for the function sru2src.
 *
 */
TEST_F(PipelineTest, sru2src)
{
  std::vector<std::vector<double>> result = pipeline::santa_catarina::sru2src(vrp, p);

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
  std::vector<std::vector<double>> result = pipeline::santa_catarina::projection(vrp, p, dp);

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

/**
 * @brief Test case for the function src2srt with reflection.
 *
 */
TEST_F(PipelineTest, src2srt_with_reflection)
{
  std::vector<std::vector<double>> result = pipeline::santa_catarina::src2srt(window, viewport, true);

  std::vector<std::vector<double>> expected = {
      {19.9375, 0, 0, 0},
      {0, -19.9166666666667, 0, 239},
      {0, 0, 1, 0},
      {0, 0, 0, 1}};

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
 * @brief Test case for the function src2srt without reflection.
 *
 */
TEST_F(PipelineTest, src2srt_without_reflection)
{
  std::vector<std::vector<double>> result = pipeline::santa_catarina::src2srt(window, viewport, false);

  std::vector<std::vector<double>> expected = {
      {19.9375, 0, 0, 0},
      {0, 19.9166666666667, 0, 0},
      {0, 0, 1, 0},
      {0, 0, 0, 1}};

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      // after the 3rd decimal place, the error is insignificant.
      EXPECT_NEAR(result[i][j], expected[i][j], 0.0001);
    }
  }
}