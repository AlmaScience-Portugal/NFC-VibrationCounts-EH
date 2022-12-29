################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ndeft2t/ndeft2t.c 

C_DEPS += \
./ndeft2t/ndeft2t.d 

OBJS += \
./ndeft2t/ndeft2t.o 


# Each subdirectory must supply rules for building sources it contributes
ndeft2t/%.o: ../ndeft2t/%.c ndeft2t/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC8N04FHI24 -DCPU_LPC8N04FHI24_cm0plus -DCPU_LPC8N04 -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_ndeft2t_hello\source" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_ndeft2t_hello" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_ndeft2t_hello\ndeft2t" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_ndeft2t_hello\drivers" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_ndeft2t_hello\device" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_ndeft2t_hello\CMSIS" -I"C:\Users\Shubham DAS\Documents\MCUXpressoIDE_11.6.1_8255\lpc8n04devboard_ndeft2t_hello\board" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-ndeft2t

clean-ndeft2t:
	-$(RM) ./ndeft2t/ndeft2t.d ./ndeft2t/ndeft2t.o

.PHONY: clean-ndeft2t

