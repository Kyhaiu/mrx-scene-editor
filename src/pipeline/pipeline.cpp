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
     * @param vrp A Core::Vertex:Vertex that represents the VRP (View Reference Point) of the SRC.
     * @param fp A Core::Vertex:Vertex that represents the FP (Focal Point) of the SRC.
     * @return std::vector<std::vector<double>> A 4x4 matrix that represents the transformation from SRU to SRC.
     */
    std::vector<std::vector<double>> sru2src(Core::Vertex::Vertex vrp, Core::Vertex::Vertex fp)
    {
      // Define the n vector.
      Core::Vertex::Vertex n = {vrp.x - fp.x, vrp.y - fp.y, vrp.z - fp.z};
      Core::Vertex::Vertex n_normalized = Math::normalize(n);

      // Define the v vector.
      // TODO: Choose the up vector, depending on the camera orientation.
      Core::Vertex::Vertex up_vec = {0, 1, 0};

      double y1 = Math::dot(up_vec, n_normalized);

      Core::Vertex::Vertex _y1 = Math::dot(y1, n_normalized);

      Core::Vertex::Vertex v = {up_vec.x - _y1.x, up_vec.y - _y1.y, up_vec.z - _y1.z};

      Core::Vertex::Vertex v_normalized = Math::normalize(v);

      // Define the u vector.
      Core::Vertex::Vertex u = Math::cross(v_normalized, n_normalized);

      // Make the transformation matrix.
      std::vector<std::vector<double>> matrix_proj;

      matrix_proj = {
          {u.x, u.y, u.z, -Math::dot(u, vrp)},
          {v_normalized.x, v_normalized.y, v_normalized.z, -Math::dot(v_normalized, vrp)},
          {n_normalized.x, n_normalized.y, n_normalized.z, -Math::dot(n_normalized, vrp)},
          {0, 0, 0, 1}};

      return matrix_proj;
    }

    /**
     * @brief This function converts a SRC (Camera Reference System) to a PRP (Projection Reference System).
     *
     * @param vrp A Core::Vertex:Vertex that represents the VRP (View Reference Point) of the SRC.
     * @param p A Core::Vertex:Vertex that represents the FP (Focal Point) of the SRC.
     * @param d The distance from the VRP to the focal point.
     * @return std::vector<std::vector<double>>
     */
    std::vector<std::vector<double>> projection(Core::Vertex::Vertex vrp, Core::Vertex::Vertex p, double d)
    {
      // This is the definitions of the projection plane.
      Core::Vertex::Vertex projection_plane = {
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
     * @param window A double[4] that represents the window of the SRT. (x_min, x_max, y_min, y_max)
     * @param viewport A double[4] that represents the viewport of the SRT. (u_min, u_max, v_min, v_max)
     * @param reflection A boolean that indicates if we need to reflect the points through the x axis.
     * @return std::vector<std::vector<double>> A 4x4 matrix that represents the transformation from SRC to SRT.
     */
    std::vector<std::vector<double>> src2srt(std::vector<double> window, std::vector<double> viewport, bool reflection = false)
    {
      std::vector<std::vector<double>> matrix_s;

      double u_min = viewport[0];
      double u_max = viewport[1];
      double v_min = viewport[2];
      double v_max = viewport[3];

      double x_min = window[0];
      double x_max = window[1];
      double y_min = window[2];
      double y_max = window[3];

      if (reflection)
      {
        // | (u_max - u_min)/(x_max - x_min), 0, 0, -x_min *((u_max - u_min)/(x_max - x_min)) + u_min |\n
        // | 0, (v_min - v_max)/(y_max - y_min), 0, y_min * ((v_max - v_min)/(y_max - y_min)) + v_max |\n
        // | 0, 0, 1, 0 |\n
        // | 0, 0, 0, 1 |
        matrix_s = {
            {(u_max - u_min) / (x_max - x_min), 0, 0, -x_min * ((u_max - u_min) / (x_max - x_min)) + u_min},
            {0, (v_min - v_max) / (y_max - y_min), 0, y_min * ((v_max - v_min) / (y_max - y_min)) + v_max},
            {0, 0, 1, 0},
            {0, 0, 0, 1}};
      }
      else
      {
        // | (u_max - u_min)/(x_max - x_min), 0, 0, -x_min * ((u_max - u_min)/(x_max - x_min)) + u_min |\n
        // | 0, (v_max - v_min)/(y_max - y_min), 0, -y_min * ((v_max - v_min)/(y_max - y_min)) + v_min) |\n
        // | 0, 0, 1, 0 |\n
        // | 0, 0, 0, 1 |
        matrix_s = {
            {(u_max - u_min) / (x_max - x_min), 0, 0, -x_min * ((u_max - u_min) / (x_max - x_min)) + u_min},
            {0, (v_max - v_min) / (y_max - y_min), 0, -y_min * ((v_max - v_min) / (y_max - y_min)) + v_min},
            {0, 0, 1, 0},
            {0, 0, 0, 1}};
      }

      return matrix_s;
    }
  } // namespace santa_catarina
} // namespace pipeline