#include <stdio.h>
#include <string.h>
#include <IOKit/hidsystem/IOHIDLib.h>
#include <IOKit/hidsystem/IOHIDParameter.h>
#include <IOKit/hidsystem/event_status_driver.h>

int main(void) {
    io_connect_t h;
    const int32_t a = INT32_MIN;
    if ((h = NXOpenEventStatus())) {
        CFStringRef t = CFSTR(kIOHIDMouseAccelerationType);
        if (IOHIDSetParameter(h, t, &a, sizeof(a)) != KERN_SUCCESS) {
            fputs("Failed to set HID parameters.\n", stderr);
            NXCloseEventStatus(h);
            return 1;
        }
        NXCloseEventStatus(h);
        puts("HID parameters set successfully.");
    } else
        fputs("Couldn't acquire handle.\n", stderr);
        return 2;
    return 0;
}
