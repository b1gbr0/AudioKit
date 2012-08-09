//
//  OCSExponentialCurvesTable.h
//  Objective-C Sound
//
//  Created by Adam Boulanger on 6/21/12.
//  Copyright (c) 2012 Hear For Yourself. All rights reserved.
//

#import "OCSFTable.h"

/** Constructs functions from segments of exponential curves.
 
 Ordinate values, in odd-numbered parts of the array, must be nonzero and must be alike in sign.
 
 Length of segment, in even-numbered parts of the array,  cannot be negative, but a zero is 
 meaningful for specifying discontinuous waveforms. The sum n1 + n2 + .... will normally equal 
 size for fully specified functions. If the sum is smaller, the function locations not included 
 will be set to zero; if the sum is greater, only the first size locations will be stored.
 
 @warning *Unsupported Functions* 

 Discrete-point linear interpolation implies an increase or decrease along a segment by equal 
 differences between adjacent locations; exponential interpolation implies that the progression 
 is by equal ratio. In both forms the interpolation from a to b is such as to assume that the 
 value b will be attained in the n + 1th location. For discontinuous functions, and for the 
 segment encompassing the end location, this value will not actually be reached, although it 
 may eventually appear as a result of final scaling.
 */
@interface OCSExponentialCurvesTable : OCSFTable

/// Instantiates an exponential curves table.
/// @param tableSize         Number of points in the table. Must be a power of 2 or power-of-2 plus 1.
/// @param valueLengthPairs  Values must be nonzero and must be alike in sign.
/// Lengths must be non-negative and the sum should equal `tableSize`.
- (id)initWithSize:(int)tableSize 
  valueLengthPairs:(OCSParameterArray *)valueLengthPairs;

/// Instantiates an exponential curves table.
/// @param tableSize Number of points in the table. Must be a power of 2 or power-of-2 plus 1.
/// @param values    Values must be nonzero and must be alike in sign.
/// @param lengths   Lengths of segments (no. of storage locations) must be non-negative and the sum should equal `tableSize`.
- (id)initWithSize:(int)tableSize 
            values:(OCSParameterArray *)values
           lengths:(OCSParameterArray *)lengths;

/// Instantiates an exponential curves table using breakpoints.
/// @param tableSize    Number of points in the table. Must be a power of 2 or power-of-2 plus 1.
/// @param breakpoints  x & y locations arranges as x1, y1, x2, y2, ... in a parameter array.  x values must be in increasing order. If the last x value is less than size, then the rest will be set to zero. Should not be negative but can be zero. y values must be non-zero and must be alike in sign.
- (id)initWithSize:(int)tableSize 
       breakpoints:(OCSParameterArray *)breakpoints;


/// Instantiates an exponential curves table using breakpoints.
/// @param tableSize Number of points in the table. Must be a power of 2 or power-of-2 plus 1.
/// @param xValues   x values must be in increasing order. If the last x value is less than size, then the rest will be set to zero. Should not be negative but can be zero. 
/// @param yValues   y values must be non-zero and must be alike in sign.
- (id)initWithSize:(int)tableSize 
 breakpointXValues:(OCSParameterArray *)xValues
 breakpointYValues:(OCSParameterArray *)yValues;

@end
