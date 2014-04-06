#include "dwm_status.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

static void setstatus(Display *display, const char *str) {
	XStoreName(display, DefaultRootWindow(display), str);
}

static int datetime(char *buf, size_t bufsize) {
	time_t t;
	struct tm *tm;

	t = time(NULL);
	tm = localtime(&t);
	if(tm == NULL) {
		fprintf(stderr, "Error getting localtime.\n");
		return -1;
	}

	if(!strftime(buf, bufsize, "%a %d %b %H:%M", tm)) {
		fprintf(stderr, "strftime is 0.\n");
		return -1;
	}

	return 0;
}

void dwm_status_init(struct dwm_status *status) {
	status->dt1[0] = 0;
	status->dt2[0] = 0;
	status->dt = status->dt1;
	status->other_dt = status->dt2;
}

int dwm_status_run(struct dwm_status *status, Display *display) {

	if(datetime(status->dt, DWM_STATUS_DATETIME_SIZE) != 0)
		return -1;
	if(strcmp(status->dt, status->other_dt) != 0) {
		setstatus(display, status->dt);
		if(status->dt == status->dt1) {
			status->dt = status->dt2;
			status->other_dt = status->dt1;
		}
		else {
			status->dt = status->dt1;
			status->other_dt = status->dt2;
		}
	}

	return 0;
}
