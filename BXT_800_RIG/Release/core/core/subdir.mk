################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/CDC.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial0.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial1.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial2.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial3.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/IPAddress.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/PluggableUSB.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/Print.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/Stream.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/Tone.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/USBCore.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/WMath.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/WString.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/abi.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/main.cpp \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/new.cpp 

S_UPPER_SRCS += \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.S 

C_SRCS += \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/WInterrupts.c \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/hooks.c \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring.c \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_analog.c \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_digital.c \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.c \
/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_shift.c 

C_DEPS += \
./core/core/WInterrupts.c.d \
./core/core/hooks.c.d \
./core/core/wiring.c.d \
./core/core/wiring_analog.c.d \
./core/core/wiring_digital.c.d \
./core/core/wiring_pulse.c.d \
./core/core/wiring_shift.c.d 

AR_OBJ += \
./core/core/CDC.cpp.o \
./core/core/HardwareSerial.cpp.o \
./core/core/HardwareSerial0.cpp.o \
./core/core/HardwareSerial1.cpp.o \
./core/core/HardwareSerial2.cpp.o \
./core/core/HardwareSerial3.cpp.o \
./core/core/IPAddress.cpp.o \
./core/core/PluggableUSB.cpp.o \
./core/core/Print.cpp.o \
./core/core/Stream.cpp.o \
./core/core/Tone.cpp.o \
./core/core/USBCore.cpp.o \
./core/core/WInterrupts.c.o \
./core/core/WMath.cpp.o \
./core/core/WString.cpp.o \
./core/core/abi.cpp.o \
./core/core/hooks.c.o \
./core/core/main.cpp.o \
./core/core/new.cpp.o \
./core/core/wiring.c.o \
./core/core/wiring_analog.c.o \
./core/core/wiring_digital.c.o \
./core/core/wiring_pulse.S.o \
./core/core/wiring_pulse.c.o \
./core/core/wiring_shift.c.o 

S_UPPER_DEPS += \
./core/core/wiring_pulse.S.d 

CPP_DEPS += \
./core/core/CDC.cpp.d \
./core/core/HardwareSerial.cpp.d \
./core/core/HardwareSerial0.cpp.d \
./core/core/HardwareSerial1.cpp.d \
./core/core/HardwareSerial2.cpp.d \
./core/core/HardwareSerial3.cpp.d \
./core/core/IPAddress.cpp.d \
./core/core/PluggableUSB.cpp.d \
./core/core/Print.cpp.d \
./core/core/Stream.cpp.d \
./core/core/Tone.cpp.d \
./core/core/USBCore.cpp.d \
./core/core/WMath.cpp.d \
./core/core/WString.cpp.d \
./core/core/abi.cpp.d \
./core/core/main.cpp.d \
./core/core/new.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
core/core/CDC.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/CDC.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/HardwareSerial.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/HardwareSerial0.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial0.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/HardwareSerial1.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial1.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/HardwareSerial2.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial2.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/HardwareSerial3.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/HardwareSerial3.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/IPAddress.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/PluggableUSB.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/PluggableUSB.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/Print.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/Print.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/Stream.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/Stream.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/Tone.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/Tone.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/USBCore.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/WInterrupts.c.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/WMath.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/WMath.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/WString.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/WString.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/abi.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/abi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/hooks.c.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/hooks.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/main.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/main.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/new.cpp.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/new.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring.c.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_analog.c.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_digital.c.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_pulse.S.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.S
	@echo 'Building file: $<'
	@echo 'Starting S compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)"  "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_pulse.c.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/wiring_shift.c.o: /opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino/wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -c -g -Os -Wall -Wextra -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -I"/home/realslimshady/Arduino/libraries/eeprom-counter-library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


