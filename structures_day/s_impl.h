#ifndef __S_IMPL_H__
#define __S_IMPL_H__

typedef union u_value {
    int iValue;
    float fValue;
} WaveValue;

typedef enum e_shape {
    SQUARE,
    TRIANGLE,
    SAW,
    SINE
} WaveShape;

typedef struct t_wavepoint {
    WaveValue amplitude;
    WaveValue frequency;
    WaveShape shape;
} WavePoint;

extern void printWavePoint(WavePoint *wp); 

#endif // ifndef __S_IMPL_H__
