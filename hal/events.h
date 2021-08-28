#pragma once

#include <hal/gpio.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// type   | id
// 31 - 16 | 15 - 0
#define EVENT_TYPE(e) ((e) >> 16)
#define EVENT_ID(e) ((e)&0xFFFF)
#define EVENT(type, id) (((type) << 16) | ((id)&0xFFFF))

// event types
#define EVENT_NONE 0
#define EVENT_SYSTEM 1
#define EVENT_PRESS 2
#define EVENT_RELEASE 3
#define EVENT_TOGGLE 4
#define EVENT_KNOB 5
#define EVENT_REPEAT 6
#define EVENT_USB 7

// system events
#define EVENT_QUIT EVENT(EVENT_SYSTEM, 1)
#define EVENT_DISPLAY_READY EVENT(EVENT_SYSTEM, 2)

// press events
#define EVENT_PRESS_SELECT1 EVENT(EVENT_PRESS, BUTTON_SELECT1)
#define EVENT_PRESS_SELECT2 EVENT(EVENT_PRESS, BUTTON_SELECT2)
#define EVENT_PRESS_SELECT3 EVENT(EVENT_PRESS, BUTTON_SELECT3)
#define EVENT_PRESS_SELECT4 EVENT(EVENT_PRESS, BUTTON_SELECT4)

#define EVENT_PRESS_MAIN1 EVENT(EVENT_PRESS, BUTTON_MAIN1)
#define EVENT_PRESS_MAIN2 EVENT(EVENT_PRESS, BUTTON_MAIN2)
#define EVENT_PRESS_MAIN3 EVENT(EVENT_PRESS, BUTTON_MAIN3)
#define EVENT_PRESS_MAIN4 EVENT(EVENT_PRESS, BUTTON_MAIN4)
#define EVENT_PRESS_MAIN5 EVENT(EVENT_PRESS, BUTTON_MAIN5)
#define EVENT_PRESS_MAIN6 EVENT(EVENT_PRESS, BUTTON_MAIN6)

#define EVENT_PRESS_SUB1 EVENT(EVENT_PRESS, BUTTON_SUB1)
#define EVENT_PRESS_SUB2 EVENT(EVENT_PRESS, BUTTON_SUB2)
#define EVENT_PRESS_SUB3 EVENT(EVENT_PRESS, BUTTON_SUB3)

#define EVENT_PRESS_ENTER EVENT(EVENT_PRESS, BUTTON_ENTER)
#define EVENT_PRESS_UP EVENT(EVENT_PRESS, BUTTON_UP)
#define EVENT_PRESS_SHIFT EVENT(EVENT_PRESS, BUTTON_SHIFT)

#define EVENT_PRESS_DIALMODE EVENT(EVENT_PRESS, BUTTON_DIAL1)
#define EVENT_PRESS_CANCEL EVENT(EVENT_PRESS, BUTTON_DIAL2)
#define EVENT_PRESS_HOME EVENT(EVENT_PRESS, BUTTON_DIAL3)

// release events
#define EVENT_RELEASE_SELECT1 EVENT(EVENT_RELEASE, BUTTON_SELECT1)
#define EVENT_RELEASE_SELECT2 EVENT(EVENT_RELEASE, BUTTON_SELECT2)
#define EVENT_RELEASE_SELECT3 EVENT(EVENT_RELEASE, BUTTON_SELECT3)
#define EVENT_RELEASE_SELECT4 EVENT(EVENT_RELEASE, BUTTON_SELECT4)

#define EVENT_RELEASE_MAIN1 EVENT(EVENT_RELEASE, BUTTON_MAIN1)
#define EVENT_RELEASE_MAIN2 EVENT(EVENT_RELEASE, BUTTON_MAIN2)
#define EVENT_RELEASE_MAIN3 EVENT(EVENT_RELEASE, BUTTON_MAIN3)
#define EVENT_RELEASE_MAIN4 EVENT(EVENT_RELEASE, BUTTON_MAIN4)
#define EVENT_RELEASE_MAIN5 EVENT(EVENT_RELEASE, BUTTON_MAIN5)
#define EVENT_RELEASE_MAIN6 EVENT(EVENT_RELEASE, BUTTON_MAIN6)

#define EVENT_RELEASE_SUB1 EVENT(EVENT_RELEASE, BUTTON_SUB1)
#define EVENT_RELEASE_SUB2 EVENT(EVENT_RELEASE, BUTTON_SUB2)
#define EVENT_RELEASE_SUB3 EVENT(EVENT_RELEASE, BUTTON_SUB3)

#define EVENT_RELEASE_ENTER EVENT(EVENT_RELEASE, BUTTON_ENTER)
#define EVENT_RELEASE_UP EVENT(EVENT_RELEASE, BUTTON_UP)
#define EVENT_RELEASE_SHIFT EVENT(EVENT_RELEASE, BUTTON_SHIFT)

#define EVENT_RELEASE_DIALMODE EVENT(EVENT_RELEASE, BUTTON_DIAL1)
#define EVENT_RELEASE_CANCEL EVENT(EVENT_RELEASE, BUTTON_DIAL2)
#define EVENT_RELEASE_HOME EVENT(EVENT_RELEASE, BUTTON_DIAL3)

// repeat events
#define EVENT_REPEAT_SELECT1 EVENT(EVENT_REPEAT, BUTTON_SELECT1)
#define EVENT_REPEAT_SELECT2 EVENT(EVENT_REPEAT, BUTTON_SELECT2)
#define EVENT_REPEAT_SELECT3 EVENT(EVENT_REPEAT, BUTTON_SELECT3)
#define EVENT_REPEAT_SELECT4 EVENT(EVENT_REPEAT, BUTTON_SELECT4)

#define EVENT_REPEAT_MAIN1 EVENT(EVENT_REPEAT, BUTTON_MAIN1)
#define EVENT_REPEAT_MAIN2 EVENT(EVENT_REPEAT, BUTTON_MAIN2)
#define EVENT_REPEAT_MAIN3 EVENT(EVENT_REPEAT, BUTTON_MAIN3)
#define EVENT_REPEAT_MAIN4 EVENT(EVENT_REPEAT, BUTTON_MAIN4)
#define EVENT_REPEAT_MAIN5 EVENT(EVENT_REPEAT, BUTTON_MAIN5)
#define EVENT_REPEAT_MAIN6 EVENT(EVENT_REPEAT, BUTTON_MAIN6)

#define EVENT_REPEAT_SUB1 EVENT(EVENT_REPEAT, BUTTON_SUB1)
#define EVENT_REPEAT_SUB2 EVENT(EVENT_REPEAT, BUTTON_SUB2)
#define EVENT_REPEAT_SUB3 EVENT(EVENT_REPEAT, BUTTON_SUB3)

#define EVENT_REPEAT_ENTER EVENT(EVENT_REPEAT, BUTTON_ENTER)
#define EVENT_REPEAT_UP EVENT(EVENT_REPEAT, BUTTON_UP)
#define EVENT_REPEAT_SHIFT EVENT(EVENT_REPEAT, BUTTON_SHIFT)

#define EVENT_REPEAT_DIALMODE EVENT(EVENT_REPEAT, BUTTON_DIAL1)
#define EVENT_REPEAT_CANCEL EVENT(EVENT_REPEAT, BUTTON_DIAL2)
#define EVENT_REPEAT_HOME EVENT(EVENT_REPEAT, BUTTON_DIAL3)

// toggle events
#define EVENT_MODE EVENT(EVENT_TOGGLE, 1)
#define EVENT_STORAGE EVENT(EVENT_TOGGLE, 2)

// USB events
#define EVENT_USB_ERROR EVENT(EVENT_USB, 1)
#define EVENT_USB_CONNECT EVENT(EVENT_USB, 2)
#define EVENT_USB_DISCONNECT EVENT(EVENT_USB, 3)
#define EVENT_USB_FRONT_CARD_MOUNT EVENT(EVENT_USB, 4)
#define EVENT_USB_FRONT_CARD_UNMOUNT EVENT(EVENT_USB, 5)
#define EVENT_USB_REAR_CARD_MOUNT EVENT(EVENT_USB, 6)
#define EVENT_USB_REAR_CARD_UNMOUNT EVENT(EVENT_USB, 7)

  void Events_init(void);
  void Events_push(uint32_t e);
  uint32_t Events_pull(void);
  void Events_wait(void);
  bool Events_waitWithTimeout(uint32_t timeout);
  void Events_clear(void);

#ifdef __cplusplus
}
#endif
