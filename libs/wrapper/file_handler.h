/*
 * file_handler.h
 *
 *  Created on: Mar 13, 2019
 *      Author: delgemoon
 */

#ifndef LIBS_WRAPPER_FILE_HANDLER_H_
#define LIBS_WRAPPER_FILE_HANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct log_ {
	FILE
};
int open_log(char* logfile);
int close_log();

#ifdef __cplusplus
}
#endif

#endif /* LIBS_WRAPPER_FILE_HANDLER_H_ */
