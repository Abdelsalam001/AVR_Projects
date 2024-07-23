################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
BUZZER_FREQ.lss \

FLASH_IMAGE += \
BUZZER_FREQ.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: BUZZER_FREQ.elf secondary-outputs

# Tool invocations
BUZZER_FREQ.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,BUZZER_FREQ.map -mmcu=atmega32 -o "BUZZER_FREQ.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

BUZZER_FREQ.lss: BUZZER_FREQ.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S BUZZER_FREQ.elf  >"BUZZER_FREQ.lss"
	@echo 'Finished building: $@'
	@echo ' '

BUZZER_FREQ.hex: BUZZER_FREQ.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex BUZZER_FREQ.elf  "BUZZER_FREQ.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: BUZZER_FREQ.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 BUZZER_FREQ.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) BUZZER_FREQ.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
