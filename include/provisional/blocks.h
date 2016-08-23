#ifndef _BLOCKS_
#define _BLOCKS_

#define PIXEL_B imgInPrevB[j-1]
#define PIXEL_C imgInPrevB[j]
#define PIXEL_D imgInPrevB[j+1]
#define PIXEL_E imgInPrevB[j+2]
#define PIXEL_G imgInPrevL[j-2]
#define PIXEL_H imgInPrevL[j-1]
#define PIXEL_I imgInPrevL[j]
#define PIXEL_J imgInPrevL[j+1]
#define PIXEL_K imgInPrevL[j+2]
#define PIXEL_M imgInL[j-2]
#define PIXEL_N imgInL[j-1]
#define PIXEL_O imgInL[j]
#define PIXEL_P imgInL[j+1]
#define PIXEL_R imgInNextL[j-1]
#define PIXEL_S imgInNextL[j]
#define PIXEL_T imgInNextL[j+1]

#define LABEL_H imgOutPrevL[j-1]
#define LABEL_I imgOutPrevL[j]
#define LABEL_J imgOutPrevL[j+1]
#define LABEL_K imgOutPrevL[j+2]
#define LABEL_O imgOutL[j]
#define LABEL_P imgOutL[j+1]
#define LABEL_R imgOutNextL[j-1]
#define LABEL_S imgOutNextL[j]
#define LABEL_T imgOutNextL[j+1]

#define LABEL_BLOCK_A imgOutPrevL[j-2]
#define LABEL_BLOCK_B imgOutPrevL[j]
#define LABEL_BLOCK_C imgOutPrevL[j+2]
#define LABEL_BLOCK_D imgOutNextL[j-2]
#define LABEL_BLOCK_E imgOutNextL[j]

#define hLABEL_BLOCK_A imgOutPrevL[j-1]
#define hLABEL_BLOCK_B imgOutPrevL[j]
#define hLABEL_BLOCK_C imgOutPrevL[j+1]
#define hLABEL_BLOCK_E imgOutNextL[j]


#endif
