################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Lib/Periferije/IO/IO.c 

OBJS += \
./Core/Lib/Periferije/IO/IO.o 

C_DEPS += \
./Core/Lib/Periferije/IO/IO.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Lib/Periferije/IO/%.o Core/Lib/Periferije/IO/%.su Core/Lib/Periferije/IO/%.cyclo: ../Core/Lib/Periferije/IO/%.c Core/Lib/Periferije/IO/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Lib-2f-Periferije-2f-IO

clean-Core-2f-Lib-2f-Periferije-2f-IO:
	-$(RM) ./Core/Lib/Periferije/IO/IO.cyclo ./Core/Lib/Periferije/IO/IO.d ./Core/Lib/Periferije/IO/IO.o ./Core/Lib/Periferije/IO/IO.su

.PHONY: clean-Core-2f-Lib-2f-Periferije-2f-IO

