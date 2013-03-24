# -*- cmake -*-

# - Find SSVUtilsJson
# Find the SSVUtilsJson includes and library
# This module defines
# SSVUTILSJSON_INCLUDE_DIR, where to find SSVUtilsJson headers.
# SSVUTILSJSON_LIBRARIES, the libraries needed to use SSVUtilsJson.
# SSVUTILSJSON_FOUND, If false, do not try to use SSVUtilsJson.
# also defined, but not for general use are
# SSVUTILSJSON_LIBRARY, where to find the SSVUtilsJson library.

FIND_PATH(SSVUTILSJSON_INCLUDE_DIR
  NAMES SSVUtilsJson/SSVUtilsJson.h
  PATH_SUFFIXES include/
  PATHS "${PROJECT_SOURCE_DIR}/../SSVUtilsJson/"
  "${PROJECT_SOURCE_DIR}/extlibs/SSVUtilsJson/"
  ${SSVUTILSJSON_ROOT}
  $ENV{SSVUTILSJSON_ROOT}
  /usr/local/
  /usr/
  /sw/         # Fink
  /opt/local/  # DarwinPorts
  /opt/csw/    # Blastwave
  /opt/
)

message("\nFound SSVUtilsJson include at: ${SSVUTILSJSON_INCLUDE_DIR}.\n")

FIND_LIBRARY(SSVUTILSJSON_LIBRARY
  NAMES SSVUtilsJson libSSVUtilsJson SSVUtilsJson-s libSSVUtilsJson-s ssvutilsjson libssvutilsjson ssvutilsjson-s libssvutilsjson-s
  PATH_SUFFIXES lib/ lib64/
  PATHS "${PROJECT_SOURCE_DIR}/../SSVUtilsJson/"
  "${PROJECT_SOURCE_DIR}/extlibs/SSVUtilsJson/"
  ${SSVUTILSJSON_ROOT}
  $ENV{SSVUTILSJSON_ROOT}
  /usr/local/
  /usr/
  /sw/         # Fink
  /opt/local/  # DarwinPorts
  /opt/csw/    # Blastwave
  /opt/
)

message("\nFound SSVUtilsJson library at: ${SSVUTILSJSON_LIBRARY}.\n")

IF (SSVUTILSJSON_LIBRARY AND SSVUTILSJSON_INCLUDE_DIR)
    SET(SSVUTILSJSON_LIBRARIES ${SSVUTILSJSON_LIBRARY})
    SET(SSVUTILSJSON_FOUND TRUE)
ELSE (SSVUTILSJSON_LIBRARY AND SSVUTILSJSON_INCLUDE_DIR)
    SET(SSVUTILSJSON_FOUND FALSE)
ENDIF (SSVUTILSJSON_LIBRARY AND SSVUTILSJSON_INCLUDE_DIR)

IF (SSVUTILSJSON_FOUND)
      MESSAGE(STATUS "Found SSVUtilsJson in ${SSVUTILSJSON_INCLUDE_DIR}")
ELSE (SSVUTILSJSON_FOUND)
   IF (SSVUTILSJSON_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find SSVUtilsJson library")
   ENDIF (SSVUTILSJSON_FIND_REQUIRED)
ENDIF (SSVUTILSJSON_FOUND)

MARK_AS_ADVANCED(
  SSVUTILSJSON_LIBRARY
  SSVUTILSJSON_INCLUDE_DIR
)
