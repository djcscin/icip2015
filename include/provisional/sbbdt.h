#ifndef _sBBDT_
#define _sBBDT_

#include "unionFind.h"
#include "mytime.h"
#include "global.h"
#include "declarations.h"
#include "blocks.h"

#define action_NO
#define action_NLB  EXTRA_ACTION make(); LABEL_BLOCK_E=lastLabel;
#define action_AQ   EXTRA_ACTION LABEL_BLOCK_E=LABEL_BLOCK_B;
#define action_AP   EXTRA_ACTION LABEL_BLOCK_E=LABEL_BLOCK_A;
#define action_AS   EXTRA_ACTION LABEL_BLOCK_E=LABEL_BLOCK_D;
#define action_MPQ  EXTRA_ACTION lab=LABEL_BLOCK_A; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_B);
#define action_MQS  EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_B);
#define action_MPS  EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_A);
#define action_MPQS EXTRA_ACTION lab=LABEL_BLOCK_D; LABEL_BLOCK_E=lab; merge(lab,LABEL_BLOCK_A); merge(lab,LABEL_BLOCK_B);
#define action_MQSX merge(LABEL_BLOCK_D,LABEL_BLOCK_B);
#define action_MQSN action_NLB action_MQSX

void sbbdt() {
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
                if (PIXEL_H) {
                    if (PIXEL_N) {
                        if (PIXEL_I) {
                            action_AP
                        } else {
                            if (PIXEL_C) {
                                action_AP
                            } else {
                                if (PIXEL_J) {
                                    action_MPQ
                                } else {
                                    action_AP
                                }
                            }
                        }
                    } else {
                        if (PIXEL_R) {
                            if (PIXEL_M) {
                                if (PIXEL_I) {
                                    action_AP
                                } else {
                                    if (PIXEL_C) {
                                        action_AP
                                    } else {
                                        if (PIXEL_J) {
                                            action_MPQ
                                        } else {
                                            action_AP
                                        }
                                    }
                                }
                            } else {
                                if (PIXEL_I) {
                                    action_MPS
                                } else {
                                    if (PIXEL_C) {
                                        action_MPS
                                    } else {
                                        if (PIXEL_J) {
                                            action_MPQS
                                        } else {
                                            action_MPS
                                        }
                                    }
                                }
                            }
                        } else {
                            if (PIXEL_I) {
                                action_AP
                            } else {
                                if (PIXEL_C) {
                                    action_AP
                                } else {
                                    if (PIXEL_J) {
                                        action_MPQ
                                    } else {
                                        action_AP
                                    }
                                }
                            }
                        }
                    }
                } else {
                    if (PIXEL_N) {
                        if (PIXEL_I) {
                            if (PIXEL_G) {
                                if (PIXEL_B) {
                                    action_AP
                                } else {
                                    action_MPQ
                                }
                            } else {
                                action_MQS
                            }
                        } else {
                            if (PIXEL_J) {
                                if (PIXEL_G) {
                                    if (PIXEL_B) {
                                        if (PIXEL_C) {
                                            action_AP
                                        } else {
                                            action_MPQ
                                        }
                                    } else {
                                        action_MPQ
                                    }
                                } else {
                                    action_MQS
                                }
                            } else {
                                action_AS
                            }
                        }
                    } else {
                        if (PIXEL_R) {
                            if (PIXEL_I) {
                                if (PIXEL_G) {
                                    if (PIXEL_B) {
                                        if (PIXEL_M) {
                                            action_AP
                                        } else {
                                            action_MPS
                                        }
                                    } else {
                                        action_MQS
                                    }
                                } else {
                                    action_MQS
                                }
                            } else {
                                if (PIXEL_J) {
                                    if (PIXEL_G) {
                                        if (PIXEL_B) {
                                            if (PIXEL_C) {
                                                if (PIXEL_M) {
                                                    action_AP
                                                } else {
                                                    action_MPS
                                                }
                                            } else {
                                                action_MQS
                                            }
                                        } else {
                                            action_MQS
                                        }
                                    } else {
                                        action_MQS
                                    }
                                } else {
                                    action_AS
                                }
                            }
                        } else {
                            if (PIXEL_I) {
                                action_AQ
                            } else {
                                if (PIXEL_J) {
                                    action_AQ
                                } else {
                                    action_NLB
                                }
                            }
                        }
                    }
                }
            } else {
                if (PIXEL_P) {
                    if (PIXEL_I) {
                        if (PIXEL_N) {
                            if (PIXEL_H) {
                                action_AP
                            } else {
                                if (PIXEL_G) {
                                    if (PIXEL_B) {
                                        action_AP
                                    } else {
                                        action_MPQ
                                    }
                                } else {
                                    action_MQS
                                }
                            }
                        } else {
                            if (PIXEL_S) {
                                if (PIXEL_R) {
                                    if (PIXEL_M) {
                                        if (PIXEL_H) {
                                            action_AP
                                        } else {
                                            if (PIXEL_G) {
                                                if (PIXEL_B) {
                                                    action_AP
                                                } else {
                                                    action_MPQ
                                                }
                                            } else {
                                                action_MQS
                                            }
                                        }
                                    } else {
                                        action_MQS
                                    }
                                } else {
                                    action_AQ
                                }
                            } else {
                                action_AQ
                            }
                        }
                    } else {
                        if (PIXEL_J) {
                            if (PIXEL_S) {
                                if (PIXEL_N) {
                                    if (PIXEL_C) {
                                        if (PIXEL_H) {
                                            action_AP
                                        } else {
                                            if (PIXEL_G) {
                                                if (PIXEL_B) {
                                                    action_AP
                                                } else {
                                                    action_MPQ
                                                }
                                            } else {
                                                action_MQS
                                            }
                                        }
                                    } else {
                                        action_MQS
                                    }
                                } else {
                                    if (PIXEL_R) {
                                        if (PIXEL_C) {
                                            if (PIXEL_M) {
                                                if (PIXEL_H) {
                                                    action_AP
                                                } else {
                                                    if (PIXEL_G) {
                                                        if (PIXEL_B) {
                                                            action_AP
                                                        } else {
                                                            action_MPQ
                                                        }
                                                    } else {
                                                        action_MQS
                                                    }
                                                }
                                            } else {
                                                action_MQS
                                            }
                                        } else {
                                            action_MQS
                                        }
                                    } else {
                                        action_AQ
                                    }
                                }
                            } else {
                                action_AQ
                            }
                        } else {
                            if (PIXEL_S) {
                                if (PIXEL_N) {
                                    action_AS
                                } else {
                                    if (PIXEL_R) {
                                        action_AS
                                    } else {
                                        action_NLB
                                    }
                                }
                            } else {
                                action_NLB
                            }
                        }
                    }
                } else {
                    if (PIXEL_N) {
                        if (PIXEL_S) {
                            if (PIXEL_I) {
                                if (PIXEL_H) {
                                    action_AP
                                } else {
                                    if (PIXEL_G) {
                                        if (PIXEL_B) {
                                            action_AP
                                        } else {
                                            action_MPQ
                                        }
                                    } else {
                                        action_MQS
                                    }
                                }
                            } else {
                                action_AS
                            }
                        } else {
                            if (PIXEL_T) {
                                if (PIXEL_I) {
                                    if (PIXEL_H) {
                                        action_NLB
                                    } else {
                                        if (PIXEL_G) {
                                            if (PIXEL_B) {
                                                action_NLB
                                            } else {
                                                action_MQSN
                                            }
                                        } else {
                                            action_MQSN
                                        }
                                    }
                                } else {
                                    action_NLB
                                }
                            } else {
                                if (PIXEL_I) {
                                    if (PIXEL_H) {
                                        action_NO
                                    } else {
                                        if (PIXEL_G) {
                                            if (PIXEL_B) {
                                                action_NO
                                            } else {
                                                action_MQSX
                                            }
                                        } else {
                                            action_MQSX
                                        }
                                    }
                                } else {
                                    action_NO
                                }
                            }
                        }
                    } else {
                        if (PIXEL_R) {
                            if (PIXEL_S) {
                                action_AS
                            } else {
                                if (PIXEL_T) {
                                    action_NLB
                                } else {
                                    action_NO
                                }
                            }
                        } else {
                            if (PIXEL_S) {
                                action_NLB
                            } else {
                                if (PIXEL_T) {
                                    action_NLB
                                } else {
                                    action_NO
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //analysis phase
    FLATTEN
    //labeling phase
    LABELING_sBBDT

    FINIT_TIME
    FREE_UNION_FIND
    EXTRA_FREE
}

#endif
