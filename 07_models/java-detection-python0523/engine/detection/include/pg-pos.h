#ifndef __PG_POS_H__
#define __PG_POS_H__
#include <assert.h>
#include "pg-one-pos.h"

/*
 * pg_leftmost_one_pos32
 *      Returns the position of the most significant set bit in "word",
 *      measured from the least significant bit.  word must not be 0.
 */
static inline int
pg_leftmost_one_pos32(uint32 word)
{
    int shift = 32 - 8;

    assert(word != 0);

    while ((word >> shift) == 0)
        shift -= 8;

    return shift + pg_leftmost_one_pos[(word >> shift) & 255];
}

/*
 * pg_nextpower2_32
 *      Returns the next higher power of 2 above 'num', or 'num' if it's
 *      already a power of 2.
 *
 * 'num' mustn't be 0 or be above PG_UINT32_MAX / 2 + 1.
 */
static inline uint32
pg_nextpower2_32(uint32 num)
{
    assert(num > 0 && num <= PG_UINT32_MAX / 2 + 1);

    /*
     * A power 2 number has only 1 bit set.  Subtracting 1 from such a number
     * will turn on all previous bits resulting in no common bits being set
     * between num and num-1.
     */
    if ((num & (num - 1)) == 0)
        return num; /* already power 2 */

    return ((uint32)1) << (pg_leftmost_one_pos32(num) + 1);
}

#endif /* __SQL_PARSER_H__ */
