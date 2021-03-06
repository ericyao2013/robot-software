#ifndef AVERSIVE_MATH_GEOMETRY_DISCRETE_CIRCLES_H
#define AVERSIVE_MATH_GEOMETRY_DISCRETE_CIRCLES_H

#include <stdbool.h>

#include "math/geometry/circles.h"
#include "math/geometry/polygon.h"

/* Computes polygon inscribed in given circle.
 * The first point of the polygon starts at angle offset.
 *
 * @param poly[in,out] Polygon that contains discrete circle
 * @param circle[in] Circle in which the polygon is inscribed
 * @param samples[in] Number of samples of the discrete circle (i.e. number of polygon vertices)
 * @param angle_offset[in] Starting angle in radians
 *
 * @return true if successfully computed discrete circle, false otherwise
 */
bool discretize_circle(poly_t* poly, circle_t circle, int samples, float angle_offset);

#endif /* AVERSIVE_MATH_GEOMETRY_DISCRETE_CIRCLES_H */
