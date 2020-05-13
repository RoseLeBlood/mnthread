#ifndef MINLIB_ESP32_ERROR_
#define MINLIB_ESP32_ERROR_

#define ERR_MUTEX_OK                    0
#define ERR_MUTEX_ALREADYINIT					 -1
#define ERR_MUTEX_NOTINIT						   -2
#define ERR_MUTEX_CANTCREATEMUTEX			 -3

#define ERR_SPINLOCK_OK                 0
#define ERR_SPINLOCK_ALREADYINIT				-10
#define ERR_SPINLOCK_NOTINIT						-20
#define ERR_SPINLOCK_CANTCREATEMUTEX		-30

#define ERR_THREAD_OK                    ERR_MUTEX_OK
#define ERR_THREAD_CANTINITMUTEX				-4
#define ERR_THREAD_CANTSTARTTHREAD			-5
#define ERR_THREAD_THREADFUNCNOTSET			-6
#define ERR_THREAD_NOTRUNNING						-7
#define ERR_THREAD_ALREADYRUNNING				-8

#endif
