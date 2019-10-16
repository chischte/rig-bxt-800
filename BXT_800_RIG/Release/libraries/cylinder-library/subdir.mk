################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/realslimshady/Arduino/libraries/cylinder-library/Cylinder.cpp 

LINK_OBJ += \
./libraries/cylinder-library/Cylinder.cpp.o 

CPP_DEPS += \
./libraries/cylinder-library/Cylinder.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/cylinder-library/Cylinder.cpp.o: /home/realslimshady/Arduino/libraries/cylinder-library/Cylinder.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_MEGA2560 -DARDUINO_ARCH_AVR     -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/cores/arduino" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/CONTROLLINO_Boards/hardware/avr/3.0.2/variants/Controllino_mega" -I"/home/realslimshady/Arduino/libraries/CONTROLLINO" -I"/home/realslimshady/Arduino/libraries/cylinder-library" -I"/home/realslimshady/Arduino/libraries/insomnia-delay-library" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SoftwareSerial/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/packages/arduino/hardware/avr/1.6.23/libraries/SPI/src" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/SD/1.2.3/src" -I"/home/realslimshady/Arduino/libraries/ITEADLIB_Arduino_Nextion" -I"/opt/eclipsearduino/sloeber/arduinoPlugin/libraries/Nextion/1.1.0" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


