/*

  This file is a part of the Nova Physics Engine
  project and distributed under the MIT license.

  Copyright © Kadir Aksoy
  https://github.com/kadir014/nova-physics

*/

#ifndef NOVAPHYSICS_SOLVER_H
#define NOVAPHYSICS_SOLVER_H

#include "novaphysics/body.h"
#include "novaphysics/collision.h"
#include "novaphysics/resolution.h"
#include "novaphysics/constraint.h"


/**
 * solver.h
 * 
 * Collision and constraint(not yet) resolver functions
 */


/**
 * @brief Prepare for resolving
 * 
 * @param res 
 */
void nv_prestep_collision(nv_Resolution *res, double inv_dt, bool accumulate);

/**
 * @brief Resolve collision between two bodies
 * 
 * @param res Collision resolution
 */
void nv_resolve_collision(nv_Resolution *res, bool accumulate);


/**
 * @brief Resolve constraint
 * 
 * @param cons Constraint
 */
void nv_resolve_constraint(nv_Constraint *cons);


/**
 * @brief Resolve spring constraint
 * 
 * @param cons Constraint
 */
void nv_resolve_spring(nv_Constraint *cons);


#endif