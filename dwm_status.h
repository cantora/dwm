#ifndef DWM_STATUS_H
#define DWM_STATUS_H

#include <X11/Xlib.h>

#define DWM_STATUS_DATETIME_SIZE 256
struct dwm_status {
	char dt1[DWM_STATUS_DATETIME_SIZE];
	char dt2[DWM_STATUS_DATETIME_SIZE];
	char *dt, *other_dt;
};

void dwm_status_init(struct dwm_status *status);
int dwm_status_run(struct dwm_status *status, Display *display);

#endif /* DWM_STATUS_H */
