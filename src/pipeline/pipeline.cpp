#include <pipeline/pipeline.hpp>
#include <math/math.hpp>
#include <iomanip>

namespace pipeline
{
  namespace santa_catarina
  {

    /**
     * @brief This function converts a SRU (Universe Reference System) to a SRC (Camera Reference System).
     *
     * @param vrp A HalfMesh::Vertex that represents the VRP (View Reference Point) of the SRC.
     * @param fp A HalfMesh::Vertex that represents the FP (Focal Point) of the SRC.
     * @return std::vector<std::vector<double>> A 4x4 matrix that represents the transformation from SRU to SRC.
     */
    std::vector<std::vector<double>> sru2src(HalfMesh::Vertex vrp, HalfMesh::Vertex fp)
    {
      // Define the n vector.
      HalfMesh::Vertex n = {vrp.x - fp.x, vrp.y - fp.y, vrp.z - fp.z};
      HalfMesh::Vertex n_normalized = Math::normalize(n);

      // Define the v vector.
      // TODO: Choose the up vector, depending on the camera orientation.
      HalfMesh::Vertex up_vec = {0, 1, 0};

      double y1 = Math::dot(up_vec, n_normalized);

      HalfMesh::Vertex _y1 = Math::dot(y1, n_normalized);

      HalfMesh::Vertex v = {up_vec.x - _y1.x, up_vec.y - _y1.y, up_vec.z - _y1.z};

      HalfMesh::Vertex v_normalized = Math::normalize(v);

      // Define the u vector.
      HalfMesh::Vertex u = Math::cross(v_normalized, n_normalized);

      // Make the transformation matrix.
      std::vector<std::vector<double>> matrix_proj;

      matrix_proj = {
          {u.x, u.y, u.z, -Math::dot(u, vrp)},
          {v_normalized.x, v_normalized.y, v_normalized.z, -Math::dot(v_normalized, vrp)},
          {n_normalized.x, n_normalized.y, n_normalized.z, -Math::dot(n_normalized, vrp)},
          {0, 0, 0, 1}};

      return matrix_proj;
    }

    std::vector<std::vector<double>> projection(HalfMesh::Vertex vrp, HalfMesh::Vertex p, double d)
    {
      // This is the definitions of the projection plane.
      HalfMesh::Vertex projection_plane = {
          vrp.x + (p.x - vrp.x) * (d / (vrp.z - p.z)),
          vrp.y + (p.y - vrp.y) * (d / (vrp.z - p.z)),
          vrp.z + (p.z - vrp.z) * (d / (vrp.z - p.z))};

      // The distance from the VRP to the projection plane.
      double dp = Math::length(projection_plane, vrp);
      // The distance from the VRP to the focal point.
      double z_vp = -dp;
      // Z coordinate of the point, where the projection lines intersect the projection plane.
      // In this case, the z_prp is 0. Because this point coincides with the origin of the SRC (0, 0, 0).
      double z_prp = 0;

      std::vector<std::vector<double>> matrix_p;

      matrix_p = {
          {1, 0, 0, 0},
          {0, 1, 0, 0},
          {0, 0, (-z_vp) / dp, z_vp * (z_prp) / dp},
          {0, 0, -1 / d, z_prp / dp}};

      return matrix_p;
    }

    /**
     * @brief This function converts a SRC (Camera Reference System) to a SRT (Screen Reference System).
     *
     * @param window A int[4] that represents the window of the SRT. (x_min, x_max, y_min, y_max)
     * @param viewport A int[4] that represents the viewport of the SRT. (u_min, u_max, v_min, v_max)
     * @return std::vector<std::vector<double>> A 4x4 matrix that represents the transformation from SRC to SRT.
     */
    std::vector<std::vector<double>> src2srt(int *window, int *viewport)
    {
      // | (u_max - u_min)/(x_max - x_min), 0, 0, -x_min * ((u_max - u_min)/(x_max - x_min)) + u_min |\n
      // | 0, (v_min - v_max)/(y_max - y_min), 0, y_min * ((v_max - v_min)/(y_max - y_min)) + v_max |\n
      // | 0, 0, 1, 0 |\n
      // | 0, 0, 0, 1 |
      std::vector<std::vector<double>> matrix_s;

      matrix_s = {
          {(double)((viewport[1] - viewport[0]) / (window[1] - window[0])), 0, 0, (double)-window[0] * ((viewport[1] - viewport[0]) / (window[1] - window[0])) + viewport[0]},
          {0, (double)(viewport[3] - viewport[2]) / (window[3] - window[2]), 0, (double)window[2] * ((viewport[3] - viewport[2]) / (window[3] - window[2])) + viewport[3]},
          {0, 0, 1, 0},
          {0, 0, 0, 1}};

      return matrix_s;
    }
  } // namespace santa_catarina
} // namespace pipeline