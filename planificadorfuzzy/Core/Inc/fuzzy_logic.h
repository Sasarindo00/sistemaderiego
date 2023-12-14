/*
 * fuzzy_logic.h
 *
 *  Created on: Dec 9, 2023
 *      Author: Sugawuara
 */

#ifndef INC_FUZZY_LOGIC_H_
#define INC_FUZZY_LOGIC_H_

#include <stdint.h>


#define FIS_TYPE float
#define FIS_RESOLUSION 101
#define FIS_MIN -3.4028235E+38
#define FIS_MAX 3.4028235E+38
typedef FIS_TYPE(*_FIS_MF)(FIS_TYPE, FIS_TYPE*);
typedef FIS_TYPE(*_FIS_ARR_OP)(FIS_TYPE, FIS_TYPE);
typedef FIS_TYPE(*_FIS_ARR)(FIS_TYPE*, int, _FIS_ARR_OP);

#endif /* INC_FUZZY_LOGIC_H_ */

