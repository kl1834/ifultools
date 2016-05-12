
/* @(#) $File: //depot/Research/ifultools/pkg/ifultools/inst/include/fra_fdp.h $: $Revision: #1 $, $Date: 2008/03/21 $ */
/* This is a self-documenting doc++ file. */

#ifndef IN_FRA_FDP_H_
#define IN_FRA_FDP_H_

#include "ut_plat.h"
#include "ut_type.h"
#include "mat_type.h"
#include "ut_err.h"
#include "wav_type.h"

/* This file contains FDP function declarations for the fractal mutils library. */

#ifdef __cplusplus
extern "C" {
#endif

/** Function to simulate an FD process with time varying model parameters.
 *
 * Creates a realization of a time varying fractionally differenced (FD)
 * process with a given vector of FD parameters and corresponding
 * vector of innovation variances.
 *
 * @limits The FD parameter is limited to -1/2 < delta < 5/2.
 * @author Copyright (c), 1988, 2006 Insightful Corp.  All rights reserved.
 * @include fra\_fdp.h
 * @source fra\_fdp.c
 * @library wavelets
 * @usage #err = frauniv_fdp_simulate( &delta, &innovation_variance, intrp_ptr, &result );#
 * @return Standard mutils error/OK code.
 * @param  delta        Pointer to a pre-allocated single-column or
 *                      single-row universal matrix of type MUTIL\_DOUBLE
 *                      representing the FD parameters as they evolve in time.
 * @param  innovation_variance Pointer to a pre-allocated single-column or
 *                      single-row universal matrix of type MUTIL\_DOUBLE.
 *                      representing the FD innovation variances
 *                      as they evolve in time.
 * @param  intrp_ptr    Pointer for implementation of interrupt checking.
 * @param  result       Pointer to universal matrix which (upon return)
 *                      will contain the simulation realization in a
 *                      single-column universal matrix of type MUTIL\_DOUBLE.
 *                      The memory for the universal matrix is automatically
 *                      allocated.
 *
 * @see frauniv_fdp_simulate_weights
 */
MUTIL_LIBEXPORT mutil_errcode frauniv_fdp_simulate(
  const univ_mat *delta,
  const univ_mat *innovation_variance,
  void           *intrp_ptr,
  univ_mat       *result);

/** Function to generate the weights for a time varying FD process simulation.
 *
 * Time varying fractionally differenced (FD) process realizations
 * are generated by cumulatively summing over the inner product of a
 * Gaussian pseudo-random noise sequence (with zero mean and unit variance)
 * and a series of weights that are dependent upon both the FD parameter
 * and innovation variance at a particular time. This function calculates
 * these weights and returns them in a matrix, with the t-th row corresponding
 * to the weights required to generate the t-th element of a
 * FD process realization. By design, the resulting weight matrix is
 * lower triangular.
 *
 * @limits The FD parameter is limited to -1/2 < delta < 5/2.
 * @author Copyright (c), 1988, 2006 Insightful Corp.  All rights reserved.
 * @include fra\_fdp.h
 * @source fra\_fdp.c
 * @library wavelets
 * @usage #err = frauniv_fdp_simulate_weights( &delta, &innovation_variance, intrp_ptr, &result );#
 * @return Standard mutils error/OK code.
 * @param  delta        Pointer to a pre-allocated single-column or
 *                      single-row universal matrix of type MUTIL\_DOUBLE
 *                      representing the FD parameters as they evolve in time.
 * @param  innovation_variance Pointer to a pre-allocated single-column or
 *                      single-row universal matrix of type MUTIL\_DOUBLE.
 *                      representing the FD innovation variances
 *                      as they evolve in time.
 * @param  intrp_ptr    Pointer for implementation of interrupt checking.
 * @param  result       Pointer to a universal matrix which (upon return)
 *                      will contain the time-varying FD simulation weights.
 *                      The universal matrix will be of type MUTIL\_DOUBLE.
 *                      with dimension N x N, where N is the length of the
 *                      delta vector. The memory for the universal matrix
 *                      is automatically allocated.
 *
 * @see frauniv_fdp_simulate
 */
MUTIL_LIBEXPORT mutil_errcode frauniv_fdp_simulate_weights(
  const univ_mat *delta,
  const univ_mat *innovation_variance,
  void           *intrp_ptr,
  univ_mat       *result);


#ifdef __cplusplus
}
#endif

#endif /* IN_FRA_FDP_H_*/

