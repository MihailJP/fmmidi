#ifndef easywave_h
#define easywave_h

#include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif

void easywave_initialize(int frequency, int device);
void easywave_finalize(void);
void easywave_output(const short* data, size_t n);
void easywave_flush(void);
int easywave_pending_samples(void);

#ifdef __cplusplus
}
#endif

#endif
