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
FOUR_ISR.lss \

FLASH_IMAGE += \
FOUR_ISR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: FOUR_ISR.elf secondary-outputs

# Tool invocations
FOUR_ISR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,FOUR_ISR.map -mmcu=atmega32 -o "FOUR_ISR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

FOUR_ISR.lss: FOUR_ISR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S FOUR_ISR.elf  >"FOUR_ISR.lss"
	@echo 'Finished building: $@'
	@echo ' '

FOUR_ISR.hex: FOUR_ISR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex FOUR_ISR.elf  "FOUR_ISR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: FOUR_ISR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 FOUR_ISR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) FOUR_ISR.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
