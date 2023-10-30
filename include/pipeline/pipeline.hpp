#pragma once

#include <core/common.hpp>

namespace pipeline
{
  /**
   * @brief This is the namespace that contains all the classes and functions related to the pipeline
   proposed by the author Adair Santa Catarina.
   *
   */
  namespace santa_catarina
  {
    std::vector<std::vector<double>> sru2src(HalfMesh::Vertex vrp, HalfMesh::Vertex fp);
    std::vector<std::vector<double>> projection(HalfMesh::Vertex vrp, HalfMesh::Vertex p, double d);
    std::vector<std::vector<double>> src2srt(int *window, int *viewport);

    std::vector<std::vector<double>> algebraic_pipeline_sta_catarina(HalfMesh::Vertex vrp, HalfMesh::Vertex fp, HalfMesh::Vertex p, double d, int *window, int *viewport);
  } // namespace santa_catarina

  /**
   * @brief This is the namespace that contains all the classes and functions related to the pipeline
    proposed by the author José Madeiras Pereira.
   *
   */
  namespace madeiras_pereira
  {

  } // namespace madeiras_pereira
} // namespace pipeline