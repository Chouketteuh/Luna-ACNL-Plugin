#include <3ds.h>

Result __sync_fini(void) __attribute__((weak));

void    envDestroyHandles(void);

void     __libctru_exit(int rc)
{
    envDestroyHandles();

    if (__sync_fini)
        __sync_fini();
}
