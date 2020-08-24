#ifndef MINLIB_ESP32_THREAD_
#define MINLIB_ESP32_THREAD_

#include "mn_autolock.hpp"
#include "mn_error.hpp"
#include "mn_sleep.hpp"
#include "mn_micros.hpp"

#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"



class  basic_thread {
public:
#if MN_THREAD_CONFIG_THREAD_LOCK == MN_THREAD_CONFIG_MUTEX
  using LockType_t = mutex_t;
#elif MN_THREAD_CONFIG_THREAD_LOCK == MN_THREAD_CONFIG_SPINLOCK
  using LockType_t = spinlock_t;
#endif

  basic_thread() { }
  basic_thread(char const* strName, unsigned int uiPriority,
       unsigned short  usStackDepth = configMINIMAL_STACK_SIZE);
	virtual ~basic_thread();

  int                   create(int uiCore = -1);
  int                   kill();

  bool                  is_running();

  const char*           get_name();
  unsigned int          get_priority();
  unsigned short        get_stackdepth();
  xTaskHandle           get_handle();
  void*                 get_return_value();
  uint32_t              get_time_since_start();
  uint32_t              get_id();
  uint32_t              get_on_core();

  void                  setPriority(unsigned int uiPriority);

  void                  suspend();
  void                  resume();

  virtual void*         on_thread() { thread_started(); return NULL; }

  basic_thread*         get_root();
  basic_thread*         get_child();

  bool                  add_child_thread(basic_thread* thread);

  void                  yield();

  /**
   *  Internal helper function to signal this thread.
   */
  inline void signal()  { //ThreadWaitSem.Give(); }
public:
  static void suspend(basic_thread *t)  { t->suspend(); }
  static void resume(basic_thread *t)   {   t->resume(); }
  static void yield()                   { taskYIELD(); }
  static void sleep(unsigned int secs)     { ::mn_sleep(secs); }
  static void usleep(unsigned int usec)     { ::mn_usleep(usec); }
  static void nsleep(const struct timespec *req, struct timespec *rem)     {
    ::mn_nsleep(req, rem);
  }

  static void lock(basic_thread * t)    { t->m_runningMutex->lock(); }
  static void unlock(basic_thread * t)    { t->m_runningMutex->unlock(); }
protected:
  static void runtaskstub(void* parm);
	void thread_started();
private:
  static uint32_t get_new_id();
protected:
  xTaskHandle handle;
  const char* m_strName;
  unsigned int m_uiPriority;
  unsigned short m_usStackDepth;
  void* m_retval;

  bool m_bMutexInit;
  bool m_bRunning;
  uint32_t m_iID;
  uint32_t m_iCore;
  LockType_t *m_runningMutex;
  LockType_t *m_contextMutext;

  LockType_t *m_continuemutex, *m_continuemutex2;

  spinlock_t ThreadWaitSem;
private:
  basic_thread *m_pChild;
  basic_thread *m_pParent;
};

using mthread = basic_thread;

#endif
