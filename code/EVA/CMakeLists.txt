INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/server )

IF(WITH_EVA)
  ADD_DEFINITIONS(-DEVA)
ENDIF(WITH_EVA)

ADD_SUBDIRECTORY(server)

IF(WITH_TOOLS)
  ADD_SUBDIRECTORY(tools)
ENDIF(WITH_TOOLS)

