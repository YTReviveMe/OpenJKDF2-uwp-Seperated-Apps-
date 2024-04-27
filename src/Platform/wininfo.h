#ifdef __cplusplus
#define EXTWRAP extern "C"
#else
#define EXTWRAP
#endif

EXTWRAP char* wininfo_getBundlePath(char* file);
EXTWRAP char* wininfo_getStatePath(char* file);