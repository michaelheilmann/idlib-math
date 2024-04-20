// Copyright (c) 2023-2024 Michael Heilmann.All rights reserved.
#if !defined(IDLIB_VECTOR_3_H_INCLUDED)
#define IDLIB_VECTOR_3_H_INCLUDED

#include "scalar.h"
// NULL
#include <stddef.h>

/// @since 0.1
/// A three component vector with elements of type idlib_f32.
typedef struct idlib_vector_3_f32 {
  idlib_f32 e[3];
} idlib_vector_3_f32;

/// @since 1.0
/// Get the squared length of a idlib_vector_3_f32 object.
/// @param operand A pointer to the idlib_vector_3_f32 object.
/// @return The squared length of the idlib_Vector_3_f32 object pointed to by @a operand.
static inline idlib_f32
idlib_vector_3_f32_get_squared_length
  (
    idlib_vector_3_f32 const* operand
  );

/// @since 1.0
/// Get the length of a idlib_vector_3_f32 object.
/// @param operand A pointer to the idlib_vector_3_f32 object.
/// @return The length of the idlib_Vector_3_f32 object pointed to by @a operand.
static inline idlib_f32
idlib_vector_3_f32_get_length
  (
    idlib_vector_3_f32 const* operand
  );

/// @since 0.1
/// Assign an idlib_vector_3_f32 object the specified scalar values.
/// @param target A pointer to the idlib_vector_3_f32 object.
/// @param x, y, z The scalar values.
static inline void
idlib_vector_3_f32_set
  (
    idlib_vector_3_f32* target,
    idlib_f32 x,
    idlib_f32 y,
    idlib_f32 z
  );

/// @since 0.1
/// Assign an idlib_vector_3_f32 object the values of an zero vector.
/// @param target A pointer to the idlib_vector_3_f32 object.
static inline void
idlib_vector_3_f32_set_zero
  (
    idlib_vector_3_f32* target
  );

/// @since 1.0
/// Compute the sum of two idlib_vector_3_f32 objects and assign the result to a idlib_vector_3_f32 object.
/// @param target The idlib_vector_3_f32 object to assign the result to.
/// @param operand1 The idlib_vector_3_f32 object that is the augend (aka first term).
/// @param operand2 The idlib_vector_3_f32 object that is the addend (aka second term).
/// @remarks @a target, @a operand1, and @a operand2 all may refer to the same idlib_vector_3_f32 object.
static inline void
idlib_vector_3_f32_add
  (
    idlib_vector_3_f32* target,
    idlib_vector_3_f32 const* operand1,
    idlib_vector_3_f32 const* operand2
  );

/// @since 1.0
/// Compute the difference of two idlib_vector_3_f32 objects and assign the result to a idlib_vector_3_f32 object.
/// @param target The idlib_vector_3_f32 object to assign the result to.
/// @param operand1 The idlib_vector_3_f32 object that is the minuend (aka first term).
/// @param operand2 The idlib_vector_3_f32 object that is the subtrahend (aka second term).
/// @remarks @a target, @a operand1, and @a operand2 all may refer to the same idlib_vector_3_f32 object.
static inline void
idlib_vector_3_f32_subtract
  (
    idlib_vector_3_f32* target,
    idlib_vector_3_f32 const* operand1,
    idlib_vector_3_f32 const* operand2
  );

/// @since 1.0
/// Get if two idlib_vector_3_f32 objects are equal.
/// @param operand1 The first operand.
/// @param operand2 The second operand.
/// @return @a true if the idlib_f32 objects are equal. @a false otherwise.
static inline bool
idlib_vector_3_f32_are_equal
  (
    idlib_vector_3_f32 const* operand1,
    idlib_vector_3_f32 const* operand2
  );

static inline idlib_f32
idlib_vector_3_f32_get_squared_length
  (
    idlib_vector_3_f32 const* operand
  )
{
  IDLIB_DEBUG_ASSERT(NULL != operand);
  idlib_f32 length_squared = operand->e[0] * operand->e[0]
                           + operand->e[1] * operand->e[1]
                           + operand->e[2] * operand->e[2];
  return length_squared;
}

static inline idlib_f32
idlib_vector_3_f32_get_length
  (
    idlib_vector_3_f32 const* operand
  )
{ return idlib_sqrt_f32(idlib_vector_3_f32_get_squared_length(operand)); }

static inline void
idlib_vector_3_f32_set
  (
    idlib_vector_3_f32* target,
    idlib_f32 x,
    idlib_f32 y,
    idlib_f32 z
  )
{
  IDLIB_DEBUG_ASSERT(NULL != target);

  target->e[0] = x;
  target->e[1] = y;
  target->e[2] = z;
}

static inline void
idlib_vector_3_f32_set_zero
  (
    idlib_vector_3_f32* target
  )
{ idlib_vector_3_f32_set(target, 0.f, 0.f, 0.f); }

static inline void
idlib_vector_3_f32_add
  (
    idlib_vector_3_f32* target,
    idlib_vector_3_f32 const* operand1,
    idlib_vector_3_f32 const* operand2
  )
{
  IDLIB_DEBUG_ASSERT(NULL != target);
  IDLIB_DEBUG_ASSERT(NULL != operand1);
  IDLIB_DEBUG_ASSERT(NULL != operand2);
  target->e[0] = operand1->e[0] + operand2->e[0];
  target->e[1] = operand1->e[1] + operand2->e[1];
  target->e[2] = operand1->e[2] + operand2->e[2];
}

static inline void
idlib_vector_3_f32_subtract
  (
    idlib_vector_3_f32* target,
    idlib_vector_3_f32 const* operand1,
    idlib_vector_3_f32 const* operand2
  )
{
  IDLIB_DEBUG_ASSERT(NULL != target);
  IDLIB_DEBUG_ASSERT(NULL != operand1);
  IDLIB_DEBUG_ASSERT(NULL != operand2);
  target->e[0] = operand1->e[0] - operand2->e[0];
  target->e[1] = operand1->e[1] - operand2->e[1];
  target->e[2] = operand1->e[2] - operand2->e[2];
}

static inline bool
idlib_vector_3_f32_are_equal
  (
    idlib_vector_3_f32 const* operand1,
    idlib_vector_3_f32 const* operand2
  )
{
  IDLIB_DEBUG_ASSERT(NULL != operand1);
  IDLIB_DEBUG_ASSERT(NULL != operand2);
  if (operand1 == operand2) {
    return true;
  }
  return operand1->e[0] == operand2->e[0]
      && operand1->e[1] == operand2->e[1]
      && operand1->e[2] == operand2->e[2];
}

#endif // IDLIB_VECTOR_3_H_INCLUDED
