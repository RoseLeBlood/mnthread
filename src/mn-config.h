#ifndef __MINLIB_MNTHREAD_CONFIG_H__
#define __MINLIB_MNTHREAD_CONFIG_H__

#define MN_THREAD_MAJOR_VERSION 1
#define MN_THREAD_MINOR_VERSION 0
#define MN_THREAD_DEBUG_VERSION 6

#define MN_THREAD_CONFIG_MUTEX      1
#define MN_THREAD_CONFIG_SPINLOCK   2

#define MN_THREAD_CONFIG_AUTOLOCK MN_THREAD_CONFIG_MUTEX

// Ab hier nichts verändern | DO NOT EDIT AFTER THIS LINE!!!
#define MN_THREAD_CONFIG_THREAD_LOCK MN_THREAD_CONFIG_MUTEX



#endif
