################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_LPC8N04.c 

C_DEPS += \
./device/system_LPC8N04.d 

OBJS += \
./device/system_LPC8N04.o 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC8N04FHI24 -DCPU_LPC8N04FHI24_cm0plus -DCPU_LPC8N04 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\source" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\drivers" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\device" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\CMSIS" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_power_mode_switch_lpc_1\board" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-device

clean-device:
	-$(RM) ./device/system_LPC8N04.d ./device/system_LPC8N04.o

.PHONY: clean-device

