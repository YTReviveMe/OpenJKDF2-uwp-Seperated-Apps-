#ifdef __cplusplus
#define EXTWRAP extern "C"
#else
#define EXTWRAP
#endif

EXTWRAP void wininfo_getBundlePath(char* buffer, char* filename); // TODO: Need to use buffers it I come back to this
EXTWRAP void wininfo_getStatePath(char* buffer, char* filename);
EXTWRAP void wininfo_getInstallPath(char* buffer);