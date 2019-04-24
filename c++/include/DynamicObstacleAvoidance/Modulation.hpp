/**
 * @class Modulation
 * @brief Class to define Modulations of the dynamical system
 * @author Baptiste Busch
 * @date 2019/04/16
 */

#ifndef DYNAMIC_OBSTACLE_AVOIDANCE_MODULATION_H_
#define DYNAMIC_OBSTACLE_AVOIDANCE_MODULATION_H_

#include <deque>
#include <tuple>
#include <utility>
#include <functional>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <math.h>
#include <algorithm>
#include "DynamicObstacleAvoidance/Obstacle/Obstacle.hpp"
#include "DynamicObstacleAvoidance/Agent.hpp"

namespace Modulation
{
    Eigen::Vector3f compute_direction_to_obstacle(const Obstacle& obstacle, const Eigen::Vector3f& agent_position);
    Eigen::Vector3f compute_normal_to_obstacle(const Obstacle& obstacle, const Eigen::Vector3f& agent_position);
    double compute_distance_to_obstacle(const Obstacle& obstacle, const Eigen::Vector3f& agent_position);
    Eigen::MatrixXf compute_eigenvalues();
    Eigen::ArrayXf weight_obstacles(const Eigen::ArrayXf& distances, double critical_distance, double weight_power);
    std::pair<Eigen::Matrix3f, Eigen::Matrix3f> compute_basis_matrices(const Eigen::Vector3f& normal_vector, const Eigen::Vector3f& agent_position, const Eigen::Vector3f& obstacle_reference_position);

    /**
    * @brief The function evaluates the gamma function and all necessary components needed to construct the modulation function, to ensure safe avoidance of the obstacles.
    * Beware that this function is constructed for ellipsoid only, but the algorithm is applicable to star shapes.
    * @param[in] robotPos Position of the robot in the obstacle reference frame
    * @param[in] obstacle Description of the obstacle with parameters
    * @param[in] rotation Rotation matrix
    * @param[out] basis Basis matrix with rows the reference and tangent to the obstacles surface
    * @param[out] basisOrthogonal Orthogonal basis matrix with rows the normal and tangent
    * @param[out] eigenValues Eigenvalue matrix which is responsible for the modulation
    */
    std::tuple<Eigen::Matrix3f, Eigen::Matrix3f, Eigen::Matrix3f, double> compute_modulation_matrix(const Agent& agent, const Obstacle& obstacle);
    Eigen::Vector3f modulate_velocity(const Agent& agent, const std::deque<Obstacle>& obstacles, const std::deque<Eigen::Vector3f>& attractor_positions);
}

#endif