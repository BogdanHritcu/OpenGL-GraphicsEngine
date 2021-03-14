#pragma once

#include <limits>
#include <GLFW/glfw3.h>

#define pixMAX_VERTICES			      4000000 //the number of the max allowed vertices at the same time
#define pixMAX_INDICES_PER_VERTEX     3
#define pixMAX_INDICES                (pixMAX_VERTICES * pixMAX_INDICES_PER_VERTEX)
#define pixTRANSFORM_STACK_SIZE	      4 //default transformation stack size

#define pixMAX_UBYTE   UCHAR_MAX
#define pixMAX_USHORT  USHRT_MAX
#define pixMAX_UINT    UINT_MAX

#if pixMAX_INDICES<pixMAX_UBYTE
typedef GLubyte pixIndexType;
#define pixELEMENT_RESTART_INDEX pixMAX_UBYTE
#define pixINDEX_TYPE GL_UNSIGNED_BYTE

#elif pixMAX_INDICES<pixMAX_USHORT
typedef GLushort pixIndexType;
#define pixELEMENT_RESTART_INDEX pixMAX_USHORT
#define pixINDEX_TYPE GL_UNSIGNED_SHORT

#else
typedef GLuint pixIndexType;
#define pixELEMENT_RESTART_INDEX pixMAX_UINT
#define pixINDEX_TYPE GL_UNSIGNED_INT

#endif

#ifndef pixVERTEX_H
#include "../vertex/vertex.h" //for sizeof(Vertex)
#endif // !VERTEX_H

#define pixVERTEX_BUFFER_SIZE         (pixMAX_VERTICES * sizeof(Vertex)) //(bytes)

#define pixINDEX_BUFFER_SIZE          (pixMAX_INDICES * sizeof(pixIndexType)) //(bytes)

#define pixVERTEX_POSITION_LAYOUT 0
#define pixVERTEX_COLOR_LAYOUT 1
#define pixVERTEX_TEX_COORDS_LAYOUT 2

#define pixPOS_FLOAT_COUNT 3
#define pixCOLOR_FLOAT_COUNT 4
#define pixTEX_COORDS_FLOAT_COUNT 2

#define pixATTR0_OFFSET 0
#define pixATTR1_OFFSET (pixATTR0_OFFSET + pixPOS_FLOAT_COUNT)  
#define pixATTR2_OFFSET (pixATTR1_OFFSET + pixCOLOR_FLOAT_COUNT)  

#define pixCOLOR_BUFFER_BIT GL_COLOR_BUFFER_BIT
#define pixSTENCIL_BUFFER_BIT GL_STENCIL_BUFFER_BIT
#define pixDEPTH_BUFFER_BIT GL_DEPTH_BUFFER_BIT


#define pixINSIDE  0 //0000
#define pixLEFT    1 //0001
#define pixRIGHT   2 //0010
#define pixDOWN    4 //0100
#define pixUP      8 //1000


#define pixPI  3.14159265359f
#define pixKEY_COUNT 1024
#define pixBUTTON_COUNT 16
