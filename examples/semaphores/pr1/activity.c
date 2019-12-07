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
#include <core/semaphore.h>
#include <core/time.h>
#include <types.h>
extern uint8_t sid;
uint8_t val;
void cpu_work(int cycle) {
	printf("################# test #################\n");
	uint64_t start, end;
	pok_time_get(&start);
	for (int i = 0; i < cycle; i++) {
//		for (int j = 2; j < 4; j++) {
//			for (int k = 2; k < j; k++) {
//				int temp = j % k;
//			}
//
		//}
		pok_thread_sleep(2000000);
	}
	pok_time_get(&end);
	printf("time: %lu\n", end-start);
}
void* pinger_job()
{
	printf("thead 1");
	cpu_work(10);
	while(1);
}

void* pinger_job2()
{
	printf("thread 2");
	cpu_work(20);
	while(1);
}

void* pinger_job3()
{
	printf("thread 3");
	cpu_work(5);
	while(1);
}
