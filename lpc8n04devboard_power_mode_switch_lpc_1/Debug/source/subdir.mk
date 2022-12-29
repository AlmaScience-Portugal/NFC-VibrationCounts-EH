################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/power_mode_switch_lpc.c \
../source/semihost_hardfault.c 

C_DEPS += \
./source/power_mode_switch_lpc.d \
./source/semihost_hardfault.d 

OBJS += \
./source/power_mode_switch_lpc.o \
./source/semihost_hardfault.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC8N04FHI24 -DCPU_LPC8N04FHI24_cm0plus -DCPU_LPC8N04 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\source" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\drivers" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\device" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\CMSIS" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\board" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/power_mode_switch_lpc.d ./source/power_mode_switch_lpc.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o

.PHONY: clean-source

