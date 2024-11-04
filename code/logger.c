#include <stdio.h>

#include "logger.h"

void logmsg(char* message) {
	printlog("LOG", message, 34);
}

void loginfo(char* message) {
	printlog("INFO", message, 35);
}

void logerr(char* message) {
	printlog("ERR", message, 91);
}

void logsilent(char* message) {
	printf("%s\n", message);
}

void printlog(char* logtype, char* msg, int color) {
	printf("\033[1;%dm", color);
	printf("[%s] ", logtype);
	printf("\033[0:%dm", color);
	printf("%s\n", msg);
	printf("\033[0m");	
}
