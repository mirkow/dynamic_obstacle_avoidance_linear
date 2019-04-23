/**
 * @class Obstacle
 * @brief Class to define the obstacles
 * @author Baptiste Busch
 * @date 2019/04/16
 */

#ifndef DYNAMIC_OBSTACLE_AVOIDANCE_OBSTACLE_ELLIPSOID_H_
#define DYNAMIC_OBSTACLE_AVOIDANCE_OBSTACLE_ELLIPSOID_H_

#include <iostream>
#include <eigen3/Eigen/Core>
#include "DynamicObstacleAvoidance/Obstacle/Obstacle.hpp"


class Ellipsoid2D: public Obstacle 
{
private:
	Eigen::Array2f direction_axis;
	Eigen::Array2f lengths;

public:
	explicit Ellipsoid2D(Eigen::Vector3f& center_position, Eigen::Vector4f& center_orientation, Eigen::Vector3f& reference_position, double safety_margin=0);
	explicit Ellipsoid2D(Eigen::Vector3f& center_position, Eigen::Vector4f& center_orientation, double safety_margin=0);
	~Ellipsoid2D();

	Eigen::VectorXf compute_normal_to_external_point(const Eigen::Vector3f& external_point) const;
	double compute_distance_to_external_point(const Eigen::Vector3f& external_point) const;
	
};

#endif