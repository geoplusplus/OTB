//----------------------------------------------------------------------------
//
// "Copyright Centre National d'Etudes Spatiales"
// "Copyright Centre for Remote Imaging, Sensing and Processing"
//
// License:  LGPL
//
// See LICENSE.txt file in the top level directory for more details.
//
//----------------------------------------------------------------------------
// $Id$

#ifndef AlosSarPositionVectorRecord_h
#define AlosSarPositionVectorRecord_h

#include <iostream>
#include <cstdlib>
#include <AlosSarRecord.h>

namespace ossimplugins
{

/**
 * @ingroup PlatformPositionDataRecord
 * @brief This class is able to read a position vector record
 */
class AlosSarPositionVectorRecord
{
public:
  /**
   * @brief Constructor
   */
  AlosSarPositionVectorRecord();

  /**
   * @brief Destructor
   */
  ~AlosSarPositionVectorRecord();

  /**
   * @brief Copy constructor
   */
  AlosSarPositionVectorRecord(const AlosSarPositionVectorRecord& rhs);

  /**
   * @brief Copy operator
   */
  AlosSarPositionVectorRecord& operator=(const AlosSarPositionVectorRecord& rhs);
  /**
   * @brief This function write the AlosSar PositionVectorRecord in a stream
   */
  friend std::ostream& operator<<(std::ostream& os, const AlosSarPositionVectorRecord& data);

  /**
   * @brief This function read a AlosSar PositionVectorRecord from a stream
   */
  friend std::istream& operator>>(std::istream& is, AlosSarPositionVectorRecord& data);

  /**
   * @brief Data point position (m)
   */
  double* get_pos()
  {
    return _pos;
  };

  /**
   * @brief Data point velocity (mm/s)
   */
  double* get_vel()
  {
    return _vel;
  };

protected:
  /**
   * @brief Data point position (m)
   */
  double _pos[3];
  /**
   * @brief Data point velocity (mm/s)
   */
  double _vel[3];
private:


};
}
#endif