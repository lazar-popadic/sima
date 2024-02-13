################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Lib/Periferije/Tajmer/Tajmer.c 

OBJS += \
./Core/Lib/Periferije/Tajmer/Tajmer.o 

C_DEPS += \
./Core/Lib/Periferije/Tajmer/Tajmer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Lib/Periferije/Tajmer/%.o Core/Lib/Periferije/Tajmer/%.su Core/Lib/Periferije/Tajmer/%.cyclo: ../Core/Lib/Periferije/Tajmer/%.c Core/Lib/Periferije/Tajmer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L432xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Lib-2f-Periferije-2f-Tajmer

clean-Core-2f-Lib-2f-Periferije-2f-Tajmer:
	-$(RM) ./Core/Lib/Periferije/Tajmer/Tajmer.cyclo ./Core/Lib/Periferije/Tajmer/Tajmer.d ./Core/Lib/Periferije/Tajmer/Tajmer.o ./Core/Lib/Periferije/Tajmer/Tajmer.su

.PHONY: clean-Core-2f-Lib-2f-Periferije-2f-Tajmer

