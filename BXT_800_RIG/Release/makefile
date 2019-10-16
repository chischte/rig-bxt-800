################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries/insomnia-delay-library/subdir.mk
-include libraries/cylinder-library/subdir.mk
-include libraries/SoftwareSerial/src/subdir.mk
-include libraries/SPI/src/subdir.mk
-include libraries/SD/src/utility/subdir.mk
-include libraries/SD/src/subdir.mk
-include libraries/Nextion/subdir.mk
-include libraries/ITEADLIB_Arduino_Nextion/subdir.mk
-include libraries/CONTROLLINO/subdir.mk
-include core/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
/home/realslimshady/git/bxt-800-rig/BXT_800_RIG/Release/arduino.ar \

ELF += \
BXT_800_RIG.elf \

HEX += \
BXT_800_RIG.hex \


# All Target
all: BXT_800_RIG

# Tool invocations
BXT_800_RIG: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-size" -A "/home/realslimshady/git/bxt-800-rig/BXT_800_RIG/Release/BXT_800_RIG.elf"
	@echo 'Finished building target: $@'
	@echo ' '

/home/realslimshady/git/bxt-800-rig/BXT_800_RIG/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc-ar" rcs     /home/realslimshady/git/bxt-800-rig/BXT_800_RIG/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

BXT_800_RIG.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/opt/eclipsearduino/sloeber//arduinoPlugin/packages/arduino/tools/avr-gcc/5.4.0-atmel3.6.1-arduino2/bin/avr-gcc" -Wall -Wextra -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega2560  -o "/home/realslimshady/git/bxt-800-rig/BXT_800_RIG/Release/BXT_800_RIG.elf"   $(LINK_OBJ)   /home/realslimshady/git/bxt-800-rig/BXT_800_RIG/Release/arduino.ar  "-L/home/realslimshady/git/bxt-800-rig/BXT_800_RIG/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

BXT_800_RIG.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
