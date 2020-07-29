# About:

A hardware specific implementation of the [gpio_hal.h](https://github.com/Ackleberry/gpio_hal) API for STM32F303xE microcontroller.

# Adding the module to your project:

Clone this repository into the driver section of your project. Only the contents of the `src` folder need to be included in the build. All other files are used for unit testing.

# UNIT Test Setup:

1. Install [Ruby](https://rubyinstaller.org/)

2. Install latest Ruby Rake gem:

    `gem install rake`

3. Install **32-Bit** GCC.

4. Clone the [Unity](https://github.com/ThrowTheSwitch/Unity) repository in the same directory level as your project folder.

# Running the UNIT Tests:

Open terminal in the directory, run `rake` or `rake all` to build and run the UNIT tests.

# Common Issues:

## `fatal error: sys/cdefs.h: No such file or directory`

This issue is caused by not having 32 bit GCC installed. If installing 32-Bit GCC is a hassle then you can update all occurances of `-m32` to `-m64` in the `target_gcc_32.yml` file.


