################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/DriveForward.cpp 

OBJS += \
./src/Commands/DriveForward.o 

CPP_DEPS += \
./src/Commands/DriveForward.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\Prashasth K/wpilib/cpp/current/include" -I"C:\Users\Prashasth K\eclipse-workspace\Practice (Autonomous)\src" -I"C:\Users\Prashasth K/wpilib/user/cpp/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


