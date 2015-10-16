################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PS_4.cpp \
../src/problem1.cpp \
../src/problem2.cpp 

OBJS += \
./src/PS_4.o \
./src/problem1.o \
./src/problem2.o 

CPP_DEPS += \
./src/PS_4.d \
./src/problem1.d \
./src/problem2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


