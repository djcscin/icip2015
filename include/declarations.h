#ifndef _DECLARATIONS_
#define _DECLARATIONS_

#define _IMG_IN_PREV_BLOCK_ imgInPrevB = imgIn[BORDER_SIZE - 2];
#define _IMG_IN_PREV_LINE_  imgInPrevL = imgIn[BORDER_SIZE - 1];
#define _IMG_IN_LINE_       imgInL = imgIn[BORDER_SIZE];
#define _IMG_IN_NEXT_LINE_  imgInNextL = imgIn[BORDER_SIZE + 1];
#define _IMG_IN_2NEXT_LINE_ imgInNext2L = imgIn[BORDER_SIZE + 2];

#define _IMG_OUT_PREV_LINE_ imgOutPrevL = imgOut[BORDER_SIZE - 1];
#define _IMG_OUT_LINE_      imgOutL = imgOut[BORDER_SIZE];
#define _IMG_OUT_NEXT_LINE_ imgOutNextL = imgOut[BORDER_SIZE + 1];

#define IMG_IN_PREV_BLOCK   PIXEL * const _IMG_IN_PREV_BLOCK_
#define IMG_IN_PREV_LINE    PIXEL * const _IMG_IN_PREV_LINE_
#define IMG_IN_LINE         PIXEL * const _IMG_IN_LINE_
#define IMG_IN_NEXT_LINE    PIXEL * const _IMG_IN_NEXT_LINE_

#define IMG_OUT_PREV_LINE   LABEL * const _IMG_OUT_PREV_LINE_
#define IMG_OUT_LINE        LABEL * const _IMG_OUT_LINE_
#define IMG_OUT_NEXT_LINE   LABEL * const _IMG_OUT_NEXT_LINE_


#define _JEND   (width - BORDER_SIZE)
#define _END    ((height - BORDER_SIZE - BORDER_SIZE) * width - BORDER_SIZE)
#define _END0   ((height - BORDER_SIZE - BORDER_SIZE) * width - BORDER_SIZE - BORDER_SIZE)

#define DEF_VARS_CELLS                          int i; const int _end = _END;
#define INI_VARS_ROWS_COLS(_JEND,_END,_ADD)     const int _jend = _JEND, _end = _END, _add = _ADD;
#define DEF_VARS_ROWS_COLS(_JEND,_END,_ADD)     int i, j, jend; INI_VARS_ROWS_COLS(_JEND,_END,_ADD)
#define _DEF_VARS_ROWS_COLS_(_JEND,_END,_ADD)   int i, j; INI_VARS_ROWS_COLS(_JEND,_END,_ADD)

#define DEF_VARS_ROWS1_COLS     DEF_VARS_ROWS_COLS(_JEND,_END,width)
#define DEF_VARS_ROWS2_COLS     DEF_VARS_ROWS_COLS(_JEND,_END,width+width)

#define FOR_ROWS    i = BORDER_SIZE, jend = _jend; i < _end; i += _add, jend += _add
#define FOR_COLS1   j = i; j < jend; ++j
#define FOR_COLS2   j = i; j < jend; j += 2
#define FOR_CELLS1  i = BORDER_SIZE; i < _end; ++i
#define FOR_CELLS2  i = BORDER_SIZE; i < _end; i += 2


#define _DEF_VARS_ROWS1_COLS_    _DEF_VARS_ROWS_COLS_(_JEND,_END,width)
#define _DEF_VARS_ROWS2_COLS_    _DEF_VARS_ROWS_COLS_(_JEND,_END,width+width)
#define _DEF_VARS_ROWS1e2_COLS_  _DEF_VARS_ROWS1_COLS_ const int _addD = width + width;

#define _DEF_VARS0_ROWS1_COLS_   _DEF_VARS_ROWS_COLS_(_JEND,_END0,width)
#define _DEF_VARS0_ROWS2_COLS_   _DEF_VARS_ROWS_COLS_(_JEND,_END0,width+width)
#define _DEF_VARS0_ROWS1e2_COLS_ _DEF_VARS0_ROWS1_COLS_ const int _addD = width + width;

#define _FOR_ROWS_          i = BORDER_SIZE; i < _end; i += _add
#define _FOR_ROWS_D_        i = BORDER_SIZE; i < _end; i += _addD
#define _FOR0_ROWS_         i = 0; i < _end; i += _add
#define _FOR0_ROWS_D_       i = 0; i < _end; i += _addD

#define _FOR_COLS1_         j = BORDER_SIZE; j < _jend; ++j
#define _FOR_COLS2_         j = BORDER_SIZE; j < _jend; j += 2
#define _FOR_CELLS1_        i = BORDER_SIZE; i < _end; ++i
#define _FOR_CELLS2_        i = BORDER_SIZE; i < _end; i += 2

#define _FOR_COLS1_BORDER_  j = BORDER_SIZE-1; j <= _jend; ++j
#define _FOR_COLS2_BORDER_  j = BORDER_SIZE-1; j <= _jend; j += 2
#define _FOR_CELLS1_BORDER_ i = BORDER_SIZE-1; i <= _end; ++i
#define _FOR_CELLS2_BORDER_ i = BORDER_SIZE-1; i <= _end; i += 2

#endif
