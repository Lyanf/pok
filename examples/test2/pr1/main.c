/*
 *                               POK header
 * 
 * The following file is a part of the POK project. Any modification should
 * made according to the POK licence. You CANNOT use this file or a part of
 * this file is this part of a file for your own project
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2009 POK team 
 *
 * Created by julien on Thu Jan 15 23:34:13 2009 
 */


#include <libc/stdio.h>
#include <core/thread.h>
#include <core/partition.h>
#include <core/semaphore.h>
#include <types.h>
#include "activity.h"

#include <types.h>

#include <core/time.h>

uint8_t sid;

// int functest() {
// 	return 0;
// }

int main ()
{
	
  uint8_t tid;
  pok_ret_t ret;
  pok_thread_attr_t     tattr;

//   uint64_t tp;
//   pok_time_get(&tp);

  tattr.priority = 42;
  tattr.deadline = 10000000;

  tattr.entry = pinger_job;

  ret = pok_thread_create(&tid , &tattr);
  pok_thread_period();


  tattr.priority = 22;
  tattr.deadline = 5000000;

  tattr.entry = pinger_job2;


  ret = pok_thread_create(&tid , &tattr);

  pok_thread_period();



  tattr.priority = 32;
  tattr.deadline = 3000000;

  tattr.entry = pinger_job3;
  ret = pok_thread_create(&tid, &tattr);
  pok_thread_period();



  pok_partition_set_mode (POK_PARTITION_MODE_NORMAL);
  pok_thread_wait_infinite ();

   return (0);
}
