SRC += features/oled.c features/rgb_matrix.c
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = yes
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
RGB_MATRIX_SUPPORTED = yes
OLED_ENABLE = yes
LTO_ENABLE = yes             # Enable link time optimization
# WPM_ENABLE = yes             # Enable words per minute output

