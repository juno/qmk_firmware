# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
AUDIO_ENABLE = no       # Audio output on port C6
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no   # Enable Bluetooth with the Adafruit EZ-Key HID
BOOTMAGIC_ENABLE = no   # Virtual DIP switch configuration(+1000)
COMMAND_ENABLE = no     # Commands for debug and configuration
CONSOLE_ENABLE = no     # Console for debug(+400)
EXTRAKEY_ENABLE = no    # Audio control and System control(+450)
MIDI_ENABLE = no        # MIDI controls
MOUSEKEY_ENABLE = no    # Mouse keys(+4700)
NKRO_ENABLE = no        # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE = yes   # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no   # Breathing sleep LED during USB suspend
SWAP_HANDS_ENABLE = no  # Enable one-hand typing
UNICODE_ENABLE = no     # Unicode

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

# Enable Link Time Optimization to saving amount of space
EXTRAFLAGS += -flto
