#ifndef _BBDT_
#define _BBDT_

#include "unionFind.h"
#include "mytime.h"
#include "global.h"
#include "declarations.h"
#include "blocks.h"

#define action_1
#define action_2 EXTRA_ACTION make(); LABEL_BLOCK_E=lastLabel;
#define action_3 EXTRA_ACTION LABEL_BLOCK_E=LABEL_BLOCK_C;
#define action_4 EXTRA_ACTION LABEL_BLOCK_E=LABEL_BLOCK_B;
#define action_5 EXTRA_ACTION LABEL_BLOCK_E=LABEL_BLOCK_A;
#define action_6 EXTRA_ACTION LABEL_BLOCK_E=LABEL_BLOCK_D;
#define action_7 EXTRA_ACTION lab=LABEL_BLOCK_B; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_C);
#define action_8 EXTRA_ACTION lab=LABEL_BLOCK_A; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_C);
#define action_9 EXTRA_ACTION lab=LABEL_BLOCK_A; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_B);
#define action_10 EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_C);
#define action_11 EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_B);
#define action_12 EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_A);
#define action_13 EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_B); merge(lab,LABEL_BLOCK_C);
#define action_14 EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_A); merge(lab,LABEL_BLOCK_C);
#define action_15 EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_A); merge(lab,LABEL_BLOCK_B);

void bbdt() {
    DEF_VARS_ROWS2_COLS
    LABEL lab; DECLARING_LAB_ARRAY
    EXTRA_DECLARATION
    IMG_IN_PREV_BLOCK
    IMG_IN_PREV_LINE
    IMG_IN_LINE
    IMG_IN_NEXT_LINE
    IMG_OUT_PREV_LINE
    IMG_OUT_LINE
    IMG_OUT_NEXT_LINE

    INIT_UNION_FIND
    INIT_ALG
    EXTRA_INIT
    INIT_TIME

    //scanning phase
    for (FOR_ROWS) {
        for (FOR_COLS2) {
            if (PIXEL_O) {
                if (PIXEL_N) {
                    if (PIXEL_K) {
                        if (PIXEL_J) {
                            if (PIXEL_I) {
                                action_4
                            } else {
                                if (PIXEL_C) {
                                    if (PIXEL_H) {
                                        action_4
                                    } else {
                                        if (PIXEL_G) {
                                            if (PIXEL_B) {
                                                action_4
                                            } else {
                                                action_10
                                            }
                                        } else {
                                            action_10
                                        }
                                    }
                                } else {
                                    action_10
                                }
                            }
                        } else {
                            if (PIXEL_P) {
                                if (PIXEL_D) {
                                    if (PIXEL_I) {
                                        action_4
                                    } else {
                                        if (PIXEL_C) {
                                            if (PIXEL_H) {
                                                action_4
                                            } else {
                                                if (PIXEL_G) {
                                                    if (PIXEL_B) {
                                                        action_4
                                                    } else {
                                                        action_10
                                                    }
                                                } else {
                                                    action_10
                                                }
                                            }
                                        } else {
                                            action_10
                                        }
                                    }
                                } else {
                                    action_10
                                }
                            } else {
                                if (PIXEL_I) {
                                    action_4
                                } else {
                                    if (PIXEL_C) {
                                        if (PIXEL_H) {
                                            action_4
                                        } else {
                                            if (PIXEL_G) {
                                                if (PIXEL_B) {
                                                    action_4
                                                } else {
                                                    action_6
                                                }
                                            } else {
                                                action_6
                                            }
                                        }
                                    } else {
                                        action_6
                                    }
                                }
                            }
                        }
                    } else {
                        if (PIXEL_I) {
                            action_4
                        } else {
                            if (PIXEL_C) {
                                if (PIXEL_H) {
                                    action_4
                                } else {
                                    if (PIXEL_G) {
                                        if (PIXEL_B) {
                                            action_4
                                        } else {
                                            if (PIXEL_J) {
                                                if (PIXEL_E) {
                                                    action_10
                                                } else {
                                                    action_11
                                                }
                                            } else {
                                                action_6
                                            }
                                        }
                                    } else {
                                        if (PIXEL_J) {
                                            if (PIXEL_E) {
                                                action_10
                                            } else {
                                                action_11
                                            }
                                        } else {
                                            action_6
                                        }
                                    }
                                }
                            } else {
                                if (PIXEL_J) {
                                    if (PIXEL_E) {
                                        action_10
                                    } else {
                                        action_11
                                    }
                                } else {
                                    action_6
                                }
                            }
                        }
                    }
                } else {
                    if (PIXEL_J) {
                        if (PIXEL_H) {
                            if (PIXEL_M) {
                                if (PIXEL_I) {
                                    action_4
                                } else {
                                    if (PIXEL_C) {
                                        action_4
                                    } else {
                                        if (PIXEL_K) {
                                            action_10
                                        } else {
                                            if (PIXEL_E) {
                                                action_10
                                            } else {
                                                action_11
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (PIXEL_R) {
                                    if (PIXEL_K) {
                                        if (PIXEL_I) {
                                            action_10
                                        } else {
                                            if (PIXEL_C) {
                                                action_10
                                            } else {
                                                action_14
                                            }
                                        }
                                    } else {
                                        if (PIXEL_I) {
                                            if (PIXEL_E) {
                                                action_10
                                            } else {
                                                action_11
                                            }
                                        } else {
                                            if (PIXEL_E) {
                                                if (PIXEL_C) {
                                                    action_10
                                                } else {
                                                    action_14
                                                }
                                            } else {
                                                if (PIXEL_C) {
                                                    action_11
                                                } else {
                                                    action_15
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (PIXEL_I) {
                                        action_4
                                    } else {
                                        if (PIXEL_C) {
                                            action_4
                                        } else {
                                            if (PIXEL_K) {
                                                action_8
                                            } else {
                                                if (PIXEL_E) {
                                                    action_8
                                                } else {
                                                    action_9
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (PIXEL_R) {
                                if (PIXEL_M) {
                                    if (PIXEL_G) {
                                        if (PIXEL_B) {
                                            if (PIXEL_I) {
                                                action_4
                                            } else {
                                                if (PIXEL_C) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_K) {
                                                        action_10
                                                    } else {
                                                        if (PIXEL_E) {
                                                            action_10
                                                        } else {
                                                            action_11
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (PIXEL_K) {
                                                action_10
                                            } else {
                                                if (PIXEL_E) {
                                                    action_10
                                                } else {
                                                    action_11
                                                }
                                            }
                                        }
                                    } else {
                                        if (PIXEL_K) {
                                            action_10
                                        } else {
                                            if (PIXEL_E) {
                                                action_10
                                            } else {
                                                action_11
                                            }
                                        }
                                    }
                                } else {
                                    if (PIXEL_K) {
                                        action_10
                                    } else {
                                        if (PIXEL_E) {
                                            action_10
                                        } else {
                                            action_11
                                        }
                                    }
                                }
                            } else {
                                action_4
                            }
                        }
                    } else {
                        if (PIXEL_K) {
                            if (PIXEL_P) {
                                if (PIXEL_H) {
                                    if (PIXEL_M) {
                                        if (PIXEL_D) {
                                            if (PIXEL_I) {
                                                action_4
                                            } else {
                                                if (PIXEL_C) {
                                                    action_4
                                                } else {
                                                    action_10
                                                }
                                            }
                                        } else {
                                            action_10
                                        }
                                    } else {
                                        if (PIXEL_R) {
                                            if (PIXEL_D) {
                                                if (PIXEL_I) {
                                                    action_10
                                                } else {
                                                    if (PIXEL_C) {
                                                        action_10
                                                    } else {
                                                        action_14
                                                    }
                                                }
                                            } else {
                                                action_14
                                            }
                                        } else {
                                            if (PIXEL_D) {
                                                if (PIXEL_I) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_C) {
                                                        action_4
                                                    } else {
                                                        action_8
                                                    }
                                                }
                                            } else {
                                                action_8
                                            }
                                        }
                                    }
                                } else {
                                    if (PIXEL_D) {
                                        if (PIXEL_R) {
                                            if (PIXEL_M) {
                                                if (PIXEL_G) {
                                                    if (PIXEL_B) {
                                                        if (PIXEL_I) {
                                                            action_4
                                                        } else {
                                                            if (PIXEL_C) {
                                                                action_4
                                                            } else {
                                                                action_10
                                                            }
                                                        }
                                                    } else {
                                                        action_10
                                                    }
                                                } else {
                                                    action_10
                                                }
                                            } else {
                                                action_10
                                            }
                                        } else {
                                            action_4
                                        }
                                    } else {
                                        if (PIXEL_I) {
                                            if (PIXEL_B) {
                                                if (PIXEL_M) {
                                                    if (PIXEL_G) {
                                                        action_10
                                                    } else {
                                                        if (PIXEL_R) {
                                                            action_14
                                                        } else {
                                                            action_8
                                                        }
                                                    }
                                                } else {
                                                    if (PIXEL_R) {
                                                        action_14
                                                    } else {
                                                        action_8
                                                    }
                                                }
                                            } else {
                                                if (PIXEL_R) {
                                                    action_13
                                                } else {
                                                    action_7
                                                }
                                            }
                                        } else {
                                            if (PIXEL_R) {
                                                action_10
                                            } else {
                                                action_3
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (PIXEL_R) {
                                    if (PIXEL_M) {
                                        if (PIXEL_I) {
                                            if (PIXEL_H) {
                                                action_4
                                            } else {
                                                if (PIXEL_G) {
                                                    if (PIXEL_B) {
                                                        action_4
                                                    } else {
                                                        if (PIXEL_D) {
                                                            action_10
                                                        } else {
                                                            action_11
                                                        }
                                                    }
                                                } else {
                                                    if (PIXEL_D) {
                                                        action_10
                                                    } else {
                                                        action_11
                                                    }
                                                }
                                            }
                                        } else {
                                            if (PIXEL_C) {
                                                if (PIXEL_H) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_G) {
                                                        if (PIXEL_B) {
                                                            action_4
                                                        } else {
                                                            action_6
                                                        }
                                                    } else {
                                                        action_6
                                                    }
                                                }
                                            } else {
                                                action_6
                                            }
                                        }
                                    } else {
                                        if (PIXEL_I) {
                                            if (PIXEL_D) {
                                                action_10
                                            } else {
                                                action_11
                                            }
                                        } else {
                                            if (PIXEL_H) {
                                                if (PIXEL_C) {
                                                    if (PIXEL_D) {
                                                        action_10
                                                    } else {
                                                        action_11
                                                    }
                                                } else {
                                                    action_12
                                                }
                                            } else {
                                                action_6
                                            }
                                        }
                                    }
                                } else {
                                    if (PIXEL_I) {
                                        action_4
                                    } else {
                                        if (PIXEL_H) {
                                            if (PIXEL_C) {
                                                action_4
                                            } else {
                                                if (PIXEL_M) {
                                                    action_6
                                                } else {
                                                    action_5
                                                }
                                            }
                                        } else {
                                            action_2
                                        }
                                    }
                                }
                            }
                        } else {
                            if (PIXEL_R) {
                                if (PIXEL_M) {
                                    if (PIXEL_I) {
                                        if (PIXEL_H) {
                                            action_4
                                        } else {
                                            if (PIXEL_G) {
                                                if (PIXEL_B) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_E) {
                                                        if (PIXEL_D) {
                                                            action_10
                                                        } else {
                                                            action_11
                                                        }
                                                    } else {
                                                        action_11
                                                    }
                                                }
                                            } else {
                                                if (PIXEL_E) {
                                                    if (PIXEL_D) {
                                                        action_10
                                                    } else {
                                                        action_11
                                                    }
                                                } else {
                                                    action_11
                                                }
                                            }
                                        }
                                    } else {
                                        if (PIXEL_C) {
                                            if (PIXEL_H) {
                                                action_4
                                            } else {
                                                if (PIXEL_G) {
                                                    if (PIXEL_B) {
                                                        action_4
                                                    } else {
                                                        action_6
                                                    }
                                                } else {
                                                    action_6
                                                }
                                            }
                                        } else {
                                            action_6
                                        }
                                    }
                                } else {
                                    if (PIXEL_I) {
                                        if (PIXEL_E) {
                                            if (PIXEL_D) {
                                                action_10
                                            } else {
                                                action_11
                                            }
                                        } else {
                                            action_11
                                        }
                                    } else {
                                        if (PIXEL_H) {
                                            if (PIXEL_C) {
                                                if (PIXEL_E) {
                                                    if (PIXEL_D) {
                                                        action_10
                                                    } else {
                                                        action_11
                                                    }
                                                } else {
                                                    action_11
                                                }
                                            } else {
                                                action_12
                                            }
                                        } else {
                                            action_6
                                        }
                                    }
                                }
                            } else {
                                if (PIXEL_I) {
                                    action_4
                                } else {
                                    if (PIXEL_H) {
                                        if (PIXEL_C) {
                                            action_4
                                        } else {
                                            if (PIXEL_M) {
                                                action_6
                                            } else {
                                                action_5
                                            }
                                        }
                                    } else {
                                        action_2
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (PIXEL_P) {
                    if (PIXEL_J) {
                        if (PIXEL_S) {
                            if (PIXEL_N) {
                                if (PIXEL_I) {
                                    action_4
                                } else {
                                    if (PIXEL_C) {
                                        if (PIXEL_H) {
                                            action_4
                                        } else {
                                            if (PIXEL_G) {
                                                if (PIXEL_B) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_K) {
                                                        action_10
                                                    } else {
                                                        if (PIXEL_E) {
                                                            action_10
                                                        } else {
                                                            action_11
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (PIXEL_K) {
                                                    action_10
                                                } else {
                                                    if (PIXEL_E) {
                                                        action_10
                                                    } else {
                                                        action_11
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (PIXEL_K) {
                                            action_10
                                        } else {
                                            if (PIXEL_E) {
                                                action_10
                                            } else {
                                                action_11
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (PIXEL_R) {
                                    if (PIXEL_M) {
                                        if (PIXEL_H) {
                                            if (PIXEL_I) {
                                                action_4
                                            } else {
                                                if (PIXEL_C) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_K) {
                                                        action_10
                                                    } else {
                                                        if (PIXEL_E) {
                                                            action_10
                                                        } else {
                                                            action_11
                                                        }
                                                    }
                                                }
                                            }
                                        } else {
                                            if (PIXEL_G) {
                                                if (PIXEL_B) {
                                                    if (PIXEL_I) {
                                                        action_4
                                                    } else {
                                                        if (PIXEL_C) {
                                                            action_4
                                                        } else {
                                                            if (PIXEL_K) {
                                                                action_10
                                                            } else {
                                                                if (PIXEL_E) {
                                                                    action_10
                                                                } else {
                                                                    action_11
                                                                }
                                                            }
                                                        }
                                                    }
                                                } else {
                                                    if (PIXEL_K) {
                                                        action_10
                                                    } else {
                                                        if (PIXEL_E) {
                                                            action_10
                                                        } else {
                                                            action_11
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (PIXEL_K) {
                                                    action_10
                                                } else {
                                                    if (PIXEL_E) {
                                                        action_10
                                                    } else {
                                                        action_11
                                                    }
                                                }
                                            }
                                        }
                                    } else {
                                        if (PIXEL_K) {
                                            action_10
                                        } else {
                                            if (PIXEL_E) {
                                                action_10
                                            } else {
                                                action_11
                                            }
                                        }
                                    }
                                } else {
                                    action_4
                                }
                            }
                        } else {
                            action_4
                        }
                    } else {
                        if (PIXEL_K) {
                            if (PIXEL_D) {
                                if (PIXEL_S) {
                                    if (PIXEL_N) {
                                        if (PIXEL_I) {
                                            action_4
                                        } else {
                                            if (PIXEL_C) {
                                                if (PIXEL_H) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_G) {
                                                        if (PIXEL_B) {
                                                            action_4
                                                        } else {
                                                            action_10
                                                        }
                                                    } else {
                                                        action_10
                                                    }
                                                }
                                            } else {
                                                action_10
                                            }
                                        }
                                    } else {
                                        if (PIXEL_R) {
                                            if (PIXEL_M) {
                                                if (PIXEL_H) {
                                                    if (PIXEL_I) {
                                                        action_4
                                                    } else {
                                                        if (PIXEL_C) {
                                                            action_4
                                                        } else {
                                                            action_10
                                                        }
                                                    }
                                                } else {
                                                    if (PIXEL_G) {
                                                        if (PIXEL_B) {
                                                            if (PIXEL_I) {
                                                                action_4
                                                            } else {
                                                                if (PIXEL_C) {
                                                                    action_4
                                                                } else {
                                                                    action_10
                                                                }
                                                            }
                                                        } else {
                                                            action_10
                                                        }
                                                    } else {
                                                        action_10
                                                    }
                                                }
                                            } else {
                                                action_10
                                            }
                                        } else {
                                            action_4
                                        }
                                    }
                                } else {
                                    action_4
                                }
                            } else {
                                if (PIXEL_I) {
                                    if (PIXEL_N) {
                                        action_10
                                    } else {
                                        if (PIXEL_H) {
                                            if (PIXEL_M) {
                                                action_10
                                            } else {
                                                if (PIXEL_S) {
                                                    if (PIXEL_R) {
                                                        action_14
                                                    } else {
                                                        action_8
                                                    }
                                                } else {
                                                    action_8
                                                }
                                            }
                                        } else {
                                            if (PIXEL_B) {
                                                if (PIXEL_M) {
                                                    if (PIXEL_G) {
                                                        action_10
                                                    } else {
                                                        if (PIXEL_S) {
                                                            if (PIXEL_R) {
                                                                action_14
                                                            } else {
                                                                action_8
                                                            }
                                                        } else {
                                                            action_8
                                                        }
                                                    }
                                                } else {
                                                    if (PIXEL_S) {
                                                        if (PIXEL_R) {
                                                            action_14
                                                        } else {
                                                            action_8
                                                        }
                                                    } else {
                                                        action_8
                                                    }
                                                }
                                            } else {
                                                if (PIXEL_S) {
                                                    if (PIXEL_R) {
                                                        action_13
                                                    } else {
                                                        action_7
                                                    }
                                                } else {
                                                    action_7
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    if (PIXEL_S) {
                                        if (PIXEL_R) {
                                            action_10
                                        } else {
                                            if (PIXEL_N) {
                                                action_10
                                            } else {
                                                action_3
                                            }
                                        }
                                    } else {
                                        action_3
                                    }
                                }
                            }
                        } else {
                            if (PIXEL_S) {
                                if (PIXEL_N) {
                                    if (PIXEL_I) {
                                        action_4
                                    } else {
                                        if (PIXEL_C) {
                                            if (PIXEL_H) {
                                                action_4
                                            } else {
                                                if (PIXEL_G) {
                                                    if (PIXEL_B) {
                                                        action_4
                                                    } else {
                                                        action_6
                                                    }
                                                } else {
                                                    action_6
                                                }
                                            }
                                        } else {
                                            action_6
                                        }
                                    }
                                } else {
                                    if (PIXEL_R) {
                                        if (PIXEL_M) {
                                            if (PIXEL_I) {
                                                if (PIXEL_H) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_G) {
                                                        if (PIXEL_B) {
                                                            action_4
                                                        } else {
                                                            if (PIXEL_E) {
                                                                if (PIXEL_D) {
                                                                    action_10
                                                                } else {
                                                                    action_11
                                                                }
                                                            } else {
                                                                action_11
                                                            }
                                                        }
                                                    } else {
                                                        if (PIXEL_E) {
                                                            if (PIXEL_D) {
                                                                action_10
                                                            } else {
                                                                action_11
                                                            }
                                                        } else {
                                                            action_11
                                                        }
                                                    }
                                                }
                                            } else {
                                                if (PIXEL_C) {
                                                    if (PIXEL_H) {
                                                        action_4
                                                    } else {
                                                        if (PIXEL_G) {
                                                            if (PIXEL_B) {
                                                                action_4
                                                            } else {
                                                                action_6
                                                            }
                                                        } else {
                                                            action_6
                                                        }
                                                    }
                                                } else {
                                                    action_6
                                                }
                                            }
                                        } else {
                                            if (PIXEL_I) {
                                                if (PIXEL_E) {
                                                    if (PIXEL_D) {
                                                        action_10
                                                    } else {
                                                        action_11
                                                    }
                                                } else {
                                                    action_11
                                                }
                                            } else {
                                                action_6
                                            }
                                        }
                                    } else {
                                        if (PIXEL_I) {
                                            action_4
                                        } else {
                                            action_2
                                        }
                                    }
                                }
                            } else {
                                if (PIXEL_I) {
                                    action_4
                                } else {
                                    action_2
                                }
                            }
                        }
                    }
                } else {
                    if (PIXEL_S) {
                        if (PIXEL_N) {
                            if (PIXEL_I) {
                                action_4
                            } else {
                                if (PIXEL_C) {
                                    if (PIXEL_H) {
                                        action_4
                                    } else {
                                        if (PIXEL_G) {
                                            if (PIXEL_B) {
                                                action_4
                                            } else {
                                                action_6
                                            }
                                        } else {
                                            action_6
                                        }
                                    }
                                } else {
                                    action_6
                                }
                            }
                        } else {
                            if (PIXEL_R) {
                                if (PIXEL_M) {
                                    if (PIXEL_H) {
                                        if (PIXEL_I) {
                                            action_4
                                        } else {
                                            if (PIXEL_C) {
                                                action_4
                                            } else {
                                                action_6
                                            }
                                        }
                                    } else {
                                        if (PIXEL_G) {
                                            if (PIXEL_B) {
                                                if (PIXEL_I) {
                                                    action_4
                                                } else {
                                                    if (PIXEL_C) {
                                                        action_4
                                                    } else {
                                                        action_6
                                                    }
                                                }
                                            } else {
                                                action_6
                                            }
                                        } else {
                                            action_6
                                        }
                                    }
                                } else {
                                    action_6
                                }
                            } else {
                                action_2
                            }
                        }
                    } else {
                        if (PIXEL_T) {
                            action_2
                        } else {
                            action_1
                        }
                    }
                }
            }
        }
    }
    //analysis phase
    FLATTEN
    //labeling phase
    LABELING_BBDT

    FINIT_TIME
    FREE_UNION_FIND
    EXTRA_FREE
}

#endif
