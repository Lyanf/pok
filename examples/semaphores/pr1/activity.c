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
#include <types.h>
#include <time.h>
extern uint8_t sid;
uint8_t val;
void cpu_work(int cycle) {
	clock_t start, end;
	start = clock();
	for (int i = 0; i < cycle; i++) {
		for (int j = 2; j < 10000; j++) {
			for (int k = 2; k < j; k++) {
				int temp = j % k;
			}
		}
	}
	end = clock();
	double re = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%lf\n", re);
}
void* pinger_job()
{
	cpu_work(10);
}

void* pinger_job2()
{
	cpu_work(20);
}

void* pinger_job3()
{
	cpu_work(5);
}