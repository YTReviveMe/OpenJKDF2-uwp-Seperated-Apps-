#ifdef __cplusplus
#define EXTWRAP extern "C"
#else
#define EXTWRAP
#endif

EXTWRAP char* wininfo_getBundlePath(char* file); // TODO: Need to use buffers it I come back to this
EXTWRAP char* wininfo_getStatePath(char* file);
EXTWRAP void wininfo_getInstallPath(char* buffer);