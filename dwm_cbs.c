#include "dwm_cbs.h"
#include "dwm_status.h"

static struct dwm_status status;

void dwm_cb_timer_init() {
	dwm_status_init(&status);
}

void dwm_cb_timer(Display *display) {
	static int initialized = 0;

	if(!initialized) {
		dwm_cb_timer_init();
		initialized = 1;
	}

	dwm_status_run(&status, display);
}
