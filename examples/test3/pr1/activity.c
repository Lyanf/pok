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

#include "aes.h"

uint8_t key[] = {
		0x00, 0x01, 0x02, 0x03,
		0x04, 0x05, 0x06, 0x07,
		0x08, 0x09, 0x0a, 0x0b,
		0x0c, 0x0d, 0x0e, 0x0f,
		0x10, 0x11, 0x12, 0x13,
		0x14, 0x15, 0x16, 0x17,
		0x18, 0x19, 0x1a, 0x1b,
		0x1c, 0x1d, 0x1e, 0x1f};

	uint8_t in[] = {
		0x00, 0x11, 0x22, 0x33,
		0x44, 0x55, 0x66, 0x77,
		0x88, 0x99, 0xaa, 0xbb,
		0xcc, 0xdd, 0xee, 0xff};
extern uint8_t sid;
uint8_t val;

void printu64(uint64_t x) {
    char* p = &x;
    for(int i = 0; i < 8; ++i) {
    	printf("%x", p[i]);
    }

}
void cpu_work(int cycle,int id) {
	uint64_t q = 1;
	pok_time_t start, end;

	uint8_t out[16]; // 128

	uint8_t *w; // expanded key	
	 
 	w = aes_init(sizeof(key));

	pok_time_get(&start);
	for(int i = 0; i < 1000; ++i) {
		aes_key_expansion(key, w);
	}
	pok_time_get(&end);
	int i = 0;
// 	for(int i = 0; i < 100000; i++) {
// 		aes_cipher(in /* in */, out /* out */, w /* expanded key */);
// 	}

	//pok_time_get(&end);
	printf("time----%d: begin_time %u\n",id, start);
	printf("time----%d: end_time:%u\n",id, end);
	printf("time----%d: %u\n",id, end-start);
}
void* pinger_job()
{
	printf("thead 1 created\n");
	cpu_work(1000,1);
	printf("thead 1 finished\n");
	while(1);
}

void* pinger_job2()
{
	printf("thead 2 created\n");
	cpu_work(100,2);
	printf("thead 2 finished\n");
	while(1);
}

void* pinger_job3()
{
	printf("thead 3 created\n");
	cpu_work(500,3);
	printf("thead 3 finished\n");
	while(1);
}
