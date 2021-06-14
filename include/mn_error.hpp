/**
 * @file
 * This file is part of the Mini Thread Library (https://github.com/RoseLeBlood/MiniThread ).
 * @author Copyright (c) 2021 Amber-Sophia Schroeck
 * @par License
 * The Mini Thread Library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3, or (at your option) any later version.
 *
 * The Mini Thread Library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the Mini Thread  Library; if not, see
 * <https://www.gnu.org/licenses/>.
 */
#ifndef MINLIB_ESP32_ERROR_
#define MINLIB_ESP32_ERROR_

#include "mn_config.hpp"

/**
 * Begin the helper macro to switch ESP_ERRORS to MNTHREAD_ERROR errors
 * @param _error The holder of the error value
 *
 * @code
 *  int _error = esp_netif_set_mac(m_pNetIf, mac);
 * MN_ESP2MNTHREAD_ERROR_BEGIN(_error)
 * MN_ESP2MNTHREAD_ERROR_VAL(_error, ESP_OK, NO_ERROR);
 * MN_ESP2MNTHREAD_ERROR_VAL(_error, ESP_ERR_ESP_NETIF_IF_NOT_READY, ERR_MNTHREAD_NETIF_NOT_INIT);
 * MN_ESP2MNTHREAD_ERROR_VAL(_error, ESP_ERR_NOT_SUPPORTED, ERR_MNTHREAD_NOT_SUPPORTED);
 * MN_ESP2MNTHREAD_ERROR_END(_error);
 * @endcode
 */
#define MN_ESP2MNTHREAD_ERROR_BEGIN(_error)  			switch(_error) {
/**
 * the helper macro to switch ESP_ERRORS to MNTHREAD_ERROR errors
 * @param _error The holder of the error value and holder of the MNTHREAD_ERROR code
 * @param esp The esp value to find
 * @param mnt The MNTHREAD_ERROR to set
 */
#define MN_ESP2MNTHREAD_ERROR_VAL(_error, esp, mnt) 	case (esp): _error = (mnt); break;
/**
 * End the helper macro to switch ESP_ERRORS to MNTHREAD_ERROR errors
 * @param _error The holder of the error value - set to ERR_MNTHREAD_UNKN
 */
#define MN_ESP2MNTHREAD_ERROR_END(_error) 				default:  _error = (ERR_MNTHREAD_UNKN); break; }

/**
 * @ingroup base
 */

/**
 * No Error
 */
#define NO_ERROR                        0x0000

/**
 * Timed out
 */
#define ERR_MNTHREAD_TIMEOUT                     0x0001
/**
 * The given param was null or error in malloc
 */
#define ERR_MNTHREAD_NULL                        0x0002
/**
 * The function is not supported
 */
#define ERR_MNTHREAD_NOT_SUPPORTED               0x0005
/**
 * Currently not defined error
 */
#define ERR_MNTHREAD_UNKN                        0x0003
/**
 * Invalig Arguments
 */
#define ERR_MNTHREAD_INVALID_ARG				 0x0004

#define ERR_MNTHREAD_NETIF_NOT_INIT 			 0x0006
/**
 * Out of mem
 */
#define ERR_MNTHREAD_OUTOFMEM                    0x0007

/**
 * No Error in one of the mutex function
 */
#define ERR_MUTEX_OK                    NO_ERROR
/**
 * The mutex allready created
 */
#define ERR_MUTEX_ALREADYINIT			0x1001
/**
 * The mutex is not created, please call create first
 */
#define ERR_MUTEX_NOTINIT				0x1002
/**
 * The mutex can't create
 */
#define ERR_MUTEX_CANTCREATEMUTEX		0x1003
/**
 * It timed out on lock the mutex - mutex are not locked
 */
#define ERR_MUTEX_LOCK                  0x1004
/**
 * Error to unlock the mutex, call lock first
 */
#define ERR_MUTEX_UNLOCK                0x1005


// --------------------------------

/**
 * No Error in one of the spinlock or semaphore function
 */
#define ERR_SPINLOCK_OK                 NO_ERROR
/**
 * The spinlock or semaphore allready created
 */
#define ERR_SPINLOCK_ALREADYINIT		0x2001
/**
 * The spinlock or semaphore is not created, please call create first
 */
#define ERR_SPINLOCK_NOTINIT			0x2002
/**
 * The spinlock or semaphore can't create
 */
#define ERR_SPINLOCK_CANTCREATESPINLOCK	0x2003
/**
 * It timed out on lock the spinlock or semaphore - spinlock or semaphore are not locked
 */
#define ERR_SPINLOCK_LOCK               0x2004
/**
 * Error to unlock the spinlock or semaphore, call lock first
 */
#define ERR_SPINLOCK_UNLOCK             0x2005
/**
 * Count is bigger are the max count - spinlock not created
 */
#define ERR_SPINLOCK_BAD_INITIALCOUNT   0x2006

// --------------------------------

/**
 * No Error in one of the Thread function
 */
#define ERR_TASK_OK                   NO_ERROR
/**
 * The Lock objects are maked error
 */
#define ERR_TASK_CANTINITMUTEX		    0x3001
/**
 * The thread (i.e. task) can not start unknown error
 */
#define ERR_TASK_CANTSTARTTHREAD		0x3002
/**
 * The threah function is null
 */
#define ERR_TASK_THREADFUNCNOTSET		0x3003
/**
 * The thread is not running
 */
#define ERR_TASK_NOTRUNNING			    0x3004
/**
 * The thread can not start, becourse the thread is allready started
 */
#define ERR_TASK_ALREADYRUNNING		    0x3005
/**
 * Call task function wait and join from this task - this will not work!
 */
#define ERR_TASK_CALLFROMSELFTASK		0x3006
/**
 * The Lock objects are maked error
 */
#define ERR_TASK_CANTCREATEEVENTGROUP	 0x3007

// --------------------------------

/**
 * No Error in one of the Tasklet function
 */
#define ERR_COROUTINE_OK                   NO_ERROR
/**
 * Can not create the lock object for the tasklet, tasklet not created
 */
#define ERR_COROUTINE_CANTINITLOCKT  		0x4001
/**
 * Tasklet can not created
 */
#define ERR_COROUTINE_CANSHEDULE   		    0x4002

// --------------------------------

/**
 * No Error in one of the Queue function
 */
#define ERR_QUEUE_OK                    NO_ERROR
/**
 * The queue is allready Created
 */
#define ERR_QUEUE_ALREADYINIT			0x5001
/**
 * The queue can't created
 */
#define ERR_QUEUE_CANTCREATE			0x5002
/**
 * The queue is not created
 */
#define ERR_QUEUE_NOTCREATED            0x5003
/**
 * The item can not enqueued in the queue
 */
#define ERR_QUEUE_ADD                   0x5004
/**
 * The item can not remove from the queue
 */
#define ERR_QUEUE_REMOVE                0x5005
/**
 * No items in the queue
 */
#define ERR_QUEUE_PEEK                  0x5006
/**
 * Can not create the lock object for the blocking queue
 */
#define ERR_QUEUE_CANTCREATE_LOCK       0x5007

/**
 * No Error in one of the Timer function
 */
#define ERR_TIMER_OK                    NO_ERROR
/**
 * The timer is allready Created
 */
#define ERR_TIMER_ALREADYINIT			0x6001
/**
 * The timer can't created
 */
#define ERR_TIMER_CANTCREATE			0x6002
/**
 * The timer is not created
 */
#define ERR_TIMER_NOTCREATED            0x6003
/**
 * The timer can not start
 */
#define ERR_TIMER_AKTIVATE              0x6004
/**
 * The timer can not stop
 */
#define ERR_TIMER_INAKTIVATE            0x6005
/**
 * The timer can not reset
 */
#define ERR_TIMER_RESET                 0x6006

/**
 * No Error in one of the workqueue function
 */
#define ERR_WORKQUEUE_OK                    NO_ERROR
/**
 * The workqueue is allready Created
 */
#define ERR_WORKQUEUE_ALREADYINIT			0x7001
/**
 * The workqueue can't created
 */
#define ERR_WORKQUEUE_CANTCREATE			0x7002
/**
 * Warning
 */
#define ERR_WORKQUEUE_WARNING               0x7003
/**
 * The mutex can not init
 */
#define ERR_WORKQUEUE_CANTINITMUTEX         0x7004
/**
 * The item can not add to the workqueue
 */
#define ERR_WORKQUEUE_ADD                   0x7005


/**
 * Basis error - no error
 */
#define ERR_SYSTEM_OK                         NO_ERROR
/**
 * Basis error - error can not lock
 */
#define ERR_SYSTEM_LOCK                       0x0001
/**
 * Basis error - error can not unlock
 */
#define ERR_SYSTEM_UNLOCK                     0x0002
/**
 * Basis error - error in called functions
 */
#define ERR_SYSTEM_NO_RETURN                  0x0003


/**
 * No error
 */
#define ERR_MEMPOOL_OK                    NO_ERROR
/**
 * The given ligent im mempool are bad
 */
#define ERR_MEMPOOL_BADALIGNMENT          0x8003
/**
 * The mempool can not create
 */
#define ERR_MEMPOOL_CREATE                0x8004
/**
 * Reserve
 */
#define ERR_MEMPOOL_MIN                   0x8005

/**
 * No Error in one of the tickhook function
 */
#define ERR_TICKHOOK_OK                   NO_ERROR
/**
 * Error to add a new tickhook
 */
#define ERR_TICKHOOK_ADD                  0x9001
/**
 * The entry is null
 */
#define ERR_TICKHOOK_ENTRY_NULL           0x900A

#endif
